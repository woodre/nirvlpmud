main(str) {
   string name;
   object who, what;
   
   if(!str || sscanf(str,"%s %s",name,str) != 2)
      {
      write("Syntax: deston <player> <object>\n");
      return 1;
   }
   
   who = find_player(name);
   if(!who)
      {
      write("No such player.\n");
      return 1;
   }
   
   what = present(str,who);
   if(!what)
      {
      write("No such object on player.\n");
      return 1;
   }
   destruct(what);
   write("Ok.\n");
   return 1; }
