/** \brief Junk channel file
 *
 * Has support for the mudwide junk channel functionality.
 *
 */
#include "/obj/user/shout_only.c"

/*
 * This was meant to be coordinated SPECIFICALLY with the 
 * object ~/closed/stuff/vehicles/vehicle.c
 * The assumption is that the environment of this object is
 * the vehicle.c or similarly inherited code.
 *
 * Some people wonder why i made it so complex, there was a reason.
 * In either case, here is the order of operation:
 *
 * Player opens breech.
 * Player selects ammo they are going to load.
 * Player loads round.
 * Player closes breech
 * Player aims at a target
 * Player pulls trigger
 * Target is hit, and it is up to the projectile to determine what happens.
 *
 * Now for the hazards of this operation:
 * - If the breech is open, and the round is hazardous it can KILL everyone in the
 *   cabin, or whatever nasty effect is determined by the ammo.
 * - If the barrel is overheating it will not fire as accurately.
 * - If the barrel is REALLY overheating it will detonate the round prematurely in the
 *   barrel, and see #1.
 *
 * CREDITS:
 * Deathmonger's original catapult code, the functional inspiration for
 * most of what happens here.
 * 
 * Note that my catapult is essentially a cheap ripoff of his original
 * work. Even the desc (Huge wooden catapult) is the same.
 *
 */


/* member variables */

/** \brief The short description of the howitzer.  */
string my_short_desc;

/** \brief Our long description, a multibyte string, terminated with carriage return. */
string my_long_desc;

/** \brief The formal name of the weapon. */
string my_name;

/** \brief The alias of the weapon. */
string my_alias;

/** \brief The id of object acceptable as ammo. */
string my_ammo_id;

/** \brief The name of what we will use as our 'trigger' */
string my_trigger_id;

/** \brief The name of what we use for our breech. Some people like 'chamber' or similar. */
string my_breech_id;

/** \brief The filename that we use for empty shell casings. */
string my_empty_casing_filename;



/** \brief The condition of our breech. */
status is_breech_open;

status weapon_has_fired;

/** \brief The current accumulated heat for our barrel */
int barrel_heat;

/** \brief The point where the barrel starts to overheat. */
int barrel_overheat_threshold;

/** \brief Anything past this and our barrel starts to inflict serious damage on people. */
int barrel_overheat_redline;

/** \brief The percentage if we cross the threshold something bad happens */
int barrel_overheat_chance;    

/** \brief The time in rounds for the barrel to cool down by one notch. */
int barrel_cooloff_interval;

/** \brief used to count how much time between cooling on the barrel */
int temp_heat_counter;


/** \brief The projectile object being loaded. */
object my_projectile;

/** \brief The target that we are firing at.  */
object target;


/** \brief Our ID string*/
id(str) 
{
    return str == my_alias || str == my_name;
}


/** \brief Our short description */
short()
{
    return my_short_desc;
}
/* end function short() */


/** \brief Our long description text. */
long() 
{
  
    write(my_long_desc);
    
    write("\nIn order to operate this weapon you should really consult the manual that\n"+
          "comes along with it.\n\n");
    
    if(is_breech_open) write("The breech is open.\n");
        else write("The breech is closed.\n");

    if(my_projectile) write(my_projectile->short() + " is loaded into the " + my_alias + ".\n");
        else write("The " + my_alias + " is not loaded.\n");
    
    if(target) write("The " + my_alias + " is currently targetting " + (target->query_name()) + ".\n");
        else write("The " + my_alias + " is not pointed at anyone.\n");

    if(is_barrel_overheating_dangerously())
        write("The " + my_alias + " appears to be overheated VERY DANGEROUSLY.\nYou really should wait until it cools or risk serious personal injury or death.\n");
    else if(is_barrel_overheating())
        write("The " + my_alias + " appears to be overheated.\nYou really should let it cool down.\n");

    say(this_player()->query_name() + " examines the " + my_alias + " carefully.\n");
}
/* end function long() */


