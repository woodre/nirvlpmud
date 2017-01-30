#include "/players/pestilence/ansi.h"
inherit "/players/vertebraker/closed/std/monster";
#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
#define attacker attacker_ob
int i,z,y,ill;
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  ill = 0;

  set_name("Desire"); 
  set_alt_name("desire");
  set_alias("stripper");
  set_short("Desire the stripper");
  set_long("Desire is a gothic red head.  Her hair is a dark red.  Her skin\n"+
           "is very pale, with lots of black eye shadow.  Her lipstick and\n"+
           "fingernails are colored in black.  She has a very shapely body\n"+
           "with piercings in her eyebrow, tongue, nose, belly button and\n"+
           "labia.\n");
  set_race("human");
  set_gender("female");
  set_level(18);
  set_wc(30+random(6));
  set_ac(16+random(4));
  set_hp(530+random(200));
  set_wc_bonus(7);
  set_heal(15,5);
  add_money(0);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_al(0);
  load_chat("Desire says: Would you like to feel my tongue ring on your body?\n");
  load_chat("Desire winks at you suggestively.\n");
  set_chat_chance(10);
  load_a_chat("Desire screams in delight!\n");
  set_a_chat_chance(10);
  set_spell_mess2("Desire runs her tongue across your face, drawing blood.\n");
  set_spell_mess1("Desire attacks fiercly with her tongue piercing.\n");
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
   write("Desire licks your clitoris as she finger fucks you.\n");
   return 1;
   }
   else{
   write("Desire rips off your clothes, and jumps on top of your stiff dick.\n");
   return 1; }
   }

else {
   notify_fail("Desire says: i can only fuck you.\n");
   return 0;
   }
}

suck(arg) {

if (arg == "me"){
   if(TP->query_gender() == "female") {
   write("Desire sucks on your clitoris as she finger fucks you.\n");
   return 1;
   }
   else{
   write("Desire rips off your clothes, and shoves your stiff dick in her mouth.\n");
   return 1; }
   }

else {
   notify_fail("Desire says: i can only suck you.\n");
   return 0;
  }
}

durst_sing() {
y = 1;
if (y == 1) {
say("Desire sits you down in the couch.\n");
call_out("dance2", 1);
   }
      return 1;
}

dance2() {
y = 1;
if (y == 1) {
say("Desire straddles your legs and starts to rub her ass on you.\n");
call_out("dance3", 2);
  }  
    return 1;
}

dance3() {
y = 1;
if (y == 1) {
say("Desire works her body, moving it all over your body.\n"+
      "She rubs her ass all over your lap, and turns around\n"+
      "to face you and starts to mock grind to your face.  Her\n"+
      "with her vagina two inches from your mouth.\n"+
      "You start to drool.\n");
call_out("dance4", 3);
}
      return 1;
}

dance4() {
y = 1;
if (y == 1) {
say("Desire shakes her ass in front of your face.  She then\n"+
    "spins around to face you and starts to grind her groin\n"+
    "into your groin.\n \n \n"+
    "Desire says: I'm sorry but your time is up.\n"+
    "Desire kisses you gently on your cheek.\n");
  }
      return 1;
}
heart_beat(){
int z;
::heart_beat();

if(attacker_ob && present(attacker_ob,environment(this_object()))){
z = random(10);
if(z>8){
  if (query_attack()) {
    if(query_attack()->query_attrib("sta") < random(30)
    && ill == 0) {
     move_object(clone_object("players/pestilence/poison.c"),
        query_attack()); 
    ill = 1;
return 1;
}
}
   tell_room(environment(this_object()), 
  "Desire rakes her piercings across her opponent's body."+NORM+".\n");
  tell_object(attacker_ob,
  "Desire rakes you with her piercings, leaving you "+RED+"bleeding"+NORM+".\n");
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
  tell_room(environment(this_object()),
        "As Desire dies, her funny money falls from all of the hidden places.\n");
return 0; }
