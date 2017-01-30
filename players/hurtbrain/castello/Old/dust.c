id(str) { return (str == "dust" || str =="bag"); }

reset() {}

long() { write("This is a bag of star dust. Type 'throw dust' to use it.\n"); }

short() { return "A bag of star dust"; }

init() {
    add_action("heal","throw");
}

heal(arg) {
        if (arg != "dust"){
                notify_fail("What do you want to throw?\n");
                return 0;
                }
    say(call_other(this_player(),"query_name") + " throws dust on itself.\n");
    write("You throw the dust on yourself. The bag disintegrates.\n");
    call_other(this_player(),"heal_self",50);
    destruct(this_object());
    return 1;
}
get() { return 1; }

drop() { return 0; }
query_weight() { return 0; }

query_value() { return 3000; }
