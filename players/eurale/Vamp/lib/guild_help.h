/*
  guild_help.h
*/

#include "/players/eurale/defs.h"

/* --------------- Display the help info for the fangs --------------- */
guild_help(str) {
  string help_file_name, cat_return, lookup_file_name;
  int start_line, nbr_lines;
  object obj;

if(!str) { write("Help what?\n"); return 1; }

if(str == "assess") help_file_name = "assess";
if(str == "backhand") help_file_name = "backhand";
if(str == "bats" || str == "abat" || str == "mbat")
    help_file_name = "bats";
if(str == "bite") help_file_name = "bite";
if(str == "cancel") help_file_name = "cancel_summons";
if(str == "call wolf" || str == "wolf") help_file_name = "call_wolf";
if(str == "calm") help_file_name = "calm";
if(str == "check") help_file_name = "check";
if(str == "communication") help_file_name = "communication";
if(str == "convert") help_file_name = "convert";
if(str == "cult") help_file_name = "cult";
if(str == "cure" || str == "cure disease") help_file_name = "cure";
if(str == "damn") help_file_name = "damn";
if(str == "demon") help_file_name = "demon";
if(str == "demote") help_file_name = "demote";
if(str == "dispell" || str == "dispell mist") help_file_name = "dispell";
if(str == "drain" || str == "drain corpse") help_file_name = "drain";
if(str == "emit" || str == "emit mist") help_file_name = "emit";
if(str == "emotes") help_file_name = "emotes";
if(str == "expell") help_file_name = "expell";
if(str == "eyes") help_file_name = "eyes";
if(str == "fear") help_file_name = "fear";
if(str == "fix heart") help_file_name = "fix_heart";
if(str == "forms") help_file_name = "forms";
if(str == "friends") help_file_name = "friends";
if(str == "gohome") help_file_name = "gohome";
if(str == "grasp") help_file_name = "grasp";
if(str == "infuse") help_file_name = "infuse";
if(str == "leave" || str == "leave guild") help_file_name = "leave";
if(str == "obits") help_file_name = "obits";
if(str == "promote") help_file_name = "promote";
if(str == "remove") help_file_name = "remove";
if(str == "repel") help_file_name = "repel";
if(str == "replace") help_file_name = "replace";
if(str == "rip") help_file_name = "rip";
if(str == "sanctuary") help_file_name = "sanctuary";
if(str == "seconds") help_file_name = "seconds";
if(str == "servant") help_file_name = "servant";
if(str == "scan") help_file_name = "scan";
if(str == "scratch") help_file_name = "scratch";
if(str == "sharpen") help_file_name = "sharpen";
if(str == "skill levels") help_file_name = "skill_level";
if(str == "spells") help_file_name = "spells";
if(str == "status") help_file_name = "status";
if(str == "summon") help_file_name = "summon";
if(str == "transfer") help_file_name = "transfer";
if(str == "trials") help_file_name = "trials";
if(str == "updates") help_file_name = "updates";

lookup_file_name = "/players/eurale/Vamp/hlp/"+help_file_name+".hlp";
cat(lookup_file_name);
write("\n");

return 1;
}
