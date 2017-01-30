inherit "obj/treasure";

reset(arg)
{
    if (arg) return;
    set_id("statue");
  set_short("A large stone statue");
  set_long("A large stone statue of a griffin.\n"+
           "The winged lion has a very fierce look on it's face.\n"+
           "It's eyes seem to glow red...\n");
    set_value(10);
    set_weight(1);
}
get()
{ return 0; }
