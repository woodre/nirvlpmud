#define NAME "haji"
#define DEST "room/eastroad3"
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

id(str) { return str == "road"||str=="path"||str=="haji"||str=="road of wonder"; }

short() {
  return "A golden road which makes you feel enlightened to the northwest";
}

long() {
    write("The road to the northwest leads northwest to New York,\n");
    write("which is home to the great seer Rush Limbaugh.\n");
}

init() {
  add_action("enter", "northwest");
         add_action("enter","nw");
}

enter() {
   call_other(this_player(),"move_player","leaves northwest to enlightenment #players/haji/rush/ny/gcsta");
    return 1;
}

reset(arg) {
   object ob1;

    if (arg)
	return;
/*
    move_object(this_object(), DEST);
*/
    call_other("players/haji/castle2","???",0);
/* quest replaced but left in for quest points  5/29/97 Eurale
   if (!present("grail", find_object("room/quest_room"))) {
      ob1 = clone_object("obj/quest_obj");
      call_other(ob1, "set_name", "grail");
      call_other(ob1, "set_hint", "Search out and find the holy grail.\n");
      move_object(ob1, find_object("room/quest_room"));
   }
*/
}
is_castle() {return 1;}
