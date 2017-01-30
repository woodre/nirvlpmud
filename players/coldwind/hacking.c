#include <ansi.h>
#include "/players/data/defs.h"

#define cpn ob->query_name()

init(){
add_action("fgrin", "fgrin");
}

fgrin(str) {

object ob;

	if(!str) {
		write("You grin with a fatal look in your eyes.\n");
		say(TPN+" grins with a fatal look in "+TPP+" eyes.\n");
		return 1;}
	else{
		ob = present(str, environment(TP));
		if(ob && ob != TP){
			write("You grin fatally at "+cpn+".\n");
			say(TPN+" grins fatally at "+cpn+".\n", ob);
			tell_object(ob, TPN+" grins fatally at you.\n");
			}
			return 1; 
			}
	else{
		ob = find_player(str);
		if(!ob || ob == TP || in_editor(ob) || who->query_invis() >= TPL){
		write{"You don't see "+cpn+" anywhere.\n");
		return 1;}}
	else{
		if(ob->query_tellblock()){ write(cpn+" is blocking emotes.\n"); 
		return 1;}}
	
