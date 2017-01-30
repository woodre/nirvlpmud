#include "/players/mokri/define.h"

main(str) {
   string other;
   object obj, who;
   
   if(!str) {
      write("Syntax: rc <player || object> <object>.\n"+
         "        If one argument is given, displays code for 'argument' in players environment or inventory.\n"+
         "        If two arguments are given, displays code for 'argument2' on or in environment of 'argument1.\n");
      return 1; }
   
   if(sscanf(str,"%s %s",str,other) == 2)
      {
      who = find_player(str);
      str = other;
      if(!who)
         {
         write("No such player.\n");
         return 1;
      }
   }
   else
      who = this_player();
   obj = present(str,who);
   if(!obj) obj = present(str,ENV(who));
   if(!obj) {
      write("No such object to rc.\n");
      return 1;
   }
   
   str = file_name(obj);
   if(sscanf(str,"%s#%s",str,other));
   write("FILE: /"+str+".c\n\n");
   cat("/"+str+".c");
   return 1; }
