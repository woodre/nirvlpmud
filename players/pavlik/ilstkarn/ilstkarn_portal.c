#include "/players/pavlik/ilstkarn/ILSTKARN"
#define NAME "Pavlik"

string location;

id(str) { 
  return str == "portal";
}

short() {
  return "A mysterious portal to another world. [open]";
}

long() {
  write(
  "The forbidden portal to the Ilstkarken Mountains, home of the\n"+
  "Ilstkarn Wizards.  Only the brave, or foolish, would set foot\n"+
  "inside this portal.  The evil wizards of Ilstkarn do not welcome\n"+
  "trespassers.\n");
  return;
}


init() {
  if(this_player() && environment() && present(this_player(), environment()))
  add_action("enter","enter");
}

enter(str) {
  if(!str || !id(str)) return 0;
/*
  if(this_player()->query_real_name() != "fakirdude")
  write("Not open.\n-Verte\n");
  else
*/
  if(str == "portal") {
    this_player()->move_player("into the Portal of Ilstkarn#players/pavlik/ilstkarn/enter");
    write_file("/players/pavlik/ilstkarn/LOG",
    capitalize(this_player()->query_real_name())+" has entered the portal. ["+ctime()+"]\n");
    return 1;
  }
  return 0;
}

/* 
 * this should keep this object from ever being dested.
 */
clean_up(){ return 0; }

reset(arg) {
  location = random(6);
  if(location == 0) { move_object(this_object(), "room/forest1"); }
  if(location == 1) { move_object(this_object(), "room/fortress"); }
  if(location == 2) { move_object(this_object(), "room/sunalley1"); }
  if(location == 3) { move_object(this_object(), "room/eastroad5"); }
  if(location == 4) { move_object(this_object(), "room/southroad2"); }
  if(location == 5) { move_object(this_object(), "room/lanceroad4"); }
  ("players/pavlik/castle")->set_portal_location(environment(this_object()));

  if(!arg) {
    monster_num = random(5);
  }

}

is_castle(){ return 1; }


okay_follow() { return 1; }
