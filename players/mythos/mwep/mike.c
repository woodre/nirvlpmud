#include "/players/mythos/closed/ansi.h"
#define tp this_player()
int w;
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
   set_name("microphone");
    set_alt_name("mike");
    set_alias("dj_weapon");
     set_short("A Microphone");
    set_long("A miscrophone of a DJ.  This is a power item.\n"+
             "Power throbs through it and you feel elated!\n"+
             "There is something etched into it.\n");
    set_read("Keep the Faith of Juliana's Tokyo!\n");
    set_class(18);
    set_weight(4);
    set_value(5000);
    set_hit_func(this_object());
}
weapon_hit(attacker){
if(random(3) == 0) {
  write("You lash out with the mike and POWER floods you!\n");
  say(capitalize(tp->query_real_name())+" lashes out with the mike!\n");
  tell_room(environment(tp),
  HIR+"\n\n       ****  "+NORM+BOLD+" CRACK "+NORM+HIR+"  ****\n\n\n"+NORM);
return 7; }
return;
}

query_save_flag()  { return 0; }

init() {
  ::init();
  if(tp->query_real_name() == "dj") {
  this_object()->set_class(40); }
  else { this_object()->set_class(18); }
} 
