#include "../def.h"

status main(string str, object gob, object player)
{
  int len, s;
  object file;

  if(!str)
  {
    file = HELP+"base.c"
    if(file_size(file) > 0)
    {
      file->help(gob, player);
      return 1;
    }
  }
  
  str = lower_case(str);
  str = implode(explode(str, " "), "_");  
  len = strlen(str);
  s = 0;
  
  while(s < len) 
  {
    if ((str[s] < 'a' || str[s] > 'z') &&	(str[s] < '0' || str[s] > '9') && str[s] != '_')
    {
      tell_object(player, "No mhelp on that subject.\n");
      return 1;
    }
    s += 1;
  }
  
  file = SPELLS+str+".c";
  if(file_size(file) > 0)
  {
    file->help(gob, player);
    return 1;
  }
  
  file = HELP+str+".c";
  if(file_size(file) > 0)
  {
    file->help(gob, player);
    return 1;
  }
  
  tell_object(player, "No mhelp on that subject.\n");
  return 1;
}  
  
 

