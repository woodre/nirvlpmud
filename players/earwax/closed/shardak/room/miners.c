inherit "/obj/monster";
#include "../include/ansi.h"

void reset(int arg) {
    ::reset(arg);
    if (arg) return;
    set_name("miners");
    set_short("Some miners are digging in the western wall");
    set_long("\
The miners are no more than a couple of feet tall and very human-\n\
like in shape, except for the fact that their forearms seem quite\n\
similar to pickaxes -- both in shape and in action, and they are\n\
being put to good use at the moment. The miners have upper bodies\n\
that look like they were carved in stone.\n");
    load_chats(({
	"The miners hack vigorously away at the rock wall.\n" +
	"A low passage in the western wall is taking shape.\n",
	"One miner obliterates a piece of rock that was cut loose.\n",
	"Suddenly one of the miners seems to go berserk; It hacks like\n" +
	"mad at the rock sending chips of rock flying in every direction.\n",
    }));
    set_chat_chance(20);
    set_level(10); set_hp(150); set_wc(14); set_ac(8);
}
