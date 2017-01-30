#include "/players/cosmo/closed/ansi.h"
inherit "obj/armor";
reset(arg) {
  set_name("plastic");
  set_short("A large, clear chunk of plastic");
  set_alias("shield");
  set_long(
    "\nThis is a piece of the bubble in which the Bubble Boy\n"+
    "lived.  It protected him from the environment and\n"+
    "allowed him to live, so doubtlessly it can offer you\n"+
    "protection as well.\n\n");
  set_ac(1);
  set_type("shield");
  set_weight(1);
  set_value(100);
  set_save_flag();
}

wear(str){
  if (::wear(str) && worn) {
    write("The plastic begins to glow as it surrounds your body.\n");
    set_short("A large, clear chunk of plastic ("+BLU+"glowing"+NORM+")");
    set_light(1);
  return 1; }
}


remove(str){
  if (::remove(str) && !worn) {
    write("The glow of the plastic fades away.\n");
    set_short("A large, clear chunk of plastic");
    set_light(-1);
  return 1; }
}

drop(silently){
  if (worn && !::drop(silently)) {
    write("The glow of the plastic fades away.\n");
    set_short("A large, clear chunk of plastic");
    set_light(-1);
  return 0; }
}

