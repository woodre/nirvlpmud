inherit "obj/monster";
object grammy;
 
init() {
  ::init();
}
reset(arg) {
  if(!arg) {
  ::reset(arg);
  set_name("milli");
  set_level(15);
  set_alias("milli");
  set_race("man");
  set_hp(330);
  set_al(-220);
  set_short("Milli");
  set_long("He got his grammy for not singing on a hit record.\n" +
           "");
  set_wc(18);
  set_ac(9);
  set_chance(1);
  if(!present("grammy", this_object())) {
    grammy = clone_object("/players/astaroth/grammy");
    move_object(grammy, this_object());
  }
}
}
