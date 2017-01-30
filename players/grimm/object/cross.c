inherit "obj/treasure";

reset(arg) {
   if(arg) return;
set_short("Silver Cross");
set_long("This is a silver cross rumured to be the only weapon able to defeat Malachi.\n");
set_alias("cross");
set_weight(1);
set_id("vamp cross");
set_value(800);
}

query_save_flag() { return 0; }
