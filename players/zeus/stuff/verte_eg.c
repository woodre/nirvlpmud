/* master object for the xp race by verte */

inherit "/players/vertebraker/closed/std/m_efuns";
inherit "/obj/clean";

#define LIB "/obj/exp_store"
#define SAVEFILE "players/vertebraker/exp/save"

static status activated;
string *AllTime;

void
restore_me()
{
    restore_object(SAVEFILE);
}

void
save_me()
{
    save_object(SAVEFILE);
}

void
reset(status arg)
{
    if(arg) return;
    set_no_clean(1);
    AllTime = ({ });
    restore_me();
}

int
sort_me(int a, int b)
{
    return(b > a);
} 

mixed *
get_top(int n)
{
    int i, s;
    mixed *val, *chub;
    mapping c;

    val = sort_array(m_values(c = (mapping)LIB->query_contest()),
           "sort_me", this_object());

    s = sizeof(val);
    chub = ({ });

    for(i = 0; i < n; i ++)
    {
      if(s > i)
      {
        if(!val[i]) chub += ({ "None", 0 });
        else 
          chub += ({ get_key(c, val[i]), val[i] });
      }
      else
        chub += ({ "None", 0 });
    }
    
    return chub;
}

mixed *
get_alltime()
{
    return AllTime;
}
     
void
shutdown_contest()
{
    mixed *Winners;

    Winners = get_top(3);
    AllTime += ({ ctime()[4..9], Winners, });
    save_me();
}

void
activate()
{
    activated = 1;
    LIB->activate_contest(1);
}

void
deactivate()
{
    activated = 0;
    LIB->activate_contest(0);
    shutdown_contest();
}

status
query_activated()
{
    return activated;
}

void
register(string who)
{
    LIB->add_contestant(who);
}

mapping
query_mapping()
{
    return (mapping)LIB->query_contest();
}

status
query_registered(string Name)
{
    string *k;
    k = m_indices((mapping)LIB->query_contest());
    if(member_array(Name, k) == -1) return 0;
    else return 1;
}
