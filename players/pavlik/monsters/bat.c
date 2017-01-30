inherit "/obj/monster";

  object there, vamp, player;
reset(arg) {
   ::reset(arg);
   if (!arg) {
     set_name( "bat" );
     set_alias("bat");
  set_short("A Strange looking Bat");
 set_long("A strange looking bat with red glowing eyes.\n");
     set_level(2);
     set_ac(-999);
     set_wc(1);
     set_hp(999);
     set_al(-80);
     set_aggressive(0);
     set_chat_chance(1);
  set_heart_beat(1);
  load_chat("The Bats eyes glow red in the dim light of the room\n");
   load_chat("You can sense the evil flowing from this small creature.\n");
     money = (1);
   }
}

heart_beat() {
   there = environment(this_object());
  if(this_object()->query_attack()) {
     player = this_object()->query_attack();
  tell_room(there, "When the bat is attacked it's form suddenly wavers.\n"+
  "The small body of the bat turns into a misty cloud and then\n"+
  "resolidifies.  Now stands before you a handsome man with pale\n"+
  "skin and red eyes...\n"+
  "My what big teeth you have Grandma!\n");
     vamp = clone_object("players/pavlik/monsters/vamp.c");
       move_object(vamp, there);
 tell_room(there, "\n  The Vampire looks at you.\n"+
  "  'Do you really think you can beat me?' he says.  Then he\n"+
 "  laughs softly. 'Well then, let's get started!'\n"+
 "  He straightens out his long black cloak and smiles at you\n"+
 "  with wicked fangs.\n\n");
       destruct(this_object());
    return 1;
 }
}

