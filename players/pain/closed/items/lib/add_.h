add_pierce(str) {
	if(!str) {
		write("You must specify were you are going to get pierced.\n");
		write("Currently you can choose from the following list: \n");
		write("Nipple   Ear   Clit   Tongue   Eyebrow   Scrotum\n");
		return 1;
	}
	if(str == "nipple") {
		TO->nipple = 1;
		write(p_msg);
		return 1;
	}
	if(str == "tongue") {
		TO->tongue = 1;
		write(p_msg);
		return 1;
	}
	if(str == "clit") {
		TO->clit = 1;
		write(p_msg);
		return 1;
	}
