#include <ansi.h>
#include "../defs.h"

status main(string str, object PO, object User)
{
	string pre;
	
	if(!CHAND){
		write("The guild line is currently down.\n");
		return 1;
	}
	
	if(!str){
		write("What would you like to say to your fellow Rogues?\n");
		return 1;
	}
	
	pre = "";
  	pre += RED+"(XX "+WHT+"Rogue"+RED+" XX)"+WHT+" "+OFF+OFF;
  	
  	if(str[0] == ':')
  		pre += NORM;
  	else
  		pre += User->query_name()+":   "+NORM;
  	
  	CHAND->channel_message(CHAN_NAME, str, pre);
  	return 1;
}
