#define ITEMLIST "players/mizan/etheriel/ROOMS/4CC-ITEMLIST"
inherit "players/mizan/closed/RandomRoom.c";
string items;
int pushed_tl;
reset() {
  ::reset();
  set_light(1);
  if(restore_object(ITEMLIST)) {
    rsay("The ether-muck bubbles and gribbles in a most bloated way.\n");
  }
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/environs/wz-pinball.c",
    "players/mizan/obit.c",
    "players/mizan/etheriel/environs/4cc-sign",
    "players/mizan/etheriel/items/rack.c",
  });
  ::extra_reset();
}

query_zokko() { return "Ieeeeee!!!!"; }

init() {
  ::init();
  add_action("up","up");
  add_action("nuck","machine");
  add_action("push","push");
  add_action("tug","tug");
}

nuck() {
  this_player()->move_player("machine#players/mizan/etheriel/ROOMS/nuck.c");
  return 1;
}

up() {
  this_player()->move_player("up#room/wild1");
  return 1;
}

push() {
  object ob;
  string filname;
  string temp1;
  string filtemp;
  if(pushed_tl) {
  write("You push helplessly at the ether-muck.\n");
  rsay((this_player()->query_name()) + " pushes helplessly at the ether-muck.\n");
  return 1;
  }
  write("You push against the ether-muck.\n");
  rsay((this_player()->query_name()) + " pushes against the ether-muck.\n");
  pushed_tl=1;
  items = "";
  ob = first_inventory(this_object());
  while(ob) {
    object oc;
    oc=ob;
    ob=next_inventory(ob);
    if(!living(oc)) {
      filtemp = object_name(oc);
      if(filtemp) if(sscanf(filtemp,"%s#%s",filname,temp1) == 2) if(filname)
      if(!oc->get() ||
    oc->query_save_flag() ||
      filname == "players/mythos/prac/bag"){
        rsay("Nothing happens to " + (oc->short()) + ".\n");
      } else {
        items = items + filname + "^!";
        rsay((oc->short()) + " disappears into the ether-muck.\n");
        destruct(oc);
      }
    }
  }
  save_object(ITEMLIST);
  write("Ok.\n");
  return 1;
}

tug() {
  if(!pushed_tl) {
    write("You tug helplessly at the ether-muck.\n");
    rsay((this_player()->query_name()) + " tugs helplessly at the ether-muck.\n");
    return 1;
  }
  if(restore_object(ITEMLIST)) {
    write("You tug against the ether-muck.\n");
    rsay((this_player()->query_name()) + " tugs against the ether-muck.\n");
    load_thingies(items);
    pushed_tl=0;
    items="";
    save_object(ITEMLIST);
    return 1;
  } else {
    write("Nothing happens.\n");
    rsay((this_player()->query_name()) + " tugs against the ether-muck but nothing happens.\n");
    return 1;
  }
}

load_thingies(str) {
    string file, argument, rest;
    object ob;
    while(str && str != "") {
      if(sscanf(str, "%s^!%s", file, rest) != 2) {
        write("Something wrong happens. Everything disappears with a soft 'poof'.\n");
        return;
      }
    str = rest;
    ob = clone_object(file);
  rsay((ob->short()) + " fades into view.\n");
    move_object(ob, this_object());
  }
}

short() { return "Plane of Etheriel [many exits]"; }

long() {
  int i;
  string lngfrm;
  write("\n"+
"\tBefore you is an array of things that are suspended in this\n"+
"  gloopy glock ether-muck stuff with an astoundingly uncanny sense of\n"+
"  order. The current seems to be happy and consistent here, not too\n"+
"  viscous as to feel air-like, and not too slow like melted tar.\n"+
"  in either case, you feel very comfortable right 'here' at this\n"+
"  moment.\n");
  lngfrm = "There are many obvious exits: up, machine,";
  while(i < sizeof(dest_dir)) {
    lngfrm = lngfrm + " " + dest_dir[i];
    i += 1;
    if (i == sizeof(dest_dir) - 1)
      lngfrm = lngfrm + " and";
      else if (i < sizeof(dest_dir))
        lngfrm = lngfrm + ",";
    }
  lngfrm = lngfrm + ".";
  lngfrm = format(lngfrm, 70);
  write(lngfrm + "\n");
}

rsay(str) {
  tell_room(this_object(), str);
  return 1;
}

