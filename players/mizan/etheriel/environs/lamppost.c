inherit "/players/mizan/core/object.c";

reset(arg)
{
   ::reset(arg);
   if(arg) return;


   set_get(0);

   set_short("A lamp post (lit)");
   set_long("What a funny looking thing... in the sense it does not fit\n"+
            "this realm at all! How did it get here?\n");

   set_name("post");
   set_alias("lamp");

   set_read("Stickers all over the lamp post advertise prostitution and escort agencies.");

   set_smell("The lamp post smells like... dog urine.\n");
   set_taste("The lamp post tastes incredibly enough like... dog urine.\n");
}

