inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);
   set_name("club");
   set_alt_name("club");
   set_alias("spiked club");
   set_short("A wicked spiked club");
set_long("This is merely a club with protruding metal shards.\n");
   set_class(1254);
   set_weight(3);
   set_value(500);
}
