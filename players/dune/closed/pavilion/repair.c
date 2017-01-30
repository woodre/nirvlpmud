/* this is the repair object, it stops all    */
/* actions from the pilot, except to bail out */
#define MECH environment(this_object())
#define TR   tell_room
#define TO   this_object()
id(str) { return "_system_maintenance_"; }
get() { return 0; }
drop() { return 1; }
reset() {}

object PIT(object ob) {
  object cockpit;
  cockpit = present("_cockpit_", environment(ob));
  return cockpit;
}

set_repairs(int time, string type) {
  TR(MECH, "You risk vulnerability and perform some "+
           type+" repairs.\n");
  call_out("all_done", 1, time);
#ifndef __LDMUD__
  add_action("stop_actions"); add_xverb("");
#else
  add_action("stop_actions", "", 3);
#endif
  return 1;
}



stop_actions(string str) {
   string mesg;
  if(str) if(str == "bail") { 
     call_other("/players/dune/closed/pavilion/control.c","out");
     destruct(this_object());
     return 1; }
   if(str) if(str == "sys" || sscanf(str, "comm%s", mesg)) { }
   else {
    TR(MECH, "Your mech is in repair, you must wait.\n");
     TR(MECH, "The only thing you can do is to 'bail', 'sys', or 'comm'.\n");
    return 1; }
}

all_done(int time) {
  if(time <= 0) {
    TR(MECH, "Repairs are completed.\n");
    destruct(this_object());
    return 1; }
  time -= 1;
  if(PIT(TO)) {
     MECH->heal_self(1);
    PIT(TO)->add_heat(-2);
    }
  call_out("all_done", 1, time);
  return 1;
}
