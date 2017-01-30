
   	/*  arena_room4.c  */
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
    "door",
      "The small door is made of wood and has no handle or way to open it\n"+
      "from this room.  It is used for opponents to enter the arena",
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
    DIR + "r/arena_room2.c", "south",
    DIR + "r/arena_room1.c", "southwest",
    DIR + "r/arena_room3.c", "west",
  });

  enable_commands();
}

short(){ return "An arena in the desert"; }

long(str){
  if(torch)
    long_desc = 
"  You stand in the northeast corner of the arena.  Thick stone walls\n"+
"climb about ten feet into the air around the edge of the arena.\n"+
"On the eastern wall of the arena is a small sidedoor for opponents\n"+
"to enter the arena through.  It can not be opened from here.  The\n"+
"sky is dark above and the ground is dry and dead, coated with sand.\n"+
"Many torches line the walls of the arena, all of which are lit.\n";
  else
    long_desc = 
"  You stand in the northeast corner of the arena.  Thick stone walls\n"+
"climb about ten feet into the air around the edge of the arena.\n"+
"On the eastern wall of the arena is a small sidedoor for opponents\n"+
"to enter the arena through.  It can not be opened from here.  The\n"+
"sky is dark above and the ground is dry and dead, coated with sand.\n"+
"Torches line the walls of the arena, all of which are extinguished.\n";
  ::long(str);
}

void init(){
  ::init(); 
  add_action("extinguish", "extinguish");
  add_action("light", "light");
  add_action("open", "open");
  add_action("enter", "enter");
}

void catch_tell(string str){
  tell_room("/players/fred/closed/bloodfist/r/arena_stands.c", 
    BOLD+BLK+"[A] "+NORM+str);
}

int open(string what){
  if(what != "door") return 0;
  write("You try to open the door but it doesn't open from this side.\n");
  tell_room(this_object(), this_player()->query_name()+
    " tries to open the door.\n", ({ this_player() }));
  return 1;
}

int enter(string what){
  if(what != "door") return 0;
  write("You try to enter the door but you can't from here.\n");
  tell_room(this_object(), this_player()->query_name()+
    " tries to enter the door.\n", ({ this_player() }));
  return 1;
}

