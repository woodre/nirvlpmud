
   	/*  arena_room1.c  */
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
      "The thick metal doors of the arena are intricately designed,\n"+
      "however many of the details of them are filled with sand and\n"+
      "difficult to make out.  They lead south out of the arena",
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
    DIR + "r/arena_room3.c", "north",
    DIR + "r/arena_room4.c", "northeast",
    DIR + "r/arena_room2.c", "east",
    DIR + "r/arena.c",       "leave",
  });

  enable_commands();
}

short(){ return "An arena in the desert"; }

long(str){
  if(torch)
    long_desc = 
"  You stand within the thick stone walls of the arena.  They climb about\n"+
"ten feet into the air all around you.  The large metal doors are south\n"+
"and provide the only exit to the encampment.  The ground of the arena is\n"+
"flat dry rock lined with small cracks and sand.  Darkness cloaks the sky\n"+
"overhead and the warmth of the desert presses down on you like a weight.\n"+
"Lit torches line the walls of the arena that flicker in the wind.\n";
  else
    long_desc = 
"  You stand within the thick stone walls of the arena.  They climb about\n"+
"ten feet into the air all around you.  The large metal doors are south\n"+
"and provide the only exit to the encampment.  The ground of the arena is\n"+
"flat dry rock lined with small cracks and sand.  Darkness cloaks the sky\n"+
"overhead and the warmth of the desert presses down on you like a weight.\n"+
"The torches on the walls are extinguished.\n";
  ::long(str);
}

void init(){
  ::init(); 
  add_action("extinguish", "extinguish");
  add_action("light", "light");
  add_action("leave", "leave");
}

int leave(){
  if(!this_player()->is_player()) return 1; 
  if(this_player()->query_ghost())
  {
    write("You must exit the arena by using the White Tunnel.\n");
    return 1;
  }
  "/players/fred/closed/bloodfist/r/arena.c"->reset_use();
  return 0;
}

void catch_tell(string str){
  tell_room("/players/fred/closed/bloodfist/r/arena_stands.c", 
    BOLD+BLK+"[A] "+NORM+str);
}

