#define MOV_RATE 4
inherit "/obj/monster";
string master;

reset(arg)
{
	::reset(arg);
	if (!arg) {
		set_name("a note of music");
		set_alias("music_bard");
		set_alt_name("note");
		set_short("A note of music");
		set_level(1);
		set_ac(1);
		set_wc(1);
		set_hp(1);
		call_out("random_move", MOV_RATE);
	}
}

status random_move()
{
	int n;
	object ob, ob2;
	string there;

	n = random(14);
	switch (n) {
	case 0:
		command("east");
		break;
	case 1:
		command("north");
		break;
	case 2:
		command("west");
		break;
	case 3:
		command("south");
		break;
	case 4:
		command("down");
		break;
	case 5:
		command("up");
		break;
	case 6:
		command("northeast");
		break;
	case 7:
		command("southeast");
		break;
	case 8:
		command("northwest");
		break;
	case 9:
		command("southwest");
		break;
	case 10:
		command("out");
		break;
	case 11:
		command("enter");
		break;
	case 12:
		command("in");
		break;
	case 13:
		command("exit");
		break;
	}
	call_out("random_move", MOV_RATE);
	return 1;
}

set_master(str)
{
	master = str;
}

query_master()
{
	return master;
}
