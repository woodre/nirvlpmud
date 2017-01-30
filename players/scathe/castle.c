#define NAME "scathe"
#define DEST "/room/sea.c"
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

id(str) { return str == "cavern"; }

short() {
   return "A large Cavern to the south";
}

long() {
   write("This is a large dark cavern.\n");
   write("Maybe you should enter it.\n");
}

init() {
  add_action("south", "south");
}

south() {
   this_player()->move_player("south#/players/scathe/cave/entry");
   return 1;
}

reset(arg) {
object room,quest;
room = find_object("room/quest_room");
if(!present("rod_quest", room)) {
   quest = clone_object("obj/quest_obj.c");
   quest->set_name("rod_quest");
   quest->set_hint("Seek the 4 parts of the rod at the cavern by the sea and assemble\n");
   move_object(quest,room);
}
   if (arg)
      return;
   move_object(this_object(), DEST);
}
is_castle(){return 1;}
