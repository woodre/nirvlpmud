inherit "obj/monster";

int busy;
object guy;

/*
 * Mad Martin will make armor for you if you give him an Alligator Hide
 */

reset(arg){
  ::reset(arg);
 if(arg) return;
 set_name("Mad Martin");
 set_alias("mad martin");
 set_short("Mad Martin");
 set_long(
 "Mad Martin got locked away in the dungeons many many years ago and has\n"+
 "lived here ever since.  His sanity disappeared with his sight and\n"+
 "now he sits in his cell and babbles to himself.  Martin was a master\n"+
 "craftsman in his time and he is still pretty good when he has the right\n"+
 "materials.  Martin holds a small paring knife that looks like it still\n"+
 "has a very sharp edge.\n");
 set_race("martin");
 set_gender("male");
 set_level(100+random(6));
 set_wc(100+random(10));
 set_ac(50+random(50));
 set_hp(10000+random(1000));
 set_al(0);
 set_aggressive(0);
 set_chat_chance(25);
 load_chat("Mad Martin sharpens his knife on the cell walls.\n"+
 "The nasty screeching sound makes you cringe.\n");
 load_chat("Mad Martin sniffs the air.\n"+
 "Mad Martin speaks loudly: I smell me a critter!\n");
 load_chat("Mad Martin wheezes and coughs.\n");
 load_chat("Mad Martin waves his knife in the air.\n");
 load_chat("Martin scratches his crotch.\n");
 load_chat("Martin says: I need me a hide!\n");
 set_a_chat_chance(50);
 load_a_chat("Martin says: Your not supposed to attack me.\n");
 load_a_chat("Martin says: This was a big mistake.\n");
 load_a_chat("Martin says: I suggest you run for it.\n");
 load_a_chat("Martin sticks his finger up your nose.\n");
 busy = 0;
}


catch_tell(str){
  string who, what;
  string tmp;

  if(sscanf(str, "%s speaks loudly: %s", who, what)==2){

    /* make sure it is a player */
    if(!find_player(lower_case(who))) return;

    /* ignore if the player is in battle */
    if(find_player(lower_case(who))->query_attack()) return;

    if(busy > 0){
      say("Martin says: Shaddup!  Can't yas see I'm busy!?\n");
      return 1;
    }

    if(sscanf(what, "%s boots", tmp)){
      if(present("alligator hide", this_object())){
        make_boots(who);
      }
      else {
        say("Martin says: I could make ya some boots if I had me a 'gator hide.\n");
      }
      return 1;
    }
    else {
      pick_response();
    }
  }
  else {
    if(!sscanf(str, "%s %s", who, tmp)==2) return;
    if(lower_case(who) == "mad" || lower_case(who) == "martin") return;
    if(!random(4)) random_talk();
    return 1;
  }
}

make_boots(who){
  guy = find_player(lower_case(who));

  if(!guy){
    say("Mad Martin frowns.\n");
    say("Martin says: Something get screwed up.  Ask me again.\n");
    return 1;
  }

  busy = 1;
  set_chat_chance(0);
  say("\n");
  say("Mad Martin says: Ayup.  I can make ya some boots.\n");
  say("Mad Martin says: Just take me but a second.\n");
  say("Martin pulls out his knife and begins to work on the hide.\n");
  say("\n");
  call_out("making_boots", 5);
  return 1;
}

/* if we did speak loudly but didnt use the key words */
pick_response(){
  int i;
  i = random(6);
  if(i==0) say("Mad Martin says: I'd craft ya some boots if ya asked me to.\n");
  else if(i==1) say("Martin says: Did you get locked in the dungeons too?\n");
  else if(i==2) say("Martin says: If only I had me a 'gator hide!\n");
  else if(i==3) say("Mad Martin says: I dont understand ya boy!\n");
  else say("Mad Martin says: What in the hell are you talking about!?\n");
  return 1;
}



/* this is used if we didnt speak loudly */
random_talk(){
  int i;
  i = random(6);
  if(i==0) say("Mad Martin wipes his knife clean on his gator skin boots.\n");
  else if(i==1) say("Mad Martin says: EH?  What did you say?\n");
  else if(i==2) say("Martin stumbles around blindly.\n");
  else if(i==3) say("Martin says: Speak up damnit!  My hearin aint so good no more!\n");
  else if(i==4) say("Mad Martin says: Them damn rats been stealin my stuff again!\n");
  else say("Mad Martin says: You's gonna haveta 'speak loudly' for me ta hear ya.\n");
  return 1;
}

making_boots(){
  object obj;
  if( (random(13) == 9) && (busy > 1) ){
    say("Mad Martin slips and tears the hide with his knife.\n"+
    "Martin says: Gawd Damnit!  Ruined me another hide!\n");
    say("Martin shrugs and says: Guess you need to get me another.\n");
    destruct(present("hide", this_object()));
    busy = 0;
    set_chat_chance(25);
    return 1;
  }
  if(busy < 3){
    say("Mad Martin continues to craft a pair of boots from the hide.\n");
    busy++;
    call_out("making_boots", 5);
    return 1;
  }
  else {
  set_chat_chance(25);
  busy = 0;
  obj = clone_object("players/pavlik/armor/gator_boots");
  destruct(present("hide", this_object()));
  say("Mad Martin completes his task.\n"+
  "He holds a brand new pair of gator hide boots up and smiles.\n");

  if(!present(guy, environment(this_object()))){
    say("Martin says: Damnit.  Now where did he go?\n");
    say("Martin says: Guess I'll just have to keep these boots fer myself.\n");
    move_object(obj, this_object());
    return 1;
  }

  say("Mad Martin gives boots to "+capitalize(guy->query_name())+".\n");
  move_object(obj, guy);

  return 1;
  }
}

init(){
 ::init();
 add_action("loud_speak","speak");
}

loud_speak(str){
  string tmp, what;

  if(sscanf(str, "%s %s", tmp, what)==2){
    if(tmp == "loudly"){
      tell_room(environment(this_player()),
       capitalize(this_player()->query_real_name())+" speaks loudly: "+what+"\n");
      return 1;
    }
    else {
      tell_room(environment(this_player()),
      capitalize(this_player()->query_real_name())+" speaks loudly: "+tmp+" "+what+"\n");
      return 1;
    }
  }
  tell_room(environment(this_player()),
  capitalize(this_player()->query_real_name())+" speaks loudly: "+str+"\n");
  return 1;
}
