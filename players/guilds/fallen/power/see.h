#define AN capitalize((string)a->query_real_name())

see(str){
  object a, special, ob, comp;
  int max, ga;
  if(User->query_ghost()) return 0;
  if(!GOB->query_skills("see")) return 0;
  if(GOB->light_check()) return 1;
  if(!str) return 0;
  comp = present("guild_comp_pouch", User);
  if(environment(User)->realm() == "NM")
  {
    TOU"Your power is being drained here.\n");
    return 1;
  }
  if(!comp)
  {
    TOU"You lack the spell component to cast this spell.\n");
    return 1;
  }
  if(!comp->query_geode())
  {
    TOU"You lack the spell component to cast this spell.\n");
    return 1;
  }
  a = find_player(str);
  if(!a)
  {
    TOU "There is no "+str+" logged on.\n");
    return 1;
  }
  if(!GOB->spell_failure(1)) return 1;
  if(GOB->casting_check()) return 1;
  if(a == User) return 0;

  TOU
    "You close your eyes and focus on "+a->query_name()+"...\n\n");

  if(a->test_dark()) return 1;
  if(a->query_level() > 20)
  {
    TOU "You are unable to focus on "+AN+" for some reason.\n");
    return 1;
  }

  TOU a->short()+" ("+a->query_gender()+")"+".\n");
  TOU AN+" is a "+a->query_race()+", "+a->query_phys_at(1)+" feet "+
    a->query_phys_at(2)+" inches tall and "+a->query_phys_at(3)+" lbs.\n");
  if(a->query_description())
    TOU AN+" "+a->query_description()+"\n");
  if(a->query_pl_k())
    TOU AN+" can fight other players.\n");

  if(a->query_ghost())
    TOU AN+" is a ghost.\n");
  else if(a->query_frog())
    TOU AN+" is a frog.\n");
  else
  {
    int foo, goo;
    foo = (int)a->query_hp();
    goo = (int)a->query_mhp();
    if(foo < goo / 10)
      TOU AN+" is in very bad shape.\n");
    else if(foo < goo / 5)
	  TOU AN+ " is in bad shape.\n");
    else if(foo < goo / 2)
	  TOU AN+" is somewhat hurt.\n");
    else if(foo < goo - 20)
	  TOU AN+" is slightly hurt.\n");
    else
      TOU AN+" is in good shape.\n");
  }

  special = all_inventory(a);
  for(ga = 0; ga < sizeof(special); ga++)
  {
    string extra_str;
    extra_str = call_other(special[ga], "extra_look");
    if(extra_str)
      TOU extra_str+".\n");
  }

  TOU "\t"+capitalize(a->query_name()) + " is carrying:\n");
  max = 20;
  ob = first_inventory(a);
  while(ob && max > 0)
  {
    string sh;
    sh = call_other(ob, "short");
	if(sh)
      TOU sh + ".\n");
	ob = next_inventory(ob);
    max -= 1;
  }

  User->add_spell_point(-15);
  GOB->add_endurance(-3);
  comp->use_geode();
  GOB->energy_check();
  return 1;
}
