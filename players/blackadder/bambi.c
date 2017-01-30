   if (!bambi || !living(bambi)) {
      bambi = clone_object("obj/monster.talk");
      call_other(bambi,"set_name","bambi");
      call_other(bambi,"set_short","Bambi the bimbo");
      call_other(bambi,"set_long",
         "Bambi has long flowing blonde hair, a truly impressive 38-22-36\n" +
         "figure, and not a brain in her head.  She is clad only in the\n" +
         "skimpiest of skimpy bikinis leaving little to the imaginanation.\n" +
         "Bambi loves everybody (once or twice).\n");
      call_other(bambi,"set_level",2);
      call_other(bambi,"set_hp",50);
      call_other(bambi,"set_ac",2);
      call_other(bambi,"set_wc",2);
      move_object(bambi,this_object());
      money = clone_object("obj/money");
      call_other(money,"set_money",random(50));
      move_object(money,bambi);
      call_other(bambi,"set_chat_chance",20);
      call_other(bambi,"set_a_chat_chance",33);
      call_other(bambi,"load_chat","Bambi says: Hey, let's party!\n");
      call_other(bambi,"load_chat","Bambi says: Come a little closer.\n");
      call_other(bambi,"load_chat","Bambi licks you!\n");
      call_other(bambi,"load_chat","Bambi snuggles with you.\n");
      call_other(bambi,"load_chat","Bambi fondles you.\n");
      call_other(bambi,"load_chat","Bambi kisses you.\n");
      call_other(bambi,"load_chat","Bambi rubs your crotch.\n");
      call_other(bambi,"load_chat","Bambi bares her breasts! WHOO! WHOO!\n");
      call_other(bambi,"load_chat","Bambi rubs your back.\n");
      call_other(bambi,"load_chat","Bambi does the nasty.\n");
      call_other(bambi,"load_chat","Bambi splashes you.\n");
      call_other(bambi,"load_chat","Bambi looks at you with cow eyes.\n");
      call_other(bambi,"load_chat","Bambi says: What's your sign?\n");
      call_other(bambi,"load_chat","Bambi says: You're just my type!\n");
      call_other(bambi,"load_chat","Bambi shakes her booty.\n");
      call_other(bambi,"load_chat","Bambi says: What's that between your legs?\n");
      call_other(bambi,"load_a_chat","Bambi crys.\n");
      armor1 = clone_object("obj/armor");
      call_other(armor1,"set_name","bikini");
      call_other(armor1,"set_short","A skimpy bikini");
      call_other(armor1,"set_long","Bambi's skimpy bikini.\n");
      call_other(armor1,"set_value",250);
      call_other(armor1,"set_ac",1);
      call_other(armor1,"set_type","armor");
      transfer(armor1,bambi);
      call_other(bambi,"init_command","wear bikini");
   }
