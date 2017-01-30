/*
 * The purpose of this object is to house basic functionality used by the smart monsters.
 * Contents personal copyright Mizan@Nirvana, 2003.
 * Exclusive rights also to Boltar@Nirvana.
 * Reproduction on other muds restricted, under penalty of personal retribution.
 *
 */

#define IS_SOUL_DM
#include "definitions.h"
#include "router.h"

#include "/obj/ansi.h"
#include "/obj/user/shout_only.c"

/*  contains a pool of functions used by the monsters within the guild.
 *
 */

/* member variables */

id(str) { return str == "soul-daemon" || str == "server"; }

short() { return "A network server named (soul-daemon)"; }


reset(arg)
{
    if(arg) return;
    
    move_object(this_object(), DAEMON_HOME);
    report_message("System online. Function reset(" + arg + ") called.\n");

}


do_general_emote_buh(arg, arg2)
{
    object ob;
    ob = verify_emote_target(arg, arg2);

    if(ob)
    {
    }
    else
    {
    }

}

do_general_emote_fbog(arg, arg2)
{
    object ob;
    ob = verify_emote_target(arg, arg2);

    if(ob)
    {
    }
    else
    {
    }

}

do_goofy_emote_antlers(arg, arg2)
{
    object ob;
    ob = verify_emote_target(arg, arg2);

    if(ob)
    {
    }
    else
    {
    }

}

do_offensive_emote_fishbeat(arg, arg2)
{
    object ob;
    ob = verify_emote_target(arg, arg2);

    if(ob)
    {
    }
    else
    {
    }

}

do_offensive_emote_crotchkick(arg, arg2)
{
    object ob;
    ob = verify_emote_target(arg, arg2);

    if(ob)
    {
    }
    else
    {
    }

}


/* first arg is ourselves, second is a string of whatever we are supposed to emote target */
verify_emote_target(arg, arg2)
{
    object ob;
    object room;
    
    if(!arg) return;
    
    room = environment(arg2);
    ob = present(arg2, room);
    
    if(ob && living(ob) && ob != arg)
        return ob;
    else
        return 0;
    
}



/* used internally... */
report_message(arg)
{
    object ob;
    object room;
    string message;
    int i;


    message = HIY + ">> " + HIR + "*" + HIY + "System.soul" + NORM + NORM + " reports: " + arg;

    ob = users();

    for(i = 0; i < sizeof(ob); i ++)
    {
        if(present(RADIO_ID, ob[i]))
            tell_object(ob[i], message);
    }
    tell_room(LISTENING_ROOM, message);

}

/* eof */