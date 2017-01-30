#include "/players/vertebraker/define.h"
#include "/players/vertebraker/ed/paths.h"
inherit MONSTER;
reset(arg)  {
    ::reset(arg);
    if(arg) return;
    set_name(BOLD+BLK+"EviL ScoTTy"+NORM);
    set_alias("evil scotty");
    set_alt_name("scotty");
    set_race("undead");
    set_short(BOLD+BLK+"EviL ScOttY"+NORM);
    set_long(
    "The putrid, foul creature before you has yellowish, sickening eyes.\n"+
    "It only has two loves: mayhem and the taste of human flesh.  Scotty's\n"+
    "considerable size make this 'zombie-ized' teenager more powerful than\n"+
    "the rest.  Tiny maggots and other foul vermin crawl in and out of its body\n"+
    "pores just as you gaze at it. \n");
    set_gender("male");
    set_message_hit(({BOLD+BLK+"annihilated"+NORM," with a fury of blows",BOLD+BLK+"mauled"+NORM,
"",BOLD+BLK+"sliced"+NORM," using the power of Con'dar",BOLD+BLK+"crashed into"+NORM,
" - sending itself flying",BOLD+BLK+"slashed"+NORM," with its claws",BOLD+BLK+"smashed"+NORM,
"",BOLD+BLK+"nicked"+NORM,""}));
    set_level(16);
    set_ac(10+random(7));
    set_wc(20+random(5));
    set_hp(375+random(50));
    set_al(-40);
    set_chat_chance(9);
    set_a_chat_chance(8);
    set_aggressive(1);
    load_chat(BOLD+BLK+"EviL Sc0tTy says: '"+NORM+"join us..."+BOLD+BLK+"'\n"+NORM);
    load_chat("The undead creature cackles in bemusement!\n");
    load_chat("The evil zombie cracks its spine.\n");
    load_a_chat("\nThe disgusting creature picks you up and throws you across the room!\n");
    load_a_chat(BOLD+BLK+"EviL Sc0tTy says: '"+NORM+"join us..."+BOLD+BLK+"'\n"+NORM);
    load_a_chat("\nThe zombie stabs you in your ankle with a pencil!\n");
    load_a_chat("The zombie cackles mirthfully!\n");
    load_a_chat(BOLD+BLK+"EviL Sc0TtY says: '"+NORM+"why have you disturbed our slumber!"+BOLD+BLK+"'\n"+NORM);
    set_dead_ob(TO);
    enable_commands();
    }


monster_died() {
    object ob, attacker;
    attacker = TO->query_attack();
    ob = present("corpse",ENV(attacker));
    tell_room(ENV(TO->query_attack()),"\nWith grueling effort and incredible timing, "+(TO->query_attack())->query_name()+" slices and chops "+(TO->query_attack())->query_possessive()+" way through the monster...\n"+
"Eventually the steaming entrails and miscellaneous body pieces seep\n"+
"their way into the floor, leaving an acidic trail and stain\n"+
" on the floor...\n",({TO->query_attack()}));
    write(
"With grueling effort and incredible timing, you chop your way\n"+
" through the monster...\n"+
"Eventually the steaming entrails and miscellaneous body pieces seep\n"+
" through into the floor, leaving an acidic trail and stain...\n");
    ENV(TO)->set_slime();
    destruct(ob);
    return 0; }
