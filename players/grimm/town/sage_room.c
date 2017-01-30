inherit "room/room";
 
init() {
  add_action("judge","judge");
  add_action("wake","wake");
  ::init();
}
 
reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc = "Sage's House";
    no_castle_flag = 0;
    long_desc = 
"This is the home of a very wise old man.  Rumor has it that he can tell you\n"
+"anything about anything, but of course, that is only a rumor.  You can\n"
+"hear him snoring very loudly in another room (obviously he doesn't want\n"
+"to be disturbed).\n";
    dest_dir = 
        ({
         "players/grimm/town/mainstreet_9", "east",
        });
}
 
wake(str) {
  object blade;
  if (!str) {
    write("Who do you want to awaken?\n");
    return 1;
    }
  if (str=="sage" || str=="old man" || str=="man") {
   if (!present("cal_hob_books", this_player())) {
    write("You awaken the sage.  A second later you see a very old man walk\n"+
    "through the doorway.  He looks to be at least 100 years old and is wearing\n"+
    "a Spurs T-Shirt and glow in the dark boxers.\n"+
    "\nThe sage turns to you and says:\n"+
    "''Hail adventurer! I have a job of utmost importance for you. Hmmm,\n"+
    "although you don't look worthy of this task I am inclined to give you\n"+
    "a chance to first prove yourself to me.  Locate and return my Calvin and\n"+
    "Hobbes books to me and I will inform you further of your task. All I know about\n"+
    "where it is is that there is a clue in the catacombs.''\n"+
    "\nWith that, he turns around and goes back to sleep.\n");
    return 1;
     } else {
write("You awaken the sage.  A second later you see a very old man walk\n"+
      "through the doorway.  He looks to be very tired and destressed.\n"+
      "He looks up and sees that you have his books and says:\n\n"+
      "''Holy Cripey! I can't believe you found them! THANK YOU THANK YOU!\n"+
      "Very well then, I am placing you on a very important task. You must\n"+
      "destroy the menace of Sacred Blood, the evil vampire Malachi.\n"+
      "To start you on your way you need to PRAY in the church of Sacred\n"+
      "Blood.  I will give you this blade that turns night into day to help\n"+
      "you during this quest.''\n"+
        "\nThe sage then heads off to read his books.\n");
       destruct(present("books", this_player()));
       write_file("/players/grimm/closed/LOGS/sage",capitalize(this_player()->query_real_name())+" just got the DayBlade.\nThe time is: "+ctime(time())+"\n-----------------------------\n");
       blade=clone_object("/players/grimm/weapon/dayblade");
       move_object(blade, this_player());
       return 1;
       }
    }
return 0;
}
 
judge(str) {
  string what, it, who;
  if(!str) {
    write("What do you want the sage to judge?\n");
    return 1;
  }
  if(!present("badge",this_player())) {
    write("The sage will not judge those not in the Doppleganger's guild.\n");
    return 1;
  }
  if(present("Dopple-Faction",this_player())) {
    write("The sage says: You are already in a faction, leave me.\n");
    return 1;
  }
  if(this_player()->query_guild_rank()<9) {
    write("The sage will only judge those who are guild level 9 and above.\n");
    return 1;
  }
  if(str!="me worthy" && str!="my soul" && str!="my steps") {
    write("The sage will not judge that.\n");
    return 1;
  }
  if(str=="me worthy") {
    what = "corpse of lich";
    it = "lich";
    who = "Barbarians";
  }
  if(str=="my soul") {
    what = "corpse of flayer";
    it = "flayer";
    who = "Mystics";
  }
  if(str=="my steps") {
    what = "corpse of lich";
    it = "lich";
    who = "Ninjas";
  }
  if(!present(what,this_player())) {
    write("The sage awakens and slowly looks you over.\n");
    write("The sage says: You are not yet worthy.\n");
    write("The sage says: Return to me the corpse of a hateful enemy.\n");
    write("The sage says: Return the corpse of the "+it+".\n");
    write("The sage turns and heads back to sleep.\n");
    return 1;
  }
  write("The sage awakens and slowly looks you over.\n");
  write("The sage says: You have proven yourself worthy.\n");
  write("The sage says: Go now, and join the "+who+".\n");
  write("The sage turns and heads back to sleep.\n");
  this_player()->add_guild_exp(-this_player()->query_guild_exp());
  this_player()->add_guild_exp(200000);
  destruct(present(what,this_player()));
  this_player()->add_weight(-5);
  return 1;
}
