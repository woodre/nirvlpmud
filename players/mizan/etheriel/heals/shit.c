inherit "/players/mizan/core/object.c";
#include "/obj/user/shout_only.c"
#include "/obj/ansi.h"

object my_wedged_object;

reset(arg) 
{
    ::reset(arg);
    if(arg) return;

    set_name("shit");
    set_value(1600);
    set_weight(1);
    set_alias("pile");

    set_short("A pile of shit");
    
    set_long("This is a pile of shit! You lucky bastard.\n"+
             "You notice that you can 'wedge' things into this pile of shit.\n"+
             "You are also able to 'fling' this shit at someone else too.\n"+
             "How novel! How disgusting! If you're a really sick and twisted\n"+
             "idiot you might even try eating this stuff too! However that would\n"+
             "be a really stupid idea.\n");

    set_read("There is absolutely nothing worth reading here. Move along.\n");

    set_smell("It is STINKY!\nWhat the hell did you expect? French perfumes?!\n");

    set_taste("You are one disgusting nutjob.\n");

}

init()
{
    ::init();
    add_action("on_fling","fling");
    add_action("on_wedge","wedge");
    add_action("on_eat", "eat");
}

short()
{
    if(my_wedged_object)
        return my_short_desc + " (with something wedged inside it)";
    else
        return my_short_desc;
}

long()
{
    write(my_long_desc);

    if(my_wedged_object)
        write(my_wedged_object->short() + " appears to be stuck inside this pile of shit.\n");
}


on_fling(arg)
{
    object target;
    if(!arg) return 0;
    if(environment(this_object()) != this_player()) return 0;

    target = present(arg, environment(this_player()));
    
    if(!target)
    {
        write("Fling shit at who (fling <creature>)?\n");
        return 1;
    }

    if(!living(target))
    {
        write("Hey genius, '" + arg + "' is not a living thing.\n");
        return 1;
    }

    /* in this case, wizzes should be immune - except me :) */
    if(target->query_real_name() != "mizan")
        if(this_player()->query_level() <= 20 && target->query_level() >= 20)
        {
            write("'Holy shit', as that would be such a stupid fricking idea.\n");
            return 1;
        }

    if(this_player() == target)
    {
        write("Don't be stupid.\n");
        return 1;
    }

    write("You fling the pile of shit at " + target->query_name() + "!\n");

    move_object(this_object(), environment(target));
    this_player()->add_weight(-this_object()->query_weight());
 
    on_explode(target);
    return 1;
}


on_wedge(arg)
{
    object ob;
    if(environment(this_object()) != this_player()) return 0;

    if(!arg)
    {
        write("Wedge what into the pile of shit (wedge <object>)?\n");
        say(this_player()->query_name() + " stares with deep reflection into a pile of shit.\n");
        return 1;
    }

    if(my_wedged_object)
    {
        write("Something is already wedged into the shit pile.\n");
        return 1;
    }

    ob = present(arg, this_player());

    if(!ob)
    {
        write("You have no such object in possession.\n");
        return 1;
    }

    if(ob && environment(ob) != this_player())
    {
        write("You have to pick it up first.\n");
        return 1;
    }

    if(ob == this_object())
    {
        write("You can't wedge the shit into itself.\n");
        return 1;
    }

    if(ob->drop())
    {
        write("You can't wedge that into the shit pile.\n");
        return 1;
    }

    if(ob->query_weight() > this_object()->query_weight())
    {
        write("That item is too large to fit in the shit pile.\n");
        return 1;
    }

    /* put the object inside */
    move_object(ob, this_object());
    this_player()->add_weight(-ob->query_weight());
    my_wedged_object = ob;
    
    /* tell the room what happened */
    write(my_wedged_object->short() + " is carefully smushed into the shit pile.\n");
    write("That is really damn disgusting. You are a sick freak.\n");

    say(my_wedged_object->short() + " is carefully wedged into a pile of shit by " + this_player()->query_name() + ".\n");
    say("DISGUSTING!!!\n\n");

    return 1;
}

