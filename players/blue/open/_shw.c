#include "/players/blue/closed/guild/inc/command.h"

command_shw() {
   object *pepl, mark;
   int i, n;
    write("--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--\n");
   pepl = users();
   n = 0;
   i = 0;
   while(n < sizeof(pepl)) {
       mark = present("shadow-mark", pepl[n]);      
       if( mark &&  !(pepl[n]->query_invis()&&
              pepl[n]->query_level() > LEVEL)&&ENV(pepl[n])) {
         write(CAP(pepl[n]->query_name()));
         if(strlen(pepl[n]->query_name()) < 8) write("\t");
         write("\t"+mark->query_shlevel());
         write("\t"+environment(pepl[n])->short()+"\n");
         i += 1;  
      }
      n += 1;
   }
   write("--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--<<>>--\n");
   write(i+" shadows logged on.\n");
   return 1;
}

help() {
   write("usage: 'shw'\nList all the shadows currenty playing.\n");
   return 1;
}
