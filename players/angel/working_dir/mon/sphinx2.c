/*
  sphinx.c
*/

inherit "obj/monster";

int riddle_number, riddle_correct;

reset(arg) {
  object obj;
  set_name("sphinx");
  set_level(25);
  set_alias("nooneelsesphinx");
  set_race("sphinx");
  set_hp(500);
  set_al(0);
  set_short("A sphinx");
  set_long("A 15' tall winged lion with a human-like face.\n"+
           "It whispers slyly: Type 'riddle' if you're brave enough.\n");
  set_wc(20);
  set_ac(5);
  set_aggressive(0);
  set_chat_chance(25);
  load_chat(
    "The sphinx mumbles something about the IQ's of adventurers.\n");
  load_chat(
    "The creature examines you and asks: What do you want?\n");
  load_chat(
    "The sphinx smiles slyly and says: You'll never find it.\n");
  set_a_chat_chance(40);
  load_a_chat("The sphinx roars with laughter!\n");
  load_a_chat("The sphinx looks knowingly at you and smirks.\n");
  load_a_chat(
    "The sphinx smiles slyly and says: You'll never find it now!\n");
  obj=clone_object("obj/money");
  obj->set_money(800+random(400));
  move_object(obj, this_object());
  riddle_correct=0;
}

heart_beat() {
  if (!test_if_any_here())
    move_object(this_object(), "players/nooneelse/entryforest/e_mountains4");
  if (query_attack() && random(100) <= 20) {
    tell_room(environment(this_object()),
              "Beams of green light shoot from the sphinx's eyes.\n");
    query_attack()->hit_player(20);
  }
  if (query_attack() && random(100) <= 5) {
    tell_object(query_attack(),
               "The sphinx buffets you with its wings and you stumble away.\n");
    query_attack()->run_away();
  }
  ::heart_beat();
}

init() {
  ::init();

  add_action("riddle", "riddle");
  add_action("answer", "answer");
  add_action("sniff",  "sniff");
}

riddle(str) {
  if (this_player()->query_wimpy()) {
    write("You are not brave enough to try my riddles.\n");
    say("The sphinx says:\n"+
        "   "+this_player()->query_name()+
        ", you are not brave enough to try my riddles.\n", this_player());
    return 1;
  }
  write("So, you think you want to try the riddle do you?\n\n"+
        "Alright brave one, but remember, riddles can be fatal!\n\n");
  if (!riddle_number) riddle_number= 1 + random(5);
  if (riddle_number==1) {
    write("What walks on four legs in the morning,\n"+
          "Two legs in the afternoon,\n"+
          "And three legs in the evening?\n");
  }
  if (riddle_number==2) {
    write("What is always up but not always seen,\n"+
          "Gives us light in times of dark,\n"+
          "And is round but may not seem as such?\n");
  }
  if (riddle_number==3) {
    write("What has three dimensions (length, width and height),\n"+
          "but only two sides?\n");
  }
  if (riddle_number==4) {
    write("What may blind a seeing man, yet help the blind man see?\n");
  }
  if (riddle_number==5) {
    write("My life can be measured in hours.\n"+
          "I serve by being devoured.\n"+
          "Thin, I'm quick.\n"+
          "Thick, I'm slow.\n"+
          "Wind is my foe.\n");
  }
  write("\nTo answer the riddle, say: 'answer <answer>'\n");
  return 1;
}

answer(str) {
  if (!str) return 0;
  if (str=="man" && riddle_number==1 ||
      str=="moon" && riddle_number==2 ||
      str=="paper" && riddle_number==3 ||
      str=="sand" && riddle_number==4 ||
      str=="candle" && riddle_number==5) {
    riddle_correct=1;
    tell_room(environment(this_object()), "Correct!  Well done!\n");
    write(
      "Now, if you follow your nose, it may protect you.\n\n"+
      "    'Ware the vampires!  They are extremely powerful!\n"+
      "    Use the taditional methods of weakening them and they "+
      "can be killed.\n"+
      "    Once killed, they must be destroyed quickly!\n\n"+
      "\nWith that, the sphinx flaps its wings powerfully and takes off.\n");
    say("The sphinx says something to "+this_player()->query_name()+"\n"+
        "then flaps its wings powerfully and takes off.\n", this_player());
    environment(this_object())->set_question_answered();
    destruct(this_object());
    return 1;
  }
  tell_room(environment(this_object()),
    "Wrong!  The sphinx's eyes start to glow a brilliant green and you hear\n"+
    "a soft ticking.\n");
  return 1;
}

sniff(str) {
  if (riddle_correct) return 0;
  tell_room(environment(this_object()),
    "The sphinx looks offended and demands:  'Are you implying I stink?'\n\n"+
    "The sphinx's eyes start to glow a brilliant green and you hear\n"+
    "a soft ticking.\n");
  return 1;
}
