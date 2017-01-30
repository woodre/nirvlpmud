#include "/players/jaraxle/define.h"
inherit "obj/armor";

reset(arg){
   ::reset(arg);

set_name("bracer");
set_alias("glowing bracer");
set_short(HIG+"G"+HIC+"lowing "+HIG+"B"+HIC+"racer"+NORM);
set_long(
"A medium sized bracer with an imperfect "+HIG+"emerald"+NORM+" set in the center.\n"+
"Within the "+HIG+"emerald"+NORM+" an eagle's talon has been etched. The bracer's\n"+
""+HIG+"emerald"+NORM+" sets off a "+HIG+"green"+NORM+" hue, which makes the bracer "+HIC+"glow"+NORM+".\n");

set_type("ring");
set_ac(2);
set_weight(1);
set_value(1100);
}

do_special(owner){
if(random(100) < 40) { tell_object(environment(),
 "You hold forth the glowing bracer...\n"+
  "A giant "+HIG+"Emerald Claw"+NORM+" of light flows from its top crystal!\n"+
  "It rushes towards your enemy, "+HIR+"GASHING"+NORM+" them terribly!\n");
  return 1; }
return 0;
}
