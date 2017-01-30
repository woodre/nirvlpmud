 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("two-handed sword");
set_alias("sword");
set_short("A massive two-handed sword");
set_long("A massive two-handed sword, it looks almost too big for a goblin to use\n"+
         "especially in one hand.  It's extremely sharp blade looks like it would\n"+
         "shred flesh and bone.\n");
set_class(18);
set_weight(2);
set_value(550);
}
