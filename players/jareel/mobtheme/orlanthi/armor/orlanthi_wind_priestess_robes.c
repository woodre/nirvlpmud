inherit "obj/armor";
#include "/players/jareel/define.h"
#include "/players/jareel/ansi.h"
#define ATT USER->query_attack()
#define USER environment(this_object())

reset(arg) {
 ::reset(arg);
 call_out("elec",60);

set_name("robes");
set_id("armor");
set_alias("robes");

set_short(BOLD+BLU+"Lightning Robes"+NORM);
set_long(
  "This armor is charged with a current of arcing electricity.  A surge\n"+
  "of power pulsates through the garment.  The runes of Air and motion\n"+
  "are finely embroidered throughout its surface.  \n");

set_ac(4);
/*
set_save_flag(1);
Make save -Bp
*/
set_value(1100);
set_type("armor");
set_weight(4);
 
}

elec() {
object hh;
if(!environment(this_object())) return 1;
hh = environment(environment(this_object()));
if(!hh) return 0;
tell_room(hh,
"Arcing "+BOLD+"electrical energy"+NORM+" leaps from "+CAP(USER->query_name())+"'s robes."+NORM+"\n");
call_out("elec2",60);
   return 1;
}

elec2() {
object hh;
if(!environment(this_object())) return 1;
hh = environment(environment(this_object()));
if(!hh) return 0;
tell_room(hh,
""+BOLD+BLU+CAP(USER->query_name())+"'s robes"+NORM+" humm with raw power."+NORM+"\n");
   call_out("elec3",20);
   return 1;
}

elec3() {
object hh;
if(!environment(this_object())) return 1;
hh = environment(environment(this_object()));
if(!hh) return 0;
tell_room(hh,
""+BOLD+"Electricity arcs "+NORM+"over "+CAP(USER->query_name())+"'s body."+NORM+"\n");
call_out("elec",60);
   return 1;
}



do_special(owner)
{
   if(!random(6)){
     tell_room(environment(USER),
BOLD+BLU+CAP(USER->query_name())+" robes course with energy"+NORM+".\n");
owner->add_spell_point(random(3));
return 0;}
return 0;}
