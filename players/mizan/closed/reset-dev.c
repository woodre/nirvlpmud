id(str) { return str == "device"; }
short() { return "Zok's Nuclear Reset Device [Release One]"; }
long() {
  write("This device resets everything in the room. To use, type 'zok room'.\n");
}

get() { return 1; }
drop() { return 1; }

init() { 
  add_action("zokroom","zok");
}

zokroom(str) {
  object ob;
  string rnamea;
  if(!str || str != "room") return 0;
  ob=first_inventory(environment(this_player()));
  while(ob) {
    object oc;
      oc=ob;
    ob=next_inventory(ob);
  rnamea=object_name(oc);
  if(!living(oc) && !oc->query_npc()) {
      write("Object: " + (oc->short()) + " zokked.\n");
      destruct(oc);
  if(find_object(rnamea)) {
    destruct(find_object(object_name(oc)));
  }
    }
 }
  write("Ok.\n");
  return 1;
}
