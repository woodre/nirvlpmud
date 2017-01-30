/*
 * The purpose of this object is to house basic functionality used by the smart monsters.
 * Contents personal copyright Mizan@Nirvana, 2003.
 * Exclusive rights also to Boltar@Nirvana.
 * Reproduction on other muds restricted, under penalty of personal retribution.
 *
 */

#define IS_TACTICAL_DM
#include "definitions.h"
#include "router.h"
#include "/obj/ansi.h"

/*  settings: intervals of time before we consider a castle 'empty'
 *  alters the aggression of pillaging
 *
 */

/* member variables */
object *my_roster;                  /* an active roster of monsters that are logged in */

string *my_observed_players;        /* players who have attacked us in the past. */
string my_attribnames;              /* used by do_attrib_monster(); */

int since_roster_additions;         /* additions since the last observation */
int since_roster_deletions;         /* removed (dead) creatures since the last  observation */
int since_combat_damage;            /* combat damage accumulated (total!) since last observation */
int since_player_count;             /* player count online */
int since_monster_count;
int current_player_count;
int current_monster_count;
int recommended_monster_count;

int is_ordering_backup;
int is_recharging_reserves;
int is_radio_silenced;

int register_combat_counter;
string my_current_castle;

object backup;
object backup_protect;

id(str) { return str == "tactical-daemon" || str == "server"; }

short() { return "A network server named (tactical-daemon)"; }

recharge_reserves()
{
    report_message(HIB + "Reserves reporting ready again.\n" + NORM);
    is_recharging_reserves = 0;
}

reset(arg)
{
/*    save_self(); */
    if(arg) return;


    move_object(this_object(), DAEMON_HOME);

    restore_self(); 
    is_ordering_backup = 0;

    report_message("System online. Function reset(" + arg + ") called.\n");

    /* our fake heartbeat */
    remove_call_out("fake_beat");
    call_out("fake_beat", 5);

    /* our population manager */

    remove_call_out("population_control_beat");
    call_out("population_control_beat", 10);

    /* send out our offense */
    
    remove_call_out("dispatch_offensive");
    call_out("dispatch_offensive", 60);

}

population_control_beat()
{
    /* count up how many players there are */
    current_player_count = sizeof(users());
    
    /* now monsters */
    current_monster_count = count_active_monsters();
    
    /* Calculate our ideal population. */
    recommended_monster_count = current_player_count / 2;
    if(recommended_monster_count > 12) recommended_monster_count = 12;

    /* broadcast population report. */
    report_message("Previous player count: " + since_player_count + 
                   ", Current: " + current_player_count + "\n");
    report_message("Previous monster count: " + since_monster_count + 
                   ", Current: " + since_monster_count +
                   ", Recommended: " + recommended_monster_count + "\n");


    since_player_count = current_player_count;
    since_monster_count = current_monster_count;


    remove_call_out("population_control_beat");
    call_out("population_control_beat", 180);
}

query_roster_member(arg)
{
    if(arg && arg > sizeof(my_roster)) return 0;
    if(arg && arg < 0) return 0;
    return my_roster[(int) arg]; 
}

/* This simply returns how many active monsters there are in the mix. */
count_active_monsters()
{
    int i;
    int count;

    for(i = 0; i < sizeof(my_roster); i ++)
    {
        if(my_roster[i] && environment(my_roster[i])) count ++;
    }

    return count;
}


/* we register our last combat engagement */
register_combat_contact()
{
    register_combat_counter = 0;    
}

init()
{

    /* note that we should make our commands a little more unix like. 
     * take lots of arguments instead of one command for every little thing, etc */

    add_action("on_order","order");
    add_action("on_orderall","orderall");
    add_action("on_ordertype","ordertype");
    add_action("on_ordercabal","ordercabal");
    add_action("on_orderteam","orderteam");
    add_action("on_report","report");
    add_action("on_reportall","reportall");
    add_action("on_rollcall","rollcall");
    add_action("on_statall","mstatall");

    add_action("dispatch_offensive","doff");
    add_action("dispatch_defensive","ddef");
}


