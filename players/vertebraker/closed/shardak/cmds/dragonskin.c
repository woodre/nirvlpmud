 /*
 * DRAGONSKIN spell for Shardak guild.
 * (c) Balowski/Rasmus 1996
 * rewritten by verte to support multilevel call,
 * random spellcast and new messages
 */
#pragma strict_types
#include "../def.h"
#include "../std.h"
#include "../macros.h"
inherit CMD;

#define COST 40

status
main(string str)
{
    object      ob;
    int         c;
    if (str) return 0;
    needrank(3);
    if (present("verte_dragon_skin", this_player())) {
        write("You already have dragon skin.\n");
        return 1;
    }

    c = COST + random(20);
    needmana(c);

    if((object)this_player()->query_attack())
    {
      write("All your attention must be devoted to Shardak.\n");
      return 1;
    }

    write("You mutter a few words of incantation and kneel reverently,\n"+
          "praying in dark meditation to the dark lord Shardak.\n");
    say(this_player()->query_name() +
          " mutters a few words of incantation and kneels on the ground,\n"+
          "uttering words of dark meditation.\n");
    move_object(clone_object(OBJDIR +"call_dskin"), this_player());
    this_player()->add_spell_point(-c);
    return 1;
}
