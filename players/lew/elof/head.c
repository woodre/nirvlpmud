inherit "obj/treasure";

reset(arg) {
  if(!arg) {

    set_id("head");
    set_short("Keivjam's head");
    set_long("This is the symbol of the ultimate triumph.\n"+
             "The Gods would be proud.\n");
    set_weight(3);
    set_value(450);
}
}
put() {
    destruct(this_object());
}
query_save_flag() { return 1; }
