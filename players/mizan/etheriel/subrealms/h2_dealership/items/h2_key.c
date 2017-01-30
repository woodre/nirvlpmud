
inherit "/players/mizan/core/object.c";

reset(arg)
{
   ::reset(arg);
   if(arg) return;

   set_get(1);
   set_value(100);
   set_weight(1);
   set_name("key");
   set_alias("h2hummer_key");

   set_short("A GM H2 door key");
   set_long("This is a solid metal hunk of a key, wrapped in a plastic sheath.\n"+
            "It is used for the hatches and doors of a General Motors H2.\n");

   set_read("The key says: Made in China.\n");
   set_taste("The key tastes bitter and quite a lot like paperclips.\n");
   set_taste("The key smells like plastic.\n");
}


