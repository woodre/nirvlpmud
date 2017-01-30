#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  object pet, it, them, *inv, m;
  string cmd, what, who;
  int size, x, ivalue, tvalue;
  if(User->query_ghost()) return 0;
  if(!PO->level_check(7)) return 0;
  if(!str) return 0;

  if(!(pet = (object)PO->query_pet()))
  {
    TOU "You do not have a pet to command.\n");
    return 1;
  }

  if(!present(pet, environment(User)))
  {
    if(str == "call")                                            /***call***/
    {
      TOU "You call your pet to your side.\n\n");
      TRU pet->short()+" arrives.\n");
      if(PO->query_sending())
        PO->sent();
      move_object(pet, environment(User));
      return 1;
    }
    else {
      TOU "Your pet is not here to command.\n");
    return 1;
    }
  }
  else if(str == "hide")                                       /***hide***/
  {
    TOU"You tell "+pet->short()+" to run and hide.\n");
    TRU pet->short()+" rushes away to hide.\n", ({ User }));
    PO->pet_send();
    move_object(pet, "/room/void.c");
    return 1;
  }
  else if(str == "dismiss")                                    /***dismiss***/
  {
    TOU"You free "+pet->short()+" from your tyranical oppression.\n");
    TRU pet->short()+" wanders off, happy to be free.\n");
    move_object(pet, "/room/void.c");
    destruct(pet);
    PO->set_pet(0);
    return 1;
  }
  else if(sscanf(str, "%s %s %s", cmd, what, who) == 3)
  {
    if(cmd == "send")                                          /***send***/
    {
      if(!(it = present(what, pet)))
      {
        TOU pet->short()+" doesn't have that to send.\n");
        return 1;
      }
      if(!(them = find_player(who))) 
      {
        TOU pet->short()+" doesn't know where "+who+" is.\n");
        return 1;
      }
      if((string)environment(pet)->realm() == "NT")
      {
        TOU pet->short()+" can't seem to find it's way out of here.\n");
        return 1;
      }
      if((string)environment(them)->realm() == "NT")
      {
        TOU pet->short()+" isn't sure how to reach "+capitalize(who)+".\n");
        return 1;
      }
      else 
      {
        PO->pet_send();
        pet->send(them, it, PO, User);
        if(environment(them) != environment(pet))
        {
          TRU pet->short()+" rushes away.\n");
          move_object(pet, environment(them));
          tell_room(environment(pet), pet->short()+" arrives from "+Name+".\n");
        }
        else
          TRU pet->short()+" turns its attention to "+
          them->query_name()+".\n");
        tell_object(them, "Type 'accept delivery' if you want:  "+
          it->short()+".\n\n");
        /*  "Type 'decline delivery' or ignore this if you don't want it.\n\n"); */
        return 1;
      }
    }
  }
  else if(sscanf(str, "%s %s", cmd, what) == 2)
  {
    if(cmd == "get" || cmd == "take")                          /***get***/
    {
      if(what == "all")
      {
        inv = all_inventory(environment(pet));
        size = sizeof(inv);
        for(x = 0; x < size; x++)
        {
          it = inv[x];
          if(it->get())
          {
            TRU pet->short()+" takes "+it->short()+".\n");
            move_object(it, pet);
          }
        }
        return 1;
      }
      else if(!(it = present(what, environment(pet))))
        TRU pet->short()+" looks confused.\n");
      else {
        /* if carry more */
        if(!it->get())
          TRU pet->short()+" tries but fails to take "+it->short()+".\n");
        else {
          TRU pet->short()+" takes "+it->short()+".\n");
          move_object(it, pet);
        }
        return 1;
      }
    }
    else if(cmd == "drop")                                     /***drop***/
    {
      if(what == "all")
      {
        inv = all_inventory(pet);
        size = sizeof(inv);
        for(x = 0; x < size; x++)
        {
          it = inv[x];
          TRU pet->short()+" drops "+it->short()+".\n");
          move_object(it, environment(pet));
        }
        return 1;
      }
      else if(!(it = present(what, pet)))
        TOU pet->short()+" doesn't have that to drop.\n");
      else {
        TRU pet->short()+" drops "+it->short()+".\n");
        move_object(it, environment(pet));
      }
      return 1;
    }
    else if(cmd == "give")                                     /***give***/
    {
      if(!(it = present(what, pet)))
        TOU pet->short()+" doesn't have that to give.\n");
      else if(!User->add_weight(it->query_weight()))
        TOU "You can't carry that.\n");
      else {
        TOU pet->short()+" gives you "+it->short()+".\n");
        TRU pet->short()+" gives "+Name+" "+it->short()+".\n", ({ User }));
        move_object(it, User);
      }
      return 1;
    }

    else if(cmd == "sell")                                     /***sell***/
    {
      ivalue = tvalue = 0;
      move_object(pet, "/room/void.c");
      if(what == "all")
      {
        PO->pet_send();
        TOU pet->short()+" wanders off to find a shop.\n");
        TRU pet->short()+" wanders off.\n", ({ User }));
        inv = all_inventory(pet);
        size = sizeof(inv);
        for(x = 0; x < size; x++)
        {
          it = inv[x];
          ivalue = (int)it->query_value();
          ivalue = ((ivalue * 100) / 106); /* loose a bit per doc/build/RULES */
          if(ivalue > 1000) ivalue = 1000; /* max at 1000 per doc/build/RULES */
          tvalue += ivalue;
          move_object(it, environment(pet));
          destruct(it);
        }
        pet->set_sold_value(tvalue);
        pet->sell(PO, User);
        return 1;
      }
      else if(!(it = present(what, pet)))
        TOU pet->short()+" doesn't have that to sell.\n");
      else {
        PO->pet_send();
        TOU pet->short()+" wanders off to find a shop.\n");
        TRU pet->short()+" wanders off.\n", ({ User }));
        ivalue = (int)it->query_value();
        ivalue = ((ivalue * 100) / 106); /* loose a bit per doc/build/RULES */
        if(ivalue > 1000) ivalue = 1000; /* max at 1000 per doc/build/RULES */
        move_object(it, environment(pet));
        destruct(it);
        pet->set_sold_value(ivalue);
        pet->sell(PO, User);
      }
      return 1;
    }        
    
  }
  if(sscanf(str, "%s %s", cmd, what) >= 2)
  {
    if(cmd == "say")                                      /***say***/
    {
      TRU pet->short()+" says, \""+what+"\"\n");
      return 1;
    }
    else if(cmd == "emote")                                    /***emote***/
    {
      TRU pet->short()+" "+what+"\n");
      return 1;
    }
  }

  return 0;
}

