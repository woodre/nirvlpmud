/*
 * base obj
 * for all Nirvana objs
 * Coded by Vertebraker@Nirvana 2002
 */

/* -miz 13 oct 2003
 * I ripped this off from /obj/treasure_new.c since it looked like the way
 * for the future, but also seemed a little under construction.
 * It's been renamed and mangled to fit my object needs. 
 *
 */

#include "definitions.h"

static status is_loaded;   /* is obj loaded? if not, reset some vals .. needed instead of reset() code to keep things okay */

string my_name_of_weapon;  /* Used only for weapons */
string my_name;            /* Used for all other objs, query_name() */

string my_alt_name;        /* Alternate name */
string my_alias_name;      /* Alias name */
string my_alias;           /* See above, a concession */
string *my_aliases;        /* Array to handle infinite alias adding */
string *my_move_history;   /* an array of the recent places we have been in. */
string my_short_desc;      /* Short description of the item */
string my_long_desc;       /* Long description */
string my_info;            /* Special info about an obj */
string my_type;            /* Type of item.. used primarily for wep & armor */
string my_read_msg;        /* Msg seen when 'read' */
string my_smell_msg;       /* message seen when 'smell'ed */
string my_taste_msg;       /* message seen when 'taste'd */
string my_tracking_name;   /* a kludge, used for the tracking system */

int is_saveable;             /* Save flag .. 1 for nonsave, 0 for okay */
int is_gettable;           /* if this object can be picked up */
int is_tracking;           /* if the object should be writing its tracking info to disk... */
int is_broken;             /* Is item broken? */

int value;                 /* Value of obj, in coins */
int local_weight;          /* Weight of obj */
int weight;                /* See above, concession time */
int tracking_number;       /* a randomly generated tracking number */
int hits;                  /* Hits, Misses.. used primarily for Weps .. */
int misses;                /* these vals have use since they are the only real built-in variables that save for Lockers */
int limited_issue_count;   /* If limited issue, the max number that can exist at any time */

status is_inactive;
status is_limited_issue;   /* whether or not these objects exist in limited numbers or not */
status is_dest_flag;       /* Destruct flag for shops */

object my_carrier;         /* my environment (owner) object */


/* ----- id querying ----- */

status id(string str) 
{
  if(!my_aliases) my_aliases=({});
  return (str==my_name_of_weapon||
          str==my_name||
          str==my_alt_name||
          str==my_alias_name||
          str==my_alias||
          str==my_type||
          member_array(str, my_aliases)> -1);
}

string short() 
{
    string tmp_short;
    object x;
    tmp_short = my_short_desc;
    
    if(is_broken) tmp_short += "[BROKEN]";
    if(is_inactive) tmp_short += "[INACTIVE]";

    /* some day note this level in 'help wiz_levels' ..
    and use <security.h>
    */
    if(my_info && (x = this_player()) && ((int) x->query_level() > 30))
    tmp_short += "{i:" + my_info + "}";

    return tmp_short;
}

void long(string str)
{
    if(!is_inactive)
        write(my_long_desc);
    else
    {
        write("There are too many instances of this object currently in the game.\n"+
              "However this is still a legitimate copy of '" + my_short_desc + "'.\n"+
              "If this object was recovered from the lockers, hotel, or other storage facility\n"+
              "you are still able to store the object away and recover it for use at a later\n"+
              "date and time.\n");

        write("\n" + my_short_desc + " is encased in a solid plastic coating.\n"+
              "Beneath the coating, you see:\n" + my_long_desc);

    }
}

/* ----- Initialization code ----- */

void reset(int arg)
{
    if(arg) return;
    /* by default the object is gettable */
    is_gettable = 1;

    /* also by default it is not being tracked to disk. IMPORTANT! */
    is_tracking = 0;

    my_carrier = environment(this_object());

    OBJECTDM->report_creation(this_object());
    tell_room(LISTENING_ROOM, "Object reports: " + object_name(this_object()) + " has been cloned.\n");
    this_object()->add_move_history();

    remove_call_out("limited_issue_check");
    call_out("limited_issue_check", 1);
}

void limited_issue_check()
{
    int count;
    
    if(is_limited_issue) 
    {
        count = (int) OBJECTDM->count_object_instances(this_object());

        if(count >= limited_issue_count)
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

    if(!is_loaded)
    {
        weight=0;
        local_weight=0;
        value=0;
        is_loaded=1;
    }

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

    }
}

/* ----- Id props ----- */

