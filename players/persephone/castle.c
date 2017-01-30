#define NAME "persephone"
#define DEST "room/hump"
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

id(str) { return str == "portal"; }

short() {
   return "The portal of fate";

}
is_castle() { return 1; }

long() {
    write("This is a strange portal if you trust your fate perhaps you should enter it'.\n");
}

init() {
  add_action("enter", "enter");
}

enter(str) {
   if(str != "portal") {
     write("Enter what??\n");
     return 1;
   }
   write("\n\n");
   write("You feel sort of strange as magical forces bend your body into and out \n");
   write("of shape. Finally you reach your destination and feel almost normal\n");
   write("\n\n");
   call_other(this_player(), "move_player",
             "enter#players/persephone/rooms/hall");
   return 1;
}
reset(arg) {
    if (arg)
        return;
    move_object(this_object(), DEST);
}
