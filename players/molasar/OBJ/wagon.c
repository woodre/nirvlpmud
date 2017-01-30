
int found;
object money;

reset(arg) {
     if(arg) return;
    found = 0;
}

id(str) { return str == "wagon" || str == "covered wagon"; }

short() { return "A covered wagon"; }

long() {
    write("A small covered wagon with which the Nomad carries his\n");
    write("belongings around with him.\n");
}

init() {
    add_action("search","search");
    add_action("search","examine");
    add_action("search","exa");
}

search(str) {
     if(!str) {
       write("Search what?\n");
       return 1;
     }
     if(str == "wagon" || str == "covered wagon") {
       if(found == 1) {
         write("You find nothing.\n");
         return 1;
       }
       write("You find a robe and some money in the wagon.\n");
       move_object(clone_object("players/molasar/ARMOR/robe"),this_object());
       money = clone_object("obj/money");
       money->set_money(random(300));
       transfer(money, this_object());
       found = 1;
       return 1;
     }
}

can_put_and_get() { return 1; }

