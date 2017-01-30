inherit "obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
	set_name("A Breeder Monk robe");
	set_short("A fuzzy blue robe of the Breeder Monks");
	set_long("This is a thick, fuzzy, and extremely comfortable blue\n"+
	"robe that once belonged to a Breeder Monk. It is now yours.\n"+
	"Therefore, you must have killed one, or bought this at a shop.\n");
	set_value(1985);
	set_ac(2);
	set_type("armor");
	set_alias("robe");
  set_weight(2);
	}
