/*
  clairvoyance.h
*/

#include "defs.h"

/* ------------ Clairvoyance ------------ */
clairvoyance(str) {
  int i, nbr, no_more;
  string directions, direction, room, s1, s2;
  object obj, room_obj;
  if(!str) {
    write("You must supply the direction you want to peek.\n");
    write("Use: clairvoyance <direction> or cv <direction>\n");
    return 1;
  }
  if (MY_LEVEL < 8 || MY_GUILD_EXP < 669) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  if (MY_SPELL_POINTS < 15) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  MY_PLAYER->add_spell_point(- 15);
  /* check for the direction commands & fix em */
  if (str=="n") str="north";
  if (str=="ne") str="northeast";
  if (str=="e") str="east";
  if (str=="se") str="southeast";
  if (str=="s") str="south";
  if (str=="sw") str="southwest";
  if (str=="w") str="west";
  if (str=="nw") str="northwest";
  if (str=="u") str="up";
  if (str=="d") str="down";
  if (sscanf(str, "%s %s", s1, s2) == 2)
    if (s1 == "in" || s1 == "enter") str="enter "+s2;
  if (str == "out") str="exit";
  directions=MY_ROOM->query_dest_dir();
  i = 0;
  no_more=0;
  if (!directions) {
    if (MY_SPELL_POINTS < 15) {
      write("You don't have enough spell points.\n");
      return 1;
    }
    MY_PLAYER->add_spell_point(- 15);
    send_peeker(str);
    return 1;
  }
  nbr=sizeof(directions);
  direction=0;
  if (nbr) {
    while(i < sizeof(directions)) {
      if (!no_more) {
        room=directions[i];
        i += 1;
        direction=directions[i];
        i += 1;
      }
      if (no_more) i+=2;
      if (direction==str)
        no_more=1;
      else
        direction=0;
    }
  }
  if (direction) {
    if (MY_SPELL_POINTS < 15) {
      write("You don't have enough spell points.\n");
      return 1;
    }
    MY_PLAYER->add_spell_point(- 15);
    room_obj = find_ob(room);
    if (room_obj) {
      write("\nTo the '"+direction+"', you see:\n\n");
      call_other(room_obj, "long", 0);
      inventory(room_obj);
    }
    else {
      send_peeker(str);
      return 1;
    }
    write("\n");
  }
  else
  if (s1 == "in" || s1 == "enter") {
    if (MY_SPELL_POINTS < 15) {
      write("You don't have enough spell points.\n");
      return 1;
    }
    MY_PLAYER->add_spell_point(- 15);
    send_peeker(str);
  }
  else {
    if (MY_SPELL_POINTS < 15) {
      write("You don't have enough spell points.\n");
      return 1;
    }
    MY_PLAYER->add_spell_point(- 15);
    write("You can't seem to see in that direction.\n");
  }
  return 1;
}


send_peeker(str) {
  object obj, peeker_environment;
  obj=clone_object(PEEKER);
  move_object(obj, MY_ROOM);
  obj->init_command(str);
  peeker_environment=environment(obj);
  if (peeker_environment==MY_ROOM)
    write("You can't seem to see in that direction..\n");
  else {
    write("\nTo the '"+str+"', you see:\n\n");
    call_other(peeker_environment, "long", 0);
    inventory(peeker_environment);
    write("\n");
  }
  return 1;
}

/* Find an object */
find_ob(str) {
  string s1, s2, tmp;
  int nbr;
  object obj;
  if(!str) { Error("No arg to find_ob."); return 1; }
  if(sscanf(str, "%s,%s", s1, s2) != 2) {
    if(sscanf(str, "%d", nbr) == 1) {
      return nbr_in_ob(nbr, my_room());
    }
    else {
      return search_all(str);
    }
  }
  obj = search_all(s1);
  while(s2 && obj) {
    tmp = 0;
    if(sscanf(s2, "%s,%s", s1, tmp) != 2) s1 = s2;
    obj = search_next(s1, obj);
    s2 = tmp;
  }
  return obj;
}

/* ----------------- search for the item --------------------- */
search_all(str) {
  object obj;
  if(!str) { Error("No arg to search_all()."); return 1; }
  obj=0;
  if(!obj) obj = present(str, MY_PLAYER);
  if(!obj) obj = present(str, MY_ROOM);
  if(!obj) obj = find_object(str);
  if(!obj) obj = find_living(str);
  if(!obj) obj = find_living("ghost of " + str);
  return obj;
}

/* Find out how many objects there are */
nbr_in_ob(n, obj) {
  object obj2;
  int nbr;
  nbr = n;
  if((nbr < 0) || !obj) return;
  obj2 = first_inventory(obj);
  while(obj2 && nbr) {
    obj2 = next_inventory(obj2);
    nbr -= 1;
  }
  return obj2;
}

search_next(str, obj) {
  int nbr;
  if(sscanf(str, "%d", nbr) == 1)
    return nbr_in_ob(nbr, obj);
  else if(str == "env")
    return environment(obj);
  return present(str, obj);
}

/* Display an error message */
Error(str) {
  write("*** Error");
  if(!str)
    write(".\n");
  else
    write(": " + str + "\n");
  return 1;
}

inventory(inventory_arg) {
  object obj;
  obj=first_inventory(inventory_arg);
  while (obj) {
    if (obj->short() && (obj->query_name() != "peeker")) {
      write(obj->short());
      write("\n");
    }
  obj=next_inventory(obj);
  }
  return 1;
}
