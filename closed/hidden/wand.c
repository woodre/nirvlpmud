int new_object;
int new_value;
string new_short, new_long, new_name;

short()
{
    if (new_object)
	return new_short;
    return "The wand of creation";
}

query_value()
{
    if (new_object)
	return new_value;
    return 0;
}

long()
{
    if (new_object) {
	write(new_long + "\n");
	return;
    }
    write("It is a long and worn wand.\n");
    write("It originally belonged to Lars.\n");
    write("He used it when he created the world.\n");
    write("You probaly can't use it.\n");
}

init() {
    if (!new_object) {
	add_action("wave"); add_verb("wave");
	add_action("home"); add_verb("home");
	add_action("crash"); add_verb("crash");
    }
}

id(str)
{
    if (new_object)
	return str == new_name;
    return str == "wand" || str == "wand of creation";
}

wave(str)
{
    if (str && !id(str))
	return 0;
    if (new_object)
	return 0;
    write("The wand gets warm, and activates.\n");
    write("You are now creating a new object.\n");
    if (call_other(this_player(), "query_level") < 20) {
	write("Something falters ...\n");
	return 1;
    }
    write("Give the name of the object: ");
    say(call_other(this_player(), "query_name") +
	" waves the wand of creation.\n");
    input_to("set_new_name");
    return 1;
}

set_new_name(str)
{
    if (str == "") {
	write("Aborted\n");
	return;
    }
    new_name = lower_case(str);
    write("Give the short description of the object: ");
    input_to("set_new_short");
}

set_new_short(str)
{
    if (str == "") {
	write("Aborted\n");
	return;
    }
    new_short = str;
    write("Give the long description of the object (terminate with '**'):\n");
    input_to("set_new_long");
    new_long = 0;
}

set_new_long(str)
{
    if (str == "") {
	write("Aborted.\n");
	return;
    }
    if (str == "**") {
	write("Give the value of the object: ");
	input_to("set_new_value");
	return;
    }
    if (new_long)
	new_long = new_long + str + "\n";
    else
	new_long = str + "\n";
    input_to("set_new_long");
}

set_new_value(str)
{
    if (str == "") {
	write("Aborted.\n");
	return;
    }
    if (sscanf(str, "%d", new_value) == 1) {
	new_object = 1;
	write("DONE.\n");
	say(call_other(this_player(), "query_name") +
	    " has created " + new_short + ".\n");
	move_object(clone_object("obj/wand"), this_player());
	return;
    }
    write("Bad value. Aborted.\n");
}

get()
{
    return 1;
}

reset(arg) {
    if (!arg)
	set_light(1);
}

home() {
    if (new_object)
	return 0;
    if (call_other(this_player(), "query_level") < 20)
	return 0;
    say(call_other(this_player(), "query_name") +
	" teleported home.\n");
    move_object(this_player(), "players/lars/workroom");
    call_other(this_player(), "look");
    return 1;
}

crash() {
    shout("You hear a distant rumble.\n");
    shout(call_other(this_player(), "query_name") +
	" has entered the game.\n");
    write("Ok.\n");
    return 1;
}
