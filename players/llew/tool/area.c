#include "/players/llew/closed/ansi.h"

area() {
   object *peep;
   int x;
   write(HIC+pad("",80,'~')+"\n"+NORM);
   write(pad("Name",15)+pad("Lev",5)+pad("Ex",5)+pad("Guild",15));
   write(pad("Hp/Mhp",9)+pad("Room",30)+"\n");
   write(HIC+pad("",80,'~')+"\n"+NORM);
   for(x=0;sizeof(peep=users())>x;x++) {
      if(environment(peep[x]) && creator(environment(peep[x])) == "llew" && peep[x]->query_real_name() != "llew") {
         write(pad(peep[x]->query_name(),15)+pad(peep[x]->query_level(),5)+
            pad(peep[x]->query_extra_level(),5)+pad(peep[x]->query_guild_name(),15)+
            pad(peep[x]->query_hp(),-4)+"/"+pad(peep[x]->query_mhp(),4)+
            pad(environment(peep[x])->short(),30)+"\n");
      }
   }
   write(HIC+pad("",80,'~'));
   write("\n"+NORM);
   return 1;
}
