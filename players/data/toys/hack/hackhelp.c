/************************************************************/
/*		An include handling a help function for Data		*/
/*					Creator:	Mishtar						*/
/*					Created:	10/29/03					*/
/*					Modified:	10/29/03 by Data			*/
/************************************************************/

int hack_help(){
	tell_object(this_player(),
		"Commands available:\n"+
		"hack_help		-this file.\n"+
		"hack <message>		-this is to speak on this channel.\n"+
        "hack :<message>         -this is to emote on the channel \n"+
		"hack list		-this is a list of who is currently on the channel.\n"+
		"hackhistory		-this will show most recent channel history. \n"+
        "toggle                  -this toggle the muffle on or off. \n"+
        "dtell <message>         -this is for sending a private message to data. \n"+
        "dmote <message>         -this is for emoting privately to data. \n"+
		"\n"+
		"One Simple Rule:\n"+
		"Leave the roll playing behind, such as cybers calling knights pansies, \n"+
        "or trying to get someone to fight. No guild issues or anything like \n"+
        "that. When talking on this line, consider the people on it as a fellow \n"+
        "guild member. \n"+
        " \n"+
        "NEWS: \n"+
        "Going to figure out how to give this object some emotes, hopefully I \n"+
        "can get about 5 good emotes in. This object wont autoload at this time.\n");
return 1;}
