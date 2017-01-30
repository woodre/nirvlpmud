#include <ansi.h>
object k;
string msg;
#define TPRN this_player()->query_real_name()

id(str) { return str == "tattoo" || str == "teller"; }

long()
{
	write("This is a swastika tattoo, on your kneecap. It\n"+
		  "lets you stay in contact with Chip all day long\n"+
		  "You may now	'chelp'\n");
}

extra_look()
{
	if(environment() == this_player())
		write("You have tattoo of a swastika on your kneecap.\n");
	else
		write(environment()->query_name() + " has a tattoo of a swastika on " + possessive(environment()) + " kneecap.\n");
}

 init()
 {
  add_action("helper","chelp");
  add_action("kcomm","cm");
  add_action("kmsg","cmmsg");
  add_action("update_scar", "tat2");
}

helper()
{
  write("This tattoo will allow you to speak with Chip all day long.\n\n"+
        "Usage:\n"+
    "chelp :    Displays this help file.\n"+
    "cm :    Check to see if Chip is online.\n"+
    "cm <msg> :    Send Chip a message.\n"+
    "cmmsg <msg> :    Leave Chip a message if he is gone.\n"+
    "tat2  :    Updates your tattoo if any changes have been made.\n");
  return 1;
}

 kmsg(str)
{
  if(!str) return 0;
     msg = ctime()+" | "+GRN+"=-="+HIG+"+*+"+NORM+GRN+"=-= "+NORM+capitalize(TPRN)+": " +str;
  write_file("/players/chip/closed/cmmsg.txt",msg+"\n");
  write("Message sent.\n");
  return 1;
}

kcomm(str)
{
  k = find_player("chip");
  if(!k)
  {
	  write("Chip is not online.\n");
	  return 1;
  }
  
  if(!str)
  {
	  write("Chip is online.\n");
	  return 1;
  }

  msg = GRN+"-"+HIG+"+ +"+NORM+GRN+"- "+NORM+capitalize(TPRN)+": " +str;
  tell_object(k,msg+"\n");
  write(msg+"\n");
  return 1;
}

int update_scar(string str)
{
   object ob;
   ob = clone_object("/players/chip/closed/teller.c");
   
   destruct(this_object());
   move_object(ob, this_player());
   write("Your scar has been updated.\n");
   return 1;
}

drop() { return 1; }