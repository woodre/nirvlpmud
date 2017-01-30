id(str) { return str == "bleater"; }
long() { write("Usage: bleatecho <msg>\n"); }
init() { add_action("bleatecho","bleatecho");
  add_action("bleatecho","be");
}

bleatecho(str) {
call_other("/players/mizan/closed/LiquidRoomDM.c","bleat"
  ,"(bleat) " + str + "\n");
  return 1;
}
