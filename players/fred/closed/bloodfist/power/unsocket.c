/* Valid Command Syntax:
   1. unsocket weapon    - unsocket first available weapon         
   1. unsocket <weapon>  - unsocket <weapon>
*/

/*
  Changed it up some.  Finally got around to making
  it so your chance of unsocketing the gem successfully
  wasn't based strictly on a random.  Is now based on
  honor, agility, and wisdom.  Max chance of success
  is 80%.
*/

#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  object gem, wep, weapon, shad;
  object *alli;
  int x, y, waswielded, honor, agl, acc, wis, fai, chance;
  string fname, gstr, wstr, tstr, first, trash;

  if(User->query_ghost()) return 0;
  if(!PO->level_check(4)) return 0;
  
  honor = (int)HONOR_DAEMON->query_honor(User->query_real_name());
  honor /= 25;  
  
  wis = WIS;
  wis /= 10;
  
  agl = AGL;
  agl /= 10;

  acc = ACC;
  acc /= 10;

  fai = FAI;
  fai /= 10;

  chance = honor+wis+agl+acc+fai;
 
  if(chance < 30) chance = 30;
  if(chance > 80) chance = 80;
  
  if(!str) 
  {
    write("Unsocket what?\n"); 
    return 1;
  }
  if(str == "weapon")
  {
    alli = all_inventory(environment(PO));
    x = sizeof(alli);
    while(y < x && !wep)
    {
      if(alli[y]->query_bloodfist_wep_shadow())
        wep = alli[y];
      y++;
    }    
  }
  else 
    wep = present(str, environment(PO));
  if(!wep)
  {
    write("You don't have a "+str+".\n"); 
    return 1;
  }
  if(!wep->is_weapon())
  {
    write(str+" is not a weapon.\n"); 
    return 1;
  }
  if(!wep->query_bloodfist_wep_shadow())
  {
    write("That weapon has not been forged with a socket.\n"); 
    return 1;
  }
  if(!wep->query_forged())
  {
    write("That weapon has not been forged with a socket.\n"); 
    return 1;
  }
  if(!wep->query_socket())
  {
    write("That weapon has not been forged with a socket.\n"); 
    return 1;
  }  
  if(!wep->query_socketed())
  {
    write("That weapon hasn't been socketed with a gem.\n"); 
    return 1;
  }
  if(wep->query_wielded()) 
  {
    waswielded = 1;
  }
  if(waswielded)
    command("unwield "+wep->query_name(), environment(PO));
  gem = clone_object("/players/fred/closed/bloodfist/obj/gem.c");
  gem->set_stype(wep->query_stype());
  gem->set_ws(wep->query_ws());
  gem->set_spec(wep->query_spec());
  gem->set_held(1);  
  sscanf(file_name(wep), "%s#%s", fname, trash);
  weapon = clone_object(fname);
  move_object(weapon, environment(PO));    
  shad = clone_object("/players/fred/closed/bloodfist/obj/wep_shadow.c");
  shad->set_bloodfist_wep_shadow(weapon);
  weapon->set_owner(this_player()->query_real_name());
  weapon->set_socket();      
  weapon->set_forged();
  weapon->set_class(wep->weapon_class());        
  weapon->set_broke(wep->query_broke());
  weapon->set_hits(wep->query_hits());
  weapon->set_misses(wep->query_misses());
  tstr = (string)gem->short(); 
  tstr = delete_colour(tstr); 
  tstr = lower_case(tstr);
  if(sscanf(tstr, "a %s", first) == 1) 
    gstr = first;
  else if(sscanf(tstr, "an %s", first) == 1) 
    gstr = first;    
  else 
    gstr = tstr;
  tstr = (string)weapon->short(); 
  tstr = delete_colour(tstr); 
  tstr = lower_case(tstr);
  if(sscanf(tstr, "a %s", first) == 1) 
    wstr = first;
  else if(sscanf(tstr, "the %s", first) == 1) 
    wstr = first;            
  else 
    wstr = tstr;
  write("Carefully you unsocket the gem from your "+wstr+".\n");      
  say(User->query_name()+" fumbles with "+User->query_possessive()+" "+
      wstr+", removing a gem from its socket.\n");
  
  if(random(100) > chance)
  {
    write("The "+gstr+" shatters as you remove it from the weapon's socket.\n");
    say("The gem shatters as it is unsocketed from the weapon.\n");
    move_object(gem, "/room/void.c");
    destruct(gem);
  }
  else
  {
    move_object(gem, environment(PO));
  }
  move_object(wep, "/room/void.c");
  destruct(wep);      
  if(waswielded) command("wield "+weapon->query_name(), environment(PO));
  return 1;
}
