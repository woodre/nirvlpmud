/***************************************************************
****************************************************************
***** If hurt, might revert back to the old say look ***********
***************************************************************/
new_say(string str){
	if(!str){
		write("Say what?\n");
		return 1;
	}
	if((USER->query_hp()*10)/(USER->query_mhp()) < 4){
		if(random(100) < (10 - (USER->query_hp()*10)/(USER->query_mhp())) * 10){
			tell_room(environment(USER),
			HIK+"Dark Matter"+NORM+" temporarily surrounds the face of "+USER->query_name()+"...\n");
			tell_object(USER,
				""+HIW+"You screech, '"+NORM+""+strsub(str, ({ "I", "We", "i", "we", "me", "us", "Me", "Us", "we'm", "we are", "We'm", "We are", "we am", "we are", "We am", "We are",
							"myself", "ourselves", "Myself", "Ourselves", "my", "our", "My", "Our", "mine", "ours", "Mine", "Ours",
			"we was", "we are", "We was", "We are"}), 3)+""+HIW+"'"+NORM+"\n\n");
			tell_room(environment(USER),
				""+BOLD+capitalize(symb_name)+" screeches, '"+NORM+""+strsub(str, ({ "s", "ss", "S", "Sss", "I", "We", "i", "we", "me", "us", "Me", "Us", "we'm", "we are", "We'm", "We are",
							"we am", "we are", "We am", "We are", "myself", "ourselves", "Myself", "Ourselves", "my", "our", "My", "Our", "mine", "ours", "Mine", "Ours",
			"we was", "we are", "We was", "We are"}), 3)+""+BOLD+BLK+"'"+NORM+"\n\n", ({USER}));
			return 1;
		}
	}
	return;
}







