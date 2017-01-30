inherit "/players/mizan/core/monster.c";
#include "/players/mizan/closed/Tracking-D.c"
#include "/players/mizan/closed/NewbieGuard.c"

reset(arg) 
{
    object weapon,treasure;
    ::reset(arg);
    if(arg) return;
    set_name("pogo");
    set_race("tree");
    set_alias("pogo");
    set_short("Pogo the tennis-ball tree");
    set_long("You've seen some strange things today, have'nt you? Good.\n"+
    "You're used to it now. So, when you see this tree with tennis\n"+
    "balls hanging from its branches drifting in front of you, I'd\n"+
    "better not catch you drop your jaw and gawk in disbelief!\n");
    set_level(15);
    set_hp(225);
    set_al(-600);
    set_ac(12);
    set_wc(20);
    set_chance(25);
    set_spell_dam(30);
    set_spell_mess1("Pogo screams loudly!");
    set_spell_mess2("Pogo kicks you.  OUCH!");
    set_chat_chance(10);
    load_chat("Pogo goes: Boing.\n");
    load_chat("Pogo goes: Bah!\n");
    load_chat("Pogo grumbles: I hate Mizan.\n");
    load_chat("Pogo grumbles: I hate Boltar.\n");
    load_chat("Pogo grumbles: I hate Saber.\n");
    load_chat("Pogo grumbles: I hate Pain.\n");
    load_chat("Pogo grumbles: I hate Sandman.\n");
    load_chat("Pogo grumbles: I hate you, too.\n");
    weapon=clone_object("players/mizan/etheriel/items/spuckrifle.c");
    move_object(clone_object("players/mizan/etheriel/items/spuckballs-ext2.c"), weapon);
    move_object(clone_object("players/mizan/etheriel/items/spuckballs-ext2.c"), weapon);
    move_object(weapon, this_object());
    treasure=clone_object("players/mizan/etheriel/items/bk-rollers.c");
    move_object(treasure, this_object());
}
