#define NAME "Morgoth"
#define DEST "room/plane7"
object quest, room;
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

id(str) { return str == "castle"; }

short() {
    return "Castle of " + NAME;
}

long() {
    write("This is the " + short() + ".\n");
}

init() {
  add_action("enter", "enter");
}

enter(str) {
    call_other(this_player(), "move_player", "enter#players/morgoth/CASTLE/entrance1");
return 1;
return 0;
}

reset(arg) {
    if (arg)
	return;
  room = find_object("room/quest_room");
  if(!present("cyclops_mace", room))
  {
    quest = clone_object("obj/quest_obj");
    quest -> set_name("cyclops_mace");
    quest -> set_hint("Go to Morgoth's castle. Find the missing four items.  Return them to the prize room.  Go to the prize room for more information !\n");
    move_object(quest, room);
   }
    move_object(this_object(), DEST);
}

is_castle() {return 1;}
