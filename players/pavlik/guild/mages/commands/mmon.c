inherit "players/pavlik/guild/mages/inherit/command";
inherit "players/pavlik/guild/mages/inherit/health_monitor";
#include "/players/pavlik/guild/mages/defs.h"
#include "/players/pavlik/guild/mages/include/string.h"

reset(arg) {
  if(arg) return;
  set_verb("mmon");
  set_name("Mage Monitor");
  set_color_name(HIC+"Mage Monitor"+NORM);
  set_rank(1);
  set_descrip(
	"Mage Monitor.\n" +
	"This is the specialized health monitor that will display vital game " +
	"stastics as well as pertinent Mage guild information.\n" +
	"\n" +
	"Use 'mmon' to display your current status.\n" +
	"Use 'mmon <on/off>' to turn the monitor on or off.\n"
  );
}


cmd(str)
{
  if(str && str == "on")
  {
	guild->set_monitor(1);
	write("Mage Monitor is: "+CYN+"on"+NORM+".\n");
	write("The monitor will display in combat.\n");
  }
  else if(str && str == "off")
  {
	guild->set_monitor(0);
	write("Mage Monitor is: "+CYN+"off"+NORM+".\n");
	write("The monitor will not display in combat.\n");
  }
  else
  {
	if(guild->query_monitor()) write("The monitor will automatically display in combat.\n");
	else write("The monitor will not automatically display in combat.\n");
	health_monitor(tp);
  }
  return 1;
}

