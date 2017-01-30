inherit "obj/treasure";

reset(arg)
{
    if (arg) return;
    set_id("flute");
    set_short("A magic flute");
  set_long("A magic flute.\n"+
           "When played it makes a sound like water dancing over\n"+
           "the rocks in a rushing stream.  It is said that the \n"+
           "flute can conjure fantastic entities when played.\n");
    set_value(10);
    set_weight(1);
}
