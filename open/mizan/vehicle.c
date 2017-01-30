/** \brief
 * Our little vehicle has a bunch of features which can be set.
 * 
 * This vehicle has a bunch of random features:
 * - It has the notion of fuel for the engine
 * - It has the notion of battery power for onboard electronics
 * - It has a bunch of different gadgets, like headlights, intercom, etc.
 *
 *
 *
 *
 */

/** \brief Inheriting /obj/monster.c
 *
 * We are inheriting the behaviors of the standard monster.c object.
 * Note that we are not inheriting from object.c
 * We have support for its tracking functionality however.
 *
 */
inherit "obj/monster";
#include "/players/mizan/esc.h"

/*
 * NOTES:
 *
 * Hid vehicle chat messages from driver and passenger (feedback from Gemini)
 * Vehicle now consumes fuel when idling.
 *
 * 
 */

/* our variables */
status is_lights_on_outside;    /* whether our exterior lights are on - NOT READY */
status is_hatch_open;           /* if our hatch is open */
status is_hatch_locked;         /* if our hatch is locked or not */
status is_driver_icom_on;       /* if the driver side intercom is switched on */
status is_passenger_icom_on;    /* if the passenger side intercom is switched on */
status is_engine_running;       /* if the engine is running */
status is_driving;              /* used when the vehicle is in drive mode */
status is_headlight_on;         /* state of our headlights */
status is_visible;              /* if we are visible or not */

status is_horn_enabled;         /* if the vehicle has a horn */
status is_headlight_enabled;    /* if the vehicle has lights */
status is_cloaking_enabled;     /* if the vehicle has a cloaking device */

object ob_driver;               /* the driver of the vehicle */
object ob_passenger;            /* the person riding shotgun */

int fuel;                       /* the amount of fuel left in the vehicle */
int maximum_fuel;               /* the maximum amount of fuel we can take */
int fuel_idle_consumption;      /* the amount of heartbeats that the vehicle consumes 1 fuel */
int count_fuel_idle_consumption;/* used by the heartbeat in counting idle fuel usage */

int battery;                    /* the amount of battery life onboard. */
int maximum_battery;            /* the max amount of charges that we can incur */
int headlight_consume_rounds;   /* the number of rounds that the headlights consume one battery tick */
int cloaking_consume_rounds;    /* the number of rounds that the cloaking consume one battery tick */
int count_headlight;            /* our count of headlight rounds on consumption */
int count_cloaking;             /* our count of cloaking rounds on consumption */

int idle_chat_chance;           /* the amount (0-100) percentage each heartbeat of chatting */
int engine_chat_chance;         /* the amount (0-100) percentage each heartbeat of chatting */
int maximum_occupants;          /* settable number of maxiumum LIVING CREATURES onboard */

string my_fuel_id;              /* the id of the object which serves as our fuel */
string my_battery_id;           /* the id of the object which serves as our battery */
string my_key_id;               /* the id of the object which serves as our key */
string my_engine_key_id;        /* the id of the object which serves as our engine key */
string my_inside_short_desc;    /* An alternate short desc that appears in who2 */
string my_inside_long_desc;     /* A multiline string of the vehicle's interior */
string my_hatch_id;             /* the creator can change the hatch's id... for example
                                   a flying carpet would not find a hatch door appropriate. */
string my_horn_verb;            /* the verb used to activate the horn. Usually, 'honk' is good enough. */
string my_horn_mess;            /* the message told to the outside when driver honks the horn. */
string my_enter_mess;           /* the player.c format for entry messages. */
string my_exit_mess;            /* the player.c format for exit messages. */
string my_engine_start_mess;    /* the startup message for the engine. */
string my_engine_stop_mess;     /* the shutdown message for the engine. */
string my_fuel_overflow_mess;   /* the message the outside sees when the fuel is overflowing */

string arr_idle_chat_mess;      /* an array of just idle messages */
string arr_engine_chat_mess;    /* an array of engine noise messages */

object ob_me;                   /* a crude hack that indicates we are ourselves */


short()
{
    /* if the player is inside us, we report a different short */
    if(this_player() && room() && room() == this_object())
    {
        if(is_visible)
            return my_inside_short_desc;
        else
            return 0;
    }
    else
        return short_desc;
}
/* end function short() */


long()
{
    string drivername;
    string passengername;

    if(this_player() && room() && your_room() && room() == your_room())
    {
        if(!is_visible)
            return 0;

        /* this happens if you are outside, looking in. */
        write(long_desc);

        write("\n");

        /* state of the hatch */
        write("There is a " + my_hatch_id + " that appears to be ");
        if(is_hatch_open == 1) write("open.\n");
        else write("closed.\n");

        /* extra stuff. */
        if(ob_driver)
            write(ob_driver->query_name() + " appears to be driving.\n");
        else
            write("Nobody appears to be driving.\n");
        
        if(ob_passenger)
            write(ob_passenger->query_name() + " appears to be riding shotgun.\n");

        if(is_engine_running)
            write("The engine appears to be running.\n");

        if(is_headlight_on)
            write("The headlights appear to be on.\n");

        return 1;
    }
    else
    {
        /* and this happens if you are inside. */
        write(my_inside_long_desc);

        write("\nTo see what is outside the " + this_object()->query_alias() + " give the command 'Look'.\n");
        write("To look at the gauges on the console, type 'console'.\n");

        /* the driver and passenger seats. */
        if(ob_driver) drivername = ob_driver->query_name();
        else drivername = "Nobody";

        if(ob_passenger) passengername = ob_passenger->query_name();
        else passengername = "nobody";

        write(drivername + " is driving, and " + passengername + " is riding shotgun.\n");

        if(is_engine_running)
            write("The engine appears to be running.\n");
        else
            write("The engine does not appear to be running.\n");

        if(is_hatch_locked == 0)
            write("The " + my_hatch_id + " is unlocked and ");
        else
            write("The " + my_hatch_id + " is locked and ");
        
        if(is_hatch_open == 1)
            write("it is open.\n    There is one obvious exit: out.\n");
        else
            write("it is closed.\n    There are no obvious exits.\n");

        return 0;
    }
}
/* end function long() */


/*
 * our reset method
 *
 */
reset(arg)
{
    string temp_long_desc;

    temp_long_desc = "You are in a big cardboard box of a vehicle.\n";
    temp_long_desc += "It really isn't very fascinating at all. The walls, floor,\n";
    temp_long_desc += "and ceiling are all corrugated cardboard. In fact, you hear\n";
    temp_long_desc += "and engine running but have no idea where the hell it is located.\n";

    ::reset(arg);

    if(arg) return;
    
    /* internal stuff */
    is_driver_icom_on = 0;
    is_passenger_icom_on = 0;
    is_engine_running = 0;
    is_headlight_on = 0;
    is_headlight_enabled = 0;
    is_hatch_locked = 1;
    is_visible = 1;
    /* we give some battery */
    battery = 10;
    headlight_consume_rounds = 20;
    cloaking_consume_rounds = 5;

    set_name("vehicle");
    set_race("box");
    set_alias("vehicle");
    set_short("A generic cardboard box vehicle");

/*
    set_long("This is a gigantic cardboard box with wheels.\nIt is probably the most boring vehicle you have ever seen.\nA big... cardboard... BOX!\n");
    set_level(10);
    set_hp(200);
    set_al(0);
    set_wc(3);
    set_ac(36);
    set_aggressive(0);

    set_key_id("heal");
    set_engine_key_id("pole");
    set_fuel(5);
    set_fuel_id("heal");
    set_inside_short_desc("Inside the vehicle");
    set_inside_long_desc(temp_long_desc);
    set_exit_mess("leaves puttering along");
    set_enter_mess("arrives, puttering");

    set_engine_startup_message("With a the yank of a pull starter, the vehicle comes to life in its 2-stroke weedwacker engine glory.\n");
    set_engine_stop_message("A pinch of the fuel line, and the vehicle's engine stops.\n");

    set_hatch_id("hatch");
    set_maximum_fuel(200);
    
    set_battery_id("cell");
    set_maximum_battery(200);
    
    set_idle_chat_chance(5);
    set_engine_chat_chance(5);

    set_fuel_idle_consumption(20);
    set_fuel_overflow_mess("The tank is full, and some extra fuel gushes out.\n");

    enable_horn();
    set_horn_verb("honk");
    set_horn_mess("The vehicle goes: BEEP BEEP!\n");

*/

    /* an array of just idle messages */
/*
    arr_idle_chat_mess = ({
        "The vehicle's cardboard shell wobbles slightly, from just standing.",
        "You smell cardboard. It must be the vehicle's body.",
    });

*/
    /* an array of engine noise messages */
/*
    arr_engine_chat_mess = ({
        "The whine of the 2-stroke engine is giving you a headache.",
        "You realize that the vehicle's engine is quite... LOUD... and annoying!",
    });
*/
    /* a dirty hack. well, i'm a dirty coder! */
    ob_me = this_object();

    remove_call_out("delayed_reset");
    call_out("delayed_reset", 1);
}
/* end function reset(); */


