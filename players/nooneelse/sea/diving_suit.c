/*
 diving_suit.c
*/

inherit "obj/armor";

int suit_is_torn;

init() {
  ::init();

  add_action("dive", "dive");
}

dive() {
  string str2;
  if (suit_is_torn) {
    str2=this_player()->query_current_room();
    if (str2=="players/nooneelse/sea/island_diving_room") {
      write("you can't dive with a torn suit!  You'd drown!\n");
      return 1;
    }
  }
  return;
}

reset(arg) {
  ::reset(arg);

  set_name("diving suit");
  set_short("diving suit");
  set_value(200);
  set_weight(2);
  set_ac(2);
  set_type("armor");
  suit_is_torn=0;
}

long() {
  write("A rubberized canvass diving suit with an attached bubble helmet.\n");
  if (suit_is_torn)
    write("It has a tear in the left leg and left arm.\n");
}

query_suit_is_torn() { return suit_is_torn; }

set_suit_is_torn(arg) { suit_is_torn=arg; }

id(str) {
  return (str=="diving suit" || str=="suit" || str=="armor");
}
