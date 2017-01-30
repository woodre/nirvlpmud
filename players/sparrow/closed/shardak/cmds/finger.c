/*
 * Guild Finger
 */
#pragma strict_types
#include "../people.h"
#include "../def.h"
#include "../std.h"
inherit CMD;

int guild_rank;
int guild_class, frozen;

static string
ClassName(int class)
{
    return classtostr(class);
}

status
main(string arg)
{
    if(arg && lower_case(arg) == "shardak")
    {
      write("~~\n~~ Your Master\n~~\n");
   }
    else
    if (arg && restore_object(SAVE_PATH + arg) &&
               restore_object("pfiles/" + arg[0..0] + "/" + arg)) {
        write("~~\n");
        write("~~ " + capitalize(arg) + " the Servant of Shardak,\n");
        write("~~ " + pad("", strlen(arg) + 1) +
                      call_other(PATH + "advance",
                                 "get_next_title", guild_rank) + ",\n");
        write("~~ " + pad("", strlen(arg) + 1) +
                      "the " + ClassName(guild_class) + "\n");
        if (frozen)
            write("**  Frozen\n");
        write("~~\n");
    }
    return 0;
}
