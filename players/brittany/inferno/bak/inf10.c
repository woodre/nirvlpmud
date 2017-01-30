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
    "     Hell's capital city, is the largest huminity has ever known,\n"+
    "its boundaries are neither spatial nor temporal.  Its sprawl is vast,\n"+
    "unplanned and chaotic with millions of streets, avenues and alleys\n"+
    "close together and intersecting.  Areas reflecting our most distant\n"+
    "past about neighborhoods from the distant future.\n";

   items = ({
});
   dest_dir = ({
"/players/brittany/inferno/inf3.c.c","west",
});
}

init(){
::init();
if(random(3) == 0) {
this_player()->set_fight_area(); }
}
