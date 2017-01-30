#include "/players/mythos/closed/ansi.h"

init()
{
if(this_player()->query_level() < 40) destruct(this_object());
  add_action("vecho","ve");
  add_action("vtell","vt");
}


get() { return 1; }
id(str) { return str=="vec"; }

vtell(str) {
object fangs,ob;
	int x;

	ob = users();
	write("You vtell: "+str+"\n");
	for (x = 0; x < sizeof(ob); x++) {
	if((fangs=present("nooneelse@vampire@fangs", ob[x]))&&fangs->query_telepathy()) 
	tell_object(ob[x],RED+":[ "+this_player()->query_name()+" ==>"+NORM+str+"\n");
	}
	return 1;
}


vecho(str) {
	object fangs,ob;
	int x;

	ob = users();
	write("You vecho: "+str+"\n");
	for (x = 0; x < sizeof(ob); x++) {
	if((fangs=present("nooneelse@vampire@fangs", ob[x]))&&
	fangs->query_telepathy()) tell_object(ob[x],RED+str+NORM+"\n");
	}
	return 1;
}
