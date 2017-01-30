#include "/players/vertebraker/ansi.h"

inherit "/players/vertebraker/closed/std/weapon";

void
reset(status arg)
{
    if(arg) return;
    ::reset();
    set_name("predator blades");
    set_short(BOLD + "The Blades of a Predator" + NORM);
    set_alias("blades of a predator");
    set_alt_name("the blades of a predator");
    set_long("\
These are eight, twelve-inch serrated blades composed of an\n\
unknown metal.  The blades bond with the owner's wrists and\n\
hands.  When attached, they move flawlessly, bringing with\n\
them a trail of destruction.\n");
    set_weight(2);
    set_type("blades");
    set_class(18);
    set_two_handed(1);
/*
    set_wield_func(this_object());
*/
    set_hit_func(this_object());
}

void
init()
{
    ::init();
    add_action("cmdAttach", "attach");
}

mixed
un_wield()
{
    object e;

    if(e = environment())
      tell_object(e, "The blades release their grip on your flesh.\n");
    ::un_wield();
}

mixed
stopwield()
{
    int ref;
    object e;

    if(ref = (status)::stopwield())
      tell_object(e, "The blades release their grip on your flesh.\n");

    return ref;
}

status
query_save_flag()
{
    return 1;
}

/*
status
wield(object ob)
{
    write("\
The blades of the Predator conform to the texture of your hands.\n");
    return 1;
}
*/

status
cmdAttach(string arg)
{
    return ::wield(arg);
}

void
dspTerrMsg()
{
    switch(random(5))
    {
      case 0:
        write(BOLD + "Your blades are a blur!\n" + NORM);
        say((string)this_player()->query_name() + "'s blades are ablur!\n");
        break;
      case 1:
        write(BOLD + "Your blades spin and slash!\n" + NORM);
        say((string)this_player()->query_name() + "'s blades spin and \
slash.\n");
        break;
      case 2:
        write(BOLD + "Your blades revel in an aura of terror.\n" + NORM);
        say((string)this_player()->query_name() + "'s blades pulse.\n");
        break;
    }
}

void
second_hit(object a)
{
    int heh, bog;
    string *msg, nm;

    if(!random(3))
      dspTerrMsg();

    heh = random(18);
    nm = (string)a->query_name();

    if(!heh)
      msg = ({ "", "missed" }); 
    else
      msg = (string *)query_message_hit(heh);

    write("You " + msg[1] + " " + nm + msg[0] + ".\n");
    say((string)this_player()->query_name() + " " + msg[1] + " " +
     nm + msg[0] + ".\n");
    bog = (heh /= 5);
    if((status)a->query_npc())
      a->heal_self(-bog);
    else
      a->add_hit_point(-bog);
    a->hit_player(heh);
}   

int
weapon_hit(object a)
{
    object User;

    /* auto deathblow */
    if((status)a->query_npc())
      if((((int)a->query_hp() * 100) / ((int)a->query_mhp())) <= 10)
    {
      object head;
      string aname, uname;

      tell_room(environment(a),
(uname = (string)(User = environment())->query_name()) + " \
slices " + (aname = (string)a->query_name()) + "'s head off.\n");
      tell_object(User, "\
You cleanly slice " + aname + "'s head off.\n");
      head = clone_object("/obj/treasure");
      head->set_name("head");
      head->set_alias("head of " + aname);
      head->set_short("the head of " + aname);
      head->set_long(format(
"This is the maimed head of " + aname + ". The nose is broken\n\
and the one eye has been crushed. But most prominently, the body,\n\
to which this head belongs, is missing.\n" + 
aname + " was decapitated by " + uname + ".\n"));
      head->set_value((int)a->query_level() * (2 + random(3)));
      head->set_weight(1);
      move_object(head, environment(a));
      a->death();
      return 0;
    }

    if(!random(3))
      second_hit(a);
    else if(!random(3))
      second_hit(a);
    if(!random(3))
      second_hit(a);

    if(0 == random(8))
    {
      write("Your blades pulse darkly.\n");
      return 5 + random(3);
    }
}

/*
string
short()
{
   return "heh";
}
*/
