
inherit "/players/mizan/core/object.c";

reset(arg)
{
   ::reset(arg);
   if(arg) return;

   set_get(1);
   set_value(100);
   set_weight(1);
   set_name("key");
   set_alias("canyonero_ignition_key");

   set_short("A Canyonero ignition key");
   set_long("This is the largest ignition key for a vehicle you have ever seen.\n"+
            "It has a picture of Texas on it, and inside is inscribed the word 'Canyonero!'.\n");

   set_read("The key says: Made in China.\n");
   set_taste("The key tastes like BEEF!\n");
   set_taste("The key smells like BEEF!\n");
}


