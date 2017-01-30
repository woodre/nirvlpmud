#include <ansi.h>

inherit "obj/treasure";

int id(string str) {
  return str == "gift" || str == "present" || str == "box";
}

reset(arg) {
  ::reset(arg);
  set_short("A present");
  set_long("A box wrapped in christmas paper.  Maybe you can open it?\n");
  set_weight(1);
  set_value(1);
}

init() {
    ::init();
    add_action("open_gift","open");
}

open_gift(str) {
  object *people;
  int i;

  if(!str) return 0;
  if (str != "gift" && str != "present") return 0;
  people = users();
  for (i = 0; i < sizeof(people); i++) {
    if (people[i]->on_channel("junk"))
      tell_object(people[i],
                  this_player()->query_name() +
                  " is covered in " + BWHT + HIBLK + "soot" + NORM +
                  " from an exploding package!\n");
      tell_object(people[i],
                  "Jokey Smurf can be heard cackling off in the distance.\n");
  }
  write("You open the gift and it EXPLODES!!\n");
  write("You are covered in soot!\n");
  move_object(clone_object("/players/rumplemintz/obj/soot"), this_player());
  destruct(this_object());
  return 1;
}
