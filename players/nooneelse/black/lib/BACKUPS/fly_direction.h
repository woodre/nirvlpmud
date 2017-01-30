/*
  fly_direction.h
*/

#include "defs.h"

/* -------- Fly in a direction until you encounter x ---------- */
fly_direction(str) {
  string direction_str, str2, str3, str4, my_brief_str, fly_array;
  string target_name;
  object old_room_obj, original_room_obj;
  int n, flying, found_it, nbr_rooms_flown, max_rooms, nbr_rooms_selected;
  int total_rooms_flown;

  if (!str) return 0;
  if (!str) {
    write("Use: fly <direction> [to <what>]\n"+
          " or: fly ##<direction>  (no space between the # & direction)\n"+
          " or: fly -##<direction>,##<direction>,##<direction>,...\n");
    return 1;
  }
  if (MY_LEVEL < 7 || MY_GUILD_EXP < 669) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  str2 = str;
  str = str+" to @@@";
  sscanf(str, "%s to %s", direction_str, target_name);
  nbr_rooms_flown = 0;
/* Changes implemented by Pain on 29 May 96 */
/* The max room numbers were severely lowered
*/
  if (MY_PLAYER->query_brief()) {
    max_rooms = 5;
    my_brief_str = "brief";
  }
  else {
    max_rooms = 5;
    my_brief_str = "verbose";
  }

  MY_FANGS->set_in_flight(1);
  /* Fly #dir,#dir,#dir,etc. */
  if (sscanf(str2, "-%s", direction_str)==1) {
    total_rooms_flown=0;
    original_room_obj = MY_ROOM;
    fly_array = explode(direction_str, ",");
    for (n=0; n<sizeof(fly_array); n++) {
      if (fly_array[n] &&
          sscanf(fly_array[n], "%d%s", nbr_rooms_selected, direction_str)==2) {
        flying = 1;
        if (total_rooms_flown >= max_rooms) flying = 0;
        nbr_rooms_flown = 0;
        while (flying) {
          write("\nFlying "+nbr_rooms_selected+" rooms '"+
                direction_str+"'.\n\n");
          nbr_rooms_flown++;
          total_rooms_flown++;
          if (nbr_rooms_flown >= nbr_rooms_selected ||
              total_rooms_flown >= max_rooms) {
            write("\nMaximum number of allowed flying rooms has been reached!\n\n");
            flying = 0;
          }
          old_room_obj = MY_ROOM;
          if (!check_fly_command(direction_str, MY_PLAYER)) {
            flying = 0;
            nbr_rooms_flown = 666;
          }
          if (old_room_obj==MY_ROOM) {
            flying = 0;
            nbr_rooms_flown = 666;
          }
        }
      }
    }
    for (n=0; n<sizeof(fly_array); n++) fly_array[n] = 0;
    if (nbr_rooms_flown==666) {
      move_object(MY_PLAYER, original_room_obj);
      write("\nSomething stopped the completion of the commands!\n"+
            "Returning to original room!\n\n");
      if (MY_PLAYER->query_brief())
        tell_object(MY_PLAYER, MY_ROOM->short()+"\n");
      else
        command("look", MY_PLAYER);
    }
    else
      write("\nYou've arrived.\n\n");
    MY_FANGS->set_in_flight(0);
    return 1;
  }

  /* Fly ### rooms in <direction> */
  if (sscanf(str, "%d%s to @@@", nbr_rooms_selected, direction_str)==2) {
    found_it = 0;
    flying = 1;
    while (flying) {
      write("\nFlying "+nbr_rooms_selected+" rooms '"+direction_str+"'.\n\n");
      old_room_obj = MY_ROOM;
      if (!check_fly_command(direction_str, MY_PLAYER)) flying = 0;
      if (old_room_obj==MY_ROOM) flying = 0;
      nbr_rooms_flown++;
      if (nbr_rooms_flown >= nbr_rooms_selected) flying = 0;
      if (nbr_rooms_flown >= max_rooms) flying = 0;
    }
    if (nbr_rooms_flown >= nbr_rooms_selected)
      write("\nYou've flown '"+direction_str+"' for "+nbr_rooms_selected+
            " rooms.\n\n");
    else
    if (nbr_rooms_flown >= max_rooms)
      write("\nYou've flown '"+direction_str+"' for "+max_rooms+
            " rooms (the max in "+my_brief_str+" mode).\n\n");
    else
    if (old_room_obj==MY_ROOM)
      write("\nYou've flown as far '"+direction_str+"' as you can.\n\n");
    MY_FANGS->set_in_flight(0);
    return 1;
  }

  /* fly in a direction */
  if (target_name=="@@@") {
    flying = 1;
    while (flying) {
      write("\nFlying '"+direction_str+"'.\n\n");
      old_room_obj = MY_ROOM;
      if (!check_fly_command(direction_str, MY_PLAYER)) flying = 0;
      if (old_room_obj==MY_ROOM) flying = 0;
      nbr_rooms_flown++;
      if (nbr_rooms_flown >= max_rooms) flying = 0;
    }
    if (nbr_rooms_flown >= max_rooms)
      write("\nYou've flown '"+direction_str+"' for "+max_rooms+
            " rooms (the max in "+my_brief_str+" mode).\n\n");
    else
      write("\nYou've flown as far '"+direction_str+"' as you can.\n\n");
    MY_FANGS->set_in_flight(0);
    return 1;
  }

  /* Fly till we encounter target_name */
  sscanf(str, direction_str+" to %s to @@@", target_name);
  found_it = 0;
  flying = 1;
  while (flying) {
    write("\nFlying '"+direction_str+"' to '"+target_name+"'.\n\n");
    old_room_obj = MY_ROOM;
    if (!check_fly_command(direction_str, MY_PLAYER)) flying = 0;
    if (present(target_name, MY_ROOM)) {
      flying = 0;
      found_it = 1;
    }
    if (old_room_obj==MY_ROOM) flying = 0;
    /* see if it's in the room's short */
    str2 = MY_ROOM->short();
    if (target_name==str2) {
      flying = 0;
      found_it = 1;
    }
    else
    if (sscanf(str2, target_name+"%s", str3)==1) {
      flying = 0;
      found_it = 1;
    }
    else
    if (sscanf(str2, "%s"+target_name+"%s", str3, str4)==2) {
      flying = 0;
      found_it = 1;
    }
    else
    if (sscanf(str2, "%s"+target_name, str3, str4)==2) {
      flying = 0;
      found_it = 1;
    }
    if (capitalize(target_name)==str2) {
      flying = 0;
      found_it = 1;
    }
    else
    if (sscanf(str2, capitalize(target_name)+"%s", str3)==1) {
      flying = 0;
      found_it = 1;
    }
    else
    if (sscanf(str2, "%s"+capitalize(target_name)+"%s", str3, str4)==2) {
      flying = 0;
      found_it = 1;
    }
    nbr_rooms_flown++;
    if (nbr_rooms_flown >= max_rooms) flying = 0;
  }
  if (found_it)
    write("\nYou've arrived at '"+target_name+"'.\n\n");
  else
  if (!found_it)
    write("\nYou've flown as far '"+direction_str+"' as you can.\n\n");
  else
  if (nbr_rooms_flown >= max_rooms)
     write("\nYou've flown '"+direction_str+"' for "+max_rooms+
            " rooms (the max in "+my_brief_str+" mode).\n\n");
  MY_FANGS->set_in_flight(0);
  return 1;
}
check_fly_command(flydir, meob) {
   if(flydir!="n"&&flydir!="e"&&flydir!="w"&&flydir!="s"&&flydir!="ne"&&flydir!="nw"&&flydir!="sw"&&flydir!="se"&&flydir!="u"&&flydir!="d") 
   if(flydir!="north"&&flydir!="east"&&flydir!="west"&&flydir!="south"&&flydir!="northeast"&&flydir!="northwest"&&flydir!="southwest"&&flydir!="southeast"&&flydir!="up"&&flydir!="down") {
      write("You may only use direction commands, n,e,w,s,ne,nw,sw,se,u, and d.\n");
      return 0;
   }
   if(command(flydir, MY_PLAYER)) return 1;
   return 0;
}
