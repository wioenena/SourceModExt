#include <include/extension.h>

L4D2Extension g_L4D2Extension;
SMEXT_LINK(&g_L4D2Extension);

IPlayerManager *g_pPlayerManager = nullptr;
IGameHelpers *g_pGameHelpers = nullptr;
IGamePlayer *g_pGamePlayer = nullptr;

bool L4D2Extension::SDK_OnLoad(char *error, size_t maxlength, bool late) {
  SM_GET_IFACE(PLAYERMANAGER, g_pPlayerManager);
  SM_GET_IFACE(GAMEHELPERS, g_pGameHelpers);
  SM_GET_IFACE(PLAYERMANAGER, g_pGamePlayer);
  if (!g_pPlayerManager) {
    snprintf(error, maxlength, "Failed to get player manager");
    return false;
  }

  if (!g_pGameHelpers) {
    snprintf(error, maxlength, "Failed to get game helpers");
    return false;
  }

  if (!g_pGamePlayer) {
    snprintf(error, maxlength, "Failed to get game player");
    return false;
  }

  g_pPlayerManager->AddClientListener(this);
  return true;
}

bool L4D2Extension::SDK_OnMetamodLoad(ISmmAPI *ismm, char *error,
                                      size_t maxlength, bool late) {
  CreateInterfaceFn engineFactory = ismm->GetEngineFactory();
  if (!engineFactory) {
    snprintf(error, maxlength, "Failed to get engine factory");
    return false;
  }

  engine =
      (IVEngineServer *)engineFactory(INTERFACEVERSION_VENGINESERVER, nullptr);
  if (!engine) {
    snprintf(error, maxlength, "Failed to get engine server");
    return false;
  }

  return true;
}

void L4D2Extension::OnClientPutInServer(int client) {
  char msg[64];
  IGamePlayer *pPlayer = g_pPlayerManager->GetGamePlayer(client);
  sprintf(msg, "Welcome %s", pPlayer->GetName());
  g_pGameHelpers->TextMsg(client, TEXTMSG_DEST_CHAT, msg);
}

void L4D2Extension::SDK_OnUnload() {
  if (g_pPlayerManager) {
    g_pPlayerManager->RemoveClientListener(this);
  }
}
