id(str) { return str == "joint"; }

reset() {}

long() { write("This is big conic cigarette. It smells strange , try to smoke it.\n"); }

short() { return "A joint of marijuana"; }

init() {
   add_action("smoke", "smoke");
    return 1;
}


smoke(arg) {
    if (arg!="joint") { return 0; }
    say(call_other(this_player(),"query_name") + " smokes a joint of marijuana.\n");
    write("You smoke a joint of marijuana.\n");
    call_other(this_player(),"heal_self",15);
    write("YoU sEe tHE WorlD AroUND yOU MovINg aND cHAnGinG SHaPe.\n");
    destruct(this_object());
    return 1;
}
 
get() { return 1; }

query_weight() { return 1; }

query_value() { return 0; }

drop() {
    return 0;
}
