#include "/players/mokri/define.h"

main(str) {
   string name;
   object who;
   
   if(!str || sscanf(str,"%s %s",name,str) != 2)
      {
      write("Syntax: cloneto <player> <path_of_object>\n");
      return 1;
   }
   
   who = find_player(name);
   if(!who)
      {
      write("No such player.\n");
      return 1;
   }
   
   str = "/players/mokri/cmds/funcs/modify_path"->modify_path(str);
   
   if(extract(str,strlen(str)-2) != ".c") str += ".c";
   if(file_size(str) < 2 || !TP->valid_read(str))
      {
      write("No such file to clone.\n");
      return 1;
   }
   move_object(clone_object(str),who);
   write("Ok.\n");
   return 1; }
