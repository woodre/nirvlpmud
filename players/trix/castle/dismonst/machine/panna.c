inherit "obj/food.c";
#include "/players/boltar/things/esc.h"

reset(arg){
set_name("panna");
set_alias("elena");
set_long("A portion of Panna Elena, a yummie cooked cream ready to be gobbled down.\n"+
"Wanna know about the RL version? Just netsurf to '"+
esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m"+ 
"http://www.b612.it/panna"+esc+"[0m"+"'.\n");
set_short("A portion of Panna Elena");
set_value(50);
set_strength(15);
set_weight(1);
set_eater_mess("You finish the cream hungrily... Mmmmmm,that was goooooooood...\n"+
esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m"+ 
"Remember http://www.b612.it/panna"+esc+"[0m"+" !!!!\n");
set_eating_mess(" eats the cream and licks his lips hungrily, wanting more!\n");
}