/* this object does not get a heartbeat. We will use fake beats because it works on 20 second intervals. */
fake_beat()
{
    /* check how much damage we have taken, and deal with it */

    /* check for roster additions */


    /* check for roster deletions */

/*    register_combat_counter ++; */

    /* if we have not seen combat for more than 15 minutes, it means our current castle is depleted! */

/*
    if(register_combat_counter >= 240)
    {
        if(my_current_castle)
            report_message("No more targets were found in Castle " + capitalize(my_current_castle) + "...\n");

        report_message("I'm ordering a short break of R&R!\n");
        remove_call_out("dispatch_relaxation");
        call_out("dispatch_relaxation", 1);
        register_combat_counter = 0;
    }

    clear_my_count();
*/

    /* no, we really do not need to run on better than a 20 second response time */
/*
    remove_call_out("fake_beat");
    call_out("fake_beat", 5);
 */
}


/* we will relax for a little while before going pillaging again */
dispatch_relaxation()
{
    int i;
    int lev;

    /* now we will order all rank 2 and 3 members to chill at the green */
    for(i = 0; i < sizeof(my_roster); i ++)
    {
        if(my_roster[i] &&
           environment(my_roster[i]))
        {
            lev = call_other(my_roster[i], "query_monster_guild_level");

            if(lev && lev < 4 && lev > 1)
                receive_orders(my_roster[i], ORDERS_LOITER, "room/vill_green", 1000);

        }
    }

    register_combat_counter = 0;
    remove_call_out("dispatch_offensive");
    call_out("dispatch_offensive", 60);
}


dispatch_offensive()
{
    string new_castle;
    int i;

    new_castle = (string) get_random_castle();

    /* first we will choose a new castle */
    if(new_castle == my_current_castle)
    {
        new_castle = (string) get_random_castle();
    }

    report_message("I am authorizing an attack on castle " + capitalize(new_castle) + "!\n");

    /* now we will order all rank 2 and 3 members of the cabal "TheCorps" to attack */
    for(i = 0; i < sizeof(my_roster); i ++)
    {
        if(my_roster[i] &&
           environment(my_roster[i]))
        {
            if(my_roster[i]->query_string(STR_CABAL_NAME) == "TheCorps")
                receive_orders(my_roster[i], ORDERS_PILLAGECASTLE, new_castle, 1000);
        }
    }

    my_current_castle = new_castle;
    return 1;
}


dispatch_defensive()
{

}


on_attrib_monster(arg)
{
    string result;
    int monsternum;
    int i;
    int attrib;

    if(!arg)
    {
        write("Usage:   mattrib <monsternum>\n\n"+
              "Fetches the attributes of the monster in question.\n");
    }

    if(!my_attribnames)
    {
        /* note that if this is altered, definitions.h must be updated too. */
        my_attribnames = ({
            "Vindictiveness",
            "Fearlessness",
            "Perception",
            "Cruelty",
            "Insanity",
            "Generousity",
        });
    }


    if(sscanf(arg, "%d", monsternum) != 1)
    {
        write("You must give a number.\n");
        return 1;
    }

    if(monsternum < 0 || monsternum >= sizeof(my_roster))
        return 0;

    if(!my_roster[monsternum])
        return 0;

    result = ">> Information for " + my_roster[monsternum]->query_name() + ":\n";
    result += HIY + ">> Attribute            Value\n" + NORM;
    
    for(i = 0; i < sizeof(my_attribnames); i ++)
    {
        attrib = my_roster[monsternum]->query_monster_attrib(i);

        result += pad(my_attribnames[i], 24);
        result += quantify_attribute(attrib) + "\n";
    }

    result += "\n";

    write(result);
    return 1;
}


on_report(arg)
{
    int monsternum;
    object monster;

    if(!arg)
    {
        write("Usage:   report <monsternum>\n\n"+
              "Fetches a status report of what the monster is currently doing.\n");
    }

    if(sscanf(arg, "%d", monsternum) != 1)
    {
        write("You must give a number.\n");
        return 1;
    }

    if(monsternum < 0 || monsternum >= sizeof(my_roster))
        return 0;

    if(!my_roster[monsternum])
        return 0;

    /* call_other(my_roster[monsternum], "report_status"); */
    report_status(my_roster[monsternum]);

    write("Ok.\n");
    return 1;

}


