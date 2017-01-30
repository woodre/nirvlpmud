int full;
id(str) {
	if(str=="martini" && full)
	return 1;
	return str == "glass";
	}
short() {
	if(full)
        return "a martini";
	return "empty glass";
	}
query_value() {
	if(!full) return 10;
	return 0;
	}
long() {
	write(short() + ".\n");
	}
reset(arg) {
	if(arg)
	return 1;
	full = 1;
	}
drink(str)
{
    if (str && str != "martini" && str !="from glass")
        return 0;
    if (!full)
        return 0;
    if (!call_other(this_player(), "drink_alcohol", 12))
        return 1;
    full = 0;
    write("One of the best you have drank!\n");
    say(call_other(this_player(), "query_name", 0) +
        " drinks a martini.\n");
    return 1;
}

init() {
    add_action("drink","drink");
}

get() {
    return 1;
}

query_weight() {
    return 1;
}
