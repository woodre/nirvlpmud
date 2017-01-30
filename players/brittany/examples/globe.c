#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = MAG+"Netherlands"+NORM;
   long_desc =
   "     Since the dawn of time humanity has shared the planet with\n"+
   "other worlds.  Travel through the Netherlands and explore a\n"+
   "universe of infinite possibilities.  Something is suspended in\n"+
   "mid-air.\n";

move_object(clone_object("/players/brittany/kadath/OBJ/sphere.c"),this_object());
   
   items = ({
         "map","An outline of a place named Kadath",
          });

   dest_dir = ({
  "/room/mine/tunnel.c","out",
              });
}

init() {
  add_action("out","out");
  add_action("spin_kadath","spin");
  add_action("spin_to_kadath","spin");
}

spin_kadath(str) {
    if(!str || str != "kadath") {
        notify_fail("Where do you want to spin?\n");
        return 0; }
write("You spin the globe it turns and turns, then lands on Kadath.\n\n");
say(this_player()->query_name()+" spins the globe to Kadath and then disappears.\n");
this_player()->move_player("kadath#/players/brittany/kadath/k1.c");
return 1; }

spin_to_kadath(str) {
    if(!str || str != "to kadath") {
        notify_fail("Where do you want to spin?\n");
        return 0; }
write("You spin the globe it turns and turns, then lands on Kadath.\n\n");
say(this_player()->query_name()+" spins the globe to Kadath and then disappears.\n");
this_player()->move_player("kadath#/players/brittany/kadath/k1.c");
return 1; }

out(str){
this_player()->move_player("out#/room/mine/tunnel.c");
return 1; }
