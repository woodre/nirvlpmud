/*
 * Resurrection object
 * Just checks if the player wants to be rezzed or not
 * Rumplmeintz
 */

object caster, castee;

object set_caster(object ob) { return caster = ob; }
object set_castee(object ob) { return castee = ob; }

string short() { return 0; }

int id(string str) { return str == "doppleganger_rez_object"; }

void reset(int arg) {
  if (arg) return;
}

void start_res() {

  if (!castee) destruct(this_object());
  if (!caster) destruct(this_object());

  tell_object(castee,
              caster->query_name() +
              " has cast a resurrection spell on you.\n");
  tell_object(castee,
              "To accept, type \"res_accept\" - To decline, type " +
              "\"res_decline\"\n");
  tell_object(castee,
              "You have 30 seconds to decide.\n");
  call_out("no_decision", 30);
}

void init() {
  add_action("rez_func", "res_accept");
  add_action("rez_func", "res_decline");
}

int rez_func() {
  if (query_verb() == "res_accept") {
    tell_object(caster,
                castee->query_name() + " accespted your resurrection.\n");
    tell_object(castee, "Resurrection Accepted.\n");
    castee->remove_ghost_finish();
  } else if (query_verb() == "res_decline") {
    tell_object(caster,
                castee->query_name() + " declined your resurrection.\n");
    tell_object(castee, "Resurrection Declined.\n");
  }
  if (find_call_out("no_decision") != -1)
    remove_call_out("no_decision");
  destruct(this_object());
  return 1;
}

int no_decision() {
  tell_object(castee, "Resurrection has timed out.\n");
  tell_object(caster, "Resurrection on " + castee->query_name() +
              " has timed out.\n");
  destruct(this_object());
  return 1;
}

