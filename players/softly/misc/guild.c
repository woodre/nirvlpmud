#include "/players/softly/misc/ansi.h"
mixed id(string str) { return str == "guildthing"; }

string short() { return "guildthing"; }

void init()
{
    add_action("cmdTitle","guild");
}

int drop() { return 1; }

int cmdTitle()
{
    write("Setting guild...\n");
    this_player()->set_guild_name("None");
    write("Okay.\n");
    destruct(this_object());
    return 1;
}
