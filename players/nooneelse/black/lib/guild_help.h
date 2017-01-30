/*
  guild_help.h
*/

#include "defs.h"

/* --------------- Display the help info for the fangs --------------- */
guild_help(str) {
  string help_file_name, cat_return, lookup_file_name;
  int start_line, nbr_lines;
  object obj;
  if (!str) return 0;
if(str == "task") help_file_name = "task";
if(str == "tasks")
  if (GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)==GUILD_MASTER ||
    GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)==GUILD_ASSISTANT ||
    GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)==GUILD_LIEUTENANT)
      help_file_name = "tasks_officers";
if(str == "bats") help_file_name = "bats";
if(str=="assess") help_file_name="assess";
  if(str == "awaken") help_file_name = "awaken";
  if (str=="back" &&
      (GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)==GUILD_MASTER ||
       GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)==GUILD_ASSISTANT ||
       GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)==GUILD_LIEUTENANT))
    help_file_name="back";
  if (str=="backhand") help_file_name="backhand";
  if (str=="bite") help_file_name="bite";
  if (str=="bury" || str=="bury hole") help_file_name="bury_hole";
  if (str=="call wolf") help_file_name="call_wolf";
  if (str=="calm") help_file_name="calm";
  if (str=="cancel") help_file_name="cancel";
  if (str=="cancel") help_file_name="cancel";
  if (str=="charity") help_file_name="charity";
  if (str=="clairaudience" || str=="ca" &&
      (GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)==GUILD_MASTER ||
       GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)==GUILD_ASSISTANT))
    help_file_name="clairaudience";
  if (str=="clairvoyance" || str=="cv") help_file_name="clairvoyance";
  if (str=="guild levels" || str=="guild level") help_file_name="guild_tasks";
  if (str=="guild news") help_file_name="guild_news";
  if (str=="cure" || str=="cure disease") help_file_name="cure_disease";
  if (str=="damn") help_file_name="damn";
  if (str=="defend" || str=="defend me") help_file_name="defend_me";
  if (str=="defile") help_file_name="defile";
  if (str=="dig" || str=="dig hole") help_file_name="dig_hole";
  if (str=="disguise") help_file_name="disguise";
  if (str=="mist form" || str=="bat form" || str=="wolf form")
    help_file_name="form";
  if (str=="drain" || str=="drain corpse") help_file_name="drain_corpse";
  if (str=="emote") help_file_name="emote";
  if (str=="eyes") help_file_name="eyes";
  if (str=="expell" &&
      (GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)==GUILD_MASTER ||
       GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)==GUILD_ASSISTANT))
    help_file_name="expell";
  if (str=="fear") help_file_name="fear";
if(str == "fix" || str == "heartbeat" || str == "fix heartbeat") 
   help_file_name = "fix_title";
  if (str=="fly") help_file_name="fly";
  if (str=="friends") help_file_name="friends";
  if (str=="glance") help_file_name="glance";
  if (str=="gohome") help_file_name="gohome";
  if (str=="grasp") help_file_name="grasp";
  if (str=="health") help_file_name="health";
  if (str=="hellfire") help_file_name="hellfire";
  if (str=="illusion") help_file_name="illusion";
  if (str=="infuse") help_file_name="infuse";
  if (str=="leave guild") help_file_name="leave";
  if (str=="magic dart" || str=="magic darts" ||
      str=="vampire dart" || str=="vampire darts") help_file_name="magic_dart";
  if (str=="office" &&
      (GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)==GUILD_MASTER ||
       GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)==GUILD_ASSISTANT ||
       GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)==GUILD_LIEUTENANT))
    help_file_name="office";
  if(str == "obits") help_file_name = "obits";
  if (str=="paths") help_file_name="paths_home";
  if (str=="process skins" || str=="process skin")
    help_file_name="process_skin";
  if ((str=="punish" || str=="punish vampire") &&
      (GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)==GUILD_MASTER ||
       GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)==GUILD_ASSISTANT ||
       GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)==GUILD_LIEUTENANT))
    help_file_name="punish_vampire";
  if (str=="regenerate") help_file_name="regenerate";
  if (str=="release" &&
      GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)==GUILD_MASTER)
    help_file_name="release";
  if (str=="remember") help_file_name="remember";
  if ((str=="remove") &&
      (GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)==GUILD_MASTER ||
       GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)==GUILD_ASSISTANT ||
       GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)==GUILD_LIEUTENANT))
    help_file_name="remove_fangs";
  if (str=="repair" &&
      (GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)==GUILD_MASTER ||
       GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)==GUILD_ASSISTANT ||
       GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)==GUILD_LIEUTENANT))
    help_file_name="repair";
  if (str=="replace" &&
      (GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)==GUILD_MASTER ||
       GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)==GUILD_ASSISTANT ||
       GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)==GUILD_LIEUTENANT))
    help_file_name="replace";
  if (str=="reset guild exp" &&
      (GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)==GUILD_MASTER ||
       GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)==GUILD_ASSISTANT ||
       GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)==GUILD_LIEUTENANT))
    help_file_name="reset";
  if (str=="rip") help_file_name="rip_throat";
  if (str=="sanctuary") help_file_name="sanctuary";
  if (str=="scan") help_file_name="scan";
  if (str=="scratch") help_file_name="scratch";
  if (str=="servant") help_file_name="servant";
  if (str=="sew skins") help_file_name="sew_skins";
  if (str=="shift") help_file_name="shift_hp";
  if (str=="skin corpse") help_file_name="skin_corpse";
  if (str=="sharpen fangs") help_file_name="sharpen_fangs";
  if (str=="shelf" &&
      (GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)==GUILD_MASTER))
    help_file_name="shelf_check";
  if (str=="solve task") help_file_name="solve_task";
  if (str=="startup") help_file_name="startup";
  if (str=="summon") help_file_name="summon";
if(str == "telekenetics") help_file_name = "telekenetics";
  if (str=="telepathy" || str=="te" || str==".te" ||
      str=="telepathyfeel" || str=="tf" || str==".tf" ||
      str=="telepathythink" || str=="tt" || str==".tt")
    help_file_name="telepathy";
  if (str=="think" || str=="thi") help_file_name="think";
  if (str=="transfer") help_file_name="transfer";
  if (str=="translate") help_file_name="translate";
  if(str == "wraith form") help_file_name = "wraith_form";
  lookup_file_name="/players/nooneelse/black/hlp/"+help_file_name+".hlp";
  if (str && str!="guild" && file_size(lookup_file_name)>=1) {
    if (help_file_name != "paths_home") {
      write("\n\n"+
            "command              vampire guild abilities"+
            "                         sp level\n"+
            "-----------------    ----------------------"+
            "------------------------- -- -----\n");
    }
    cat(lookup_file_name);
    write("\n");
    return 1;
  }
  if (str=="fangs" || str=="vampire" || str=="cult" || str=="guild") {
    write("\n                 Vampire Guild Commands\n");
    cat("/players/nooneelse/black/hlp/fangs.hlp");
    write("For further information, use 'help <command>'.\n\n");
    return 1;
  }
  if (str=="spell category" || str=="vsc") {
    MY_FANGS->more("/players/nooneelse/black/hlp/spell_category.hlp");
    return 1;
  }
  if (str=="spell levels" || str=="vsl") {
    MY_FANGS->more("/players/nooneelse/black/hlp/spell_levels.hlp");
    return 1;
  }
  return 0;
}
