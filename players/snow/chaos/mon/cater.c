/* Giant Caterpillar
 * Kicks the shit out of just about anyone very quickly (literally!)
 */
 
inherit "/obj/monster.c";

#define TO this_object()
#define ENV environment
 
string victim;
int tramps;
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
    set_name("giant caterpillar");
    set_race("chaoscreature");
    set_alias("caterpillar");
    set_short("A giant caterpillar");
    set_long(
"This is a fuzzy caterpillar. Unfortunately for you, it is\n"+
"ten meters long and aggressive. It may be soft and fuzzy but\n"+
"its chomping mouth and trampling method of attack could rip\n"+
"through an elephant with ease. It appears to desire you as its\n"+
"next prey...\n");
    set_level(22);
    set_hp(random(500)+500);
    set_ac(random(10)+12);
    set_wc(random(15)+30);
/* NEW CODE */
set_wc_bonus(46);
    set_dead_ob(this_object());
    set_aggressive(1);
    set_chat_chance(10);
    set_a_chat_chance(10);
    load_chat(
"The giant caterpillar gazes hungrily in your direction...\n");
    load_chat(
"You feel the rumble of the caterpillar's movements shaking the ground.\n");
    load_a_chat(
"The giant caterpillar looks happy.\n");
    load_a_chat(
"You try to dodge the caterpillar's wild attacks!\n");
  }
}
 
monster_died() {
  object tres, party;
  int i;
/* NO LONGER NEEDED
  party = present("party object", attacker_ob);
  if(party) party->share_exp(8000);
  if(!party) attacker_ob->add_exp(8000);
*/
  tell_room(environment(), "The giant caterpillar collapses and dies.\n");
  for(i=0; i<random(3)+1; i++) {
  tres = clone_object("/obj/heal");
  move_object(tres, this_object());
  }
  return 0;
}
 
heart_beat() {
  object meat;
  ::heart_beat();
  if(!environment()) return 1;
  if(attacker_ob) {
    if(victim != attacker_ob->query_real_name()) {
      victim = attacker_ob->query_real_name(); }
      if(!present(attacker_ob,environment(this_object()))) {
        if(environment(attacker_ob)->query_chaos() == "devour")
          move_object(this_object(),environment(attacker_ob));
      }
    trample();
    return 1;
  }
  if(!attacker_ob) {
    if(victim) {
      meat = present(victim,environment(this_object()));
      if(meat) {
        this_object()->attack_object(meat);
        trample();
        return 1;
      }
      meat = find_player(victim);
      if(meat) {
        if(environment(meat)->query_chaos() == "devour") {
          move_object(this_object(),environment(meat));
          tell_room(environment(meat),
            "A giant caterpillar arrives looking for "+
             capitalize(victim)+"!\n");
          this_object()->attack_object(meat);
          trample();
          return 1;
        }
      }
      return 1;
    }
    findmeat();
    return 1;
  }
  return 1;
}
 
findmeat() {
  object ob;
  if(!environment()) return 1;
  ob = first_inventory(ENV(TO));
  while(ob) {
    if(ob->is_player()) {
      if(random(10) < 4) {
        this_object()->attack_object(ob);
        trample();
        return 1;
      }
    }
    ob = next_inventory(ob);
  }
  return 1;
}
 
trample() {
  if(!tramps) tramps = random(5)+1;
  if(!attacker_ob) return 1;
  if(!attacker_ob || ENV(attacker_ob) != ENV(TO) ) return 1;
   if(attacker_ob->query_ghost()) return 1;
  tell_object(attacker_ob,"  A caterpillar foot crushes you!\n");
  attacker_ob->add_hit_point(-(random(5)+5));
  if(!attacker_ob->is_player()) attacker_ob->heal_self(-(random(5)+5));
  tramps--;
  if(tramps < 2) {
    last_trample();
    return 1;
  }
  trample();
  return 1;
}
 
last_trample() {
  if(!attacker_ob) return 1;
  tell_object(attacker_ob," The last foot crunches over you.\n");
  attacker_ob->heal_self(-(random(6)+5));
  tramps = random(5)+1;
  return 1;
}
 
