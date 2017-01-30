static string name, typea;
static int size, save_flaga, worn, ac, set_ac_flag;
static object worn_by, next;

link(ob)
{
  next = ob;  
}

remove_link(str)
{
  object ob;
  if(str == name) 
  {
    ob = next;
    next = 0;
    return ob;
  }
  if(next)
    next = call_other(next, "remove_link", str);
  return this_object();
}

rec_short()
{
  if(next)
    return name + ", " + call_other(next, "rec_short");
  return name;
}

test_type(str)
{
  if(str == typea)
    return this_object();
  if(next)
    return call_other(next, "test_type", str);
  return 0;
}

tot_ac()
{
  if(next)
    return ac + call_other(next, "tot_ac");
  return ac;
}

query_type()  { return typea; }
query_worn()  { return worn; }
query_name()  { return name; }
armor_class() { return ac;   }

remove(str) 
{
  if(!id(str)) return 0;
  if(!worn) 
  {
    return 0;
  }
  call_other(worn_by, "stop_wearing",name);
  worn_by = 0;
  worn = 0;
  return 1;
}

set_ac(a) 
{ 
  ac = a; 
  set_ac_flag = 7; 
}
      
set_type(t) 
{
  if(ac > 0 || !set_ac_flag) 
  {
    if(t !="armor" && t !="helmet" && t != "boots" && t != "ring" && 
       t !="amulet" && t != "shield" && t != "misc" && t != "mine") 
    destruct(this_object());
  }
 typea = t;
}

take_off() 
{
   worn_by = this_player();
   worn_by = 0;
   worn = 0;
   return 1;
}
 
shield_bonus()
{
  int stealth_amt;
  stealth_amt = 0;
  if((int)GOB->query_venomed())
  {
    if((string)GOB->query_shapetype() == "shield")
    {
      TOM "You partially deflect your enemies attack with your shield arm!\n");
      stealth_amt += random(USER->query_attrib("ste") / 4) + 6;
    }    	
    stealth_amt += venom_defense();
    if((int)GOB->query_hardened())
    {
      if(!random(4))
      {
        TOM BOLD+"Your opponents strike rings out against your armor!"+NORM+"\n");
      }
      stealth_amt += USER->QL * 2 + random(USER->QL);
    }    
    return stealth_amt;
  }
  return 0;
}
