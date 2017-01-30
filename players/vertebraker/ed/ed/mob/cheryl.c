#include "/players/vertebraker/define.h"
#include "/players/vertebraker/ed/paths.h"
inherit MONSTER;
reset(arg)  {
    ::reset(arg);
    if(arg) return;
    set_name("cheryl");
    set_alias("kid");
    set_alt_name("girl");
    set_race("human");
    set_short("An attractive girl");
    set_long(
    "Artistic Cheryl is the loner of the group.  She is also the youngest,\n"+
    "which means she isn't really paid attention to by the other kids,\n"+
    "except her brother, Ash.  She goes to Michigan State as well, but\n"+
    "isn't wearing the same get-up as Linda.  Her favorite thing to do is\n"+
    "to draw, and she is quite good at it.  She is also the most naive\n"+
    "and frail of the group.\n");
    set_gender("female");
    set_level(16);
    set_ac(10+random(7));
    set_wc(20+random(5));
    set_hp(375+random(50));
    set_al(20);
    set_chat_chance(9);
    set_a_chat_chance(8);
    load_chat("Cheryl says: Jack of diamonds...\n");
    load_chat("Cheryl says: Jack of spades...\n");
    load_chat("Cheryl says: Queen of hearts...\n");
    load_chat("Cheryl says: Six of clubs...\n");
    enable_commands();
    }

heart_beat() {
object attacker;
    attacker = TO->query_attack();
    ::heart_beat();
    if(attacker) {
tell_room(ENV(TO),
HIR+"\n\nCheryl screams wildly and whirls around, her face exploding into\n"+
" a disgusting, corpse-like form!\n\n"+NORM);
    destruct(TO);
    MOCO(ED1MOB+"evil_cheryl"),ENV(attacker));
        return 1; } }
