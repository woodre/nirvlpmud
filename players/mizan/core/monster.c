/** \brief modified monster.c
 * a modified monster object, mainly to give us some extra
 * logging capabilites.
 */

inherit "/obj/monster.c";
#include "definitions.h"

/* member variables */
string my_tracking_name;

string *my_combat_history;

object my_attacker;

int my_highest_damage;

int my_total_rounds;

int my_tracking_number;

status is_tracking;

/* \brief overloaded reset
 */
reset(arg)
{

    if(!my_combat_history) my_combat_history = ({});
    ::reset(arg);

    if(arg) return;

    is_tracking = 0;
    my_total_rounds = 0;
    my_highest_damage = 0;

    OBJECTDM->report_creation(this_object());
    tell_room(LISTENING_ROOM, "Monster.c reports: " + object_name(this_object()) + " has been cloned.\n"); 
/*    tell_room(LISTENING_ROOM, (this_object()->short()) + " reporting for duty!\n"); */

}

/* \brief overloaded heartbeat
 */
heart_beat()
{
    if(attacker_ob && attacker_ob != my_attacker)
    {
        if(!is_tracking &&
            attacker_ob->query_real_name() &&
            OBJECTDM->match_player(attacker_ob->query_real_name()))
        {
            start_tracking_to_disk(attacker_ob->query_real_name());
        }
        my_attacker = attacker_ob;
    }

    if(is_tracking && attacker_ob) add_combat_history();

    ::heart_beat();

}

void add_combat_history()
{
    /* i figured this code should have been inlined instead of daemonized. */
    string temp;

    my_total_rounds ++;

    temp = ctime() + " ";

    /* if we have an environment, get more info about it */
    if(attacker_ob)
    {
        temp += "HP: " + this_object()->query_hp() + "/" + this_object()->query_mhp() + " ";
        temp += "AHP: " + attacker_ob->query_hp() + "/" + attacker_ob->query_mhp() + " ";
        temp += "AName: " + attacker_ob->query_name() + " (" + attacker_ob->query_real_name() + " ";
    }
    else temp += "[no attacker]";

    temp += "\n";

    /* if we have been told to, write to file. */
    if(is_tracking)
    {
        write_file("/players/mizan/logs/monster." + my_tracking_name + "." + my_tracking_number, temp);
        tell_room(LISTENING_ROOM, "Monster.c reports: Log file monster." + my_tracking_name + "." + my_tracking_number + " has updated combat record.\n"); 
    }

    /* if we are empty, we initialize ourselves */
    if(!my_combat_history) my_combat_history  = ({});

    /* bump the buffer if we are too large */
    if(sizeof(my_combat_history) == MAX_COMBAT_HISTORY)
    {
        my_combat_history -= ({ my_combat_history[0] });
    }
    
    my_combat_history += ({ temp, });
}


/* this returns a string describing how well we have been fighting */
string query_combat_history()
{
    int i, a;
    string msg;

    msg = "\nCombat History for: " + object_name(this_object()) + "\n\n";

    for(i = 0, a = sizeof(my_combat_history); i < a; i++)
    {
        msg += my_combat_history[i];
    }

    msg += "\n";
    return msg;
}


/* start dumping to disk! */
start_tracking_to_disk(string str)
{
    string temp;

    /* we tell ourselves to start tracking */
    is_tracking = 1;

    /* generate a random index number */
    my_tracking_number = random(50000);

    my_tracking_name = str;

    tell_room(LISTENING_ROOM, "Monster.c reports: " + object_name(this_object()) + " has reporting to monster." + my_tracking_number + ".\n"); 
    
    write_file("/players/mizan/logs/monster." + my_tracking_name + "." + my_tracking_number, query_combat_history());

    /* write our output to the index file too. */
    temp = ctime() + " '" + this_object()->short() + "', monster." + my_tracking_name + "." + my_tracking_number + "\n";
    
    write_file("/players/mizan/logs/objectindex." + my_tracking_name, temp);

}

/* todo - write finishing info here */
death()
{
    string temp;
    string attacker_name;

    tell_room(LISTENING_ROOM, "Monster.c reports: " + object_name(this_object()) + " has died.\n"); 
/*    if(attacker) attacker_name = attacker->query_name();
    tell_room(LISTENING_ROOM, (this_object()->short()) + " was killed by " + capitalize(attacker_name) + ".\n");*/
    
    if(is_tracking)
    {
        temp = "\nEnd of report for " + object_name(this_object()) + "\n";
        temp += "Creature killed in " + my_total_rounds + " combat rounds at " + ctime() + "\n";
        write_file("/players/mizan/logs/monster." + my_tracking_name + "." + my_tracking_number, temp);
    }

    ::death();
}
