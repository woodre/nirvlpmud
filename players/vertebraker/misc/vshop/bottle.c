#include "/players/vertebraker/ansi.h"

inherit "/players/vertebraker/closed/std/treasure";

#define huh HIM + "BubbleStuff" + NORM + " [tm]"
#define BUB "/players/vertebraker/misc/vshop/bub_obj"

int dipped;

void
reset(int arg)
{
    if(arg) return;
    set_id("BubbleStuff");
    set_alias("bubblestuff");
    add_id("stuff");
    add_id("bottle");
    add_id("bottle of bubblestuff");
    add_id("wand");
    add_id("green wand");
    add_id("hoop");
    add_id("small hoop");
    add_id("soapy liquid");
    add_id("liquid");
    set_short("A bottle of " + huh);
    set_long("\
A hot pink plastic bottle filled with some sort of soapy\n\
liquid.  A little green wand is inside, with a small hoop\n\
on one end.  You could 'dip' the wand into the bottle\n\
and 'blow' bubbles throughout the air.  A label on the side\n\
reads: " + huh + " by the Verte company.\n");
    set_weight(1);
    set_value(100);
}

void
long(string str)
{
    if(str == "wand" || str == "green wand")
    {
      write("\
A light green wand with a hoop at the end of it, used\n\
for blowing bubbles.\n");
      return;
    }
    else if(str == "hoop" || str == "small hoop")
    {
      write("\
A small hoop at the end of the wand, through which you\n\
can blow some bubbles.\n");
      return;
    }
    else if(str == "soapy liquid" || str == "liquid")
    {
      write("\
Some sort of soapy liquid within the " + huh + ".\n");
      return;
    }
    else ::long(str);
}

void
init()
{
    ::init();
    add_action("cmd_dip", "dip");
    add_action("cmd_blow", "blow");
}

status
cmd_dip(string str)
{
    object x;

    if(!str)
    {
      notify_fail("Dip what?\n");
      return 0;
    }
    if(id(str))
    {
      write("You dip the little green wand into the " + huh + ".\n");
      say((string)(x = this_player())->query_name() + " \
dips " + possessive(x) + " wand into the " + huh + ".\n");
      if(dipped < 5) dipped ++;
      return 1;
    }
    notify_fail("Dip what?\n");
    return 0;
}

void
create_bubs(int bubbles)
{
    string msg;

    while(bubbles --)
    {
      switch(random(7))
      {
        case 0:
          msg = "\
A beautiful multi-coloured bubble emerges...\n";
          break;
        case 1:
          msg = "\
Parades of bubbles leap from the magic wand...\n";
          break;
        case 2:
          msg = "\
A number of bubbles spiral off into the room...\n";
          break;
        case 3:
          msg = "\
Bubbles form from the very air around you...\n";
          break;
        case 4:
          msg = "\
Bubbles float around you...\n";
          break;
        case 5:
          msg = "\
Many bubbles leap from " + (string)this_player()->query_name() + "'s \
wand...\n";
          break;
        case 6:
          msg = "\
Bubbles swarm and pop all around you...\n";
          break;
      }
      if(0 == random(2)) tell_room(environment(this_player()), msg);
      if(random(4) && !present("bubble 23", environment(this_player())))

        move_object(clone_object(BUB), environment(this_player()));
   }
}
       

status
cmd_blow(string str)
{
    int bubs;
    object x;

    if(!str)
    {
      notify_fail("Blow what?\n");
      return 0;
    }
    if(id(str) || str == "bubble" || str == "bubbles")
    {
      x = this_player();
      if(!dipped)
      {
        write("\
You try blowing some bubbles out of the green wand, but\n\
only cool air rushes through the opening.\n");
        say((string)x->query_name() + " blows through a wand.\n");
        return 1;
      }
      write("\
You take a deep breath... and blow gently through the wet,\n\
green wand....\n");
      say((string)this_player()->query_name() + " \
takes a deep breath and blows through a wand...\n");
      bubs = (random(dipped) + random(4) + random(4));
      dipped = 0;
      create_bubs(bubs);
      return 1;
    }
}
