inherit "obj/monster";
reset(arg) {
  if(arg)
    return ;
  ::reset(arg);
  set_name("lead");
  set_long("You see nothing.\n");
  set_level(1);
  set_hp(50000);
  add_commands();
}
add_commands() {
  add_action("nw", "nw");
  add_action("d","d");
  add_action("ne", "ne");
  add_action("se", "se");
  add_action("sw", "sw");
  add_action("u", "u");
  add_action("s", "s");
  add_action("e", "e");
  add_action("w", "w");
  add_action("n", "n");
}
nw() { command("northwest",this_object()); return 1; }
sw() { command("southwest",this_object()); return 1; }
se() { command("northeast",this_object()); return 1; }
ne() { command("southeast",this_object()); return 1; }
n() { command("north", this_object()); return 1; }
s() { command("south", this_object()); return 1; }
e() { command("east", this_object()); return 1; }
w() { command("west", this_object()); return 1; }
d() { command("down", this_object()); return 1; }
u() { command("up", this_object()); return 1; }
