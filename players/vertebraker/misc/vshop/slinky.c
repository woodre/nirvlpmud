#include "../../ansi.h"

inherit "/players/vertebraker/closed/std/treasure";

void
reset(int arg)
{
    string colour;

    if(arg) return;
    switch(random(4))
    {
      case 0: colour = HIM; break;
      case 1: colour = HIG; break;
      case 2: colour = BOLD; break;
      case 3: colour = HIB; break;
    }
    set_id("slinky toy");
    set_alias("toy");
    add_id("slinky");
    set_short(colour + "slinky" + NORM + " toy");
    set_long("\
A " + colour + "colourful" + NORM + " slinky toy.  \
It is a long curled piece of\n\
plastic coiled many times.  At full length, it is\n\
about eight feet long, but while coiled, it is only\n\
about five inches high.  It is quite a neat toy.\n");
    set_weight(1);
    set_value(50);
}

void
random_move()
{
    environment()->init();
    if(0 == random(3)) command("north");
    if(0 == random(3)) command("south");
    if(0 == random(3)) command("west");
    command("east");
}

void
long()
{
    object x, e;

    ::long();

    if(!(x = this_player()) || !(e = environment())) 
      return;

    if(e == x)
      write("You can place the slinky on the ground and 'walk' it.\n");
    else if(e == environment(x))
      write("You can 'walk' the slinky.\n");
}
     

void
init()
{
    ::init();
    add_action("cmd_walk", "walk");
    add_action("cmd_walk", "flip");
}

void
strut()
{
    int i, s;
    object e, room;
    string *dd, what;

    dd = (string *)(e = environment())->query_dest_dir();

    if(!dd) { random_move(); return; }

    s = sizeof(dd);

    for(i = 0; i < s; i += 2)
    {
      if(!random(2) || ((i + 2) == s))
      {
        switch(random(6))
        {
          case 0: what = "flips"; break;
          case 1: what = "hops"; break;
          case 2: what = "bounces"; break;
          case 3: what = "slinks"; break;
          case 4: what = "sproings"; break;
          case 5: what = "boings"; break;
        }
        tell_room(e, short() + " " + what + " " + dd[i + 1] + ".\n");
        if(!(room = find_object(dd[i])))
        {
          dd[i]->load_me();
          room = find_object(dd[i]);
        }
        move_object(this_object(), room);
        tell_room(room, short() + " " + what + " in.\n");
        if(0 == random(3)) strut();
        return;
      }
    }
}

void
print_msg()
{
    string x;
    switch(random(4))
    {
      case 0: x = short() + " slinks along...\n";
              break;
      case 1: x = short() + " bounces along in a path.\n";
              break;
      case 2: x = short() + " leaps over each side of itself.\n";
              break;
      case 3: x = short() + " 'walks' around for a few steps.\n";
              break;
    }
    tell_room(environment(), x);
}

status
cmd_walk(string str)
{
    if(!str || !id(str))
    {
      notify_fail("Walk what?\n");
      return 0;
    }
    
    if(environment() == this_player())
    {
      notify_fail("You must place it upon the ground first.\n");
      return 0;
    }

    write("You walk the " + short() + " and flip it end over end.\n");
    say((string)this_player()->query_name() + " flips the " +
    short() + " end over end.\n");
    print_msg();
    strut();
    return 1;
}

