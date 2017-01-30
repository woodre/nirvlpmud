inherit "/obj/treasure.c";

void reset(int arg) {
  if(arg) return;
  set_id("blah");
  set_alias("no_mini");
  set_short("Blah thing");
}
init() {
  add_action("blah", "blah");
}

blah(str) {
  input_to("blah2");
  return 1;
}

blah2(str) {
  write(str);
  write(this_player()->query_guild_rank());
}
