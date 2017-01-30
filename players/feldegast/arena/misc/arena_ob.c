#define OWNER environment()
inherit "obj/treasure";
int start, heal;
set_fake_hb(arg) {
  while(remove_call_out("fake_hb") != -1) ;
  if(arg) call_out("fake_hb",3);
}
id(str) {
  return str=="arena_ob";
}
init() {
  set_fake_hb(1);
}

/* This is called from the challenge object and determines how */
/* much of a handicap the player gets compensated for. */
set_heal(arg) {
  heal=arg;
}
fake_hb() {
  set_fake_hb(0);
/* This code is for determining if and how long a player has */
/* been disconnected.  If it is longer than 60 seconds, then */
/* that player is moved to the recovery room and the other */
/* player can leave the arena. */
  if(interactive(environment())) {
     start=0;
  }
  else {
    if (!start) start=time();
    if (time()-start > 60) {
      tell_room(environment(environment()),"Player eliminated due to disconnection.\n");
      environment(environment())->victory();
      move_object(environment(),"/players/feldegast/arena/rooms/recovery");
      log_file("feld_arena",
       OWNER->query_name()+" forfeited his match due to disconnection.\n");
      destruct(this_object());
    }
  }
/* This heals the player 15 points or less if they have handicap points left. */
  if(heal>0 && OWNER->query_hp()< OWNER->query_mhp()-15) {
     if(heal>15) OWNER->heal_self(15);
     else OWNER->heal_self(heal);
     tell_object(OWNER,"You feel slightly healed.\n");
     heal-=15;
  }
/* Destructs the object if the player isn't in the arena. */
  if(environment(environment())->short()!="The Arena") destruct(this_object());
  set_fake_hb(1);
}

