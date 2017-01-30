/* Sunflower
 * Potentially extremely high damage monster with seed blast
 */
 
inherit "/obj/monster.c";
#include "/players/snow/chaos/defs.h"
 
int seeds;
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
    set_name("sunflower");
    set_race("chaoscreature");
    set_alias("flower");
    set_short("A large sunflower");
    set_long(
"A large sunflower. It looks surprisingly sentient and deadly.\n"+
"You notice its seeds are as sharp as needles..\n");
    set_level(15);
    set_hp(random(150)+200);
    set_ac(random(8)+5);
    set_wc(random(10)+10);
    set_dead_ob(this_object());
    set_aggressive(1);
    set_chat_chance(10);
    load_chat(
"The sunflower seems to look at you...\n");
    load_chat(
"The sunflower sways back and forth...\n");
    seeds = random(500)+300;
  }
}
 
monster_died() {
  object ob;
  ob = clone_object("obj/money");
  TR(ENV(TO),
    "The Sunflower falls to a withered heap on the floor.\n");
  ob->set_money(seeds * 10);
  if(present("corpse")) move_object(ob, present("corpse"));
  return 0;
}
 
heart_beat() {
  object meat;
    ::heart_beat();
  if(!environment()) return 1;
  if(attacker_ob) {
    if(seeds > 0) seed_blast();
    RE;
  }
  findmeat();
  RE;
}
 
findmeat() {
  object ob;
  ob = first_inventory(environment(this_object()));
  while(ob) {
    if(ob->is_player()) {
      if(random(10) < 4) {
        TO->attack_object(ob);
        seed_blast();
        RE;
      }
    }
    ob = next_inventory(ob);
  }
  RE;
}
 
 
seed_blast() {
   if(attacker_ob->query_ghost()) return 1;
  if(random(10) < 4) RE;
  if(seeds < 1) RE;
  TE(attacker_ob,"  You are struck by a flying sunflower seed!\n");
  attacker_ob->hit_player(random(10)+2);
  seeds --;
  seed_blast();
  RE;
}
