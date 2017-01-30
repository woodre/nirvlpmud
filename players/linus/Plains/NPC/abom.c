#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/monster.c";
id(str) { return str=="abomination" || str=="undead";  }
int x;
object wep1, wep2, wep3, blood;
reset(arg) {
 ::reset(arg);
 if(arg) return;
 set_name("Abomination");
 set_short("An abomination");
 set_long(
 "  The abomination is a horrible looking creature.  It appears pieced\n"+
 "together many different corpses.  Crude stitches hold the various\n"+
 "body parts together.  This particular beast was made of human\n"+
 "parts, but has 3 arms.\n");
 wep1 = CO("/players/linus/Plains/obj/cleaver.c");
 MO(wep1,TO);
 init_command("wield axe");
 wep2 = CO("/players/linus/Plains/obj/sickle.c");
 MO(wep2,TO);
 wep3 = CO("/players/linus/Plains/obj/sickle.c");
 MO(wep3,TO);
 set_level(18);
 set_ac(14);
 set_al(random(-1000));
 set_aggressive(1);
 set_chat_chance(5);
 load_chat("The abomination swings his cleaver menacingly...\n");
 load_chat("The abomination waves his arms about...\n");
 load_chat("The abomination groans as if in pain.\n");
 set_a_chat_chance(5);
 load_a_chat("The abomination lashes out with a maggot infested hand.\n");
 set_chance(5);
 set_spell_dam(15+random(20));
 set_spell_mess1("The abomination strikes his attacker with a sickle");
 set_spell_mess2("The abomination strikes you with a sickle");
}
heart_beat() {
 ::heart_beat();
 x=random(30);
 blood = present("linus_blood",ENV(TO));
 if(( x > 25 ) && (!blood)) {
  tell_room(ENV(),"Blood pours from a gap in the abomination's stitches, forming a puddle on the ground.\n");
 MO(CO("/players/linus/Plains/obj/blood_pool.c"), ENV(TO));
  return 1;
}
  if(attacker_ob){
    switch(x){
    case 0..2: sickle_me(); break;
    case 3..5: sickle2_me(); break;
    case 6..30: return 0; break;
  }
 }
}
sickle_me() {
 if((attacker_ob) && (attacker_ob->query_ghost())) return;
   tell_room(ENV(TO), "The abomination strikes "+attacker_ob->query_name()+" with one of his sickles.\n"+
                      RED+"     Blood"+NORM+" splatters as the blade rips through "+attacker_ob->query_possessive()+" skin.\n", ({attacker_ob }));
   tell_object(attacker_ob, "The abomination strikes you with one of his sickles.\n"+
                      RED+"     Blood"+NORM+" splatters as the blade rips through your skin.\n");
   
   attacker_ob->hit_player(10+(x));
   return 1;
  }
sickle2_me() {
 if((attacker_ob) && (attacker_ob->query_ghost())) return;
   tell_room(ENV(TO),"The abomination swings it's chain, striking "+attacker_ob->query_name()+" hard!\n", ({ attacker_ob }));
   tell_object(attacker_ob,"The abomination swings it's chain, striking you hard!\n");
   
   attacker_ob->hit_player(x);
   return 1;
}
