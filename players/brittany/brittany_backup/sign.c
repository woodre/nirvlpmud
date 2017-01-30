inherit "obj/treasure";

reset(arg) {
  set_id("sign");
  set_short("A tall, wooden sign");
  set_long(
"This is a tall wooden sign about Trix's realm.  Perhaps you\n"+
"should read it.\n");
  set_weight(1000);
  set_value(0);
}
init() {
  add_action("cmd_read","read");
}
cmd_read(str) {
  notify_fail("Read what?\n");
  if(!str) return 0;
  if(str!="sign" && str!="the sign") return 0;
  write(
"This is a temporary sign to remind everybody that Trixtown has\n"+
"been moved to a new location s,6w,2s,e from the church or southeast\n"+
"of the Big House and due east from Bagera's Jungle.  If you have\n"+
"any questions or comments, please mail me.\n\n"+
"\t\t\t\t\t-Feldegast\n");
  return 1;
}
get() { return 0; }
