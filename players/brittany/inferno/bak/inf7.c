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
    "     A hoarse bellowing cuts the thick air as one approaches the\n"+
   "colossal residence of the horseman.  The dome of the residence is\n"+
   "shrouded in clouds and lightning.  Along with its adjacent stable,\n"+
   "both places seems to be a fearful place.\n";

   items = ({
     "residence","The gigantic residence of the horseman, go 'in' at your own risk",
     "dome","The roof of the residence is shrouded in clouds and lightning",
     "stable","The stable is dark, maybe you could open the gate",
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
