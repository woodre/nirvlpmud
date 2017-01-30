#define NAME "Cyrex"
#define DEST "room/plane4"
/*
* This is just the facade to a castle. If you want to enable the
* "enter" command, move the player to a hall or something (which
   * you have to design yourself).
* The predefined string DEST is where a player should come when he
* leaves the castle.
*
* This file is loaded automatically from "init_file". We have to move
* ourself to where we are supposed to be.
*/

id(str) { return str == "fortress"; }
is_castle() {return 1;}

short() {
   return "A huge space fortress";
}

long() {
   write("    You see in front of you the most incredible space fortress\n");
   write("ever built! You've heard about this ship since you were a kid\n");
   write("and wondered when you will be able to explore it. Now right here\n");
   write("in front of you it rests. The fortress looks like it has been\n");
   write("through a lot and has deterioated over time.  You notice a huge\n");
   write("rip on the side of the ship just enough for you to go through,\n");
   write("do you dare enter?\n");
}

init() {
   add_action("enter", "enter");
}

enter(arg) {
   this_player()->move_player("into fortress#players/cyrex/corridor");
   return 1;
}

reset(arg) {
   object room,quest;
   room=find_object("/room/quest_room");
   if(!present("protoculture",room)){
      quest=clone_object("/obj/quest_obj");
      quest->set_name("protoculture");
	quest->set_hint(
	  "Destroy the Protocultural Orb hiddend deep within the fortress\n");
      move_object(quest,room);
   }
   if (arg)
      return;
   move_object(this_object(), DEST);
}
