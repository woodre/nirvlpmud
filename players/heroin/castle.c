#define NAME "Heroin"
#define DEST "room/plane5"
#define OBJ clone_object("/players/heroin/info.c")
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

id(str) { return str == "grounds"; }

short() {
    return "The Hunting grounds of " + NAME;
}

long() {
write("This is the Hunting Grounds of Heroin.  Doesn't really look like\n"+
"a castle, looks more like a meat locker.  And Another thing, who's \n"+
"staring at you...Jesus, that guy has some nerve, doesn't he know\n"+
"who you are?? Maybe you should ENTER GROUNDS and show 'em whose boss\n");
    write(" I saw the greatest of all men and i found him all too human.\n");
}

init() {
  add_action("enter", "enter");
}

enter(str) {
if (!id(str))
return 0;
move_object(this_player(), "/players/heroin/hunting_grounds/hunt2.c");
write ("You have chosen to join the Hunt..May your God have mercy.\n");
command("look", this_player());
    return 1;
}

reset(arg) {
object ob;
    if (arg)
	return;
    move_object(this_object(), DEST);
/*
 call_other("room/quest_room.c", "short", 0);

    if(!present("*sabbath*", find_object("room/quest_room.c"))) {
   ob = clone_object("obj/quest_obj");
   call_other(ob, "set_name", "*sabbath*");
   call_other(ob, "set_hint",
   "The legendary hunt of the Elders is being influenced, You need\n"+ 
   "to solve the mystery and restore order to the hunting grounds.\n"+
   "Ask the GameMaster about your quest.\n"); 
   move_object(ob, "room/quest_room");
  } 
*/
}
is_castle(){return 1;}
