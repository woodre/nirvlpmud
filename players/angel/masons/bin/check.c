#include "defs.h"

status main(string str, int guild_rank) {
  string who;
  object ckguild;
  int exp, rank, loan;
   
if(guild_rank < 30) {
       write("You must have a guild rank of 30 to use this command.\n");
       return 1;
     }
     if(!str || sscanf(str, "%s", who) != 1) {
       write("Useage:  check <member>\n");
       return 1;
     }
     if(!find_player(who)) {
       write(capitalize(who)+" is not on.\n");
       return 1;
     }
     if((int)find_player(who)->query_invis() > 0 && guild_rank < 100) {
       write(capitalize(who)+" is not on.\n");
       return 1;
     }
     ckguild = present(MGOB_ID, find_player(who));
     if(!ckguild) {
       write(capitalize(who)+" is not a member.\n");
       return 1;
     }
     rank = (int)ckguild->query_glevel();
     exp = (int)ckguild->query_gexp();
  loan = (int)ckguild->query_loan();
     write((string)find_player(who)->short()+"\n");
     write("Level: "+(int)find_player(who)->query_level()+"\n");
     write("Experience: "+(int)find_player(who)->query_exp()+"\n");
     write("Gold coins: "+(int)find_player(who)->query_money()+"\n");
     write("Guild rank: "+rank+"\n");
     write("Guild exp: "+exp+"\n");
     write("Guild loan: "+loan+"\n");
     return 1;
}
