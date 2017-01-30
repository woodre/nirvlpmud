inherit "obj/treasure";

reset(arg) {
   if(arg) return;
set_short("A torn piece of cloth");
set_long("This looks like a torn piece of cloth from a black silk cape.\n");
set_alias("cloth");
set_weight(1);
set_value(356);
}

query_save_flag() { return 0; }
