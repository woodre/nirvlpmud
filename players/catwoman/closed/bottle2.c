#define MAX_WEIGTH      300000
int local_weight;
object shop;

long() {
    write("a bottle. ");
    if (first_inventory(this_object()))
        write("There is something in it.\n");
    else
        write("You can put things in it.\n");
}

reset(arg) {
    if (arg)
        return;
    local_weight = 0;
}

query_weight() {
    return 1;
}
init ()
   {
    if (!shop) {
                shop = clone_object("players/catwoman/stuff/vend.c");
                move_object(shop, this_object());
        }

    add_action ("go","go");
    add_action ("leave","leave");
   return;
   }

go(){
call_other(this_player(), "move_player", "go#players/catwoman/closed/bottle");
return 1;
}
leave(){
call_other(this_player(), "move_player", "leave#players/catwoman/workroom");
return 1;
}
add_weight(w) {
    if (local_weight + w > MAX_WEIGTH)
        return 0;
    local_weight += w;
    return 1;
}

short() {
    return "bottle";
}

id(str) {
    return str == "bottle";
}

query_value() {
    return 12;
}
can_put_and_get() { return 1; }

get() {
    return 1;
}

prevent_insert() {
    if (local_weight > 0) {
        write("You can't when there are things in the bag.\n");
        return 1;
    }
    return 0;
}

