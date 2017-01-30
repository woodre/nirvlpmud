/*
  telepathy.h
*/

#include "defs.h"

/* -------- Telepathy - tell all vampires ---------- */
telepathy(str) {
  int i, n, n2, n3;
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
  if (query_verb()=="tel") {
    player_list=users();
    for (i = 0; i < sizeof(player_list); i++) {
      stuff=present("nooneelse@vampire@fangs", player_list[i]);
      if (stuff) {
        who=player_list[i]->query_real_name();
        if  (GUILD_OFFICE_FLOOR_TOP->find_officer(who)==GUILD_MASTER ||
             GUILD_OFFICE_FLOOR_TOP->find_officer(who)==GUILD_ASSISTANT ||
             GUILD_OFFICE_FLOOR_TOP->find_officer(who)==GUILD_LIEUTENANT)
          tell_object(player_list[i], REV_RED+":[ "+MY_NAME_CAP+"-===>"+END+str+"\n");
      }
    }
    return 1;
  }
  if (query_verb()==".te" || query_verb()=="!telepathy") {
    if (sscanf(str, "%s %s", who, msg) != 2) {
      write("Incorrect usage.  Use: .te <who> <msg>\n");
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
/*  temp fix so vamps can log on   Eurale  5/22/97
    if (find_player(who)->query_d.  You can't use\n"+
            "telepathy to contact the gods.  Use 'tell'.\n");
      return 1;
    }
*/
    if (MY_GUILD_EXP < 671) {
      write("You can't use '.te' yet.\n");
      return 1;
    }
    if (in_editor(find_player(who)) &&
        (GUILD_OFFICE_FLOOR_TOP->find_officer(who)!=GUILD_MASTER &&
         GUILD_OFFICE_FLOOR_TOP->find_officer(who)!=GUILD_ASSISTANT)) {
      write("Sorry, "+capitalize(who)+" is editing right now.\n");
      return 1;
    }
    tell_object(find_player(who), "."+MY_NAME_CAP+" to "+
                capitalize(who)+"->"+msg+"\n");
    tell_object(MY_PLAYER, "."+MY_NAME_CAP+" to "+
                capitalize(who)+"->"+msg+"\n");
    if  (GUILD_OFFICE_FLOOR_TOP->find_officer(who)==GUILD_MASTER ||
         GUILD_OFFICE_FLOOR_TOP->find_officer(who)==GUILD_ASSISTANT ||
         MY_NAME==GUILD_MASTER || MY_NAME==GUILD_ASSISTANT)
      return 1;
    if (find_player("nooneelse") &&
        present("nooneelse vampire fangs", find_player("nooneelse"))->
          query_telepathy())
      tell_object(find_player("nooneelse"),
                  ".  ("+MY_NAME_CAP+" to "+capitalize(who)+") "+msg+"\n");
    if (find_player("nancy") &&
        present("nooneelse vampire fangs", find_player("nancy"))->
          query_telepathy())
      tell_object(find_player("nancy"),
                  ".  ("+MY_NAME_CAP+" to "+capitalize(who)+") "+msg+"\n");
    if (find_player("magus") &&
        present("nooneelse vampire fangs", find_player("magus"))->
          query_telepathy())
      tell_object(find_player("magus"),
                  ".  ("+MY_NAME_CAP+" to "+capitalize(who)+") "+msg+"\n");
    return 1;
  }
  if (str=="on") {
    MY_FANGS->set_telepathy(1);
    write("Telepathy is now on.\n");
    return 1;
  }
  if (str=="off") {
    MY_FANGS->set_telepathy(0);
    write("Telepathy is now off.\n");
    return 1;
  }
  if (str=="buzz") {
    n=0;
    n2=0;
    n3== 0) {
      tell_object(find_player("nooneelse"),
                  "\n\nzzzzzzzzzzzzzzzz  "+MY_NAME_CAP+
                  " is buzzing you, Nancy & Magus! zzzzzzzzzzzzz\n\n\n");
      n=1;
    }
    if (find_player("nancy") &&
        find_player("nancy")->query_invis() <= 0) {
      tell_object(find_player("nancy"),
                  "\n\nzzzzzzzzzzzzzzzz  "+MY_NAME_CAP+
                  " is buzzing you, Nooneelse & Magus! zzzzzzzzzzzzz\n\n\n");
      n2=1;
    }
    if (find_player("magus") &&
        find_player("magus")->query_invis() <= 0) {
      tell_object(find_player("magus"),
                  "\n\nzzzzzzzzzzzzzzzz  "+MY_NAME_CAP+
                  " is buzzing you, Nooneelse & Nancy! zzzzzzzzzzzzz\n\n\n");
      n3=1;
    }
    if (n==1) write("Nooneelse has been buzzed.\n");
    if (n2==2) write("Nancy has been buzzed.\n");
    if (n3==3) write("Magus has been buzzed.\n");
    return 1;
  }
  if (str=="buzz nooneelse") {
    if (!find_player("nooneelse") ||
        find_player("nooneelse")->query_invis() > 0) {
      write("Nooneelse is not in the mud at the moment.  Try later.\n");
      return 1;
    }
    tell_object(find_player("nooneelse"),
      "\n\nzzzzzzzzzzzzzzzz  "+MY_NAME_CAP+
      " is buzzing you! zzzzzzzzzzzzz\n\n\n");
    return 1;
  }
  if (str=="buzz nancy") {
    if (!find_player("nancy") ||
        find_player("nancy")->query_invis() > 0) {
      write("Nancy is not in the mud at the moment.  Try later.\n");
      return 1;
    }
    tell_object(find_player("nancy"),
      "\n\nzzzzzzzzzzzzzzzz  "+MY_NAME_CAP+
      " is buzzing you! zzzzzzzzzzzzz\n\n\n");
    return 1;
  }
  if (str=="buzz magus") {
    if (!find_player("magus") ||
        find_player("magus")->query_invis() > 0) {
      write("Magus is not in the mud at the moment.  Try later.\n");
      return 1;
    }
    tell_object(find_player("magus"),
      "\n\nzzzzzzzzzzzzzzzz  "+MY_NAME_CAP+
      " is buzzing you! zzzzzzzzzzzzz\n\n\n");
    return 1;
  }
  player_list=users();
  for (i = 0; i < sizeof(player_list); i++) {
    stuff=present("nooneelse@vampire@fangs", player_list[i]);
    if (stuff) {
      if (stuff->query_telepathy())
        if (MY_PLAYER->query_invis() > 0)
          tell_object(player_list[i], RED+":[ Someone==>"+END+str+"\n");
        else
          tell_object(player_list[i], RED+":[ "+MY_NAME_CAP+"==>"+END+str+"\n");
    }
  }
  return 1;
}
