/* My Shadow name shadow - don't use if you don't know what you're doing */

object me, shadow_ob;
string actual_name, disguise_name;
int decay;

set_disguise_name(str) { disguise_name = str; }
set_actual_name(str) { actual_name = str; }

set_decay(num) {
  decay = num;
  call_out("disguise_fade", decay);
}

do_shadow(ob) {
  shadow_ob = ob;
  if (shadow(ob, 1))
    return 1;
  else
  return 0;
}

query_name() {
  if (shadow_ob->query_level() > 999)
    return "Rumplemintz";
  return disguise_name;
}

query_real_name() {
  if (shadow_ob->query_level() > 999)
    return shadow_ob->query_real_name();
  return disguise_name;
}

id(str) { return str == "rump_shad" || str == disguise_name; }

string
short() {
  return disguise_name;
}

status
long() {
  write(capitalize(actual_name)+", disguised as "+capitalize(disguise_name)+".\n");
  write(short()+".\n");
}

disguise_fade() {
  write("The disguise melts away.\n");
  destruct(this_object());
  return 1;
}
