/*
 * The purpose of this object is to house basic functionality used by the smart monsters.
 * Contents personal copyright Mizan@Nirvana, 2003.
 * Exclusive rights also to Boltar@Nirvana.
 * Reproduction on other muds restricted, under penalty of personal retribution.
 *
 */

#define IS_NEXUS_DM
#include "definitions.h"
#include "router.h"
#include "/obj/ansi.h"



/* 
 *
 */

/* member variables */
int my_coins;
int is_balance_stated; /* keeps balance from being printed more than once every 10 seconds */

id(str) { return str == "nexus"; }

short() { return "The Nexus of Power"; }

long()
{
    write("This is the thing i am using to store all of the monster's guild\n"+
          "power from looting castles and such.\n");
    write("There are " + my_coins + " coins stored in the nexus.\n");
}

reset(arg)
{
    if(arg) return;
    
    restore_self(); 
    move_object(this_object(), DAEMON_HOME);
    report_message("System online. Function reset(" + arg + ") called.\n");

}


query_balance()
{
    return my_coins;
}


/* We are asking the nexus to heal us */
request_healing(mon, hp)
{
    object room;
    int heal_cost;

    if(!mon) return 0;
    if(!hp || hp < 0) return 0;

    room = environment(mon);
    if(!room) return 0;

    /* 15 coins per hp */
    heal_cost = hp * 15;
    if(heal_cost > my_coins) return 0;

    tell_room(room, mon->short() + " withdraws credits from the Operational Nexus.\n");
    tell_room(room, mon->short() + " is bathed in a healing " + HIM + "pink" + NORM + " laser...\n");
    mon->heal_me(hp);
    my_coins -= heal_cost;

    tell_room(DAEMON_HOME, heal_cost + " coins are spent healing " + mon->query_name() + " " + hp + " hitpoints...\n");
    tell_room(LISTENING_ROOM, "NexusDM.c reports: " + heal_cost + " coins are spent healing " + mon->query_name() + " " + hp + " hitpoints...\n");
    report_balance();

    return 1;
}

add_nexus_coins(arg)
{
    if(!arg) return;
    if(arg < 0) return;

    my_coins += arg;

    /* we get a LOT we tell to the guild channel */
    if(arg > 10000)
        report_message(arg + " more coins have been infused!\n");
    
    tell_room(DAEMON_HOME, "You see " + arg + " more coins flow into the nexus.\n");
    tell_room(LISTENING_ROOM, "NexusDM.c reports: You see " + arg + " more coins flow into the nexus.\n");

    report_balance();
    save_self();
}

/* we take all off the monster's inventory and fill the nexus up with coins */
/* arg2 is used if we are to destruct our entire inventory, i.e. being dismissed. */
process_inventory(arg, arg2)
{
    object ob;
    object oc;
    object room;
    object storeroom;

    int i;
    int total_value;

    if(!arg || !arg->fellow_monster()) return;

    ob = first_inventory(arg);
    room = environment(arg);
    if(!room) return;

    storeroom = find_object("/players/mizan/opl/ROOMS/storeroom.c");

    while(ob)
    {
        oc = ob;
        ob = next_inventory(ob);

        if(creator(oc) && creator(oc) != "mizan")
        {
            i = oc->query_value();
            if(i < 1) i = 0;

            /* cap our value */
            if(i > 1000) i = 1000;

            /* we add up the value... */
            total_value += i;
            if(i > 0)
            {
                /* and then destroy the object */
                if(oc->short())
                {
                    tell_room(room, oc->short() + " is offered by " + arg->query_name() + " to the Operational Nexus.\n");
 /*
 tell_room(room, oc->short() + " disappears from " + arg->query_name() + "'s inventory.\n");
  */
                }
                if(storeroom) move_object(oc, storeroom);
                else destruct(oc);
            }
            /* we zok zero value items as well */
            else
            {
                tell_room(room, oc->short() + " is disintegrated by an orbital "+ HIM + "pink" + NORM + " laser.\n");
                destruct(oc);
            }

        }
        if(arg2 && oc)
        {
            tell_room(room, oc->short() + " is returned on lease to Mizan.\n");
            if(storeroom) move_object(oc, storeroom);
            else destruct(oc);
        }

    }

    if(total_value > 0) 
    {
        /* we get a LOT we tell to the guild channel */
        if(total_value > 10000)
            report_message(arg->query_name() + " has infused " + total_value + " more coins from equipment!\n");
        
        tell_room(DAEMON_HOME, "You see equipment flow into the nexus and turn into " + total_value + " coins.\n");
        tell_room(LISTENING_ROOM, "NexusDM.c reports: Equipment flows into the nexus and turn into " + total_value + " coins.\n");
        my_coins += total_value;

        /* reimburse the monster in heal quota since they gave to us */
        arg->set_count(COUNT_HEAL_QUOTA, -(total_value * 60));


        report_balance();

        save_self();
    }

}

report_balance()
{
    if(my_coins >= MAXIMUM_BALANCE)
        my_coins = MAXIMUM_BALANCE;

    tell_room(DAEMON_HOME, "Current nexus balance is " + my_coins + " coins.\n");
    tell_room(LISTENING_ROOM, "NexusDM.c reports: Current balance is " + my_coins + " coins.\n");

    if(is_balance_stated) return;

    is_balance_stated = 1;

    if(my_coins >= MAXIMUM_BALANCE)
        report_message("Our coin balance is at maximum! Excellent!\n");
    else
        report_message("Our coin balance is at " + (my_coins * 100) / MAXIMUM_BALANCE + "% level!\n");

    remove_call_out("clear_balance_stated_flag");
    call_out("clear_balance_stated_flag", 5);
}

clear_balance_stated_flag()
{
    is_balance_stated = 0;
}


void restore_self()
{
    /* initialize vars */
    if(!my_coins) my_coins = 900000;
    
    report_balance();
  
}

void save_self()
{
    save_object(NEXUS_DM_SAVEFILE);
}


/* used internally... */
report_message(arg)
{
    object ob;
    object room;
    string message;
    int i;


    message = HIY + ">> " + HIR + "*" + HIY + "System.nexus" + NORM + NORM + " reports: " + arg;

    ob = users();

    for(i = 0; i < sizeof(ob); i ++)
    {
        if(present(RADIO_ID, ob[i]))
            tell_object(ob[i], message);
    }
    tell_room(LISTENING_ROOM, message);

}

/* eof */
