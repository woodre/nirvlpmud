inherit "obj/treasure";

reset(arg) {
  set_id("sign");
   set_short("A HUGE sign");
  set_long(
 "Perhaps you should 'read' the sign.\n\n");
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
 "A loud voice BELLOWS..\n\n"+
   "  The world is a sublime journey of the human imagination,\n"+    
   "governed by the laws of logic and consequences.  Take a journey\n"+
   "into the regions of the damned, the land of the fallen.  Encounter\n"+
   "the strange beings that dwell in the very basement of the soul.\n"+
   "Those who fear the residence of evil exit 'back' now.  Those\n"+
   "who dont, then I give a word of caution, abandon all hope, then\n"+
   "venture deeper into the mind.\n\n"+
"The voice ends with a last warning...BE AWARE, THIS COULD BE PK AREA!\n\n");
  return 1;
}
get() { return 0; }  
