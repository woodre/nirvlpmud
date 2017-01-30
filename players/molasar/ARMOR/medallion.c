
inherit "obj/armor";

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("medallion");
   set_short("A gold medallion");
   set_long("A beautiful gold medallion with a carving of a large dragon\n"+
            "clutching a sword.\n");
   set_type("amulet");
   set_value(2100);
   set_ac(1);
}
