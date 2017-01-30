main(str) {
   int x, a;
   object *us;
   string name, who;

   us = users();

   if(!str) {
      for(x = 0; x < sizeof(us); x++) {

         if(us[x]->query_invis())
            name = "("+capitalize(us[x]->query_real_name())+")";
         else
            name = capitalize(us[x]->query_real_name());

         write(x+". "+name+"\n");

      }

      return 1; }

   if(sscanf(str,"%d %s",a,who) != 2 || a >= sizeof(us) || a < 0)
      {
      write("Please select a number between 0 and " + (sizeof(us) - 1) + " to destruct, and supply a name.\n");
      return 1;
   }

   if(us[a]->query_real_name() != who) {
      write("No such name at position " + a + ".\n");
      return 1;
   }

   destruct(us[a]);
   write("Done.\n");
   return 1; }
