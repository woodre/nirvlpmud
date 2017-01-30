inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>
object stalk;


reset(arg)
{
        ::reset(arg);
        if(arg) return;
        set_name("monkey");
        set_alt_name("shinshi_monkey");
        set_race("monkey");
        set_alias("annoying monkey");
        set_short(HIK+"A rather annoying monkey"+NORM);
        set_long("This little tiny monkey is getting on your fucking nerves.\n");
        set_level(1);
        set_hp(1);
        set_ac(1);
        set_wc(1);
        set_al(-1);
        set_chat_chance(2);
        load_chat("The monkey jumps up and down on your head!\n");
        load_chat("The monkey sniffs your ass.\n");
}