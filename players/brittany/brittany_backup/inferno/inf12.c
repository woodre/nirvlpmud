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
    "     The abode of evil spirits and lost soul of souls.  Two stone leonine\n"+
    "creatures flank a harlot-demon, who was banished from being a goddess\n"+
    "symbol to a discredited demon.  For her faults, she was cast into\n"+
    "the pit to submit to the role of evil's consort.\n";

   items = ({
});
   dest_dir = ({
"/players/brittany/inferno/inf3.c","west",
});
}
