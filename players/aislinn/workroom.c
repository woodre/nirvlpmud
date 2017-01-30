id(str) {return str == "home";}
 
short() {
  return "Aislinn's Hide-E-Hole";
}
 
long() {
  write("  \n");
  write("Welcome to Aislinn's favorite place.  A walk-in fireplace is set\n");
  write("in the north wall,  with a cheery fire blazing away.  Two large, \n");
  write("comfy,  leaf-green over-stuffed chairs sit in front of it,  with\n");
  write("a small table set between them.   The west wall is entirely made\n");
  write("of glass,  and allows one to look out upon  the world of Avalon.\n");
  write("Bookshelves cover the east wall,  with a sofa  and three  chairs\n");
  write("creating  a cosy reading  area.  Pillows are scattered about for\n");
  write("those who prefer to sit on the floor.  Make yourself at home  :)\n");
  write("                                                                 \n");
  write("N : Church  S : Shop  E : Advance  W : Post  U : Pub  D : Castle\n");
}
 
init() {
  add_action("north"); add_verb("n");
  add_action("north"); add_verb("north");
  add_action("south"); add_verb("s");
  add_action("south"); add_verb("south");
  add_action("east"); add_verb("e");
  add_action("east"); add_verb("east");
  add_action("west"); add_verb("w");
  add_action("west"); add_verb("west");
  add_action("down"); add_verb("d");
  add_action("down"); add_verb("down");
  add_action("up"); add_verb("u");
  add_action("up"); add_verb("up");
}
 
north() {
  call_other(this_player(), "move_player", "X#room/church");
  return 1;
}
 
south() {
  call_other(this_player(), "move_player", "X#room/shop");
  return 1;
}
 
east() {
  call_other(this_player(), "move_player", "X#room/adv_guild");
  return 1;
}
 
west() {
  call_other(this_player(), "move_player", "X#room/post");
  return 1;
}
 
down() {
  call_other(this_player(), "move_player", "X#players/aislinn/first_aid");
  return 1;
}
 
up() {
  call_other(this_player(), "move_player", "X#room/pub2");
  return 1;
}
 
reset(arg) {
  set_light(1);
}
