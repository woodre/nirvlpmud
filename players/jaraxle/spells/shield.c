#include "/players/jaraxle/ansi.h"


object who;
status started;
int bye_bye;
status id(string str)
{
    return (str == "magi@shield" || str == "shield" ||
            str == "magic shield");
}

set_limit(t){ bye_bye = t; }

void
init()
{
    object e;
    if((e = environment()) && !started)
    {
      e->RegisterArmor(this_object(), 
        ({ "physical", 0, 30 + random(20), "do_special" }));
      /* 30-50 % resistance to physical attacks */
      who = e;
      call_out("wear_off", bye_bye, e);
      started = 1;
    }
}

void
wear_off(object x)
{
    object e;

    x->RemoveArmor(this_object());
    tell_object(x, HIY + "\
The electrical field dies around you.\n" + NORM);
    if(e = environment(x))
      tell_room(e, HIY + "\
An electrical field dies around " + (string)x->query_name() + ".\n" + NORM,
        ({ x }));

    destruct(this_object());
}

void
remove_object()
{
    if(who) who->RemoveArmor(this_object());
}

status
drop()
{
    return 1;
}   

void
extra_look()
{
    object e;
    
    if((e = environment()) && (e == this_player()))
      write(HIY + "An electrical field surrounds you.("+bye_bye+")\n" + NORM);

    else if(e)
      write(HIY + (string)e->query_name() + " \
is surrounded by an electrical field.("+bye_bye+")\n" + NORM);
}

