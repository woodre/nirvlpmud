#include "/players/feldegast/closed/guild/defines.h"
do_command(str) {
  object *members;
  int i,max;
  members=allocate(CHANNEL->query_num_members());
  max=CHANNEL->query_num_members();
  members=CHANNEL->query_members();
  write(
"_________________________________________________________\n"+
"Name                   Rank     Where\n"+
"_________________________________________________________\n"
);
  for(i=0;i<max;i++) {
    write(members[i]->query_name());
    write("\t\t");
    write(present(GUILD_ID,members[i])->query_rank());
    write("\t");
    if(!members[i]->query_invis())
      write(environment(members[i])->short());
    write("\n");
  }
  write(
"_________________________________________________________\n"
  );
  return 1;
}
