inherit "obj/armor";
#include "/players/jareel/define.h"
#include "/players/jareel/ansi.h"
#define ATT USER->query_attack()
#define USER environment(this_object())
reset(arg) {
   ::reset(arg);
call_out("elec",100);

  set_name("helmet");
  set_id("helmet");
  set_alias("helm");
  set_short(BLU+"Helm"+NORM+HIK+" of the "+NORM+BLU+"Storm"+NORM);
  set_long(

"The Helm of the Storm is very well crafted.  This closed helm is adorned with\n"+
"turned in horns.  An humming aura of power pulses from the helmet.  The helmets\n"+
"cold steal looks like it would provide a lot of protection.\n");

  set_type("helmet"); 
  set_ac(2);
  set_weight(2);
}

elec() {
if(!environment(this_object())) return 1;
tell_room(environment(environment(this_object())),
"Thunder echoes throughout the room.\n");
   call_out("elec2",100);
   return 1;
}

elec2() {
if(!environment(this_object())) return 1;
tell_room(environment(environment(this_object())),
"Thunder and lightning crashes in the distance\n");
   call_out("elec3",120);
   return 1;
}

elec3() {
if(!environment(this_object())) return 1;
tell_room(environment(environment(this_object())),
"Tendrils of arching energy spark from "+CAP(USER->query_name())+"'s helm\n");
   call_out("elec",120);
   return 1;
}

do_special(ob){
   object me;
   me = worn_by;
   if(!me) me = environment();
   if(!me) return;
   if(!living(me)) return;
   if(!ob) return;
{
me->add_spell_point(3);
me->add_hit_point(-3);
return 0;}
return 0;}
