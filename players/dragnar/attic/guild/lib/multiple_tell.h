#include "/players/dragnar/guild/defs/def.h"
tell(str) {
	object play1;
	if(!str) {
	write("Tell who what?\n");
	return 1; }
	if(sscanf(str, "%s %s",player1,tell_msg)) {
	play1 = find_player(player1);
	if(!play1) {
	ppl_list = str;
	tell2();
	return 1; }
	tell_object(play1, capname+" tells you: "+tell_msg+"\n");
	write("You tell "+player1+": "+tell_msg+"\n");
	return 1; }
}
tell2() {
	if(!sscanf(ppl_list, "%s,%s %s",player1,player2,tell_msg)) {
	write("Invalid name given.\n");
	return 1; }
	if(sscanf(ppl_list, "%s,%s %s", player1,player2,tell_msg)) {
	play1 = find_player(player1);
	play2 = find_player(player2);
	if(!play2) {
	tell3();
	return 1;
	}
	if(play1) {
	tell_object(play1, capname+" tells "+player1+","+player2+": "+tell_msg+" \n");
	}
	if(play2) {
	tell_object(play2, capname+" tells "+player1+","+player2+": "+tell_msg+"\n");
	}
	write("You tell "+player1+","+player2+": "+tell_msg+"\n");
	if(!play1) {
	write(capitalize(player1)+" is not logged on.\n");
	}
	return 1; }
}
tell3() {
	string player3;
	object play3;
	if(!sscanf(ppl_list, "%s,%s,%s %s",player1,player2,player2,tell_msg) && !player3) {
	if(!play1 && !play2) {
	write("Neither one of them are loggeg on.\n");
	return 1; }
	tell_object(play1, capname+" tells you: "+tell_msg+"\n");
	write(capitalize(player2)+" is not logged on.\n");
	return 1; 
	}
	if(sscanf(ppl_list, "%s,%s,%s %s",player1,player2,player3,tell_msg)) {
	play1 = find_player(player1);
	if(player2) {
	play2 = find_player(player2);
	}
	if(player3) {
	play3 = find_player(player3);
	}
	if(!play1 && !play2 && !play3) {
	write("They are not logged on.\n");
	return 1; }
	if(play1) {
	tell_object(play1, capname+" tells "+player1+","+player2+","+player3+": "+tell_msg+"\n");
	}
	if(play2) {
	tell_object(play2, capname+" tells "+player1+","+player2+","+player3+": "+tell_msg+"\n");
	}
	if(play3) {
	tell_object(play3, capname+" tells "+player1+","+player2+","+player3+": "+tell_msg+"\n");
	}
	write("You tell "+player1+","+player2+","+player3+": "+tell_msg+"\n");
	if(!play1) { write(capitalize(player1)+" is not logged on.\n"); }
	if(!play2) { write(capitalize(player2)+" is not logged on.\n"); }
	if(!play3) { write(capitalize(player3)+" is not logged on.\n"); }
	return 1; }
}
