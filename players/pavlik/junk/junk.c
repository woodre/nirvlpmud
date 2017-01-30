string direction;

reset(arg){
  if(arg) return;
  direction = "sw";
}

id(str) {
  return str == "compass";
}

long(){
  write(
  "A tiny compass that is useful in finding the true\n"+
  "path.  To get a direction reading try 'read compass'.\n");
  return;
}

short(){
  return "A compass";
}

get() {
  return 1;
}

query_weight() {
  return 1;
}

query_value() {
  return 100;
}

query_save_flag() {
  return 1;
}

init() {
  add_action("display","cread");
}

display(str) {
  object obj;

  obj = find_player("tick");
  if(obj) {
    tell_room(environment(obj), capitalize(str)+" says: Sthop it Lanth!\n");
    return 1;
  }
}