delayed_reset()
{
    enable_commands();
    set_heart_beat(1);
}
/* end function delayed_reset(); */


init()
{
    /* if too many creatures are in here (EXCEPT WIZARDS)
     * we bust their asses out! 
     */
    if(this_player() &&
       room() &&
       !safely_occupied())
    {
        tell_object(this_player(), "There are too many people inside " + 
            this_object()->query_alias() + "!\nYou are booted out!\n");
        tell_outside(this_player()->query_name() + " arrives, flying out of the " + this_object()->query_alias() + "!\n");
        move_object(this_player(), room());
        tell_inside(this_player()->query_name() + " cannot fit onboard and leaves falling out.\n");
        return 1;
    }

    /* call our super */
    ::init();

    /* actions everyone can do */
    add_action("on_hatch_open", "open");
    add_action("on_hatch_close", "close");
    add_action("on_hatch_lock", "lock");
    add_action("on_hatch_unlock", "unlock");

    /* actions that people can perform only if they are outside */
    if(environment(this_object()) && this_player() && room() != this_object())
    {
        add_action("on_enter", "enter");
        add_action("on_enter", "board");
        add_action("on_refuel_vehicle", "refuel");
    }

    /* actions that people can perform only if they are inside */
    if(this_player() && environment(this_player()) == this_object())
    {
        add_action("on_out", "out");
        add_action("on_become", "become");
        add_action("on_become", "be");
        add_action("on_console", "console");
        add_action("on_icom", "icom");
        add_action("on_Look_outside", "Look");
    }

    /* actions only the driver can do */
    if(is_driver() || this_player() == this_object())
    {
        add_action("on_start", "start");
        add_action("on_stop", "stop");
        add_action("on_command_drive","drive");
        add_action("on_single_command"); add_xverb("");
        add_action("on_look"); add_verb("look_outside");
/*        add_action("on_look"); add_verb("l"); */

        add_action("go_north"); add_verb("n");
        add_action("go_south"); add_verb("s");
        add_action("go_west"); add_verb("w");
        add_action("go_east"); add_verb("e");
        add_action("go_northwest"); add_verb("nw");
        add_action("go_northeast"); add_verb("ne");
        add_action("go_southwest"); add_verb("sw");
        add_action("go_southeast"); add_verb("se");
        add_action("go_up"); add_verb("u");
        add_action("go_down"); add_verb("d");

        add_action("on_recharge_vehicle", "replace");

        if(is_horn_enabled && (my_horn_verb != "" || my_horn_verb != 0))
            add_action("on_horn_honk", my_horn_verb);

        if(is_headlight_enabled)
            add_action("on_headlights", "headlights");

        if(is_cloaking_enabled)
            add_action("on_cloak", "cloak");

    }


    /* actions the driver can do */
    if(is_driver())
    {
        add_action("on_driver_intercom", "intercom");
        add_action("on_intercom_say", "say");
        add_action("on_intercom_say", "'");
    }

    /* actions only the passenger can do */
    if(is_passenger())
    {
        add_action("on_passenger_intercom", "intercom");
        add_action("on_intercom_say", "say");
        add_action("on_intercom_say", "'");
    }

    /* actions that only the vehicle itself can do */
    if(this_player() && ob_driver)
        if(this_player() == ob_driver || this_player() == this_object())
        {
        }

}
/* end function init() */


on_cloak(arg)
{
    if(!is_cloaking_enabled) return 0;

    if(!arg) return 0;

    if(arg == "on")
    {
        if(is_visible)
        {
            write("The " + this_object()->query_alias() + " is already uncloaked.\n");
            remote_say(this_player()->query_name() + " fumbles with the cloaking switch.\n");
            return 1;
        }
        else
        {
            write("You switch on the cloaking shield.\n");
            remote_say(this_player()->query_name() + " switches on the cloaking shield.\n");
            tell_inside("The " + this_object()->query_alias() + " begins to produce a soft humming noise.\n");
            tell_outside("The outline of the " + this_object()->query_alias() + " shimmers and begins to waver.\n");
            tell_outside(short() + " fades from view.\n");

            is_visible = 0;
            return 1;
        }
    }
    else if(arg == "off")
    {
        if(!is_visible)
        {
            write("The " + this_object()->query_alias() + " is already cloaked, silly.\n");
            remote_say(this_player()->query_name() + " appears fascinated that the cloaking shield is already on.\n");
            return 1;
        }
        else
        {
            write("You switch off the cloaking shield.\n");
            remote_say(this_player()->query_name() + " switches off the cloaking shield.\n");
            is_visible = 1;
            tell_outside(short() + " fades into view.\n");
            return 1;
        }

    }
    else return 0;

}
/* end function on_cloak() */


on_headlights(arg)
{
    if(!is_headlight_enabled) return 0;

    if(!arg) return 0;

    if(arg == "on")
    {
        if(battery <= 0)
        {
            write("The batteries are dead.\n");
            return 1;
        }

        if(is_headlight_on)
        {
            write("The headlights are already switched ON.\n");
            remote_say(this_player()->query_name() + " fumbles with the headlights switch.\n");
            return 1;
        }
        else
        {
            write("You switch on the headlights.\n");
            remote_say(this_player()->query_name() + " switches on the headlights.\n");
            tell_outside("The headlights of the " + this_object()->query_alias() + " switch on brightly.\n");
            is_headlight_on = 1;
            set_light(1);
            return 1;
        }
    }
    else if(arg == "off")
    {
        if(!is_headlight_on)
        {
            write("The headlights are already switched OFF.\n");
            remote_say(this_player()->query_name() + " appears fascinated that the headlights are already OFF.\n");
            return 1;
        }
        else
        {
            write("You switch off the headlights.\n");
            remote_say(this_player()->query_name() + " switches off the headlights.\n");
            tell_outside("The headlights of the " + this_object()->query_alias() + " suddenly go out.\n");
            is_headlight_on = 0;
            set_light(-1);
            return 1;
        }

    }
    else return 0;
}


/** \brief When the horn is honked.
 *
 *
 */
on_horn_honk()
{
    if(!is_horn_enabled) return 0;

    if(battery <= 0)
    {
        write("The batteries are dead.\n");
        return 1;
    }

    tell_inside(this_player()->query_name() + " honks on the horn.\n");
    tell_outside(my_horn_mess);
    return 1;
}
/* end function on_horn_honk() */


/** \brief When someone looks at the console.
 *
 *
 */
