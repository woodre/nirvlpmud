inherit "obj/treasure";
reset(arg) {
   if (arg) return;
   set_short("A battery");
   set_alias("battery");
   set_weight(1);
   set_value(100);
   set_long("A rather large battery that is used to power a ghetto blaster.\n");
}
