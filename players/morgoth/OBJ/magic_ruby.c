inherit "obj/treasure";

reset(arg)
{
    if (arg) return;
    set_id("magic ruby");
    set_short("A magic ruby");
    set_long("The ruby you hold is magic.  You feel power eminating\n"+
             "from it as you hold it in your hand.  You see your future\n"+
             "as you gaze into it....it doesn't look good...\n");
    set_value(10);
    set_weight(1);
}
