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
    "     The perimeters of hell are salients to be watched over, with\n"+
    "borders of constant dispute with the enemy from above.  They are a\n"+
    "region of endless ebb and flow as characterized by the cities large\n"+
    "block of buildings that float without direction over the smoldering\n"+
    "landscape.  Early warning systems alert the armies of darkness from\n"+
    "enemies.\n";

   items = ({
     "ebb","The block of buildings floating without direction over the smoldering landscape",
    "systems","The early warning systems alert the armies of darkness from enemies",
     "borders","The borders are areas of constant dispute with the enemy from above",
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
