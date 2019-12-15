#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"

struct PhysVehicle3D;

#define MAX_ACCELERATION 800.0f
#define TURN_DEGREES 17.5f * DEGTORAD
#define BRAKE_POWER 1000.0f

enum class state
{
	Empty,
	Carrying
};

class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app, bool start_enabled = true);
	virtual ~ModulePlayer();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

public:

	PhysVehicle3D* vehicle;
	float turn;
	float acceleration;
	float brake;
	vec3 pos;
	vec3 initPos;
	float initMat[16];
	float checkpointMat[16];
	state st;

	//Client being carried
	int client;
};