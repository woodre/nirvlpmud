inherit "obj/treasure";
reset(arg){
if(arg) return;
set_short("A Part of the Rod of Smiting");
/* 11-24-07 -Rumplemintz - added set_alias */
set_alias("part");
set_long("This is part of the famed rod of smiting.  It looks like\n"+
"you might need other parts of it to make the rod whole\n");
set_id("rodpartone");
set_weight(1);
set_value(0);
}