#include "/players/vertebraker/define.h"
#include "/players/vertebraker/ed/paths.h"
inherit MONSTER;
reset(arg)  {
    ::reset(arg);
    if(arg) return;
    set_name("linda");
    set_alias("kid");
    set_alt_name("brunette");
    set_race("human");
    set_short("A pretty brunette");
    set_long(
    "Cheery and beautiful, Linda is the girlfriend of Ash.  She is wearing\n"+
    "a grey Michigan State sweatshirt (the alma mater of the students), and\n"+
    "a pair of brown slacks.  Upon her neck is a silver necklace given to her\n"+
    "by Ash as a present.  She seems quite comfortable despite the threat\n"+
    "posed by the dark and dangerous woods.\n");
    if(!present("pendant",TO)) MOCO(ED1OBJ+"linda_pendant"),TO);
    set_gender("female");
    set_level(16);
    set_ac(10+random(7));
    set_wc(20+random(5));
    set_hp(375+random(50));
    set_al(20);
    set_chat_chance(9);
    set_a_chat_chance(8);
    load_chat("Linda says: Where's Ashley?\n");
    load_chat("Linda smiles.\n");
    load_chat("Linda strokes her pendant.\n");
    load_chat("Linda says: It's so beautiful...\n");
    load_chat("Linda says: I don't really buy into that 'zombie' nonsense...\n");
    load_a_chat("Linda screams!\n");
    enable_commands();
    }

heart_beat() {
object attacker;
    attacker = TO->query_attack();
    ::heart_beat();
    if(attacker) {
tell_room(ENV(TO),
    "\nLinda sits down on the floor and her face fills with a sadistic grin!\n"+
    "           Suddenly, her face breaks out into black hives!\n"+
    BOLD+BLK+"           '"+NORM+" Help me Ashley! "+BOLD+BLK+"'"+NORM+" she pleads....\n");
    destruct(TO);
    MOCO(ED1MOB+"evil_linda"),ENV(attacker));
        return 1; } }