on_reportall()
{
    int i;
    object monster;

    for(i = 0; i < sizeof(my_roster); i ++)
    {
        if(my_roster[i] && environment(my_roster[i]))
            call_other(my_roster[i], "report_status");
    }

    write("Ok.\n");
    return 1;

}


on_order(arg)
{
    int count;
    int duration;
    int monsternum;
    string data;
    string cmdcode;
    object monster;

    if(!arg)
    {
        write("Usage:   order <monsternum> <cmdcode> <data> <duration>\n\n"+
              "For example, the command 'order 2 killname mizan 10' will tell monster number 2\n"+
              "to kill any creature matching the name 'mizan' for 10 minutes.\n");
    }

    /* parse out our command string. luckily we are expecting the same format
     * all the time. ALL the time.
     */
    if(sscanf(arg, "%d %s %s %d", monsternum, cmdcode, data, duration) != 4)
    {
        duration = 10;
        if(sscanf(arg, "%d %s %s", monsternum, cmdcode, data) != 3)
        {
            data = "null";
            if(sscanf(arg, "%d %s", monsternum, cmdcode) != 2)
            {
                write("Your command was not understood.\n");
                return 1;
            }
        }
    }

    /* various checks of our data */

    if(!execute_order(monsternum, cmdcode, data, duration))
    {
        write("The command code was not understood.\n");
        return 1;
    }
    else
    {
        write("The order was to '" + cmdcode + " " + data + "' for " + duration + " minutes.\n");
        write("Ok.\n");
        return 1;
    }

}

on_orderall(arg)
{
    int i;
    int count;
    int duration;
    object monster;
    string data;
    string cmdcode;

    if(!arg)
    {
        write("Usage:   orderall <cmdcode> <data> <duration>\n\n");
    }

    /* parse out our command string. luckily we are expecting the same format
     * all the time. ALL the time.
     */
    if(sscanf(arg, "%s %s %d", cmdcode, data, duration) != 3)
    {
        duration = 10;
        if(sscanf(arg, "%s %s", cmdcode, data) != 2)
        {
            data = "null";
            if(sscanf(arg, "%s", cmdcode) != 1)
            {
                write("Your command was not understood.\n");
                return 1;
            }
        }
    }

    /* we cycle through our roster */
    for(i = 0; i < sizeof(my_roster); i ++)
    {

        if(my_roster[i] && environment(my_roster[i]))
        {
            if(!execute_order(i, cmdcode, data, duration))
                write("An error occurred sending order to index [" + i + "].\n");
            else
                count ++;
        }
    }

    write("The order was to '" + cmdcode + " " + data + "' for " + duration + " minutes.\n");
    write("Command sent to " + count + " recipients.\n");
    write("Ok.\n");
    return 1;

}


on_ordercabal(arg)
{
    int i;
    int count;
    int duration;
    object monster;
    string data;
    string cmdcode;
    string monsterid;

    if(!arg)
    {
        write("Usage:   ordercabal <monstertype> <cmdcode> <data> <duration>\n\n");
        return 1;
    }

    /* parse out our command string. luckily we are expecting the same format
     * all the time. ALL the time.
     */
    if(sscanf(arg, "%s %s %s %d", monsterid, cmdcode, data, duration) != 4)
    {
        duration = 10;
        if(sscanf(arg, "%s %s %s", monsterid, cmdcode, data) != 3)
        {
            data = "null";
            if(sscanf(arg, "%s %s", monsterid, cmdcode) != 2)
            {            
                write("Your command was not understood.\n");
                return 1;
            }
        }
    }

    /* we cycle through our roster */
    for(i = 0; i < sizeof(my_roster); i ++)
    {

        if(my_roster[i] &&
           environment(my_roster[i]) &&
           my_roster[i]->query_string(STR_CABAL_NAME) == monsterid)
        {
           if(!execute_order(i, cmdcode, data, duration))
                write("An error occurred sending order to index [" + i + "].\n");
            else
                count ++;
        }
    }

    write("You have requested an order sent to all monsters of the cabal '" + monsterid + "'\n");
    write("The order was to '" + cmdcode + " " + data + "' for " + duration + " minutes.\n");
    write("Command " + arg + " executed and sent to " + count + " recipients.\n");
    write("Ok.\n");
    return 1;

}

