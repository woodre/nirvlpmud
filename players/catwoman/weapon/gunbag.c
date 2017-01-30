#define MAX_WEIGTH     25
int local_weight;

long() {
    write("A  Blowgun bag. ");
    if (first_inventory(this_object()))
        write("There is something in it.\n");
    else
        write("You can put things in it.\n");
}
object d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, g1;
reset(arg) {
	if(!d1){
	d1 = clone_object("players/catwoman/weapon/pa");
	move_object(d1,this_object());
	}
	if(!d2){
	d2 = clone_object("players/catwoman/weapon/paa");
	move_object(d2,this_object());
	}
	if(!d3){
	d3 = clone_object("players/catwoman/weapon/pb");
	move_object(d3,this_object());
	}
	if(!d4){
	d4 = clone_object("players/catwoman/weapon/pc");
	move_object(d4,this_object());
	}
	if(!d5){
	d5 = clone_object("players/catwoman/weapon/pd");
	move_object(d5,this_object());
	}
	if(!d6){
	d6 = clone_object("players/catwoman/weapon/pe");
	move_object(d6,this_object());
	}
	if(!d7){
	d7 = clone_object("players/catwoman/weapon/pf");
	move_object(d7,this_object());
	}
	if(!d8){
	d8 = clone_object("players/catwoman/weapon/pg");
	move_object(d8,this_object());
	}
	if(!d9){
	d9 = clone_object("players/catwoman/weapon/ph");
	move_object(d9,this_object());
	}
	if(!d10){
	d10 = clone_object("players/catwoman/weapon/pi");
	move_object(d10,this_object());
	}
	if(!d11){
	d11 = clone_object("players/catwoman/weapon/pj");
	move_object(d11,this_object());
	}
	if(!g1){
	g1 = clone_object("players/catwoman/weapon/bgun");
	move_object(g1,this_object());
	}
    if (arg)
        return;
    local_weight = 0;
}

query_weight() {
    return 4;
}

add_weight(w) {
    if (local_weight + w > MAX_WEIGTH)
        return 0;
    local_weight += w;
    return 1;
}

short() {
    return "A Gunbag.\n";
}

id(str) {
    return str == "gunbag";
}

query_value() {
    return 5000;
}

can_put_and_get() { return 1; }

get() {
    return 1;
}
drop() {
    write("The Bag Vanishes.\n");
    destruct(this_object());
    return 1;
}
prevent_insert() {
    if (local_weight > 0) {
        write("You can't when there are things in the bag.\n");
        return 1;
    }
    return 0;
}

