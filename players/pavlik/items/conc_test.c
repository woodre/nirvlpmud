long(){ write("A concussion tester.\n"); return; }
short(){ return "Concussion tester"; }
id(str){ return str == "ctest" || str == "tester"; }
query_weight(){ return 0; }
query_value(){ return 0; }
get(){ return 1; }
init(){
 add_action("ctest","ctest");
}

ctest(){
  object obj;
  write("Testing concussion...\n");
  obj = clone_object("players/pavlik/items/concussion");
  move_object(obj, find_player("pavtest"));
  obj->do_conc();
  return 1;
}
