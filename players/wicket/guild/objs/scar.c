#include <ansi.h>

id(str) { return str == "scar" || str == "elemental scar"; }

long()
{
	write("A very nasty scar that has been left from the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts"+NORM+"\n"+
"that have scorned you. This is left as a reminder of you\n"+
"abandoning the path of the "+RED+"Ele"+YEL+"men"+GRN+"tal"+CYN+"ist"+NORM+" as it burns and\n"+
"hurts with a deep pain that just seems to never end. You\n"+
"feel empty and as the pain reminds you of what you had.\n");
}

extra_look()
{
	if(environment() == this_player())
		write("You have a "+RED+"deep scar"+NORM+" across your eye from the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts"+NORM+" punishing you.\n");
	else
		write(environment()->query_name() + " has a "+RED+"deep scar"+NORM+" across "+possessive(environment())+" eye from the scorn of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts"+NORM+".\n");
}

query_auto_load() {
	return "/players/wicket/guild/objs/scar.c:";
}

drop() { return 1; }