on_console()
{
    if(!is_driver() && !is_passenger())
        tell_inside(this_player()->query_name() + " leans over into the cabin area to look at the console.\n");
    else
        tell_observers(this_player()->query_name() + " checks the console.\n");

    write("Looking at the console, you see:\n\n");

    if(is_engine_running)
        write("The tachometer shows the engine to be running.\n");
    else
        write("The tachometer is at zero. The engine is not running.\n");

    if(is_hatch_locked == 1)
        write("The interior " + my_hatch_id + " is locked.\n");
    else
        write("The interior " + my_hatch_id + " appears to be unlocked.\n");
    
    if(is_hatch_open == 1)
        write("The " + my_hatch_id + " is open. The console goes 'Ding... ding... ding...'\n");
    else
        write("The " + my_hatch_id + " is closed. There is peace and quiet, nothing going 'Ding!'\n");
    
    if(fuel)
        write("The fuel gauge shows [" + fuel + "/" + maximum_fuel + "].\n");
    else
        write("The fuel gauge shows [EMPTY].\n");

    if(battery)
        write("The battery gauge shows [" + battery + "/" + maximum_battery + "].\n");
    else
        write("The battery gauge shows the battery is DEAD.\n");

    if(is_driver_icom_on == 1)
        write("A light indicates that the driver side intercom is ON.\n");

    if(is_passenger_icom_on == 1)
        write("A light indicates that the passenger side intercom is ON.\n");

    if(is_headlight_on)
        write("A light indicates the headlights are ON.\n");
    else
        write("The headlights are OFF.\n");

    write(query_vehicle_condition());

    return 1;
}
/* end function on_console() */

on_start(arg)
{
    if(!arg) return 0;
    else if(arg == "engine")
    {
        if(is_engine_running == 1)
        {
            write("The engine is already running.\n");
            return 1;
        }

        if(fuel <= 0)
        {
            write("There is not enough fuel to start the engine.\n");
            remote_say(this_player()->query_name() + " tries to start the engine but it has run out of fuel.\n");
            tell_outside(short() + " sputter as if trying to start up, and goes quiet again.\n");
            return 1;
        }

        if(battery <= 0)
        {
            write("The onboard battery is dead.\n");
            remote_say(this_player()->query_name() + " tries to start the engine but the battery is dead.\n");
            tell_outside(short() + " makes a slugging grinding noise trying to start the engine.\nIt appears the battery is dead.\n");
            return 1;
        }

        if(this_player() && !present(my_engine_key_id, this_player()))
        {
            write("You don't have the proper key to start the engine.\n");
            remote_say(this_player()->query_name() + " boggles steeply at how to start the engine without the proper key.\n");
            return 1;
        }

        is_engine_running = 1;
        write("You start the engine and it comes to life!\n");
        write("In order to begin driving, you need to just type 'drive'.\n");
        remote_say(this_player()->query_name() + " starts the " + this_object()->query_alias() + "'s engine and it comes to life!\n");
        tell_outside(my_engine_start_mess);
        return 1;
    }
}
/* end function on_start() */


on_stop(arg)
{
    if(!arg) return 0;
    else if(arg == "engine")
    {
        if(is_engine_running == 0)
        {
            write("The engine is already off.\n");
            return 1;
        }

        is_engine_running = 0;
        write("You stop the engine and it shuts down gracefully.\n");
        remote_say(this_player()->query_name() + " stops the " + this_object()->query_alias() + "'s engine and it comes to a graceful rest.\n");
        tell_outside(my_engine_stop_mess);
        return 1;
    }
}
/* end function on_stop() */


on_intercom_say(arg)
{
    if(is_driver())
    {
        if(is_driver_icom_on) return intercom_message(arg);
        else return 0;
    }
    else if(is_passenger())
    {
        if(is_passenger_icom_on) return intercom_message(arg);
        else return 0;
    }

}
/* end function on_intercom_say() */


is_driver(arg)
{
    object ob;
    if(!arg) ob = this_player();
    else ob = arg;
    if(ob_driver && ob == ob_driver)
        if(environment(ob_driver) && environment(ob_driver) == this_object()) return 1;
        else return 0;
    else return 0;
}
/* end function is_driver() */


is_passenger(arg)
{
    object ob;
    if(!arg) ob = this_player();
    else ob = arg;
    if(ob_passenger && ob == ob_passenger)
        if(environment(ob_passenger) && environment(ob_passenger) == this_object()) return 1;
        else return 0;
    else return 0;
}
/* end function is_passenger */


on_driver_intercom(arg)
{

    if(!arg)
    {
        write("You can give the following commands for the intercom:\n");
        write("  intercom on       - Turns on the intercom.\n");
        write("  intercom off      - Turns off the intercom.\n");
        write("\n");
        remote_say(this_player()->query_name() + " pushes the intercom buttons randomly.\n");
        return 1;
    }

    if(battery <= 0)
    {
        write("The batteries are dead.\n");
        return 1;
    }

    /* ugh. this is bleeping horrible. needs to be streamlined -miz */
    if(is_driver())
    {
        if(arg == "on")
        {
            if(is_driver_icom_on == 1)
            {
                write("The driver side intercom is already switched on.\n");
                remote_say(this_player()->query_name() + " didn't realize the driver side intercom was already switched ON.\n");
                return 1;
            }
            else
            {
                is_driver_icom_on = 1;
                write("You switch the driver side intercom on.\n");
                remote_say(this_player()->query_name() + " switches on the driver side intercom.\n");
                remote_say("You hear a faint buzzing noise.\n");
                tell_outside("A speaker comes to life, as the driver side intercom on the " + this_object()->query_alias() + " is powered up.\n");
                return 1;
            }

        }
        else if(arg == "off")
        {
            if(is_driver_icom_on == 0)
            {
                write("The driver side intercom is already switched off.\n");
                remote_say(this_player()->query_name() + " didn't realize the driver side intercom was already switched OFF.\n");
                return 1;
            }
            else
            {
                is_driver_icom_on = 0;
                write("You switch the driver side intercom off.\n");
                remote_say(this_player()->query_name() + " switches the driver side intercom off.\n");
                remote_say("A faint buzzing noise suddenly stops.\n");
                tell_outside("The driver side intercom on " + this_object()->query_alias() + " is powered off.\n");
                return 1;
            }
        }

    }
}
/* end function on_driver_intercom() */


on_passenger_intercom(arg)
{

    if(!arg)
    {
        write("You can give the following commands for the intercom:\n");
        write("  intercom on       - Turns on the intercom.\n");
        write("  intercom off      - Turns off the intercom.\n");
        write("\n");
        remote_say(this_player()->query_name() + " pushes the intercom buttons randomly.\n");
        return 1;
    }

    if(battery <= 0)
    {
        write("The batteries are dead.\n");
        return 1;
    }

    /* now for the passenger */
    if(is_passenger())
    {
        if(arg == "on")
        {
            if(is_passenger_icom_on == 1)
            {
                write("The passenger side intercom is already switched on.\n");
                remote_say(this_player()->query_name() + " didn't realize the passenger intercom was already switched ON.\n");
                return 1;
            }
            else
            {
                is_passenger_icom_on = 1;
                write("You switch the passenger side intercom on.\n");
                remote_say(this_player()->query_name() + " switches on the passenger intercom.\n");
                remote_say("You hear a faint buzzing noise.\n");
                tell_outside("A speaker comes to life, as the passenger side intercom on the " + this_object()->query_alias() + " is powered up.\n");
                return 1;
            }

        }

        else if(arg == "off")
        {
            if(is_passenger_icom_on == 0)
            {
                write("The passenger side intercom is already switched off.\n");
                remote_say(this_player()->query_name() + " didn't realize the passenger side intercom was already switched OFF.\n");
                return 1;
            }
            else
            {
                is_passenger_icom_on = 0;
                write("You switch the passenger side intercom off.\n");
                remote_say(this_player()->query_name() + " switches the passenger side intercom off.\n");
                remote_say("A faint buzzing noise suddenly stops.\n");
                tell_outside("The passenger side intercom on " + this_object()->query_alias() + " is powered off.\n");
                return 1;
            }
        }

    }
    /* endif */

}
/* end on_passenger_intercom() */


on_icom(arg)
{
    if(!arg)
    {
        write("You need to give some text to intercom users on the outside.\n");
        remote_say(this_player()->query_name() + " fumbles around with the flash intercom but doesn't say anything.\n");
        return 1;
    }

    icom_message(arg);
    return 1;
}
/* end function on_icom() */


