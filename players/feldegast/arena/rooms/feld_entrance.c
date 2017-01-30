#include "/players/feldegast/defines.h"

inherit ROOM;

object map;

void reset(int arg)
{
  if(arg)return;
  move_object(clone_object("/players/feldegast/arena/misc/prizebox.c"),this_object());
  set_short("A quiet room");
  set_long(
"  This is a quiet and serene room with a cool marble floor.  In the center\n\
of the floor is a pattern of tiles in the shape of the scales of justice.\n\
In the four corners of the room are busts of stern looking warriors.  A\n\
pair of torches guttering with blue flame are on either side of a portal\n\
filled with azure light.\n");
  set_light(1);
  set_no_fight(1);
  set_indoors(1);
  set_no_teleport(1);
  set_dest_dir(({
    "/players/feldegast/arena/rooms/inner.c","west",
  }));
}

void init()
{
  ::init();
  add_action("cmd_west", "west");
  add_action("cmd_enter","enter");
}

int cmd_enter(string str)
{
  notify_fail("Enter what?\n");
  if(!str) return 0;
  if(str!="portal") return 0;
  if((int)TP->query_pl_k() < 2) {
    write("You must set your pk spar flag using the command 'kill_players spar'.\n");
    say(TPN+" bounces off of the portal.\n");
    return 1;
  }
  say(TPN+" steps through the azure portal.\n");
  write("You step through the azure portal.\n");
  if(!map)
  {
    map=clone_object("/players/feldegast/arena/melee/map.c");
    map->set_options(({1,0,0,1,0}));
    move_object(map,this_object());
  }
  move_object(this_player(),map);
  command("look",this_player());
  map->add_player(this_player());
  write_file("/players/feldegast/log/sparring.log",ctime(time())+" "+TPN+" entered Feldaria.\n");
  say("An azure portal rises up out of the ground.\n"+TPN+" steps out of it.\nThe azure portal promptly closes again.\n");
  return 1;
}

int query_spar_area() { return 1; }

int cmd_west(string str) {
  if((int)TP->query_pl_k() > 1) {
    TP->rm_spar();
    write("Sparring flag removed.\n");
  }
  ::cmd_move(str);
  return 1;
}
