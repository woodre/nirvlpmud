inherit "obj/monster";

reset(arg) {
     ::reset(arg);
     if(!arg) {
          set_name("damian the sorcerer");
          set_alias("damian");
          set_level(50);
          set_hp(3950);
          set_ac(12);
          set_wc(35);
          set_short("Damian the sorcerer");
          set_long("A raved-haired man in deep blue robes stands before you.\n"+
                  "His aquiline nose is upturned as he gazes upward,\n"+
                  "pondering some deep mystery. His stare turns to you, and\n"+
                  "without recognition, moves on.\n");
          set_chat_chance(35);
          load_chat("Damian says: Now where did I put that combination?\n");
          load_chat("Damian says: I wish Redstan would return my wand "+
               "\npromptly when he borrows it.\n");
          load_chat("Damian looks at you with a bored expression.\n");
          set_a_chat_chance(10);
          load_a_chat("Damian says: How dare you?\n");
          load_a_chat("Damian glares at you.\n");
          set_chance(100);
          set_spell_dam(random(60));
          set_spell_mess2("Damian incinerates you in a dazzling array of "+
               "pyrotechnics.");
          set_spell_mess1("Damian incinerates his opponent with dazzling "+
               "flair."); }
}

init() {
     ::init();
     set_heart_beat(1);
}

heart_beat() {
     object who;
     ::heart_beat();
     if(this_object()->query_hp() < 3945) {
          tell_room(environment(this_object()),
               "Damian says: Leave my home you barbarian!\n"+
               "Damian makes a small gesture.\n");
          who=this_object()->query_attack();
          who->move_player("X#players/bastion/isle/wiz/shore2");
          tell_object(who, "You suddenly find yourself elsewhere.\n");
          call_out("self_destruct", 2);
          return 1; }
     return 1;
}

self_destruct() {
     say("Damian disappears in a puff of smoke.\n");
     move_object(this_object(), "players/bastion/room/void");
     destruct(this_object());
}