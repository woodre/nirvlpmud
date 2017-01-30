inherit "obj/armor";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_short("An Earwaxian Sheep Commando Garb");
    set_long("This is a polyester-like outfit designed for use with sheep but could just\n"+
    "as well be worn by others, supposedly. The only thing annoying about it other\n"+
    "than the smell of poop is a strange hole cutout in the fabric for no apparent\n"+
    "reason. When you fit it to yourself, you notice that this hole falls in the area\n"+
    "of your behind, leaving it exposed to the elements.\n");
    set_ac(1);
    set_weight(2);
    set_value(800);
    set_name("garb");
    set_type("armor");
}
