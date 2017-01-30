inherit "obj/treasure";

reset(arg)
{
    if (arg) return;
    set_id("fountain");
  set_short("A beautiful fountain");
  set_long("A large marble fountain.  The fountain is in the shape of\n"+
           "a fish.  A stream of water gushes from the fishes mouth.\n"+
           "Suspended in the stream is a flute !  Perhaps you could\n"+
           "reach into the fountain and take the flute.\n"+
           "The water in the fountain looks quite thirst quenching. It\n"+
           "is cool and clear.\n");
    set_value(10);
    set_weight(1);
}
get()
{ return 0; }
