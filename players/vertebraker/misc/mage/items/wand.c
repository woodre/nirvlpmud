#include "/players/vertebraker/ansi.h"
#define PORTAL "/players/vertebraker/misc/mage/items/portal"

inherit "/players/vertebraker/closed/std/treasure";

int ch;

void
reset(int arg)
{
    if(arg) return;
    ch = 3;
    set_id("wand");
    set_alias("wand of portals");
    set_long("\
A long green cylindrical wand, about two inches in diameter\n\
and eighteen inches in length.  There is a small inscription\n\
on the side facing you.\n");
}

void
long()
{
    ::long();
    write("\tThere are " + ch + " charges remaining.\n");
}

string
short()
{
    return(GRN + "A wand of portals (" + NORM + ch + GRN + ")" + NORM);
}

status
query_save_flag()
{
    return 1;
}

int
query_value()
{
    return (250 * ch);
}

void
init()
{
    ::init();
    add_action("cmd_read", "read");
    add_action("cmd_invoke", "invoke");
}

status
cmd_read(string str)
{
    if(!str) return 0;

    if(id(str) || str == "inscription" || str == "the inscription")
    {
      write("You squint at the inscription.\n\n" + GRN + "\
  The green dimensional gate to the green;\n\
  Power to become, you need only to invoke me.\n\n" + NORM);
      return 1;
    }
}

status
cmd_invoke(string str)
{
    object green, x, e, portal;
    if(!str) return 0;

    if(id(str) && (environment() == (x = this_player())))
    {
      write("You invoke the wand of portals.\n");
      say((string)x->query_name() + " invokes the wand of portals.\n");
      if((string)(e = environment(x))->realm() == "NT")
      {
        write("Nothing happens.\n");
        return 1;
      }

      green = find_object("/room/vill_green");

      if(!green)
      {
        "/room/vill_green"->load_me();
        green = find_object("/room/vill_green");
      }
      if(e == green)
      {
        notify_fail("You realize where you are and mutter in frustration.\n");
        return 0;
      }
      if(!present("green_portal", green))
      {
        portal = clone_object(PORTAL);
        portal->set_dest(file_name(e));
        move_object(portal, green);
        tell_room(green, "\
A " + GRN + "green" + NORM + " portal suddenly opens.\n");
        write("\
In the distance, you see a " + GRN + "green" + NORM + " portal open.\n");
      }
      if(!present("green_portal"), e)
      {
        tell_room(e, "A " + GRN + "green" + NORM + " portal \
suddenly opens.\n");
        portal = clone_object(PORTAL);
        portal->set_dest("/room/vill_green");
        move_object(portal, e);
      }

      ch--;
        
      if(!ch)
      {
        write("\
As you wave the magical wand, it flickers and fades away\n\
from your very grasp.\n");
        this_player()->add_weight(-1);
        destruct(this_object());
      }
      
      return 1;
    }
}
