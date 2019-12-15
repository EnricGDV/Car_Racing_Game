#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"
#include "PhysVehicle3D.h"
#include "ModuleAudio.h"

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
	

	CreateLine({ 0.0f, 0.0f, -10.0f }, { 0.0f, 0.0f, 20.0f }, 16, true);
	CreateLine({ -48.0f, 0.0f, -10.0f }, { -48.0f, 0.0f, 20.0f }, 16, true);
	CreateLine({ 0.0f, 0.0f, -30.0f }, { 0.0f, 0.0f, -60.0f }, 16, true);
	CreateLine({ -48.0f, 0.0f, -30.0f }, { -48.0f, 0.0f, -60.0f }, 16, true);
	CreateLine({ 98.0f, 0.0f, -30.0f }, { 98.0f, 0.0f, -60.0f }, 16, true);
	CreateLine({ 98.0f, 0.0f, -10.0f }, { 98.0f, 0.0f, 20.0f }, 16, true);
	CreateLine({ 98.0f, 0.0f, 40.0f }, { 98.0f, 0.0f, 70.0f }, 16, true);
	CreateLine({ 98.0f, 0.0f, 70.0f }, { 98.0f, 0.0f, 100.0f }, 16, true);
	CreateLine({ 98.0f, 0.0f, 100.0f }, { 98.0f, 0.0f, 130.0f }, 16, true);
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
	CreateLine({ 0.0f, 0.0f, 100.0f }, { 0.0f, 0.0f, 60.0f }, 20, true);
	CreateLine({ -10.0f, 0.0f, 30.0f }, { -40.0f, 0.0f, 30.0f }, 16, true);

	CreateLine({ 10.0f, 0.0f, 30.0f }, { -10.0f, 0.0f, 30.0f }, 10, false);
	CreateLine({ -40.0f, 0.0f, 30.0f }, { -60.0f, 0.0f, 30.0f }, 10, false);


	CreateLine({ 98.0f, 0.0f, 20.0f }, { 98.0f, 0.0f, 40.0f }, 10, false);
	CreateLine({ 98.0f, 0.0f, -30.0f }, { 98.0f, 0.0f, -10.0f }, 10, false);
	CreateLine({ 98.0f, 0.0f, -78.0f }, { 98.0f, 0.0f, -58.0f }, 10, false);
	CreateLine({ 98.0f, 0.0f, 130.0f }, { 98.0f, 0.0f, 150.0f }, 10, false);

	CreateLine({ -48.0f, 0.0f, -10.0f }, { -48.0f, 0.0f, -30.0f }, 10, false);
	CreateLine({ -48.0f, 0.0f, -60.0f }, { -48.0f, 0.0f, -80.0f }, 10, false);
	CreateLine({ -48.0f, 0.0f, 38.0f }, { -48.0f, 0.0f, 18.0f }, 10, false);

	CreateLine({ 58.0f, 0.0f, 140.0f }, { 38.0f, 0.0f, 140.0f }, 10, false);
	CreateLine({ 108.0f, 0.0f, 140.0f }, { 86.0f, 0.0f, 140.0f }, 10, false);
	CreateLine({ 10.0f, 0.0f, 140.0f }, { -10.0f, 0.0f, 140.0f }, 10, false);

	CreateLine({ 38.0f, 0.0f, -70.0f }, { 58.0f, 0.0f, -70.0f }, 10, false);
	CreateLine({ 88.0f, 0.0f, -70.0f }, { 108.0f, 0.0f, -70.0f }, 10, false);
	CreateLine({ -10.0f, 0.0f, -70.0f }, { 10.0f, 0.0f, -70.0f }, 10, false);
	CreateLine({ -58.0f, 0.0f, -70.0f }, { -38.0f, 0.0f, -70.0f }, 10, false);

	CreateLine({ 0.0f, 0.0f, 150.0f }, { 0.0f, 0.0f, 130.0f }, 10, false);

	CreateLine({ 0.0f, 0.0f, 60.0f }, { 0.0f, 0.0f, 40.0f }, 10, false);

	Cube hinge(1.0f, 2.0f, 1.0f);
	hinge.color = Grey;
	hinge.SetPos(10.0f, 1.0f, 62.0f);
	hingeb = App->physics->AddBody(hinge, 0.0f);
	Cube door(1.0f, 2.0f, 15.0f);
	door.color = Grey;
	door.SetPos(10.0f, 1.0f, 52.0f);
	doorb = App->physics->AddBody(door);
	App->physics->AddConstraintHinge(*doorb, *hingeb, vec3(0.0f, 0.0f, 9.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));
	doorp = door;

	goalPos = vec3(50.0f, 5.0f, 20.0f);
	CreateClients();

	Cylinder goal(5.0f, 50.0f);
	goal.color = TransparentGreen;
	goal.SetRotation(90.0f, vec3(0.0f, 0.0f, 1.0f));
	goalp = goal;

	Line arrow(goalPos.x, 1.0f, goalPos.z);
	arrow.origin = App->player->pos;
	arrow.destination = vec3(arrow.destination.x / 10.0f, arrow.destination.y / 10.0f, arrow.destination.z / 10.0f);
	arrow.color = Green;
	arrowp = arrow;

	App->audio->PlayMusic("audio/music/Middle_Children.ogg");

	winFx = App->audio->LoadFx("audio/fx/win.wav");
	arrivedFx = App->audio->LoadFx("audio/fx/ka-ching.wav");
	pickupFx = App->audio->LoadFx("audio/fx/pickup.wav");
	loseFx = App->audio->LoadFx("audio/fx/lose.wav");

	satisfiedcl = 0;
	game_timer.Start();

	

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");
	clients.Clear();
	cube_pieces.physic_bodies.Clear();
	cube_pieces.primitive_bodies.Clear();

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	Plane p(0.0f, 1.0f, 0.0f, 0.0f);
	Cube floor(1000.0f, 0.01f, 1000.0f);
	Cube building1(20.0f, 70.0f, 80.0f);
	building1.SetPos(75.0f, 0.0f, 85.0f);
	Cube building2(20.0f, 60.0f, 20.0f);
	building2.SetPos(75.0f, 0.0f, 5.0f);
	Cube building3(20.0f, 40.0f, 20.0f);
	building3.SetPos(75.0f, 0.0f, -45.0f);
	Cube building4(20.0f, 30.0f, 20.0f);
	building4.SetPos(23.0f, 0.0f, -45.0f);
	Cube building5(20.0f, 80.0f, 20.0f);
	building5.SetPos(-25.0f, 0.0f, -45.0f);
	Cube building6(20.0f, 35.0f, 20.0f);
	building6.SetPos(23.0f, 0.0f, 5.0f);
	Cube building7(20.0f, 60.0f, 20.0f);
	building7.SetPos(-25.0f, 0.0f, 5.0f);
	floor.color = Grey;
	building1.color = Grey;
	building1.Render();
	building2.color = Grey;
	building2.Render();
	building3.color = Grey;
	building3.Render();
	building4.color = Grey;
	building4.Render();
	building5.color = Grey;
	building5.Render();
	building6.color = Grey;
	building6.Render();
	building7.color = Grey;
	building7.Render();

	doorb->GetTransform(doorp.transform.M);
	doorp.Render();

	floor.Render();
	for (int i = 0; i < cube_pieces.primitive_bodies.Count(); i++)
		cube_pieces.primitive_bodies[i].Render();
	
	p.axis = true;
	p.Render();

	if (App->input->GetKey(SDL_SCANCODE_F4) == KEY_DOWN)
	{
		Restart();
		App->audio->PlayFx(winFx);
		App->player->vehicle->info.color = Green;
	}

	if (App->input->GetKey(SDL_SCANCODE_F5) == KEY_DOWN)
	{
		Restart();
		App->audio->PlayFx(loseFx);
		App->player->vehicle->info.color = Red;
	}

	if (game_timer.Read() > 200000)
	{
		Restart();
		App->audio->PlayFx(loseFx);
		App->player->vehicle->info.color = Red;
	}

	for (int i = 0; i < clients.Count(); i++)
	{
		
		if ((abs(App->player->pos.x - clients[i].transform[12]) < 3 && abs(App->player->pos.z - clients[i].transform[14]) < 3) && App->player->brake == BRAKE_POWER && App->player->st == state::Empty && clients[i].color.g == 0.0f)
		{
 			App->player->st = state::Carrying;
			App->player->client = i;

			App->audio->PlayFx(pickupFx);
			
			ChangeGoal(App->player->client);
			goalp.SetPos(goalPos.x, goalPos.y, goalPos.z);
		}

		if (App->player->st == state::Carrying)
		{
			btQuaternion q = App->player->vehicle->vehicle->getChassisWorldTransform().getRotation();
			App->player->vehicle->vehicle->getChassisWorldTransform().getOpenGLMatrix(&clients[App->player->client].transform);
			btVector3 lw_offset(App->player->vehicle->info.chassis_offset.x - 0.5f, App->player->vehicle->info.chassis_offset.y + 0.5f, App->player->vehicle->info.chassis_offset.z - 0.6f);
			lw_offset = lw_offset.rotate(q.getAxis(), q.getAngle());
			clients[App->player->client].transform.M[12] += lw_offset.getX();
			clients[App->player->client].transform.M[13] += lw_offset.getY();
			clients[App->player->client].transform.M[14] += lw_offset.getZ();
			arrowp.destination = vec3(App->player->pos.x + (goalp.transform.M[12] - App->player->pos.x) / 50.0f, App->player->pos.y + 3, App->player->pos.z + (goalp.transform.M[14] - App->player->pos.z ) / 50.0f);
			arrowp.origin = vec3(App->player->pos.x, App->player->pos.y+ 3.0f, App->player->pos.z);
			goalp.Render();
			arrowp.Render();

			if (abs(App->player->pos.x - goalp.transform[12]) < 3 && abs(App->player->pos.z - goalp.transform[14]) < 3 && App->player->brake == BRAKE_POWER)
			{
				App->player->st = state::Empty;

				App->audio->PlayFx(arrivedFx);

				clients[App->player->client].color = Green;
				clients[App->player->client].SetPos(App->player->pos.x, App->player->pos.y, App->player->pos.z);
				clients[App->player->client].transform.M[12] += 2.0f;
				clients[App->player->client].transform.M[13] = 0.25f;
				satisfiedcl++;
				App->player->vehicle->GetTransform(App->player->checkpointMat);
				if (satisfiedcl == 5)
				{
					App->audio->PlayFx(winFx);
					App->player->vehicle->info.color = Green;
					Restart();
				}
			}
		}

		clients[i].Render();
	}

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}


