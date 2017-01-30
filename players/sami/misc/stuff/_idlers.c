#define CAP         capitalize
main() {
   object *us;
   int x, a, time, mins, hours;
   string stime, name;
   us = users();
   write("    NAME        TIME IDLE\n"+
      "================================\n");
   for(x = 0; x < sizeof(us); x++) {
      if(us[x]->query_invis())
         name = "("+CAP(us[x]->query_real_name())+")";
      else
         name = CAP(us[x]->query_real_name());
      time = query_idle(us[x]); stime = time + " seconds";
      if(time > 60) {
         mins = time / 60; time = time - (mins * 60);
         stime = mins+" minutes "+time+" seconds"; }
      if(mins > 59) {
         hours = mins / 60; mins = mins - (hours * 60);
         stime = hours+" hours "+mins+" minutes "+time+" seconds"; }
      if(x < 9) write(" ");
      write((x+1)+". "+name);
      for(a = 12; a > strlen(name); a--) write(" ");
      write(stime+"\n");
   }
   return 1; }
