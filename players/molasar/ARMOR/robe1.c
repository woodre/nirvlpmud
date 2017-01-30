
inherit "obj/armor";

reset(arg) {
   if(!arg)
   ::reset(arg);
   set_name("robe");
   set_alias("nomad's robe");
   set_short("A nomad's robe");
   set_long("This is the garment of a wandering nomad.\n");
   set_ac(1);
   set_type("sword");
   set_weight(1);
   set_value(100);
}

