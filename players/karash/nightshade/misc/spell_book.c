inherit "obj/treasure";
reset(arg) {
if (arg) return;
set_alias("book");
set_short("Mages spell book");
set_long
("A mage is of no use without his spell book. It contains all that\n"+
"he has learned through the years of study.\n");
set_weight(1);
set_value(1000);
}
