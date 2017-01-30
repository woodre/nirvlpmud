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
    "     Arterial conduits carrying bloody mortars crisscross the cities.\n"+
    "Bricks and tissue are layered over osteo-framesworks.  The work on\n"+
    "the inverted city goes as smoothly as its counterpart with one\n"+
    "brick after another falling upward into place.  After hundreds\n"+
    "of years both cities are complete.\n";

   items = ({
     "conduits","The arterial channels carrying bloody mortars",
     "mortars","The bloody mortars crisscross the cities",
     "bricks","The bricks are layered over the frameworks",
     "city","The bricks and tissue falls into place over framesworks to build the city",
     "tissue","The tissues are layered over the frameworks",
});
   dest_dir = ({
"/players/brittany/inferno/inf3.c","west",
});
}

init(){
::init();
if(random(3) == 0) {
this_player()->set_fight_area(); }
}
