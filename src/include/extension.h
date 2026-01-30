#ifndef _INCLUDE_L4D2_PLUGIN_HPP_
#define _INCLUDE_L4D2_PLUGIN_HPP_

#include <IPlayerHelpers.h>
#include <smsdk_ext.h>

class L4D2Extension : public SDKExtension, public IClientListener {
public:
  virtual bool SDK_OnLoad(char *error, size_t maxlength, bool late);
  virtual void SDK_OnUnload();
  virtual bool SDK_OnMetamodLoad(ISmmAPI *ismm, char *error, size_t maxlength,
                                 bool late);

  // Listeners
  virtual void OnClientPutInServer(int client);
};

extern L4D2Extension g_L4D2Extension;
// extern IVEngineServer *g_pEngineServer;
extern IPlayerManager *g_pPlayerManager;
extern IGamePlayer *g_pGamePlayer;
extern IGameHelpers *g_pGameHelpers;

#endif // _INCLUDE_L4D2_PLUGIN_HPP_
