/*
  icon.c - used to trash the lich in nooneelse's graveyard crypt
*/

inherit "obj/treasure";

reset(arg) {
  set_id("icon");
  set_alias("holy item");
  set_short("A gold icon");
  set_long("This is a little gold statue with ancient words etched in it.\n");
  set_value(50);
  set_weight(1);
}

query_save_flag() { return 1; }

id(str) { return str=="icon" || str=="holy item" || str=="nooneelseicon"; }

init() {
  add_action("read", "read");
}

read(str) {
  if (!str || !id(str)) return 0;
  write("Most of the words are faded.  What you can make out looks like:\n"+
        "...placed where the lich runs to hide...\n");
  return 1;
}
