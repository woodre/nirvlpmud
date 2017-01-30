inherit "obj/treasure";

reset(arg) {
   if(arg) return;
set_short("Jewel of Blood");
set_long("The jewel is as red as blood and spherical in shape.\n");
set_weight(0);
set_alias("jewel");
set_id("vamp_jewel");
set_value(235);
}

query_save_flag() { return 0; }
