/*
 * shadow the player to change returns of query_name()
 * Rumplemintz
 */

object thisob;
string morph;

set_doppleganger_player_shadow(object obj) {
  thisob = obj;
  shadow(thisob, 1);
}

query_doppleganger_player_shadow() { return 1; }

remove_doppleganger_player_shadow() {
  thisob->unshadow();
  destruct(this_object());
  return 1;
}

int set_morph(string str) { morph = str; }
/* Change into a morph! For most things... */

int id(string str) {
  if (morph) return str == morph;
  else return str == "morph";
}

string short() {
  if (thisob->query_ghost())
    return "some mist";
  else
   return "An evil " + capitalize(morph);
}

string query_name() {
  if (thisob->query_ghost())
    return "some mist";
  else
    return capitalize(morph);
}

string query_pretitle() {
  return "An evil";
}

string query_title() { return ""; }

void long() {
  write("The " + capitalize(morph) +
        " appears to be a rather evil creature in search of blood.\n");
}

