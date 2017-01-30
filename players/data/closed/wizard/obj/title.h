create_title(str){
	string ntitle;
	if(glvl < 30) return 0;
	if(!str){ write("title <title>\n"); return 1; }
	ntitle = str;
	ntitle = extract(str, 0, 60);
	ntitle = "/players/maledicta/closed/class/color"->filter_msg(ntitle);
	USER->set_title(ntitle);
	write("->>>  "+USER->short()+"\n");
	return 1;
}

