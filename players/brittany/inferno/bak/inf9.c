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
    "     The watchtowers with giant, bone-lidden orbs seem perfect for the\n"+
    "job.  Encrusted with barracks and other military buildings appropriate\n"+
    "for a hostile frontier.  The towers are the demon's first line of defense.\n"+
    "Surmounting them are gaping jaws attached to long tubular necks that can\n"+
    "swiftly extend to scoop up flying prey.\n";

   items = ({
     "watchtowers","The towers are gigantic and bond together with bones",
     "barracks"," range of buildings inside of the watchtowers",
     "building","The military buildings inside of the watchtowers",
     "jaws","The jaws are attached to long tubular necks surmounting the towers",
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
