inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Lkatva");
  set_alias("lkatva");
  set_short("Lkatva the bartender");
  set_long(
	"Lkatva the bartender is a short robust man with an easy smile.\n"+
	"He has travelled all over the realms to gather ingredients for\n"+
	"his exotic drinks.  He has also gained a good bit of wisdom when\n"+
	"traveling across the globe, it wouldn't be a bad idea to ask him\n"+
	"for some advice every now and then.\n");
  set_level(30);
  set_ac(10);
  set_wc(30);
  set_hp(10000);
  set_al(10000);
  set_aggressive(0);
}

