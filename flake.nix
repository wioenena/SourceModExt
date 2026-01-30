{
  description = "C/C++ template";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs =
    { self, nixpkgs, ... }:
    let
      allSystems = [ "x86_64-linux" ];
      forAllSystems = f: nixpkgs.lib.genAttrs allSystems (system: f (import nixpkgs { inherit system; }));
    in
    {
      devShells = forAllSystems (
        pkgs:
        let
          pkgs32 = pkgs.pkgsi686Linux;
        in
        {
          default = pkgs32.mkShell {
            nativeBuildInputs = with pkgs; [
              cmake
              gdb
              pkgs32.clang-tools
              pkg-config
            ];

            buildInputs = with pkgs32; [
              pkgs.git
            ];

            shellHook = ''
              echo "------------------------------------------------"
              echo "🛡️ Welcome to the C/C++ development shell!"
              echo "------------------------------------------------"
              echo "Compilers: GCC $(gcc --version | head -n1 | awk '{print $3}')"

              if [ ! -d "build" ]; then
                cmake -B build
              fi

              ln -sf build/compile_commands.json compile_commands.json

              git submodule update --init --recursive
            '';
          };
        }
      );
      formatter = forAllSystems (pkgs: pkgs.nixfmt);
    };
}
