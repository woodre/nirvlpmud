id(str) {return str == "flower";}

reset() {}

long() {write("The flower smells delicious.\n");}

short() {return "Flower of life";}

init() {
    add_action("eat","eat");
   add_action("flower","flower");
    add_action("drop_object","drop");
}

eat(arg) {
     if(arg == "flower") {
         flower();
        return 1;
    } else {
        return 0;
    }
}

flower(arg) {
   say(call_other(this_player(),"query_name")+" eats the flower.\n");
    write("You eat the flower and feel refreshed.\n");
   call_other(this_player(),"heal_self",17);
   write("The flower is no more.\n");
    destruct(this_object());
    return 1;
}

get() { return 1; }

query_weight() { return 0; }

query_value() {return 0;}

drop_object(str) {
    if (str == "all") {
        drop_object("flower");
        return 0;
    }
    if (!str || !id(str))
        return 0;
    write("The flower of life vanishes.\n");
    say(call_other(this_player(),"query_name")+" drops the flower of life and it disappears!\n");
    destruct(this_object());
    return 1;
}
