/* hatchet.c: middle of the road guild weapon */
inherit "obj/weapon";
reset(arg) {
  if(arg) return 0;
  ::reset(arg);
  set_name("hatchet");
  set_alias("loggers hatchet");
  set_short("A Logger's hatchet");
  set_long("A short, sturdy stick with a dense metal mass at one end. One could do much\n"
          +"damage with such a weapon, if trained.\n");
  set_class(13);
  set_value(13);
  set_weight(3);
  set_hit_func(this_object());
  set_save_flag();
}
id(str) { return str == "hatchet" || str == "loggers hatchet"; }
weapon_hit() {
  object me, gobj, atk;
  int i;
  me = this_player();
  gobj = present("logger pack", me);
  atk = me->query_attack();
  if(!gobj) {
    i = random(40);
    if(i <= 23) {
      write("As you are untrained with this weapon, it slips, and you injure yourself.\n");
      me->add_hit_point(-i);
      write("The hatchet falls to the ground.\n");
      command("drop loggers hatchet", me);
      say(me->query_name()+" looses control of their weapon!\n");
    }
  } else {
    i = random(50); 
    if(i <= 2) {
      write("You skillfully swing the hatchet around and smash it into your foe's chest.\n");
      write(atk->query_name()+" screams in pain!\n");
      say(me->query_name()+" lands "+gobj->query_gender_term(me)+" hatchet directly in "+gobj->query_gender_term(me)+" foe's chest.\n");
      say(atk->query_name()+" screams in pain!\n");
      return 6+i;
    }
  }
  return 0;
}
