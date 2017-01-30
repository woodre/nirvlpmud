

back_me_up(){
    write("Backing up Circle stats....\n");
    save_object(SAVE_PATH2+NAME);
    return 1;
}	

save_circle(x){
    save_object(SAVE_PATH+NAME);
    if(!x)
	write("Saving Circle...\n");
    return 1;
}

restore_circle(x){
    if(x)
	write("Restoring Circle...\n");
    restore_object(SAVE_PATH+NAME);
    return 1;
}

update_obj(x, y){
    save_object(SAVE_PATH+NAME);
    if(this_player())
	call_other(this_player(), "stop_wearing", this_object(), "shield", 1);
    else if(y)
	call_other(y, "stop_wearing", this_object(), "shield", 1);
    move_object(clone_object(GUILD_FILE), environment());
    if(!x)
	write("Updating Circle...\n");
    destruct(this_object());
    return 1;
}

endurance_mon(){
    if(endurance_monitor)
    {
	write("Endurance monitor is now off.\n");
	endurance_monitor = 0;
    }
    else
    {
	write("Endurance monitor is now on.\n");
	endurance_monitor = 1;
    }
    save_object(SAVE_PATH+NAME);
    return 1;
}

load_spells(){    /*  Used by ghall.c  */
    int i;
    if(sizeof(Skills) > 0)
    {
	for(i = 0; i < sizeof(Skills); i ++){}
    }
}

tell_skills(x){    /*  Used by ghall.c  */
    int i, c;
    string hmm;
    if(!x) return 0;
    for(i = 0, c = 1; i < sizeof(Skills); i ++, c++)
    {
	hmm = Skills[i];
	if(hmm)
	{
	    write(capitalize(hmm));
	    if(c == 6)
	    {
		write(",\n");
		c = 0;
	    }
	    else
		write(", ");
	}
    }
    write("\n\n");
    return 1;
}

int qs(string str){
    if(member_array(str, Skills) > -1) return 1;
    return 0;
}
