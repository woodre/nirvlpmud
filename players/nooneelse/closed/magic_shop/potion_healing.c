/*
  potion_healing.c
*/

inherit "obj/treasure";

string str;

init() {
  ::init();

  add_action("drink", "drink");
}

drink(str) {
  if (!str || !id(str)) return 0;
  write("You drink the potion and the vial crumbles to dust.\n");
  say(this_player()->query_real_name()+
      " drinks from a vial,  which then crumbles to dust.\n", this_player());
  this_player()->heal_self(100);
  destruct(this_object());
  return 1;
}

reset(arg) {
  set_short("A glass vial");
  set_long("It is a small glass vial filled with a blue liquid.\n");
  set_value(10000);
  set_weight(1);
}

query_save_flag() { return 1; }

id(str) { return (str=="vial" ||
                  str=="glass vial" ||
                  str=="small vial" ||
                  str=="small glass vial" ||
                  str=="potion" ||
                  str=="healing potion"); }
