/* Can be found in /players/jaraxle/3rd/pyramid/rooms/torch_room.c
   Guarded by a trap, and it can be found only once per reboot   */

#include <ansi.h>

inherit "obj/treasure";
reset(arg) {
  if(arg) return;

set_id("key_sphere8");
set_alias("sphere");
set_short(CYN+"Key Sphere "+NORM+"("+HIC+"Water"+NORM+")");
set_long("A perfectly formed sphere of crystal, this appears to be a\n"+
         "gemstone that has been naturally formed and changed by magic.\n"+
         "Within the sphere, "+HIC+"Ocean Water"+NORM+" swirls about.\n");
set_weight(1);
set_value(10000+random(5000));
}

query_save_flag() {return 1; }

