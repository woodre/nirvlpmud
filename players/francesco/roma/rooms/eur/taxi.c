#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("emperor")) {
  move_object(clone_object("/players/francesco/roma/mobs/taxidriver.c"),
	this_object()); }

set_light(1);

short_desc = "Taxi cab" ;
long_desc =
     "   taxi\n",

items = ({
   });

dest_dir = ({
  "/players/francesco/roma/rooms/vi11.c","east",
  "/players/francesco/roma/rooms/vi9.c","west"
});

}


init(){
      ::init();
      }


realm() {
if(this_player()->query_attack()) return "NT"; }



/*
->> Jenny tells you: if the crash kills them, you'd want the death notice to say the died
 from a crash right?  and not the taxi driver?

You invisibly fratell Jenny: woo!   good point   :)

Jenny tells you: so you'd have monster_died start about a 1 or 2 second call_out, 
which loads a monster file named "A car crash"  or something like that.  
and that would do 100 or so hit_player damage to them

Jenny tells you: then after the crash, the doors could unlock
*/
