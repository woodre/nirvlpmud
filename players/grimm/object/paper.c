inherit "obj/treasure";
reset(arg) {
   if (arg) return;
   set_short("A scrap of paper");
   set_alias("paper");
   set_weight(0);
   set_value(0);
set_long("A very old scrap of paper.  The only thing you can make of it is:\n"+
"            _T C_ES _\n");
}

query_save_flag() { return 0; }
