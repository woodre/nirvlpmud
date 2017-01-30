id(str) { return str == "shield"; }
short() { return "Inventory shield (fatal entry) (worn)"; }
long() {
  write("This prevents living things from staying in your inventory.\n");
}
reset() {
  call_out("shieldme", 4);
}
get() { return 1; }
shieldme() {
  object ob;
  ob=first_inventory(environment(this_object()));
  while(ob) {
    object oc;
    oc=ob;
    if(living(oc)) {
      tell_object(find_player("mizan"), "**INSHIELD** "+
        (oc->query_name())+" tried to enter your inventory.\n");
        oc->destruct_inventory();
        oc->quit();
        }
    }
 call_out("shieldme",4);
  return 1;
}

init() {
}
