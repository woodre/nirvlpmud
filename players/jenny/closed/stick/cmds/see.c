#include "/players/jenny/define.h"

main(str) {
   object ob;
   string who,arg;
   if(!str || sscanf(str,"%s %s",who,arg) != 2) {
      FAIL("Syntax: 'see <who> [a/h]'\n");
      return 0; }
   ob = find_player(who);
   if(!ob) {
      write("Not logged on!\n");
      return 1; }
   ob = present("qt",ob);
   if(!ob) {
      write("Player doesn't have a qt.\n");
      return 1; }
   if(arg == "h") {
      ob->history(); }
   if(arg == "a") {
      ob->alias();
   }
   else write("Syntax: 'see <who> [a/h]'\n");
   return 1; }
