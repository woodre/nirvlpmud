#include "/players/pestilence/ansi.h"
inherit "/players/vertebraker/closed/std/monster";
#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
#define attacker attacker_ob
int i,z,y;
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Fire"); 
  set_alt_name("fire");
  set_alias("stripper");
  set_short("Fire the stripper");
  set_long("Fire has bright red hair.  She has bright blue eyes, with flawless\n"+
           "skin.  Her body is well shaped with curves in all the right spots\n"+
           "that make men and woman go wild\n");
  set_race("human");
  set_gender("female");
  set_level(20);
  set_wc(32+random(6));
  set_ac(18+random(4));
  set_hp(550+random(200));
  set_wc_bonus(20);
  set_heal(15,5);
  add_money(0);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_al(0);
  load_chat("Fire says: How would you like to feel my curves?\n");
  load_chat("Fire runs her fingers through your hair.\n");
  set_chat_chance(10);
  load_a_chat("Fire claws at you with her finger nails.\n");
  set_a_chat_chance(10);
  set_spell_mess2("Fire swings around, hitting you with her hair.\n");
  set_spell_mess1("Fire swings around, hitting her attacker with her hair.\n");
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
   write("Fire licks your clitoris as she finger fucks you.\n");
   return 1;
   }
   else{
   write("Fire rips off your clothes, and jumps on top of your stiff dick.\n");
   return 1; }
   }

else {
   notify_fail("Fire says: i can only fuck you.\n");
   return 0;
   }
}

suck(arg) {

if (arg == "me"){
   if(TP->query_gender() == "female") {
   write("Fire sucks on your clitoris as she finger fucks you.\n");
   return 1;
   }
   else{
   write("Fire rips off your clothes, and shoves your stiff dick in her mouth.\n");
   return 1; }
   }

else {
   notify_fail("Fire says: i can only suck you.\n");
   return 0;
   }
}

durst_sing() {
/* env check added by illarion 5 dec 2004 */
  if(!environment()) return;
  y = random(30);
  if (y>0){
say("Fire sits you down in the couch.\n");
call_out("dance2", 5);
   }
      return 1;
}

dance2() {
int z;
  y = random(30);
  if (y>0){
say("Fire straddles your legs to run her hands up and down your body.\n"+
    "while slowing grinding her ass on your lap.\n");
call_out("dance3", 5);
  }  
    return 1;
}

dance3() {
int z;
  y = random(30);
  if (y>0){
say("Fire works her body, wiggling it all over your body.\n"+
    "She takes one of your fingers and sticks it into her mouth.\n"+
    "While the other one slowly slides into her wet vagina.\n \n");
call_out("dance4", 5);
}
      return 1;
}

dance4() {
  y = 1;
  if (y == 1){
say("She takes your finger out of her mouth and replaces it with the other one.\n"+
    "You start to drool.\n");

call_out("dance5", 2);
}
      return 1;
}

dance5() {
int z;
  y = random(30);
  if (y>0){
say("Fire takes her breasts and pushes them into your face.\n"+
    "Her nipples are just inches away from your tongue.\n"+
    "With a quick move she throws her legs over your head and grinds on your face.\n \n \n");
call_out("dance6", 2);
}
           return 1;
}
dance6() {
  y = 1;
  if (y == 1) {
say("Fire says: I'm sorry your time is up.\n"+
    "Fire kisses you gently on your cheek\n");
  }
      return 1;
}

heart_beat(){
int z;
::heart_beat();
if(!environment()) return;

/* this_object() check added by illarion 5 dec 2004 */
if(this_object())
if(attacker_ob && present(attacker_ob,environment(this_object()))){
z = random(10);
if(z>8){
   tell_room(environment(this_object()), 
  "Fire slaps her attacker hard in the face."+NORM+".\n");
  tell_object(attacker_ob,
  "Fire slaps you hard in your face.\n");
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
