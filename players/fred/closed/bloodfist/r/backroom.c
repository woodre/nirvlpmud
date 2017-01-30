inherit "room/room";
#include "/players/zeus/closed/ansi.h"
#include "/players/fred/closed/bloodfist/defs.h"
int torch;
#include "/players/fred/closed/bloodfist/r/torches.h"

reset(arg){
	if(arg) return;

  torch = 1;
  set_light(1);
  set_no_clean(1);
  call_out("check",1);

  add_property("no_teleport");

  items =({
    "torches",
      "The torches are mounted on the stone walls of the arena",
    "sky",
      "The sky is a shroud of darkness and swirling sand",
    "ground",
      "The ground is destolate, cracked and broken",
    "sand",
      "The ground is caked with a layer of dry sand",
    "mountains",
      "The encampment is built around some mountains of rock that jut\n"+
      "out of the earth at almost as sharp an angle as the walls of the\n"+
      "encampment itself",
    "benches",
      "There are some long wooden benches here for people to relax on",
    "equipment",
      "Some swords, shields and various other pieces of equipment are\n",
      "hanging on the walls of the room",
    "swords",
      "Numerous swords of varrying lengths line the walls",
    "shields",
      "Numerous shields of varrying sizes line the walls",
    "horizon",
      "The mountains make up the horizon, which is constantly shrouded\n"+
      "by the sands whipping through the air",
  });

  dest_dir=({
    DIR + "r/arena.c",       "leave",
  });
}

short(){ return "An encampment in the desert"; }

long(str){
  if(torch)
    long_desc =
"  You are in the back area of the arena.  It is very dark here.  If not\n"+
"for the lit torches on the walls it would be pitch black.  There are\n"+
"numerous wooden benches here, as well as various pieces of equipment\n"+
"hanging on the walls.  The only exit from here leads back out to the\n"+
"entrance of the arena.\n";
  else
    long_desc = 
"  You are in the back area of the arena.  It is very dark here.  There are\n"+
"numerous wooden benches here, as well as various pieces of equipment\n"+
"hanging on the walls.  The only exit from here leads back out to the\n"+
"entrance of the arena.\n";
  ::long(str);
}

void init(){
  ::init();
  add_action("extinguish", "extinguish");
  add_action("light", "light");
}

check()
{
  object a;
  object b;
  a = present("bf_trial_mob", this_object());
  b = present("white tunnel", this_object());
  if(a)
  {
    move_object(a, "/room/void");
    destruct(a);
  }
  if(b)
  {
    destruct(b);
  }
}


