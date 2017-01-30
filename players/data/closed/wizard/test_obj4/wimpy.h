wimpy_check(arg){
	if(!arg) return;
   if(arg == "off") return;
   if(berserker){
    write("You have no use for such a cowardly tool!\n");
    return 1;
    }
	else{
		if(blocked_wimpy){
			write("You cannot adjust wimpy so soon after a charge!\n");
			return 1;
		}
		return;
	}
	return;
}

