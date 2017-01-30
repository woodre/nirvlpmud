inherit "/players/mizan/core/object.c";

reset(arg)
{
   ::reset(arg);
   if(arg) return;


   set_get(1);
   set_short("A pile of armpit hair");
   set_long("This is a collection of some really gross-looking fuzz.\n"+
	        "No, I won't even mention how bad it smells. I am sure that\n"+
	        "you are aware of that.\n");

   set_name("hair");
   set_alias("pile");

   set_weight(0);
   set_value(500);

   set_read("As much as you try, there is nothing to read about this hair.\n");

   set_smell("This armpit hair smells... horrible.\nLike a collection of a thousand farts!\n");
   set_taste("This armpit hair tastes like... stench.\n");
}

