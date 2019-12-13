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

	CreateCube({ 0.0f, 0.0f, 2.0f }, { 0.0f, 0.0f, 20.0f }, 16);

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
	Cube floor(100, 0.25, 100);
	floor.color = Grey;
	floor.Render();
	p.axis = true;
	p.Render();

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}


void ModuleSceneIntro::CreateCube(const vec3 i, const vec3 f, uint intervals)
{

	float distance = sqrt(pow(f.x - i.x, 2) + pow(f.y - i.y, 2) + pow(f.z - i.z, 2));
	float dist_segment = distance / intervals;

	vec3 dir_v = f - i;
	float dir_v_mod = sqrt((dir_v.x*dir_v.x) + (dir_v.y*dir_v.y) + (dir_v.z * dir_v.z));
	dir_v /= dir_v_mod;
	vec3 perp_v = { -dir_v.z, 0, dir_v.x };
	float perp_v_mod = sqrt((perp_v.x*perp_v.x) + (perp_v.y*perp_v.y) + (perp_v.z * perp_v.z));
	perp_v /= perp_v_mod;

	vec3 pos;
	vec3 dim(1, 2, 1);

	Cube c;
	c.color = White;
	c.size = { dim.x, dim.y, dim.z };

	for (uint j = 0; j < intervals; j++)
	{
		
		pos = (i + (dir_v * j * dist_segment)) + ((TRACK_WIDTH / 2) * perp_v);
		c.SetPos(pos.x, pos.y + 1, pos.z);
		cube_pieces.primitive_bodies.PushBack(c);
		cube_pieces.physic_bodies.PushBack(App->physics->AddBody(c, 0.0f));

		pos = (i + (dir_v * j * dist_segment)) + ((TRACK_WIDTH / 2) * -perp_v);
		c.SetPos(pos.x, pos.y + 1, pos.z);
		cube_pieces.primitive_bodies.PushBack(c);
		cube_pieces.physic_bodies.PushBack(App->physics->AddBody(c, 0.0f));

	}
}