icom_message(arg)
{
    /* an extra check here to remove spammage for the driver/passenger */

    if(is_driver() || is_passenger()) return intercom_message(arg);
        write("You intercom: " + arg + "\n");
    remote_say(this_player()->query_name() + " intercoms: " + arg + "\n");
    tell_outside(this_player()->query_name() + " intercoms from the " + this_object()->query_alias() + ": " + arg + "\n");
    return 1;
}
/* end function icom_message */


intercom_message(arg)
{
    remote_say(this_player()->query_name() + " intercoms: " + arg + "\n");
    tell_outside(this_player()->query_name() + " intercoms from the " + this_object()->query_alias() + ": " + arg + "\n");
    return 1;
}
/* end function intercom_message */


go_north() 
{
    if(ob_me && is_driving)
    {
        command("north", ob_me);
        return 1;
    }
    else return 0;
}
/* end function go_north() */


go_south() 
{
    if(ob_me && is_driving)
    {
        command("south", ob_me);
        return 1;
    }
    else return 0;
}
/* end function go_south() */


go_east() 
{
    if(ob_me && is_driving)
    {
        command("east", ob_me);
        return 1;
    }
    else return 0;
}
/* end function go_east() */


go_west() 
{
    if(ob_me && is_driving)
    {
        command("west", ob_me);
        return 1;
    }
    else return 0;
}
/* end function go_west() */


go_northwest() 
{
    if(ob_me && is_driving)
    {
        command("northwest", ob_me);
        return 1;
    }
    else return 0;
}
/* end function go_northwest() */


go_northeast() 
{
    if(ob_me && is_driving)
    {
        command("northeast", ob_me);
        return 1;
    }
    else return 0;
}
/* end function go_northeast() */


go_southwest()
{
    if(ob_me && is_driving)
    {
        command("southwest", ob_me);
        return 1;
    }
    else return 0;
}
/* end function go_southwest() */


go_southeast()
{
    if(ob_me && is_driving)
    {
        command("southeast", ob_me);
        return 1;
    }
    else return 0;
}
/* end function go_southeast() */


go_up()
{
    if(ob_me && is_driving)
    {
        command("up", ob_me);
        return 1;
    }
    else return 0;
}
/* end function go_up() */


go_down()
{
    if(ob_me && is_driving)
    {
        command("down", ob_me);
        return 1;
    }
    else return 0;
}
/* end function go_down() */


find_local(str) 
{
    object oc;
    oc = present(str, room());
    if(!oc) return 0;
    return oc;
}
/* end function find_local() */


look(str)
{
    return on_look(str);
}
/* end function look() */


on_Look_outside()
{
    write("You peer into the visual display and see:\n\n");
    remote_say(this_player()->query_name() + " peers into the visual display.\n");

    if(test_dark()) return 1;

    tell_outside("You notice someone from the " + this_object()->query_alias() + " peering about intently.\n");

    list_basic("ROOM");

    return 1;
}
/* end function on_Look_outside */


test_dark() 
{
    if (set_light(0) <= 0 && !present("dark_sight_object", this_object()))
    {
	    write("It is too dark outside.\n");
        if(level > 99)
        {
            write("But you may still see....\n");
            return 0;
        }
	    return 1;
    }
    return 0;
}
/* end function test_dark(); */


on_look(str)
{
    object ob, ob_tmp;
    string item;

    if(!str) 
    {
        list_basic("ROOM");
        return 1;
    }

    if(test_dark()) return 1;

    if(sscanf(str, "at %s", item) == 1 || sscanf(str, "in %s", item) == 1)
    {

        if(!find_local(item)) 
        {
            write(">>There is no " + str + " here.\n");
            return 1;
        }
    
        call_other(find_local(item), "long");
        list_basic(find_local(item));
        return 1;
    }

    write(">>Look AT something, or what?\n");
    return 1;
}
/* end function on_look() */


list_basic(str)
{
    object ob,ob2;

    if(test_dark()) return 1;

    if(str) 
    {
        /* We are given a directive to look at just the room */
        if(str == "ROOM") 
        {
            ob = room();
            call_other(ob, "long", 0);
        }
        else 
        {
            /* we try to find the object in the room only to look at */
            ob = find_local(str);
            if(!ob) 
            {
                write(">>No '" + str + "' found.\n");
                return 1;
            }
        }
    }

    /* now we dump out the inventory */
    ob2 = first_inventory(ob);
    while(ob2) 
    {
        object oc;
        oc = ob2;
        ob2 = next_inventory(ob2);
  
        if(oc->short() && oc != this_object())
            write((oc->short()) + ".\n");
    }
    return 1;
}
/* end function list_basic() */


/* this is our override for move_player() */
move_player(dir_dest) 
{
    string dir, dest;
    object ob;
    int is_light;

    if(!dir_dest) return 0;

    if(sscanf(dir_dest, "%s#%s", dir, dest) != 2)
    {
        tell_observers("Move to bad dir/dest\n");
        return;
    }

    /* count off our fuel. */
    if(deduct_fuel() == 0) return 1;

    hunting_time -= 1;
    if(hunting_time == 0) 
    {
        if(hunter) call_other(hunter, "stop_hunter");
        hunter = 0;
        hunted = 0;
    }
    
    if(attacker_ob && present(attacker_ob))
    {
        hunting_time = 10;
        tell_observers("You are now hunted by " + (attacker_ob->query_name()) + ".\n");
        hunter = attacker_ob;
    }

    is_light = set_light(0);
    if(is_light < 0) is_light = 0;

    if(dir == "X" && !query_invis())
        tell_outside(cap_name + " " + my_exit_mess + ".\n");
    else if(is_light)
        tell_outside(cap_name + " " + my_exit_mess + " " + dir + ".\n");

    /* tell the inside whats happening */
    if(dir == "X")
    {
        tell_inside("The " + this_object()->query_alias() + " moves in an unknown direction.\n");
    }
    else
    {
        tell_inside("The " + this_object()->query_alias() + " moves " + dir + ".\n");
    }
    
    move_object(this_object(), dest);
    is_light = set_light(0);
    
    if(is_light < 0) is_light = 0;
    /* tell_observers(dir + "\n"); */
    
    if(!my_enter_mess) my_enter_mess = "arrives";
    
    if(!query_invis() && dir == "X") tell_outside(cap_name + " " + my_enter_mess + ".\n");
    else if(is_light) tell_outside(cap_name + " " + my_enter_mess + ".\n");
    /* if (hunted && present(hunted)) attack_object(hunted); */
    if (!is_light) tell_observers("IT IS DARK.\n");
    is_light = set_light(0);
    ob = environment(this_object());

    call_other(ob, "long", 0);

    ob = first_inventory(ob);
    while(ob) 
    {
        if (ob != this_object())
        {
            string short_str;

            short_str = "";
            if(call_other(ob, "short"))
            {
            short_str = short_str + call_other(ob, "short");
            write(short_str + ".\n");
            }

        }
        ob = next_inventory(ob);
    }
}
/* end function move_player() */


/* this function begins the prompting of driver actions. */
on_command_drive() 
{
    if(is_driver())
    {
        if(is_engine_running == 0)
        {
            write("You have to start the engine first with the command 'start engine'.\n");
            remote_say(this_player()->query_name() + " grips the controls to drive but forgot to start the engine first.\n");
            return 1;
        }


        if(deduct_fuel() == 0)
            return 1;

        write("Commanding in continuous stream to " + this_object()->query_alias() +". Give '*' to stop.\n>>");
        tell_inside(this_player()->query_name() + " grips the controls, preparing to move out.\n");
        tell_outside(short_desc + " appears ready to move out.\n");

        is_driving = 1;
        input_to("command_line");
        return 1;
    }
    else return 0;
}
/* end function on_command_drive(); */


/* Uhm... i forgot why this is here. I stripped it from Summerhead's code and
 * it is supposed to have a purpose.
 */
on_single_command(str)
{
    string tempr;

    if(is_driver())
    {
        if(sscanf(str, "!%s", tempr) == 1)
        {
            write("Fuel: [" + fuel + "]  Driving '" + str + "'  Give * to quit.\n");
/*            command(tempr, this_object()); */
            return 1;
        }
        else return 0;
    }
    else return 0;
}
/* end function on_single_command() */
 

