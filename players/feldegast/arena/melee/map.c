#include "def.h"

mapping room_list;

object *players;

int *options;

int id(string str) { return str=="map"; }

void reset(int arg)
{
  string *rooms;
  int i;

  if(arg) return;
  rooms=ROOMS;
  room_list=([ ]);
  players=({ });
  for(i=0; i < sizeof(rooms); i++)
  {
    room_list[PATH+rooms[i]]=clone_object(PATH+rooms[i]);
    room_list[PATH+rooms[i]]->set_master(this_object());
  }
  call_out("hb",1);
}

void init()
{
  if(environment(this_player())==this_object())
    move_object(this_player(),room_list[ PATH+ROOMS[ random(sizeof(ROOMS)) ] ] );
}

object query_room(string str)
{
  return (object)room_list[str];
}


void remove_object(object caller)
{
  string *indices;
  int i;

  indices=keys(room_list);
  for(i=0; i < sizeof(indices); i++)
  {
    destruct(room_list[indices[i]]);
  }
  remove_call_out("hb");
}

void set_options(int *ops)
{
  options=ops;
}
hb() 
{
  int i;
  for(i=0; i < sizeof(players); i++)
  {
    if(players[i] && players[i]->query_ghost())
    {
      object corpse;
      corpse=present("corpse",environment(players[i]));
      if(corpse)
        move_object(corpse,"/players/feldegast/arena/rooms/recovery");
      tell_room(environment(players[i]),HIY+capitalize(players[i]->query_real_name())+" glows brightly, and then dematerializes before your eyes.\n"+NORM);
      move_object(players[i],"/players/feldegast/arena/rooms/recovery");
      command("regenerate",players[i]);
      command("get corpse",players[i]);
      remove_player(players[i]);
      i--;
    }
  }
  if(players[0]) call_out("hb",3);
}

void set_players(object *plyrs)
{
  players=plyrs;
}
void add_player(object plyr)
{
  players+=({ plyr });
}
void remove_player(object plyr)
{
  players-=({ plyr });
  if(sizeof(players)==0)
  {
    remove_object(this_object());
    destruct(this_object());
  }
}

/* Physical description */
string short()
{
  return "Map of Feldaria";
}
void long(string str)
{
  int health;
  int magic;
  int i;
  write("A map of the varying terrain of Feldaria.  You see people moving\n"+
        "about on the map.\n");
  write(pad("Name",20)+pad("Health",20)+pad("Magic",20)+"Location\n");
  for(i=0; i < sizeof(players); i++)
  {
    if(players[i])
    {
      health=( ( (int)players[i]->query_hp() )*100 ) / ( (int)players[i]->query_mhp() );
      magic= ( ( (int)players[i]->query_sp() )*100 ) / ( (int)players[i]->query_msp() );
      write(pad((string)players[i]->query_name(),20));
      write(pad(health+"%",20));
      write(pad(magic+"%",20));
      write((string)environment(players[i])->short());
      write("\n");
    }
    else
    {
      write("MISSING!\n");
      remove_player(0);
    }
  }
}

int query_spar()
{
  return options[3];
}
