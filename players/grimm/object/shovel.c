inherit "obj/treasure";

reset(arg) {
   if(arg) return;
set_id("shovel");
set_short("shovel");
set_long("This is an extrodinarily strong shovel.\n");
set_alias("steel shovel");
set_weight(1);
set_value(438);
}

query_save_flag() { return 0; }
