inherit "obj/clean";

string junk_name() {
  return ({
    "ice cream sandwhich",
    "broken sword",
    "rose",
    "noodle",
    "hacksaw",
    "pencil",
    "prego jar",
  })[random(7)];
}
string junk_adjective() {
  return ({
    "an old",
    "a new",
    "a borrowed",
    "a blue",
    "a big",
    "a cheap",
    "an evil",
    "a glowing",
    "a slow",
    "a disestablishmentarianistic",
  })[random(10)];
}
