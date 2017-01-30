inherit "obj/treasure";
reset(arg) {
  if(arg) return;
    set_id("reward");
    set_alias("gold");
set_short("A gold 'reward'");
set_long(
	"This beautiful gold ingot is a valuable treasure.\n");
    set_weight(2);
    set_value(2500);
}
