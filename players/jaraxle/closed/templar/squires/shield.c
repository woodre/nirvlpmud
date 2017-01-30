#include "/players/jaraxle/ansi.h"


object who;
status started;
status id(string str)
{
    return (str == "magi@shield" || str == "shield" ||
            str == "magi shield");
}


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
      started = 1;
    }
}

void
wear_off(object x)
{
    object e;

    x->RemoveArmor(this_object());
    tell_object(x, HIY + "\
A defensive field dies around you.\n" + NORM);
    if(e = environment(x))
      tell_room(e, HIM + "\
"+HIM+"A defensive field"+NORM+" dies around "+(string)e->query_name()+".\n" + NORM,
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
     write(HIY + "A defensive bubble surrounds you.\n" + NORM);

    else if(e)
    write((string)e->query_name()+" is surrounded by a "+HIM+"defensive field"+NORM+".\n");
}

