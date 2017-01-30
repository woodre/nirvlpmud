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
"     The electric crackling of the air grows in intensity as a pair of\n"+
"black ragged globes, lined in red fire, floats overhead.  It turns and\n"+
"dashes off, vanishing behind a ridge.  The crackling resumes its previous\n"+
"level with their departure.\n";
   items = ({
     "air","The air crackles with intensity",
     "globes","Black ragged globes lined in red fire",
     "ridge","A long, narrow elevation of land through the hills",
     "cavern","The hollow underground of two cities",
         "cities","Two cities that are mirror-images of each other",
     "plain","The plain continues to the northeast",
});
   dest_dir = ({
"/players/brittany/inferno/inf2.c","north",
"/players/brittany/inferno/inf4.c","northeast",
});
}

init(){
::init();
if(random(3) == 0) {
this_player()->set_fight_area(); }
}
