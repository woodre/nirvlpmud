#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = RED+"Water Region"+NORM;
   long_desc =
   "     A strong rainfall pours down in this region.  Water abounds\n"+
   "in all its states.  There is almost no dry land in this region.\n"+
   "A huge snow mountain rises out of the center.  Some flavored icicles\n"+
   "are growing down beside a waterfall of melted snow.\n";
   
   items = ({
         "boulder","A huge rock with an imprint of a hairy fist knocked into it",
          });

   dest_dir = ({
         "/players/brittany/xanth/fen.c","west",        
              });
}

init() {
   ::init();
   add_action("search","search");
  }

search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}