command_line(str) 
{
    string a;
    string b;
    string temp;

    a = 0;
    b = 0;

    if(is_driver())
    {
        if(is_engine_running == 0)
        {
            write("The engine is no longer running. You cannot drive anywhere.\n");
            is_driving = 0;
            return 1;
        }
       
        else if(fuel <= 0)
        {
            return 1;
        }

        else if(!str) 
        {
            write("You are driving the " + this_object()->query_alias() + "...\nGive * to quit. >>");
            input_to("command_line");
            return 1;
        }
  
        else if(str == "look" || str == "l")
        {
            on_look();
            write("\nFuel: [" + fuel + "]  Looking...\n>>");
            input_to("command_line");
            return 1;
        }

        else if(sscanf(str, "look %s", a) == 1)
        {
            on_look(a);
            write("\nFuel: [" + fuel + "]  Looking '" + a + "'\n>>");
            input_to("command_line");
            return 1;
        }

        else if(sscanf(str, "l %s", a) == 1)
        {
            on_look(a);
            write("\nFuel: [" + fuel + "]  Looking '" + a + "'\n>>");
            input_to("command_line");
            return 1;
        }

        else if(str == my_horn_verb)
        {
            on_horn_honk();
            write("\nFuel: [" + fuel + "]  " + capitalize(my_horn_verb) + "!\n>>");
            input_to("command_line");
            return 1;
        }

        else if(str == "*") 
        {
            write(">>Quitting! Give the command 'drive' to begin driving again.\n");
            tell_inside(this_player()->query_name() + " eases off on the driver controls.\n");
            tell_outside(short_desc + " comes to a stop, as if parked.\n");
            is_driving = 0;
            return 1;
        }
  
        temp = str;
        if(temp == "n") temp = "north";
        else if(temp == "s") temp = "south";
        else if(temp == "e") temp = "east";
        else if(temp == "w") temp = "west";
        else if(temp == "ne") temp = "northeast";
        else if(temp == "nw") temp = "northwest";
        else if(temp == "se") temp = "southeast";
        else if(temp == "sw") temp = "southwest";
        else if(temp == "u") temp = "up";
        else if(temp == "d") temp = "down";

        command(temp, this_object());

        write("\nFuel: [" + fuel + "]  Driving '" + str + "'\n>>");
  
        /* calculate fuel */
        
        input_to("command_line");
        return 1;
    }
    else return 0;
}
/* end function command_line() */


on_become(arg)
{
    if(!arg) return 0;

    else if(arg == "driver")
    {
        if(ob_driver && room(ob_driver) && room(ob_driver) == this_object())
        {
            if(ob_driver == this_player())
            {
                write("You're already the driver, bonehead.\n");
                remote_say(this_player()->query_name() + " adjusts driving position nervously.\n");
                return 1;
            }

            write("There is already someone in the driver's seat.\n");
            write(ob_driver->query_name() + " is sitting in it.\n");
            remote_say(this_player()->query_name() + " is being a bit of a backseat driver.\n");
            return 1;
        }

        /* if the driver was the passenger, address that. */
        if(ob_passenger && this_player() == ob_passenger)
        {
            ob_passenger = 0;
            write("You slip out of the passenger seat.\n");
            remote_say(this_player()->query_name() + " slips out of the passenger seat.\n");
        }

        write("You step into the driver's seat.\n");

        /* display status messages */
        if(is_driver_icom_on == 1)
            write("You notice the driver side intercom is ON.\n");

        if(is_engine_running == 1)
            write("You notice the engine is currently running.\n");
        else
            write("You will need to 'start engine' before actually driving.\n");

        remote_say(this_player()->query_name() + " steps into the driver's seat.\n");
        tell_outside("You notice that someone has climbed into the driver's seat of the " + this_object()->query_alias() + ".\n");

        ob_driver = this_player();

        /* this is a trick to reset the init() */
        move_object(this_player(), this_object());
        return 1;
    }

    else if(arg == "passenger" || arg == "shotgun")
    {
        if(ob_passenger && room(ob_passenger) && room(ob_passenger) == this_object())
        {
            if(ob_passenger == this_player())
            {
                write("You're already the passenger, genius.\n");
                remote_say(this_player()->query_name() + " fiddles aimlessly with the console controls.\n");
                return 1;
            }

            write("There is already someone in the passenger seat.\n");
            write(ob_passenger->query_name() + " is sitting in it.\n");
            remote_say(this_player()->query_name() + " calls 'SHOTGUN!' just a little bit too late.\n");
            return 1;
        }


        /* if the driver was the passenger, address that. */
        if(ob_driver && this_player() == ob_driver)
        {
            ob_driver = 0;
            write("You slip out of the driver's seat.\n");
            remote_say(this_player()->query_name() + " slips out of the driver's seat.\n");
        }

        write("You step into the passenger seat.\n");
        remote_say(this_player()->query_name() + " steps into the passenger seat.\n");

        /* for fun */
        if(1 == random(3))
            remote_say(this_player()->query_name() + " calls out: SHOTGUN!\n");


        /* this is a trick to reset the init() */
        move_object(this_player(), this_object());
        ob_passenger = this_player();
        return 1;
    }

    else if(arg == "cargo")
    {
        if(ob_driver && this_player() && this_player() == ob_driver)
        {
            write("You abandon the helm and jump back into the cargo area.\n");
            remote_say(this_player()->query_name() + " abandons the helm and jumps back into the cargo area.\n");
            remote_say("The driver's seat is now vacant.\n");
            ob_driver = 0;

            /* this is a trick to reset the init() */
            move_object(this_player(), this_object());
            return 1;
        }
        else if(ob_passenger && this_player() && this_player() == ob_passenger)
        {
            write("You jump back into the cargo area.\n");
            remote_say(this_player()->query_name() + " jumps back into the cargo area.\n");
            remote_say("The passenger seat is now vacant.\n");
            ob_passenger = 0;
        
            /* this is a trick to reset the init() */
            move_object(this_player(), this_object());
            return 1;
        }
        else
        {
            write("You already are cargo.\n");
            remote_say(this_player()->query_name() + " fidgets restlessly in the cargo area.\n");
            return 1;
        }
    }

}
/* end function on_become() */


/* this is called when a player tries to open the hatch */
on_hatch_open(arg)
{
    if(!arg || arg != my_hatch_id) return 0;
    
    if(is_hatch_open == 1)
    {
        write("The " + my_hatch_id + " is already open.\n");
        remote_say(this_player()->query_name() + " just tried to open an already open " + my_hatch_id + ". Brilliant!\n");
        return 1;
    }

    if(is_hatch_locked == 1)
    {
        write("The " + my_hatch_id + " is locked.\n");
        remote_say(this_player()->query_name() + " struggles against " + this_object()->query_alias() + "'s locked " + my_hatch_id + ".\n");
        return 1;
    }

    write("You open the " + my_hatch_id + ".\n");
    remote_say(this_player()->query_name() + " opens the " + this_object()->query_alias() + "'s " + my_hatch_id + ".\n");
    tell_inside("The " + my_hatch_id + " swings open.\n");
    tell_outside("The " + this_object()->query_alias() + "'s " + my_hatch_id + " swings open.\n");
    is_hatch_open = 1;
    return 1;
}
/* end function on_hatch_open() */


/* called when a player tries to close the hatch. */
on_hatch_close(arg)
{
    if(!arg || arg != my_hatch_id) return 0;

    if(is_hatch_open == 0)
    {
        write("The " + my_hatch_id + " is already closed.\n");
        remote_say(this_player()->query_name() + " tried to close an already closed " + my_hatch_id + ".\n");
        return 1;
    }
    
    if(is_hatch_locked == 1)
    {
        tell_inside("The lock clasp on the " + my_hatch_id + " clicks free.\n");
        is_hatch_locked = 0;
        return 1;
    }

    write("You close the " + my_hatch_id + ".\n");
    remote_say(this_player()->query_name() + " closes the " + this_object()->query_alias() + "'s " + my_hatch_id + ".\n");
    tell_inside("The " + my_hatch_id + " closes shut.\n");
    tell_outside("The " + this_object()->query_alias() + "'s " + my_hatch_id + " closes shut.\n");
    is_hatch_open = 0;
    return 1;
}
/* end function on_hatch_close() */


