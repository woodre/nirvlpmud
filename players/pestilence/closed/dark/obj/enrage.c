inherit "/obj/treasure.c";

#include "/players/pestilence/define.h"

#if 0
#include "/players/pestilence/closed/dark/obj/weapon2.h"
#include "/players/pestilence/closed/dark/obj/weapon3.h"
#endif


#define ETO environment(this_object())

reset(arg) {
  if (arg) return 0;
call_out("enrage_return",36);
}
id(str){ return str == "generic_wc_bonus"|| str == "enrage"  ||  str == "enrage_ob" || str == "notarmor"  || str == "pro_object"; }

long() {
write("Fury.\n");
  }


int gen_wc_bonus() { return 13; }

get() { return 0;}
drop() {return 1;}
extra_look() {
write(environment()->query_name()+" is "+HIR+"ENRAGED"+NORM+".\n");
}
enrage_return() {
if(ETO) {  /*  needed for startup  */
  if(living(ETO)) {
    tell_object(environment(this_object()),
      "You are no longer enraged.\n");
    destruct(this_object());
    return 1; }
  }
}

init() {
  ::init();
add_action("stop","west");
add_action("stop","back");
add_action("stop","north");
add_action("stop","south");
add_action("stop","east");
add_action("stop","northeast");
add_action("stop","northwest");
add_action("stop","southeast");
add_action("stop","southwest");
add_action("stop","se");
add_action("stop","sw");
add_action("stop","n");
add_action("stop","s");
add_action("stop","portal");
add_action("stop","leave");
add_action("stop","back");
add_action("stop","exit");
add_action("stop","darkness");
add_action("stop","enter");
add_action("stop","out");

/*
add_action("cantdo","demon");
add_action("cantdo","torment");
add_action("cantdo","slash");
add_action("cantdo","punch");
add_action("cantdo","distraught");
add_action("cantdo","dist");
add_action("cantdo","stun");
*/
}
stop() {
if(!environment()->query_attack()) { return 0; }
if(TP->query_ghost()) { return 0; }
else{
write("You're too enraged to leave.\n");
return 1; }
}

cantdo() {
write("Your to enraged to concentrate on that spell at this time.\n");
return 1; }
