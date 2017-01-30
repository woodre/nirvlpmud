#include "/players/pavlik/guild/mages/defs.h"
inherit "players/pavlik/guild/mages/inherit/command";

reset(arg) {
  if(arg) return;
  set_verb("mlog");
  set_name("Mage Log");
  set_color_name(HIC+"Mage Log"+NORM);
  set_rank(1);
  set_descrip(
	"Log a comment/suggestion.\n" +
	"Your feedback can improve the " +
	"guild.  Please use this command to submit comments or " +
	"suggestions to the Mage Guild's Administrator.\n" +
	"See Also: mbug\n"
  );
}

cmd(str)
{
  if(!str)
  {
	notify_fail("Use: mlog <message> to log a comment/suggestion.\n");
	return 0;
  }
  write_file(COMMENTLOG, "["+ctime()[4..15]+"] "+capitalize(tp->query_real_name())+": "+str+"\n");
  write("Your "+HIY+"comment"+NORM+" has been "+HIY+"logged"+NORM+".\n");
  return 1;
}

