inherit "/players/mizan/core/object.c";

reset(arg)
{
    ::reset(arg);
    if(arg) return;

    set_get(1);
    set_value(0);
    set_weight(1);

    set_name("rock");

    set_short("A small rock");
    set_long("This is a small rock. There's really nothing special about it.\n");

    set_read("There is nothing written on the rock.\n");
    set_smell("The rock smells rocky.\n");
    set_taste("The rock tastes a lot like rock, with a touch of the coarse\n"+
              "bouquet and pungent palette of dried dirt and feces.\n");
}