/** \brief Our reset function. We have some variables set for 'default'. */
reset(arg)
{
    string temp;

    if(arg) return;

    set_name("Cannon");
    set_alias("cannon");
    set_short_desc("A KwK 88mm anti-tank cannon (Model 36 L/56)");

    temp = "    This is a remarkable piece of weapon, forged from fine blued steel and built\n"+
        "  with not only the looks to kill but the ability to do so. It has a barrel\n"+
        "  diameter of 88mm and is the premier primary weapon of the Wehrmacht.\n";

    set_long_desc(temp);

    set_breech_id("breech");

    set_ammo_id("88mm-shells");
    set_trigger_id("trigger"); /* because some people like 'lever' */

    set_barrel_overheat_threshold(2);
    set_barrel_overheat_redline(4);
    set_barrel_overheat_chance(50);

    set_barrel_cooloff_interval(30);

    set_empty_casing_filename("/players/mizan/closed/stuff/vehicles/shell-casing.c");

    barrel_heat = 0;
    weapon_has_fired = 0;

    call_out("delayed_reset", 1);
}
/* end function reset() */


/** \brief 
 * This is here to let the variables 'settle' a bit, and make sure that we
 * are inside our environment before proceeding.
 */
delayed_reset()
{
    fake_beat();
}
/* end function delayed_reset() */


/** \brief A fake heart beat, without the kind of overhead heart_beat() incurs. */
fake_beat()
{

    /* handle the barrel cooling situation here */
    if(barrel_heat > 0) temp_heat_counter ++;

    if(temp_heat_counter >= barrel_cooloff_interval)
    {
        if(barrel_heat > 0)
        {
            barrel_heat --;
            tell_inside("You notice the " + my_alias + "'s barrel cooling off somewhat.\n");
            tell_outside("Steam wisps off the " + my_alias + "'s barrel, as it appears to be cooling off.\n");
        }

        if(barrel_heat == 0)
            tell_inside("The barrel is very cool to the touch now.\n");

        temp_heat_counter = 0;
    }



    remove_call_out("fake_beat");
    call_out("fake_beat",1);
}
/* end function fake_beat() */


/** \brief Our actions. 
 *
 */
init() 
{
    add_action("on_open_breech", "open");
    add_action("on_close_breech", "close");
    add_action("on_arm","arm");
    add_action("on_aim","aim");
    add_action("on_pull_lever","pull");
}
/* end function init() */


/** \brief The player needs to open the breech before chambering a round.
 * There is a risk of serious personal injury or death if this happens when
 * the barrel is overheated. Yeah, i know this doesn't quite happen in reality
 * but i liked adding the hazard.
 *
 */
on_open_breech(arg)
{
    object ob;
    object oc;
    object room;

    if(!arg || arg != my_breech_id) return 0;

    if(is_breech_open)
    {
        write("The " + my_breech_id + " is already open, you dingbat.\n");
        say(this_player()->query_name() + " tried to open an already open " + my_breech_id + ".\n");
        return 1;
    }

    write("You open the " + my_breech_id + " on the " + my_alias + ".\n");
    say(this_player()->query_name() + " opens the " + my_alias + "'s " + my_breech_id + ".\n");
    is_breech_open = 1;


    if(is_barrel_overheating())
    {
        /* There is a chance that the player gets hurt from the overheating. */
        if(1 == random(3))
        {
            write("You burn your hands on the overheated " + my_breech_id + "!\n");
            say(this_player()->query_name() + " is burned by the overheated " + my_breech_id + "!\n");
            this_player()->hit_player(10 + random(20));
            return 1;
        }
    }

    if(is_barrel_overheating_dangerously())
    {
        /* damage to everyone onboard from the heated gases */
        tell_inside("A vent of hot gas shoots out of the open " + my_breech_id + "!\n");
        tell_outside("You hear a small explosion coming from inside the " + query_vehicle_alias() + ".\n");
            
        ob = first_inventory(environment());

        while(ob)
        {
            if(living(ob))
            {
                if(ob->short())
                    tell_inside(ob->short() + " is hit by the flaming vent!\n");
                ob->hit_player(20 + random(30));
            }

            ob = next_inventory(ob);
        }


    }

    if(my_empty_casing_filename && weapon_has_fired)
    {
        oc = clone_object(my_empty_casing_filename);
        room = environment(environment());
        
        if(oc && room)
        {
            tell_inside("An empty shell casing ejects from the " + my_alias + "'s open " + my_breech_id + " onto the floor.\n");
            tell_inside(this_player()->query_name() + " hurls the empty shell casing outside via the 'empties' chute.\n");
            tell_outside("An empty shell casing falls to the ground from the " + query_vehicle_alias() + ".\n");
            move_object(oc, room);
        }
    }

    tell_outside("You hear a clicking noise coming from the " + query_vehicle_alias() + "'s " + my_alias + ".\n");
    return 1;
}
/* end function on_open_breech() */


