#include <ansi.h>

string
short()
{
    return HIR + "Ame" + HIW + "ri" + HIB + "can" + NORM + " Flag";
}

id(str) { return str == "american flag" || str == "flag" || str == "the flag"; }

long()
{
   write("The old stars and stripes.\nYou can 'wave' it or 'burn' it, depending on your views.\n");
}


wave(str)
{
    if(id(str))
    {
      write("You wave the " + short() + ".\n");
      say((string)this_player()->query_name() + " waves the " + short() + ".\n");
      return 1;
    }
    return (notify_fail("You may wave the flag.\n"), 0);
}

burn(str)
{
    if(id(str))
    {
      write("You burn the " + short() + ".\n");
      say((string)this_player()->query_name() + " burn the " + short() + ".\n");
      destruct(this_object());
      return 1;
    }
    return (notify_fail("You may burn the flag.\n"), 0);
}

drop() { return 1; }

init() { add_action("wave", "wave"); add_action("burn", "burn"); }
