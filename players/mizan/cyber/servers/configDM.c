/*
 * Used by the new CN guild.
 * Contents personal copyright Mizan@Nirvana, 2003, 2004.
 * Exclusive rights also to Boltar@Nirvana.
 * Reproduction on other muds restricted, under penalty of law and personal retribution.
 *
 */


#define IS_CONFIG_DM

/* our include files. */
#include "../config.h"
#include "../router.h"
#include "../definitions.h"
#include "/obj/ansi.h"


/* 
 *
 */

/* member variables */

id(str) { return str == "config_server"; }

short() { return "An IBM RS/6000 named 'config_server'"; }

long()
{
    write("This is a compact, black box server with a single sticker on it\n"+
          "indicating its name, but nothing else discernably marking it.\n");
}

reset(arg)
{
    if(arg) return;
    
    restore_self(); 
    move_object(this_object(), DAEMON_HOME);
    report_message("System online. Function reset(" + arg + ") called.\n");

}


void restore_self()
{
    if(!restore_object(CONFIG_DM_SAVEFILE)) 
    {
        /* initialize vars */

        save_object(CONFIG_DM_SAVEFILE);
    }
    

    /* any extra init that may need to happen */
}

void save_self()
{
    save_object(CONFIG_DM_SAVEFILE);
}


/* used internally... */
report_message(arg)
{
    object ob;
    object room;
    string message;
    int i;


    message = HIY + ">> " + HIR + "*" + HIY + "System.config" + NORM + NORM + " reports: " + arg;

/*
    ob = users();

    for(i = 0; i < sizeof(ob); i ++)
    {
        if(present(RADIO_ID, ob[i]))
            tell_object(ob[i], message);
    }
*/
    tell_room(LISTENING_ROOM, message);

}

/* eof */