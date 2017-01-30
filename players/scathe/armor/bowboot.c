inherit "obj/armor";

reset(arg){
   ::reset(arg);
   if (arg) return;
   set_short("Hard Boots");
   set_long("Tough, durable boots that provide protection in tough terrain.\n");
   set_ac(2);
   set_weight(1);
   set_value(1000);
   set_alias("boots");
   set_name("boots");
   set_type("boots");
}
