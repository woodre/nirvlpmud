#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
#define master "/players/anshar/wep/wepmaster.c"
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
         master->m_attack();
         return 0;
}

query_save_flag()  { return 1; }

