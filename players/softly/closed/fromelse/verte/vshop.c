inherit "/room/room";

inherit "/players/vertebraker/closed/std/m_efuns";

mapping Armors, Ids, Costs;


void
reset(int arg)
{
    int s;
    string type, *m;
    if(arg) return;

    set_light(1);

    Costs = ([ "helmet" : 200, "boots" : 150 ]);
    Armors = ([ ]);
    Ids = ([ ]);

    type = "helmet";
    switch(random(2))
    {
      case 0: 
        Armors[type] = ({ "bandanna", "old bandanna", 
        "A crusty old bandanna", 
        "A crusty ol' bandanna that you can wear.\n" });
        break;
      case 1:
        Armors[type] = ({ "hat", "top hat", 
        "A top hat",
        "A great big ol' top hat.\n" });
        break;
    }
    type = "boots";
    switch(random(2))
    {
      case 0:
        Armors[type] = ({ "slippers", "bunny slippers", 
     "A pair of bunny slippers",
     "A pair of cute bunny slippers.\n" });
        break;
      case 1:
        Armors[type] = ({ "shoes", "tennis shoes", 
     "A pair of tennis shoes",
     "A pair of white tennis shoes.\n" });
        break;
    }

    m = m_indices(Armors);
    s = sizeof(m);

    while(s --)
    {
      Ids[Armors[m[s]][0]] = m[s];
      Ids[Armors[m[s]][1]] = m[s];
      Ids[Armors[m[s]][2]] = m[s];
      Ids[m[s]] = m[s];
    }
}

void
init()
{
    ::init();
    add_action("cmd_list", "list");
    add_action("cmd_buy", "buy");
}

status
cmd_list()
{
    string boots;
    write("Stuff:\n");
    write(pad(Armors["helmet"][2], 30) + "- " + Costs["helmet"] + "\n");
    write(pad(Armors["boots"][2], 30) + "- " + Costs["boots"] + "\n");
    return 1;
}

status
cmd_buy(string str)
{
    int cost, weight, ac;
    string type, *data;
    object armor;

    if(!str) return 0;

    if(!member(Ids, str))
    {
      notify_fail("\
We don't sell that here.\n");
      return 0;
    }
    
    type = Ids[str];

    cost = Costs[type];
    if((int)this_player()->query_money() < cost)
    {
      notify_fail("\
You don't have enough money!\n");
      return 0;
    }

    if(type == "armor") weight = 3;
    else weight = 1;

    if(!this_player()->add_weight(weight))
    {
      notify_fail("\
You can't carry that.\n");
      return 0;
    }

    armor = clone_object("/obj/armor");

    armor->set_type(type);

    data = Armors[type];
    armor->set_name(data[0]);
    armor->set_alias(data[1]);
    armor->set_short(data[2]);
    armor->set_long(data[3]);

    if(type == "armor")
      armor->set_ac(3);
    else
      armor->set_ac(1);

    armor->set_value(cost);
    armor->set_weight(weight);

    this_player()->add_money(-cost);
    write("You buy " + data[2] + ".\n");
    move_object(armor, this_player());
    return 1;
}
