#define NAME "sandman"
#define DEST "room/well"
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

id(str) { return str == "bed"; }

short() {
   return "A comfortable looking bed";

}

long() {
    write("This is a nice bed, maybe you should 'lay on bed'.\n");
}

init() {
  if(this_player()) this_player()->add_exp(1);
  add_action("lay", "lay");
}

lay(str) {
   if(str != "on bed") {
     write("Lay on what??\n");
     return 1;
   }
   write("\n\n");
   write("As soon as your head hits the pillow, you fall into a deep sleep.\n");
   write("Your soul leaves your body, and enters into the realm of dreams!\n");
   write("\n\n");
   call_other(this_player(), "move_player",
             "enter#players/sandman/SURR/path1");
   return 1;
}

reset(arg) {
   object ob,room;
   call_other("room/vill_road2","short",0);
   room = find_object("room/vill_road2");
/*
   if(!present("statue",room)) {
   ob = clone_object("players/sandman/OBJ/cstatue");
   move_object(ob,room);
   }
*/
   /* Force load of Paladin facade */
/*
   call_other("/players/sandman/paladin/facade","???");
   call_other("/players/sandman/closed/engage","???");
*/
    if (arg)
	return;
    move_object(this_object(), DEST);
}
is_castle() { return 1; }
