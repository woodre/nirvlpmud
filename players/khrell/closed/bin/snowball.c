#include "/obj/ansi.h"

status main(string str, object ob, object User) 
{
  object who;
  int x,y;
  
  if(!str)
  { 
    write("Use -> snowball <name> <num>\n");
    return 1; 
  }
  if(!sscanf(str, "%s %d", str, x)) 
  {
    write("Use -> snowball <name> <num>\n");
    return 1; 
  }
  
  who = find_player(str);

  if(!who)
  {   
    write("That person isn't logged on. \n");  
    return 1; 
  }
  
  while(y < x)
  {
    command("clone /players/wizardchild/toys/snowball.c", this_player());
    command("throw snowball at "+str+"", this_player());
    y++;
  }
  command("haha "+str+"", this_player());
  return 1; 
}
