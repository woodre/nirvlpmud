inherit "room/room";
#include "/players/zeus/closed/all.h"
#include "/players/zeus/closed/fl_demon.h"

int uncovered, locked, opened, teleport;

reset(arg){

   teleport = 0;  if(random(TFL_TLP)) teleport = 1;
   if(!present("hermit")) MO(CO("/players/zeus/realm/NPC/hermit.c"), TO);
   uncovered = 0;   /*  They have not uncovered the trapdoor yet   */
   locked = 1;      /*  trapdoor starts out locked   */
   opened = 0;      /*  trapdoor starts out closed   */

   if(arg) return;
  short_desc="The Fallen Lands";
  long_desc=
"This is a very old shack.  It is a single room with nothing in it.  The\n"+
"floor and all four of the walls are made of old boards of wood which\n"+
"have certainly seen better days.  The roof is also made of boards which\n"+
"are slanted down to the west.  The door is on the east side of the shack.\n";
  set_light(0);
  items=({
	      "floor",
"The floor of the shack is made of old boards of wood.  A thin layer of\n"+
"dirt coats the floor.  As you walk across it, your footsteps sound hollow",
		  "walls",
"The four walls of the shacks are constructed out of old boards of wood.\n"+
"They seem to be barely holding up the roof, and keeping the forest out",
		  "boards",
"The boards of wood themselves are rotted and many have holes.  The shack\n"+
"looks as though it could colapse at any time",
		  "roof",
"The roof slants to the west so the water will run off, however much of it\n"+
"leaks through anyway.  The boards don't work well as a roof",
		  "door",
"The simple door is barely hanging on it's hinges.  There are a number of\n"+
"small holes in it",
          "holes",
"There seem to be small holes in all of the boards of the shack.  Water is\n"+
"leaking in slowly from the roof, and the wind can be felt blowing through\n"+
"the shack as if there were no walls at all",
  });
  dest_dir=({  "/players/zeus/realm/taus/hermit1.c", "leave" });
}

  void init(){
	  ::init();
	  add_action("search_cmd", "search");
	  add_action("look_cmd", "look");
	  add_action("look_cmd", "l");
	  add_action("unlock_cmd", "unlock");
	  add_action("open_cmd", "open");
	  add_action("down_dir", "down");
	  add_action("down_dir", "d");
  }

exit(){    if(TP) TP->clear_fight_area();     }
okay_follow(){ return 1; }
realm(){   if(teleport) return "NT";    }

  status search_cmd(string str)
  {
	  if(present("hermit"))
	  {
		  write("The hermit won't let you search.\n");
		  say("The hermit stops "+TP->QN+" from searching.\n");
		  return 1;
	  }
	  if(!str)
	  {
		 write("You search the shack briefly and find nothing of interest.\n");
		 say(TP->QN+" searches around.\n");
		 return 1;
	  }
	  if(str == "floor" || str == "boards" || str == "ground")
	  {
		  if(uncovered == 0)
		  {
		  write("You search the floor and discover a trapdoor.\n");
		  say(TP->QN+" uncovers a trapdoor in the floor.\n");
		  uncovered = 1;
		  return 1;
		  }
		  else
			  write("Somebody has already uncovered the trapdoor.\n");
		  return 1;
	  }
	  else
		  return 0;
	  return 1;
  }

  status look_cmd(string str)
  {
	  if(!str)
		  return 0;
	  if(str == "at trapdoor")
	  {
		  if(uncovered == 1)
		  {
		  write(
"The trapdoor is a few feet wide and is in the back of the room.  There\n"+
"is a small lock on the latch which takes a key to unlock it.  The\n");
			if(locked == 0)
				  write("trapdoor is unlocked and ");
			if(locked == 1)
				  write("trapdoor is locked and ");
			if(opened == 1)
				  write("it is open.\n");
			if(opened == 0)
				  write("it is closed.\n");
		  return 1;
		  }
		  else
			  return 0;
		  return 1;
	  }
	  else
		  return 0;
	  return 1;
  }


  status unlock_cmd(string str)
  {
	  if(!present("hermit_key", TP))
		  return 0;
	  if(str == "trapdoor" || str == "the trapdoor")
	  {
	  if(present("hermit"))
	  {
		  write("The hermit prevents you from unlocking the trapdoor.\n");
		  say("The hermit stops "+TP->QN+" from unlocking the trapdoor.\n");
		  return 1;
	  }
	  if(locked == 0)
		  write("The trapdoor is already unlocked.\n");
	  else {
		  write("You unlock the trapdoor.\n");
		  say(TP->QN+" unlocks the trapdoor.\n");
		  locked = 0;
		  return 1;
	  }
	  return 1;
	  }
	  else
		  write("What do you want to unlock?\n");
	  return 1;
  }

  status open_cmd(string str)
  {
	  if(str == "trapdoor" || str == "the trapdoor")
	  {
	  	  if(present("hermit"))
		  {
			  write("The hermit stops you from opening the trapdoor.\n");
			  say("The hermit stops "+TP->QN+" from opening the trapdoor.\n");
			  return 1;
		  }
		  if(locked == 1)
		  {
			  write("The trapdoor is locked and can't be opened.\n");
			  say(TP->QN+" tries to open the trapdoor, but it is locked.\n");
			  return 1;
		  }
		  if(opened == 1)
			  write("The trapdoor is already open.\n");
		  else {
			  write("You open the trapdoor...  you could go 'down' into it.\n");
			  say(TP->QN+" opens the trapdoor.\n");
			  opened = 1;
			  return 1;
		  }
		  return 1;
	  }
	  else
		  write("What do you want to open?\n");
	  return 1;
  }

  status down_dir()
  {
	  if(locked == 1)
		  return 0;
	  if(opened == 0)
		  return 0;
	  if(present("hermit"))
		  return 0;
	  write("You go down through the trapdoor...\n");
	  TP->MP("trapdoor#/players/zeus/realm/taus/hermit4.c");
	  return 1;
  }

