#include "/players/vertebraker/define.h"
#include "/players/vertebraker/ed/paths.h"
inherit MONSTER;
reset(arg)  {
    ::reset(arg);
    if(arg) return;
    set_name(BOLD+BLK+"EvIL ShELlY"+NORM);
    set_alias("shelly");
    set_alt_name("evil shelly");
    set_race("undead");
    set_short(BOLD+BLK+"EvIL SheLLY"+NORM);
    set_long(
    "This putrid mass of rotten flesh stings your olefactory lobes with the\n"+
    "rush of a stench somewhere between a dead body and a 60 year-old sewage\n"+
    "line.  It is entirely disgusting just to look at - its arms and legs are\n"+
    "much bulkier than in its human form, as the evil force has taken over\n"+
    "its 'body'.\n");
    set_gender("female");
    set_level(16);
    set_ac(10+random(7));
    set_wc(20+random(5));
    set_hp(375+random(50));
    set_al(-40);
    set_chat_chance(9);
    set_a_chat_chance(8);
    set_aggressive(1);
    load_chat(BOLD+BLK+"EviL SheLLY says: '"+NORM+"join us..."+BOLD+BLK+"'\n"+NORM);
    load_chat("The undead creature cackles in bemusement!\n");
    load_chat("The evil zombie cracks its spine.\n");
    load_a_chat("\nThe disgusting creature picks you up and throws you across the room!\n");
    load_a_chat("\nThe zombie stabs you in your ankle with a pencil!\n");
    load_a_chat("The zombie cackles mirthfully!\n");
    load_a_chat(BOLD+BLK+"EviL SHeLLy says: '"+NORM+"why have you disturbed our slumber!"+BOLD+BLK+"'\n"+NORM);
    set_message_hit(({BOLD+BLK+"annihilated"+NORM," with a fury of blows",BOLD+BLK+"mauled"+NORM,
"",BOLD+BLK+"sliced"+NORM," using the power of Con'dar",BOLD+BLK+"crashed into"+NORM,
" - sending itself flying",BOLD+BLK+"slashed"+NORM," with its claws",BOLD+BLK+"smashed"+NORM,
"",BOLD+BLK+"nicked"+NORM,""}));
    enable_commands();
    set_dead_ob(TO);
    }

monster_died() {
    object ob,attacker;
    attacker = TO->query_attack();
    ob = present("corpse",ENV(attacker));
tell_room(ENV(TO->query_attack()),
"\n\nThe creature takes the final hack-n-slash, stumbles backwards and\n"+
RED+"<<<"+NORM+"explodes"+RED+">>>"+NORM+" onto the floor!\n"+
"Finally the finishing blow is laid unto the foul 'beast',\n"+
" splaying its flesh!\n\n");
    ENV(TO)->set_slime();
    destruct(ob);
    return 0; }
