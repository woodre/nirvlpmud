void DR_dir_abbreviations() {
  add_action("go_north"); add_verb("n");
  add_action("go_south"); add_verb("s");
  add_action("go_west"); add_verb("w");
  add_action("go_east"); add_verb("e");
  add_action("go_northwest"); add_verb("nw");
  add_action("go_northeast"); add_verb("ne");
  add_action("go_southwest"); add_verb("sw");
  add_action("go_southeast"); add_verb("se");
  add_action("go_up"); add_verb("u");
  add_action("go_down"); add_verb("d");
}

go_north() { command("north"); return 1; }
go_south() { command("south"); return 1; }
go_east()  { command("east");  return 1; }
go_west()  { command("west");  return 1; }
go_up()    { command("up");    return 1; }
go_down()  { command("down");  return 1; }
go_northwest() { command("northwest"); return 1; }
go_northeast() { command("northeast"); return 1; }
go_southwest() { command("southwest"); return 1; }
go_southeast() { command("southeast"); return 1; }