/** \brief Closing the breech. 
 */
on_close_breech(arg)
{
    if(!arg || arg != my_breech_id) return 0;

    if(!is_breech_open)
    {
        write("The " + my_breech_id + " is already closed.\n");
        say(this_player()->query_name() + " tried to close an already closed " + my_breech_id +".\n");
        return 1;
    }

    /* now close the breech */
    write("You close the " + my_breech_id + " on the " + my_alias + ".\n");
    say(this_player()->query_name() + " closes the " + my_alias + "'s " + my_breech_id + ".\n");
    tell_outside("You hear a soft clunking noise coming from the " + query_vehicle_alias() + "'s " + my_alias + ".\n");
    is_breech_open = 0;
    return 1;
}
/* end function on_close_breech() */


/** \brief Loading the weapon.
 * I used 'arm' instead of 'load' because it might conflict with weapons
 * that players carry.
 *
 */
on_arm(str) 
{
    object ob;
    int cost;
    if(!str) return 0;

    ob = present(str, this_player());

    if(!is_breech_open)
    {
        write("The " + my_breech_id + " is closed.\n");
        return 1;
    }

    if(my_projectile) 
    {
        write("The " + my_alias + " is already loaded.\n");
        say(this_player()->query_name() + " tried to load the already loaded " + my_alias + ".\n");
        return 1;
    }

    if(!ob)
    {
        write("You have no such item.\n");
        return 1;
    }

    if(!ob->id(my_ammo_id))
    {
        write("That is not suitable ammo for the " + my_alias + ".\n");
        say(this_player()->query_name() + " just tried to load the " + my_alias + " with a " + str + ".\n");
        return 1;
    }

    /* it shouldnt happen but its here */
    if(ob == this_object()) 
    {
        write("Doh. This shouldnt happen.\n");
        return 1;
    }

    if(!ob) 
    {
        write("You have no such item.\n");
        return 1;
    }


    my_projectile = ob;
    move_object(my_projectile, this_object());

    this_player()->add_weight(-my_projectile->query_weight());

    write("You arm the " + my_alias + " with the " + str + ".\n");

    tell_inside(my_projectile->short() + " is loaded into the " + my_breech_id +
        " by " + this_player()->query_name() + ".\n");

    tell_outside("You hear a loud CLANK noise coming from the " + query_vehicle_alias() + "'s " + my_alias + ".\n");
    tell_outside("It appears something has been loaded into the barrel.\n");

    if(target)
    {
        if(environment(target) && environment(target) == this_object())
        {
            tell_inside(this_player()->query_name() + " resets the " + my_alias + " target.\n");
            tell_outside("You see the " + query_vehicle_alias() + "'s " + my_alias + " train at no target in particular.\n");
        }
        else
        {
            tell_inside(this_player()->query_name() + " adjusts the " + my_alias + " to target " + target->query_name() + ".\n");
            tell_outside("You see the " + query_vehicle_alias() + "'s " + my_alias + " update its position, still targetting " + target->query_name() + ".\n");
        }
    }

    return 1;
}
/* end function on_arm() */