on_hatch_lock(arg)
{
    if(!arg || arg != my_hatch_id) return 0;
    
    if(this_player() && present(my_key_id, this_player()))
    {
        if(is_hatch_locked == 1)
        {
            remote_say(this_player()->query_name() + " stares at the lock in the " + my_hatch_id + " in deep confusion.\n");
            write("The " + my_hatch_id + " is already locked.\n");
            return 1;
        }

        if(is_hatch_open == 1)
        {
            remote_say(this_player()->query_name() + " stares out the open " + my_hatch_id + " in steep bogglement.\n");
            write("You cannot do this when the " + my_hatch_id + " is open.\n");
            return 1;
        }

        do_lock_hatch();
        return 1;
    }
    else
    {
        /* if the player is inside they can lock/unlock as well */
        if(is_inside())
        {
            do_lock_hatch();
            return 1;
        }

        write("You don't have the proper key to lock the " + my_hatch_id + ".\n");
        remote_say(this_player()->query_name() + " fumbles for the right key to lock the " + this_object()->query_alias() + "'s " + my_hatch_id + ".\n");
        return 1;
    }

}
/* end function on_hatch_lock() */


do_lock_hatch()
{
    write("You lock the " + my_hatch_id + ".\n");
    remote_say(this_player()->query_name() + " locks the " + this_object()->query_alias() + "'s " + my_hatch_id + " securely.\n");
    tell_inside("The " + my_hatch_id + " makes a loud clicking noise.\n");
    tell_outside("The " + this_object()->query_alias() + "'s " + my_hatch_id + " makes a loud locking noise.\n");
    is_hatch_locked = 1;
    return 1;
}
/* end function do_lock_hatch() */


do_unlock_hatch()
{
    write("You unlock the " + my_hatch_id + ".\n");
    remote_say(this_player()->query_name() + " unlocks the " + this_object()->query_alias() + "'s " + my_hatch_id + ".\n");
    tell_inside("The " + my_hatch_id + " makes a soft clicking noise.\n");
    tell_outside("The " + this_object()->query_alias() + "'s " + my_hatch_id + " makes a soft clicking noise.\n");
    is_hatch_locked = 0;
    return 1;
}
/* end function do_lock_hatch() */


on_hatch_unlock(arg)
{
    if(!arg || arg != my_hatch_id) return 0;
    
    if(this_player() && present(my_key_id, this_player()))
    {
        if(is_hatch_locked == 0)
        {
            remote_say(this_player()->query_name() + " stares at the lock in the " + my_hatch_id + " in deep confusion.\n");
            write("The " + my_hatch_id + " is already unlocked.\n");
            return 1;
        }

        if(is_hatch_open == 1)
        {
            remote_say(this_player()->query_name() + " stares out the open " + my_hatch_id + " in steep bogglement.\n");
            write("You cannot do this when the " + my_hatch_id + " is open.\n");
            return 1;
        }

        do_unlock_hatch();
        return 1;
    }
    else
    {
        /* if the player is inside they can lock/unlock as well */
        if(is_inside())
        {
            do_unlock_hatch();
            return 1;
        }

        write("You don't have the proper key to unlock the " + my_hatch_id + ".\n");
        remote_say(this_player()->query_name() + " fumbles for the right key to unlock the " + this_object()->query_alias() + "'s " + my_hatch_id + ".\n");
        return 1;
    }

}
/* end function on_hatch_unlock() */


/** \brief when a player boards the vehicle.
 * We have to be picky about specifying the vehicle instead of just
 * 'enter' because of other possible objects outside with the same
 * command.
 */
on_enter(arg)
{
    if(!arg || arg != this_object()->query_alias()) return 0;
    else
    {
        /* just a paranoia check */
        if(environment(this_player()) == this_object())
        {
            write("You are already on board.\n");
            remote_say(this_player()->query_name() + " appears confused.\n");
            return 1;
        }

        if(is_hatch_locked == 1)
        {
            write("The " + my_hatch_id + " is locked.\n");
            remote_say(this_player()->query_name() + " fumbles with the " + this_object()->query_alias() + "'s locked " + my_hatch_id + ".\n");
            return 1;
        }
        else if(is_hatch_open == 0)
        {
            write("The " + my_hatch_id + " is not open.\n");
            remote_say(this_player()->query_name() + " stares in confusion at the " + this_object()->query_alias() + "'s " + my_hatch_id + ".\n");
            return 1;
        }
        else return move_player_onboard();
    }
}
/* end function on_enter() */

/** \brief when a player leaves the vehicle.
 * We are just checking here if the hatch is closed/locked/open/ etc.
 *
 */
on_out()
{
    /* just a paranoia check */
    if(environment(this_player()) == room())
    {
        /* just return 0 in case there is an exit in room() for 'out' */
        return 0;
    }

    if(is_hatch_locked == 1)
    {
        write("The " + my_hatch_id + " is locked.\n");
        remote_say(this_player()->query_name() + " fumbles with the " + this_object()->query_alias() + "'s locked " + my_hatch_id + ".\n");
        return 1;
    }
    else if(is_hatch_open == 0)
    {
        write("The " + my_hatch_id + " is not open.\n");
        remote_say(this_player()->query_name() + " stares in confusion at the " + this_object()->query_alias() + "'s " + my_hatch_id + ".\n");
        return 1;
    }
    else return move_player_out();
}
/* end function on_out() */


/*
 * if all is kosher, we return 1. If fuel has run out, we return 0.
 *
 */
deduct_fuel()
{
    fuel --;

    /* we tell people we are running out */
    if(fuel < 15 && 1 == random(2))
    {
        tell_observers("You hear a beep coming from the console.\n");
        tell_inside("You notice the 'LOW FUEL' light begins blinking.\n");
        return 1;
    }
    else if(fuel <= 0)
    {
        write("Uh oh.\n");
        tell_observers("The fuel indicator is at ZERO.\n");
        tell_inside("You notice the 'LOW FUEL' indicator is steadily lit.\n");

        /* shut the engine off too */
        if(is_engine_running)
        {
            is_engine_running = 0;
            tell_inside("The engine shuts down abruptly.\n");
            tell_outside(my_engine_stop_mess);
        }
        return 0;
    }
    else return 1;
}
/* end function deduct_fuel() */


on_refuel_vehicle(arg)
{
    object ob;
    int a;

    if(!arg || arg != this_object()->query_alias()) return 0;

    if(this_player() && present(my_key_id, this_player()))
    {

        /* no fuel, no service */
        ob = present(my_fuel_id, this_player());
        if(!ob)
        {
            write("You do not have the proper fuel for the " + this_object()->query_alias() + ".\n");
            remote_say(this_player()->query_name() + " stares in confusion at the refueling port.\n");
            return 1;
        }

        write("You pop open the fuel cap and refuel the vehicle.\n");
    
        remote_say(this_player()->query_name() + " refuels the " + this_object()->query_alias() + "\n");
        tell_inside("You hear a thunk and gurgling noise coming from the " + this_object()->query_alias() + ".\n");

        this_player()->add_weight(-(ob->query_weight()));
        /* add our fuel amount */
        a = ob->query_fuel();

        if(a <= 1) write("You feel as if that had no effect, for some reason.\n");

        add_fuel(a);
        tell_observers("You notice the fuel indicator is now reading [" + fuel + "].\n");

        destruct(ob);
        return 1;
    }
    else
    {
        write("You don't have the proper key to open the fuel cap.\n");
        remote_say(this_player()->query_name() + " forgot to bring the key for " + this_object()->query_alias() + "'s fuel cap.\n");
    }
}
/* end function on_refuel_vehicle() */


