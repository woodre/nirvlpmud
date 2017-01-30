inherit "obj/armor";

reset(arg){
   ::reset(arg);

set_name("Coal crown");
set_short("Blackened coal Crown");
set_alias("crown");
set_long("Silver is intertwined with the coal on the crown of the salamanders\n"+
         "living here within the Gundar lava pits.\n");
set_type("helmet");
set_ac(2);
set_weight(1);
set_value(1750);
}

query_save_flag() { return 1; }

