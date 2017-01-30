/*
  guild_help.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* --------------- Display the help info for the MY_POUCH --------------- */
guild_help(str) {
  string help_file_name, cat_return, lookup_file_name;
  int start_line, nbr_lines;
  object obj;

  if (!str) return 0;
  if (str=="tasks" || str=="task") {
    cat(GUILD_TASKS);
    if (MY_GUILD_RANK>=100) {
      write(NORM+CYN+
            "1->Find the demon priest of the Demon Lord in his monastery.\n"+
            "   (for 10 [5-7]) players/catt/VALLEY/monkroom3\n"+
            "   (they must be at least level 3 to do this)\n"+
            "2->Find the sturdy, short guy.  (Don't forget your "+
            "rope & torch.)\n"+
            "   (for 20 [8-11]) room/mine/tunnel16\n"+
            "3->Search the bones and find the Lord of Minotaurs, Baphomet.\n"+
            "   (You don't need to kill him.  Just find him, then type\n"+
            "    'solve task'.)\n"+
            "   (for 40 [12-14]) players/deathmonger/UNDERDARK/maze/baph\n"+
            "   (they must be at least level 7 to do this)\n"+
            "4->Find the ironwood coffin near Sebastian the Druid.\n"+
            "   (for 60 [15-18]) /players/nooneelse/mazeforest/m_forest_chamber\n"+
            "   (they must be at least level 12 to do this)\n"+
            "5->Kill the four giants.  Get their swords and 'solve task'\n"+
            "   in their conference room.\n"+
            "   (for 80 [19+]) room/giant_conf\n"+NORM);
    }
    return 1;
  }

  /* Level 5-7   Guild Rank: 10   "WHITE"   "STUDENT" */
  if (str=="anews") help_file_name="guild_news"
  if (str=="ahelp") help_file_name="guild_help"
  if (str=="alevels") help_file_name="display_guild_levels"
  if (str=="tasks") help_file_name="list_guild_tasks"
  if (str=="solve") help_file_name="solve_guild_tasks"
  if (str=="loginmsg") help_file_name="loginmsg"
  if (str=="logoutmsg") help_file_name="logoutmsg"
  if (str=="alight") help_file_name="light"
  if (str=="assess") help_file_name="assess"
  if (str=="awho") help_file_name="show_who"
  if (str=="aemote") help_file_name="emote"
  if (str=="atell") help_file_name="tell"
  if (str=="athink") help_file_name="think"
  if (str=="cpr") help_file_name="fix_heartbeat"
  if (str=="fellows") help_file_name="show_alchemists"
  if (str=="launder") help_file_name="fix_guild_object"
  if (str=="refine") help_file_name="refine"
  if (str=="resign") help_file_name="resign_guild"
  if (str=="road") help_file_name="road_to_guild"
  if (str=="set") help_file_name="set_login_room"
  if (str=="stone") help_file_name="stone_skin"
  if (str=="skin") help_file_name="skin_corpse"
  if (str=="process") help_file_name="process_skins"
  if (str=="sew") help_file_name="sew_skins"

  /* Level 8-11   Guild Rank: 20   "YELLOW"   "ACOLYTE" */
  if (str=="dig") help_file_name="dig_hole"
  if (str=="bury") help_file_name="bury_hole"
  if (str=="detect") help_file_name="detect_disease"
  if (str=="cure") help_file_name="cure_diseases"
  if (str=="flash") help_file_name="flash"
  if (str=="etheral") help_file_name="etheral_door"
  if (str=="ice") help_file_name="ice"
  if (str=="forbid") help_file_name="forbid_entry"
  if (str=="sanctuary") help_file_name="sanctuary"

  /* Level 12-14   Guild Rank: 40   "BLUE"   "LEARNED" */
  if (str=="acid") help_file_name="acid"
  if (str=="grease") help_file_name="oil_of_slipperiness"
  if (str=="air") help_file_name="air_elemental"
  if (str=="earth") help_file_name="earth_elemental"
  if (str=="fire") help_file_name="fire_elemental"
  if (str=="dismiss") help_file_name="dismiss_elemental"
  if (str=="peace") help_file_name="peace"
  if (str=="haze") help_file_name="haze"
  if (str=="transport") help_file_name="transport"

  /* Level 15-18   Guild Rank: 60   "RED"   "ADEPT" */
  if (str=="charity") help_file_name="charity"
  if (str=="fear") help_file_name="fear"
  if (str=="poison") help_file_name="poison"
  if (str=="scan") help_file_name="scan"
  if (str=="summon") help_file_name="summon"
  if (str=="cancel") help_file_name="cancel_summons"
  if (str=="create") help_file_name="create_raven"
  if (str=="aid") help_file_name="aid"

  /* Level 19+    Guild Rank: 80   "BLACK"   "MASTER" */
  if (str=="asell") help_file_name="remote_sell"
  if (str=="hail") help_file_name="hail"
  if (str=="repair") help_file_name="repair"
  if (str=="sharpen") help_file_name="sharpen"
  if (str=="call") help_file_name="call_vampire"

  /* Special (guildmaster)   "PLATINUM"   "GRANDMASTER" */
  if (str=="acheck") help_file_name="check_member"
  if (str=="areplace") help_file_name="replace_MY_POUCH"
  if (str=="apunish") help_file_name="punish_alchemist"
  if (str=="ademote") help_file_name="demote_member"
  if (str=="aexpell") help_file_name="expell_member"
  if (str=="apromote") help_file_name="promote_member"
  if (str=="aremove") help_file_name="remove_member"

  lookup_file_name="/players/nooneelse/Alchemist/hlp/"+help_file_name+".hlp";
  if (str && str!="guild" && file_size(lookup_file_name)>=1) {
    if (help_file_name != "paths_home") {
      write(NORM+CYN+"\n\n"+
            "command              alchemist guild abilities"+
            "                         sp level\n"+
            "-----------------    ----------------------"+
            "------------------------- -- -----\n");
    }
    cat(lookup_file_name);
    write("\n"+NORM);
    return 1;
  }
  if (str=="MY_POUCH" || str=="alchemist" || str=="guild") {
    write(NORM+CYN+"\n                 Alchemist Guild Commands\n");
    cat("/players/nooneelse/Alchemist/hlp/MY_POUCH.hlp");
    write("For further information, use 'help <command>'.\n\n"+NORM);
    return 1;
  }
  if (str=="spell category" || str=="asc") {
	write(NORM+CYN);
    MY_POUCH->more("/players/nooneelse/Alchemist/hlp/spell_category.hlp");
    write(NORM);
    return 1;
  }
  if (str=="spell levels" || str=="asl") {
	write(NORM+CYN);
    MY_POUCH->more("/players/nooneelse/Alchemist/hlp/spell_levels.hlp");
    write(NORM);
    return 1;
  }
  return 0;
}
