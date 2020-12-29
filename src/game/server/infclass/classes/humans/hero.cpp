#include "hero.h"

#include <game/server/infclass/entities/infccharacter.h>

CInfClassHero::CInfClassHero()
	: CInfClassHuman()
{
}

void CInfClassHero::SetupSkin()
{
	CInfClassHuman::SetupSkin(); // Reset to default

	// Hero (correct colors)
	str_copy(m_SkinInfo.m_aaSkinPartNames[SKINPART_MARKING], "stripe", sizeof(m_SkinInfo.m_aaSkinPartNames[SKINPART_MARKING]));
	m_SkinInfo.m_aUseCustomColors[SKINPART_BODY] = 1;
	m_SkinInfo.m_aUseCustomColors[SKINPART_HANDS] = 1;
	m_SkinInfo.m_aUseCustomColors[SKINPART_FEET] = 1;
	m_SkinInfo.m_aSkinPartColors[SKINPART_BODY] = 16307835;
	m_SkinInfo.m_aSkinPartColors[SKINPART_MARKING] = -16711808;
	m_SkinInfo.m_aSkinPartColors[SKINPART_DECORATION] = 65408;
	m_SkinInfo.m_aSkinPartColors[SKINPART_HANDS] = 184;
	m_SkinInfo.m_aSkinPartColors[SKINPART_FEET] = 9765959;
	m_SkinInfo.m_aSkinPartColors[SKINPART_EYES] = 65408;
}
