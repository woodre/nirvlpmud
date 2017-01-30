/*
 * Curse object - sits in inventory or cursed thing and resets heal_rate and
 *                heal_int upon destruct
 */

int org_rate, org_int;
object owner;

object set_owner(object ob) { return owner = ob; }

int id(string str) { return str == "doppleganger_curse_object"; }

int set_orgs(int hrate, int hint) {
  org_rate = hrate;
  org_int = hint;
  return 1;
}

void start_me() {
  if (owner && environment(this_object())->is_npc()) {
    environment(this_object())->set_heal(0, 305);
    call_out("stop_me", 300);
  } else
    destruct(this_object());
}

void reset(int arg) {
  if (arg) return;
}

void stop_me() {
  object badge;

  badge = present("V-GUILD", owner);
  badge->set_cursed(0);
  environment(this_object())->set_heal(org_rate, org_int);
  tell_room(environment(owner),
            "The curse on " + environment(this_object())->query_name() +
            " releases it's grip.\n", ({ owner }) );
  tell_object(owner,
            "Your curse on " + environment(this_object())->query_name() +
            " wears off.\n");
  destruct(this_object());
}

