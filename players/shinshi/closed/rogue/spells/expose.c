/* Most of this code is from Mythos' Zantetsuken with a bit of tweaking for the Rogues to allow them to break one piece of armor every 10 minutes*/
/* with a chance of failure*/
#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
  object *armors, *inv;
  object breakit, attacker, wound, stopper;
  string title;
  int m,n,s, dex;
  
  n=random(120);
  attacker = (object)User->query_attack();
  dex = (int)call_other(User, "query_attrib", "dex");
  
  if(User->query_extra_level() < 13){
	  write("You cannot use that ability yet!\n");
	  return 1;
  }
  
  if(User->query_sp() < 90){
	  write("You do not have the energy to do that!\n");
	  return 1;
  }
  
  
  if(!attacker)
  {
	  write("You aren't attacking anything.\n");
	  return 1;
  }
  
  if(present("shinshi_stop_expose", User))
  {
	  write("That ability is still on cooldown!\n");
	  return 1;
  }
  
  if(n == 12)
  {
    write("Your opponent blocks your attack and gashes your arm open!\n");
    say(attacker->query_name()+" blocks the attack and slices a deep cut into "+User->query_name()+".\n");
    wound = clone_object(OBJPATH+"wound.c");
    stopper = clone_object(OBJPATH+"noexpose.c");
    move_object(wound, User);
    move_object(stopper, User);
    stopper->start_it();
    wound->start_it();
    User->add_spell_point(-90);
    return 1;
  }

  if((dex * 3) < n)
  {
    write("Your opponent slips to the left dodging your attack.\n");
    say(attacker->query_name()+" slips to the side dodging "+User->query_name()+"'s attack.\n");
    stopper = clone_object(OBJPATH+"noexpose.c");
    move_object(stopper, User);
    stopper->start_it();
    User->add_spell_point(-90);
    return 1;
  }
  
  if((dex * 3) > n) 
  {
    armors=({});
    inv=all_inventory(attacker);
    s=sizeof(inv);
    
    while(s--)
    if(inv[s]->armor_class() > 0 && inv[s]->query_worn())
      armors+=({inv[s]});
    
    m = sizeof(armors);
  
    if(!m)
    {
      write("Your attacker isn't wearing any armors.\n");
      return 1;
    }

    if(m) 
    {
      breakit=armors[random(m)];
      title=(string)breakit->query_name();
      if(!title) title=(string)breakit->query_type();
      if(!title) title="armor";
      tell_object(User, "\n\n\tYou slice through your opponent's "+title+"!\n");
      tell_object(attacker, User->query_name()+" notices a $HK$weakness$N$ in your $Y$defenses $N$and $HR$CRUSHES$N$ your $G$armor$N$ leaving you $HY$exposed$N$ to $HK$attacks$N$.\n");
      tell_room(environment(User), User->query_name()+" slices through "+attacker->query_name()+"'s "+title+"!\n", ({ User, attacker}));
      breakit->armor_breaks();
      /* Add some extra damage to compensate for the change */
      attacker->heal_self(-4-random(4));
      stopper = clone_object(OBJPATH+"noexpose.c");
      move_object(stopper, User);
      stopper->start_it();
      User->add_spell_point(-90);
    }
  }
  return 1;
}
