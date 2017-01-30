inherit "obj/treasure";
reset(arg) {
if (arg) return;
set_short(
"A SIGN! LOOK AT IT!");
set_long
("To the west are the mountains.\n"+
 "To the east are the docks where you might be able\n"+
  "to sneak aboard a ship.\n"+
 "To the north is the way you just came :).\n"+
 "TO the south is the closed castle of Ledsville\n"+
  "and the armor shop.\n");
set_weight(50);
set_alias("sign");
set_value(1);
}
