//====== Copyright � 1996-2005, Valve Corporation, All rights reserved. =======//
//
// Purpose: CTF AmmoPack.
//
//=============================================================================//
#ifndef ENTITY_WEAPON_SPAWNER_H
#define ENTITY_WEAPON_SPAWNER_H

#ifdef _WIN32
#pragma once
#endif

#include "tf_powerup.h"

//=============================================================================
//
// CTF WeaponSpawner class.
//

class CWeaponSpawner : public CTFPowerup
{
public:
	DECLARE_CLASS( CWeaponSpawner, CTFPowerup );
	DECLARE_DATADESC();
	DECLARE_SERVERCLASS();
	
	CWeaponSpawner();

	void	Spawn( void );
	virtual CBaseEntity* Respawn( void );
	void	Precache( void );
	bool	MyTouch( CBasePlayer *pPlayer );
	void	SetWeaponModel( void );

	powerupsize_t	GetPowerupSize( void ) { return POWERUP_FULL; }
	const char* GetSuperWeaponRespawnLine(void);
	const char* GetSuperWeaponPickupLine(void);
	const char* GetSuperWeaponPickupLineSelf(void);
	virtual void Materialize(void);
	string_t szWeaponName;
	string_t szWeaponModel;
	string_t szWeaponModelOLD;
	string_t szPickupSound;
	CNetworkString(m_iszWeaponName, 128);
	char m_iszWeaponModel[128];
	char m_iszWeaponModelOLD[128];
	char m_iszPickupSound[128];

	CNetworkVar( bool, m_bDisableSpin );
	CNetworkVar( bool, m_bDisableShowOutline );
	CNetworkVar( int,  m_iIndex );
private:
	CNetworkVar( float, m_flRespawnTick );
};

#endif // ENTITY_WEAPON_SPAWNER_H


