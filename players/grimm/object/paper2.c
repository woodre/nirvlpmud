inherit "obj/treasure";
int i;
reset(arg) {
   if (arg) return;
   i="players/grimm/closed/coord"->i_coord();
   set_short("A tiny scrap of paper");
   set_id("paper2");
   set_alias("paper");
   set_weight(0);
   set_value(0);
set_long("A very old scrap of paper.  The only thing you can make of it is:\n"+
"            _AT_"+i+"'_\n");
}


query_save_flag() { return 0; }
