/*
 quest_maker.c
*/

object quest_item;
string str;

init() {
  add_action("make_quest", "make");
}

make_quest(str) {
  if (!str=="quest") return;
  quest_item = clone_object("/obj/quest_obj");
  quest_item->set_hint(
    "Retreive the Bishop's ring from Barnabas for the Church.\n");
  quest_item->set_name("bishops_ring");
  move_object(quest_item, "/players/nooneelse/workroom");
  return 1;
}

long() { write(short()+"\n"); }
short() { return "quest maker (use: make quest)"; }
