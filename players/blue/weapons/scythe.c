inherit"obj/weapon";

reset(arg) {
 
   if(!arg) {
  
   set_name("scythe");
   set_short("A Deadly Scythe");
   set_long("This weapon is an instrument of death, normally used by the "+
            "Grim Reaper.\nIt is sharp and cold.\n");
   set_class(20);
   set_weight(2);
   set_value(2000);
   set_save_flag(0);
   }
}
