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
    "     The cavern jaws draw purposefully together crushing buildings\n"+
    "and souls to sludge, much like being compelled to roll a stone\n"+
    "to the top of the cavern, for it to escape near the top and roll\n"+
    "back down.  The buildings forms anew with a fresh generation of\n"+
    "souls.\n";

   items = ({
     "jaws","The mouth of the caverns draws together crushing buildings and souls",
     "souls","The souls are crushed with buildings into sludge",
     "buildings","The buildings forms anew with a fresh generation of souls",
     "sludge","The mixture of the buildings and souls as they are crushed together",
     "buildings","The buildings are crushed with souls into sludge",
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
