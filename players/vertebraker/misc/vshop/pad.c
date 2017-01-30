/* paddleball for the mothafuckin two thousand
    verte[2001] */


#include "/players/vertebraker/ansi.h"

inherit "/obj/treasure";

int m;

string dir;

void stop_paddling();

void
reset(int arg)
{
    if(arg) return;
    set_id("paddleball");
    set_short("A paddleball");
    dir = "up";
    set_weight(1);
    set_value(100);
    set_long("\
A thin wooden paddle, with a twelve-inch long elastic\n\
cord hanging from the middle of it.  On the end of\n\
the cord is a small, red rubber ball.\n");
}

string
short()
{
    return short_desc + (m ? (BOLD + " (paddling)" + NORM) : "");
}

void
long()
{
    ::long();

    if(m)
      write(BOLD + "\tThe ball is in motion.\n" + NORM +
            "You may 'stop' it at any time.\n");
    else
      write("You may 'paddle' away at your heart's desire.\n");
}

void
init()
{
    if(environment() && !living(environment()))
      stop_paddling();

    ::init();
    add_action("cmd_paddle", "paddle");
    add_action("cmd_stop", "stop");
}

void
stop_paddling()
{
    object User, Env;

    if((User = environment()) && User &&
       (Env = environment(User)) && Env && living(User))
    {
      tell_room(Env, (string)User->query_name() + " \
stops paddling " + possessive(User) + " paddleball.\n", ({ User }));
      tell_object(User, "\
You stop paddling the paddleball.\n");
    }

    while(remove_call_out("event_pad") != -1);

    m = 0;
}

mixed
drop()
{
    if(m && environment())
      stop_paddling();

    return 0;
}

status
cmd_paddle()
{
    if(m || this_player() != environment()) return 0;

    write("\t\
You whack the ball high into the air...\n");

    say((string)this_player()->query_name() + " \
whacks the little rubber ball high into the air...\n");

    call_out("event_pad", 3);

    m = 1;
    return 1;
}

status
cmd_stop()
{
    if(!m || this_player() != environment()) return 0;
    write("\
You stop bouncing the ball and catch it against\n\
the side of your paddle.\n");
    say((string)this_player()->query_name() + " \
stops bouncing the ball and catches it against the\n\
side of " + possessive(this_player()) + " paddle.\n");

    stop_paddling();
    return 1;
}

string get_msg(string type)
{
    string x;

    if(type == "stretch")
      switch(random(8))
      {
        case 0: 
          x = "\
The elastic stretches as the ball flies " + dir + "...\n";
          break;
        case 1:
          x = "\
The ball yanks to the end of the cord and falls back...\n";
          break;
        case 2:
          x = "\
The rubber ball hurls to the furthest extremity...\n\
It cuts back towards the paddle...\n";
          break;
        case 3:
          x = "\
The small ball pulls tight on the elastic cord.\n";
          break;
        case 4:
          x = "\
Hurling in a completely linear path " + dir + ", \n\
the ball suddenly yanks back towards the paddle...\n";
          break;
        case 5:
          x = "\
The elastic cord throws the ball back towards\n\
the paddle...\n";
          break;
        case 6:
          x = "\
The ball cleaves through the air, and at the last moment,\n" + BOLD + "\
zips" + NORM + " back towards the paddle.\n";
          break;
        case 7:
          x = "\
The small red ball reaches the elastic limit heading " + dir + "\n\
and hurtles back towards the wooden paddle.\n";
          break;
      }
    else if(type == "smack")
      switch(random(6))
      {
        case 0:
          x = "\
Paddle and ball connect in a flurry of brown and red.\n";
          break;
        case 1:
          x = "\
The ball smacks off the balsa-like paddle.\n";
          break;
        case 2:
          x = "\
The red rubber ball bounces into the wooden paddle.\n";
          break;
        case 3:
          x = "\
Bounding away, the ball meets smack into the middle\n\
of the paddle.\n";
          break;
        case 4:
          x = "\
The cord becomes loose and the oncoming ball thuds\n\
into the stationary paddle.\n";
          break;
        case 5:
          x = "\
The ball glances off a fierce paddle strike...\n";
          break;
      }

else
  switch(random(4))
  {
    case 0: x = "\
The ball yanks just out of reach.\n";
      break;
    case 1: x = "\
You fail to catch the ball with the paddle\n\
return.. ending the game immediately.\n";
      break;
    case 2: x = "\
Your corkylike skills bring the game crashing\n\
to a complete and utter halt.\n";
      break;
    case 3: x = "\
You whiff and miss with the paddle.  What a joke.\n";
      break;
  }
    return x;
}

status
okay_swat(object ob)
{
    if((int)ob->query_attrib("ste") < random(22))
      return 0;

    else
      if((int)ob->query_attrib("luc") < random(22))
        return 0;

    else 
      return 1;
}

void
event_pad()
{
    object User, EnvOb;
    string smsg, bmsg, gmsg, Uname;

    User = environment();

    if(!User || !living(User))
    {
      stop_paddling();
      return;
    }

    EnvOb = environment(User);

    if(!EnvOb)
    {
      stop_paddling();
      return;
    }

    smsg = get_msg("stretch");
    tell_object(User, smsg);
    
    Uname = (string)User->query_name();
  
    if(okay_swat(User))
    {
      bmsg = get_msg("smack");
      tell_object(User, bmsg);
      tell_room(EnvOb, Uname + " \
swats the ball with " + possessive(User) + " paddle.\n", ({ User }));
      if(0 == random(3))
      {
        switch(random(4))
        {
          case 0: dir = "left"; break;
          case 1: dir = "up"; break;
          case 2: dir = "down"; break;
          case 3: dir = "right"; break;
        }
        tell_object(User, BOLD + "\t\
The ball bounces " + dir + "...\n" + NORM);
        tell_room(EnvOb, "\
The ball leaps " + dir + "...\n", ({ User }));

      }
    }

    else
    {
      gmsg = get_msg("fumble");
      tell_object(User, gmsg);
      tell_room(EnvOb, Uname + " \
moves too slowly and the game crashes to a halt.\n", ({ User }));
      stop_paddling();
      return;
    }
         
    call_out("event_pad", 3);
}


