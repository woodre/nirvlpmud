dhelp(str) {
  write("\n");
  write(YEL+"\tYour enhanced dna brings thoughts quickly to your brain...\n"+NORM);
  if(!str) {
    cat("/players/pestilence/closed/destroyer/help/general.txt");
    write("\n"); return 1; }
  if(str == "levels"){cat("/players/pestilence/closed/destroyer/help/levels.txt"); return 1;}
  if(str == "emote"){cat("/players/pestilence/closed/destroyer/help/emote.txt"); return 1;}
  if(str == "emotes"){cat("/players/pestilence/closed/destroyer/help/emote.txt"); return 1;}
  if(str == "level"){cat("/players/pestilence/closed/destroyer/help/levels.txt"); return 1;}
  if(str == "barrage"){cat("/players/pestilence/closed/destroyer/help/spells/barrage.txt"); return 1;}
  if(str == "ba"){cat("/players/pestilence/closed/destroyer/help/spells/barrage.txt"); return 1;}
  if(str == "bs"){cat("/players/pestilence/closed/destroyer/help/spells/blindside.txt"); return 1;}
  if(str == "blindside"){cat("/players/pestilence/closed/destroyer/help/spells/blindside.txt"); return 1;}
  if(str == "rage"){cat("/players/pestilence/closed/destroyer/help/spells/rage.txt"); return 1;}
  if(str == "rush"){cat("/players/pestilence/closed/destroyer/help/spells/rush.txt"); return 1;}
  if(str == "frenzy"){cat("/players/pestilence/closed/destroyer/help/spells/frenzy.txt"); return 1;}
  if(str == "abolish"){cat("/players/pestilence/closed/destroyer/help/spells/abolish.txt"); return 1;}
  if(str == "ab"){cat("/players/pestilence/closed/destroyer/help/spells/abolish.txt"); return 1;}
  if(str == "rob"){cat("/players/pestilence/closed/destroyer/help/spells/rob.txt"); return 1;}
  if(str == "disable"){cat("/players/pestilence/closed/destroyer/help/spells/disable.txt"); return 1;}
  if(str == "weaken"){cat("/players/pestilence/closed/destroyer/help/spells/weaken.txt"); return 1;}
  if(str == "study"){cat("/players/pestilence/closed/destroyer/help/spells/study.txt"); return 1;}
  if(str == "disarm"){cat("/players/pestilence/closed/destroyer/help/spells/disarm.txt"); return 1;}
  if(str == "dwield"){cat("/players/pestilence/closed/destroyer/help/spells/dwield.txt"); return 1;}
  if(str == "rules"){cat("/players/pestilence/closed/destroyer/help/rules.txt"); return 1;}
  if(str == "dlead"){cat("/players/pestilence/closed/destroyer/help/spells/dlead.txt"); return 1;}
  if(str == "darkness"){cat("/players/pestilence/closed/destroyer/help/spells/darkness.txt"); return 1;}
  if(str == "story"){cat("/players/pestilence/closed/destroyer/help/story.txt"); return 1;}
  if(str == "login"){cat("/players/pestilence/closed/destroyer/help/login.txt"); return 1;}
  if(str == "dtitle"){cat("/players/pestilence/closed/destroyer/help/spells/dtitle.txt"); return 1;}
  if(str == "disavantage"){cat("/players/pestilence/closed/destroyer/help/disadv.txt"); return 1;}
  if(str == "drawbacks"){cat("/players/pestilence/closed/destroyer/help/disadv.txt"); return 1;}
  if(str == "disadvantages"){cat("/players/pestilence/closed/destroyer/help/disadv.txt"); return 1;}
  if(str == "disadvantage"){cat("/players/pestilence/closed/destroyer/help/disadv.txt"); return 1;}
  if(str == "skills"){cat("/players/pestilence/closed/destroyer/help/skills1.txt"); return 1;}
  if(str == "skills1"){cat("/players/pestilence/closed/destroyer/help/skills1.txt"); return 1;}
  if(str == "wolverine"){cat("/players/pestilence/closed/destroyer/help/spells/wolverine.txt"); return 1;}
  if(str == "rank"){cat("/players/pestilence/closed/destroyer/help/rank.txt"); return 1;}
  if(str == "ranks"){cat("/players/pestilence/closed/destroyer/help/rank.txt"); return 1;}
  if(str == "leave"){cat("/players/pestilence/closed/destroyer/help/leave_guild.txt"); return 1;}
  if(str == "rules"){cat("/players/pestilence/closed/destroyerhelp/rules.txt"); return 1;}
  if(str == "leave_guild"){cat("/players/pestilence/closed/destroyer/help/leave_guild.txt"); return 1;}
  if(str == "who3"){cat("/players/pestilence/closed/destroyer/help/who3.txt"); return 1;}
  if(str == "gupdate"){cat("/players/pestilence/closed/destroyer/help/gupdate.txt"); return 1;}
  if(str == "align"){cat("/players/pestilence/closed/destroyer/help/spells/align.txt"); return 1;}
  if(str == "slash"){cat("/players/pestilence/closed/destroyer/help/spells/slash.txt"); return 1;}
  if(str == "demon"){cat("/players/pestilence/closed/destroyer/help/spells/demon.txt"); return 1;}
  if(str == "spells"){cat("/players/pestilence/closed/destroyer/help/spell_list1.txt"); return 1;}
  if(str == "spells1"){cat("/players/pestilence/closed/destroyer/help/spell_list1.txt"); return 1;}
  if(str == "spells2"){cat("/players/pestilence/closed/destroyer/help/spell_list2.txt"); return 1;}
  if(str == "history"){cat("/players/pestilence/closed/destroyer/help/history.txt"); return 1;}
  if(str == "dist"){cat("/players/pestilence/closed/destroyer/help/spells/dist.txt"); return 1;}
  if(str == "distraught"){cat("/players/pestilence/closed/destroyer/help/spells/dist.txt"); return 1;}
  if(str == "enrage"){cat("/players/pestilence/closed/destroyer/help/spells/enrage.txt"); return 1;}
  if(str == "fatal"){cat("/players/pestilence/closed/destroyer/help/spells/fatal.txt"); return 1;}
  if(str == "offwield"){cat("/players/pestilence/closed/destroyer/help/spells/offwield.txt"); return 1;}
  if(str == "punch"){cat("/players/pestilence/closed/destroyer/help/spells/punch.txt"); return 1;}
  if(str == "stun"){cat("/players/pestilence/closed/destroyer/help/spells/stun.txt"); return 1;}
  if(str == "torment"){cat("/players/pestilence/closed/destroyer/help/spells/torment.txt"); return 1;}
  if(str == "wound"){cat("/players/pestilence/closed/destroyer/help/spells/wound.txt"); return 1;}
  write("That help topic is not available.\n"); return 1; }
