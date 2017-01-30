/*
  ru784.c - abortion pill
*/

inherit "obj/treasure";

init() {
  ::init();

  add_action("read",    "read");
  add_action("read",    "examine", 3);
  add_action("read",    "look", 1);
  add_action("swallow", "swallow");
}

read(str) {
  string str1, str2;
  if (!str) return 0;
  if (str=="pill" || str=="at pill") str="at pill";
  sscanf(str, "%s %s", str1, str2);
  if (str!="pill" && str2!="pill") return 0;
  write("This pill will remove an unwanted pregnancy.\n"+
        "To use: swallow pill\n");
  return 1;
}

swallow(str) {
  if (str!="pill" && str!="abortion pill" && str!="ru784 pill") return 0;
  if(!this_player()->query_pregnancy()){
    write("You are not pregnant.\n");
    return 1;
  }
  this_player()->clear_pregnancy();
  destruct(this_object());
  write("Ok.  Pregnancy terminated.\n");
  return 1;
}

reset(arg) {
  set_short("An RU784 pill");
  set_value(1500);
  set_weight(1);
}

id(str) { return (str=="pill"  || str=="abortion pill" || str=="ru784"); }
