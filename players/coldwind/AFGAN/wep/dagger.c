#include "/players/coldwind/define.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("dagger");
set_alias("weapon");
set_short(BOLD+"W"+NORM+"ide "+BOLD+"B"+NORM+"lade "+BOLD+"D"+NORM+"agger"+NORM);
set_long(BOLD+
" You are examining a strange looking dagger. The word 'o_|_||' is carved on the\n"+
"handle, while the wide blade is curved against the edged side to add the unique \n"+
"look of the dagger, but also increasing the performance and the ability to maneuver\n"+
"with the weapon.\n"+NORM);
set_type("knife");
set_class(18);
set_weight(3);
set_value(1000);
set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
object user;
user = environment(this_object())->query_name();
W = random(21);
if(W>16)  {
  say(WHT+"\n"+
          "       ~~~~~~~~~"+HIW+"T H W A C K"+NORM+WHT+"~~~~~~~~~ \n"+
  ""+NORM+"   The wide blade sinks deep in your flesh.\n"+
  " \n");

  write(WHT+"\n"+
          "       ~~~~~~~~~"+HIW+"T H W A C K"+NORM+WHT+"~~~~~~~~~ \n"+
  ""+NORM+"   The wide blade sinks deep in "+ attacker->query_name() + "'s flesh.\n"+
  " \n");
  return 7;
   }
if(W>11)  {
  say(HIC+"                     |  |  | \n"+
          "                   Q_|__|  | \n"+     
   "       "+NORM+HIK+""+ attacker->query_name() + " drops on the ground in agony"+NORM+"\n");

  write(HIC+"                     |  |  | \n"+
            "                   Q_|__|  | \n"+     
   "       "+NORM+HIK+""+ attacker->query_name() + " drops on the ground in agony"+NORM+"\n");

  return 4;
   }
return;
}
