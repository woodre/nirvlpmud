inherit "obj/treasure";
int k;
reset(arg) {
   if (arg) return;
   k="players/grimm/closed/coord"->k_coord();
   set_short("A scrap of paper");
   set_id("paper4");
   set_alias("paper");
   set_weight(0);
   set_value(0);
set_long("A very old scrap of paper.  The only thing you can make of it is:\n"+
"            _IN_."+k+"''\n");
}

query_save_flag() { return 0; }
