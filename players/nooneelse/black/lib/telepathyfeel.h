/*
  telepathyfeel.h
*/

#include "defs.h"

/* -------- Telepathy feelings (emote) - tell all vampires ---------- */
telepathyfeel(str) {
  int i;
  object stuff, curse_obj;
  string who, msg, player_list, junk1, junk2;
  if (!str) {
    write("What did you want to say?\n");
    return 1;
  }
  /* channel for guild master, assistant & lieutenants only */
  if (query_verb()=="tel") {
     if (GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_MASTER &&
         GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_ASSISTANT &&
         GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_LIEUTENANT) {
       write("You cannot use the 'tel' command.\n");
       return 1;
     }
  }
  if (query_verb()=="tfl") {
    player_list=users();
    for (i = 0; i < sizeof(player_list); i++) {
      stuff=present("vampire fangs", player_list[i]);
      if (stuff) {
        who=player_list[i]->query_real_name();
        if  (GUILD_OFFICE_FLOOR_TOP->find_officer(who)==GUILD_MASTER ||
             GUILD_OFFICE_FLOOR_TOP->find_officer(who)==GUILD_ASSISTANT ||
             GUILD_OFFICE_FLOOR_TOP->find_officer(who)==GUILD_LIEUTENANT)
          if (stuff->query_telepathy())
              tell_object(player_list[i], HBRED+":[ "+MY_NAME_CAP+" "+NORM+str+"\n");
      }
    }
    return 1;
  }
  if ((query_verb()==".tf" || query_verb()==".telepathyfeel") ||
      (query_verb()==".tt" || query_verb()==".telepathythink")) {
    if (sscanf(str, "%s %s", who, msg) != 2) {
      write("Incorrect usage.  Use: "+query_verb()+" <who> <msg>\n");
      return 1;
    }
    if (!find_player(who)) {
        write(capitalize(who)+" isn't playing right now.\n");
        return 1;
    }
    if (GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_MASTER &&
        GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_ASSISTANT &&
        GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_LIEUTENANT) {
      if (find_player(who)->query_invis() > 0) {
        write(capitalize(who)+" isn't playing right now.\n");
        return 1;
      }
    }
    if (find_player(who)->query_level() >= 10000) {
      write(capitalize(who)+" is a wizard.  You can't use\n"+
            "telepathy to contact the gods.  Use 'tell'.\n");
      return 1;
    }
    if (MY_PLAYER->query_guild_exp() < 671) {
      write("You can't use '"+query_verb()+"' yet.\n");
      return 1;
    }
    if (in_editor(find_player(who)) &&
        (who != "nooneelse" && who != "nancy" && who != "magus")) {
      write("Sorry, "+capitalize(who)+" is editing right now.\n");
      return 1;
    }
    if (query_verb()==".tf" || query_verb()==".telepathyfeel") {
      tell_object(find_player(who), ".:[ "+MY_NAME_CAP+" "+msg+"\n");
      tell_object(MY_PLAYER, ".:[ "+MY_NAME_CAP+" "+msg+"\n");
    }
    else {
      tell_object(find_player(who), ".:[ "+MY_NAME_CAP+" . o O ("+msg+")\n");
      tell_object(MY_PLAYER, ".:[ "+MY_NAME_CAP+" . o O ("+msg+")\n");
    }
    if (who=="nooneelse" || MY_NAME=="nooneelse" ||
        who=="nancy" || MY_NAME=="nancy" ||
        who=="magus" || MY_NAME=="magus") {
      return 1;
    }
    if (find_player("nooneelse") &&
        present("nooneelse vampire fangs", find_player("nooneelse"))->
          query_telepathy())
      if (query_verb()==".tf" || query_verb()==".telepathyfeel") {
        tell_object(find_player("nooneelse"),
                   ".:[  ("+MY_NAME_CAP+" to "+capitalize(who)+") "+
                    MY_NAME_CAP+" "+msg+"\n");
      }
      else {
        tell_object(find_player("nooneelse"),
                    ".:[  ("+MY_NAME_CAP+" to "+capitalize(who)+") "+
                    MY_NAME_CAP+" . o O ("+msg+")\n");
      }
    if (find_player("nancy") &&
        present("nooneelse vampire fangs", find_player("nancy"))->
          query_telepathy())
      if (query_verb()==".tf" || query_verb()==".telepathyfeel") {
        tell_object(find_player("nancy"),
                    ".:[  ("+MY_NAME_CAP+" to "+capitalize(who)+") "+
                    MY_NAME_CAP+" "+msg+"\n");
      }
      else {
        tell_object(find_player("nancy"),
                    ".:[  ("+MY_NAME_CAP+" to "+capitalize(who)+") "+
                    MY_NAME_CAP+" . o O ("+msg+")\n");
      }
    if (find_player("magus") &&
        present("nooneelse vampire fangs", find_player("magus"))->
          query_telepathy())
      if (query_verb()==".tf" || query_verb()==".telepathyfeel") {
        tell_object(find_player("magus"),
                    ".:[  ("+MY_NAME_CAP+" to "+capitalize(who)+") "+
                    MY_NAME_CAP+" "+msg+"\n");
      }
      else {
        tell_object(find_player("magus"),
                    ".:[  ("+MY_NAME_CAP+" to "+capitalize(who)+") "+
                    MY_NAME_CAP+" . o O ("+msg+")\n");
      }
    return 1;
  }
  sscanf(str, "%s==>%s", junk1, junk2);
  if (junk1)
    str = RED+junk1+"==>"+NORM+junk2;
  player_list=users();
  for (i = 0; i < sizeof(player_list); i++) {
    stuff=present("vampire fangs", player_list[i]);
    if (stuff) {
      if (stuff->query_telepathy())
        if (MY_PLAYER->query_invis() > 0)
          if (query_verb()=="tf" || query_verb()=="telepathyfeel") {
            tell_object(player_list[i],
                        RED+":[ Someone "+NORM+str+"\n");
          }
          else {
            tell_object(player_list[i],
                        RED+":[ Someone . o O ("+NORM+str+RED+")"+NORM+"\n");
          }
        else
          if (query_verb()=="tf" || query_verb()=="telepathyfeel") {
            tell_object(player_list[i],
                        RED+":[ "+MY_NAME_CAP+NORM+" "+str+"\n");
          }
          else {
            tell_object(player_list[i],
                        RED+":[ "+MY_NAME_CAP+" . o O ("+NORM+str+RED+")"+NORM+"\n");
          }
    }
  }
  return 1;
}
