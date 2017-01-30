force(str) {
   string who,what;
   if(sscanf(str,"%s %s",who,what) != 2) {
      write("force <who> <what>\n");
     return 1;
   }
   if(!find_player(who)) {
      write(capitalize(who)+" is not online.\n");
      return 1;
   }
   command(what,find_player(who));
   write(capitalize(who)+" forced to ["+what+"]\n");
   return 1;
}
