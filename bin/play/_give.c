#include <security.h>
#include "/obj/lib/living/settings.h"

int cmd_give(string str)
{
  string item, dest;
  object item_ob, dest_ob;
  int weight;
  int maxflag,coins,dest_coin;
  string power;
  string cap_name;
  
 if(!str) return 0;
  cap_name = (string)this_player()->query_name();
    
  power = 0;
  if((int)this_player()->query_level() >= ITEM_OVER)
  {
    if (sscanf(str,"! %s",power) == 1)
    {
      str = power;
	    power = "!";
    }
  }
  if(!str)
  {
    notify_fail("Give what to whom?\n");
    return 0;
  }
  if(this_player()->test_dark())
	  return 1;
	  
  if(sscanf(str, "%d coins to %s", coins, dest) == 2)
	  item = 0;
  else if ( sscanf(str, "1 coin to %s", dest) ||
            sscanf(str, "coin to %s", dest) ||
            sscanf(str, "one coin to %s", dest))
    coins = 1;
  
  else if (sscanf(str, "%s to %s", item, dest) != 2)
  {
	  write("Give what to whom?\n");
	  return 1;
  }
  
  dest = lower_case(dest);
  if (item)
  {
	  item = lower_case(item);
	  item_ob = present(item, this_player());
	  if (!item_ob)
	  {
	    write("There is no " + item + " here.\n");
	    return 1;
	  }
	  if(environment(item_ob) == this_player() && item_ob->drop() && !power)
	  {
	    return 1;
	  }
	  else if (!item_ob || (!call_other(item_ob, "get") && !power))
	  {
	    write("You can't get that !\n");
	    return 1;
	  }
  }
  
  dest_ob = present(dest, environment(this_player()));
  if (!dest_ob)
  {
	  write("There is no " + capitalize(dest) + " here.\n");
	  return 1;
  }
  if(dest_ob->query_disallow_give())
  {
    write(dest_ob->query_name()+" is not accepting items.\n");
    tell_object(dest_ob, this_player()->query_name()+" tried to give you something.\n");
    return 1;
  }
  if (!living(dest_ob) && !power)
  {
	  write("You can't do that.\n");
	  return 1;
  }
  if (!item)
  {
    if (this_player()->query_no_give())
    {
      write("You cannot give money while another copy is logging in.\n");
      return 1;
    }
	  if (coins <= 0 && !power)
	  {
	    return 0;
    }
	  if ((int)this_player()->query_money() < coins && !power)
	  {
	    write("You don't have that much money.\n");
	    return 1;
	  }
	  if (!power)
	    this_player()->add_money(-coins);
	    
	  if (coins > 1 && !power)
	      this_player()->save_me();
	    
    dest_coin = (int)dest_ob->query_money();
  
    if(dest_coin  > MAXCOINS)
      maxflag = 1;
	
    dest_ob->add_money(coins);
  
    if(!maxflag && dest_ob && (int)dest_ob->query_money() == MAXCOINS)
      maxflag = 2; 
    
    if(!maxflag)
    {
      if (coins != 1)
	      this_player()->checked_say(
	       cap_name + " gives " + coins + " coins to " + capitalize(dest) +".\n");
	    else
	    {
	      this_player()->checked_say(
	        cap_name + " gives 1 coin to " + capitalize(dest) + ".\n");
      }
    }
	    
	  else if(maxflag == 2)
      this_player()->checked_say(
        cap_name + " gives " + (MAXCOINS - dest_coin) +
           " coins to " + capitalize(dest) + ".\n");
	  write("Ok.\n");
	  return 1;
  }
  
  if(!item_ob) return 1;
  
  weight = (int)call_other(item_ob, "query_weight");
  
  if (!dest_ob->add_weight(weight) && !power)
  {
	  write(capitalize(dest) + " can't carry any more.\n");
	  return 1;
  }
  
  this_player()->add_weight(-weight);
  
  if(dest_ob == this_player())
  {
    if(item_ob->id("moneyXX"))
    {
      if(!weight)
      { 
        this_player()->add_weight(-((int)item_ob->query_oldwt()));
      }
      if(weight < (int)item_ob->query_olderwt())
      {
        this_player()->add_weight(-((int)item_ob->query_olderwt()));
        item_ob->clear_olderwt();
        this_player()->add_weight(weight);
      }
    }
  }
  move_object(item_ob, dest_ob);
  this_player()->checked_say(
    cap_name + " gives " + item + " to " + capitalize(dest) + ".\n");
  write("Ok.\n");
  return 1;
}
