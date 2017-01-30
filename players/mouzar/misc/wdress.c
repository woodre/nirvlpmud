inherit "obj/armor";
reset(arg) {
   if (arg) return;
   set_name("dress");
   set_short("Lovely Wedding Dress");
   set_type("armor");
   set_alias("gown");
   set_ac(1);
   set_weight(3);
   set_value(10000);
   set_long("This dress is every soon to be wifes dream.  The top of\n"+
	    "of it is white lace.  The middle turns into silk with rose\n"+
	    "patterns sewn into it.  The bottom spans out and it trails\n"+
	    "about 5 feet behind the lucky bride.");
}