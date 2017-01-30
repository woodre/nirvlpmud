inherit "obj/treasure";
reset(arg) {
   if (arg) return;
   set_short("A long duck feather");
   set_alias("feather");
   set_weight(0);
   set_value(50);
   set_long("A very nice looking feather with a point finer than a ball point pen.\n");
}
