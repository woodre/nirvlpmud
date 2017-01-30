#include "/players/mokri/define.h"

main(string str) {
   string name, tmp;
   object who;
   
   if(!str || sscanf(str,"%s %s",name,str) != 2) {
      write("Syntax: at <player> <command>.\n");
      return 1; }
   
   who = find_player(name);
   if(!who) {
      write("No such player!\n");
      return 1; }
   
   tmp = file_name(ENV(TP));
   move_object(TP,ENV(who));
   command(str,TP);
   move_object(TP,tmp);
   
   return 1; }
