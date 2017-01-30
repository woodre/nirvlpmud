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
"     Wandering deeper into the plains of hell, the land seems very\n"+
"much much alive.  The ground slices itself into slivers that spins\n"+
"up in the air and disappears into the darkness.  In the distance,\n"+
"an entire hill lifts, trumpets and settles back onto the ground.  A\n"+
"river of liquid corkscrews into the air like a reverse tornado,\n"+
"churning into the ragged clouds above.  The plain leads into\n"+
"several directions.\n",
   items = ({
"river","A river of lava, fluid rock that issues from a volcano.",
"tornado", "A localized windstorm, characterized by a long, funnel-shaped cloud",
"plains","The plains have minor differences in elevation",
"ground","The ground slices into slivers and spins up into the air",
"hill","The hill lifts, trumpets and then settles on the ground",
"plain","The plain leads into different directions",
"slivers","A small, slender part of the ground, slice into a half dozen pieces",
"clouds","Black ragged globes, lined in red fire, floating overhead",
"land","The land seems alive and governed by it's own laws",
});
   dest_dir = ({
"/players/brittany/inferno/inf1a.c","west",
"/players/brittany/inferno/inf2a.c","east",
"/players/brittany/inferno/inf3.c","south",
});
}

init(){
::init();
if(random(3) == 0) {
this_player()->set_fight_area(); }
}

