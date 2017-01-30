inherit "/players/mizan/core/monster.c";
#include "/players/mizan/closed/Tracking-D.c"

object weapon, heal, item;

reset(arg) 
{
    int n;
    set_heart_beat(1);
    ::reset(arg);
    if(!arg) 
    {
        set_ep(820039);
        set_name("suvrat");
        set_short("Suvrat the Confused");
        set_long("Suvrat appears to be some sort of laboratory technician.\n"+
                 "He appears to have been recently fired as well. Approach with care.\n");
        set_level(17);
        set_hp(450);
        set_ac(14);
        set_wc(23);
        set_chat_chance(12);
        load_chat("Suvrat picks his nose.\n");
        load_chat("Suvrat eats some boogers.\n");
        set_chance(20);
        set_spell_dam(25);
        set_spell_mess1("Suvrat kicks you in the shins!\n");
        set_spell_mess2("Suvrat screams: What the hell is the wrong with the you?!\n");
        weapon=clone_object("players/mizan/etheriel/items/busted-belt-sander.c");
        move_object(weapon, this_object());
        heal = clone_object("players/mizan/etheriel/items/rotten-sausage.c");
        move_object(heal, this_object());
        item = clone_object("players/mizan/etheriel/items/water-balloon.c");
        move_object(item, this_object());
    }
}
