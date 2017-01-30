inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("jerkin");
set_alias("jerkin");
set_short("a shredded jerkin");
set_long(
"What a piece of junk.... it is torn in many places and definately needs\n"
+ "to be washed(more likely burned).. but then again.. it may be useful?\n");
set_weight(1);
/* Changed value 150 to 100 -Snow */
set_value(100);
set_ac(1);
set_type("amulet");
}
