#include "/players/pestilence/ansi.h"
inherit "/players/vertebraker/closed/std/monster";
#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
#define attacker attacker_ob
int i,y;
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Jessica"); 
  set_alt_name("jessica");
  set_alias("stripper");
  set_short("Jessica the stripper");
  set_long("Jessica stand five foot ten inches tall.  She is a very large and\n"+
           "beautiful woman.  Her red hair is short, exposing her beautiful\n"+
           "facial features, and her very sexy nape of her neck.  Jessica\n"+
           "weighs 120 pounds with measurements of 38-26-34.\n"+
           "labia.\n");
  set_race("human");
  set_gender("female");
  set_level(20);
  set_wc(30+random(6));
  set_ac(16+random(4));
  set_hp(530+random(200));
  set_wc_bonus(20);
  set_heal(15,5);
  add_money(0);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_al(0);
  load_chat("Jessica says: Would you like to be with a real woman?\n");
  load_chat("Jessica tells you: the rest of the girls are skanks compared to me.\n");
  set_chat_chance(10);
  load_a_chat("Jessica yells for Joe!\n");
  set_a_chat_chance(10);
  set_spell_mess2("Jessica hits you with a hard roundhouse right.\n");
  set_spell_mess1("Jessica hits her attacker with a hard roundhouse right.\n");
  set_chance(20);
  set_spell_dam(40);
  call_out("durst_sing", 2);
}

init() {
  ::init();
add_action("stop","fuck");
add_action("suck","suck");

}
stop(arg) {

if (arg == "me"){
   if(TP->query_gender() == "female") {
   write("Jessica licks your clitoris as she finger fucks you.\n");
   return 1;
   }
   else{
   write("Jessica rips off your clothes, and jumps on top of your stiff dick.\n");
   return 1; }
   }

else {
   notify_fail("Jessica says: i can only fuck you.\n");
   return 0;
   }
}

suck(arg) {

if (arg == "me"){
   if(TP->query_gender() == "female") {
   write("Jessica sucks on your clitoris as she finger fucks you.\n");
   return 1;
   }
   else{
   write("Jessica rips off your clothes, and shoves your stiff dick in her mouth.\n");
   return 1; }
   }

else {
   notify_fail("Jessica says: i can only suck you.\n");
   return 0;
   }
}

durst_sing() {
  y = random(30);
  if (y>0){
say("Jessica sits you down in the couch.\n");
call_out("dance2", 5);
   }
      return 1;
}

dance2() {
int z;
  y = random(30);
  if (y>0){
say("Jessica straddles your legs to run her hands up and down your body.\n"+
    "while slowing grinding her ass on your lap.\n");
call_out("dance3", 5);
  }  
    return 1;
}

dance3() {
int z;
  y = random(30);
  if (y>0){
say("Jessica works her body, wiggling it all over your body.\n"+
    "She takes one of your fingers and sticks it into her mouth.\n"+
    "While the other one slowly slides into her wet vagina.\n \n"+
    "She takes your finger out of her mouth and replaces it with the other one.\n");
call_out("dance4", 5);
}
      return 1;
}

dance4() {
int z;
  y = random(30);
  if (y>0){
say("Jessica takes her breasts and pushes them into your face.\n"+
    "Her nipples are just inches away from your tongue.\n"+
    "With a quick move she throws her legs over your head and grinds on your face.\n \n \n");
call_out("dance5", 2);
  }
      return 1;
}

dance5() {
  y = 1;
  if (y == 1){
say("Jessica says: I'm sorry but your time is up.\n"+
    "Jessica kisses you gently on your cheek.\n");
}
          return 1;
}

heart_beat(){
int z;
::heart_beat();
if(!environment()) return;

if(attacker_ob && present(attacker_ob,environment(this_object()))){
z = random(10);
if(z>8){
   tell_room(environment(this_object()), 
  "Jessica spits in her attacker's eye."+NORM+".\n");
  tell_object(attacker_ob,
  "Jessica spits in your eye, leaving it quite irritated.\n");
    attacker->hit_player(20+random(30));
     }
}
}

monster_died() {
  move_object(clone_object("/players/pestilence/club/obj/money.c"),
      environment(this_object()));
  move_object(clone_object("/players/pestilence/club/obj/money.c"),
      environment(this_object()));
  move_object(clone_object("/players/pestilence/club/obj/money.c"),
      environment(this_object()));
  move_object(clone_object("/players/pestilence/club/obj/money.c"),
      environment(this_object()));
  move_object(clone_object("/players/pestilence/club/obj/money.c"),
      environment(this_object()));
  move_object(clone_object("/players/pestilence/club/obj/money.c"),
      environment(this_object()));
return 0; }
