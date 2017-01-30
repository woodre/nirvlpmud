#include "DEFS.h"

net_who()  {
int b,glev,artlev,deg,honor;
string type,art;
object ob;
ob = users();

write("\n");
write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"+
      "~~~~~~~~~~~~~~~\n");
write("Ninja         Quality    Honor      Belt      Line  Rank\n");
write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"+
      "~~~~~~~~~~~~~~~\n");

for(b=0;b<sizeof(ob);b+=1)  {
  if(!ob[b]->query_invis()) {
  if(present("CyberNinja Implants",ob[b]))  {
   glev = IP(ob[b])->guild_lev();
   artlev = IP(ob[b])->query_art_level();
   deg = IP(ob[b])->query_degree();
   write(" ");
   if( IP(ob[b])->sensei() && (glev < 13) ) write("*");
   else write(" ");
   write(pad(CAP(ob[b]->query_name()),15));
   write(pad(IP(ob[b])->guild_lev(),6));
   write("  ");
   honor = IP(ob[b])->query_honor();
   write(pad(honor_title(honor), 9));
   write("  ");
   if(deg > 0)
    write(pad(belt_color(artlev,art)+" "+deg,10));
   else write(pad(belt_color(artlev,art),10));
   if(IP(ob[b])->muffled() > 0) {write(pad("Off",6));}
   else write(pad("On",6));
   type = guild_title(glev);
   if(IP(ob[b])->referee())      type = "Referee";
   if(IP(ob[b])->head_referee()) type = "Head Referee";
   if(IP(ob[b])->minister())     type = "Minister";
   if(IP(ob[b])->shogun())       type = "Shogun";
   if(IP(ob[b])->daimyo())       type = "Daimyo";
   if(IP(ob[b])->regent())       type = "Regent";
   if(ob[b]->query_real_name() == EMP1) type = "Emperor";
   if(ob[b]->query_real_name() == EMP2) type = "Emperor";
   write(pad(type,24));
   write("\n");
   }
  }
 }
 write("~~~~~~~~~~~~~~~~~~~~~*Asterisks mark the Senseis~~~~~~~~~~~"+
      "~~~~~~~~~~~~~~~\n");
return 1;
}
