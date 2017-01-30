status main(string str, object PO, object User)
{
	mixed ob;
	ob = "/players/shinshi/closed/shaman/objects/chatob.c";
	
	if(!ob){
		write("The guild line is currently down.\n");
		return 1;
	}
	if(!str){
		write("What would you like to emote to your fellow Shaman?\n");
		return 1;
	}
	
	ob->emote(str);
	return 1;
}