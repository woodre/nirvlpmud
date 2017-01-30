/****************************************
*     wc 19 player gets random(8) sp back
*     in return..curse is interesting....
*     players crime is set and once in a while
*     is forced to attack random npc in room
*     taken from the ashura.c  (avatar of
*     destruction)  weapon is saveable
*
*     approved by saber
*******************************************/

#include "/players/mythos/closed/ansi.h"
#define tp this_player()->query_name()
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("shurato");
    set_alt_name("sword");
    set_alias("katana");
    set_short(YEL+"Shurato"+NORM);
    set_long("A sword of purest crystal.  It seems to radiate\n"+
             "a malicious aura of might.  Once wielded only by\n"+
             "the avatar Ashura, it now rests in your hands....\n"+
             "Be wary.....\n");
    set_class(19);
    set_type("sword");
    set_weight(7);
    set_value(8000);
  /* make the sheet of fire be actual fire - ill
    set_hit_func(this_object());
  */
    set_params("other|fire",0,"fire_hit");
    call_out("check",100);
}
fire_hit(attacker){
  if(this_player()) if(this_player()->is_player()) this_player()->set_crime();
  if(attacker)
if(1 == random(4))
  {
    write("You call down a great sheet of flame upon your enemy!\n\n"+
           HIY+"\n\tI  N  F  E  R  N  O  !\n\n"+NORM);
   say("You see "+capitalize(environment(this_object())->query_name())+" call down a "+
         "great sheet of flame upon the enemy!\n\n"+
           HIY+"\n\tI  N  F  E  R  N  O  !\n\n"+NORM);
    tell_object(attacker,RED+"\nFire and AGONY is all you know!\n\n"+NORM);
     if(this_player())
    call_other(this_player(),"add_spell_point",random(8));
    return 5;
}}

query_save_flag()  { return 0; }



check() {
object target;
if(environment(this_object())) {
if( environment(environment(this_object()))) {
target=first_inventory(environment(environment(this_object())));
	if(living(environment(this_object()))) { 
	   if(environment(this_object())->query_npc() !=1) {
if(call_other(environment(this_object()),"query_attrib","pie") < random(40)) {
	         tell_object(environment(this_object()),"You feel a need to shed"+
	            " blood and let CHAOS reign!\n");
	         while(target) {
	           if(target->query_npc() && !call_other(target,"id","messenger")) {
	           environment(this_object())->attack_object(target);
	           return 1;}
	           target=next_inventory(target);
	           }
	           call_out("check",700+random(500));
	           return 1;}
	   tell_object(environment(this_object()),"Something whispers to you of "+
	        "dark dreams and destruction.\n");
	        call_out("check",200 +random(500));
	        return 1;} } } }
	        call_out("check",200 +random(500));
	        return 1;}
