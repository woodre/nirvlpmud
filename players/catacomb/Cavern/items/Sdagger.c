inherit "/obj/weapon.c";

reset (arg) {
  ::reset(arg);
  if(arg) return;

  set_name("dagger");
  set_alias("fang");
  set_short("A sharp fang");
  set_long(
 "  The sharp fang could easily be used as a dagger.  From one of \n"+
 "the trecherous giant spiders in the Durkor caverns it is a weapon\n"+
 "to be reckoned with.\n" );
  set_type("dagger");
  set_class(16);
  set_weight(1);
  set_value(1000); 
}
 
  