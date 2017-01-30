inherit "obj/armor";

reset(arg){
    ::reset(arg);
    if (arg) return;
    set_short("Hood");
    set_long("An Executioner's Hood....it is dark and menacing.\n");
    set_ac(1);
    set_weight(2);
    set_value(1000);
    set_name("hood");
    set_type("helmet");
}
