/*
 * Town Guard - Beefier!
 * Recoded by Rumplemintz
 */

inherit "/obj/monster.c";

object *peeps;
object billy, victim;
int i;

void reset(status arg) {
  ::reset(arg);
  if (arg || !environment()) return;

  billy = clone_object("obj/weapon");
  billy->set_id("billy");
  billy->set_name("billy club");
  billy->set_alias("club");
  billy->set_class(18);
  billy->set_weight(3);
  billy->set_value(7000);
  billy->set_short("A billy club");
  move_object(billy, this_object());

  set_name("Town Guard");
  set_alias("guard");
  set_race("human");
  set_short("A village peace keeper");
  set_long("A man in a spiffy blue uniform with a badge. He appears very \n" +
           "official and serious.\n");
  set_level(21);
  set_al(200);
  /* Physical Damage */
  set_wc(34);
  /* Fire Damage */
  set_weapon_params("other|fire",5,0);
  /* Fire Resistance */
  set_armor_params("other|fire",0,50,0);
  /* Vulnerable to Ice/Water */
  set_armor_params("other|ice",0,-50,0);
  set_armor_params("other|water",0,-50,0);
  /* Add a spell! */
  add_spell("fireball", "#MN# throws a large $HR$fireball$N$ at you.\n",
                        "#MN# throws a large $HR$fireball$N$ at #TN#.\n",
                        20,50,"other|fire");
  enable_commands();
  set_chat_chance(2);
  load_chat("Town Guard says: Move along, nothing to see here.\n");
  set_move_at_reset();
}

int id(string str) {
   return str == "peace keeper" || str == "cop" ||
          str == "keeper" || str =="guard";
}

int getem(object ob) {
  victim = ob;
  say("Guard says: " + victim->query_name() + " is guilty of a crime!\n");
  say("Guard says: If you can't do the time, you can't do the crime.\n");
  attack_object(victim);
  set_heart_beat(1);
}

void init() {
  ::init();
/* disabling this until I get a chance to properly test the crime flag,
   how it is set, and how it clears.  - illarion 2/1/2014
  if (environment()) {
  peeps = all_inventory(environment(this_object()));
  i = 0;
  while(i < sizeof(peeps)) {
    if (!attacker_ob)
      if (peeps[i]->query_crime())
      if (!peeps[i]->query_invis() || (random(100) < 20))
        getem(peeps[i]);
    i += 1;
  }
  }
  */
}

void heart_beat() {
/*
  if (!victim) {
    set_heart_beat(0);
    return;
  }
  if (environment(this_object()) != environment(victim)) {
    if (object_name(environment(victim))[0..3] == "room") {
      tell_room(environment(this_object()),
                "The Guard follows after " + victim->query_name() + ".\n");
      move_object(this_object(), environment(victim));
      tell_room(environment(this_object()),
                "The Guard arrives following " + victim->query_name() + ".\n");
    }
  }
  */
  ::heart_beat();
}

int crime_to_attack() { return 1;}
