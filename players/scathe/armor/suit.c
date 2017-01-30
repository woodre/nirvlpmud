inherit "obj/armor";

reset(arg){
    ::reset(arg);
    if (arg) return;
    set_short("Black Suit");
    set_long("A midnight black suit worn by executioners.\n");
    set_ac(4);
    set_weight(3);
    set_value(1200);
    set_name("suit");
    set_type("armor");
}
