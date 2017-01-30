/* fake_armor (c) verte[2001] 

    'cause i like fuckin' this track up */

inherit "/players/vertebraker/closed/std/treasure";

static status worn;     /* worn flag */
string type, *wMsgs, *rMsgs;   /* type & wear+remove msgs */
static object worn_by;  /* wearer object, if any */

void
reset(status arg)
{
    if(arg) return;
    ::reset();
    wMsgs = ({ "You wear $me$.\n", " wears $me$.\n" });
    rMsgs = ({ "You remove $me$.\n", " removes $me$.\n" });
}

void
set_ac(int x) { /* heh */ }


void
set_type(string x)
{
    type = x;
}

void
set_wear_msgs(string *achoo)
{
   wMsgs = achoo;
}

void
set_remove_msgs(string *achoo)
{
   rMsgs = achoo;
}

status
id(string str)
{
    if(::id(str) || (type && (str == type))) return 1;
    return 0;
}

string
query_type()
{
    return type;
}

void
init()
{
    ::init();
    add_action("cmd_wear", "wear");
    add_action("cmd_remove", "remove");
}

string
acey_deucey(string msg, int flag)
{
    string a, b;

    if(sscanf(msg, "%s$me$%s", a, b))
      msg = ((a ? a : "") + name + (b ? b : ""));

    if(flag)
      msg = ((string)this_player()->query_name() + msg);

    return msg;
}

void
removeMe()
{
    object me, e;

    if(worn && (me = environment()))
    {
      tell_object(me, acey_deucey(rMsgs[0], 0));
      if(e = environment(me))
        tell_room(e, acey_deucey(rMsgs[1], 1), ({ me }));
    }
    worn = 0;
    worn_by = 0;
}

void
drop()
{
    removeMe();
}

status
is_armor()
{
    string vrb;

    if((vrb = query_verb()) && (vrb == "ready" ||
        vrb == "#" || vrb == "armors"))
      return 1;

    else return 0;
}

status
armor_class()
{
    string vrb;

    if((vrb = query_verb()) && (vrb == "ready" ||
        vrb == "#" || vrb == "armors"))
      return 1;

    else return 0;
}

status
cmd_wear(string str)
{
    if(!str)
    {
      notify_fail("Wear what?\n");
      return 0;
    }
    if((environment() == this_player()) && id(str))
    {
      if(worn)
      {
        notify_fail("You are already wearing it!\n");
        return 0;
      }

        write(acey_deucey(wMsgs[0], 0));
        say(
            acey_deucey(wMsgs[1], 1));
      
      worn = 1;
      worn_by = this_player();
      return 1;
    }

    return 0;
}

status
cmd_remove(string str)
{
    if(!str)
    {
      notify_fail("Remove what?\n");
      return 0;
    }

    if((environment() == this_player()) && id(str))
    {
      if(!worn)
      {
        notify_fail("You aren't wearing it.\n");
        return 0;
      }

      removeMe();
      return 1;
    }

    return 0;
}

/* compat. is a must :) */

status wear(string str) { return cmd_wear(str); }

status remove(string str) { return cmd_remove(str); }

mixed
locker_init(string aaa)
{
      string heh;
    sscanf(aaa, "%s-%s-%s-%s-%s-%s",
           wMsgs[0], wMsgs[1], rMsgs[0], rMsgs[1], type, heh);
    return heh;
}
           
string
locker_arg() 
{
    return (wMsgs[0] + "-" + wMsgs[1] + "-" + rMsgs[0] +
            "-" + rMsgs[1] + "-" + type);
}

string
short()
{
    return ::short() + (worn ? " (worn)" : "");
}
