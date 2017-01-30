#define NAME "Catt"
#define DEST "room/plane9"
#include "/players/catt/AREAS/base_defines.c"
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

id(str) { return str == "gates"; }

short() {
   return "A set of gates to the north [open]";
}

long() {
   write("There is a beautiful valley to the north.\n");
/*
         "but the gates are locked and you can't get \n"+
         "through them.\n");
*/
}

init() {
  add_action("enter", "enter");
}
enter(str) {
    if (!id(str))
	return 0;
call_other(this_player(), "move_player", "enters gates#"+VALLEY+"valley1");
/* 08/23/06 Earwax: No need to keep logging this
  write_file("/players/catt/ENTER_LOG",
        this_player()->query_name()+" entered valley!\n");
*/
    return 1;

}
reset(arg) {
/* Changing this.... Rumplemintz
   object portal;
   object ob;
   tell_room("room/vill_track","hello");
    if(!present("path", find_object("room/vill_track.c"))) {
     portal = clone_object("players/catt/portal.c");
     move_object(portal, "room/vill_track");
     }
*/
  if(arg)
    return;
    move_object(this_object(), DEST);
/* Added following to replace above commented out section - Rumplemintz */
  "/room/vill_track"->loadingtheroomblablah();
  move_object(clone_object("/players/catt/portal"), "room/vill_track");
/* load_files added so I could autoload certain objects. */
   /*
   This guild isn't open.  Don't autoload it if it ain't open.
      Vertebraker [5.31.01]

   load_files();
  */
}
is_castle() { return 1; }
load_files() {
   object ob;
   ob = clone_object("players/catt/GUILD/DEMON/demon_soul.c");
   destruct(ob);
   return 1;
}
