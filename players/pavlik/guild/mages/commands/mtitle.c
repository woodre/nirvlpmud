#include "/players/pavlik/guild/mages/defs.h"
inherit "players/pavlik/guild/mages/inherit/command";

reset(arg) {
  if(arg) return;
  set_verb("mtitle");
  set_name("Mage Title");
  set_color_name(HIC+"Mage Title"+NORM);
  set_rank(15);
  set_descrip(
	"Set a custom title.\n" +
	"See Also: color\n"
  );
}


cmd(str)
{

  if(tp->query_guild_rank() < query_rank())
    return 0;

  if(!str)
  {
	notify_fail("Set your title to what?\n");
	return 0;
  }

  str = COLOR_PARSER->parse_pcodes(str);

  tp->set_title(str);
  write("You change your title.\n");
  write("You are now:\n"+tp->short()+"\n");
  return 1;

}

