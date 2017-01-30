#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  object nmy, pet, *inv, what;
  int cost, x, size, newwc;
  if(User->query_ghost()) return 0;
  if(!PO->level_check(7)) return 0;
  if(!User->query_attack())
  {
    TOU"You must be fighting something to force it into submission.\n");
    return 1;
  }
  else
    nmy = (object)User->query_attack();

  if(!present(nmy, environment(User)))
  {
    TOU"You must be fighting something to force it into submission.\n");
    return 1;
  }

  cost = (int)nmy->query_level() + (int)nmy->query_hp() - (WIS / 10);
  if(cost > 100 || (((int)nmy->query_hp() > ((int)nmy->query_mhp() / 15))
    && (int)nmy->query_hp() > 50))
  {
    TOU "Your enemey is too strong to force into submission.\n");
    return 1;
  }

  if((string)environment(User)->realm() == "NM")
  {
    TOU"Your energy is being drained here.\n");
    return 1;
  }

  if(User->query_sp() < cost)
  {
    TOU "You are too weak to do this now.\n");
    return 1;
  }

  if(PO->query_pet())
  {
    TOU"You already have control of a monster.\n");
    return 1;
  }

  if(nmy == (object)PO->query_pet())
  {
    TOU"You already have control of "+nmy->short()+".\n");
    return 1;
  }

  TOU "You force "+nmy->short()+" into submission.\n"+
    nmy->short()+" whimpers softly.\n");

  TRU Name+" forces "+nmy->short()+" into submission.\n", ({ User }));

  newwc = (int)nmy->query_wc() / 2;
  if(newwc > 19)
    newwc = 19;

  pet = clone_object("/players/fred/closed/bloodfist/obj/control_pet.c");
  pet -> set_name((string)nmy->query_name());  
  pet -> set_level((int)nmy->query_level() / 2);
  pet -> set_alias(nmy->query_alias());
  pet -> set_short(nmy->short());
  pet -> set_long(nmy->query_long());
  pet -> set_wc(newwc);
  pet -> set_ac((int)nmy->query_ac() / 2);
  pet -> add_money(nmy->query_money()); /* does this work */
  pet -> set_heal(1,1);
  pet -> set_controller(User);

  inv = all_inventory(nmy);
  size = sizeof(inv);
  if(size > 0)
  {
    for(x = 0; x < size; x++)
    {
      if(inv[x]->query_wielded())
      {
        command("unwield", nmy);
        move_object(inv[x], pet);
        command("wield "+inv[x]->query_type()+"", pet);
      }
      if(inv[x]->query_worn())
      {
        command("remove "+what+"", nmy);
        move_object(inv[x], pet);
        command("wear "+inv[x]->query_type()+"", pet);
      }
     move_object(inv[x], pet);
    }
  }

  move_object(pet, environment(User));
  PO->set_pet(pet);

  nmy->set_custom_attacker_death_mess("");
  nmy->set_custom_room_death_mess("");
  nmy->set_no_exp_value(); /* no exp from the kill, sacrifice made to control mob */
  nmy->hit_player(100);
  if(present("corpse", environment(User)))
    destruct(present("corpse", environment(User)));
  if(present("money", environment(User)))
    destruct(present("money", environment(User)));
  
  User->add_sp(-cost);
  return 1;
}

