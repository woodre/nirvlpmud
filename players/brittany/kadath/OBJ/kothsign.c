inherit "obj/treasure";

reset(arg) {
  set_id("stone");
   set_short("A huge stone");
  set_long(
"This is a stone with a sign lodged into it.  Perhaps you\n"+
"could 'read' the sign");
  set_weight(1000);
  set_value(0);
}
init() {
  add_action("cmd_read","read");
}


cmd_read(str) {
  notify_fail("You can not read that!\n");
  if(!str) return 0;
  if(str!="sign" && str!="the sign") return 0;
  write(
"This is the sacred temple of the Great One.  The cursed ones were\n"+
"sent to the cemetary through a stone door at the top of the stairs.\n"+
"The door leads through the Enchanted Woods, back to the waking world.\n"+
"There is a book 'hidden' deep within the woods, that would be very\n"+
"helpful in deciphering information.\n");
  return 1;

}
get() { return 0; }  
