inherit "/players/mizan/core/object.c";

reset(arg)
{
   ::reset(arg);
   if(arg) return;

   set_get(1);
   set_value(100);
   set_weight(1);
   set_name("key");
   set_alias("steamroller_ignition_key");

   set_short("A small metal ignition key");
   set_long("This an understated metal ignition key. It has the words 'CAT-573'\n"+
            "inscribed on the back of it.\n");

   set_read("The key says: Caterpillar, Inc.\n");
   set_taste("The key tastes bitter and quite a lot like paperclips.\n");
   set_taste("The key smells like plastic.\n");
}


