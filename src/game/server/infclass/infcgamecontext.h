#ifndef GAME_SERVER_INFCLASS_CONTEXT_H
#define GAME_SERVER_INFCLASS_CONTEXT_H

#include "../gamecontext.h"

#include <vector>
#include <map>

class CGameControllerInfClass;
class CInfClassPlayer;
class CInfClassPlayerClass;

class CInfClassGameContext : public CGameContext
{
public:
	CInfClassGameContext();
	~CInfClassGameContext();

	CGameControllerInfClass *GetController() const { return m_pInfcGameController; }
	CGameWorld *GameWorld();

	void RegisterTypes();
	void OnInit() override;
	void OnShutdown() override;
	void OnConsoleInit() override;

	void OnMessage(int MsgID, CUnpacker *pUnpacker, int ClientID) override;
	void OnTick() override;
	void OnSnap(int ClientID) override;
	void OnPostSnap() override;

	void OnClientConnected(int ClientID, bool AsSpec) override;

	void AnnounceSkinChange(int ClientID);
	void SendChatTarget(int To, const char *pText);
	void CreateSoundGlobal(int Sound);

	CInfClassPlayer *GetPlayer(int ClientID);
	CInfClassPlayerClass *CreateInfClass(int ClassId);

	bool AreConnected(vec2 Pos1, vec2 Pos2, float Radius);

	void CreateLaserDotEvent(vec2 Pos0, vec2 Pos1, int LifeSpan);

protected:
	CInfClassGameContext(int Resetting);
	void ModClear();

	using InfPlayerClassConstructor = CInfClassPlayerClass *();

	template <typename C>
	int RegisterInfClassClass();

	static void ConSetClass(IConsole::IResult *pResult, void *pUserData);

	void LoadModEntities();

	struct LaserDotState
	{
		vec2 m_Pos0;
		vec2 m_Pos1;
		int m_LifeSpan;
		int m_SnapID;
	};
	array<LaserDotState> m_LaserDots;
	array<int> m_GlobalSounds;

	CMapItemGroup *m_pEntityGroup = nullptr;

	CGameControllerInfClass *m_pInfcGameController = nullptr;
	std::vector<InfPlayerClassConstructor*> m_ClassConstructors;
	std::map<int, const char *> m_ClassIdToName;
};

#endif // GAME_SERVER_INFCLASS_CONTEXT_H
