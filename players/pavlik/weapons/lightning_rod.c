inherit "obj/weapon.c";
#define ME capitalize(wielded_by->query_name())

/*
 * Lightning Rod - a weapon with lousy WC (12) and no special combat
 * functions.  However when it is wielded, the player has a chance
 * of getting struck by lightning!  Getting struck completely recharges
 * the players SPs, but it also hits the player for random(amount recharged)
 */

reset(arg) {
  ::reset();
  if (arg) return;
  set_name("Lightning Rod");
  set_alias("rod");
  set_type("polearm");
  set_short("A long rod");
  set_long(
  "A long rod of silvery metal.  The rod is about 10' in length.\n");
  set_class(12);
  if(!random(3)) set_save_flag(0);
  else set_save_flag(1);
  set_weight(5);
  set_value(800);
  call_out("strike", 25);
}

init() {
 ::init();
 if(this_player()->query_level() > 20)
   add_action("strike","rstrike");
}

strike() {
  int i;
  int amt;

  i = random(50);

  if(!wielded_by) {
    if(i < 26) {
      tell_object(environment(this_object()),
      "A dark cloud passes overhead.  The long metal rod hums quietly for a\n"+
      "moment and then grows quiet.\n");
    }
    call_out("strike", 60+random(360));
    return 1;
  }

  if(i < call_other(wielded_by, "query_attrib", "luc")) {
    tell_room(environment(wielded_by),
    "A dark cloud passes overhead.  The rumbling of thunder rolls across\n"+
    "the earth.  Suddenly a powerful strike of lightning flashes down from\n"+
    "the sky and strikes the long metal rod in "+ME+"'s hands!\n");
    tell_object(wielded_by,
    "Your body racks uncontrolably as it absorbs the lightning bolt!\n"+
    "The pain is unbearable, but your mind and body now feel supercharged!!!\n");

    amt = wielded_by->query_msp() - wielded_by->query_sp();
    wielded_by->hit_player(random(amt));
    wielded_by->add_spell_point(amt);

  }
  else {
    tell_room(environment(wielded_by),
    "A dark cloud passes overhead.  The long metal rod in "+ME+"'s hands hums\n"+
    "momentarily and then is quiet again.  The cloud disappears.\n");
  }

  call_out("strike", 60+random(360));
  return 1;
}