void ModuleSceneIntro::CreateLine(const vec3 initialPos, const vec3 finalPos, uint numCubes, bool isDouble)
{

	float distance = sqrt(pow(finalPos.x - initialPos.x, 2.0f) + pow(finalPos.y - initialPos.y, 2.0f) + pow(finalPos.z - initialPos.z, 2.0f));
	float distanceSeg = distance / numCubes;

	vec3 dir_v = finalPos - initialPos;
	float dir_v_mod = sqrt((dir_v.x*dir_v.x) + (dir_v.y*dir_v.y) + (dir_v.z * dir_v.z));
	dir_v /= dir_v_mod;
	vec3 perp_v = { -dir_v.z, 0, dir_v.x };
	float perp_v_mod = sqrt((perp_v.x*perp_v.x) + (perp_v.y*perp_v.y) + (perp_v.z * perp_v.z));
	perp_v /= perp_v_mod;

	vec3 pos;
	vec3 dim(1.0f, 2.0f, 1.0f);

	Cube wall;
	wall.color = White;
	wall.size = { dim.x, dim.y, dim.z };

	for (uint j = 0; j < numCubes; j++)
	{
		if (isDouble)
		{
			pos = (initialPos + (dir_v * j * distanceSeg)) + ((TRACK_WIDTH / 2.0f) * perp_v);
			wall.SetPos(pos.x, pos.y + 1.0f, pos.z);
			cube_pieces.primitive_bodies.PushBack(wall);
			cube_pieces.physic_bodies.PushBack(App->physics->AddBody(wall, 0.0f));
		}
		
		
		pos = (initialPos + (dir_v * j * distanceSeg)) + ((TRACK_WIDTH / 2.0f) * -perp_v);
		wall.SetPos(pos.x, pos.y + 1.0f, pos.z);
		cube_pieces.primitive_bodies.PushBack(wall);
		cube_pieces.physic_bodies.PushBack(App->physics->AddBody(wall, 0.0f));

	}
}

