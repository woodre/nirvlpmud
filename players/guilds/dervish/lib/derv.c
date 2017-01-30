#include "../defs.h"
#include <ansi.h>

status main(string str, object PO, object User)
{
  string pre;
  
	if(!CHAND) {
		write("The guild line is currently down.\n");
		return 1;
	}
	
	if(!str) {
		PO->dervishes();
		return 1;
	}
	
  pre = RED+BOLD+"**DERVISH** ";
  
  if( str[0] == ':' )
    pre += NORM;
  else
    pre += this_player()->query_name() + ":   "+ NORM;
    
	CHAND->channel_message( CHAN_NAME, str, pre );
	return 1;
}
