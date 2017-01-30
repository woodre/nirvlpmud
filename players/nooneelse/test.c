/*
 test.c
*/

inherit "room/room";

string command_str;

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc = "test room";
  long_desc = "This is to test catch_tell.\n";
  dest_dir = 
    ({
      "players/nooneelse/workroom", "north",
    });
}
/*>>>*/
init() {
  ::init();

  add_action("say_what"); add_xverb("");
}

say_what(str) {
write(">>> str='"+str+"'\n");
}