on_orderteam(arg)
{
    int i;
    int count;
    int duration;
    object monster;
    string data;
    string cmdcode;
    string monsterid;

    if(!arg)
    {
        write("Usage:   orderteam <monstertype> <cmdcode> <data> <duration>\n\n");
        return 1;
    }

    /* parse out our command string. luckily we are expecting the same format
     * all the time. ALL the time.
     */
    if(sscanf(arg, "%s %s %s %d", monsterid, cmdcode, data, duration) != 4)
    {
        duration = 10;
        if(sscanf(arg, "%s %s %s", monsterid, cmdcode, data) != 3)
        {
            data = "null";
            if(sscanf(arg, "%s %s", monsterid, cmdcode) != 2)
            {            
                write("Your command was not understood.\n");
                return 1;
            }
        }
    }

    /* we cycle through our roster */
    for(i = 0; i < sizeof(my_roster); i ++)
    {

        if(my_roster[i] &&
           environment(my_roster[i]) &&
           my_roster[i]->query_string(STR_TEAM_NAME) == monsterid)
        {
           if(!execute_order(i, cmdcode, data, duration))
                write("An error occurred sending order to index [" + i + "].\n");
            else
                count ++;
        }
    }

    write("You have requested an order sent to all monsters of the team '" + monsterid + "'\n");
    write("The order was to '" + cmdcode + " " + data + "' for " + duration + " minutes.\n");
    write("Command " + arg + " executed and sent to " + count + " recipients.\n");
    write("Ok.\n");
    return 1;

}

on_ordertype(arg)
{
    int i;
    int count;
    int duration;
    object monster;
    string data;
    string cmdcode;
    string monsterid;

    if(!arg)
    {
        write("Usage:   ordertype <monstertype> <cmdcode> <data> <duration>\n\n");
        return 1;
    }

    /* parse out our command string. luckily we are expecting the same format
     * all the time. ALL the time.
     */
    if(sscanf(arg, "%s %s %s %d", monsterid, cmdcode, data, duration) != 4)
    {
        duration = 10;
        if(sscanf(arg, "%s %s %s", monsterid, cmdcode, data) != 3)
        {
            data = "null";
            if(sscanf(arg, "%s %s", monsterid, cmdcode) != 2)
            {            
                write("Your command was not understood.\n");
                return 1;
            }
        }
    }

    /* we cycle through our roster */
    for(i = 0; i < sizeof(my_roster); i ++)
    {

        if(my_roster[i] && environment(my_roster[i]) && my_roster[i]->id(monsterid))
        {
           if(!execute_order(i, cmdcode, data, duration))
                write("An error occurred sending order to index [" + i + "].\n");
            else
                count ++;
        }
    }

    write("You have requested an order sent to all monsters of type '" + monsterid + "'\n");
    write("The order was to '" + cmdcode + " " + data + "' for " + duration + " minutes.\n");
    write("Command " + arg + " executed and sent to " + count + " recipients.\n");
    write("Ok.\n");
    return 1;

}




