inherit "obj/treasure";
reset(arg) {
  if(arg) return;
    set_id("head");
set_short("A glowing head");
set_long(
	"  This gruesome looking glowing head is actually nothing more\n"+
	"than a pumpkin with a lighted candle in it.\n");
    set_weight(2);
    set_value(25);
}
