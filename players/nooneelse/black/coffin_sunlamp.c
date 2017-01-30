/*
  coffin_sunlamp.c - a sunlamp for the vampire's coffins
*/

inherit "obj/treasure";

int light_on;
string my_name;
object my_obj;

reset(arg) {
  if (arg) return;

  set_short("A lamp");
  set_weight(666);
  set_value(0);
}

get() { return 0; }

id(str) { return str=="light switch" || str=="switch" ||
                 str=="sunlamp" || str=="lamp" || str=="light"; }

long(str) {
  if (str=="light switch" || str=="switch")
    write("A gleaming brass knob on the side of the light.\n");
  else
    write("A gleaming brass lamp, with a switch on the side.\n");
}

init() {
  add_action("turn_light_on", "flip");
  add_action("turn_light_on", "throw");
  add_action("turn_light_on", "press");
  add_action("turn_light_on", "turn");
}

turn_light_on(str) {
  string s1;
  if (query_verb()=="turn" &&
      (str=="light on" || str=="switch on")) str="switch";
  if (query_verb()=="flip" || query_verb()=="throw" || query_verb()=="turn")
    s1="s";
  else
  if (query_verb()=="press")
    s1="es";
  else
    return 0;
  if (light_on) {
    write("The light is already on.\n");
    return 1;
  }
  my_name=this_player()->query_name();
  my_obj=this_player();
  write("Click!  The sunlamp turns on and swivels to aim directly at you.\n\n");
  say("Click!  "+my_name+" "+query_verb()+s1+" the switch on a sunlamp and\n"+
      "it swivels to point directly at "+my_obj->query_objective()+".\n\n");
  light_on=1;
  call_out("burn1", 3);
  return 1;
}

burn1() {
  tell_object(my_obj,
    "You start to feel really warm, especially on your face and hands.\n\n");
  tell_my_room(
    my_name+" starts to fidget and feels "+my_obj->query_possessive()+
    "face and hands.\n\n");
  call_out("burn2", 5);
}

burn2() {
  tell_object(my_obj,
    "Your face and hands are really starting to feel hot now.  The\n"+
    "skin on the rest of your body is noticably hot too!\n\n");
  tell_my_room(my_name+" continues to fidget and starts to look worried.\n\n");
  call_out("burn3", 5);
}

burn3() {
  tell_object(my_obj,
    "Smoke starts to curl up off your skin as you feel yourself start to "+
    "burn up!\n\n");
  tell_my_room("Smoke starts to curl up off "+my_name+"'s skin!\n\n");
  call_out("burn5", 5);
}

burn4() {
  tell_object(my_obj,
    "The smoke continues and your skin starts to blister and crack.\n\n");
  tell_my_room("The smoke continues and "+my_name+
               "'s skin starts to blister and crack.\n\n");
  call_out("burn5", 5);
}

burn5() {
  tell_object(my_obj,
    "All the fluids of your body are dripping to the floor, splattering\n"+
    "and hissing as they land.\n\n");
  tell_my_room(
    "All the fluids of "+my_name+"'s body are dripping to the floor,\n"+
    "splattering and hissing as they land.\n\n");
  call_out("burn6", 5);
}

burn6() {
  tell_object(my_obj,
    "If all your muscles weren't already clamped in pain, you would have\n"+
    "to empty your stomach at the horrid stench.  All you can do is moan\n"+
    "in agony.\n\n");
  tell_my_room(
    "All of "+my_name+"'s muscles clamp tight in pain, as "+
    my_obj->query_pronoun()+"\n"+
    "wretches at the horrid stench.  All "+my_obj->query_pronoun()+
    " can do is moan\n"+
    "in agony.\n\n");
  call_out("burn7", 5);
}

burn7() {
  tell_object(my_obj,
    "Click!  The timer on the sunlamp turns it off and you start to feel\n"+
    "normal again.\n\n");
  tell_my_room("Click!  The timer on the sunlamp turns it off.\n\n");

}

/* tell my room, but not me */
tell_my_room(str) {
  string players_here;
  players_here = first_inventory(environment(this_object()));
  while (players_here) {
    if (living(players_here) &&
        !players_here->query_npc() &&
        players_here != my_obj) {
      tell_object(players_here, str+"\n");
    }
    players_here=next_inventory(players_here);
  }
  return 1;
}
