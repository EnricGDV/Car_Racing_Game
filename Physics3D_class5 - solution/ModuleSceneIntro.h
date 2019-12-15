#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "Primitive.h"

#define MAX_SNAKE 2

struct PhysBody3D;
struct PhysMotor3D;

#define TRACK_WIDTH 20.0f

struct Cubes
{
	p2DynArray<PhysBody3D*>		physic_bodies;
	p2DynArray<Cube>			primitive_bodies;
};

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	void OnCollision(PhysBody3D* body1, PhysBody3D* body2);
	void CreateLine(const vec3 iniPos, const vec3 finalPos, uint numCubes, bool isDouble);
	void CreateClients();
	void Restart();

	void ChangeGoal(int num);

public:
	/*
	PhysBody3D* pb_snake[MAX_SNAKE];
	Sphere s_snake[MAX_SNAKE];

	PhysBody3D* pb_snake2[MAX_SNAKE];
	Sphere s_snake2[MAX_SNAKE];
	*/

	Cubes cube_pieces;
	Cube doorp;
	Cube hingep;
	PhysBody3D* doorb;
	PhysBody3D* hingeb;
	Cylinder goalp;
	Line arrowp;
	vec3 goalPos;
	p2DynArray<Cube> clients;
	int satisfiedcl;
	uint winFx;
	uint arrivedFx;
	uint loseFx;
	uint pickupFx;

	Timer game_timer;
};
