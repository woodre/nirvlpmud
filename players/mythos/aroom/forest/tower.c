/* 10/11/05 Earwax: Made room land. */

inherit "/players/earwax/housing/land.c";
#include "/players/mythos/closed/ansi.h"
#define tp this_player()->query_name()
inherit "room/room";
reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/amon/forest/sound.c"),this_object()); }
  if(!present("ryo")) {
    move_object(clone_object("/players/mythos/amon/forest/ryo2.c"),this_object()); }
  if(!arg) {
  set_light(0);
    short_desc = "Tower Entrance";
    long_desc =
    "You stand before a Tall Dark Tower.  For some reason your eyes seem \n"+
     "to glance over it as if the Tower "+BOLD+"doesn't"+NORM+" want you to\n"+
     "'gaze' at it. The 'shadows' move and you see something odd beyond the\n"+
     "Tower.\nBeaware that once you enter this tower others may kill you."+
    "\n";
  items = ({
    "enter","The tower looks frightening... perhaps entering is not a good idea",
    "back","You see the bridge behind you",
    "around","Behind the tower you see something odd....",
    "shadows","Another ryos seems to haunt this place",
    "rope","You see the rope across the river...it seems unsafe....",
  });

  dest_dir = ({
    "/players/mythos/aroom/forest/tower2.c","enter",
    "/players/mythos/aroom/forest/bridge2.c","back",
    "/players/mythos/aroom/forest/clear.c","around",
    "/players/mythos/aroom/forest/around.c","rope",
  });
  set_realm_name("Ancient");
  set_lot_size(9);
  set_cost(500000);
  setup_land();
} }

init() {
  ::init();
  add_action("gaze_tower","gaze");
  add_action("around","around");
  add_action("enter","enter");
}

gaze_tower() {
  object ryo2;
  write("The Tower seems to grow angry!\n"+
    "The wind blows and the trees shake!\n"+
    HIB+"\n\tC R A C K\n"+NORM+
    "\nA bolt of lightning hits you!\n");
  say("You notice the wind seems to blow harder!\n"+
    "The trees shake and suddenly....\n\n"+
    HIB+"\tC R A C K\n\n"+NORM+
    "You see a bolt of lightning hits "+this_player()->query_name()+ "!\n");
  call_other(this_player(),"add_hit_point",-200);
  ryo2=clone_object("/players/mythos/amon/forest/ryo2.c");
  call_other(ryo2,"set_aggressive",1);
  move_object(ryo2,this_object());
return 1; }

enter() {
  write_file("/players/mythos/logs/tower",ctime(time())+"\t"+this_player()->query_real_name()+
  "\t\t"+this_player()->query_level()+"\ttower\n");   return 0;}
  
around() {
write_file("/players/mythos/logs/tower",ctime(time())+"\t"+this_player()->query_real_name()+
"\t\t"+this_player()->query_level()+"\tclear\n");   return 0;}
