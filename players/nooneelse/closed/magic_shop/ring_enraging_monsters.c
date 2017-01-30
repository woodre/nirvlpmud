/*
  ring_enraging_monsters.c

  This is a ring of enraging monsters.  It is cursed and, once worn, can't
  be dropped except in the church.  It will make any monster the holder
  encounters attack him/her/it.
*/

inherit "obj/armor";

string str;
int ring_worn, stop_loop;


init() {
  ::init();

  add_action("wear_ring",   "wear");
  add_action("read_ring",   "read");
  add_action("drop_ring",   "drop");
  add_action("drop_ring",   "remove");
  add_action("who_is_here", "north", 1);
  add_action("who_is_here", "northeast");
  add_action("who_is_here", "ne");
  add_action("who_is_here", "east", 1);
  add_action("who_is_here", "southeast");
  add_action("who_is_here", "se");
  add_action("who_is_here", "south", 1);
  add_action("who_is_here", "southwest");
  add_action("who_is_here", "sw");
  add_action("who_is_here", "west", 1);
  add_action("who_is_here", "northwest");
  add_action("who_is_here", "nw");
  add_action("who_is_here", "enter");
  add_action("who_is_here", "in");
  add_action("who_is_here", "exit");
  add_action("who_is_here", "out");
  add_action("who_is_here", "leave");
}


/* start the curse */
wear_ring(str) {
  if (!str || !id(str)) return 0;
  ring_worn=1;
  return 0;
}

/* Clue the player of the curse & tell how/where to get rid of it.      */
read_ring(str) {
  if (!str || !id(str)) return 0;
  write(
    "It says: You really should drop this off where you began life.\n");
  return 1;
}

/* Don't drop the ring unless player is in the church */
drop_ring(str) {
  int weight;
  string str1, str2, str3;
  if (!str || !id(str) || !ring_worn) return 0;
  str1=file_name(environment(this_player()));
  sscanf(str1, "%s.c", str2);
  if (!str2) str2=str1;
  if (str2=="room/church" && present(str,this_player())==this_object()) {
    weight=this_object()->query_weight();
    if (weight <= 0) weight=0;
    this_player()->add_weight(-weight);
    destruct(this_object());
    write("A transparent hand appears and crushes the ring.\n");
    return 1;
  }
  else {
    write("The ring refuses to be parted from you.\n");
    return 1;
  }
  return 1;
}

/* piss off the little guys :) */
who_is_here() {
  object obj;
  int i, nbr, no_more;
  string str, directions, direction, room, s1, s2;
  if (!ring_worn) return 0;
  str=query_verb();
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
  if (sscanf(str, "%s %s", s1, s2)==2)
    if (s1=="in" || s1=="enter") str="enter "+s2;
  if (str == "out") str="exit";
  directions=environment(this_player())->query_dest_dir();
  i=0;
  no_more=0;
  if (!directions) return 0;
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
  if (direction) this_player()->move_player(direction+"#"+room);
  obj = first_inventory(environment(environment(this_object())));
  while (obj) {
    if (obj->query_npc() && obj->query_level() <= 15) {
      obj->attack_object(environment(this_object()));
    }
    obj=next_inventory(obj);
  }
  return 1;
}

reset(arg) {
  ::reset(arg);
  if (arg) return 0;

  set_name("ring");
  set_alias("tin ring");
  set_short("Tin Ring");
  set_long("This is a cheap looking ring that's just your size.\n"+
           "There seems to be something written inside the band.\n");
  set_value(0);
  set_weight(1);
  set_ac(1);
  set_type("ring");
  set_arm_light(1);
}

prevent_insert() {
  write("The "+short()+" shakes and quivers and jumps back into your hand.\n");
  return 1;
}
