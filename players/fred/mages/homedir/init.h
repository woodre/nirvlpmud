init() {
  if(!ENV(TO)) return 1;
  if(!ENV(TO)->is_player()) return 1;
  if(!TP->is_player()) return;
   add_action("cmd_bede","bede");
   add_action("cmd_blast","blast");
   add_action("cmd_circle","mages");
   add_action("cmd_coat","coat");
   add_action("color_info","color_help");
   add_action("cmd_curse","curse");
   add_action("cmd_dart","dart");
   add_action("cmd_demise","demise");
   add_action("cmd_deathknight","deathknight");
   add_action("cmd_deathknight","dk");
   add_action("cmd_disrupt","disrupt");
   add_action("cmd_dragon","dragon");
   add_action("cmd_drain","drain");
   add_action("cmd_flame","flame");
   add_action("cmd_fog","fog");
   add_action("cmd_gchat","cc");
   add_action("cmd_gemote","ce");
   add_action("cmd_ghoul","ghoul");
 if(this_player() && this_player()->query_real_name() == "verte") add_action("cmd_drakyr", "drakyr");
   add_action("cmd_heal","heal");
   add_action("cmd_pillusion","pillusion");
   add_action("cmd_obillusion","obillusion");
   add_action("cmd_lich","lich"); 
   add_action("cmd_midas","midas"); 
   add_action("cmd_memorize","memorize");
   add_action("cmd_quit","quit");
   add_action("cmd_mreport","mreport");
   add_action("msave","msave");
   add_action("cmd_recall","recall");
   add_action("cmd_risk","risk");
   add_action("cmd_revert","revert");
   add_action("cmd_say","say");
#ifndef __LDMUD__ /* Rumplemintz */
   add_action("cmd_say"); add_xverb("'");
#else
   add_action("cmd_say", "'", 3);
#endif
   add_action("cmd_score2","score");
   add_action("cmd_tell","tell");
   add_action("ghoul_info","gcmds");
   add_action("dragon_info","dcmds");
   add_action("lich_powers","lich_powers");
   add_action("dknight_powers","dknight_powers");
   add_action("cmd_score","sc");
   add_action("cmd_title","title");
   add_action("mupdate","mupdate");
   add_action("cmd_uncurse","uncurse");
   add_action("cmd_vitalize","vitalize");
   add_action("cmd_home","home");
   add_action("info_help","info");
   add_action("no_no","missile");
   add_action("no_no","mi");
   add_action("no_no","fireball");
   add_action("no_no","fi");
   add_action("no_no","shock");
   add_action("no_no","sh");
   add_action("no_no","sonic");
   add_action("no_no","so");
   add_action("cmd_freeze","freeze");
   add_action("cmd_unfreeze","unfreeze");
   add_action("cmd_drakyr","drakyr");
  /*
   add_action("cmd_xfer","xfer");
  */
   mrestore();
   call_out("save_me", 900);
   ENV()->set_guild_name("black circle");
   ENV()->set_guild_file(basename(this_object()));
   if(!TP->query_invis() && TP->query_level() < 39)
   cmd_gemote("has entered the realm.");
   }

