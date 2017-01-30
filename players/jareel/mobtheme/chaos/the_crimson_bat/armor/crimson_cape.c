
inherit "obj/armor";
#include "/players/jareel/define.h"
#include "/players/jareel/ansi.h"
#define ATT USER->query_attack()
#define USER environment(this_object())
reset(arg) {
   ::reset(arg);

  set_name("cape");
  set_id("cloak");
  set_alias("cape");
  set_short(RED+"Crimson Cape"+NORM);
  set_long(

"This cloak is charged with a current of electricity.  A\n"+
"feeling of power comes over you as you gaze upon the\n"+
"finely sewn garmet.\n");

  set_type("cloak");
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
   if(!random(6)){
tell_room(environment(USER),
BOLD+RED+CAP(USER->query_name())+" is surrounded by a Crimson aura."+NORM+"\n");
ATT->add_spell_point(-9+random(9));
return 0;}
return 0;}
