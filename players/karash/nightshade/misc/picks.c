inherit "obj/treasure";
reset(arg) {
if (arg) return;
set_alias("picks");
set_short("Thieves picks");
set_long
("These picks are an assortment of small blades, wires, and picks.\n"+
"A smart theif never leaves home without them.\n");
set_weight(1);
set_value(500);
}
