inherit "obj/monster.c";

    int handnum, gold, flg, starts_thinking;
    int atflg;
    object yesply, notply;
short() { return "Bret Maverick"; }

long(str) {
write("Yep, It's him alright, the hero from that great old western 'Maverick'.\n");
write("You can play a hand of poker with him.  \n");
write("\n");
 write("Just type play <# of coins bet>\n");
	return;
}

id(str) {
    return str == "bret maverick" || str == "bret" || str == "board" ||
	str == "go board" || str == "maverick";
}

reset(arg) {
      atflg = 0;
    if (random(5) < 6)
say("Mr. Maverick asks you to play some poker.\n");
    if (arg)
	return;
    cap_name = "Bret Maverick";
    name = "maverick";
    level = 12;
    experience = 39000;
    max_hp = 140;
    hit_point = 140;
    weapon_class = 13;
    is_npc = 1;
    alignment = 400;
    enable_commands();
    attack();
}

init() {
     add_action("play", "play");
}
play(str){
  int luck, bet, lost;
  if (!str) {
    write("you need to bet something!\n");
 return 1;
}
  sscanf(str, "%d", bet);
if (bet < 0)
  return 0;
  if(call_other(this_player(), "query_money", 0) < bet) {

    tell_object(this_player(), "Mr. Maverick tells you he knows you don't have enough money.\n");
     return 1;
 }
 luck = random(100);
 if (luck < 60) {
   say("too bad, " + call_other(this_player(), "query_name", 0) + " lost "+ bet +" coins at poker.\n");
 lost = 0 - bet;
 call_other(this_player(), "add_money", lost);
  return 1;
 }
 if (luck > 60) {
   say(call_other(this_player(), "query_name", 0) + " won " + bet + " coins playing poker.\n");
  call_other(this_player(), "add_money", bet);
  return 1;
   }
}


catch_tell(str) {
   set_heart_beat(1);
   }
heart_beat() {
   already_fight = 0;
   attack();
  set_heart_beat(0);
   }
