inherit "/players/mizan/core/object.c";

reset(arg)
{
   ::reset(arg);
   if(arg) return;


   set_get(1);
   set_weight(10);
   set_value(800);

   set_short("The kitchen sink");
   set_long("This is THE kitchen sink. It's the thing that every American\n"+
	"brings along when they feel like packing too much for a trip.\n");

   set_name("sink");

   set_smell("The kitchen sink smells like stale food.\n");
   set_taste("The kitchen sink tastes really damn disgusting.\n");
}

