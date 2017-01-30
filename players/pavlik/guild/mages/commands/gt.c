#include "/players/pavlik/guild/mages/defs.h"
inherit "players/pavlik/guild/mages/inherit/command";
inherit "players/pavlik/guild/mages/inherit/string";

reset(arg) {
  if(arg) return;
  set_verb("gt");
  set_name("Guild Tell");
  set_color_name(HIC+"Guild Tell"+NORM);
  set_rank(1);
  set_descrip(
	"Communicate with other guild members.\n" +
	"See Also: gc\n"
  );
}


cmd(str) {
  string pre;
  int i;

  if(!str)
  {
	notify_fail("Tell guild members what?\n");
	return 0;
  }

  if(guild->query_muffled() == 1)
  {
	notify_fail("You are muffled.\n");
	return 0;
  }

  /*str = COLOR_PARSER->parse_pcodes(str) + NORM;*/
  
  if( str[0] == ':' )
    pre = HIC+"["+HIR+"*"+HIC+"] "+NORM;
  else
    pre =  CYN+"["+HIC+ME+NORM+CYN+"]: "+NORM;

  CHAND->channel_message( CHAN_NAME, str, pre );
  return 1;

}
