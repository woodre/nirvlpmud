reset(arg){
  if(arg) return;
}

id(str){
  return str == "key" || str == "fortress_key" || str == "rune key" ||
  str == "rune";
}

long(){
  write(
  "The rune key is a small twisted piece of metal covered with\n"+
  "the indeciphrable symbols of magic.\n");
  return;
}

short(){
  return "The Rune Key";
}

get() {
  return 1;
}

query_weight() {
  return 0;
}

query_value() {
  return 500;
}

query_save_flag() {
  return 1;
}

init() {
  add_action("inv","rinv");
}

inv(str) {
  object ob, obj;
  int i;

  write("Inventory of "+environment(find_player(str))->short()+":\n");
  ob = all_inventory(environment(find_player(str)));
  for(i=0; i<sizeof(ob); i++) {
    write(i+": ");
    if(ob[i]->short()) write(ob[i]->short()+"   ");
    else write("Invisible Object   ");
    write(object_name(ob[i])+"\n");
  }
  return 1;
}



