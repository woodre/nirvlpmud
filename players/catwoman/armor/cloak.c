
inherit "/obj/armor";

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("cloak");
   set_alias("brown cloak");
   set_short("A brown cloak");
   set_long("A brown cloak.\n");
   set_weight(1);
   set_ac(1);
   set_type("cloak");
   set_value(250);
}