info_help(str){
  write(BOLD+BLK+"\tDark Energy invades your mind...\n\n"+NORM);
  if(!str){cat("/players/fred/mages/info/basic.txt"); return 1; }
  if(str == "bede"){cat("/players/fred/mages/info/bede.txt"); return 1; }
  if(str == "blast"){cat("/players/fred/mages/info/blast.txt"); return 1;}
  if(str == "cc"){cat("/players/fred/mages/info/cc.txt"); return 1;}
  if(str == "ce"){cat("/players/fred/mages/info/ce.txt"); return 1;}
  if(str == "coat"){cat("/players/fred/mages/info/coat.txt"); return 1;}
  if(str == "commands"){cat("/players/fred/mages/info/commands.txt"); return 1;}
  if(str == "curse"){cat("/players/fred/mages/info/curse.txt"); return 1;}
  if(str == "dart"){cat("/players/fred/mages/info/dart.txt"); return 1;}
  if(str == "demise"){cat("/players/fred/mages/info/demise.txt"); return 1;}
  if(str == "deathknight"){cat("/players/fred/mages/info/deathknight.txt"); return 1;}
  if(str == "deathknight_powers"){cat("/players/fred/mages/info/deathknight_powers.txt"); return 1;}
  if(str == "disrupt") {cat("/players/fred/mages/info/disrupt.txt"); return 1;}
  if(str == "dragon"){cat("/players/fred/mages/info/dragon.txt"); return 1;}
  if(str == "dragon_commands"){cat("/players/fred/mages/info/dragon_commands.txt"); return 1;}
  if(str == "drain"){cat("/players/fred/mages/info/drain.txt"); return 1;}
  if(str == "flame"){cat("/players/fred/mages/info/flame.txt"); return 1;}
  if(str == "fog"){cat("/players/fred/mages/info/fog.txt"); return 1;}
  if(str == "freeze"){cat("/players/fred/mages/info/freeze.txt"); return 1;}
  if(str == "ghoul"){cat("/players/fred/mages/info/ghoul.txt"); return 1;}
  if(str == "ghoul_commands"){cat("/players/fred/mages/info/ghoul_commands.txt"); return 1;}
  if(str == "heal"){cat("/players/fred/mages/info/heal.txt"); return 1;}
  if(str == "home"){cat("/players/fred/mages/info/home.txt"); return 1;}
  if(str == "lich"){cat("/players/fred/mages/info/lich.txt"); return 1;}
  if(str == "lich_powers"){cat("/players/fred/mages/info/lich_powers.txt"); return 1;}
  if(str == "midas"){cat("/players/fred/mages/info/midas.txt"); return 1;}
  if(str == "mages"){cat("/players/fred/mages/info/mages.txt"); return 1;}
  if(str == "memorize"){cat("/players/fred/mages/info/memorize.txt"); return 1;}
  if(str == "mreport"){cat("/players/fred/mages/info/mreport.txt"); return 1;}
  if(str == "mupdate"){cat("/players/fred/mages/info/mupdate.txt"); return 1;}
  if(str == "obillusion"){cat("/players/fred/mages/info/obillusion.txt"); return 1;}
  if(str == "pillusion"){cat("/players/fred/mages/info/pillusion.txt"); return 1;}
  if(str == "rank0"){cat("/players/fred/mages/info/rank0.txt"); return 1;}
  if(str == "rank1"){cat("/players/fred/mages/info/rank1.txt"); return 1;}
  if(str == "rank2"){cat("/players/fred/mages/info/rank2.txt"); return 1;}
  if(str == "rank3"){cat("/players/fred/mages/info/rank3.txt"); return 1;}
  if(str == "rank4"){cat("/players/fred/mages/info/rank4.txt"); return 1;}
  if(str == "rank5"){cat("/players/fred/mages/info/rank5.txt"); return 1;}
  if(str == "recall"){cat("/players/fred/mages/info/recall.txt"); return 1;}
  if(str == "revert"){cat("/players/fred/mages/info/revert.txt"); return 1;}
  if(str == "risk"){cat("/players/fred/mages/info/risk.txt"); return 1;}
  if(str == "title"){cat("/players/fred/mages/info/title.txt"); return 1;}
  if(str == "uncurse"){cat("/players/fred/mages/info/uncurse.txt"); return 1;}
  if(str == "vitalize"){cat("/players/fred/mages/info/vitalize.txt"); return 1;}
  if(str=="drakyr"){cat("/players/fred/mages/info/drakyr.txt"); return 1; }
  write(BOLD+BLK+"There is no information on "+str+" at this time.\n"+NORM);
  return 1;   
 }

no_no() {   
   write(BOLD+BLK+"That is not a spell the Black Circle approves of.\n"+NORM);
   return 1;
}

ghoul_info(){
  cat("/players/fred/mages/info/ghoul_commands.txt"); 
  return 1;
 }

lich_powers(){
  cat("/players/fred/mages/info/lich_powers.txt");
  return 1;
 }

dknight_powers(){
  cat("/players/fred/mages/info/deathknight_powers.txt");
  return 1;
 }

dragon_info(){
  cat("/players/fred/mages/info/dragon_commands.txt");
  return 1;
 }

color_info(){
 write("***********************************\n\n"+
       "Colors Available are:\n"+
       "H = Bold        K = Black\n"+
       "R = Red         G = Green\n"+
       "Y = Yellow      B = Blue\n"+
       "M = Magenta     C = Cyan\n"+
       "W = White       N = Normal\n");
 write("Examples:\n"+
        "You want an illusion of you robes:\n"+
        ""+BOLD+BLK+"     Black Robes"+NORM+" (worn).\n\n");
  write("You would enter:\n\n"+
        " obillusion $HK$Black Robes$N$ (worn)\n\n");
  write("Lets say you used the coat spell and they're glowing:\n"+
        "You want an illusion that looks like this:\n"+
        ""+BOLD+BLK+"    Black Robes "+YEL+"(Spectral) "+NORM+" (worn).\n\n");
  write("You would enter:\n\n"+
        "obillusion $HK$Black Robes $Y$(Spectral)$N$ (worn)\n\n");
  write("Just play around with it. You'll get the hang of it.\n");
  write("************************************\n\n");
  return 1;
}      

save_me(){
 msave();
 call_out("save_me", 900);
}


