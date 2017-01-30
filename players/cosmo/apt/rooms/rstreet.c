/* Street Room */
#define tp this_player()->query_name()
#define mp this_player()->move_player
#include "/players/cosmo/closed/ansi.h" 
inherit "players/cosmo/dc/dcroom";

int cover_test;

reset(arg) {
  if(arg) return;
  set_light(1);
  set_room_type("street");
  short_desc=GRN+"Upper East Side"+NORM;
  long_desc=
"You arrive on the side of a street running east-west on the\n"+
"upper east side of town.  Traffic is light here, but the cars\n"+
"that drive by, drive very fast.  Shops and apartment buildings\n"+
"line the sides of the streets.  One building in particular stands\n"+
"out above the rest.  You also notice a slightly open manhole in\n"+
"front of you.\n",

  items= ({
    "manhole","You might be able to slide the cover off and crawl down",
    "buildings","Old dirty buildings. Who knows what you might find in them",
    "building","A large apartment building.  You could probably enter it",
    "shops","All of the typical city shops may be found along this street",
  });

   dest_dir= ({
     "players/cosmo/apt/rooms/rs1", "east",
     "players/cosmo/apt/rooms/rs2", "west",
     "players/cosmo/dc/rooms/path/p4", "south",
     "players/cosmo/apt/rooms/lobby", "enter",
   });
}

init() {
  ::init() ;
  add_action("slide","slide");
  add_action("crawl","crawl");
}

slide(arg) {
   if(!arg) {
      write("What would you like to slide?\n"); return 1; }
   if(arg !="cover") {
      write("That cannot be slid.\n");
      return 1;
   }
   write("You use all your strength to push the manhole");
   write(" cover off to the side.\n");
   say(capitalize(tp)+" slides the cover off the manhole.\n");
   cover_test = 1;
   return 1;
}

crawl(arg) {
   if(!arg) {
      write("Where would you like to crawl?\n"); return 1; }
   if(arg !="down") {
      write("You cannot crawl in that direction.\n"); return 1; }
   if(cover_test != 1) {
      write("You must remove the cover first!\n"); return 1; }
   write("You crawl down into the darkness.\n");
   say(capitalize(tp)+" crawls down the manhole.\n");
   mp("down the manhole#/players/cosmo/apt/rooms/hole.c");
   return 1;
}
