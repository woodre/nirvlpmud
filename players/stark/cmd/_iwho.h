cmd_idlers() {
   object *us;
   int x, time, mins, hours;
   string stime, name, lev, exlev, vis;
   us = users();
   write("\n");
   for(x = 0; x < sizeof(us); x++) {
      name = us[x]->query_real_name();
      lev = us[x]->query_level();
      exlev = us[x]->query_extra_level();
      vis="";
      if(us[x]->query_invis()) { vis = ""+HIR+"*"+NORM+""; }
      time = query_idle(us[x]); stime = time + " seconds";
      if(time > 60) {
         mins = time / 60; time = time - (mins * 60);
         stime = mins+" minutes "+time+" seconds"; }
      if(mins > 59) {
         hours = mins / 60; mins = mins - (hours * 60);
         stime = hours+" hours "+mins+" minutes "+time+" seconds"; }
      write(""+pad("("+lev+"+"+exlev+")",12)+""+NORM+""+pad(name,15)+" "+stime+""+vis+"\n");
   }
   return 1; }
