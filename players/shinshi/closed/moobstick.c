inherit "/obj/treasure.c";
#include <ansi.h>

id(str) {
return str == "stick" || str == "moob_stick";
}

short() { return "A large "+HIY+"glowing"+NORM+" stick"; }
long() {
write("This\n"+
"is not needed\n");
}

drop() { return 0; }
get() { return 1; }
query_weight() { return 2; }
query_value() { return 0; }

init()
{
	add_action("whack", "whack");
}

whack(str)
{
	object person, moobs;
	int waist, cup;
	string moobsize;
	
	waist = random(20) + 20;
	cup = random(20);
	
	switch(cup){
		case 19:
		moobsize = "BB";
		break;
		case 18:
		moobsize = "B";
		break;
		case 17:
		moobsize = "CC";
		break;
		case 16:
		moobsize = "C";
		break;
		case 15:
		moobsize = "DD";
		break;
		case 14:
		moobsize = "D";
		break;
		case 13:
		moobsize = "EE";
		break;
		case 12:
		moobsize = "E";
		break;
		case 11:
		moobsize = "FF";
		break;
		case 10:
		moobsize = "F";
		break;
		case 9:
		moobsize = "GG";
		break;
		case 8:
		moobsize = "G";
		break;
		case 7:
		moobsize = "HH";
		break;
		case 6:
		moobsize = "H";
		break;
		case 5:
		moobsize = "II";
		break;
		case 4:
		moobsize = "I";
		break;
		case 3:
		moobsize = "JJ";
		break;
		case 2:
		moobsize = "J";
		break;
		case 1:
		moobsize = "KK";
		break;
		default:
		moobsize = "K";
		break;
	}
	
	
	if(!str)
	{
		write("Who are we giving moobies to?\n");
		return 1;
	}
	
	person = find_living(str);
	
	if(!person)
	{
		write("That person is not online.\n");
		return 1;
	}
	
	if(person && !present(person, environment(this_player())))
	{
		write(person->query_name()+" is not in the room with you!\n");
		return 1;
	}
	
	if(person->query_gender() != "male")
	{
		write(person->query_name()+" is not a man!\n");
		return 1;
	}
	
	if(present("lolyouhavemanboobs", person))
	{
		write(person->query_name()+" already has man boobs!\n");
		return 1;
	}
	
	tell_object(this_player(), "You whack "+person->query_name()+" on the chest with your stick!\n");
	tell_object(this_player(), "Man boobs begin to form on "+person->query_name()+"'s chest!\n");
	tell_object(person, this_player()->query_name()+" smacks you on your chest with a glowing stick!\n");
	tell_object(person, "Your chest begins to throb as your chest begins to get larger.\n");
	moobs = clone_object("/players/shinshi/closed/moobs.c");
	moobs->set_waist(waist);
	moobs->set_cup(moobsize);
	move_object(moobs, person);
	tell_object(person, "You now have man boobs.\n");
	return 1;
}