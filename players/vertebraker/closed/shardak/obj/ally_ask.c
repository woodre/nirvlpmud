#include "../def.h"
#define wop "34394893849834"

string save_nm;
string recruiter;

drop() { return 1; }

id(str) { return (str=="ally_ask_ob"); }

init()
{
  add_action("confirm", wop);
}

ask(nm)
{
  recruiter=nm;
  save_nm=environment()->query_real_name();
  call_out("time_out", 60);
  command(wop, environment());
  return 1;
}

confirm()
{
  input_to("okay_it");
  return 1;
}

okay_it(str)
{
  object aob;
  if(str!="y" && str != "Y" && str != "yes" && str != "YES")
  {
    write("You have decided not to enter into the alliance with Evil.\n");
    return 1;
  }
  else
  {
    write("Shardak telepaths: You have chosen wisely.\n");

    aob = clone_object(OBJDIR + "allymark");
    move_object(aob, this_player());      /* it is without weight */
    command("aupdate", this_player());

    CHANNELD->broadcast(this_player()->query_name() + " \
is now an ally of the Servants.\n",
      0, "[Servants]");
    write(           "\
      You are now an ally of the Servants of Shardak.\n\
      Examine the mark you have received for more information.\n");

    write_file(LOGDIR + "allies", ctime()[4..15] + " : " +
      capitalize(recruiter) +
      " made " + (string)this_player()->query_name() + " an ally.\n");
    while(remove_call_out("time_out") != -1);
    destruct(this_object());
    return 1; 
  }
}

time_out(str)
{

   if(find_player(recruiter))
      tell_object(find_player(recruiter), "\n\tTime has expired.  "+capitalize(save_nm)+" is NOT an Ally.\n\n");
    if(environment())
      tell_object(environment(), "\n\tTime has expired. You are NOT an Ally.\n\n");
    destruct(this_object());
  return;
}
