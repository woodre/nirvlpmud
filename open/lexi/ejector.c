/*An eject command for workrooms by Mishtar*/
/*add the following with your includes as necessary*/

#include "/bin/gender.c"

#define tp this_player()
#define tpn this_player()->query_name()
#define tpp posess(tp)
#define cpn capitalize(str)

/*Under this line: if(this_player()->query_real_name()==OWNER) add*/

	add_action("kiss_off","kiss_off");}

int kiss_off(string str){
	string aroom,name;
	object who;
	aroom = "/room/vill_green.c"; 
	if(!str){ write("Kick out who?\n"); return 1;}
	if(!present(str, environment(tp))){ write(cpn+" is not in your room.\n"); return 1;}
	if(sscanf(str,"%s",name));
	who = find_player(name);
	if(str != OWNER){
		write("You kick "+cpn+" out of your room!\n");
		tell_room(aroom, cpn+" drops out of the sky from a great height.\n");
		move_object(who,aroom);
		tell_object(who, tpn+" kicks you out of "+tpp+" room!\nYou have been moved to "+
			(string)environment(who)->short()+".\n");
		say(tpn+" kicks "+cpn+" out of "+tpp+" room!\n");
		return 1;}}