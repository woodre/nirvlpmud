/* Emote_check is a function for checking all the basic stuff for emotes */
emote_check(str) {
  object targ;
  int afar;
  if(TP->is_ghost()) {
    notify_fail("You can't do that while you're a ghost.\n");
    return 0;
  }
  if(str) {
    targ=present(str,environment(TP));
    if(!targ) {
      targ=find_player(str);
      afar=1;
    }
    if(!targ) {
      notify_fail("That person isn't here.\n");
      return 0;
    }
  }
  if(targ) {
    if(targ==this_player() || in_editor(targ) || targ->query_invis() >= targ->query_level())
      return 0;
    if(targ->query_tellblock()) {
      write(targ->query_name()+" is blocking emotes.\n");
      return 1;
    }
  }
  return call_other(this_object(),"do_"+query_verb(),targ,afar);
}

do_drool(targ, arg) {
   notify_fail("Drool at whom?\n");
   if(!targ) {
     write("You drool uncontrollably.\n");
     say(TPN+" drools uncontrollably.\n");
     return 1;
   }
   if(targ && !arg) {
     write("You drool uncontrollably at "+targ->query_name()+".\n");
     tell_object(targ,TPN+" drools uncontrollably at you.\n");
     tell_room(environment(TP),TPN+" drools uncontrollably at "+targ->query_name()+".\n",({ TP, targ }));
     return 1;
   }
   if(targ && arg) {
     write("You drool at "+targ->query_name()+" from afar.\n");
     tell_object(targ,TPN+" drools at you from afar.\n");
     return 1;
   }
}
do_froth(targ,arg) {
   notify_fail("Froth at whom?\n");
   if(!targ) {
     write("You froth at the mouth.\n");
     say(TPN+" froths at the mouth.\n");
     return 1;
   }
   if(targ && !arg) {
     write("You froth at "+targ->query_name()+".\n");
     tell_object(targ,TPN+" froths at you.\n");
     tell_room(environment(TP),TPN+" froths at "+targ->query_name()+".\n",({ TP, targ }));
     return 1;
   }
   if(targ && arg) {
     write("You froth at "+targ->query_name()+" from afar.\n");
     tell_object(targ,TPN+" froths at you from afar.\n");
     return 1;
   }
 }
do_rlaugh(targ,arg) {
   notify_fail("Rlaugh at whom?\n");
   if(!targ) {
     write("You roll around laughing.\n");
     say(TPN+" rolls around laughing.\n");
     return 1;
   }
   if(targ && !arg) {
     write("You roll around laughing at "+targ->query_name()+".\n");
     tell_object(targ,TPN+" rolls around laughing at you.\n");
     tell_room(environment(TP),TPN+" rolls around laughing at "+targ->query_name()+".\n",({ TP, targ }));
     return 1;
   }
   if(targ && arg) {
     write("You roll around laughing at "+targ->query_name()+" from afar.\n");
     tell_object(targ,TPN+" rolls around laughing at you from afar.\n");
     return 1;
   }
}
do_leap(targ,arg) {
   notify_fail("Leap at whom?\n");
   if(!targ) {
     write("You leap into the air!\n");
     say(TPN+" leaps into the air!\n");
     return 1;
   }
   if(targ && !arg) {
     write("You leap high into the air, landing on "+targ->query_name()+" with a *THUD*!\n");
     tell_object(targ,TPN+" leaps high into the air, landing on you with a *THUD*!\n");
     tell_room(environment(TP),TPN+" leaps high into the air, landing on "+targ->query_name()+" with a *THUD*!\n",({ TP, targ }));
     return 1;
   }
}
do_fpat(targ,arg) {
   notify_fail("Fpat whom?\n");
   if(targ && !arg) {
     write("You pat "+targ->query_name()+" on the back and say, \"Way to go, Bucko!\"\n");
     tell_object(targ,TPN+" pats you on the back and says, \"Way to go, Bucko!\"\n");
     tell_room(environment(TP),TPN+" pats "+targ->query_name()+" on the back and says, \"Way to go, Bucko!\"\n",({ TP, targ }));
     return 1;
   }
 }
