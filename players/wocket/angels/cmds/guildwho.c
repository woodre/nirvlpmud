#include "/players/wocket/closed/ansi.h"

guildwho(){
string angels;
object *everyone,member;
object mem;
int i;
everyone = users();
write(CYN+"-----------------------------------------------------------------------------\n"+NORM);
write("Name\t\tLevel\tGender\tRank\tLocation\n");
write(CYN+"-----------------------------------------------------------------------------\n"+NORM);
write("\n");
for(i = 0; i < sizeof(everyone); i++){
  mem=everyone[i];
    member = present("ifonlybardscouldntmakeobjects",mem);
   if(member){
angels = mem->query_name()+"      \t";
  angels += mem->query_level()+"\t";
  angels += mem->query_gender()+"\t";
  angels += member->query_rank()+"\t";
  angels += environment(mem)->short()+"\n";
write(angels);
  }
}
write(CYN+"-----------------------------------------------------------------------------\n"+NORM);
}

