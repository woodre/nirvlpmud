#include "/players/mythos/closed/ansi.h"
#define MY find_player("mythos")
#define MYTH tell_object(MY
object targ;
string msg;
id(str) { return str == "ward" || str == "viewer"; }

short() { return "Viewer-Ward"; }

init() { 
  if(this_player() == environment(this_object()))
     targ = this_player();
}

reset(arg) {
  if(arg) return;
  targ = 0;
  set_heart_beat(1);
}

heart_beat() {
  if(!environment(this_object())) { destruct(this_object()); return 1; }
  if(!targ) { destruct(this_object()); return 1; }
  if(MY) {
  msg = "   [ "+targ->query_real_name()+"  wc: ";
   msg += targ->query_wc()+"  ac: "+targ->query_ac()+"  hp: ";
   msg += targ->query_hp()+"/"+targ->query_mhp()+"  sp: "+targ->query_sp()+"/"+targ->query_msp();
  msg += "  ]";
   MYTH,BLU+msg+NORM+"\n");
}
}
