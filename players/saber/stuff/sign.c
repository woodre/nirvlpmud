inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("sign");
  set_short("A large sign");
   set_long(
  "\n"+
  "Welcome to the land of the Shadow of the Sun.\n"+
  "\n"+
  "You stand at the edge of the City of Ryllian, capital of\n"+
  "the Dukedom of Daradayle.  The rift through which you have\n"+
  "traveled is of precarious stability.  This has the regrettable\n"+
  "effect of not allowing you to travel deep into the heart\n"+
  "of the land.  Our arch magi are working to correct the\n"+
  "situation, and so as time passes you will find that you\n"+
  "may journey farther into Ryllian.\n"+
  "\n"+
  "The perceptive traveller will notice that this realm is\n"+
  "different from some others.  Almost everything that is see\n"+
  "can be looked at.  If you see mountains around you, you\n"+
  "may look at them.  For example, in this location you may\n"+
  "want to look at the road.  Also, all rooms may be searched.\n"+
  "Other differences must be sought out by the worthy, as they\n"+
  "may lead to great profit.  And be warned.  Not all is as\n"+
  "it at first appears...\n"+
  "                                                  -- Saber\n");
   set_weight(100);
   set_value(0);
}
