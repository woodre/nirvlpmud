#include <ansi.h>
#include "../def.h"

int tot_pks;

convert_num(x)
{
    switch(x)
    {
      case 1: return "once";
      case 2: return "twice";
      case 3: return "thrice";
      default: return x + " times";
    }
}

void
analyze_this(string who, object mark)
{
    mixed pk;
    int i;

    pk = (string *)mark->query_pkills();
    if((i = member_array(who, pk)) > -1)
    {
      pk = pk[i+1];
      for(i = 0; i < sizeof(pk); i ++){
        write("\t" + pk[i] + "\n");
      tot_pks += 1;
     }
    }
}

status
main(string arg)
{
    object mark;
    mark = present(OBJID, this_player());
    if(!mark) return 0;
    if(arg)
    {
      if(member_array(lower_case(arg), (string *)mark->query_pkills()) == -1)
        return (write("You have never slain that player as a Shardak.\n"), 1);
      else write("\n\t\t" + BOLD + capitalize(arg) + NORM + "\n");
      analyze_this(lower_case(arg), mark);
      write("\n");
      return 1;
    }
    else
    {
      int i;
      string *pk;
      pk = (string *)mark->query_pkills();
      tot_pks = 0;
      if(!pk || !sizeof(pk)) return (write("You haven't slain anyone as a Shardak.\n"), 1);
      write(HIR + "\n\t\t\t[PkList]\n\n" + NORM);
      for(i = 0; i < sizeof(pk); i += 2)
      {
        write("   " + (i/2+1) + ": " + BOLD + capitalize(pk[i]) + NORM + "\n");
        analyze_this(lower_case(pk[i]), mark);
        write("\n");
      }
      write(HIW+"Total PK's: "+HIR+tot_pks+NORM+"\n");
      write(HIW+"Total PK Points: "+HIR+mark->query_tot_pkills()+NORM+"\n");
      write("\n");
      return 1;
    }
}
