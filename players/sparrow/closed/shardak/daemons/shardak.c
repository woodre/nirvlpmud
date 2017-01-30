#include "../std.h"
#include "../macros.h"
#include "../def.h"

#define mark(X) present(OBJID, X)

mixed Servants()
{
    int      x;
    object   *victims, *rebuild;
    object mk;
 
    victims = users();
    rebuild = ({ });

    for(x = 0; x < sizeof(victims); x++)
    {
      if(victims[x])
      if((string)victims[x]->query_guild_name() == GUILDNAME 
         && present(OBJID, victims[x])
         && environment(victims[x]) && interactive(victims[x])
         && (int)victims[x]->query_level() < 21)
      rebuild += ({ victims[x] });
    }
    return rebuild;
}

void demand_stuff()
{
    int        x, content, org; 
    object     *Users;
    string     type;
    
    Users = Servants();

    org = sizeof(Users);

    for(x = 0; x < sizeof(Users); x ++)
    {
      if((string)Users[x]->query_real_name() != "worm")
      if(mark(Users[x]) && !mark(Users[x])->Sacrifice() && !mark(Users[x])->query_sacrifice_type())
      {
        switch(random(3))
        {
          case 0:
            type = "blood";
            break;
          case 1:
            type = "soul";
            break;
          case 2:
            type = "gold";
            break;
        }
        CHANNELD->broadcast("\
Shardak demands a " + type + " sacrifice from " + 
(string)Users[x]->query_name() + ".\n", 0, "{Servants}");
        if(mark(Users[x])) mark(Users[x])->NeedSacrifice(type);
      }
      else
        content ++;
    }
    if(content == org)
    {
    object mk;
      CHANNELD->broadcast("Shardak smiles contentedly.\n",
        1, "{Servants}");
      for(x = 0; x < sizeof(Users); x ++)
      {
        tell_object(Users[x],
"Shardak strengthens you with some of his power.\n");
        if(mk=mark(Users[x])) mk->give_me_back_my_power_foo();
        Users[x]->heal_self(20 + random(10));
      }
    }
    while(remove_call_out("demand_stuff") != -1);
    call_out("demand_stuff", 1300 + random(2000));
}
