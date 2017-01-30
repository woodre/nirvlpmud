inherit "/players/mizan/core/object.c";

reset(arg)
{
   ::reset(arg);
   if(arg) return;


   set_get(1);
   set_short("An acoustic guitar");
   set_long("This is an acoustic guitar with two strings remaining.\n" +
            "There appears to be some writing on the bottom of it.\n");

   set_name("guitar");
   set_weight(2);
   set_value(200);

   set_read("You turn the guitar over, and written on the bottom is:\n"+
            "'Stolen from Chris Anderson'.\n");

   set_smell("The guitar smells like stale beer and for some reason... basswood.\n");
   set_taste("The guitar tastes like dried boogers!\n");
}

