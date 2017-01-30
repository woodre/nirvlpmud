int local_weight;
int chest_is_open;

init() {
add_action("open", "open");
add_action("close", "close");
}

id(str) { return str == "rack"; }

short() {
    return "A magazine rack";
}

long() {
write("This is a magazine rack. Most of the things look rather... ordinary!\n"+
"Wow! *gasp* There is a cover on it for those times when gravity switches.\n");
    if (chest_is_open)
	write("It is open.\n");
    else
	write("It is closed.\n");
}

query_value() { return 200; }

query_weight() { return 21; }


can_put_and_get() { return chest_is_open; }

add_weight() { return 1; }

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
  if(arg) { return; }
  move_object(clone_object("obj/level_list"), this_object());
/*
  move_object(clone_object("players/mizan/n/di"),  this_object());
*/
  move_object(clone_object("obj/newspaper"), this_object());
    chest_is_open = 0;
}
