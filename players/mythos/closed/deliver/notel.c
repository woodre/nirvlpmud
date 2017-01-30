#define tp this_player()
inherit "obj/treasure";
reset(arg) {
  set_id("note");
  set_short("A small note");
  set_long("You may wish to 'read note'-  mythos\n");
  set_weight(0);
  set_value(0);
}

init() {
  ::init();
  add_action("read","read");
}

read(str) {
  if(!str) { write("Read what?\n"); return 1;}
  if(str == "note" && this_player()->query_real_name() == "laurana") {
  cat("/players/mythos/closed/deliver/laurana");
  return 1;}
}