on_recharge_vehicle(arg)
{
    object ob;
    int a;

    if(!arg || arg != this_object()->query_alias()) return 0;

    if(this_player() && present(my_key_id, this_player()))
    {

        /* no fuel, no service */
        ob = present(my_battery_id, this_player());
        if(!ob)
        {
            write("You do not have the proper battery for the " + this_object()->query_alias() + ".\n");
            remote_say(this_player()->query_name() + " stares in confusion at the battery terminals.\n");
            return 1;
        }

        write("You pop open the battery compartment and replace the old battery.\n");
    
        remote_say(this_player()->query_name() + " replaces the old battery of the " + this_object()->query_alias() + "\n");
        tell_inside("You hear a beeping check noise coming from the " + this_object()->query_alias() + ".\n");


        this_player()->add_weight(-(ob->query_weight()));
        /* add our fuel amount */
        a = ob->query_battery();

        if(a <= 1) write("You feel as if that had no effect, for some reason.\n");

        add_battery(a);
        tell_observers("You notice the battery indicator is now reading [" + battery + "].\n");

        destruct(ob);
        return 1;
    }
    else
    {
        write("You don't have the proper key to open the battery compartment.\n");
        remote_say(this_player()->query_name() + " forgot to bring the key for " + this_object()->query_alias() + "'s battery compartment.\n");
    }
}
/* end function on_recharge_vehicle() */


move_player_onboard()
{
    tell_inside(this_player()->query_name() + " arrives via the entry " + my_hatch_id + ".\n");
    move_object(this_player(), this_object());
    tell_outside(this_player()->query_name() + " leaves boarding the " + this_object()->query_alias() + ".\n");
    write("You climb aboard the " + this_object()->query_alias() + ".\n");
    return 1;
}
/* end function move_player_onboard() */


move_player_out()
{
    if(ob_driver && ob_driver == this_player())
    {
        tell_inside(ob_driver->query_name() + " vacates the driver's seat.\n");
        ob_driver = 0;
    }

    if(ob_passenger && ob_passenger == this_player())
    {
        tell_inside(ob_passenger->query_name() + " vacates the passenger's seat.\n");
        ob_passenger = 0;
    }

    tell_inside(this_player()->query_name() + " leaves out the " + my_hatch_id + ".\n");
    move_object(this_player(), room());
    tell_outside(this_player()->query_name() + " arrives climbing out of the " + this_object()->query_alias() + ".\n");
    write("You climb out of the " + this_object()->query_alias() + ".\n");
    return 1;
}
/* end function move_player_out() */


/*
 * our heart beat
 *
 */
heart_beat()
{
    object attacker,room;
    string attacker_name;
    int a; /* used by chat_chance stuff */


    /* Setup some vars */
    room = environment(this_object());
    attacker = this_object()->query_attack();


    /* we just let our attacker hit us. */
    if(attacker)
    {
        attacker_name = attacker->query_real_name();

        if(present(attacker_name,environment(this_object())))
        {

            if(1 == random(5))
                tell_inside("You hear a loud 'klung!' coming from outside.\n");

        }
    }


    /* we do our chat */
    if(idle_chat_chance > random(100))
    {
        a = random(sizeof(arr_idle_chat_mess));
        tell_outside(arr_idle_chat_mess[a] + "\n");
    }
    else if(engine_chat_chance > random(100) && is_engine_running == 1)
    {
        a = random(sizeof(arr_engine_chat_mess));
        tell_outside(arr_engine_chat_mess[a] + "\n");
    }

    if(is_hatch_open && 1 == random(10))
    {
        tell_inside("You hear a bell going 'Ding... ding... ding...'\nYou also see a light in the shape of an open door flashing on the console.\n");
    }


    if(count_fuel_idle_consumption >= fuel_idle_consumption)
    {
        deduct_fuel();
        count_fuel_idle_consumption = 0;
        tell_observers("You notice the fuel gauge drop a tick.\n");
    }

    if(is_engine_running) count_fuel_idle_consumption++;

    /* it is important that we do not call our super. */
    /* this object behaves differently in combat. it doesn't */
    /* fight back. */


    /* if invis is enabled, we deduct some */
    if(is_cloaking_enabled && !is_visible)
    {
        count_cloaking ++;
        if(count_cloaking >= cloaking_consume_rounds)
        {
            /* we consume from the battery */
            deduct_battery();
            count_cloaking = 0;
        }
    }

    /* if headlight is enabled, we deduct some */
    if(is_headlight_enabled && is_headlight_on)
    {
        count_headlight ++;
        if(count_headlight >= headlight_consume_rounds)
        {
            /* we consume from the battery */
            deduct_battery();
            count_headlight = 0;
        }
    }


}
/* end function heart_beat() */


tell_inside(arg)
{
    object ob;
    object room;

    room = this_object();

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

/*
    tell_room(this_object(), arg);
 */
}
/* end function tell_inside() */


/*
 * This is a little function to tell everyone outside a message EXCEPT
 * ourselves.
 */
tell_outside(arg)
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
/* end function tell_outside() */


/*
 * we tell only people that are actively listening.
 *
 */
tell_observers(str)
{
    if(ob_driver) tell_object(ob_driver, str);
    if(ob_passenger) tell_object(ob_passenger, str);
    return 1;
}
/* end function tell_observers() */


remote_say(arg) 
{
  if(!arg) return 1;
  if(this_player())
   this_player()->remote_say(arg);
   return 1;
}
/* end function remote_Say() */


room(arg)
{
    if(!arg) 
        return environment(this_object());
    else
        return environment(arg);
}
/* end function room() */


your_room()
{
    return environment(this_player());
}
/* end function your_room() */


is_inside()
{
    if(environment(this_player()) == this_object()) return 1;
    else return 0;
}
/* end function is_inside() */


catch_tell(str) 
{
    object from;

    /* if no player we don't route messages */
    from = this_player();
    if(!from) return 1;
    
    tell_observers("%" + str);
    return 1;

}
/* end function catch_tell() */


safely_occupied()
{
    object ob;
    int i;

    /* reset */
    i = 0;

    /* if max occupants isnt set, we return okay by default. */
    if(!maximum_occupants) return 1;

    /* wizards are ok by default */
    else if(this_player() && this_player()->query_level() >= 21) return 1;

    else if(this_player())
    {
        /* count up our livings */
        ob = first_inventory(this_object());
        while(ob)
        {
            if(living(ob)) i++;
            ob = next_inventory(ob);
        }

        if(i >= maximum_occupants)
            return 0;
        else return 1;
    }
    else return 0;
}
/* end function safely_occupied() */


boom()
{
    string result;
    result = ESC + "[25m" +
      "\tBBBBBBB    OOOOOO    OOOOOO   MM     MM  !!  !!\n"+
      "\tBB    BB  OO    OO  OO    OO  MMM   MMM  !!  !!\n"+
      "\tBBBBBBB   OO    OO  OO    OO  MM MMM MM  !!  !!\n"+
      "\tBB    BB  OO    OO  OO    OO  MM  M  MM  \n"+
      "\tBBBBBBB    OOOOOO    OOOOOO   MM     MM  !!  !!\n\n"+
      ESC + "[0m" + ESC + "[0m";

    return result;

}
/* end function boom() */


/* pile-o-functions */

realm() { return "NT"; }
query_realm() { return "NT"; }
can_put_and_get() { return 0; }
is_living() { return 0; }
is_vehicle() { return 1; }

query_hbflag() { return "hbstayon"; }
query_save_flag() { return 1; }

transfer_inventory() { return 0; }
transfer_all_to() { return 0; }

run_away() { return 0; }
frog_curse() { return 0; }

/* this is key to preventing players from 'giving' us stuff. */
add_weight() { return 0; }

/** \brief Enables horn functionality in the vehicle.
 * This function is called on reset. If horn is enabled, the driver can honk.
 */
enable_horn() { is_horn_enabled = 1; }


/** \brief Usually should not need to be called, but disables horn functionality.
 *
 */
