#include "/players/pestilence/ansi.h"
inherit "/players/vertebraker/closed/std/monster";
#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
#define attacker attacker_ob
int i,y,z;
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Kitty"); 
  set_alt_name("kitty");
  set_alias("stripper");
  set_short("Kitty the stripper");
  set_long("Kitty is a short, blonde stripper.  She has the curves that make men\n"+
           "and women juice in their pants. She has blue eyes and her flows down\n"+
           "past her shoulders.  Her breasts are very round and volumptious.\n");
  set_race("human");
  set_gender("female");
  set_level(20);
  set_wc(32+random(4));
  set_ac(18+random(4));
  set_hp(550+random(200));
  set_wc_bonus(20);
  set_heal(15,5);
  add_money(0);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_al(0);
  load_chat("Kitty says: I do more things than just strip.\n");
  load_chat("Kitty licks her lips excitedly.\n");
  set_chat_chance(10);
  load_a_chat("Kitty rubs her tits in your face, temporarily blinding you.\n");
  load_a_chat("Kitty says: This isn't the way to treat a woman.\n");
  set_a_chat_chance(10);
  set_spell_mess2("Kitty hits you hard with her nicely rounded breasts.\n");
  set_spell_mess1("Kitty hits her attacker with her nicely rounded breasts.\n");
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
   write("Kitty licks your clitoris as she finger fucks you.\n");
   return 1;
   }
   else{
   write("Kitty rips off your clothes, and jumps on top of your stiff dick.\n");
   return 1; }
   }

else {
   notify_fail("Kitty says: i can only fuck you.\n");
   return 0;
   }
}

suck(arg) {

if (arg == "me"){
   if(TP->query_gender() == "female") {
   write("Kitty sucks on your clitoris as she finger fucks you.\n");
   return 1;
   }
   else{
   write("Kitty rips off your clothes, and shoves your stiff dick in her mouth.\n");
   return 1; }
   }

else {
   notify_fail("Kitty says: i can only suck you.\n");
   return 0;
   }
}

durst_sing() {
  y = 1;
  if (y == 1){
say("Kitty sits you down in the couch.\n");
call_out("dance2", 5);
   }
      return 1;
}

dance2() {
  y = 1;
  if (y == 1){
say("Kitty straddles your legs to run her hands up and down your body.\n"+
    "while slowing grinding her ass on your lap.\n");
call_out("dance3", 5);
  }  
    return 1;
}

dance3() {
  y = 1;
  if (y == 1){
say("Kitty slowly lifts one leg up and sets it on your shoulder, giving\n"+
    "you a nice shot of her vagina.  With the leg still in that position\n"+
    "she plunges one of her fingers deep inside herself.\n");
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
  y = 1;
  if (y == 1){
say("Kitty takes your finger and rubs it on her clitoris.\n"+
    "Kitty moans in delight\n"+
    "Your finger is starting to tingle from the wetness.\n \n \n");
call_out("dance6", 2);
  }
      return 1;
}

dance6() {
  y = 1;
  if (y == 1){
say("Kitty says: I'm sorry but your time is up.\n"+
    "Kitty kisses you gently on your cheek.\n");

}
      return 1;
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