/* translates text into valid command codes */
execute_order(monsternum, cmd, data, duration)
{
    object target;
    string cmdcode;
    int result;

    /* check for monster index */
    if(monsternum < 0 || monsternum >= sizeof(my_roster)) return 0;

    /* check our cmdcode */
    cmdcode = validate_cmdcode(cmd);
    if(cmdcode == 0) return 0;

    /* duration cannot be negative */
    if(duration < 0) return 0;

    switch(cmdcode)
    {

    case ORDERS_PESTER_OBJECT:
    case ORDERS_HEAL_OBJECT:
    case ORDERS_COVER_OBJECT:
    case ORDERS_HARRASS_OBJECT:
    case ORDERS_PROTECT_OBJECT:
    case ORDERS_HUNT_OBJECT:
    case ORDERS_KILL_OBJECT:
    case ORDERS_HOUND_OBJECT:
    case ORDERS_HITFADE_OBJECT:
    case ORDERS_EXPLODE_OBJECT:
    case ORDERS_STEALKILLS_OBJECT:

        target = obtain_target(data);
        receive_orders(my_roster[monsternum], cmdcode, target, duration);
        result = 1;
        break;

    case ORDERS_KILL_BY_NAME:
    case ORDERS_KILL_BY_IPADDR:
    case ORDERS_KILL_BY_GUILDNAME:
    case ORDERS_HOLD_POSITION:
    case ORDERS_DEFEND_SPOT:
    case ORDERS_LOITER:
    case ORDERS_HARRASS_NAME:
    case ORDERS_HITFADE_NAME:
    case ORDERS_EXPLODE_SPOT:
    case ORDERS_PILLAGECASTLE:
    case ORDERS_PILLAGELOITER:
    case ORDERS_STEALKILLS_NAME:
    case ORDERS_PESTER_NAME:
    case ORDERS_DISMISS:

        receive_orders(my_roster[monsternum], cmdcode, data, duration);
        result = 1;
        break;

    default:
        result = 0;
    }

    return result;

}


/* This simply takes a command code and returns a valid verb for it. */
validate_cmdcode(arg)
{

    if(arg == "harrass") return ORDERS_HARRASS_OBJECT;
    else if(arg == "protect") return ORDERS_PROTECT_OBJECT;
    else if(arg == "huntobj") return ORDERS_HUNT_OBJECT;
    else if(arg == "killobj") return ORDERS_KILL_OBJECT;
    else if(arg == "killname") return ORDERS_KILL_BY_NAME;
    else if(arg == "killip") return ORDERS_KILL_BY_IPADDR;
    else if(arg == "killguild") return ORDERS_KILL_BY_GUILDNAME;
    else if(arg == "hold") return ORDERS_HOLD_POSITION;
    else if(arg == "defend") return ORDERS_DEFEND_SPOT;
    else if(arg == "loiter") return ORDERS_LOITER;
    else if(arg == "dismiss") return ORDERS_DISMISS;
    else if(arg == "harrassip") return ORDERS_HARRASS_IP;
    else if(arg == "harrassname") return ORDERS_HARRASS_NAME;
    else if(arg == "hound") return ORDERS_HOUND_OBJECT;
    else if(arg == "hitfade") return ORDERS_HITFADE_OBJECT;
    else if(arg == "hitfadename") return ORDERS_HITFADE_NAME;
    else if(arg == "explode") return ORDERS_EXPLODE_OBJECT;
    else if(arg == "explodespot") return ORDERS_EXPLODE_SPOT;
    else if(arg == "pillagecastle") return ORDERS_PILLAGECASTLE;
    else if(arg == "pillageloiter") return ORDERS_PILLAGELOITER;
    else if(arg == "stealkills") return ORDERS_STEALKILLS_OBJECT;
    else if(arg == "stealkillsname") return ORDERS_STEALKILLS_NAME;
    else if(arg == "pestername") return ORDERS_PESTER_NAME;
    else if(arg == "pester") return ORDERS_PESTER_OBJECT;
    else if(arg == "cover") return ORDERS_COVER_OBJECT;
    else if(arg == "heal") return ORDERS_HEAL_OBJECT;
    else return 0;
}

        
/* we take a string and try to get an object with it */
obtain_target(arg)
{
    object ob;

    if(!arg) return 0;

    ob = find_player(arg);
    if(!ob) ob = find_living(arg);
   
    if(ob) return ob;
    else return 0;
}


capture_my_count()
{
    /* and then what we are doing is capturing new data and moving old data
     * to the 'old' pile 
     */

    current_player_count = sizeof(users());
    
}


clear_my_count()
{
    /* all we are doing is resetting our stats until the next heartbeat, */
    since_roster_additions = 0;
    since_roster_deletions = 0;
    since_combat_damage = 0;

}