on_eat(arg)
{
    string temp;

    if(environment(this_object()) != this_player()) return 0;
    if(!arg || !id(arg)) return 0;

    /* tell the victim */
    write("You SICK FREAK!\n\nYou eat the pile of shit whole.\n");
    write("That really was not a smart idea at all.\n");
    write("Suddenly, you don't feel too well.\n");

    /* tell the room */
    say(this_player()->query_name() + " grabs a pile of shit and EATS THE DAMN THING WHOLE!\n");
    say("That was horribly disgusting but you feel that some hilarity is about to ensue.\n");
    say(this_player()->query_name() + " suddenly does not look too well.\n");

    /* tell the log file */
    temp = ctime() + " " + this_player()->query_real_name() + " (" + this_player()->query_exp() + "exp) has eaten the shit.\n";
    log_file("mizan.SHIT_CONSUMPTION", temp);

    if(!present("shit-consumption-sickness", this_player()))
        move_object(clone_object("/players/mizan/etheriel/items/shit-consumption-residue.c"), this_player());

    if(my_wedged_object)
        destruct(my_wedged_object);

    this_player()->add_weight(-this_object()->query_weight());
    destruct(this_object());

    return 1;
}

on_taste(str)
{
    if(!my_taste_msg) return 0;

    if(!str || !id(str)) return 0;

    if(short())
    say(short() + " is tasted by " + this_player()->query_name() + " (DISGUSTING!)\n");

    write(my_taste_msg);

    write("You don't feel too well.\n");
    command("puke", this_player());
    this_player()->hit_player(20 + random(this_player()->query_level()));

    command("drop shit", this_player());
    command("scream", this_player());

    return 1;
}


on_explode(arg)
{
    object ob;
    
    if(!environment(this_object()))
    {
        return 0;
    }

    tell_room(environment(), YEL);
    tell_room(environment(), sput());
    tell_room(environment(), ESC + "[0m"+ ESC + "[0m");

    if(arg && living(arg))
    {
        chan_msg("A pile of fecal matter has just struck " + (arg->query_name()) + ".\n");

        tell_room(environment(), arg->query_name() + " is hit with a pile of shit!\n");
    }

    tell_room(environment(), "Fecal matter explodes and flies everywhere in a circular pattern.\n");

    ob = first_inventory(environment());
    while(ob)
    {
        if(arg && living(ob) && ob != arg)
        {
            move_object(clone_object("/players/mizan/etheriel/items/shit-nearmiss-residue.c"), ob);
        }
        else
        {
            move_object(clone_object("/players/mizan/etheriel/items/shit-directhit-residue.c"), ob);
        }
        ob = next_inventory(ob);
    }

    /* put something in our environment too */
    if(environment() && living(environment()))
    {
        tell_object(environment(), "You are hit point-blank by an explosive wave of shit.\nDelightful!\n");
        move_object(clone_object("/players/mizan/etheriel/items/shit-directhit-residue.c"), environment());
    }

    if(my_wedged_object)
    {
        move_object(my_wedged_object, environment());
        call_other(my_wedged_object, "weapon_breaks");
        call_other(my_wedged_object, "armor_breaks");
    }

    if(environment(this_object()) && environment(environment(this_object())))
        call_other(environment(this_object()), "on_explode");

    destruct(this_object());
    return 1;
}

/* for the vehicles */
detonate(arg)
{
    return on_explode(arg);
}

sput()
{
    string my_result;

    my_result =
      "\t SSSS   PPPPP   UU   UU  TTTTTTTT  !!  !!\n"+
      "\tSS      PP  PP  UU   UU     TT     !!  !!\n"+
      "\t SSSS   PPPPP   UU   UU     TT     !!  !!\n"+
      "\t    SS  PP      UU   UU     TT\n"+
      "\t SSSS   PP       UUUUU      TT     !!  !!\n\n";

    return my_result;

}
