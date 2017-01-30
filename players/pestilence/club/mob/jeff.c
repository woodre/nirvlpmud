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

  move_object(clone_object("/players/pestilence/club/obj/key.c"),
        this_object());

  set_name("Jeff"); 
  set_alt_name("jeff");
  set_alias("bodyguard");
  set_short("Jeff the bodyguard");
  set_long("Jeff is a large man, both in height and weight.  He looks after\n"+
           "the strippers in the backstage area.  Jeff isn't a person who\n"+
           "likes people fooling around with the strippers.\n");
  set_race("human");
  set_gender("male");
  set_level(18);
  set_wc(33+random(6));
  set_ac(13+random(4));
  set_hp(400+random(200));
  set_wc_bonus(7);
  set_heal(15,5);
  add_money(2000);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_al(0);
  load_chat("Jeff says: You better not touch any of my girls.\n");
  load_chat("Jeff bumps into you, and gives you a stare.\n");
  set_chat_chance(10);
  load_a_chat("Jeff says: Why you little punks!\n");
  set_a_chat_chance(10);
  set_spell_mess2("Jeff hits you with a flurry of punches.\n");
  set_spell_mess1("Jeff releases a flurry of punches.\n");
  set_chance(20);
  set_spell_dam(40);
}
init() {
  ::init();


}

heart_beat(){
int z;
::heart_beat();
if(!environment()) return;

if(attacker_ob && present(attacker_ob,environment(this_object()))){
z = random(10);
if(z>8){
   tell_room(environment(this_object()), 
  "Jeff pulls his knife out and stabs his attacker.\n");
  tell_object(attacker_ob,
  "Jeff plunges his knife into your flesh, causing "+HIR+"blood"+NORM+" to flow.\n");
    attacker->hit_player(20+random(30));
     }
}
}
