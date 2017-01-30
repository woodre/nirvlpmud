/**
 * objectDM.c
 *
 * This is an object daemon. It's existence is to make basic functions for
 * all sorts of objects easier. The idea for this thing is to be able to keep
 * track of all sorts of objects cloned, and their properties.
 *
 *
 */
#include "definitions.h"

#define HOME "/players/mizan/core/home"
#define SAVEFILE "players/mizan/core/objectDM-SAVEFILE"

/* member variables */

/* the individuals we want to pay specific attention to */
string *observed_players;

/* the IP networks that we want to pay specific attention to */
string *observed_tcpipblocks;

/* the top 1000 objects that we are tracking */
static object *current_objects;

/* the creation info of the top 1000 objects that we are tracking */
static string *current_objectnames;

static string *current_objectdates;

/* our current position in the index */
static int cursor;


/* methods */
status id(string str) { return str == "mainframe" || str == "computer"; }

string short() { return "A giant black mainframe computer"; }

void long()
{
    if(this_player()->query_level() < 20)
    {
        write("There appears to be writing on a sticker on the mainframe, but\n"+
              "you have no idea how yo translate it. Waaaay too complex.\n");
    }
    else
    {
        write("This is the S390 G5 mainframe that is keeping track of all the\n"+
              "objects being cloned and distributed in /players/mizan.\n\n");

        write("This is version V0M0R3 (0.0.3)\n");
        write("In order to use it, give the following commands:\n\n");
        write("  dumpall            Dumps a listing of all objects being tracked.\n\n");
        write("  dumpplayers        Dumps a listing of all players being tracked.\n\n");
        write("  dumpips            Dumps a listing of all IP address ranges being tracked.\n\n");
        write("  dumpactive         Dumps a listing of all objects being tracked plus owners.\n\n");
        write("  printnum <num>     Prints the object history of item <num>\n");
        write("                     that was referenced in the 'dumpall' command.\n\n");
        write("  printname <fn>     Prints the object history of the item matching\n");
        write("                     a fully formed filename- i.e. '/obj/torch#0404'.\n\n");
        write("  observe <plyr>     Observe the player named <plyr>.\n\n");
        write("  unobserve <plyr>   Stop observing the player named <plyr>.\n\n");
        write("  observeip <ip>     To start watching a specific TCP/IP range. Note that IP\n"+
              "                     ranges do not follow Cisco subnet notations. Wildcards\n"+
              "                     are used but you MUST specify the left-hand side.\n\n");
        write("  unobserveip <ip>   To stop watching a specific TCP/IP range. Note that IP\n"+
              "                     ranges do not follow Cisco subnet notations. Wildcards\n"+
              "                     are used but you MUST specify the left-hand side.\n\n");
        write("  objindex <plyr>    To see the index of data collected for a player.\n\n");
        write("  objlog <plyr>.<#>  This is a tricky command. It shows everything recorded\n");
        write("                     for an object. You would want to take the info collected\n");
        write("                     after an index, for example 'mizan.40404' and give that\n");
        write("                     as a command here to see the file. For example:\n");
        write("                     'objlog mizan.40404'.\n\n");
    }
}

int get() { return 0; }


void reset(int arg)
{
    /* move ourselves home. */
    move_object(this_object(), HOME);

    this_object()->restore_self();
}

void init()
{
    if(this_player() && this_player()->query_level() > 19)
    {
        add_action("on_dump_everything", "dumpall");
        add_action("on_dump_players", "dumpplayers");
        add_action("on_dump_ips", "dumpips");
        add_action("on_printnum", "printnum");
        add_action("on_printname", "printname");
        add_action("on_dumpactive","dumpactive");

        add_action("on_observe", "observe");
        add_action("on_unobserve", "unobserve");
        add_action("on_observe", "register");
        add_action("on_unobserve", "unregister");

        add_action("on_observeip", "observeip");
        add_action("on_unobserveip", "unobserveip");
        add_action("on_observeip", "registerip");
        add_action("on_unobserveip", "unregisterip");

        add_action("on_objlog", "objlog");
        add_action("on_objindex", "objindex");
    }
}

