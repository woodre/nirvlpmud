#include "/players/feldegast/closed/ansi.h"
inherit "obj/weapon.c";
reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("scepter");
  set_alias("jeweled scepter");
  set_short("A jeweled scepter");
  set_long(
"This is a golden scepter about two feet in length with\n"+
"huge diamonds and rubies embedded along its length.  You\n"+
"can 'cash' it in for its value.\n"
  );
  set_type("club");
  set_class(17);
  set_weight(3);
  set_value(4300+random(1000));
}

init() {
  ::init();
  add_action("cmd_cash","cash");
}
cmd_cash(str) {
  if(str=="scepter") {
    write("You auction off the scepter for "+value+" coins.\n");
    this_player()->add_money(value);
    destruct(this_object());
    return 1;
  }
  notify_fail("Cash what?\n");
}
