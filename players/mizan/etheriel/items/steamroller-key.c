inherit "/players/mizan/core/object.c";

reset(arg)
{
   ::reset(arg);
   if(arg) return;

   set_get(1);
   set_value(100);
   set_weight(1);
   set_name("key");
   set_alias("steamroller_key");

   set_short("A small metal door key");
   set_long("This is a small metal door key. It has a square fob on one end.\n"+
            "There appear to be no other significant markings on it.\n");

   set_read("The key says: Caterpillar, Inc.\n");
   set_taste("The key tastes bitter and quite a lot like paperclips.\n");
   set_taste("The key smells like plastic.\n");
}


