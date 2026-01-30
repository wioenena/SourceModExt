#ifndef _INCLUDE_SOURCEMOD_EXTENSION_CONFIG_H_
#define _INCLUDE_SOURCEMOD_EXTENSION_CONFIG_H_

#define SMEXT_CONF_NAME "wioenena L4D2 extension"
#define SMEXT_CONF_DESCRIPTION "<none>"
#define SMEXT_CONF_VERSION "1.0.0"
#define SMEXT_CONF_AUTHOR "wioenena"
#define SMEXT_CONF_URL "https://github.com/wioenena"
#define SMEXT_CONF_LOGTAG "wioenena"
#define SMEXT_CONF_LICENSE ""
#define SMEXT_CONF_DATESTRING __DATE__

#define SMEXT_LINK(name) SDKExtension *g_pExtensionIface = name;
#define SMEXT_CONF_METAMOD
#define SMEXT_ENABLE_PLAYERHELPERS
#define SMEXT_ENABLE_GAMEHELPERS

#endif // _INCLUDE_SOURCEMOD_EXTENSION_CONFIG_H_
