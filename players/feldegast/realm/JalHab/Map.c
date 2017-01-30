#include "defs.h"

object *room_list;
object *npc;

object query_location(int x, int y);
object load_room(int x, int y);

void reset(int arg) {
  if(!arg) {
    room_list=allocate(LENGTH*WIDTH);
    npc=allocate(6);
  }
  /* Start these monsters off in a random location. */
  if(!npc[0]) {
    npc[0]=clone_object(MON_PATH+"wanderer.c");
    move_object(npc[0],query_location(random(LENGTH),random(WIDTH)));
  }
  if(!npc[1]) {
    npc[1]=clone_object(MON_PATH+"confusius.c");
    move_object(npc[1],query_location(random(LENGTH),random(WIDTH)));
  }
  if(!npc[2]) {
    string dest;
    npc[2]=clone_object(MON_PATH+"jikhal.c");
    switch(random(3)) {
      case 0: dest=PATH+"stav4.c"; break;
      case 1: dest=PATH+"stav2.c"; break;
      case 2: dest=PATH+"sroy.c"; break;
    }
    move_object(npc[2],dest);
  }
  if(!npc[3]) {
    string dest2;
    npc[3]=clone_object(MON_PATH+"dancer.c");
    switch(random(3)) {
      case 0: dest2=PATH+"smark.c"; break;
      case 1: dest2=PATH+"stav1.c"; break;
      case 2: dest2=PATH+"stav4.c";
              npc[3]->load_chats(({ }));
              break;
    }
    move_object(npc[3],dest2);
  }
  if(!npc[4])
    move_object(clone_object(PATH+"sandstorm.c"),query_location(random(LENGTH),random(WIDTH)));
  if(!npc[5]) {
    string dest3;
    npc[5]=clone_object(MON_PATH+"bld_eagle.c");
    switch(random(7)) {
      case 0: dest3=PATH+"stav1.c"; break;
      case 1: dest3=PATH+"stav2.c"; break;
      case 2: dest3=PATH+"sroy.c"; break;
      case 3: dest3=PATH+"sgate.c"; break;
      case 4: dest3=PATH+"smerch.c"; break;
      case 5: dest3=PATH+"sshop2.c"; break;
      case 6: dest3=PATH+"barrack1.c"; break;
    }
    move_object(npc[5],dest3);
  }

}

void init() {
  if(environment(this_player())==this_object())
    move_object(this_player(),query_location(7,2));
}

object query_location(int x, int y)
{
  object room;
  room=room_list[y*WIDTH+x];
  if(!room)
  {
    room=load_room(x,y);
    room_list[y*WIDTH+x]=room;
  }
  return room;
}

object load_room(int x, int y)
{
  object room;

  if(x==7 && y==2)
    room=clone_object(PATH+"xoasis.c");
  else if(x==3 && y==2)
    room=clone_object(PATH+"xvillage.c");
  else if(x==6 && y==4)
    room=clone_object(PATH+"xmound.c");
  else if(x==2 && y==8)
    room=clone_object(PATH+"xrocks.c");
  else if(x==6 && y==7)
    room=clone_object(PATH+"xsudak.c");
  else if(x==3 && y==6)
    room=clone_object(PATH+"xoasis2.c");
  else if(x==1 && y==4)
    room=clone_object(PATH+"xcastle.c");
  else if(x==0)
    room=clone_object(PATH+"xmount.c");
  else
    switch(random(2))
    {
      case 0: room=clone_object(PATH+"xdesert1.c");
              break;
      case 1: room=clone_object(PATH+"xdesert2.c");
              break;
    }
  room->set_coords(x,y);
  return room;
}
void remove_object(object prev)
{
  int i;
  for(i=0; i < sizeof(room_list); i++)
    if(room_list[i])
      destruct(room_list[i]);
}
/******************************************************************
                    Physical attributes   
******************************************************************/
int id(string str)
{
  return str=="map";
}

string short()
{
  return "The Great Map of the Desert";
}

void long(string str)
{
  int i;
  for(i=0; i < sizeof(room_list); i++)
  {
    if(i % WIDTH == 0)
      write("\n");
    if(room_list[i])
      write("*");
    else
      write(".");
  }
}
