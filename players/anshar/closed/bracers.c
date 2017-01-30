#include "/players/anshar/closed/mydef.h"
inherit "obj/armor";
reset(arg){
   ::reset(arg);
   set_name("speed bracers");
   set_short("Bracers of speed");
   set_alias("bracers");
   set_long("A pair of dark leather bracers. They shimmer slightly with power\n");
   set_type("ring");
   set_ac(2);
   set_weight(1);
   set_value(1000);
}
init() {
  ::init();
  call_out("speed",5);
}
speed() {
  if(worn) {
  if(environment(this_object())->query_attack()) {
      tell_object(environment(this_object()),
                 "You attack again!\n"+
                 "The bracers hum with power!\n");
      environment(this_object())->attack();
      environment(this_object())->hit(environment(this_object())->query_attack());
    }
  }
   call_out("speed",5);
   return 1;}
