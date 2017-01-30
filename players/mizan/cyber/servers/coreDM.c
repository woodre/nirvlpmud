/*
 * Used by the new CN guild.
 * Contents personal copyright Mizan@Nirvana, 2003, 2004.
 * Exclusive rights also to Boltar@Nirvana.
 * Reproduction on other muds restricted, under penalty of law and personal retribution.
 *
 */


/*
 * coreDM.c
 *
 * This object is a daemon which contains nothing but core-level functionality for the
 * rest of the guild. We're talking really low level stuff like color, file, display
 * sort of things.
 *
 */
#define IS_CORE_DM

/* our include files. */
#include "../config.h"
#include "../router.h"
#include "../definitions.h"
#include "/obj/ansi.h"


/* 
 *
 */

/* member variables */

id(str) { return str == "core_server"; }

short() { return "An IBM RS/6000 named 'core_server'"; }

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
    if(!restore_object(CORE_DM_SAVEFILE)) 
    {
        /* initialize vars */

        save_object(CORE_DM_SAVEFILE);
    }
    

    /* any extra init that may need to happen */
}

void save_self()
{
    save_object(CORE_DM_SAVEFILE);
}


/* used internally... */
report_message(arg)
{
    object ob;
    object room;
    string message;
    int i;

    message = HIY + ">> " + HIR + "*" + HIY + "System.core" + NORM + NORM + " reports: " + arg;
    tell_room(LISTENING_ROOM, message);
}

/* functions start here! */


/*
 * While ANSI_replace() is designed for just single tokens, this function takes
 * an entire string with spaces and deals with all the tokenizing.
 *
 * originally vertebraker's
 *
 */
ANSI_filter(str)
{
    int s; 
    string *words;

    if(!str) return str;
    s = sizeof(words = explode(str, "$"));

    while(s--)
    {
        if(ANSI_replace(words[s]))
            words[s] = ANSI_replace(words[s]);
    }

    str = (implode(words, "")) + ESC + "[0m";
    return str;
}


/**
 * This replaces ANSI tokens with their real escape keyed counterparts.
 * It is meant to be called internally by ANSI_filter().
 * But it has been available for use anyhow.
 *
 * originally vertebraker's 
 *
 */
ANSI_replace(word)
{
    string z;

    if(!word) return word;

    switch(word)
    {
        case "-":  z = ESC + "[0m"; break;
        case "H":  z = ESC + "[1m"; break;
        case "K":  z = ESC + "[30m"; break;
        case "R":  z = ESC + "[31m"; break;
        case "G":  z = ESC + "[32m"; break;
        case "Y":  z = ESC + "[33m"; break;
        case "B":  z = ESC + "[34m"; break;
        case "M":  z = ESC + "[35m"; break;
        case "C":  z = ESC + "[36m"; break;
        case "W":  z = ESC + "[37m"; break;
        case "N":  z = ESC + "[2;37;0m"; break;
        case "HK": z = ESC + "[1;30m"; break;
        case "HR": z = ESC + "[1;31m"; break;
        case "HG": z = ESC + "[1;32m"; break;
        case "HY": z = ESC + "[1;33m"; break;
        case "HB": z = ESC + "[1;34m"; break;
        case "HM": z = ESC + "[1;35m"; break;
        case "HC": z = ESC + "[1;36m"; break;
        case "HW": z = ESC + "[1;37m"; break;
    }
    
    if(!z) return word;
    return z;
}

/**
 * The purpose of this function is to provide a smarter core 'write' functionality.
 * It understands a variety of tokens. For more info, you will want to reference
 * the brief comments in this function...
 *
 *
 */
void cwrite(string arg)
{

}
















/* eof */