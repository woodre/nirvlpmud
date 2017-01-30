inherit "obj/treasure";

reset(arg) {
 if(arg) return;
    set_short("A Green Potion");
    set_alias("potion");
  set_long("This is a glass bottle filled with a strange green potion.\n"+
   "To use this item type: potion.\n");
   set_weight(2);
    set_value(7500);
}
 id(str) { return str == "potion" || str == "green potion"; }

init() {
 ::init();
  add_action("potion","potion");
}

potion() {
  int i;
  i = 300618 - 299924;
  write("The answer is "+i+"\n");
  return 1;
}
