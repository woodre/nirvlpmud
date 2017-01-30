inherit "obj/treasure";

reset(arg) {
   if(arg) return;
set_short("Wooden Stake");
set_long("This is a very old wooden stake.\n");
set_alias("stake");
set_id("vamp stake");
set_value(800);
}

query_save_flag() { return 0; }
