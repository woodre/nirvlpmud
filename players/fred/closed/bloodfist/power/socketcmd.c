/* Valid Command Syntax:
   1. socket <gem>               - socket <gem> into first available weapon
   2. socket <weapon>            - socket first available gem into <weapon>
   3. socket <gem> into <weapon> - socket <gem> into <weapon>
*/
#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  string one, two;
  string tstr, gstr, wstr, first;
  object temp, temp2, gem, wep;
  object *alli;
  int x, y, waswielded;

  if((string)User->query_real_name() != "fred" && 
     (string)User->query_real_name() != "forbin") return 0;  
  if(User->query_ghost()) return 0;
  if(!PO->level_check(4)) return 0;

  if(!str) 
  {
    write("Socket what?\n"); 
    return 1;
  }
  else if(sscanf(str, "%s into %s", one, two) == 2)                 /* syntax 3 */
  {
    temp = present(one, environment(PO));
    temp2 = present(two, environment(PO));
    if(!temp)
    {
      write("You don't have a "+one+".\n"); 
      return 1;
    }
    if(!temp2)
    {
      write("You don't have a "+two+".\n"); 
      return 1;
    }
    if(!temp->query_is_bf_gem())
    {
      write(one+" is not a bloodfist gem.\n"); 
      return 1;
    }
    if(!temp2->is_weapon())
    {
      write(two+" is not a weapon.\n"); 
      return 1;
    }
    gem = temp;
    wep = temp2;
  }
  else if(sscanf(str, "%s", one) == 1)
  {
    temp = present(one, environment(PO));
    if(!temp)
    {
      write("You don't have a "+str+".\n"); 
      return 1;    
  }
    if(temp->query_is_bf_gem())                                     /* syntax 1 */
    {
      gem = temp;
      alli = all_inventory(environment(PO));
      x = sizeof(alli);
      while(y < x && !wep)
      {
        if(alli[y]->query_bloodfist_wep_shadow())
          wep = alli[y];
        y++;
      }
    }
    if(temp->is_weapon())                                           /* syntax 2 */
    {
      wep = temp;
      alli = all_inventory(environment(PO));
      x = sizeof(alli);
      while(y < x && !gem)
      {
        if(alli[y]->query_is_bf_gem())
          gem = alli[y];
        y++;
      }
    }
  }
  if(!wep)
  { 
    write("You don't have a forged weapon with a socket.\n"); 
    return 1;
  }
  if(!gem)
  {
    write("You don't have a bloodfist gem to socket into the weapon.\n"); 
    return 1;
  }
  if(!gem->query_held())
  {
    write("You must hold the gem first.\n"); 
    return 1;              
  }
  if(!wep->query_bloodfist_wep_shadow())
  {
    write("You cannot socket a weapon that hasn't been forged.\n"); 
    return 1;
  }
  if(!wep->query_forged())
  {
    write("You cannot socket a weapon that hasn't been forged.\n"); 
    return 1;
  }
  if(wep->query_socketed())
  {
    write("That weapon has already been socketed with a gem.\n"); 
    return 1;
  }
  else if(!wep->query_socket())
  {
    write("That weapon has not been forged with a socket.\n"); 
    return 1;
  }
  if(wep->query_wielded()) 
  {
    waswielded = 1;   
  }
  if(waswielded) command("unwield "+wep->query_name(), environment(PO));
  tstr = (string)gem->short(); 
  tstr = delete_colour(tstr); 
  tstr = lower_case(tstr);
  gstr = tstr;
  tstr = (string)wep->short(); 
  tstr = delete_colour(tstr); 
  tstr = lower_case(tstr);
  if(sscanf(tstr, "a %s", first) == 1) 
    wstr = first;
  else if(sscanf(tstr, "the %s", first) == 1) 
    wstr = first;            
  else 
    wstr = tstr;    
  write("You socket your "+wstr+" with "+gstr+".\n");
  say(User->query_name()+" sockets "+User->query_possessive()+" "+wstr+" with "+gstr+".\n");    
  wep->socket(gem->query_gname(), gem->query_spec(), gem->query_ws());
  wep->set_socketed();
  destruct(gem);
  command("wield "+wep->query_name(), environment(PO));
  return 1;
}