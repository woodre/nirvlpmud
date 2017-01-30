#include <ansi.h>

inherit "/obj/treasure";

void reset(status arg)
{
  if(arg) return;
  set_id("can of peanuts");
  set_alias("peanuts");
  SetMultipleIds(({"can","nuts","can of nuts","verteJokeCan"}));
  set_weight(1);
  set_short("A tasty-looking can of peanuts");
  set_long("\
Mmm. Delicious peanuts!\n\
Open the can and have a few!\n");
}

void init()
{
  ::init();
  add_action("cmd_open", "open");
  add_action("cmd_kick", "kick");
}

int cmd_kick(string str)
{
  if(str && id(str))
  {
    write("You kick the can around.\n");
    say((string)this_player()->query_name()+" kicks "+short()+" around.\n");
    if((int)this_player()->query_attrib("dex") > random(50))
    {
      write("You punt the can onto your head and bounce it on your skull thrice,\n"+
            "then gracefully let it slip back onto the top of your foot, flipping it\n"+
            "before you side-slap it to your other foot.\n");
      say((string)this_player()->query_name()+" gets jiggy wit it.\n");
    }
    return 1;
  }
}

int cmd_open(string str)
{
  if(str && id(str))
  {
    tell_room(environment(this_player()),
      "\n\n\n\n\n\t\t\tPOP!\n\n\n\n");
    tell_room(environment(this_player()),
      HIG+"A GREEN SNAKE LEAPS AT ");
    write("YOU ");
    tell_room(environment(this_player()),
      upper_case((string)this_player()->query_real_name())+" ", 
      ({ this_player() }));
    tell_room(environment(this_player()),
      "FROM THE CAN!!!\n\n\n"+NORM);
    if((int)this_player()->query_attrib("int") > random(40))
      write("It was just a joke.\n");
    else
    {
      if(environment() == this_player())
        command("drop verteJokeCan", this_player());
      write("You flee in terror!\n");
      say((string)this_player()->query_name()+" flees in terror!\n");
      this_player()->run_away();
      while((int)this_player()->query_attrib("wil") < random(40))
      {
        write("You've got the willies!\n");
        say((string)this_player()->query_name()+" is all FREAKED out!\n");
        this_player()->run_away();
      }
    }
    return 1;
  }
}