int on_dumpactive()
{
    int i, a;
    object ob;
    string msg, temp;

    msg = "\nObject Dump called by " + this_player()->query_name() + " at " + ctime() + "\n\n";

    for(i = 1, a = sizeof(current_objects); i < a; i++)
    {
        ob = current_objects[i];
        if(ob && environment(ob))
        {
            /* the object has an environment */
            if(living(environment(ob)))
                temp = "(" + environment(ob)->query_real_name() + ")";
            else
                temp = "(" + environment(ob)->short() + ")";


            msg += i  + ")\t" + temp + " " +  current_objectnames[i] + "\n"; 
            write(msg);
            msg = "";
        }
    }
    
    say(this_player()->query_name() + " does an object dump from the mainframe.\n");
    return 1;
}

/* this is a kludge */
int on_objlog(string str)
{
    write("Attempting to display information... tailing file...\n");
    write("Tail contents of /players/mizan/logs/object." + str + "\n\n");
    tail("/players/mizan/logs/object." + str);
    write("\nDone.\n");
    say(this_player()->query_name() + " does an object view from the mainframe for 'object" + str + "'.\n");
    return 1;
}


/* this is a kludge */
int on_objindex(string str)
{
    write("Attempting to display information... tailing file...\n\n");
    write("Tail contents of /players/mizan/logs/objectindex." + str + "\n\n");
    tail("/players/mizan/logs/objectindex." + str);
    write("\nDone.\n");
    say(this_player()->query_name() + " does an object index from the mainframe on '" + str + "'.\n");
    return 1;
}


/** \brief called by objects when they clone. 
 */
void report_creation(object ob)
{

    if (!ob) return;

    /* bump the buffer if we are too large */
    if(sizeof(current_objects) == 200)
    {
        current_objectnames -= ({ current_objectnames[0] });
        current_objects -= ({ current_objects[0] });
        current_objectdates -= ({ current_objectdates[0] });
    }
    
    if (!current_objects)
      current_objects = ({ ob });
    else
      current_objects += ({ ob });
    if (!current_objectnames) 
     current_objectnames = ({ object_name(ob) });
    else
      current_objectnames += ({ object_name(ob), });
    if (!current_objectdates)
      current_objectdates = ({ ctime() });
    else
      current_objectdates += ({ ctime(), });
    
    cursor ++;
    if(cursor == 200) cursor = 200;
    
}

/** \brief Dumps all objects that are being currently tracked.
 *  or more accurately only the most recent 1000.
 *
 */
int on_dump_everything()
{
    int i, a;
    string msg;

    msg = "\nObject Dump called by " + this_player()->query_name() + " at " + ctime() + "\n\n";

    for(i = 1, a = sizeof(current_objects); i < a; i++)
    {
        msg += i  + ")\t" + current_objectdates[i] + " " +  current_objectnames[i] + "\n"; 
        write(msg);
        write_file("/players/mizan/logs/objectdump.txt", msg);
        msg = "";
    }
    
    say(this_player()->query_name() + " does an object dump from the mainframe.\n");
    write("Output also appended to /players/mizan/logs/objectdump.txt\nDone.\n");
    return 1;
}


int on_dump_players()
{
    int i, a;
    string msg;
    
    msg = "Current players being observed:\n\n";

    for(i = 0, a = sizeof(observed_players); i < a; i++)
    {
        msg += i  + ")\t" + observed_players[i] + "\n";
        write(msg);
        msg = "";
    }

    say(this_player()->query_name() + " does a player dump from the mainframe.\n");
    write("\nDone.\n");
    return 1;
}

int on_dump_ips()
{
    int i, a;
    string msg;
    
    msg = "Current IP ranges being observed:\n\n";

    for(i = 0, a = sizeof(observed_tcpipblocks); i < a; i++)
    {
        msg += i  + ")\t" + observed_tcpipblocks[i] + "\n";
        write(msg);
        msg = "";
    }

    say(this_player()->query_name() + " does an IP dump from the mainframe.\n");
    write("\nDone.\n");
    return 1;
}

/** \brief prints the history of an object to screen.
 */
