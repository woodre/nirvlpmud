heart_beat()
{
  ::heart_beat();
  if(attacker_ob)
  {
    if(random(100) < 25) slash();
    if(random(100) < 25) breath_fire();
    if(random(100) < 25) tail_lash();
  }
}

slash()
{
  tell_object(attacker_ob,
    "\n\t"+query_name()+" "+HIC+"RAKES"+NORM+" you with its claws!\n\n");
  tell_room(environment(),
    "\n\t"+query_name()+" "+HIC+"RAKES"+NORM+" "+
    attacker_ob->query_name()+" with its claws!\n",
    ({ attacker_ob }));
    
  attacker_ob->hit_player(50+random(50));
}

breath_fire()
{
  object *obs;
  int    s;
  tell_room(environment(),
  "A sulfury "+HIK+"smoke"+NORM+" puffs from "+query_name()+"'s nostrils.\n");
  tell_room(environment(),
    HIR+"\n\t\tFIRE leaps from "+query_name()+"'s throat!\n\n"+NORM);
    
  obs = all_inventory(environment());
  s = sizeof(obs);
  
  while(s --)
  {
    if(obs[s] && living(obs[s]) && obs[s] != this_object())
    {
      obs[s]->hit_player(50+random(50),"other|fire");
    }
  }
  return 1;
}

tail_lash()
{
  tell_object(attacker_ob,
    "\n\t"+query_name()+" "+HIC+"LASHES"+NORM+" you with its TAIL!\n\n");
  tell_room(environment(),
    "\n\t"+query_name()+" "+HIC+"LASHES"+NORM+" "+
    attacker_ob->query_name()+" with its TAIL!\n",
    ({ attacker_ob }));
    
  attacker_ob->hit_player(50+random(50));
}

catch_tell(str)
{
  string x;
  object c;
  if(sscanf(str,"%s died.%s",x,x) == 2 &&
     c = present("corpse",environment()))
  {
    tell_room(environment(),
      query_name()+" greedily devours the corpse!\n");
    heal_self(100);
    destruct(c);
  }
}