do_yes(targ, arg) {
   notify_fail("Yes at whom?\n");
   if(!targ) {
     write("You nod your head yes.\n");
     say(TPN+" nods "+TP->query_possessive()+" head yes.\n");
     return 1;
   }
   if(targ && !arg) {
     write("You nod your head yes at "+targ->query_name()+".\n");
     tell_object(targ,TPN+" nods "+TP->query_possessive()+" head yes at you.\n");
     tell_room(environment(TP),TPN+" nods "+TP->query_possessive()+" head yes at "+targ->query_name()+".\n",({ TP, targ }));
     return 1;
   }
   if(targ && arg) {
     write("You nod your head yes at "+targ->query_name()+" from afar.\n");
     tell_object(targ,TPN+" nods "+TP->query_possessive()+" head yes at you, from afar.\n");
     return 1;
   }
}
do_no(targ, arg) {
   notify_fail("No at whom?\n");
   if(!targ) {
     write("You shake your head no.\n");
     say(TPN+" shakes "+TP->query_possessive()+" head no.\n");
     return 1;
   }
   if(targ && !arg) {
     write("You shake your head no at "+targ->query_name()+".\n");
     tell_object(targ,TPN+" shakes "+TP->query_possessive()+" head no at you.\n");
     tell_room(environment(TP),TPN+" shakes "+TP->query_possessive()+" head no at "+targ->query_name()+".\n",({ TP, targ }));
     return 1;
   }
   if(targ && arg) {
     write("You shake your head no at "+targ->query_name()+" from afar.\n");
     tell_object(targ,TPN+" shakes "+TP->query_possessive()+" head no at you, from afar.\n");
     return 1;
   }
}
do_afk(targ, arg) {
  if(!targ) {
    write("You say, \"I will be away from my keyboard for a few minutes.\"\n");
    say(TPN+" says, \"I will be away from my keyboard for a few minutes.\"\n");
    return 1;
  }
  if(targ && arg) {
    write("You tell "+targ->query_name()+", \"I will be away from my keyboard for a few minutes.\"\n");
    tell_object(targ,TPN+" tells you, \"I will be away from my keyboard for a few minutes.\"\n");
    return 1;
  }
}
do_fhug(targ,arg) {
  if(targ && !arg) {
    write("You grab "+targ->query_name()+" tight and hug them, patting them on the back and saying, \"Thanks man...\"\n");
    tell_object(targ,TPN+" grabs you tight and hugs you, pats you on the back and says, \"Thanks man...\"\n");
    tell_room(environment(TP),TPN+" grabs "+targ->query_name()+" tight and hugs them, patting them on the back and saying, \"Thanks man...\"\n",({ TP, targ }));
    return 1;
  }
}
do_fkneel(targ,arg) {
  if(targ && !arg) {
    write("You kneel in front of "+targ->query_name()+", take her hand in yours, looking up into her\n"+
          "wondrous pools of beauty, kissing her hand and bowing your head solemnly.\n");
    tell_object(targ,TPN+" kneels in front of you, taking your hand in his, looking up into your\n"+
                 "wondrous pools of beauty, kissing your hand and bowing his head solemnly.\n");
    tell_room(environment(TP),TPN+" kneels in front of "+targ->query_name()+" and blesses himself with her presence.\n",({ TP, targ }));
    return 1;
  }
}
do_fcourt(targ,arg) {
  if(targ && !arg) {
    write("You shyly move beside "+targ->query_name()+" and ask if you could court her.\n");
    tell_object(targ,TPN+" shly moves beside you and asks if he could be honored enough to court you.\n");
    tell_room(environment(TP), TPN+" moves beside "+targ->query_name()+" and asks "+targ->query_objective()+" something quietly.\n",({ TP, targ }));
    return 1;
  }
}


 do_tip(targ, arg) {
   notify_fail("Tip at whom?\n");
   if(!targ) {
     write("You tip your hat.\n");
     say(TPN+" tips "+TP->query_possessive()+" hat.\n");
     return 1;
   }
   if(targ && !arg) {
     write("You tip your hat to "+targ->query_name()+".\n");
     tell_object(targ,TPN+" tips "+TP->query_possessive()+" hat to you.\n");
     tell_room(environment(TP),TPN+" tips "+TP->query_possessive()+" hat to "+targ->query_name()+".\n",({ TP, targ }));
     return 1;
   }
   if(targ && arg) {
     write("You tip your hat to "+targ->query_name()+" from afar.\n");
     tell_object(targ,TPN+" tips "+TP->query_possessive()+" hat to you from afar.\n");
     return 1;
   }
}


 do_thug(targ, arg) {
   notify_fail("Tacklehug at whom?\n");
   if(!targ) {
     write("You run and leap into the air, landing flat on your face!\n");
     say(TPN+" runs and leaps into the air, landing flat on his face!.\n");
     return 1;
   }
   if(targ && !arg) {
     write("You sprint towards "+targ->query_name()+", leaping into the air, giving them a *huge* tacklehug!\n");
     tell_object(targ,TPN+" sprints at you, knocking you to the ground with a *huge* tacklehug!\n");
     tell_room(environment(TP),TPN+" sprints across the room and lands a *huge* tacklehug on "+targ->query_name()+"!\n",({ TP, targ }));
     return 1;
   }
   if(targ && arg) {
     write("You sprint across the mud, leaping into the air, giving "+targ->query_name()+" a *huge* tacklehug from afar.\n");
     tell_object(targ,TPN+" sprints at you from across the mud and lands a *huge* tacklehug on you!\n");
     return 1;
   }
}


 do_fsmirk(targ, arg) {
   notify_fail("Smirk at whom?\n");
   if(!targ) {
     write("You smirk, then glance around the room.\n");
     say(TPN+" smirks, glancing around the room.\n");
     return 1;
   }
   if(targ && !arg) {
     write("You smirk at "+targ->query_name()+", glancing around the room.\n");
     tell_object(targ,TPN+" smirks at you, then glances around the room.\n");
     tell_room(environment(TP),TPN+" smirks at "+targ->query_name()+", then glances around the room.\n",({ TP, targ }));
     return 1;
   }
   if(targ && arg) {
     write("You smirk at "+targ->query_name()+", glancing around the realms.\n");
     tell_object(targ,TPN+" smirks at you from across the realms.\n");
     return 1;
   }
}


 do_fbleed(targ, arg) {
   notify_fail("Bleed on whom?\n");
   if(!targ) {
     write("You bleed.\n");
     say(TPN+" bleeds profusely.\n");
     return 1;
   }
   if(targ && !arg) {
     write("You bleed on "+targ->query_name()+".\n");
     tell_object(targ,TPN+" bleeds on you.\n");
     tell_room(environment(TP),TPN+" bleeds on "+targ->query_name()+".\n",({ TP, targ }));
     return 1;
   }
   if(targ && arg) {
     write("You bleed all over "+targ->query_name()+" from afar.\n");
     tell_object(targ,TPN+" bleeds profusely on you from afar.\n");
     return 1;
   }
}


 do_heh(targ, arg) {
   notify_fail("Heh at whom?\n");
   if(!targ) {
     write("You go, \"Heh..\"\n");
     say(TPN+" goes, \"Heh..\"\n");
     return 1;
   }
   if(targ && !arg) {
     write("You go, \"Heh..\"\n");
     tell_object(targ,TPN+" goes, \"Heh..\" at you.\n");
     tell_room(environment(TP),TPN+" goes, \"Heh..\" at "+targ->query_name()+".\n",({ TP, targ }));
     return 1;
   }
   if(targ && arg) {
     write("You go \"Heh..\" at "+targ->query_name()+" from afar.\n");
     tell_object(targ,TPN+" goes, \"Heh..\" at you from afar.\n");
     return 1;
   }
}
