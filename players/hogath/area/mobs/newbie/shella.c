/******************/
/* Monster        */
/* Hogath         */
/* cc 2004        */ 
/**************** */

#include <ansi.h>

inherit "/obj/monster";

reset(arg) {
    ::reset(arg);
    if (!arg)  {
      object weapon;
       
       
        set_name("Shella");
        set_alt_name("shella");
        set_alias("shella");
        set_short("Shella");
        set_race("gnome");
        set_long(
"This is Shella, the lady of the house.  She is wearing a\n"+
"bright floral pattern dress, and is rolling out a large slab\n"+
"of pie dough.\n");
        set_gender("female");
        set_level(8);
        set_ac(8);
        set_wc(10);
        set_hp(120);
        set_al(0);}
        move_object(clone_object("/players/hogath/area/items/rpin.c"));
        init_command("wield weapon");
        set_chat_chance(5);
        load_chat("Shella hums.\n");
        load_chat("Shella grunts as she rolls out a slab of dough.\n");
}

