/*****************************************************************************
 *      File:                   bullboard.c
 *      Function:               This bulletin board costs 500k coins to post 
 *                              on.
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:
 *      Change History:         DONE Initial revision - 09 Mar 2011
 ****************************************************************************/

#include "/obj/ansi.h"
#define DATAFILE "players/mizan/opl/data/bulletin_board"

string messages, new_hd, new_body;
int num_messages;
object who;

id(str) {
    return str == "board";
}

long() 
{
    write(HIY + 
        "    Standing before you is an extravagant, if not outrightly garish\n"+
        "  gold structure built in the style of Hector Guimard's Paris Metro \n"+
        "  entrance masterpieces. This bulletin board is unique in that it\n"+
        "  requires payment in order to leave a note, to the tune of 500,000\n"+
        "  gold coins per posting, payable via an electronic bank transaction.\n"+
        "  It's expensive, so you had better think about what you want to say.\n"+
        "  You can set up new notes with the command 'note headline'.\n"+
        "  Read a note with 'read num', and remove an old note with\n"+
        "  'remove num'.\n" + NORM);
    if (num_messages == 0) 
    {
        write("It is empty.\n");
        return;
    }
    write("The bulletin board contains " + num_messages);
    if (num_messages == 1)
        write(" note:\n\n");
    else
        write(" notes:\n\n");
    say(call_other(this_player(), "query_name") +
        " studies the bulletin board.\n");
    headers();
}

short()
{
    return (HIY + "A garish, freestanding bulletin board" + NORM + " [" + num_messages + "]");
}

get()
{
    return 0;
}

init() {
    add_action("new","note");
    add_action("read","read");
    add_action("remove","remove");
}

reset(arg) {
    if (arg) return;
    restore_object(DATAFILE);
}


headers() {
    string hd, body, rest;
    int i, tmp;

    i = 1;
    rest = messages;
    while (rest != 0 && rest != "") {
        tmp = sscanf(rest, "%s:\n**\n%s\n**\n%s", hd, body, rest);
        if (tmp != 2 && tmp != 3) {
            write("Corrupt.\n");
            return;
        }
        write(i + ":\t" + hd + "\n");
        i += 1;
    }
}

new(hd) 
{
    if (!hd)
        return 0;

    if((this_player()->query_bank_balance()) < 500000)
    {
        write("You don't have enough gold in your bank balance!\n");
        write("You currently have " + this_player()->query_bank_balance() + " coins in your account.\n");
        return 1;
    }

    if (who) 
    {
        write((who->query_name()) + " is busy writing.\n");
        return 1;
    }
    
    if (num_messages == 100) 
    {
        write("You have to remove an old message first.\n");
        return 1;
    }
    
    if (strlen(hd) > 50) 
    {
        write("The header is too long.\n");
        return 1;
    }

    who = this_player();
    say(who->query_name())+" begins writing a note and disappears into a fold of space.\n)";
    move_object(who, this_object());
    new_hd = hd;
    this_player()->add_bank_balance(-500000);

    input_to("get_body");
    write("You are inside a fold of space within the bulletin board.\n"+
          "All outside environment noise has been muffled.\n"+
          "Give message, and terminate with '**'.\n");
    write("]");
    new_body = "";
    return 1;
}

get_body(str) 
{
    if (str == "**") 
    {
        new_hd = new_hd + "[" + capitalize(this_player()->query_real_name()) + ", "
        + ctime() + "]";
        messages = messages + new_hd + ":\n**\n" + new_body + "\n**\n";
        num_messages += 1;
        new_body = 0;
        new_hd = 0;
        save_object(DATAFILE);
 
        say((who->query_name())+" finishes writing a note and fades into view.\n");
        move_object(who, environment(this_object()));
        write("Done.\n");
        who = 0;
        return;
    }
    new_body = new_body + str + "\n";
    write("]");
    input_to("get_body");
}

read(str) 
{
    string hd, body, rest;
    int i, tmp;

    if (str == 0 || (sscanf(str, "%d", i) != 1 &&
                     sscanf(str, "note %d", i) != 1))
        return 0;
    if (i > num_messages) 
    {
        write("Not that number of messages.\n");
        return 1;
    }

    rest = messages;
    while (rest != 0 && rest != "") 
    {
        i -= 1;
        tmp = sscanf(rest, "%s:\n**\n%s\n**\n%s", hd, body, rest);

        if (tmp != 2 && tmp != 3) 
        {
            write("Corrupt.\n");
            return;
        }

        if (i == 0) 
        {
            say(call_other(this_player(), "query_name") +
                " reads a note titled '" + hd + "'.\n");
            write("The note is titled:\n'" + hd + "':\n\n");
            write(HIY + body + NORM);
            return 1;
        }
    }
    write("Hm. This should not happen.\n");
}

remove(str) 
{
    string hd, body, rest;
    int i, tmp;

    if(this_player()->query_level() < 21)
    {
        write("Sorry, unfortunately this is only something wizards can do.\n");
        return 1;
    }

    if (str == 0 || (sscanf(str, "%d", i) != 1 &&
                     sscanf(str, "note %d", i) != 1))
        return 0;

    if (i > num_messages) 
    {
        write("Not that number of messages.\n");
        return 1;
    }

    rest = messages;
    messages = "";

    while (rest != 0 && rest != "") 
    {
        i -= 1;
        tmp = sscanf(rest, "%s:\n**\n%s\n**\n%s", hd, body, rest);

        if (tmp != 2 && tmp != 3) 
        {
            write("Corrupt.\n");
            return;
        }

        if (i == 0) 
        {
            say(call_other(this_player(), "query_name") +
                " removed a note titled '" + hd + "'.\n");
            write("Ok.\n");
            messages = messages + rest;
            num_messages -= 1;
            save_object(DATAFILE);
            return 1;
        }

        messages = messages + hd + ":\n**\n" + body + "\n**\n";
    }
    write("Hm. This should not happen.\n");
}

