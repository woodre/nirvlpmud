#include "/players/vertebraker/ansi.h"

string dest;

void
reset(int arg)
{
    if(arg) return;
    call_out("close_me", 240);
}

string
short()
{
    return "A " + GRN + "green" + NORM + " portal";
}

status
get()
{
    return 0;
}

status
id(string str)
{
    return str == "green portal" || str == "portal" ||
           str == "the green portal" || str == "the portal" ||
           str == "green_portal"; }

void
init()
{
    add_action("cmd_enter", "enter");
    add_action("cmd_in", "in");
    add_action("cmd_step", "step");
}

status
cmd_in()
{
    command("enter green portal", this_player());
    return 1;
}

status
cmd_step(string str)
{
    string c, h;

    if(!str) return 0;

    if(id(str) || (sscanf(str, "into %s", c) && id(c)) ||
       (sscanf(str, "in %s", c) && id(c)))
    {
       command("enter green portal", this_player());
       return 1;
    }

    return 0;
}
      

status
cmd_enter(string str)
{
    if(!str) return 0;

    if(id(str))
    {
      if(!dest)
      {
        write("You dare not enter that portal...\n");
        return 1;
      }
      write("\n\
You enter the green portal...\n\n\n\
\t\tYou are somewhere else.\n\n");
      this_player()->move_player(GRN + "through the green portal" +
       NORM + "#" + dest);
      return 1;
    }
    return 0;
}

void
set_dest(string d)
{
   dest = d;
}

void
long()
{
    return write("A mysterious " + GRN + "green" + NORM + " portal.\nYou are not sure where it leads.\n");
}


void
close_me()
{
    object x;
    if(x = environment())
      tell_room(x, "The " + GRN + "green" + NORM + " portal closes.\n");
    destruct(this_object());
}

status
query_save_flag()
{
    return 1;
}
