#define NAME "mistress"
#define DEST "room/vill_shore2"
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

id(str) { return str == "library"; }

short() {

  return "There is a path leading north towards an elegant library";
}

long() {

    write("This is the library owned by Mistress.\n");
}

init() {
  add_action("enter", "enter");
  add_action("enter", "north");
  add_action("enter", "n");
}

enter(str) {
   call_other(this_player(), "move_player", "north#players/mistress/path/entrance.c");
    return 1;
}
reset(arg) {
   object room,quest;
   object guildgem, mygem;
   room = find_object("room/quest_room");
   if(!present("disk_quest",room)) {
     quest = clone_object("obj/quest_obj");
     quest->set_name("disk_quest");
     quest->set_hint("Goto the library, find the disk and return it to the scientist.\n");
     move_object(quest,room); }
   if(arg)
     return;
/*
   guildgem = clone_object("players/mistress/closed/guild/obj/riders_gem.c");
   mygem = clone_object("players/mistress/closed/guild/obj/mygem.c");
   */
   move_object(this_object(),DEST); }

is_castle(){return 1;}