void set_name(string x) 
{
    my_name_of_weapon = x;
    my_name = x;
}

string query_name()
{
    if(my_name)
        return my_name;
    else
        return my_name_of_weapon;
}

void set_id(string x) 
{
    set_name(x);
}

void set_alias(string x) 
{
    my_alias = x;
    my_alias_name = x;
}

/* ----- New Aliasing ----- */

status add_alias(string x) 
{
    if(!my_aliases) my_aliases=({});

    if(member_array(x, my_aliases)>-1)
        return 0;
    else
    {
        my_aliases += ({x});
        return 1;
    }
}

status delete_alias(string x) 
{
    if(!my_aliases)
    {
        my_aliases=({});
        return 0;
    }
    else
    {
        int y;
        if((y=member_array(x,my_aliases))==-1)
            return 0;
        else
        {
            my_aliases-=({my_aliases[y]});
            return 1;
        }
    }
}   

/* ----- Descriptions ----- */

void set_short(string x) 
{
    my_short_desc = x;
    if(!my_long_desc)  /* Added this .. so
                     set_short() can be called again */
    my_long_desc = (x + ".\n");
}

string query_short() { return my_short_desc; }

void set_long(string x) { my_long_desc = x; }

string query_long(string x) { return my_long_desc; }

/* ----- ints: value, weight, etc. ----- */

void set_value(int x) { value = x; }

int query_value() 
{
    if(is_broken) return 0;
    return value;
}

void set_weight(int x) 
{
    weight = x;
    local_weight = x;
}

int query_weight() 
{
    if(weight)
        return weight;
    else
        return local_weight;
}

void set_save_flag(int x) 
{
    is_saveable=1;
    if(x > 0)
        is_saveable = x;
}

int query_save_flag() 
{
    if(is_broken)
        return 1;
    return is_saveable;
}

void set_hits(int x) { hits = x; }

void set_misses(int x) { misses = x; }

int query_hits() { return hits; }

int query_misses() { return misses; }

void set_get(int arg) { is_gettable = arg; }


/* ----- special properties ----- */

int get() { return is_gettable; }

void set_read(string x) { my_read_msg = x; }

string query_read() { return my_read_msg; }

void set_smell(string x) { my_smell_msg = x; }

string query_smell() { return my_smell_msg; }

void set_taste(string x) { my_taste_msg = x; }

string query_taste() { return my_taste_msg; }

void set_info(string x) { my_info = x; }

string query_info() { return my_info; }

void set_type(string x) { my_type = x; }

string query_type() { return my_type; }

void set_broke(int x) { is_broken = x; }

int query_broke() { return is_broken; }

status query_limited_issue() { return is_limited_issue; }

void set_limited_issue(status arg) { is_limited_issue = arg; }

int query_limited_issue_count() { return limited_issue_count; }

void set_limited_issue_count(int arg) { limited_issue_count = arg; }

int on_ping() { return 1; }

/* ----- new light code ----- */

mixed set_light(int x) 
{
    if(x)
    {
        int light_val;

        if((light_val=(efun::set_light(0))) > x)
            efun::set_light(light_val-x);
        else
            efun::set_light(light_val-x);
        return;
    }
    else
        return efun::set_light(0);
}

int query_light() { return set_light(0); } 

/* ----- hotel save properties ----- */

status save_thing(string str) 
{
    save_object(str);
    return 1;
}

status restore_thing(string str) { return restore_object(str); }

/* ----- shop funs ----- */
status query_dest_flag() { return is_dest_flag; }
void set_dest_flag(int x) { is_dest_flag=x; }

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

    temp += "\n";

    /* if we have been told to, write to file. */
    if(is_tracking)
    {
        write_file("/players/mizan/logs/object." + my_tracking_name + "." + tracking_number, temp);
        tell_room(LISTENING_ROOM, "Object reports: Log file object." + my_tracking_name + "." + tracking_number + " has updated history.\n");
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

    tell_room(LISTENING_ROOM, "Object reports: " + object_name(this_object()) + " has reporting to object." + my_tracking_name + "." + tracking_number + ".\n");
    
    write_file("/players/mizan/logs/object." + my_tracking_name + "." + tracking_number, query_move_history());

    /* write our output to the index file too. */
    temp = ctime() + " '" + this_object()->short() + "', object." + my_tracking_name + "." + tracking_number + "\n";
    write_file("/players/mizan/logs/objectindex." + my_tracking_name, temp);

}

/* eof */