/* 
   5.25.01  cuz it just ain't gettin' easier baby
 */

inherit "/obj/weapon";

status twoHandedFlag;

status
verte_shield_check(object slob)
{
    object ob;

    ob = first_inventory(slob);
    while(ob)
    {
      if(((status)ob->is_armor() || (int)ob->query_ac()) &&
         (string)ob->query_type() == "shield" &&
         (status)ob->query_worn())
        return 1;
      
      if(ob) ob = next_inventory(ob);
    }
}

void
set_two_handed(int flag)
{
    twoHandedFlag ^= flag;
}

void
locker_init(string heh)
{
    twoHandedFlag = atoi(heh);
}

string
locker_arg()
{
    return "" + twoHandedFlag;
}

status
id(string arg)
{
    object a;

    if(::id(arg))
      return 1;
    if((a = previous_object()) &&
       (string)a->query_type() == "shield" &&
       (status)a->is_armor())
      return (arg == "notarmor");
}

status
wield(string arg)
{
    object a;

    a = this_player();

    if(!arg || environment() != a ||
       !id(arg) || wielded)
      return (int)::wield(arg);

    if(verte_shield_check(a))
    {
      notify_fail("\
You cannot wield this two-handed weapon while wearing\n\
a shield.\n");
      return 0;
    }

      return (int)::wield(arg);
}


string
short()
{
    string sh;

    sh = (string)::short();

    if(twoHandedFlag)
    {
      string a, b;
      if(sscanf(sh, "%s(wielded)%s", a, b))
        return (a + "(wielded in both hands)" + (b ? b : ""));
      else return sh;
    }

    else
      return sh;
}

status
two_handed()
{
    return twoHandedFlag;
}

int
offwield_function()
{
    if(twoHandedFlag) return 2;
    return 0;
}
