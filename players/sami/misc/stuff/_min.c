#include "/players/mokri/define.h"

main(string str) {
   string what, where;
   
   if(!str || sscanf(str,"%s %s",str,what) != 2) {
      write("Do what where now?\n");
      return 1; }
   
   where = file_name(ENV(TP));
   str = "/players/mokri/cmds/funcs/modify_path"->modify_path(str);
   if(extract(str,strlen(str)-2) != ".c") str += ".c";
   if(file_size(str) < 2)
      {
      write("No such room.\n");
      return 1;
   }
   move_object(TP,str);
   command(what,TP);
   move_object(TP,where);
   
   return 1; }
