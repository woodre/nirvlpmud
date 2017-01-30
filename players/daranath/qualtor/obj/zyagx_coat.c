inherit "obj/armor";

reset(arg){
   ::reset(arg);

   set_name("lab coat");
   set_short("A long dirty white lab coat");
   set_alias("coat");
   set_long("A long white lab coat, the fabric of which is covered in\n"+
            "both chemicals and blood.\n");
   set_type("armor");
   set_ac(3);
   set_weight(2);
   set_value(1000);
}
