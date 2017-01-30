inherit "obj/armor";

int local_weight;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  local_weight = 0;
  set_name("straitjacket");
  set_value(2500);
  set_ac(3);
  set_weight(3);
  set_type("armor");
  set_alias("jacket");
}

short() {
 if(worn) {
   if(1== random(2)) {
      random_emote();
   }
     return "A straitjacket [strapped] (worn)";
  }
  return "A straitjacket";
}

random_emote() {
  if(1==random(11)) {
    say((this_player()->query_name()) + " grins maniacally.\n");
    write("You grin maniacally.\n");
    return 1;
  }
  if(1==random(11)) {
    say((this_player()->query_name()) + " runs around the room, going 'Chugga chugga chugga!'\n");
    write("You run around the room, acting like a choo-choo train.\n");
    return 1;
  }
  if(1==random(11)) {
    say((this_player()->query_name()) + " tries to break free of the straitjacket.\n");
    write("You try to break free of the straitjacket.\n");
    return 1;
  }
  if(1==random(11)) {
    say((this_player()->query_name()) + " bobbles violently.\n");
    write("You bobble violently.\n");
    return 1;
  }
  if(1==random(11)) {
    say((this_player()->query_name()) + " screams 'Garbanzo!'\n");
    write("You scream 'Garbanzo!'\n");
    return 1;
  }
  if(1==random(11)) {
    say((this_player()->query_name()) + " barks like a dog.\n");
    write("You bark like a dog.\n");
    return 1;
  }
  if(1==random(11)) {
    say((this_player()->query_name()) + " chomps on some dirt.\n");
    write("You chomp on some dirt.\n");
    return 1;
  }
  say((this_player()->query_name()) + " drools all over the place.\n");
  write("You drool uncontrollably.\n");
  return 1;
}


