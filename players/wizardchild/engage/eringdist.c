/*
// This is quick and dirty code
// by Llandril the Wanderer
// llandril@baker.cnw.com
// 12-Nov-96
*/
#define eringpath "/players/wizardchild/engage/engagering"

init(){
	add_action("engage","engage");
	add_action("eringdistdest","eringdistdest");
}

short(){
	return "A distribution object for engagement rings (eringdist)";
}

long(){
	write("Type 'engage <person1> to <person2>'\n");
	write("Type 'eringdistdest'\n");
}

id(str){
	return str == "eringdist";
}

eringdistdest(str){
	destruct(this_object());
}

engage(str){
	string person1, person2;
	object theRing;
	
	sscanf(str,"%s to %s",person1,person2);
	if( !find_player(person1) || !find_player(person2) ) {
		write("Can't find them, sorry. Line 33.\n");
		return 1;
	}
	theRing = clone_object(eringpath);
	move_object(theRing,find_player(person1));
	theRing->set_lover(person2);
	theRing = clone_object(eringpath);
	move_object(theRing,find_player(person2));
	theRing->set_lover(person1);
	write("All done, why don't you let them know?\n");
}
