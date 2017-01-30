
/* Engagement Ring */

string NAME, SPOUSE, spouse;
int married;

id(str) { return str=="ring" || str=="engagement ring"; }

long() { 
  if(this_player()->query_gender()=="female") {
    write(format("You see a delicately wrought band of platinum set with " +
     "a large, blue-white diamond.\n\n"));
  }
  else {
    write(format("You see a wide band of pure platinum, simple and " +
     "elegant.\n\n"));
  }
  write("Type \"help ring.\"\n");
}

short () { 
  return NAME + "'s engagement ring (" + SPOUSE + ")";
}

extra_look () {
  return NAME + " is wearing an engagement band";
}

query_auto_load () {
  return "players/bastion/closed/engage:" + SPOUSE;
}

init () {
  add_action("help", "help");
  add_action("restore","restore");
  add_action("toss", "toss");
  add_action("ring_chat", "ring");
/*
  add_action("bring", "bring");
  add_action("go", "go");
 */
  add_action("quit", "quit");
  if (this_player()->query_real_name() == "bastion")
    add_action("renew_all_rings", "renew");
  if(!NAME)
    NAME=this_player()->query_real_name();
  NAME = capitalize(NAME);
  if(!SPOUSE) {
    SPOUSE = "None"; spouse = "none";
  }
  if(SPOUSE && find_player(spouse)) {
    tell_object(find_player(spouse), "(ring) " + NAME + " joins you " +
                "in the game.\n");
  }
  else
    write("(ring) " + SPOUSE + " is not logged in.\n");
}

init_arg (str) { 
  SPOUSE=str;
  spouse=lower_case(str);
}

help(str) {
  if(!str || str!="ring")
    return 0;
  write(format("Now that you are engaged, you can:\n\n" +
    "ring <mess> \t\tTalk to your fiance\n" +
    "ring :<emote> \t\tEmote through the ring\n" +
/*
    "bring <spouse> \t\tTransport your spouse (50 sp's)\n" +
    "go <spouse> \t\tGo to your spouse (50 sp's)\n" +
 */
    "toss ring \t\tDestroy your ring\n" +
    "restore ring \t\tRestore your fiance's ring\n"+
    "help ring \t\tSee this message\n"));
  return 1;
}

ring_chat(str) {
  string mess;
  object rings;
  int i;
  if(!str) {
    notify_fail("Ring <mess> or ring :<mess>.\n");
    return 0;
  }
  mess=str;
  if(mess[0]==58) {
    mess="(ring) " + NAME + " " + mess[1..strlen(mess)] + "\n";
  }
  else {
    mess=NAME + " (ring): " + mess + "\n";
  }
  write(format(mess));
  if(spouse && find_player(spouse))
    tell_object(find_player(spouse), format(mess));
  rings = filter_objects(all_inventory(this_player()), "filter_rings",
                         this_object());
  for(i=0;i < sizeof(rings); i++)
    rings[i]->aux_ring_chat(mess);
  return 1;
}

aux_ring_chat(str) {
  if(spouse && find_player(spouse))
    tell_object(find_player(spouse), format(str));
  return 1;
}

filter_rings(ob) {
  return (ob->id("engagement ring") && ob!=this_object());
}

bring(str) {
  object here;
  if(!str) {
    notify_fail("Bring <spouse>.\n");
    return 0;
  }
  if(str!=spouse) {
    notify_fail("That person is not your spouse.\n");
    return 0;
  }
  if(!find_player(spouse)) {
    notify_fail(capitalize(str) + " is not logged in.\n");
    return 0;
  }
  if(this_player()->query_sp() < 50) {
    notify_fail("You need at least 50 spell points.\n");
    return 0;
  }
  here=environment(this_player());
  if(here->realm("NT") || environment(find_player(str))->realm("NT")) {
    write("A warping of space prevents you.\n");
    return 1;
  }
  this_player()->add_spell_point(-50);
  tell_object(find_player(str), "You appear before your beloved.\n");
  write("You summon your beloved.\n");
  tell_room(environment(this_player()),capitalize(str) + " materializes.\n");
  move_object(find_player(str), environment(this_player()));
  return 1;
}

go(str) {
  object here;
  if(!str) {
    notify_fail("Go <spouse>.\n");
    return 0;
  }
  if(lower_case(str)!=spouse) {
    notify_fail("That person is not your spouse.\n");
    return 0;
  }
  if(!find_player(str)) {
    notify_fail(capitalize(str) + " is not logged in.\n");
    return 0;
  }
  if(this_player()->query_sp() < 50) {
    notify_fail("You need at least 50 spell points.\n");
    return 0;
  }
  here=environment(this_player());
  if(here->realm("NT") || environment(find_player(str))->realm("NT")) {
    write("A warping of space prevents you.\n");
    return 1;
  }
  this_player()->add_spell_point(-50);
  write("You appear before your beloved.\n");
  tell_room(environment(find_player(str)), NAME +
   " materializes.\n");
  move_object(this_player(), environment(find_player(str)));
  return 1;
}

set_spouse(str) {
  SPOUSE=capitalize(str);
  spouse=lower_case(str);
  if(SPOUSE) married=1;
  else married=0;
}

set_owner(str) {
  NAME=capitalize(str);
}

get() { return 1; }
drop() { return 1; }

quit() {
  ring_chat(":leaves you all alone.\n");
}

query_spouse() { return spouse; }

toss(str) {
   if(!str || str != "ring") return 0;
   write("You toss your engagement ring high into the air never to be seen again.\n");
   say(this_player()->query_name() + " throws anengagement ring into the air and it vanishes forever.\n");
   destruct(this_object());
   return 1;
}

restore(str) {
  object new;
   if(!str || str != "ring") return 0;
   if(!SPOUSE || !find_player(spouse)) {
      write(SPOUSE +" is not here.\n");
      return 1;
   }
  new=clone_object("/players/bastion/closed/engage.c");
  new->set_spouse(this_player()->query_real_name());
  new->set_owner(spouse);
  write(SPOUSE + "'s engagement ring has been restored.\n");
  move_object(new,find_player(spouse));
  tell_object(find_player(spouse), "Your ring has been restored.\n");
  return 1;
}

renew_my_ring () {
  object ob;
  ob = clone_object("/players/bastion/closed/engage.c");
  ob->set_owner(NAME);
  ob->set_spouse(spouse);
  move_object(ob, environment(this_object()));
  tell_object(environment(this_object()), this_player()->query_name() + 
              " replaced your engagement ring.\n");
  destruct(this_object());
  return 1;
}

renew_all_rings (str) {
  object *all, *rings, *inv;
  int i;
  if (!str || str != "rings") {
    notify_fail("Renew what?\n");
    return 0;
  }
  all = users();
  rings = ({ });
  for (i = 0; i < sizeof(all); i++) {
    inv = all_inventory(all[i]);
    rings += filter_objects(inv, "filter_rings", this_object());
  }
  for (i = 0; i < sizeof(rings); i++) {
    rings[i]->renew_my_ring();
  }
  renew_my_ring();
  write("Done.\n");
  return 1;
}
