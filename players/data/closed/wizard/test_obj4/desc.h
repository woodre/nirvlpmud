short(){
	if(offhand) return offhand->short()+" (offwielded)";
	return;
}

long(){
	if(offhand) return offhand->long();
	else return;
}


extra_look(){
	if(this_player()){
		if(this_player() != USER){
			return USERN+" is a Warrior";
		}
		else{
			return "As a Warrior you may use 'warrior' for help on commands";
		}
	}
	return USERN+" is a Warrior";
}