void ModuleSceneIntro::CreateClients()
{
	Cube cl(0.5f, 0.5f, 0.5f);
	cl.color = Red;

	for (uint j = 0; j < 5; j++)
	{
		clients.PushBack(cl);
	}

	//Placing clients
	clients[0].SetPos(-50.0f, 0.25f, -75.0f);
	clients[1].SetPos(0.0f, 0.25f, -20.0f);
	clients[2].SetPos(100.0f, 0.25f, 135.0f);
	clients[3].SetPos(80.0f, 0.25f, -20.0f);
	clients[4].SetPos(23.0f, 0.25f, 125.0f);
}


//Changing the goal for different clients
void ModuleSceneIntro::ChangeGoal(int num)
{
	switch (num)
	{
	case 0:
		goalPos = vec3(100.0f, 5.0f, 100.0f);
		break;
	case 1: 
		goalPos = vec3(-40.0f, 5.0f, 30.0f);
		break;
	case 2:
		goalPos = vec3(100.0f, 5.0f, 0.0f);
		break;
	case 3:
		goalPos = vec3(75.0f, 5.0f, -75.0f);
		break;
	case 4:
		goalPos = vec3(0.0f, 5.0f, 0.0f);
		break;

	}

}

//Restarting game
void ModuleSceneIntro::Restart()
{
	App->audio->PlayMusic("audio/music/Middle_Children.ogg");
	game_timer.Start();
	App->player->st = state::Empty;
	App->player->vehicle->SetTransform(App->player->initMat);
	for (uint j = 0; j < 5; j++)
	{
		clients[j].color = Red;
	}
	clients[0].SetPos(-50.0f, 0.25f, -75.0f);
	clients[1].SetPos(0.0f, 0.25f, -20.0f);
	clients[2].SetPos(100.0f, 0.25f, 135.0f);
	clients[3].SetPos(80.0f, 0.25f, -20.0f);
	clients[4].SetPos(23.0f, 0.25f, 125.0f);
}

