/*
 * GW command for the Shardak guild
 * free guild who
 * by Drag and Bal
 */
#include "../std.h"
#include "../def.h"
#include "../people.h"
#include <security.h>
#include "/players/vertebraker/ansi.h"
inherit CMD;

status
main()
{
    object          *list, player, guild;
    int             i, level, inv, class;
    string          str, name;

    level = (int) this_player()->query_level();
    i = sizeof(list = (object *) CHANNELD->users("[Servants]"));
write(RED +
"\n__________________________________________________________________________\n" + NORM + 
"\n\
NAME:           CLASS:     RANK: MUFFLED: LOCATION:\n\
" + RED +
"__________________________________________________________________________"
+ NORM + "\n\
\n");
    while (i--) {
        str = "";
        if((player = list[i]) && ((guild = present("shardak_mark", player)) || (guild = present("allymark", player))))
        {
            inv = (int) player->query_invis(level);
if ((string)this_player()->query_real_name() == "earwax") 
  name = capitalize((string)player->query_real_name());
else
            name = (inv > 0) ? "A shadow" : (string) player->query_name();
            if (!interactive(player))
                name = "(" + name + ")";
            if ((int) player->query_pl_k() == 1)
              name += "*";
            str += pad(name, 16);

            str += pad((string) guild->ClassName(), 11);

            if ((int) guild->GuildClass() != C_ALLY)
              str += pad("" + (int)player->query_guild_rank(), 4);
            else
              str += pad("--", 4);
            str += (guild->Muffled() ? "  Yes\t  " : "  No\t  ");

            name = 0;
            if ((inv <= 18) && environment(player))
                name = (string) environment(player)->short();
            if (!stringp(name))
                name = "Unknown";
            if (index(name, 27) >= 0) str += name;
            else str += name[0..34];
            if (player->query_invis() < 19 || (string) this_player()->query_real_name() == "earwax")
              write(str + "\n");
        }
    }
write(RED +
"__________________________________________________________________________\n" + NORM);
    return 1;
}

