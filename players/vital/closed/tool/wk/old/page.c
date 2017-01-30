#include <ansi.h>

status
main(string str)
{
    object chub;

    if(!str) return 0;
    if(!(chub = find_player(str)))
    {
      notify_fail(capitalize(str) + " isn't on to page.\n");
      return 0;
    }

    write(HIY + "Paging Dr. " + capitalize(str) + "...\n" + NORM);
    tell_object(chub, BEEP + BEEP + BEEP + HIY + (string)
this_player()->query_name() + " is paging you!\n" + NORM);
    return 1;
}
