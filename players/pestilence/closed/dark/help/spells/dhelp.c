#include "/players/pestilence/ansi.h"

main( string str) {
  write("\n");
  write(HIK+"\tDarkness flows from the ground surrounding you...\n"+NORM);
  if(!str) {
    cat("/players/pestilence/closed/dark/help/general.txt");
    write("\n"); return 1; }
  if(str == "levels"){cat("/players/pestilence/closed/dark/help/levels.txt"); return 1;}
  if(str == "emote"){cat("/players/pestilence/closed/dark/help/emote.txt"); return 1;}
  if(str == "emotes"){cat("/players/pestilence/closed/dark/help/emote.txt"); return 1;}
  if(str == "level"){cat("/players/pestilence/closed/dark/help/levels.txt"); return 1;}
  if(str == "irritator"){cat("/players/pestilence/closed/dark/help/spells/irritator.txt"); return 1;}
  if(str == "summon"){cat("/players/pestilence/closed/dark/help/spells/irritator.txt"); return 1;}
  if(str == "rules"){cat("/players/pestilence/closed/dark/help/rules.txt"); return 1;}
  if(str == "dlead"){cat("/players/pestilence/closed/dark/help/spells/dlead.txt"); return 1;}
  if(str == "darkness"){cat("/players/pestilence/closed/dark/help/spells/darkness.txt"); return 1;}
  if(str == "story"){cat("/players/pestilence/closed/dark/help/story.txt"); return 1;}
  if(str == "combat"){cat("/players/pestilence/closed/dark/help/levels.txt"); return 1;}
  if(str == "ravage"){cat("/players/pestilence/closed/dark/help/spells/ravage.txt"); return 1;}
  if(str == "login"){cat("/players/pestilence/closed/dark/help/login.txt"); return 1;}
  if(str == "set_title"){cat("/players/pestilence/closed/dark/help/set_title.txt"); return 1;}
  if(str == "disavantage"){cat("/players/pestilence/closed/dark/help/disadv.txt"); return 1;}
  if(str == "drawbacks"){cat("/players/pestilence/closed/dark/help/disadv.txt"); return 1;}
  if(str == "disadvantages"){cat("/players/pestilence/closed/dark/help/disadv.txt"); return 1;}
  if(str == "disadvantage"){cat("/players/pestilence/closed/dark/help/disadv.txt"); return 1;}
  if(str == "rank"){cat("/players/pestilence/closed/dark/help/levels.txt"); return 1;}
  if(str == "ranks"){cat("/players/pestilence/closed/dark/help/levels.txt"); return 1;}
  if(str == "leave"){cat("/players/pestilence/closed/dark/help/leave_guild.txt"); return 1;}
  if(str == "rules"){cat("/players/pestilence/closed/dark/help/rules.txt"); return 1;}
  if(str == "leave_guild"){cat("/players/pestilence/closed/dark/help/leave_guild.txt"); return 1;}
  if(str == "who3"){cat("/players/pestilence/closed/dark/help/who3.txt"); return 1;}
  if(str == "gupdate"){cat("/players/pestilence/closed/dark/help/gupdate.txt"); return 1;}
  if(str == "align"){cat("/players/pestilence/closed/dark/help/spells/align.txt"); return 1;}
  if(str == "demon"){cat("/players/pestilence/closed/dark/help/spells/demon.txt"); return 1;}
  if(str == "spells"){cat("/players/pestilence/closed/dark/help/spell_list1.txt"); return 1;}
  if(str == "powers1"){cat("/players/pestilence/closed/dark/help/spell_list1.txt"); return 1;}
  if(str == "powers2"){cat("/players/pestilence/closed/dark/help/spell_list2.txt"); return 1;}  
  if(str == "spells1"){cat("/players/pestilence/closed/dark/help/spell_list1.txt"); return 1;}
  if(str == "spells2"){cat("/players/pestilence/closed/dark/help/spell_list2.txt"); return 1;}
  if(str == "history"){cat("/players/pestilence/closed/dark/help/history.txt"); return 1;}
  if(str == "chain"){cat("/players/pestilence/closed/dark/help/spells/dist.txt"); return 1;}
  if(str == "power"){cat("/players/pestilence/closed/dark/help/spell_list1.txt"); return 1;}
  if(str == "powers"){cat("/players/pestilence/closed/dark/help/spell_list1.txt"); return 1;}
  if(str == "distraught"){cat("/players/pestilence/closed/dark/help/spells/dist.txt"); return 1;}
  if(str == "enrage"){cat("/players/pestilence/closed/dark/help/spells/enrage.txt"); return 1;}
  if(str == "fatal"){cat("/players/pestilence/closed/dark/help/spells/fatal.txt"); return 1;}
  if(str == "offwield"){cat("/players/pestilence/closed/dark/help/spells/offwield.txt"); return 1;}
if(str == "pain"){cat("/players/pestilence/closed/dark/help/spells/pain.txt"); return 1;}
if(str == "corrupt"){cat("/players/pestilence/closed/dark/help/spells/corrupt.txt"); return 1;}
if(str == "infect"){cat("/players/pestilence/closed/dark/help/spells/infect.txt"); return 1;}
if(str == "unw"){cat("/players/pestilence/closed/dark/help/spells/unw.txt"); return 1;}
if(str == "offw"){cat("/players/pestilence/closed/dark/help/spells/offw.txt"); return 1;}
if(str == "death"){cat("/players/pestilence/closed/dark/help/spells/death.txt"); return 1;}
  if(str == "stun"){cat("/players/pestilence/closed/dark/help/spells/stun.txt"); return 1;}
  if(str == "torment"){cat("/players/pestilence/closed/dark/help/spells/torment.txt"); return 1;}
  if(str == "wound"){cat("/players/pestilence/closed/dark/help/spells/wound.txt"); return 1;}
  if(str == "dwield"){cat("/players/pestilence/closed/dark/help/spells/dwield.txt"); return 1;}
  write("That help topic is not available.\n"); return 1; }
