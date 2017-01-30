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
  set_name("Magic"); 
  set_alt_name("magic");
  set_alias("stripper");
  set_short("Magic the stripper");
  set_long("Magic seems to have a power that controls men.  With her shoulder\n"+
           "length brown hair, and gorgeous brown eyes, she seems to cast a\n"+
           "spell on men.  Her facial features seem almost too perfect, with\n"+
           "skin so smooth and soft, a person feels like they are in heaven with\n"+
           "one touch.\n");
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
  load_chat("Magic says: Can i cast a spell on you?\n");
  load_chat("Magic runs her hand down her curves.\n");
  set_chat_chance(10);
  load_a_chat("Magic says: You can't hurt me silly.\n");
  set_a_chat_chance(10);
  set_spell_mess2("Magic runs her hands over your body, sucking your life away in the process.\n");
  set_spell_mess1("Magic runs her hands over her attacker's body.\n");
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
   write("Magic licks your clitoris as she finger fucks you.\n");
   return 1;
   }
   else{
   write("Magic rips off your clothes, and jumps on top of your stiff dick.\n");
   return 1; }
   }

else {
   notify_fail("Magic says: i can only fuck you.\n");
   return 0;
   }
}

suck(arg) {

if (arg == "me"){
   if(TP->query_gender() == "female") {
   write("Magic sucks on your clitoris as she finger fucks you.\n");
   return 1;
   }
   else{
   write("Magic rips off your clothes, and shoves your stiff dick in her mouth.\n");
   return 1; }
   }

else {
   notify_fail("Magic says: i can only suck you.\n");
   return 0;
   }
}

durst_sing() {
  y = random(30);
  if (y>0){
say("Magic sits you down in the couch.\n");
call_out("dance2", 5);
   }
      return 1;
}

dance2() {
int z;
  y = random(30);
  if (y>0){
say("Magic straddles your legs to run her hands up and down your body.\n"+
    "while slowing grinding her ass on your lap.\n");
call_out("dance3", 5);
  }  
    return 1;
}

dance3() {
int z;
  y = random(30);
  if (y>0){
say("Magic works her body, wiggling it all over your body.\n"+
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
say("Magic shakes her ass in front of your face.  She then\n"+
    "spins around to face you and starts to grind her groin\n"+
    "into your groin leaving your lap slightly moist.\n \n \n"+
    "Magic says: I'm sorry but your time is up.\n"+
    "Magic kisses you gently on your cheek\n");
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
  "Magic waves her hand in a motion that seems to hurt her attacker."+NORM+".\n");
  tell_object(attacker_ob,
  "Magic hits you with a wave of spells.\n");
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
