inherit "/players/mizan/core/object.c";

reset(arg)
{
    ::reset(arg);
    if(arg) return;

    set_get(1);
    set_value(5);
    set_weight(1);
    set_name("box");
    set_alias("pizza box");
    set_short("A crumpled up pizza box");
    set_long(" This was once a box of pizza that was supposed to be delivered\n"+
   "but its contents have been consumed vigorously by some fat bastard.\n");
}

