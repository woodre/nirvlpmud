inherit "obj/treasure";

reset(arg) {
  set_id("sconce");
   set_short("A clay sconce");
  set_long(
"     The clay sconce on the wall, has a candle inside of it,\n"+
"maybe you can 'light' it");
  set_weight(1000);
  set_value(0);
}
init() {
  add_action("cmd_light","light");
}
cmd_light(str) {
  notify_fail("Light what?\n");
  if(!str) return 0;
  if(str!="candle" && str!="the candle") return 0;
  write(
"     The candle flickers softly, then lights up the stairs.  Some symbols\n"+
"can be seen on the adjacent wall.\n");
  return 1;
}
get() { return 0; }  
