#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "/players/brittany/room";

reset(arg) {
   if(arg) return;
   set_light(0);
   
short_desc = RED+"Inferno"+NORM;
   long_desc =
   "     Inset into the gumlike ceiling and the floor of an unimaginably\n"+
   "huge organic cavern are two cities.  They are near mirror-images\n"+
   "perpetually in a state of construction.  Each city is built by\n"+
   "thousands of toiling souls swarming over the bones covering the\n"+
   "two growing sites.  Each site in the caverns are demonic entities\n"+
   "that erode the human spirit.\n";

   items = ({
     "ceiling","The ceiling is gumlike inside of the huge organic cavern of two cities",
     "floor","The floor is inset into the huge organic cavern of two cities",
     "city","The city is built by thousands of toiling souls",
     "mirror-images","The cities are near images of each other",
     "bones","The bones are covering the two growing sites",
     "souls","The souls are swarming over bones",
     "caverns","The caves of two cities, that are images of each other",
     "spirit","A supernatural being, the mind of souls",
     "cities","The cities are covered by thousands of toiling souls swarming over bones",
});
   dest_dir = ({
"/players/brittany/inferno/inf3.c","southwest",
"/players/brittany/inferno/inf13.c","city1",
});
}

init() {
   ::init();
if(random(3) == 0) {
this_player()->set_fight_area(); }
  add_action("city1","city1");
}

city1(str) {
   this_player()->move_player("inf13#/players/brittany/inferno/inf13.c");
   return 1;
}

