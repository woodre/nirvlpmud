inherit "obj/armor";
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("rollerblades");
  set_alias("blades");
  set_short("A funky pair of rollerblades");
  set_long("These are a pair of black CCM rollerblades that look slightly worn\n"+
  "but the wheels still spin forever when you flick them. Fearsome!\n"+
  "A small sticker on one of the boots reads: 'Size 9. Mean people suck'\n.");
  set_value(400);
  set_ac(1);
  set_type("boots");
  set_weight(1);
}

