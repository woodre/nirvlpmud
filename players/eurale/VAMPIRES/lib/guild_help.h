/*
  guild_help.h
*/

#include "/players/eurale/defs.h"

/* --------------- Display the help info for the fangs --------------- */
guild_help(str) {
  string help_file_name, cat_return, lookup_file_name;
  int start_line, nbr_lines;
  object obj;

if(!str) { str="cult"; }

if(str == "assess") help_file_name = "assess";
if(str == "awaken") help_file_name = "awaken";
if(str == "backhand") help_file_name = "backhand";
if(str == "bats") help_file_name = "bats";
if(str == "batsell") help_file_name = "batsell";
if(str == "benergy") help_file_name = "benergy";
if(str == "bite") help_file_name = "bite";
if(str == "blood") help_file_name = "blood";
if(str == "calm") help_file_name = "calm";
if(str == "cancel") help_file_name = "cancel";
if(str == "check") help_file_name = "check";
if(str == "communication") help_file_name = "communication";
if(str == "cult") help_file_name = "cult";
if(str == "cure") help_file_name = "cure";
if(str == "damn") help_file_name = "damn";
if(str == "delevitate") help_file_name = "delevitate";
if(str == "demon") help_file_name = "demon";
if(str == "demote") help_file_name = "demote";
if(str == "dismiss") help_file_name = "dismiss";
if(str == "donate") help_file_name = "donate";
if(str == "drain") help_file_name = "drain";
if(str == "eject") help_file_name = "eject";
if(str == "emotes") help_file_name = "emotes";
if(str == "expell") help_file_name = "expell";
if(str == "fear") help_file_name = "fear";
if(str == "forms") help_file_name = "forms";
if(str == "friends") help_file_name = "friends";
if(str == "grasp") help_file_name = "grasp";
if(str == "haunt") help_file_name = "haunt";
if(str == "heart") help_file_name = "heart";
if(str == "infuse") help_file_name = "infuse";
if(str == "leave") help_file_name = "leave";
if(str == "levitate") help_file_name = "levitate";
if(str == "obits") help_file_name = "obits";
if(str == "paths") help_file_name = "paths";
if(str == "promote") help_file_name = "promote";
if(str == "regen") help_file_name = "regen";
if(str == "repel") help_file_name = "repel";
if(str == "vemove") help_file_name = "remove";
if(str == "veplace") help_file_name = "replace";
if(str == "scan") help_file_name = "scan";
if(str == "scratch") help_file_name = "scratch";
if(str == "seconds") help_file_name = "seconds";
if(str == "sharpen") help_file_name = "sharpen";
if(str == "shift") help_file_name = "shift";
if(str == "spells") help_file_name = "spells";
if(str == "storage") help_file_name = "storage";
if(str == "summon") help_file_name = "summon";
if(str == "transfer") help_file_name = "transfer";
if(str == "trials") help_file_name = "trials";
if(str == "updates") help_file_name = "updates";
if(str == "vlevels") help_file_name = "vlevels";
if(str == "wings") help_file_name = "wings";
if(str == "who2") help_file_name = "who2";
if(str == "wolf") help_file_name = "wolf";

lookup_file_name = "/players/eurale/VAMPIRES/hlp/"+help_file_name+".hlp";
cat(lookup_file_name);
write("\n");

return 1;
}
