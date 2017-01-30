
#include "/obj/user/shout_only.c"

object thingo,target;
status is_locked;

/**
 * Mizan changelog
 * 11 oct 2003 - made changes to call on_explode() callout when the object is pulted into a room.
 *               to be used primarily with my water balloon objects or other similar projectiles.
 *
 * 07 nov 2003 - put a wait state of 5 seconds before catapult can be re-armed.
 *
 */
id(str) { return str == "catapult"; }
short() { return "A huge wooden catapult"; }

long() 
{
  
    write("This is a large, complex looking device that is actually\n"+
          "very simple to use. A big red sticker on it reads:\n\n"+
          "  Siege Catapult Model Number 10492, Acme Corp.\n"+
          "  To load this catapult with something type 'arm <object>'.\n"+
          "  To aim this catapult at someone type 'aim <playername>'.\n"+
          "  To fire the catapult type 'pull lever'.\n\n");

    if(thingo) write("The catapult is loaded with " + lower_case(thingo->short()) + ".\n");
    else write("The catapult is not loaded.\n");
    
    if(target) write("The catapult is currently pointed at " + (target->query_name()) + ".\n");
    else write("The catapult is not pointed at anyone.\n");
    
    if(this_player() && this_player()->query_guild_name() == "polymorph")
    write("You can see who fired what recently with the command 'catapult history'.\n");
}

init() 
{
    add_action("arm","arm");
    add_action("aim","aim");
    add_action("pull_lever","pull");
    add_action("catapult","catapult");
}

/* Hey, you never know. */
query_save_flag() { return 1; }

arm(str) 
{
    object ob;
    int cost;
    if(!str) return 0;

    if(is_locked)
    {
        write("The catapult is still returning to firing position.\n");
        return 1;
    }

    /* as much as i would like higher level wizzes to use the catapult... */
    if(this_player()->query_level() > 29)
    {
        write("Sorry, but wizards over L30 cannot use the catapult.\n");
        write("It would display the short() of the object on weapons and armor\n");
        write("reflecting the armor or weapon classes.\n");
        return 1;
    }

    ob = present(str, this_player());

    /* something is already loaded */
    if(thingo) 
    {
        write("The catapult is already loaded.\n");
        return 1;
    }
    
    /* it shouldnt happen but its here */
    if(ob == this_object()) 
    {
        write("Doh. This shouldnt happen.\n");
        return 1;
    }

    /* player no tiene el thingo. */
    if(!ob) 
    {
        write("You have no such item.\n");
        return 1;
    }

    /* there is no such thing as a free lunch */
    if(ob->query_value() < 450) 
    {
        if(this_player()->query_hp() < 6) 
        {
            write("You are too tired to arm the catapult!\n");
            return 1;
        }
        cost = 5;
    }

    /* yup */
    if(this_player()->query_hp() < 30) 
    {
        write("You are too tired to arm the catapult.\n");
        return 1;
    } else cost = 29;
 
    /* for wizzes */
    if(this_player()->query_level() < 21)
    if(!ob->get() || ob->drop()) 
    {
        write("You cannot load the catapult with that.\n");
        return 1;
    }

    thingo = ob;
    move_object(thingo, this_object());

    /* handle the weight */
    this_player()->add_weight(-thingo->query_weight());

    /* make sure everyone knows */
    tell_room(environment(this_object()), (this_player()->query_name()) +
    " arms the catapult with " + lower_case(thingo->short()) + ".\n");
    this_player()->add_hit_point(-cost);
    return 1;
}


aim(str) 
{
    object ob;
    if(!str) return 0;
    if(!thingo) 
    {
        write("You need to arm the catapult with something first.\n");
        return 1;
    }
    
    ob = find_player(str);
    
    if(str == "mizan") 
    {
        write("Doh!\n");
        return 1;
    }
    
    if(!ob || ob->query_invis() > 30) 
    {
        write("There is no such player logged in.\n");
        return 1;
    }

    if(this_player()->query_level() < 20)
    if(ob->query_level() > 20) 
    {
        write("Somehow, you think that would be very foolish.\n");
        return 1;
    }

    target = ob;
    tell_room(environment(this_object()), (this_player()->query_name()) +
    " aims the catapult at " + (target->query_name()) + ".\n");
    return 1;

}

pull_lever(str) 
{
    if(!str || str != "lever") return 0;
    if(!thingo) 
    {
        write("The catapult is not loaded with anything.\n");
        return 1;
    }

    if(!target) 
    {
        write("The catapult is not aimed at anyone.\n");
        return 1;
    }   

    if(this_player()->query_level() < 19)
    if(environment(target) && environment(target)->realm() == "NT")
    {
        write("Something in the target's environment is keeping you from getting a clean fix on their location.\n");
        return 1; 
    }
    tell_room(environment(this_object()), (this_player()->query_name()) +
    " pulls the lever and launches something into oblivion!\n");

    log_file("mizan.catapult", this_player()->query_name() + " hit " + target->query_name() + " with " + lower_case(thingo->short()) + ".\n");

    chan_msg((thingo->short()) + " rockets across the MUD and knocks " + (target->query_name()) + " to the ground!\n");
    tell_object(target, (thingo->short()) + " falls from nowhere and smacks you silly!\n");

    if(environment(target))
        tell_room(environment(target), "Something drops from the heavens and smashes " +
        (target->query_name()) + " squarely in the head!\n");

    if(environment(target))
    {
        move_object(thingo, environment(target));
        /* DO NOT issue the detonate() function as it may be a problem with the howitzer
        * shells and other random crap of that nature that i have which harms monsters/players.
        */
        call_other(thingo, "on_explode", target);
    }
    else destruct(thingo);

    thingo = 0;
    target = 0;

    is_locked = 1;
    call_out("unlock_catapult", 5);

    return 1;
}

unlock_catapult()
{
    is_locked = 0;
    tell_room(environment(this_object()), "The catapult's firing arm returns to firing position.\n");
}

catapult(str)
{
    if(this_player() && this_player()->query_guild_name() != "polymorph")
    return 0;

    if(str && str == "history")
    {
        say(this_player()->query_name() + " checks the catapult history.\n");

        write("\n>>Catapult Usage History--------------------------------------------------<<\n\n");
        tail("/log/mizan.catapult");
        return 1;
    }

    return 0;
}

on_explode()
{
    tell_room(environment(this_object()), "You hear something explode from way up on the catapult's firing arm.\n"+
        "Whatever was armed up there is now blown to bits.\n");
}
