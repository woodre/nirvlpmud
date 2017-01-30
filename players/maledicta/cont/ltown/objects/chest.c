
int open_chest;
object money;

reset(arg) {
if(arg) return;
    open_chest = 0;
    money = clone_object("obj/money");
    call_other(money, "set_money", 1000 + random(500));
    move_object(money, this_object());
}

long(str) {
    write("This is a chest. You may 'open' it.\n");
    
}

short() {
    if (open_chest)
	return "a chest (open)";
    return "a chest";
}

init() {
   add_action("open", "open");
    
}

open(str) {
    if (!id(str))
	return 0;
    if(open_chest){
    notify_fail("It is already open!\n");
    return 1;
    }
    open_chest = 1;
    write("Ok.\n");
    say(this_player()->query_name()+" opens the chest.\n");
    return 1;
}

id(str) {
    return str == "chest" || str == "treasure chest";
}


can_put_and_get() {
    return open_chest;
}

add_weight() { return 1; }