on_rollcall()
{
    object room;
    object ob;
    int i;
    int count;
    string temp;

    
    write(HIY + ">> Roll call!\n\n" + NORM);

    for(i = 0; i < sizeof(my_roster); i ++)
    {
        ob = my_roster[i];

        if(ob && environment(ob))
        {
            /*     index             monstername            roomfile */
            temp = pad(i + ")", 4) + pad(ob->query_name(), 34) + object_name(environment(ob)) + ".\n";
            write(temp);
            count ++;
        }

    }
    write(HIY + "Total active monsters: " + count + "\n" + NORM);

    return 1;
}


on_monster_guild_who()
{
    object room;
    object ob;
    int i;
    int count;

    string rank;
    string position;
    string temp;
    string temp2;
    string temp3;
    string result;
    string tempname;
    string filename_room;

    write(">> Order#, Monster, Rank, and Position\n");

    for(i = 0; i < sizeof(my_roster); i ++)
    {
        ob = my_roster[i];

        if(ob && environment(ob))
        {
            /* get the filename of the room. we need this later. */
            filename_room = object_name(environment(ob));


            tempname = ob->query_name();
            if(tempname && strlen(tempname) > 30) tempname = extract(tempname, 0, 30);

            /*       index             name                     */
            result = pad(i + ")", 4) + pad(tempname, 32);
            
            temp = ob->query_monster_guild_rank();
            temp3 = "";

            /* colorize our chess piece */
            if(sscanf(temp, "Black %s", temp2) == 1)
            {
                /* Black */
                temp3 += BOLD + HIW + BBLK + pad(temp, 14) + NORM + NORM + NORM;
            }
            else if(sscanf(temp, "White %s", temp2) == 1)
            {
                /* white */
                temp3 += BOLD + HIK + HBWHT + pad(temp, 14) + NORM + NORM + NORM;
            }
            else 
                temp3 += HIY + pad(temp, 14) + NORM;

            result += temp3 + NORM + NORM + NORM + " ";
            

            /* we want to hide location if inside Boltar's UFO */
            if(sscanf(filename_room, "players/boltar/things/ufo%s", temp) == 1)
                result += "(location unknown)\n";
            else
            {
                tempname = environment(ob)->short();
                if(tempname && strlen(tempname) > 28) tempname = extract(tempname, 0, 28);
                result += tempname + NORM + NORM + NORM + "\n";
            }

            write(result);

            /* increment our counter */
            count ++;
        }

    }
    write(HIY + ">> Total active monsters: " + count + "\n" + NORM);

    return 1;
}


#define DISPLAYTYPE_GENERIC     1
#define DISPLAYTYPE_HEALTH      2
#define DISPLAYTYPE_COMPOSITE   3
#define DISPLAYTYPE_ATTRIBS     4
#define DISPLAYTYPE_GOLD        5
#define DISPLAYTYPE_TEAM        6

