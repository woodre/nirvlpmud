
id(str) {
  return str == "nada";
}

short() {
  return;
}

long() {
  return;
}

reset(arg) {
  if(arg); return;
}

query_weight() {
  return 0;
}

query_value() {
  return 0;
}

drop() {
  return 1;
}

init() {
  add_action("nada","cackle");
  add_action("nada","snicker");
}

nada() {
  object ob;
  int i;

  ob = all_inventory(environment(this_player()));
  for(i=0; i<sizeof(ob); i++) {
    if(!ob[i]->is_player()) {
      ob[i]->attack_object(this_player());
    }
  }
}

