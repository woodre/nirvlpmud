inherit "/players/mizan/core/object.c";

reset(arg)
{
   ::reset(arg);
   if(arg) return;


   set_get(1);
   set_weight(100000);
   set_value(2000);

   set_short("A rocket hood");
   set_long("Commonly known as a 'beanie cap', this is a massive piece of\n"+
    "plastic and steel meant to cover the nose cone of a rocket sitting\n"+
    "on the launching pad.\n");

   set_name("hood");
   set_alias("rocket");

   set_read("A small sticker on the base reads: 'Richard Simmons was here'.");

   set_smell("The rocket hood smells like kerosene.\n");
   set_taste("The rocket hood tastes like... KY Jelly?!\n");
}

