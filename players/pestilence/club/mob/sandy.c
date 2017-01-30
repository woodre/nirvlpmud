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
  set_name("Sandy"); 
  set_alt_name("sandy");
  set_alias("stripper");
  set_short("Sandy the stripper");
  set_long("Sandy is a beautiful brunette.  Her hair flows down over her soft\n"+
           "and smooth skin.  She has deep brown eyes that seem to penetrate\n"+
           "your soul.\n");
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
  load_chat("Sandy says: Do you want me to make you feel good?\n");
  load_chat("Sandy licks her lips seductively.\n");
  set_chat_chance(10);
  load_a_chat("Sandy kicks you in the groin.\n");
  set_a_chat_chance(10);
  set_spell_mess2("Sandy stings you very hard with her g-string.\n");
  set_spell_mess1("Sandy stings her attacker with a g-string.\n");
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
   write("Sandy licks your clitoris as she finger fucks you.\n");
   return 1;
   }
   else{
   write("Sandy rips off your clothes, and jumps on top of your stiff dick.\n");
   return 1; }
   }

else {
   notify_fail("Sandy says: i can only fuck you.\n");
   return 0;
   }
}

suck(arg) {

if (arg == "me"){
   if(TP->query_gender() == "female") {
   write("Sandy sucks on your clitoris as she finger fucks you.\n");
   return 1;
   }
   else{
   write("Sandy rips off your clothes, and shoves your stiff dick in her mouth.\n");
   return 1; }
   }

else {
   notify_fail("Sandy says: i can only suck you.\n");
   return 0;
   }
}

durst_sing() {
  y = 1;
  if (y == 1){
say("Sandy sits you down in the couch.\n");
call_out("dance2", 5);
   }
      return 1;
}

dance2() {
  y = 1;
  if (y == 1){
say("Sandy straddles your legs to run her hands up and down your body.\n"+
    "while slowing grinding her ass on your lap.\n");
call_out("dance3", 5);
  }  
    return 1;
}

dance3() {
  y = 1;
  if (y == 1){
say("Sandy works her body, wiggling it all over your body.\n"+
    "She takes one of your fingers and sticks it into her mouth.\n"+
    "While the other one slowly slides into her wet vagina.\n \n"+
    "She takes your finger out of her mouth and replaces it with the other one.\n");
call_out("dance4", 5);
}
      return 1;
}

dance4() {
  y = 1;
  if (y == 1){
say("You start to drool!\n");
call_out("dance5", 2);
}
      return 1;
}

dance5() {
  y = 1;
  if (y == 1){
say("Sandy takes her breasts and pushes them into your face.\n"+
    "Her nipples are just inches away from your tongue.\n"+
    "With a quick move she throws her legs over your head and grinds on your face.\n \n \n");
call_out("dance6", 2);
  }
      return 1;
}

dance6() {
  y = 1;
  if (y == 1){
say("Sandy says: I'm sorry but your time is up.\n"+
    "Sandy kisses you gently on your cheek.\n");

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
  "Sandy hits her attacker with a barrage of kicks."+NORM+".\n");
  tell_object(attacker_ob,
  "Sandy hits you with a barrage of kicks.\n");
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
