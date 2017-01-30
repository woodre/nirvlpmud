#include "/players/wocket/closed/ansi.h"
inherit "/obj/weapon";

reset(arg){
set_name("femur");
set_short("The femur of a nonge");
set_long("This large femur make a perfect club.  Blood stains it's\n"+
         "head from both its first owner and it's victims. \n");
set_class(17);
set_type("blunt");
set_weight(2);
set_value(random(500));
set_hit_func(this_object());
}

weapon_hit(){
int W;
W = random(5);
if(W == 1){
    write("The femur draws blood from it's adversaries\n"+ 
          RED+"     S K U L L ... . . .  .  .  .  . \n"+OFF);
    return 2;
}
if(W == 3){
    write("You twirl your femur with deadly grace before\n"+
          RED+"    < < < CRUNCH > > >n"+OFF);
    return 2;
}
}