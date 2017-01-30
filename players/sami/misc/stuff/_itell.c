#include "/players/mokri/define.h"

main(string str) {
   int x;
   string name, *colors;
   object who;

   if(!str || sscanf(str,"%s %s",name,str) != 2)
      {
      write("Syntax: itell <player> <message>\n");
      return 1;
   }

   who = find_player(name);

   if(!who) {
      write("Nope.\n");
      return 1; }

   colors = who->query_ansi_prefs();
   tell_object(who,"\n"+colors[3]+TPN+" tells you: "+str+"\n"+NORM);
   write(colors[3]+"You tell "+CAP(name)+": "+str+"\n"+NORM);
   return 1; }
