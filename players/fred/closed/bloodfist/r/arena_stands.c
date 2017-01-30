inherit "/room/room";
#include "/players/fred/closed/bloodfist/defs.h"
int torch;
#include "/players/fred/closed/bloodfist/r/torches.h"

reset(arg){
  if(arg) return;

  torch = 1;
  set_light(1);
  set_no_clean(1);

  items =({
    "walls",
       "The stone walls of the arena climb about eight feet into the air",
    "ground",
      "The ground of the encampment is dry and littered with sand",
    "sand",
      "A thin layer of sand coats the ground",
    "sky",
      "The sky is a mass of darkness and blowing sand",
    "darkness",
      "The sky is a mass of darkness and blowing sand",
    "staircase",
      "The metal staircase wraps around the outside of the arena leading\n"+
      "down to the ground floor of the encampment",
  });

  dest_dir =({ DIR+"r/arena.c", "down" });
}

short(){ return "An arena in the desert"; }

long(str){
  if(torch)
    long_desc =
"  This is a small sitting area which has been built above the arena for\n"+
"spectators to watch.  It provides an excellent view of all the action\n"+
"that occurs within its walls.  There is a narrow metal staircase which\n"+
"leads down to the ground of the encampment.  Numerous torches line the\n"+
"stands here providing light for the area.  The wind is blowing strongly.\n";
  else
    long_desc = 
"  This is a small sitting area which has been built above the arena for\n"+
"spectators to watch.  It provides an excellent view of all the action\n"+
"that occurs within its walls.  There is a narrow metal staircase which\n"+
"leads down to the ground of the encampment.  Numerous torches line the\n"+
"stands here however they are all extinguished.  The wind is strong here.\n";
  ::long(str);
}

void init(){
  ::init();
  add_action("extinguish", "extinguish");
  add_action("light", "light");
}