int on_printnum(string arg)
{
    int i;
    object ob;

    if(!arg) return 1;
    if(sscanf(arg, "%d", i) == 1)
    {
        ob = current_objects[i];

        if(i >= sizeof(current_objects) || i < 0)
        {
            write("Invalid object number given.\n");
            return 1;
        }

        if(ob)
        {
            write(ob->query_move_history());
            say(this_player()->query_name() + " has requested from the mainframe object reference #" +  arg + ".\n");
            return 1;
        }
        else
        {
            write("Unfortunately object index [" + i + "] (" + current_objectnames[i] + ") is unresolved.\n");
            return 1;
        }
    }
    

    return 1;
}


/** \brief prints the history of an object to screen.
 * DOES NOT WORK YET
 */
int on_printname(string arg)
{
    int i;
    object ob;

    if(!arg) return 1;
    
    i = (int) this_object()->match_by_objectname(arg);

    if(i)
    {

        ob = current_objects[i];

        if(ob)
        {
            write(ob->query_move_history());
            say(this_player()->query_name() + " has requested from the mainframe object file " + arg + ".\n");
            return 1;
        }
        else
        {
            write("Unfortunately object index [" + i + "] (" + current_objectnames[i] + ") is unresolved.\n");
            return 1;
        }
    }

    write("No object matching filename '" + arg + "' was found.\n");

    return 1;
}


int on_observe(string arg)
{
    if(!arg)
    {
        write("Usage:\n    observe <playername>  to begin tracking object flow for said player.\n");
        return 1;
    }
    
    if(this_object()->match_player(arg))
    {
        write("That person is already being observed.\n");
        return 1;
    }

    this_object()->observe_player(arg);

    say(this_player()->query_name() + " has requested from the mainframe observance of player '"  +  arg + "'.\n");
    write("'" + arg + "' has been added to the observed list.\n");
    write("Done.\n");
    this_object()->save_self();

    return 1;
}


int on_unobserve(string arg)
{
    if(!arg)
    {
        write("Usage:\n    unobserve <playername>  to stop tracking object flow for said player.\n");
        return 1;
    }
    
    if(!this_object()->match_player(arg))
    {
        write("That person was not being observed at all.\n");
        return 1;
    }

    this_object()->stop_observe_player(arg);

    say(this_player()->query_name() + " has requested from the mainframe unobservance of player '"  +  arg + "'.\n");
    write("'" + arg + "' has been removed from the observed list.\n");
    write("Done.\n");
    this_object()->save_self();
    
    return 1;
}


int on_observeip(string arg)
{
    if(!arg)
    {
        write("Usage:\n    observeip <IPADDR>    To start watching a specific TCP/IP range. Note that IP\n"+
              "                                  ranges do not follow Cisco subnet notations. Wildcards\n"+
              "                                  are used but you MUST specify the left-hand side.\n"+
              "\n");
        write("For example, these are valid address ranges to observe:\n\n"+
              "192.168.0       (192.168.0.0/16)\n"+
              "10              (10.0.0.0/8)\n"+
              "209.109.36      (209.109.36.0/24)\n"+
              "192.155.4.1     (192.155.4.1/32 - an exact match)\n\n"+
              "The following are NOT valid addresses:\n\n"+
              "*.144.3.4,      191.*.191.0\n\n");
        return 1;
        return 1;
    }
    
    if(this_object()->match_ipaddr(arg))
    {
        write("That address range is already being observed.\n");
        return 1;
    }

    this_object()->observe_ips(arg);

    say(this_player()->query_name() + " has requested from the mainframe observance of IP range '"  +  arg + "*'.\n");
    write("IP range '" + arg + "*' has been added to the observed list.\n");
    write("Done.\n");
    this_object()->save_self();

    return 1;
}