/* not finished */
on_statall(arg)
{
    object room;
    object ob;
    int i;
    int count;
    int displaytype;
    string title;
    string result;
    string tempname;
    string temp1;
    string temp2;
    string temp3;

    title = pad(">> Monster Name", 36);

    /* figure out our display type, and title */
    if(!arg) 
    {
        displaytype = DISPLAYTYPE_GENERIC;
        title += pad("Age", 20);
    }
    else if(arg == "h")
    {
        displaytype = DISPLAYTYPE_HEALTH;
        title += pad("HP", 10) + pad("MHP", 10);
        title += pad("QuotaUsed", 10) + pad("QuotaMax", 10);
    }
    else if(arg == "c")
    {
        displaytype = DISPLAYTYPE_COMPOSITE;
        title += pad("Composite", 10) + pad("AC", 6) + pad("WC", 6) + pad("Level", 6) + pad("EXP Worth", 12);
    }
    else if(arg == "a")
    {
        displaytype = DISPLAYTYPE_ATTRIBS;
        title += pad("Vind.", 6) + pad("Frl.", 6) + pad("Perc.", 6);
        title += pad("Cruel", 6) + pad("Ins.", 6) + pad("Genr.", 6);
    }
    else if(arg == "g")
    {
        displaytype = DISPLAYTYPE_GOLD;
        title += pad("Gold", 10);
        title += pad("InfuseAt", 10);
        title += pad("Infused", 10);
        title += pad("Corpses", 10);
    }
    else if(arg == "t")
    {
        displaytype = DISPLAYTYPE_TEAM;
        title += pad("Teamname", 20) + pad("Cabal", 20);
    }
    else
    {
        displaytype = DISPLAYTYPE_GENERIC;
        title += pad("Age", 20);
    }

    /* plop our title down */
    write(title + "\n");

    for(i = 0; i < sizeof(my_roster); i ++)
    {
        ob = my_roster[i];

        if(ob && environment(ob))
        {


            tempname = ob->query_name();
            if(tempname && strlen(tempname) > 30) tempname = extract(tempname, 0, 30);

            result = pad(i + ")", 4) + pad(tempname, 32);
            
            /* our conditions */
            switch(displaytype)
            {
            case DISPLAYTYPE_HEALTH:
                temp1 = pad(ob->query_hp(), 10) + pad(ob->query_mhp(), 10);
                temp1 += pad(ob->query_count(COUNT_HEAL_QUOTA), 10) + pad(ob->query_int(VAL_MAX_HEAL_QUOTA), 10);
                break;
            case DISPLAYTYPE_COMPOSITE:
                temp1 = pad(ob->query_composite(), 10) + pad(ob->query_ac(), 6) + pad(ob->query_wc(), 6);
                temp1 += pad(ob->query_level(), 6) + pad(ob->calculate_worth(), 12);
                break;
            case DISPLAYTYPE_ATTRIBS:
                temp1  = pad(ob->query_monster_attrib(ATTRIB_VINDICTIVENESS), 6);
                temp1 += pad(ob->query_monster_attrib(ATTRIB_FEARLESSNESS), 6);
                temp1 += pad(ob->query_monster_attrib(ATTRIB_PERCEPTION), 6);
                temp1 += pad(ob->query_monster_attrib(ATTRIB_CRUELTY), 6);
                temp1 += pad(ob->query_monster_attrib(ATTRIB_INSANITY), 6);
                temp1 += pad(ob->query_monster_attrib(ATTRIB_GENEROUSITY), 6);
                break;
            case DISPLAYTYPE_GOLD:
                temp1 = pad(ob->query_money(), 10);
                temp1 += pad(ob->query_int(VAL_INFUSE_POINT), 10);
                temp1 += pad(ob->query_count(COUNT_COINS_INFUSED), 10);
                temp1 += pad(ob->query_count(COUNT_CORPSES_LOOTED), 10);
                break;
            case DISPLAYTYPE_TEAM:
                temp1 = pad(ob->query_string(STR_TEAM_NAME), 20) + pad(ob->query_string(STR_CABAL_NAME), 20);
                break;
            default:
                break;
                temp1 = ob->query_age();
            }

            result += temp1 + "\n";

            write(result);


            /* increment our counter */
            count ++;
        }

    }

    write(HIY + ">> Total active monsters: " + count + "\n" + NORM);

    return 1;
}


/* living creatures will call on this method */
report_event(code, data)
{
    switch(code)
    {
    case EVENT_ARRIVAL:
        return process_arrival(data);
        break;
    case EVENT_DEPARTURE:
        return process_removal(data);
        break;
    }
}


/* we are expecting an object. */
process_arrival(data)
{

    /* no data, feh! */
    if(!data) return 0;

    /* add the monster to the list */
    roster_add(data);

    
}


/* we are expecting an object. */
process_removal(data)
{
    roster_remove(data);
}


/* the way i did the coverage maps is really ghetto.
 * The overall map contains an array.
 * Each element is also an array.
 * The first element of this sub array is the id of the monster that would be providing backup.
 * The second element of this sub-array is the id of the monster that would be 'in distress'
 */

