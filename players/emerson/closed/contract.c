inherit "obj/treasure";

reset(arg) {
  set_short("Mercenary Contract");
  set_long("A contract from Cyrex's Mercenary Chamber.\n");
  set_value(0);
  set_weight(1);
}

get() {
  return 1;
}

drop() {
   write("You cannot drop your contract!\n");
  return 1;
}
id(str) { return str=="contract" || str=="mercenary contract"; }

