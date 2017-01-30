reset(arg) {
    if(!arg)
	set_light(1);
    if(!present("tatyana"))
	move_object(clone_object("players/quantos/tatyana"), this_object());
}

init() {
	add_action ("north","north");
	add_action ("south","south");
	add_action ("east","east");
	add_action ("west","west");
	add_action ("up","up");
	add_action ("down","down");
	add_action ("out","out");
	add_action ("press","press");
	add_action ("press","push");
	add_action ("walk","walk");
	add_action ("pet","pet");
	add_action ("pet","stroke");
	add_action ("spell_fail","missile");
	add_action ("spell_fail","shock");
	add_action ("spell_fail","fireball");
	add_action ("spell_fail","lightning");
	add_action ("attack_fail","kill");
	add_action ("attack_fail","attack");
	add_action ("scratch","scratch");
}

pet(str) {
    if(str == "tatyana" || str == "cat") {
	write("Tatyana stretches her body up to meet your hand, purring as\n");
	write("you stroke her lithe form. She seems quite pleased with you.\n");
	say(call_other(this_player(), "query_name", 0) +
		" pets Tatyana, who begins to purr.\n");
	return 1;
    } else { return 0; }
}

scratch(str) {
    if(str == "tatyana" || str == "cat") {
	write("Tatyana purrs contentedly as you scratch her behind the ears.\n");
	say(call_other(this_player(), "query_name", 0) +
		" scratches Tatyana behind the ears.\n");
	return 1;
    } else if(!str) {
	write("You scratch a hard-to-reach itch.\n");
	return 1;
    } else { return 0; }
}

spell_fail(str) {
    if(str == "tatyana" || str == "cat") {
	write("Tatyana looks at your gesturing hands bemusedly. Nothing happens.\n");
	return 1;
    } else {
	write("I think not.\n");
	return 1;
    }
}

attack_fail(str) {
    if(str == "tatyana" || str == "cat") {
	write("A force prevents you from striking such an adorable cat.\n");
	return 1;
    } else {
	write("Nope. Don't do that. It would be bad.\n");
	return 1;
    }
}

walk() {
    call_other(this_player(), "move_player", "to the skywalk#players/quantos/skywalk");
    return 1;
}

press(str) {
    if (str == "button") {
	write ("A can of Coca-Cola Classic comes tumbling out of the machine,\n");
	return 1;
    } else { return 0; }
}

north() {
    call_other (this_player(), "move_player", "north#players/quantos/under/sinkhole");
    return 1;
}

south() {
    call_other (this_player(), "move_player",
	"south#players/quantos/skywalk");
    return 1;
}

east() {
    call_other (this_player(), "move_player", "east#room/pub2");
    return 1;
}

west() {
    call_other (this_player(), "move_player", "west#room/church");
    return 1;
}

out() {
    call_other (this_player(), "move_player", "out#room/post");
    return 1;
}

up() {
    call_other (this_player(), "move_player",
	"up#players/desmodus/workroom");
    return 1;
}

down() {
    call_other (this_player(), "move_player",
	"down#players/aislinn/workroom");
    return 1;
}

long() {
    write ("You are in Quantos' workroom.\n");
    write ("There are loose computer printouts scattered everywhere.\n");
    write ("\n");
    write ("A Macintosh IIfx sits on the desk, with a Laser Writer to the\n");
    write ("side. A Coke machine is in the southwest corner.\n");
    write ("\n");
    write ("N: Sinkhole  S: Skywalk  E: Pub  W: Church  U: Des  D: Ais  Out: P.O.\n");
}

short() {
    return "Quantos' workroom";
}