disable_horn() { is_horn_enabled = 0; }


/** \brief Enables headlight functionality.
 *
 *
 */
enable_headlights() { is_headlight_enabled = 1; }


/** \brief disables headlight functionality.
 *
 *
 */
disable_headlights() { is_headlight_enabled = 0; }


/** \brief enables cloaking for the vehicle.
 */
enable_cloaking() { is_cloaking_enabled = 1; }


/** \brief disables cloaking for the vehicle.
 */
disable_cloaking() { is_cloaking_enabled = 0; }


/** \brief Sets the id of the key that the vehicle is to use.
 * Note that this is not for the engine key, but all of the other stuff like opening
 * the doors and fuel cap.
 *
 */
set_key_id(arg) { my_key_id = arg; }
query_key_id() { return my_key_id; }

set_fuel(arg) { fuel = arg; }
add_fuel(arg)
{
    fuel += arg; 
    if(fuel > maximum_fuel)
    {
        tell_outside(my_fuel_overflow_mess);
        fuel = maximum_fuel;
    }
}

query_fuel() { return fuel; }

set_fuel_id(arg) { my_fuel_id = arg; }
query_fuel_id() { return my_fuel_id; }

set_battery_id(arg) { my_battery_id = arg; }
query_battery_id() { return my_battery_id; }

set_fuel_overflow_mess(arg) { my_fuel_overflow_mess = arg; }
query_fuel_overflow_mess() { return my_fuel_overflow_mess; }

set_engine_key_id(arg) { my_engine_key_id = arg; }
query_engine_key_id() { return my_engine_key_id; }

set_inside_short_desc(arg) { my_inside_short_desc = arg; }
query_inside_short() { return my_inside_short_desc; }
inside_short() { return my_inside_short_desc; }

set_inside_long_desc(arg) { my_inside_long_desc = arg; }
query_inside_long() { return my_inside_long_desc; }
inside_long() { return my_inside_long_desc; }

set_enter_mess(arg) { my_enter_mess = arg; }
query_enter_mess() { return my_enter_mess; }

set_exit_mess(arg) { my_exit_mess = arg; }
query_exit_mess() { return my_exit_mess; }

set_engine_startup_message(arg) { my_engine_start_mess = arg; }
query_engine_startup_message(arg) { return my_engine_start_mess; }

set_engine_stop_message(arg) { my_engine_stop_mess = arg; }
query_engine_stop_message(arg) { return my_engine_stop_mess; }

set_idle_chat_chance(arg) { idle_chat_chance = arg; }
query_idle_chat_chance(arg) { return idle_chat_chance; }

set_engine_chat_chance(arg) { engine_chat_chance = arg; }
query_engine_chat_chance(arg) { return engine_chat_chance; }

set_fuel_idle_consumption(arg) { fuel_idle_consumption = arg; }
query_fuel_idle_consumption() { return fuel_idle_consumption; }

query_light() { return 1; }

query_driver() { return ob_driver; }
query_passenger() { return ob_passenger; }
query_hatch_locked() { return is_hatch_locked; }
query_hatch_open() { return is_hatch_open; }

set_maximum_occupants(arg) { maximum_occupants = arg; }
query_maximum_occupants() { return maximum_occupants; }

set_hatch_id(arg) { my_hatch_id = arg; }
query_hatch_id() { return my_hatch_id; }

set_idle_chat_mess(arg) { arr_idle_chat_mess = arg; }
set_engine_chat_mess(arg) { arr_engine_chat_mess = arg; }

set_maximum_fuel(arg) { maximum_fuel = arg; }
query_maximum_fuel() { return maximum_fuel; }

query_visible() { return is_visible; }
is_visible() { return is_visible; }
set_visible(arg) { is_visible = arg; }


/** \brief Sets the 'verb' used to trigger the horn.
 *
 * Default is 'honk' which should be good enough for most cases.
 *
 */
set_horn_verb(arg) { my_horn_verb = arg; }
query_horn_verb() { return my_horn_verb; }

/** \brief Sets the message the outside sees when driver honks the horn.
 *
 * Single line, terminated with a carriage return.
 */
set_horn_mess(arg) { my_horn_mess = arg; }
query_horn_mess() { return my_horn_mess; }


set_cloaking_consumption(arg) { cloaking_consume_rounds = arg; }
set_headlight_consumption(arg) { headlight_consume_rounds = arg; }
set_maximum_battery(arg) { maximum_battery = arg; }

query_battery(arg) { return battery; }
set_battery(arg) { battery = arg; }


add_battery(arg) 
{
    battery += arg; 
    if(battery > maximum_battery)
    {
        battery = maximum_battery; 
        tell_observers("You notice the onboard battery is fully charged.\n");
        return 1;
    }
}

/*
 * if all is kosher, we return 1. If battery has run out, we return 0.
 *
 */
deduct_battery()
{
    battery --;

    /* we tell people we are running out */
    if(battery < 8 && 1 == random(2))
    {
        tell_observers("You notice a light in the shape of a battery coming from the console.\n");
        tell_inside("You notice the 'LOW BATTERY' light begins blinking.\n");
        return 1;
    }
    else if(battery <= 0)
    {
        write("Uh oh.\n");
        tell_observers("The battery indicator is at ZERO.\n");
        tell_inside("You notice the 'LOW BATTERY' indicator is steadily lit.\n");

        /* shut the cloak */
        if(!is_visible)
        {
            is_visible = 1;
            tell_inside("The cloaking device powers off.\n");
            tell_outside(short() + " fades into view.\n");
        }

        /* shut the headlights off */
        if(is_headlight_on)
        {
            is_headlight_on = 0;
            set_light(1);
            tell_inside("The headlights go out.\n");
            tell_outside("The headlights of the " + this_object()->query_alias() + " suddenly go out.\n");
        }

        return 0;
    }
    else return 1;
}
/* end function deduct_battery() */


query_vehicle_condition()
{
    string temp;
    temp = "The " + this_object()->query_alias();

    if(hit_point < max_hp/10) 
      return (temp + " is in very bad condition.\n");
    else if(hit_point < max_hp/5)
      return (temp + " is in bad condition.\n");
    else if(hit_point < max_hp/2)
      return (temp + " is somewhat damaged.\n");
    else if(hit_point < max_hp - 20) 
      return (temp + " is slightly damaged.\n");
    else return (temp + " is like new.\n");
}


/** \brief Called when the vehicle dies.
 * The vehicle is a monster, and standard monster behavior of being turned into
 * a corpse is overridden here. Instead, the vehicle explodes and the players are
 * all tossed out. Some of them wimpy. The objects onboard are dested, and a message
 * is told to the outside.
 *
 */
death()
{
    object ob;
    object oc;

    tell_inside(this_object()->short() + " has taken too much damage!\n");
    tell_inside("It's time to abandon ship and get the hell out!\n");
    tell_inside("You run for your life!\n");
    tell_outside(short_desc + " has taken too much damage...\n");
    tell_outside(this_object()->query_alias() + " explodes in a violent...\n");
    tell_outside(boom());

    /* we discard anything that isnt alive */
    oc = first_inventory(this_object());
    while(oc)
    {
        ob = oc;
        oc = next_inventory(oc);
        
        if(living(ob))
        {
            /* move people outside */
            tell_object(ob, "You tumble out of the wreckage and emerge outside.\n");
            tell_outside(ob->query_name() + " arrives, flying out of the wreckage.\n");
            move_object(ob, room());
            command("look_outside", ob);

            /* we make some people run away... hee */
            if(1 == random(3))
            {
                tell_outside(ob->query_name() + " is thrown quite some distance by the blast!\n");
                ob->run_away();
            }
        }
        else
        {
            /* things that were onboard get destroyed */
            if(ob->short()) tell_outside(ob->short() + " goes up in flames!\n");
            destruct(ob);

            /* an interesting 'bug' is that things inside containers that
             * are on the floor are spared. */
        }
       
    }

    destruct(this_object());
    /* it is important that we do not call our death super. */
}
/* end function death() */


/* eof */
