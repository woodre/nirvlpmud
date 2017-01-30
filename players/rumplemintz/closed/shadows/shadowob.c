object thisob;
string arg, shad;

void set_player_shadow(object ob) {
  thisob = ob;
  shadow(thisob, 1);
}

int remove_player_shadow() {
  thisob->unshadow();
  destruct(this_object());
  return 1;
}

int id(string str) {
  return str == "rumpshadow";
}

void set_shad(string str) { shad = str; }
void set_arg(string str) { arg = str; }

string short() {
  if (shad = "short")
    return arg;
  else (string)thisob->short();
}

string query_real_name() {
  if (shad = "query_real_name")
    return arg;
  else return (string)thisob->query_real_name();
}
