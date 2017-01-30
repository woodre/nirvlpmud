inherit "obj/treasure";
reset(arg) {
  if(arg) return;

set_id("standard");
set_alias("goblin standard");
set_short("A green goblin standard");
set_long("A weather torn and beaten standard, the goblins look up to anyone\n"+
         "carrying the standard.  It bears the symbol of a human skull\n"+
         "surrounded in flames.\n");
set_weight(1);
set_value(200);
}
