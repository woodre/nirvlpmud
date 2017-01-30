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
  write("E : Church  S : Shop  AG : Advance  P : Post  Q : Quantos  M : M\n");
}
 
init() {
  add_action("q","q");
  add_action("s","south");
  add_action("e","east");
  add_action("ag","ag");
  add_action("p","p");
  add_action("m","m");
}
 
e() {
  call_other(this_player(), "move_player", "X#room/church");
  return 1;
}
 
s() {
  call_other(this_player(), "move_player", "X#room/shop");
  return 1;
}
 
ag() {
  call_other(this_player(), "move_player", "X#room/adv_guild");
  return 1;
}
 
p() {
  call_other(this_player(), "move_player", "X#room/post");
  return 1;
}
 
q() {
  move_object(this_player(),environment(find_living("quantos")));
  return 1;
}
 
m() {
  move_object(this_player(),environment(find_living("m")));
  return 1;
}
 
reset(arg) {
  set_light(1);
}
