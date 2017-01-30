inherit "/obj/generic_heal.c";
#include "definitions.h"


string my_read_msg;        /* Msg seen when 'read' */
string my_smell_msg;       /* message seen when 'smell'ed */
string my_taste_msg;       /* message seen when 'taste'd */
string *my_move_history;   /* an array of the recent places we have been in. */
string my_tracking_name;   /* a kludge, used for the tracking system */

int is_tracking;           /* if the object should be writing its tracking info to disk... */
int tracking_number;       /* a randomly generated tracking number */
int limited_issue_count;   /* If limited issue, the max number that can exist at any time */

status is_inactive;
status is_limited_issue;   /* whether or not these objects exist in limited numbers or not */

object my_carrier;         /* my environment (owner) object */


/* ----- Initialization code ----- */

void reset(int arg)
{
    ::reset(arg);
    if(arg) return;

    /* also by default it is not being tracked to disk. IMPORTANT! */
    is_tracking = 0;

    my_carrier = environment(this_object());

    OBJECTDM->report_creation(this_object());
    tell_room(LISTENING_ROOM, "Heal.c reports: " + object_name(this_object()) + " has been cloned.\n");
    this_object()->add_move_history();

    remove_call_out("limited_issue_check");
    call_out("limited_issue_check", 1);

}

/* bummer. i wish we could daemonize this but for now this function runs inlined. */
void limited_issue_check()
{
    int count;
    
    if(is_limited_issue) 
    {
        count = (int) OBJECTDM->count_object_instances(this_object());

        if(count > limited_issue_count)
        {
            /* deactivate the object */
            tell_room(LISTENING_ROOM, "Object reports: " + object_name(this_object()) + " has reached limited issue of " + limited_issue_count + ".\n");
            
            if(environment() && short())
                tell_object(environment(), short() + " turns inactive.\nThere are too many copies of this object in the game.\n");

            is_inactive = 1;
        }

    }
}


void init() 
{

    /* we update our location if moved */
    if(my_carrier && environment(this_object()))
    {
        if(my_carrier != environment(this_object()))
        {

            if(!is_tracking 
               && my_carrier->query_real_name() 
               && OBJECTDM->match_player(my_carrier->query_real_name()))
            {
                /* whew! */
                this_object()->start_tracking_to_disk(my_carrier->query_real_name());
            }

            this_object()->add_move_history();
        }
    }
    /* and set the new location when done */
    my_carrier = environment(this_object());

    if(!is_inactive)
    {

        /* local actions for us. */
        add_action("on_read", "read");
        add_action("on_smell", "smell");
        add_action("on_smell", "sniff");
        add_action("on_taste", "taste");

        /* the super doesn't get called at all if the object is inactive */
        ::init();
    }
}


void set_read(string x) { my_read_msg = x; }

string query_read() { return my_read_msg; }

void set_smell(string x) { my_smell_msg = x; }

string query_smell() { return my_smell_msg; }

void set_taste(string x) { my_taste_msg = x; }

string query_taste() { return my_taste_msg; }


/* ----- reading ---- */

int on_read(string str)
{
    if(!my_read_msg) return 0;

    if(!str || !id(str)) return 0;

    if(short())
    say(short() + " is carefully examined by " + this_player()->query_name() + ".\n");

    write(my_read_msg);

    return 1;
}

/* ----- smelling ---- */

int on_smell(string str)
{
    if(!my_smell_msg) return 0;

    if(!str || !id(str)) return 0;

    if(short())
    say(short() + " is carefully smelled by " + this_player()->query_name() + ".\n");

    write(my_smell_msg);
    return 1;
}

/* ----- tasting ---- */

int on_taste(string str)
{
    if(!my_taste_msg) return 0;

    if(!str || !id(str)) return 0;

    if(short())
    say(short() + " is tasted by " + this_player()->query_name() + ".\n");

    write(my_taste_msg);
    return 1;
}

status query_limited_issue() { return is_limited_issue; }

void set_limited_issue(status arg) { is_limited_issue = arg; }

int query_limited_issue_count() { return limited_issue_count; }

void set_limited_issue_count(int arg) { limited_issue_count = arg; }


/* ----- updating our location history ---- */

void add_move_history()
{
    /* i figured this code should have been inlined instead of daemonized. */
    string temp;

    temp = ctime() + " ";

    /* if we have an environment, get more info about it */
    if(my_carrier)
    {
        temp += object_name(my_carrier);
        if(living(my_carrier))
            temp += " , real name: " + my_carrier->query_real_name();
    }
    else temp += "[no environment]";

    /* lets add some armor-specific info */
/*    temp += " WC: " + class_of_weapon + " Hits: " + hits + " Misses: " + misses + "\n"; */

    /* if we have been told to, write to file. */
    if(is_tracking)
    {
        write_file("/players/mizan/logs/heal." + my_tracking_name + "." + tracking_number, temp);
        tell_room(LISTENING_ROOM, "Heal.c reports: Log file object." + my_tracking_name + "." + tracking_number + " has updated history.\n");
    }

    /* if we are empty, we initialize ourselves */
    if(!my_move_history) my_move_history  = ({});

    /* bump the buffer if we are too large */
    if(sizeof(my_move_history) == MAX_MOVE_HISTORY)
    {
        my_move_history -= ({ my_move_history[0] });
    }
    
    my_move_history += ({ temp, });

}


/* this returns a string describing where we've been */
string query_move_history()
{
    int i, a;
    string msg;

    msg = "\nMove History for: " + object_name(this_object()) + "\n\n";

    for(i = 0, a = sizeof(my_move_history); i < a; i++)
    {
        msg += my_move_history[i];
    }

    if(environment(this_object()))
        msg += "Current environment: " + object_name(environment(this_object())) + "\n";

    msg += "\n";
    return msg;
}

void start_tracking_to_disk(string str)
{
    string temp;

    if(is_tracking) return;

    /* we tell ourselves to start tracking */
    is_tracking = 1;

    /* generate a random index number */
    tracking_number = random(50000);

    my_tracking_name = str;

    tell_room(LISTENING_ROOM, "Heal.c reports: " + object_name(this_object()) + " is reporting to object." + my_tracking_name + "." + tracking_number + ".\n");
    
    write_file("/players/mizan/logs/heal." + my_tracking_name + "." + tracking_number, query_move_history());

    /* write our output to the index file too. */
    temp = ctime() + " '" + this_object()->short() + "', heal." + my_tracking_name + "." + tracking_number + "\n";
    write_file("/players/mizan/logs/objectindex." + my_tracking_name, temp);

}

/* eof */