/*  This is used in all the museum arena rooms */

status exit_cmd(string str){
	if(!str) return 0;
	if(str == "arena"){
		write("\nYou softly say \"exit arena\" ...\n"+
			"\t\tA beam of light wraps around you...\n\n\n");
		say(TP->QN+" softly says \"exit arena\" ... \n"+
			"\t\t\tA beam of light wraps around "+TP->QN+"...\n");
		MO(TP, "/players/zeus/museum/lounge.c");
		command("look", TP);
		TR(environment(TP), TP->QN+" appears in a flash of light.\n",
			({TP}));
		return 1;
	}
	else return 0;
	return 1;
}

feel(){ return "no"; }
