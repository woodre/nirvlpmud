#define ROOMDIR "players/mizan/etheriel/ROOMS/"

/* RandomRoom Version 3.1 / LiquidRoom Version 1.0 */

object ob;
string dest_dir;
string short_desc;
string long_desc;
string numbers;
string object_names;

reset() {
  extra_reset();
}

extra_reset() {
  int i;
  dest_dir = call_other("players/mizan/closed/RandomRoomDM", "set_exits");
  if(!object_names) return;
  if(!ob) {
    ob=allocate(sizeof(object_names));
  }
  i = 0;
  while(i < sizeof(object_names)) {
    if(!ob[i]) {
      ob[i]=clone_object(object_names[i]);
      move_object(ob[i], this_object());
    }
  i += 1;
  }
}

init() {
  int i;
  if (!dest_dir) return;
  i = 0;
  while(i < sizeof(dest_dir)) {
    add_action("move", dest_dir[i]);
    i += 1;
  }
  add_action("wimpy_exit","down");
  add_action("area_tell","bleat");
  add_action("wormhole","wormhole");
}

id(str) { return str == "RandomRoom"; }

long() {
  int i;
  string lngfrm;
  if(set_light(0) == 0) {
    write("It is dark.\n");
    return;
  }
  write(long_desc);
  if(!dest_dir) write("No obvious exits.\n");
  else {
    i = 0;
    if(sizeof(dest_dir) == 1) lngfrm = "There is one obvious exit:";
    else
      lngfrm = "There are " + convert_number(sizeof(dest_dir)) + " obvious exits:";
      while(i < sizeof(dest_dir)) {
        lngfrm = lngfrm + " " + dest_dir[i];
        i += 1;
          if (i == sizeof(dest_dir) - 1) lngfrm = lngfrm + " and";
          else
            if (i < sizeof(dest_dir)) lngfrm = lngfrm + ",";
      }
    lngfrm = lngfrm + ".";
    lngfrm = format(lngfrm, 70);
    write(lngfrm + "\n");
  }
  return;
}

wormhole(str) {
  call_other("/players/mizan/closed/LiquidRoomDM.c", "wormhole", str);
  return 1;
}

area_tell(str) {
  call_other("/players/mizan/closed/LiquidRoomDM.c", "area_tell", str);
  return 1;
}

wimpy_exit() {
  string feedme;
  if(!this_player()->query_attack()) return 0;
  feedme=call_other("/players/mizan/closed/RandomRoomDM", "one_random", 0);
  this_player()->move_player("wimpy#"+ ROOMDIR + feedme);
  return 1;
}

move(str) {
  int i;
  i = 0;
  while(i < sizeof(dest_dir)) {
    if(query_verb() == dest_dir[i]) {
      this_player()->move_player(dest_dir[i] + "#" + ROOMDIR + dest_dir[i]);
      return 1;
    }
  i += 1;
  }
}

short() {
  int i;
  string temp;
  temp=short_desc+" [";
    for (i=0;i<sizeof(dest_dir);i+=1) {
      temp += dest_dir[i];
      if (i < sizeof(dest_dir)-1) temp += ",";
    }
  temp += "]";
  return temp;
}

query_version() { return "RandomRoom Version 3.0 / LiquidRoom Version 1.0"; }

convert_number(n) {
  numbers = call_other("room/room", "query_numbers");
  if (n > 9) {
    return "many";
  } else {
  return numbers[n];
  }
}

