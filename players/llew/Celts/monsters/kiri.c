inherit "obj/monster";
object gold,locket,pipe;

reset(arg) {
   ::reset(arg);
   if(arg) return;

   locket=clone_object("/players/llew/Celts/armor/kiri_locket.c");
   move_object(locket,this_object());
   gold=clone_object("obj/money");
   gold->set_money(random(2000)+random(2000)+1000);
   move_object(gold,this_object());
   pipe=clone_object("/players/llew/Celts/misc/pan_pipes.c");
   move_object(pipe,this_object());
   init_command("wear locket");

   set_name("kiri");
   set_short("A youthful elf maiden");
   set_race("elf");
   set_alias("elf");
   set_long("A beautiful elven maiden by the name of Kiri.\n"+
      "She has long, golden, curly hair and sparkling green eyes.\n"+
      "Sad and distant, she takes no notice of you.  She is kind\n"+
      "and good, but so very sad...\n");
   set_level(20);
   set_ac(22);
   set_wc(25);
   set_hp(575);
   set_al(1000);
   enable_commands();
   set_chat_chance(6);
   set_a_chat_chance(10);
   load_chat("Kiri plays a sorrowful tune on her panpipes.\n");
   load_chat("Kiri softly sings, 'Come away, O human child...'\n");
   load_chat("Kiri swims briefly in the pool.\n");
   load_chat("Kiri absently picks a wildflower.\n");
   load_a_chat("Kiri softly sings, 'The world's more full of weeping than you can understand.'\n");
   load_a_chat("Kiri sighs deeply.\n");
}

catch_tell(str) {
   string who;
   string a,b,c;
   if(sscanf(str, "%s hugs you.",who)) {
      tell_object(find_player(lower_case(who)),"Kiri hugs you.\n");
      say("Kiri hugs "+who+".\n",find_player(lower_case(who)));
      tell_object(find_player(lower_case(who)),"Kiri whispers to you: Thank you...\n");
      say("Kiri whispers something to "+lower_case(who)+".\n");
   }
   if(sscanf(str,"%s smiles at you.",who)) {
      tell_object(find_player(lower_case(who)),"Kiri smiles at you.\n");
      say("Kiri smiles at "+who+".\n",find_player(lower_case(who)));
      say("Kiri sighs deeply.\n");
   }
   if(sscanf(str,"%ssays%spipe%s",a,b,c) ==3) {
      say("Kiri smiles, 'The pipes?  They are my music, my joy.'\n"+
          "             'The magic in them makes me feel good...'\n");
   }
   if(sscanf(str,"%ssays%slocket%s",a,b,c) ==3) {
      say("Kiri sigh, 'My wonderful love... gave it to me'\n"+
          "            'in romance.  Now it stays close to my heart.'\n");
   }
}
