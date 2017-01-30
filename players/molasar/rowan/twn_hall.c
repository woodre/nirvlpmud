
#include "/room/clean.c"

reset(arg) {
   if(!arg)
     set_light(1);
   extra_reset();
}

extra_reset() {
   object board;
   if(!present("bboard")) {
     board = clone_object("/players/molasar/rowan/obj/bboard");
     move_object(board, this_object());
   }
}

short() { return "The Town Hall of Rowan  [n]"; }

long() { 
   write("You are in the Town Hall of Rowan.\n");
   write("Here you can read news of the town or post questions/comments\n");
   write("     There is one obvious exit:   north\n");
}

init() {
   add_action("north","north");
}

north() {
   this_player()->move_player("north#players/molasar/rowan/e_twn_sq");
   return 1;
}

