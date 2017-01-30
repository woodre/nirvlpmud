#include "../x.h"

int cmd_tell(string str)
{
 string who, what;
 object ob;
 if((string)TP->RN != "x") return 0;
 if(!str || sscanf(str,"%s %s",who,what) < 2) return 0;
 if(!(ob=find_player(who))) return 0;
 tell_object(ob, "X tells you: "+what+"\n");
 write("You tell "+who+" "+what+"\n");
 ob->add_tellhistory("x told you: "+what);
 return 1;
}
