/*
 * Object to lower a monster's AC
 * Rumplemintz
 */

int ac, org_ac, duration;

mapping ac_mod;

void original() {
  org_ac = (int)environment()->query_ac();
}

status set_duration(int hbs) {
  duration = hbs;
}

void ac_mod() {
  object ob;

  ob = environment(this_object());
  if (!ac_mod)
    ac_mod = ([ ]);
  if (ac_mod[ob]) {
    ac_mod[ob] = ac_mod[ob] - org_ac/2;
  } else {
    ac_mod[ob] -= org_ac/2;
  }
  ob->RegisterArmor(this_object(), ({ "physical", ac_mod[ob], 0, 0 }));
}

void reset() {
  set_heart_beat(1);
}

status id(string str) { return str == "mystic_weaken_ob"; }

void heart_beat() {
  if (!environment())
    return;
  if (!living(environment()) || !environment()->is_npc())
    destruct(this_object());
  if (duration)
    duration -= 1;
  if (!duration) {
    environment()->set_ac(org_ac);
    tell_room(environment(environment()),
              environment()->query_name() + " regains " +
              environment()->query_possessive() + " strength.\n");
    destruct(this_object());
  }
}

no_exp_effect() { return 1; }
