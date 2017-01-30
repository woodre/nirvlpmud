inherit "obj/armor";
#include "/players/jareel/define.h"
#include "/players/jareel/ansi.h"
#define ATT USER->query_attack()
#define USER environment(this_object())
reset(arg) {
   ::reset(arg);

  set_name("helmet");
  set_id("helmet");
  set_alias("helm");
  set_short(BLU+"Helm"+NORM+" of the "+BLU+"Storm"+NORM);
  set_long(

"This cloak is charged with a current of electricity.  A\n"+
"feeling of power comes over you as you gaze upon the\n"+
"finely sewn garmet.\n");

  set_type("helmet"); 
  set_ac(2);
  set_weight(1);
 }

do_special(ob){
   object me;
   me = worn_by;
   if(!me) me = environment();
   if(!me) return;
   if(!living(me)) return;
   if(!ob) return;
{
tell_room(environment(USER),
BOLD+RED+CAP(USER->query_name())+" is surrounded by a Crimson aura."+NORM+"\n");
me->add_spell_point(3);
me->add_hit_point(-3);
return 0;}
return 0;}
