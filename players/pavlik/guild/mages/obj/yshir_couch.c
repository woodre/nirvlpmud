#define ME capitalize(this_player()->query_real_name())
object seated;

reset(arg) {
  if(arg) return;
  seated = 0;
}

short(){ 
  if(seated == 0) return "A plush couch [empty]";
  else return "A plush couch ["+seated->query_real_name()+"]";
}

long(){
  if(environment(this_player()) != this_object())
  write(
  "A fine plush couch invites you into its comfortable cushions.\n"+
  "The soft pillows are made of fine silk and inlaid with intricate\n"+
  "golden weavings.  Although the couch is obviously a priceless\n"+
  "artifact, you feel welcome to sit upon it.\n");
  else write(
  "You are stretched out comfortably on Yshir's couch.  Your\n"+
  "mind drifts aimlessly as your body is able to relax so\n"+
  "completely.  You know you can stand up at any time, so there is\n"+
  "no hurry to leave the comfort of the couch.\n");
  return;
}

query_value(){ return 0; }
query_weight(){ return 999; }

set_seated(ob){ seated = ob; }
query_seated(){ return seated; }

init(){
  if(seated != 0 && !present(seated, this_object())) seated = 0;
  if(environment(this_player())==this_object()) {
    clear_intruder();
    add_action("stand_up","stand");
    add_action("stand_up","wake");
    add_action("say_it"); add_xverb("'");
    add_action("say_it","say");
  }
  else {
    add_action("sit_couch","sit");
  }
}

say_it(str) {
  string what, junk;

  if(!sscanf(str, "train %s", junk)==1 &&
     !sscanf(str, "teach %s", junk)==1) {
    write("You mumble something in a sleepy voice.\n");
    tell_room(environment(this_object()),
    ME+" mumbles something in his sleep.\n");
    return 1;
  }

  write("You say: "+str+"\n");
  say(ME+" says: "+str+"\n");
  return 1;
}

clear_intruder() {
  if(!this_player()->is_player()) return 1;
  if(seated == 0) {
    move_object(this_player(), "players/pavlik/guild/mages/rooms/yshir_room");
    return 1;
  }
  if(this_player() != seated) {
    move_object(this_player(), "players/pavlik/guild/mages/rooms/yshir_room");
    return 1;
  }
}

stand_up() {
  write(
  "Regretfully you wake your body and stand up from the couch.\n"+
  "As your mind becomes more awake Yshir slowly dissolves from sight.\n"+
  "You stand up fully conscious and refreshed.\n"+
  "There is no sign of Yshir.\n"+
  "You wonder if maybe she was just a dream...\n");
  move_object(this_player(), "players/pavlik/guild/mages/rooms/yshir_room");
  say(ME+" wakes and stands up from the couch.\n");
  seated = 0;

  if(present("yshir", this_object()))
    destruct(present("yshir", this_object()));

  return 1;
}

sit_couch() {
  if(seated != 0) {
    write("There is already someone on the couch.\n");
    return 1;
  }
  write("\n"+
  "You sit down and make yourself comfortable on the couch...\n"+
  "You float aimlessly on the verge of sleep.  Your eyelids seem\n"+
  "so very heavy and the cushions of Yshir's couch slide out from\n"+
  "under your body as you effortlessly drift away into sleep.\n");
  write("\n"+
  "A beautiful woman materializes before you.  She is dressed in\n"+
  "a blue and gold gown that swishes quietly as she walks.\n"+
  "Yshir says:  Greetings Mage.\n\n");
  say(ME+" lays down on the couch and instantly feels asleep.\n");

  seated = this_player();
  move_object(this_player(), this_object());

  if(!present("yshir", this_object()))
  move_object(clone_object("players/pavlik/guild/mages/rooms/npc/yshir"),
  this_object());

  return 1;
}

realm(){ return "NT"; }
