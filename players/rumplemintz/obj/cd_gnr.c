#pragma strong_types

inherit "obj/treasure";

void reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_name("case");
  set_alias("cd case");
  set_short("A CD case");
  set_long("On the side it says:\n"+
           "          Guns 'n Roses - Appetite for Destruction\n"+
           "\nIt looks like you could read the case.\n");
  set_weight(0);
  set_value(0);
}

void init() {
  ::init();
  add_action("read", "read");
}

status read(string str) {
  if(!str || !id(str))
    return 0;
  cat("/players/rumplemintz/ascii/appetite.ascii");
  return 1;
}
