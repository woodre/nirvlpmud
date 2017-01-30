/*
 * Object to lower a monster's WC
 * Rumplemintz
 */
#include <ansi.h>

int wc, org_wc, duration;

mapping wc_mod;

void original() {
  org_wc = (int)environment()->query_wc();
}

status set_duration(int hbs) { return duration = hbs; }

void wc_mod() {
  object ob;

  ob = environment(this_object());
  if (!wc_mod)
    wc_mod = ([ ]);
  if (wc_mod[ob]) {
    wc_mod[ob] = wc_mod[ob] - org_wc/2;
  } else {
    wc_mod[ob] -= org_wc/2;
  }
  ob->RegisterWeapon(this_object(), ({ "physical", wc_mod[ob], 0 }));
}

void reset() {
  set_heart_beat(1);
}

status id(string str) { return str == "mystic_veil_ob"; }

void heart_beat() {
  if (!environment())
    return;
  if (!living(environment()) || !environment()->is_npc())
    destruct(this_object());
  if (duration)
    duration -= 1;
  if (!duration) {
    environment()->set_wc(org_wc);
    tell_room(environment(environment()),
              environment()->query_name() + " regains " +
              environment()->query_possessive() + " strength.\n");
    destruct(this_object());
  }
}

no_exp_effect() { return 1; }
string extra_look() {
  return environment()->query_name() +
         " is covered in a " + HIG + "Mystic" + NORM + " veil";
}

