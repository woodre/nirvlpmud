/*
 * QUIT removes registration in channel daemon
 * and saves the guild object.
 */
#pragma strict_types
#include "../def.h"
#include "../std.h"
inherit CMD;

status
main()
{
    if (!((int) this_player()->query_invis()))
      CHANNELD->broadcast(this_player()->query_name() + " leaves the game.\n",
                          0, "{Servants}");
    CHANNELD->deregister(previous_object(), "Servants");
    CHANNELD->deregister(this_player(), ({"[Servants]", "{Servants}",}));
/*
      write_file(LOGDIR + "EXP",
       "[q] "+ctime()[4..15] + " : " + this_player()->query_real_name() +
       " " + this_player()->query_guild_rank() + " " + 
       this_player()->query_level() + "+" + 
       this_player()->query_extra_level() +" " 
       + this_player()->query_exp() + "\n");
*/
    previous_object()->save_me();
    return 0;
}
