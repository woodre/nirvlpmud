inherit "obj/armor";

reset(arg){
    ::reset(arg);
    if (arg) return;
    set_short("Initiate's garb");
    set_long("\
Bedraggled clothes made for the most unsavory of household duties.\n\
There are many patch marks and frays.\n");
    set_ac(2);
    set_weight(1);
    set_value(500);
    set_name("garb");
    set_type("armor");
}
