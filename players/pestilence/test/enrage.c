#define ETO environment(this_object())
#include "/players/pestilence/define.h"
inherit "/obj/treasure.c";
static status wielded;
static int no_go_time;
static int no_go_over;
static object wielded_by;
static int broke;
static int eff_wc;
static int misses,hits;
static int save_flag,class_of_weapon;
static object hit_func;
static string type;
static string *message_hit;

reset(arg) {
  if (arg) return 0;
call_out("enrage_return",15);
set_heart_beat(1);
}
id(str){ return str == "generic_wc_bonus"|| str == "enrage"  ||  str == "enrage_ob" || str == "notarmor"  || str == "pro_object"; }

long() {
write("Fury.\n");
  }
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
if(TP->query_ghost() == 1) { return 0; }
else{
write("You're too enraged to leave.\n");
return 1; }
}

cantdo() {
write("Your to enraged to concentrate on that spell at this time.\n");
return 1; }

gen_wc_bonus(){
        int total,str_bonus,dex_bonus;
        total = 0;
   if(no_go_time < time()) no_go_over = 0;
   if(no_go_over >= 2) return;
   no_go_time = time();
   no_go_over += 1;
        if(!USER) return 0; /* just a test!  added by verte 6.23.01 */

        str_bonus = USER->query_attrib("str");

        
        /********  This only happens if no Wep is wielded **********/
        if(USER->query_weapon() == this_object()){
                total += clawstwo();
                total += clawstwo();
        }
        /**********************************************************/
        


        total += ((15+random(str_bonus))); 

        
        if(!environment(this_object())->query_attack()) return 0;  /* added by verte 6.23.01 */ 

if(USER->query_real_name() == "pestilence") tell_object(USER, "TOTAL IS: "+total+".\n");
        return total;
}
