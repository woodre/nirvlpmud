#include "/players/vertebraker/ansi.h"

int life;

void
reset(int arg)
{
    if(arg) return;
    life = 6 + random(20);
    call_out("hova", 1);
}

status
get()
{
    write("As you touch the bubble, it pops!\n");
    destruct(this_object());
    return 0; 
}

status
id(string str)
{
    return str == "bubble";
}

string
str_colour(string a)
{
    int i, s;
    string heh, c, z;

    heh = "";
    s = strlen(a);

    for(i = 0; i < s; i ++)
    {
      if(((z = a[i..i]) != " ") && (0 == random(3)))
      {
        switch(random(4))
        {
          case 0: c = HIG; break;
          case 1: c = HIM; break;
          case 2: c = HIR; break;
          case 3: c = HIC; break;
        }
        heh += (c + z + NORM);
      }
      else heh += z;
    }

    return heh;
}


string
short()
{
    string a, b;
    switch(random(7))
    {
      case 0: a = "a colorful bubble"; break;
      case 1: a = "a shiny bubble"; break;
      case 2: a = "a dual bubble"; break;
      case 3: a = "a big bubble"; break;
      case 4: a = "a mini bubble"; break;
      case 5: a = "a pretty bubble"; break;
      case 6: a = "a slimy bubble"; break;
    }
    switch(random(4))
    {
      case 0: b = "bouncing"; break;
      case 1: b = "flying"; break;
      case 2: b = "floating"; break;
      case 3: b = "hovering"; break;
    }
    return (str_colour(a) + " (" + str_colour(b) + ")");
}

void
long()
{
    write("\
A multi-coloured bubble formed from some kind of liquid...\n");
}

void
random_move()
{
    string d;

    switch(random(4))
    {
      case 0: d = "north"; break;
      case 1: d = "south"; break;
      case 2: d = "east"; break;
      case 3: d = "west"; break;
    }

    command(d, this_object());
}

void
hova()
{
    object x;

    if(!(x = environment()))
    {
      destruct(this_object());
      return;
    }

    if(0 == random(3)) random_move();
    if(0 == random(10))
      tell_room(x, "A bubble bounces around...\n");
    life --;
    if(!life)
    {
      if(0 == random(8))
        tell_room(x, "A bubble pops!\n");
      destruct(this_object());
      return;
    }
    call_out("hova", 1);
}
