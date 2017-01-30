#include "/players/hogath/tools/def.h"
#include <ansi.h>

inherit "/obj/monster";

object master;

reset(arg) {
    ::reset(arg);
    if (!arg)  {
      

        set_name("Bat");
        set_alt_name("bat");
        set_alias("bat");
        set_short("Small Bat");
        set_race("Mammal");
        set_long("A small furry Brown Bat.\n");
        set_gender("male");
        set_level(1);
        set_ac(6);
        set_wc(12);
        set_hp(50);
        set_al(0);}
        set_a_chat_chance(4);
        load_a_chat("Bat bites"+tpn+"!\n");
        
        
}

heart_beat()
{
     ::heart_beat();
     if (!master  || !attacker_ob  || !random(30))
      {
       say("Bat flies away.\n");
       destruct(this_object());
      }
}

set_master(ob) {master = ob; }

calculate_worth() { return 1; }
