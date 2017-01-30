/* AUTOLOAD */
query_auto_load() { return "/players/snow/guild/slave.c:"; }
    
/* DROP AND GET */
drop () { return 1; }  /* undroppable */
get() { return 0; }    /* ungettable */
/* WEAPON FUNCTIONS */
weapon_mod() { return arms * 5; }
query_grip_weapon() { return grip_weapon; }
set_grip_weapon(object ob) { grip_weapon = ob; }
