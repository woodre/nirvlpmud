inherit "obj/monster";
 
reset(arg) {
  object recorder;
if (!arg) {  ::reset(arg); }
  set_name("vanilli");
  set_level(8);
  set_alias("vanilli");
  set_race("man");
  set_hp(130);
  set_al(-210);
  set_short("Vanilli");
  set_long("He is the companion and fellow notsinger of Milli.\n" +
           "");
  set_wc(13);
  set_ac(5);
  set_chance(1);
  if(!present("recorder", this_object())) {
    recorder = clone_object("/players/astaroth/taperec");
    move_object(recorder, this_object());
  }
}
