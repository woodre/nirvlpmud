/*
 * Shatter spell for Shardak guild
 * Destroys shadow cast with 'darkness'
 * updated by verte w/ cost + msg
 */
#pragma strict_types
#include "../std.h"
#include "../def.h"
#include "../macros.h"
#include "/players/vertebraker/ansi.h"
#define COST 100

inherit CMD;

status
main()
{
    object          it;

    needrank(6);
    needmana(COST);
    it = (object) environment(this_player())->shardak_darkness(0);
    if (!it) {
	write("Darkness does not envelop this place.\n");
	return 1;
    }
    write("You growl softly, and a furious echo forms...\n\n");
    say(this_player()->query_name()+" growls softly, and a furious echo forms...\n\n");
    tell_room(environment(this_player()),
       BOLD+"\t      R     O     A      R\n\n"+NORM+
            "The darkness surrounding the room shatters!\n");
    destruct(it);
    this_player()->add_spell_point(-COST);
    return 1;
}
