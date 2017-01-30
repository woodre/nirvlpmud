inherit "obj/monster";
#define NAME_OF_GHOST "some mist"
#define IT capitalize(target->query_name())
#define ROOM environment(this_object())

object target;
int hunting;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Myyrkzaan");
  set_alias("myyrkezaan");
  set_short("Myyrkezaan, Destroyer of Good");
  set_long("coming soon.\n");
  set_race("demonspawn");
  set_gender("uknown");
  set_level(25);
  set_hp(500+random(300));
  set_ac(35);
  set_wc(35);
  set_al(-1000);
  set_aggressive(0);
  set_chat_chance(25);
  load_chat("Myyrkezaan lounges gracefully like a cat.\n");
  load_chat("Myyrkezaan stares into your soul and smiles his twisted smile.\n");
  load_chat("Myyrkezaan sings softly to himself.\n");
  load_chat("Myyrkezaan slowly plucks the petals from a flower.\n");
  set_dead_ob(this_object());
  target = 0;
  hunting = 0;
}

id(str) {
  return str == "Myyrkezaan" || str == "myyrkezaan" || str == "myyrk" ||
  str == "demon" || str == "ilstkarn_monster";
}

set_target(ob) { target = ob; }
query_target() { return target; }
set_hunting(i) { hunting = i; }
query_hunting() { return hunting; }

/*
 * Can't stop him once he's gotten started.
 */
stop_fight() {
  if(this_player()->query_level() > 20) {
    ::stop_fight();
    return 1;
  }
  return 1;
}

/*
 * Myyrk will silently hunt after a player until he is dead.
 */
heart_beat() {
  ::heart_beat();

  if(!hunting) {
    return 1;
  }

  if(!target || target->query_ghost()) { 
    die();
    return;
  }

  if(!present(target)) {
    if(!(target->query_interactive())) {
      die();
      return 1;
    }

    tell_room(ROOM,
    "Myyrkezaan chuckles softly and glides out of the room.\n");
    move_object(this_object(), environment(target));
    tell_room(ROOM,
    "Myyrkezaan glides silently into the room.\n");

    if(ROOM == "players/mythos/closed/guild/death/death") {
      die();
      return;
    }

    if(target->query_interactive()) {
      attack_object(find_player(target));
    }

  }
}

/*
 * Message to give when our target has been taken care of.
 */
die() {
  tell_room(ROOM,
  "Myyrkezaan throws his head back and laughs heartily!\n"+
  "The evil sound makes your heart skip a beat.\n");
  tell_room(ROOM,
  "The sinister demon looks you in the eye before turning into a\n"+
  "shapeless mist and seeping into the ground.\n");

  /* clear all hunting flags */
  target = 0;
  hunting = 0;

  /* send him home */
  move_object(this_object(), "players/pavlik/workroom");
}

/*
 * Things to do when Myyrk gets killed.
 */
monster_died() {
  /* log who killed him */
  /* remove his weapon and replace with one player can have */
  /* perhaps summon angry demon on this person? */
  return 0;
}

