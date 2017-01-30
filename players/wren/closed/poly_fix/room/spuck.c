inherit "players/mizan/closed/RandomRoom.c";
query_light() { return 1; }

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tYou think your way into this room, and see something rather odd.\n"+
"  It is a tremendously large thing, suspended in the middle of the 'room'.\n"+
"  Judging from its behavior, it seems to be eating. You can't help but\n"+
"  giggle, as you see it absorb the smaller blobs of stuff that hover too\n"+
"  close by. Suddenly, you wonder what would happen if it sucked YOU up...\n";
}

extra_reset() {
  object_names=({
  "players/mizan/etheriel/beasties/spuck",
  "players/mizan/etheriel/beasties/minga.c",
  "players/mizan/etheriel/beasties/beano.c",
  "players/mizan/etheriel/beasties/spuckball.c",
  "players/mizan/etheriel/beasties/spuckball.c"
  });
  ::extra_reset();
/*
  call_out("spuck_eating", 45);
 */
}

spuck_eating() {
  object ob;
  object spuck;
  spuck=present("spuck");
  if(!spuck) return 0;
  ob=first_inventory(this_object());
    while(ob) {
      object oc;
      oc=ob;
      oc=next_inventory(ob);
          if(living(oc) && (oc->query_npc()) != 1 && 1 == random(16) && oc->query_guild_name() != "polymorph" &&
        oc != spuck->query_attack()) {
          tell_object(oc, "You hovered too close to Spuck... with a *gloop* you are sucked\n"+
		"into its recesses...\n\n\n");
          say((oc->query_name())+" got too close to Spuck and is absorbed.\n");
          move_object(oc, "players/mizan/etheriel/ROOMS/inside");
        }
       if(1== random(8) && !oc->query_permanency() &&  oc->query_level() < 20) { 
          say((oc->query_name())+" is unwillingly absorbed by Spuck.\n");
      move_object(oc, "/players/mizan/etheriel/ROOMS/inside.c");
          oc->set_heart_beat(0);
          destruct(oc);
        }
    }
  call_out("spuck_eating", 45);
}
