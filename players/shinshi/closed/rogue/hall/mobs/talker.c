inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
        ::reset(arg);
        if(arg) return;

        set_alt_name("driver");
        set_race("rogue");
        set_alias("shinshi_rogue_talker");
        set_long("\
		This is not necessary. Not a real mob.\n");
        set_level(100);
        set_hp(99999);
        set_ac(99999);
        set_wc(99999);
        set_al(0);
        set_chat_chance(5);
        load_chat("A fellow Rogue says, \"HAH! You should've seen his face when I stabbed him in the back!\n");
        load_chat("A fellow Rogue laughs with members of the Brotherhood over a recent victory.\n");
        load_chat("\"What the hell do you mean you can defeat me in a duel?\"\n");
        load_chat("A fight between Rogues breaks out!\n");
        load_chat("A dead body is pulled from the pub.\n");
        
}