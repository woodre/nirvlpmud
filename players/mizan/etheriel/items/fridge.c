int local_weight;
int chest_is_open;

init() {
add_action("open", "open");
add_action("close", "close");
}

id(str) { return str == "fridge"; }

short() {
    return "A Kenmore refrigerator";
}

long() {
write("This is a big white fridge with loads of hastily scribbled notes\n"+
	"tacked and taped all over it.\n");
    if (chest_is_open)
	write("It is open.\n");
    else
	write("It is closed.\n");
}

query_value() { return 200; }



can_put_and_get() { return chest_is_open; }

add_weight(w) {
    if (w + local_weight > 100)
	return 0;
    local_weight += w;
}

close(str)
{
    if (!id(str))
        return 0;
    chest_is_open = 0;
    write("Ok.\n");
    return 1;
}

open(str)
{
    if (!id(str))
        return 0;
    chest_is_open = 1;
    write("Ok.\n");
    return 1;
}

reset(arg) {
    if (arg)
	return;
    chest_is_open = 0;
}
