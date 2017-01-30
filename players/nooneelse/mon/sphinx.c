/*
 sphinx.c
*/

inherit "obj/monster";

object coins;

int riddle_number, riddle_correct;

init() {
  ::init();

  add_action("riddle", "riddle");
  add_action("answer", "answer");
  add_action("sniff", "sniff");
}

riddle(str) {
  if (this_player()->query_wimpy()) {
    say(this_player()->query_name()+
        ", you are not brave enough to try the riddle.\n");
    return 1;
  }
  write("So, you think you want to try the riddle do you?\n");
  write("Alright brave one, but remember, riddles can be fatal!\n");
  write("\n");

  if (!riddle_number) riddle_number= 1 + random(11);
  if (riddle_number == 1) {
    write("\nIt comes only before,\n"+
          "\tIt comes only after,\n"+
          "Rises only in darkness,\n"+
          "\tBut rises only in light.\n"+
          "It is always the same,\n"+
          "\tBut is yet always different.\n\n");
  }
  if (riddle_number == 2) {
    write("\nA golden treasure that never stays;\n"+
          "\tThe coin whose face gives wealth to all.\n"+
          "Strands, nuggets, and dust of gold\n"+
          "\tare all bought with its shining grace. . .\n"+
          "And all are more precious than any gleaming metal.\n\n");
  }
  if (riddle_number == 3) {
    write("\nI run through hills;\n"+
          "\tI veer around mountains.\n"+
          "I leap over rivers\n"+
          "\tand crawl through the forests.\n"+
          "Step out your door to find me.\n\n");
  }
  if (riddle_number == 4) {
    write("\nWhen you look into my face,\n"+
          "\tI shall never lie;\n"+
          "Instead be but a window into your soul,\n"+
          "\twhether there light or shadows hide;\n"+
          "As in me many see their deaths\n"+
          "\twhere others see their lives;\n"+
          "In this deny me many try,\n"+
          "\tbut they simply twist their knives;\n"+
          "For though prejudiced to some I may seem,\n"+
          "\tTHE LIE IS THEIR OWN LIVES.\n\n");
  }
  if (riddle_number == 5) {
    write("\nTwo bodies have I,\n"+
          "\tthough both joined in one.\n"+
          "The more still I stand,\n"+
          "\tthe quicker I run.\n\n");
  }
  if (riddle_number == 6) {
    write("\nYou get many of me, but never enough.\n"+
          "\tAfter the last one, your life soon will snuff.\n"+
          "You may have one of me but one day a year,\n"+
          "\tWhen the last one is gone, your life disappears.\n\n");
  }
  if (riddle_number == 7) {
    write("\nI make you weak at the worst of all times.\n"+
          "\tI keep r hands sweat, and your heart grow cold,\n"+
          "\tI visit the weak, but seldom the bold.\n\n");
  }
  if (riddle_number == 8) {
    write("\nDouble my number, I'm less than a score,\n"+
          "\tHalf of my number is less than four.\n"+
          "Add one to my double when bakers are near,\n"+
          "\tDays of the week are still greater, I fear.\n\n");
  }
  if (riddle_number == 9) {
    write("\nThey have not flesh, nor feathers,\n"+
          "\tNor scales, nor bone.\n"+
          "Yet they have fingers and thumbs,\n"+
          "\tOf their own.\n\n");
  }
  if (riddle_number == 10) {
    write("\nIt is more beautiful than the face of your love.\n"+
          "\tIt is more scary than your worst fear.\n"+
          "Dead men eat it all the time.\n"+
          "\tIf a live man eats it, he soon will die.\n\n");
  }
  if (riddle_number == 11) {
    write("\nHe who makes me doesn't want me,\n"+
          "He who buys me doesn't need me,\n"+
          "He who uses me doesn't care.\n\n");
  }
  write("To answer the riddle, say: 'answer <answer>'\n");
  return 1;
}

answer(str) {
  if (!str) return;
  if (str == "moon" && riddle_number == 1 ||
      str == "sun" && riddle_number == 2 ||
      str == "road" && riddle_number == 3 ||
      str == "mirror" && riddle_number == 4 ||
      str == "hourglass" && riddle_number == 5 ||
      str == "birthday" && riddle_number == 6 ||
      str == "fear" && riddle_number == 7 ||
      str == "six" && riddle_number == 8 ||
      str == "gloves" && riddle_number == 9 ||
      str == "nothing" && riddle_number == 10 ||
      str == "casket" && riddle_number == 11) {
    say("Correct!  Well done!  Now, if you follow your nose, "+
        "it may protect you.\n");
    riddle_correct=1;
    write("\n");
    write("    'Ware the vampires!  They are extremely powerful.  "+
          "Use the taditional\n");
    write("    methods of weakening them and they st be destroyed quickly!\n");
    environment(this_object())->set_question_answered();
    destruct(this_object());
    return 1;
  }
  say("Wrong!  The sphinx's eyes start to glow a brilliant green and "+
      "you hear\n");
  say("a soft ticking.\n");
  return 1;
}

sniff(str) {
  if (riddle_correct) return;
  say("The sphinx looks offended and demands:  'Are you implying I stink?'\n");
  say("The sphinx's eyes start to glow a brilliant green and you hear\n");
  say("a soft ticking.\n");
  return 1;
}

reset(arg) {
  if (sizeof(explode(file_name(this_object()),"#"))==1) return;
  ::reset(arg);
  if (arg) return;

  this_object()->load_chat(
    "The sphinx mumbles something about the IQ's of adventurers to itself.\n");
  this_object()->load_chat(
    "The creature examines you and asks: What do you want?\n");
  this_object()->load_chat(
    "The sphinx smiles slyly and says: You'll never find it.\n");
  this_object()->set_chat_chance(25);
  this_object()->load_a_chat("The sphinx roars with laughter!\n");
  this_object()->load_a_chat("The sphinx looks knowingly at you and smirks.\n");
  this_object()->load_a_chat(
    "The sphinx smiles slyly and says: You'll never find it now.\n");
  this_object()->set_a_chat_chance(40);
  set_name("sphinx");
  set_alt_name("nooneelsesphinx");
  set_level(25);
  set_hp(500);
  set_wc(20);
  set_ac(15);
  set_ep(350000);
  set_al(0);
  set_short("A sphinx");
  set_long("A 15' tall winged lion with a human-like face.\n"+
           "It whispers slyly: Type 'riddle' if you're brave enough.\n");
  set_whimpy(0);
  set_aggressive(0);
  set_spell_mess1("Beams of green light shoot from the sphinx's eyes.\n");
  set_spell_mess2("You feel the sphinx's beams scorching your skin.\n");
  set_chance(10);
  set_spell_dam(20);
  coins=clone_object("obj/money");
  coins->set_money(1000);
  move_object(coins, this_object());
  riddle_correct=0;
}

weapon_hit(attacker) {
  if (call_other(this_player(), "query_name") == "sphinx" && !random(5)) {
    tell_room(environment(attacker),
              "The sphinx buffets you with its wings and you stumble away.\n");
    call_other(attacker, "run_away", 1);
    return 0;
  }
}
