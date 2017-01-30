/*
 * The purpose of this object is to house basic functionality used by the smart monsters.
 * Contents personal copyright Mizan@Nirvana, 2003.
 * Exclusive rights also to Boltar@Nirvana.
 * Reproduction on other muds restricted, under penalty of personal retribution.
 *
 */

#define IS_SADISTIC_DM
#include "definitions.h"
#include "router.h"

#include "/obj/ansi.h"
#include "/obj/user/shout_only.c"

/*  contains a pool of functions used by the monsters within the guild.
 *
 */

/* member variables */

id(str) { return str == "sadistic-daemon" || str == "server"; }

short() { return "A network server named (sadistic-daemon)"; }


reset(arg)
{
    if(arg) return;
    
    move_object(this_object(), DAEMON_HOME);
    report_message("System online. Function reset(" + arg + ") called.\n");

}




/* used internally... */
report_message(arg)
{
    object ob;
    object room;
    string message;
    int i;


    message = HIY + ">> " + HIR + "*" + HIY + "System.sadistic" + NORM + NORM + " reports: " + arg;

    ob = users();

    for(i = 0; i < sizeof(ob); i ++)
    {
        if(present(RADIO_ID, ob[i]))
            tell_object(ob[i], message);
    }
    tell_room(LISTENING_ROOM, message);

}

/* eof */