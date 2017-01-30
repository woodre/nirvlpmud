#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "/players/brittany/room";
#include "/open/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(0);
   
short_desc = RED+"DIS"+NORM;
   long_desc =
   "     You have entered the city of DIS, Hell's capital city.  It\n"+
   "is the largest of the two mirror-image cities.  Arterial conduits\n"+
   "carrying bloody mortars crisscross the cities.  Bricks and tissues\n"+
   "are layered over huge frameworks.  An array of different size\n"+
   "buildings line the city.  A dark cloud over one building draws\n"+
   "your attention.\n";

   items = ({
     "city","The city is built by thousands of toiling souls",
     "mirror-images","The cities are near images of each other",
     "bones","The bones are covering the two growing sites",
     "souls","The souls are swarming over bones",
     "caverns","The caves of two cities, that are images of each other",
     "cloud","A dark cloud hangs over one building of the city",
     "buildings","The buildings are made out of bricks and tissues of toiling souls",
     "building","A dark cloud hangs over this building, maybe you should 'enter' it",
     "cities","The cities are covered by thousands of toiling souls swarming over bones",
});
   dest_dir = ({
"/players/brittany/inferno/inf4.c","back",
"/players/brittany/inferno/inf11.c","enter",
});
}

init() {
   ::init();
if(random(3) == 0) {
this_player()->set_fight_area(); }
  add_action("back","back");
  add_action("enter","enter");
}
enter(str) {
   write("You enter the building.\n");
   say(tpn+"  E N T E R S  the building.\n");
tp->move_player("into the unknown#/players/brittany/inferno/inf11.c");
    return 1;
}

back(str){
tp->move_player("back#/players/brittany/inferno/inf4.c");
return 1; }

