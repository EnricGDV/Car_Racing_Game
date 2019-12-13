#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"
#include "PhysBody3D.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));

	CreateLine({ 0.0f, 0.0f, -10.0f }, { 0.0f, 0.0f, 20.0f }, 16, true);
	CreateLine({ -48.0f, 0.0f, -10.0f }, { -48.0f, 0.0f, 20.0f }, 16, true);
	CreateLine({ 0.0f, 0.0f, -30.0f }, { 0.0f, 0.0f, -60.0f }, 16, true);
	CreateLine({ -48.0f, 0.0f, -30.0f }, { -48.0f, 0.0f, -60.0f }, 16, true);
	CreateLine({ 48.0f, 0.0f, -10.0f }, { 48.0f, 0.0f, 20.0f }, 16, true);
	CreateLine({ 48.0f, 0.0f, -30.0f }, { 48.0f, 0.0f, -60.0f }, 16, true);
	CreateLine({ 48.0f, 0.0f, 40.0f }, { 48.0f, 0.0f, 70.0f }, 16, true);
	CreateLine({ 48.0f, 0.0f, 70.0f }, { 48.0f, 0.0f, 100.0f }, 16, true);
	CreateLine({ 48.0f, 0.0f, 100.0f }, { 48.0f, 0.0f, 130.0f }, 16, true);
	CreateLine({ 58.0f, 0.0f, 30.0f }, { 88.0f, 0.0f, 30.0f }, 16, true);
	CreateLine({ 58.0f, 0.0f, -70.0f }, { 88.0f, 0.0f, -70.0f }, 16, true);
	CreateLine({ 10.0f, 0.0f, 30.0f }, { 40.0f, 0.0f, 30.0f }, 16, true);
	CreateLine({ 10.0f, 0.0f, -70.0f }, { 40.0f, 0.0f, -70.0f }, 16, true);
	CreateLine({ 10.0f, 0.0f, -20.0f }, { 40.0f, 0.0f, -20.0f }, 16, true);
	CreateLine({ 58.0f, 0.0f, -20.0f }, { 88.0f, 0.0f, -20.0f }, 16, true);
	CreateLine({ -10.0f, 0.0f, -70.0f }, { -40.0f, 0.0f, -70.0f }, 16, true);
	CreateLine({ -10.0f, 0.0f, -20.0f }, { -40.0f, 0.0f, -20.0f }, 16, true);
	CreateLine({ 10.0f, 0.0f, 140.0f }, { 40.0f, 0.0f, 140.0f }, 16, true);
	CreateLine({ 58.0f, 0.0f, 140.0f }, { 88.0, 0.0f, 140.0f }, 16, true);
	CreateLine({ 58.0f, 0.0f, 140.0f }, { 88.0, 0.0f, 140.0f }, 16, true);
	CreateLine({ 0.0f, 0.0f, 130.0f }, { 0.0f, 0.0f, 100.0f }, 16, true);
	CreateLine({ 0.0f, 0.0f, 100.0f }, { 0.0f, 0.0f, 70.0f }, 16, true);
	CreateLine({ -10.0f, 0.0f, 30.0f }, { -40.0f, 0.0f, 30.0f }, 16, true);

	CreateLine({ 8.0f, 0.0f, 30.0f }, { -22.0f, 0.0f, 30.0f }, 16, false);
	CreateLine({ 0.0f, 0.0f, 70.0f }, { 0.0f, 0.0f, 40.0f }, 16, false);

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	Plane p(0, 1, 0, 0);
	Cube floor(1000, 0.01, 1000);
	for (int i = 0; i < cube_pieces.primitive_bodies.Count(); i++)
		cube_pieces.primitive_bodies[i].Render();
	floor.color = Grey;
	floor.Render();
	p.axis = true;
	p.Render();

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}


void ModuleSceneIntro::CreateLine(const vec3 initialPos, const vec3 finalPos, uint numCubes, bool isDouble)
{

	float distance = sqrt(pow(finalPos.x - initialPos.x, 2) + pow(finalPos.y - initialPos.y, 2) + pow(finalPos.z - initialPos.z, 2));
	float distanceSeg = distance / numCubes;

	vec3 dir_v = finalPos - initialPos;
	float dir_v_mod = sqrt((dir_v.x*dir_v.x) + (dir_v.y*dir_v.y) + (dir_v.z * dir_v.z));
	dir_v /= dir_v_mod;
	vec3 perp_v = { -dir_v.z, 0, dir_v.x };
	float perp_v_mod = sqrt((perp_v.x*perp_v.x) + (perp_v.y*perp_v.y) + (perp_v.z * perp_v.z));
	perp_v /= perp_v_mod;

	vec3 pos;
	vec3 dim(1, 2, 1);

	Cube wall;
	wall.color = White;
	wall.size = { dim.x, dim.y, dim.z };

	for (uint j = 0; j < numCubes; j++)
	{
		if (isDouble)
		{
			pos = (initialPos + (dir_v * j * distanceSeg)) + ((TRACK_WIDTH / 2) * perp_v);
			wall.SetPos(pos.x, pos.y + 1, pos.z);
			cube_pieces.primitive_bodies.PushBack(wall);
			cube_pieces.physic_bodies.PushBack(App->physics->AddBody(wall, 0.0f));
		}
		
		
		pos = (initialPos + (dir_v * j * distanceSeg)) + ((TRACK_WIDTH / 2) * -perp_v);
		wall.SetPos(pos.x, pos.y + 1, pos.z);
		cube_pieces.primitive_bodies.PushBack(wall);
		cube_pieces.physic_bodies.PushBack(App->physics->AddBody(wall, 0.0f));

	}
}

void ModuleSceneIntro::CreateCircle(const vec3 centre, const vec3 radius, uint numCubes)
{

}

