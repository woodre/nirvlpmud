/****************************************
*     The random attack was taken almost
*     verbatim from Mythos' shurato
*******************************************/

#include "/players/anshar/closed/ansi.h"
#define tp this_player()->query_name()
int Y;
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("deathmaster");
    set_alt_name("sword");
    set_alias("demon");
    set_short(BLU+"Deathmaster"+NORM);
    set_long("     An ebon blade sparkles from a pitch black hilt formed\n"+
             "of some dark leather. The guards is a straight piece of\n"+
             "equally dark metal capped by a large polished piece of black\n"+
             "obsidian on either end. There are some runes on the blade\n"+
             "that are barely discernable.\n");
    set_class(18);
    set_weight(4);
    set_value(10000);
    set_hit_func(this_object());
    call_out("check",100);
    Y = 1;
}
weapon_hit(attacker){
   int X;
   if(11 < random(15)) {
     if(this_player()->query_alignment()<1) {
       X = random(50);
       if(X<10) {
       say(
       BLU+"Deathmaster"+NORM+" sucks the life from its opponent for strength!\n");
       write(
       BLU+"Deathmaster"+NORM+" sucks the life from your opponent for strength!\n");
       attacker->heal_self(random(6));
       return random(6); }
       if(10<=X && X<=20) {
       say(
       BLU+"Deathmaster"+NORM+" drains the enemy!\n");
       write(
       BLU+"Deathmaster"+NORM+" pulls life from the enemy's body into yours!\n");
       attacker->heal_self(-random(6));
       this_player()->add_hit_point(random(6));
       call_other(this_player(),"add_spell_point",random(6));
       return 2; }
       if(20<X && X<30) {
       say(
       BLU+"Deathmaster"+NORM+" cleaves into its foe!\n");
       write(
       BLU+"Deathmaster"+NORM+" rips your foe's flesh!\n");
       return 6; }
       if(30<=X && X<=45) {
       say(
       BLU+"Deathmaster"+NORM+" drains energy from the foe!\n");
       write(
       BLU+"Deathmaster"+NORM+" hums as it stores its enemy's lifeforce!\n");
       Y++;
       return 3; }
       if(X>45) {
       say(
       BLU+"Deathmaster"+NORM+" releases its stored energy!\n");
       write(
       BLU+"Deathmaster"+NORM+" blasts into your enemy with its stored power!\n");
       attacker->heal_self(-Y);
       Y=1;
       return 4; }
}
}
}
init() {
  ::init();
}

query_save_flag()  { return 1; }

check() {
object target;
if(environment(this_object())) {
if(environment(environment(this_object()))) {
target=first_inventory(environment(environment(this_object())));
	if(living(environment(this_object()))) { 
	   if(environment(this_object())->query_npc() !=1) {
if(call_other(environment(this_object()),"query_attrib","pie") < random(40)) {
	         tell_object(environment(this_object()),"Deathmaster whispers"+
	            " to you of death, and you feel compelled!\n");
	         while(target) {
	           if(target->query_npc() && !call_other(target,"id","messenger")) {
	           environment(this_object())->attack_object(target);
	           return 1;}
	           target=next_inventory(target);
	           }
	           call_out("check",300+random(300));
	           return 1;}
	   tell_object(environment(this_object()),"A desire to take a life "+
	        "fills you.\n");
	        call_out("check",100 +random(300));
	        return 1;} } } }
	        call_out("check",100 +random(300));
	        return 1;}
