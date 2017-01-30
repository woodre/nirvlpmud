inherit "obj/armor";

reset(arg){
    ::reset(arg);
    if (arg) return;
    set_short("Black Monk Robes");
    set_long("\
A long black robe made of very soft materials.  It was made for a\n\
little indulgence in an otherwise stark life.\n");
    set_ac(4);
    set_weight(2);
    set_value(3500);
    set_name("robes");
    set_alias("garb");
    SetMultipleIds(({"black monk robes"}));
    set_type("armor");
}
