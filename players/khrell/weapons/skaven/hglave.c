#include "/players/khrell/define.h"
#include <ansi.h>
inherit "obj/weapon.c";

reset(arg) {
   ::reset(arg);
   if (arg) return;
   
   set_name("hellglave");
   set_alias("glave");
   set_type("polearm");
   set_short(HIY+"Hell"+NORM+YEL+"glave"+NORM);
   set_long(
"   The hellglave is a diabolic polearm forged and used by the infernal\n"+
"Verminlords.  Only the most blackhearted and sinister would ever dare\n"+
"to use this evil weapon.\n");  
   set_class(19);
   set_weight(4);
   set_value(10000);
   set_hit_func(this_object());
}


weapon_hit(attacker){
  if(random(13) > 8) {
say("\n\n"+
 "The hellglave "+RED+"C L E A V E S "+NORM+" a massive "+HIR+"gaping wound"+NORM+
 " in its target!\n");
 
 
 write("\n\n"+
  "Your hellglave "+RED+"C L E A V E S"+NORM+" a massive "+HIR+"gaping wound"+NORM+
  " in your foe!\n\n");
  return 6; }
return;
}

query_wear() { return 0; }
weapon_breaks() { return 1; }

status id(string str) {
  if(str == "notarmor" && (string)previous_object()->query_type() == "shield")
    return 1;
  return (status)::id(str);
}

status wield(string str) {
  object *inv;
  int x,s;
  if(!id(str))
    return 0;
  if(environment()!=TP)
      return 0;
  if(present("notweapon",this_player())) {
    write("For some reason you are unable to wield this weapon.\n");
    return 1;
  }
  if (wielded) {
    write("You already wield it!\n");
    return 1;
  }
  inv=all_inventory(TP);
  s=sizeof(inv);
  for(x=0;x<s;x++) {
    if((string)inv[x]->query_type() == "shield" && inv[x]->query_worn()) {
      write("You need both hands free for this weapon.\n");
      return 1;
    }
  }
  wielded_by = this_player();
  call_other(this_player(), "wield", this_object(), silentwield);
  wielded = 1;
  return 1;
}
