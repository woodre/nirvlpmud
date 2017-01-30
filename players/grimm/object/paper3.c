inherit "obj/treasure";
int j;
reset(arg) {
   if (arg) return;
   j="players/grimm/closed/coord"->j_coord();
   set_short("A shard of paper");
   set_id("paper3");
   set_alias("paper");
   set_weight(0);
   set_value(0);
set_long("A very old shard of paper.  The only thing you can make of it is:\n"+
"            _O_"+j+"_\n");
}

query_save_flag() { return 0; }
