#include "/players/pavlik/guild/mages/defs.h"
inherit "players/pavlik/guild/mages/inherit/command";

reset(arg) {
  if(arg) return;
  set_verb("mbug");
  set_name("Mage Bug");
  set_color_name(HIC+"Mage Bug"+NORM);
  set_rank(1);
  set_descrip(
	"Log a bug.\n" +
	"Please report any possible bugs using this " +
	"command.  If you need to file a detailed bug report you " +
	"can use the Post Office to mail the Mage Guild's Administrator\n" +
	"See Also: mlog\n"
  );
}


cmd(str)
{
  if(!str)
  {
	notify_fail("Use: mbug <message> to log a bug\n");
	return 0;
  }
  write_file(BUGLOG,
  "["+ctime()[4..15]+"] "+capitalize(tp->query_real_name())+" "+basename(environment(tp))+" : "+str+"\n");
  write("Your "+HIR+"bug report"+NORM+" has been "+HIY+"logged"+NORM+".\n");
  return 1;
}