/* Think of this function almost like a dating service. BAHAHAHA */
request_backup_for(arg)
{
    int i;
    int found_match;
    string name;

    if(!arg) return 0;

    /* we have already called for backup a little while ago... must wait */
    if(is_recharging_reserves)
    {
        report_message("I ordered backup already... Have to wait until reserves charge...\n");
        return 1;
    }

    name = arg->query_name();
    found_match = 0;

    /* we are looking through our coverage map to see who can assist 'arg' */
    for(i = 0; i < sizeof(my_roster); i ++)
    {
        /* we have to be an active member, and not ourselves */
        if(my_roster[i] && !found_match && environment(my_roster[i]) && my_roster[i] != arg)
        {
            /* if we are not currently fighting */
            if(!my_roster[i]->query_attack())
            {
                /* we have found a match */
                if(my_roster[i]->query_coverage_map() == name || my_roster[i]->query_coverage_map() == "all")
                {
                    report_message("I am sending " + my_roster[i]->query_name() + " to assist " + name + ".\n");
                    found_match = 1;
                    is_recharging_reserves = 1;
                    receive_orders(my_roster[i], ORDERS_PROTECT_OBJECT, arg, 10);
                    my_roster[i]->set_heart_beat(1);
                    my_roster[i]->heart_beat();

                    remove_call_out("recharge_reserves");
                    call_out("recharge_reserves", 360);
                   
                }

            }
            
        }
    }
    /* end for() */

    /* no date available */
    report_message(arg->query_name() + ", there are no available units that can scramble to protect you.\n");
    if(!is_ordering_backup)
    {
        report_message(HIB + "I am going to order for backup.\n" + NORM);

        is_ordering_backup = 1;
        is_recharging_reserves = 1;
        backup_protect = arg;
        
        remove_call_out("recharge_reserves");
        call_out("recharge_reserves", 60 - sizeof(users()));

        remove_call_out("order_backup");
        call_out("order_backup", 4);
    }

    return 0;
}

order_backup(arg)
{
    /* the creature we are supposed to help has died :( */
    if(!backup_protect)
    {
        report_message("Backup order cancelled :(\n");
        is_ordering_backup = 0;
        return 1;
    }

    report_message(HIB + "Goliath Beano has reported from reserves callup.\n" + NORM);
    backup = clone_object("/players/mizan/mbv2/beasties/goliathbeano.c");
    move_object(backup, environment(this_object()));

    remove_call_out("unleash_backup");
    call_out("unleash_backup", 3);
}

unleash_backup(arg)
{
    /* the creature we are supposed to help has died :( */
    if(!backup_protect)
    {
        report_message("Backup order cancelled :(\n");
        is_ordering_backup = 0;
        return 1;
    }

    if(!backup)
    {
        report_message("Backup has failed to show! WTF!\n");
        is_ordering_backup = 0;
        return 1;
    }

    report_message("Reinforcements have arrived for you, " + backup_protect->query_name() + ".\n");
    receive_orders(backup, ORDERS_PROTECT_OBJECT, backup_protect, 10);
    is_ordering_backup = 0;
    backup->set_heart_beat(1);
    backup->heart_beat();
    return 1;
}



/* used internally, usually. */
roster_add(arg)
{
    if(!arg) return;
    report_message(arg->query_name() + " is added to the roster.\n");
    
    /* increment the monsters that have joined us */
    since_roster_additions ++;
    my_roster += ({ arg, });
}


/* used internally, usually */
roster_remove(arg)
{
    if(!arg) return;
    report_message(arg->query_name() + " is removed from the roster.\n");

    /* increment our counters */
    since_roster_deletions ++;
    my_roster -= ({ arg, });

}

/* used internally... */
report_message(arg)
{
    object ob;
    object room;
    string message;
    int i;


    message = HIY + ">> " + HIR + "*" + HIY + "System.tactical" + NORM + NORM + " reports: " + arg;

    ob = users();

    for(i = 0; i < sizeof(ob); i ++)
    {
        if(ob[i]) /* added by verte */
        if(present(RADIO_ID, ob[i]))
            tell_object(ob[i], message);
    }

    tell_room(LISTENING_ROOM, message);
}


restore_self()
{
    if(!restore_object(TACTICAL_DM_SAVEFILE)) 
    {
        /* initialize mappings */
        if(!my_roster)
            my_roster = ({ });

        if(!my_observed_players)
            my_observed_players = ({ });

        save_object(TACTICAL_DM_SAVEFILE);
    }
  
}

save_self()
{
    save_object(TACTICAL_DM_SAVEFILE);
}

query_roster() { return my_roster; }


/* eof */
