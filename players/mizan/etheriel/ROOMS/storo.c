#define ITEMLIST "players/mizan/etheriel/ROOMS/STORO-ITEMLIST"
inherit "players/mizan/closed/RandomRoom.c";
string items;
int pushed_tl;
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  if(restore_object(ITEMLIST)) {
    rsay("The ether-muck bubbles and gribbles in a most bloated way.\n");
  }
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/fungoid.c",
    "players/mizan/etheriel/beasties/blinking-oofa2.c",
    "players/mizan/etheriel/environs/storo-sign.c"
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
  int tmpl;
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
  sscanf(filtemp, "%s#%s", filname, temp1);
      if(!oc->get() ||
       oc->query_save_flag() ||
       filname == "players/mythos/prac/bag"
       ){
        rsay("Nothing happens to " + (oc->short()) + ".\n");
      } else {
	items = items + filname + "^!";
    tmpl ++;
        rsay((oc->short()) + " disappears into the ether-muck.\n");
        destruct(oc);
      }
    }
  if(tmpl > 3) break;
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
if(file) if(file != "0.c") {
    ob = clone_object(file);
  rsay((ob->short()) + " fades into view.\n");
    move_object(ob, this_object());
  }
}
}

short() { return "Plane of Etheriel [many exits]"; }

long() {
  int i;
  string lngfrm;
  write("\n"+
"\tSome strange popping noises can be felt when you drift into this\n"+
"  area. The viscosity of the ether-muck around you has a very soft and\n"+
"  consistent texture. You deduce that the popping noises are coming from\n"+
"  the elusive portal-like anomalies that you have frequently seen in\n"+
"  this realm. Things that drift near them disappear, but fade into view\n"+
"  after several moments.\n");
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
