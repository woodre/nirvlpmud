/* knife.c: logger's guild knife */
#define THERE() present("logger pack", this_player())
#define ME this_player()
inherit "obj/weapon";
reset(arg) {
  if(arg) return 0;
  ::reset(arg);
  set_name("knife");
  set_alias("guild knife");
  set_short("A Logger's knife");
  set_long("A small pocket knife with a very sharp blade. One could use it for minimal\n"
          +"defense, probably.\n");
  set_class(10);
  set_weight(2);
  set_value(10);
  set_hit_func(this_object());
  set_save_flag();
}
id(str) { return str == "knife" || str == "loggers knife" || str == "guild knife"; }
weapon_hit() {
  int rand;
  if(!THERE()) {
    rand = random(50);
    if(rand <= 20) {
      write("You are untrained with this weapon, and it slips from your hands!\n");
      command("drop loggers knife", ME);
      say(ME->query_name()+" looses control of his weapon!\n");
      ME->add_hit_point(-5);
    }
  } else {
    rand = random(100);
    if(rand <= 4) {
      write("You quickly misdirect your foe, and bring you knife back and into its chest!\n");
      write("As the blood flows from your foe's wound, you twirl your knife and cackle\n");
      write("merrily!\n");
      say(ME->query_name()+" slices and dices "+THERE()->query_gender_term(ME)+" foe.\n");
      return 5;
    }
  }
  return 0;
}
