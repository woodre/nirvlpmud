inherit "obj/treasure";
reset(arg) {
if (arg) return;
set_short(
"A SIGN! LOOK AT IT!");
set_long
("The main shop is 3 south then west.\n"+
 "The pub is 3 south then east\n"+
 "The portable heal shop is south then east\n");
set_weight(50);
set_alias("sign");
set_value(1);
}
