#include "/players/vertebraker/define.h"
#include "/players/vertebraker/ed/paths.h"
inherit MONSTER;
reset(arg)  {
    ::reset(arg);
    if(arg) return;
    set_name(BOLD+BLK+"EViL ChERyL"+NORM);
    set_alias("cheryl");
    set_alt_name("evil cheryl");
    set_race("undead");
    set_short(BOLD+BLK+"EViL ChERyL"+NORM);
    set_long(
    "The _dead_ version of Cheryl is a horrifying combination of a fat albino\n"+
    "man and a psychotic zombie from any George Romero movie.  He/she/it has\n"+
    "glowing, beady red eyes like the rest that seem to penetrate your soul.\n"+
    "Looking at this monstrosity makes you yearn for the original Cheryl.\n");
    set_gender("female");
    set_level(16);
    set_ac(10+random(7));
    set_wc(20+random(5));
    set_hp(375+random(50));
    set_al(-40);
    set_chat_chance(9);
    set_a_chat_chance(8);
    set_message_hit(({BOLD+BLK+"annihilated"+NORM," with a fury of blows",BOLD+BLK+"mauled"+NORM,
"",BOLD+BLK+"sliced"+NORM," using the power of Con'dar",BOLD+BLK+"crashed into"+NORM,
" - sending itself flying",BOLD+BLK+"slashed"+NORM," with its claws",BOLD+BLK+"smashed"+NORM,
"",BOLD+BLK+"nicked"+NORM,""}));
    set_aggressive(1);
    load_chat(BOLD+BLK+"EviL ChERyL says: '"+NORM+"join us..."+BOLD+BLK+"'\n"+NORM);
    load_chat("The undead creature cackles in bemusement!\n");
    load_chat("The evil zombie cracks its spine.\n");
    load_a_chat("\nThe disgusting creature picks you up and throws you across the room!\n");
    load_chat(BOLD+BLK+"EviL ChERyL says: '"+NORM+"join us..."+BOLD+BLK+"'\n"+NORM);
    load_a_chat("\nThe zombie stabs you in your ankle with a pencil!\n");
    load_a_chat("The zombie cackles mirthfully!\n");
    load_a_chat(BOLD+BLK+"EviL ChERyL says: '"+NORM+"why have you disturbed our slumber!"+BOLD+BLK+"'\n"+NORM);
    enable_commands();
    set_dead_ob(TO);
    }

monster_died() {
    object ob,attacker;
    attacker = TO->query_attack();
    ob = present("corpse",ENV(attacker));
  tell_room(ENV(TO),
"\nThe creature is hacked 'n slashed to pieces..... At the last\n"+
" moment, the finishing blow is laid unto the foul creature,\n"+
" splaying its gruesome flesh!\n");
    ENV(TO)->set_slime();
    destruct(ob);
    return 0; }
