#include "/players/anshar/closed/ansi.h"
#include "/players/anshar/closed/mydef.h"
#define BURY "/open/anshar/bury.c"
#define MATTACK "/open/anshar/wepatk.c"
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("weapon");
    set_alt_name("sword");
    set_alias("test");
    set_short(BLU+"TEST"+NORM);
    set_long("     A test weapon.\n");
    set_class(16);
    set_weight(4);
    set_value(0);
    set_hit_func(this_object());
}
weapon_hit(attacker){
   set_hits(1);
   set_misses(1);
   extra_attacks();
   return 0;
}

query_save_flag()  { return 1; }

init() {
  ::init();
  add_action("bury_corpse","bury");
}

bury_corpse(str) { BURY->bury(str); return 1; }
extra_attacks() { MATTACK->m_attack(); return 0; }
id(str) { return str=="legion_weapon" || str=="weapon" ; }
