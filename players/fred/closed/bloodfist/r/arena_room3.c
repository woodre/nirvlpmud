
   	/*  arena_room3.c  */
inherit "players/fred/closed/bloodfist/obj/arena_inherit";
#include "/players/fred/closed/bloodfist/defs.h"
int torch;
#include "/players/fred/closed/bloodfist/r/torches.h"

reset(arg){
	if(arg) return;

  torch = 1;
  set_light(1);
  set_no_clean(1);

  items =({
    "torches",
      "The torches are mounted on the stone walls of the arena",
    "doors",
      "The doors are hard to really see from this far away",
    "sky",
      "The sky is a mass of darkness and blowing sand",
    "darkness",
      "The sky is a mass of darkness and blowing sand",
    "ground",
      "The ground is hard and desolate, cracked and littered with sand",
    "sand",
      "A thin layer of sand coats the ground",
    "cracks",
      "Tiny cracks form an intricate pattern beneath your feet in the ground",
    "walls",
      "The walls of the arena are massive barriers of stone which reach\n"+
      "upwards of ten feet into the sky.  There are many gashes visible\n"+
      "in them from prior battles held here",
  });

  dest_dir=({
    DIR + "r/arena_room1.c", "south",
    DIR + "r/arena_room2.c", "southeast",
    DIR + "r/arena_room4.c", "east",
  });

  enable_commands();
}

short(){ return "An arena in the desert"; }

long(str){
  if(torch)
    long_desc = 
"  You stand in the northwest corner of the arena.  Thick stone walls\n"+
"climb about ten feet into the air around the edge of the arena.\n"+
"On the southern wall of the arena two large metal doors are visible.\n"+
"The ground of the museum is flat, hard rock, coated by a thin layer\n"+
"of sand that is constantly being pushed around by the wind.  The sky\n"+
"above is a shroud of darkness.  Lit torches line the walls here.\n";
  else
    long_desc = 
"  You stand in the northwest corner of the arena.  Thick stone walls\n"+
"climb about ten feet into the air around the edge of the arena.\n"+
"On the southern wall of the arena two large metal doors are visible.\n"+
"The ground of the museum is flat, hard rock, coated by a thin layer\n"+
"of sand that is constantly being pushed around by the wind.  The sky\n"+
"above is a shroud of darkness.  The torches on the walls here have\n"+
"all been extinguished.\n";
  ::long(str);
}

void init(){
  ::init(); 
  add_action("extinguish", "extinguish");
  add_action("light", "light");
  add_action("search", "search");
  add_action("open", "open");
}

void catch_tell(string str){
  tell_room("/players/fred/closed/bloodfist/r/arena_stands.c", 
    BOLD+BLK+"[A] "+NORM+str);
}

int search(string what){
  if(what != "ground" && what != "sand" && what != "floor") return 0;
  write("You search the "+what+" and discover a trapdoor hidden by\n"+
    "the sand.  It doesn't look as though it has been used in ages.\n");
  tell_room(this_object(), this_player()->query_name()+
    " searches the area.\n", ({ this_player() }));
  return 1;
}

int open(string what){
  if(what != "door" && what != "trapdoor") return 0;
  write("You try to open the trapdoor however it is too heavy to move.\n");
  tell_room(this_object(), this_player()->query_name()+
    " tries to open the trapdoor but can't.\n", ({ this_player() }));
  return 1;
}

int enter(string what){
  if(what != "door" && what != "trapdoor") return 0;
  write("You try to enter the trapdoor except it isn't open.\n");
  tell_room(this_object(), this_player()->query_name()+
    " tries to enter the trapdoor but it isn't open.\n", ({ this_player() }));
  return 1;
}

