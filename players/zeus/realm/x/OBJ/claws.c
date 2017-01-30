inherit "/obj/weapon.c";

reset(arg) {
   ::reset(arg);
   if (arg) return;

  set_name("beast claws");
  set_alias("claws");
  set_short("Claws of the Beast");
  set_long(
"These claws came from a Beast of the Forest.  They are somewhat\n"+
"long and look to be quite sharp.  They could be used as quite a nice\n"+
"weapon if need be.  They could be 'barter'ed for good money.\n");
  set_value(1700);
  set_weight(3);
  set_class(19);
}

query_save_flag(){    return 1; }