/** \brief Functionality that i ripped out from my catapult.
 */
on_aim(str) 
{
    object ob;
    if(!str) return 0;

    if(!my_projectile) 
    {
        write("You need to arm the " + my_alias + " with something first.\n");
        return 1;
    }

    ob = present(str, environment(environment()));
    if(!ob || !living(ob))
    ob = find_player(str);

    if(str == "mizan") 
    {
        write("Nope.\n");
        say(this_player()->query_name() + " just tried to aim the " + my_alias + " at Mizan.\n");
        return 1;
    }

    if(!ob || ob->query_invis() > 30) 
    {
        write("There is no such player logged in.\n");
        say(this_player()->query_name() + " just tried to aim the " + my_alias + " at nobody in existence.\n");
        return 1;
    }

    if(this_player()->query_level() < 20 && ob->query_level() > 20) 
    {
        write("Somehow, you think that would be very foolish.\n");
        say(this_player()->query_name() + " just tried to aim the " + my_alias + " at a wizard. Not smart.\n");
        return 1;
    }

    target = ob;

    if(environment(target) && environment(target) == this_object())
    {
        write("You really can't do that.\n");
        say(this_player()->query_name() + " just tried to aim the " + my_alias + " at ITSELF.\n");
        return 1;
    }


    
    tell_inside(this_player()->query_name() + " aims the " + my_alias + " at " + (target->query_name()) + ".\n");
    tell_outside("You see the " + query_vehicle_alias() + "'s " + my_alias + " turn about, now targetting " + target->query_name() + ".\n");
    return 1;

}


/** \brief When the weapon is fired.
 * An object is cloned and put on the environment of the target, where its payload
 * is detonated. This is in keeping with the OO nature of things.
 *
 */
on_pull_lever(str) 
{

    if(!str || str != my_trigger_id) return 0;

    if(is_breech_open)
    {
        write("The " + my_breech_id + " is open!\n");
        return 1;
    }

    if(!my_projectile) 
    {
        write("The " + my_alias + " is not loaded with anything.\n");
        return 1;
    }

    if(!target) 
    {
        write("The " + my_alias + " is not aimed at anyone.\n");
        return 1;
    }   

    if(environment(target) && environment(target) == this_object())
    {
        write("The target has moved inside the vehicle.\n");
        return 1;
    }

    if(this_player()->query_level() < 19)
        if(environment(target) && environment(target)->realm() == "NT")
        {
            write("Something in the target's environment is keeping you from getting a clean fix on their location.\n");
            return 1; 
        }

    tell_inside(this_player()->query_name() + " pulls the " + my_trigger_id + " and fires the " + my_alias + "!\n");

    chan_msg((my_projectile->short()) + " is fired from a " + my_alias + " and smashes violently into " + (target->query_name()) + "!\n"); 

    tell_object(target, (my_projectile->short()) + " rockets out of nowhere and crashes into you!\n");

    if(environment(target))
    {
        tell_room(environment(target), "Something comes crashing down at violently high speed at " +
        (target->query_name()) + "!\n");
    }

    if(environment(target)) 
    {
        move_object(my_projectile, environment(target));
        call_other(my_projectile, "detonate", target);
    }
    else destruct(my_projectile);
    

    add_barrel_heat();

    my_projectile = 0;
    weapon_has_fired = 1;
/*
    target = 0;
 */
    return 1;
}

/** \brief Note that this is different from what is used on the vehicle.c
 *
 */
tell_inside(arg)
{
    object ob;
    object room;

    room = environment(this_object());

    if(room)
    {
        ob = first_inventory(room);
        while(ob)
        {
            if(ob != this_object())
                tell_object(ob, arg);
            ob = next_inventory(ob);
        }
    }

}
/* end function tell_inside() */


