inherit "obj/treasure";

reset(arg) {
   if(arg) return;
set_short("Amulet of Protection");
set_long("As you look at the amulet you notice a white glimer\n");
set_weight(0);
set_alias("amulet");
set_id("vamp_amulet");
set_value(674);
}

query_save_flag() { return 0; }
