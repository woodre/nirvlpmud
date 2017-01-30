wimpy_check(arg){
	if(!arg) return;
	else{
		if(blocked_wimpy){
			write("You cannot adjust wimpy so soon after a charge!\n");
			return 1;
		}
		return;
	}
	return;
}

