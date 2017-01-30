inherit "obj/treasure";

reset(arg) {
   if(arg) return;
set_short("A dog bone");
set_long("This is just an ordinary dog bone.\n");
set_alias("bone");
set_id("vamp bone");
set_value(200);
}

query_save_flag() { return 0; }