int on_unobserveip(string arg)
{
    if(!arg)
    {
        write("Usage:\n    unobserveip <IPADDR>  To stop watching a specific TCP/IP range. Note that IP\n"+
              "                                  ranges do not follow Cisco subnet notations. Wildcards\n"+
              "                                  are used but you MUST specify the left-hand side.\n"+
              "\n");
        write("For example, these are valid address ranges to observe:\n\n"+
              "192.168.0       (192.168.0.0/16)\n"+
              "10              (10.0.0.0/8)\n"+
              "209.109.36      (209.109.36.0/24)\n"+
              "192.155.4.1     (192.155.4.1/32 - an exact match)\n\n"+
              "The following are NOT valid addresses:\n\n"+
              "*.144.3.4,      191.*.191.0\n\n");
        return 1;
    }
    
    if(!this_object()->match_ipblock(arg))
    {
        write("That address range was not being observed at all.\n");
        return 1;
    }

    this_object()->stop_observe_ips(arg);

    say(this_player()->query_name() + " has requested from the mainframe unobservance of IP text matching '"  +  arg + "*'.\n");
    write("IP address range '" + arg + "*' has been removed from the observed list.\n");
    write("Done.\n");
    this_object()->save_self();
    
    return 1;
}






void restore_self()
{
    if(!restore_object(SAVEFILE)) 
    {
        /* initialize mappings */
        if(!current_objects) current_objects = ({});
        if(!current_objectnames) current_objectnames = ({});

        cursor = 0;

        /* initialize player mappings */
        if(!observed_players) observed_players = ({});

        save_object(SAVEFILE);
    }
  
}

void save_self()
{
    save_object(SAVEFILE);
}


/** \brief This is called when we want to add a player to the list to observe.
 *
 */
void observe_player(string arg)
{
    if(!arg) return;
    observed_players += ({ arg, });
}


/** \brief unsubscribes the player from the list.
 */
void stop_observe_player(string arg)
{
    if(!arg) return;
    observed_players -= ({ arg, });
}

/** \brief This is called when we want to add a player to the list to observe.
 *
 */
void observe_ips(string arg)
{
    if(!arg) return;
    observed_tcpipblocks += ({ arg, });
}


/** \brief unsubscribes the player from the list.
 */
void stop_observe_ips(string arg)
{
    if(!arg) return;
    observed_tcpipblocks -= ({ arg, });
}


/* \brief this matches against the entire object list to see if we have
 *        a match.
 */
int match_player(string arg)
{
    int i;

    if(!arg) return 0;

    /* we cycle through to see if we have a match. */
    for(i = 0; i < sizeof(observed_players); i ++)
    {
        /* found it! */
        if(arg == observed_players[i]) return 1;
    }

    /* no match, return 0. */
    return 0;
}

/** \brief matches by object name (object_name()) of objects
 *
 */
int match_by_objectname(string arg)
{
    int i;

    if(!arg) return 0;

    /* we cycle through to see if we have a match. */
    for(i = 0; i < sizeof(current_objectnames); i ++)
    {
        /* found it! */
        if(arg == current_objectnames[i]) return i;
    }

    /* no match, return 0. */
    return 0;
}

int match_ipaddr(string arg)
{
    int i;

    if(!arg) return 0;

    /* we cycle through to see if we have a match. */
    for(i = 0; i < sizeof(observed_tcpipblocks); i ++)
    {
        /* found it! */
        if(arg == observed_tcpipblocks[i]) return 1;
    }

    /* no match, return 0. */
    return 0;
}



int count_object_instances(object ob)
{
    int i;
    int count;
    string temp;
    string temp2;
    string temp3;
    string filename;

    if(!ob) return 0;

    /* don't add ourselves */
    count = 0;

    if(sscanf(object_name(ob), "%s#%s", filename, temp) != 2)
        filename = object_name(ob);

    /* cycle through our listings until we achieve a match */
    for(i = 0; i < sizeof(current_objectnames); i ++)
    {
        /* if the object exists, we check it */
        if(current_objects[i] && environment(current_objects[i]))
        {
            /* if we have a match, add it to our count */
            if(sscanf(current_objectnames[i], "%s#%s", temp2, temp3) != 2)
                temp2 = current_objectnames[i];
            
            if(filename == temp2)
                count ++;
        }
    }
    
    tell_room(LISTENING_ROOM, "ObjectDM reports: There are " + count + " copies of " + filename + " in existence.\n");
    return count;
}
