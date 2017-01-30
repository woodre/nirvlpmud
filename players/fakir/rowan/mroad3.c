
#include "/room/clean.c"

reset(arg) {
   if(!arg)
     set_light(1);
}

short() { return "The Road to the Mountains  [nw,u]"; }

long() {
   write("You are at the foot of the Mountains.\n");
   write("A long spiralling path leads up into the mountains.\n");
   write("     There are two obvious exits:  northwest and up\n");
}

init() {
   add_action("northwest","northwest");
   add_action("up","up");
}

northwest() {
   this_player()->move_player("northwest#players/molasar/rowan/mroad2");
   return 1;
}

up() {
   this_player()->move_player("up#players/molasar/rowan/mtn/path1");
   return 1;
}