/** \brief Note that this is different from what is used on the vehicle.c
 * This is a little function to tell everyone outside a message EXCEPT
 * ourselves. Note that by OUTSIDE we mean outside the vehicle, which this
 * object is supposed to be within...
 */
tell_outside(arg)
{
    object ob;
    object room;

    room = environment(this_object());

    if(room)
        room = environment(room);

    if(room)
    {
        ob = first_inventory(room);
        while(ob)
        {
            if(ob != environment())
                tell_object(ob, arg);
            ob = next_inventory(ob);
        }
    }

}
/* end function tell_outside() */


room(arg)
{
    if(!arg) 
        return environment(this_object());
    else
        return environment(arg);
}
/* end function room() */


is_barrel_overheating()
{
    if(barrel_heat >= barrel_overheat_threshold)
        return 1;
    else return 0;
}
/* end function is_barrel_overheating() */


/* This is just a little function to let us know if the barrel is overheating dangerously...
 * If returns 1, we have license to detonate the shell inside or any other random act of
 * violence necessary.
 */
is_barrel_overheating_dangerously()
{
    if(barrel_heat >= barrel_overheat_redline)
        return 1;
    else return 0;
}
/* end function is_barrel_overheating_dangerously() */


/** \brief Accumulator for the heat on the barrel.
 * Usually we only accumulate by ones.
 *
 */
add_barrel_heat(arg)
{
    if(!arg)
        barrel_heat ++;
    else
        barrel_heat += arg; 

    if(is_barrel_overheating())
    {
        tell_inside("You notice the " + my_alias + " is overheating.\n");
        tell_outside("You notice the " + query_vehicle_alias() + "'s " + my_alias + " barrel seem to overheat somewhat.\n");
    }
    else if(is_barrel_overheating_dangerously())
    {
        tell_inside("You notice the " + my_alias + " is overheating VERY DANGEROUSLY.\n");
        tell_outside("You notice the " + query_vehicle_alias() + "'s " + my_alias + " barrel seem to overheat very dangerously!\n");
    }
}
/* end function add_barrel_heat() */


/* pile-o-functions */
set_short_desc(arg) { my_short_desc = arg; }
set_long_desc(arg) { my_long_desc = arg; }
set_name(arg) { my_name = arg; }
set_alias(arg) { my_alias = arg; }
set_ammo_id(arg) { my_ammo_id = arg; }
set_trigger_id(arg) { my_trigger_id = arg; }
set_breech_id(arg) { my_breech_id = arg; }
set_barrel_overheat_threshold(arg) { barrel_overheat_threshold = arg; }
set_barrel_overheat_redline(arg) { barrel_overheat_redline = arg; }
set_barrel_cooloff_interval(arg) { barrel_cooloff_interval = arg; }
set_barrel_overheat_chance(arg) { barrel_overheat_chance = arg; }
set_empty_casing_filename(arg) { my_empty_casing_filename = arg; }


query_trigger_id() { return my_trigger_id; }
query_breech_open() { return is_breech_open; }
query_short_desc() { return my_short_desc; }
query_long_desc() { return my_long_desc; }
query_name() { return my_name; }
query_alias() { return my_alias; }
query_ammo_id() { return my_ammo_id; }
query_breech_id() { return my_breech_id; }
query_barrel_overheat_threshold() { return barrel_overheat_threshold; }
query_barrel_overheat_redline() { return barrel_overheat_redline; }
query_barrel_cooloff_interval() { return barrel_cooloff_interval; }
query_barrel_overheat_chance() { return barrel_overheat_chance; }
query_empty_casing_filename() { return my_empty_casing_filename; }


/** \brief Hey, you never know. If this were to end up in a hotel room...  */
query_save_flag() { return 1; }

/** \brief This is key to preventing players from 'giving' us stuff. */
add_weight() { return 0; }

/** \brief Returns the alias of the environment */
query_vehicle_alias()
{
    object ob;
    ob = room();
    if(ob) return ob->query_alias();
    else return 0;
}

/* eof */