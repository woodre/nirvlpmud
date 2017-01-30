/*
  keep_common.c - a file with all the keep's room names & some common variables
*/

string GENERIC_THRONE_ROOM, GENERIC_PARAPIT, GENERIC_REPAIR_ROOM;

#define MAX_DAMAGE 20
#define MAX_SOLDIERS 10

#define TELL_KEEP(str) \
tell_room(THRONE_ROOM,"A herald enters, announces:\n  "+str+"and leaves.\n"); \
tell_room(PARAPIT,"A herald enters, announces:\n  "+str+"and leaves.\n"); \
tell_room(REPAIR_ROOM,"A herald enters, announces:\n  "+str+"and leaves.\n");

int keep_soldiers, keep_damage, gates_are_open, keep_soldiers_defending;
string owner_name, owner_id;
object THRONE_ROOM, PARAPIT, REPAIR_ROOM, keep_obj, keep_room_obj;

set_THRONE_ROOM(arg) { THRONE_ROOM=arg; }
set_PARAPIT(arg) { PARAPIT=arg; }
set_REPAIR_ROOM(arg) { REPAIR_ROOM=arg; }
set_GENERIC_THRONE_ROOM() {
  GENERIC_THRONE_ROOM="/players/nooneelse/closed/keep/keep_throne_room";
}
set_GENERIC_PARAPIT() {
  GENERIC_PARAPIT="/players/nooneelse/closed/keep/keep_parapit";
}
set_GENERIC_REPAIR_ROOM() {
  GENERIC_REPAIR_ROOM="/players/nooneelse/closed/keep/keep_repair";
}
set_keep_room(arg) { keep_room_obj=arg; }
set_owner_name(arg) { owner_name=arg; }
set_keep_obj(arg) { keep_obj=arg; }
set_keep_soldiers(arg) { keep_soldiers=arg; }
set_soldiers_defending(arg) { keep_soldiers_defending=arg; }
set_gates(arg) { gates_are_open=arg; }
set_owner_id(str) { owner_id=owner_name+" keep"; }

query_THRONE_ROOM(arg) { return THRONE_ROOM; }
query_PARAPIT(arg) { return PARAPIT; }
query_REPAIR_ROOM(arg) { return REPAIR_ROOM; }
query_owner_id() { return owner_id; }
query_keep_room() {
  if (!keep_room_obj) keep_room_obj=environment(this_object());
  return keep_room_obj;
}
query_owner_name() {
  if (!owner_name) owner_name="nooneelse";
  return owner_name;
}
query_keep_obj() {
  if (!keep_obj) keep_obj=this_object();
  return keep_obj;
}
query_keep_soldiers() { return keep_soldiers; }
query_max_soldiers() { return MAX_SOLDIERS; }
query_soldiers_defending() { return keep_soldiers_defending; }
query_gates() { return gates_are_open; }
query_keep_damage() { return keep_damage; }
query_max_damage() { return MAX_DAMAGE; }

describe_damage() {
  string damage_msg, defending_msg;
  if (query_soldiers_defending())
    defending_msg="are";
  else
    defending_msg="are not";
  damage_msg=
    "     There are "+query_keep_soldiers()+" soldier(s) in the keep.\n"+
    "     The soldier(s) "+defending_msg+" actively defending the keep.\n"+
    "     The keep is ";
  if (query_keep_damage()==0) return damage_msg+"in perfect condition";
  if (query_keep_damage()<=2) return damage_msg+"in very good condition";
  if (query_keep_damage()<=4) return damage_msg+"in good condition";
  if (query_keep_damage()<=6) return damage_msg+"barely damaged";
  if (query_keep_damage()<=8) return damage_msg+"slightly damaged";
  if (query_keep_damage()<=10) return damage_msg+"somewhat damaged";
  if (query_keep_damage()<=12) return damage_msg+"damaged";
  if (query_keep_damage()<=14) return damage_msg+"heavily damaged";
  if (query_keep_damage()<=16) return damage_msg+"crumbling";
  if (query_keep_damage()<=18) return damage_msg+"collapsing";
  if (query_keep_damage()<=20) return damage_msg+"utterly destroyed";
}

destruct_keep_room(arg) {
  object player_obj, next_obj;
  player_obj = first_inventory(arg);
  while(player_obj) {
    next_obj=next_inventory(player_obj);
    if (player_obj->is_player()) {
      move_object(player_obj, environment(query_keep_obj()));
      tell_object(player_obj,
                  "\nThe keep crumbles about your ears.  "+
                  "Fortunately, you weren't hurt.\n");
      command("look", player_obj);
    }
    player_obj=next_obj;
  }
  destruct(arg);
}

add_keep_damage(arg) {
  object keep_item;
  string str, msg;
  keep_damage=keep_damage+arg;
  if (keep_damage < 0) keep_damage=0;
  keep_damage=keep_damage + 1;
  if (keep_damage >= MAX_DAMAGE) {
    /* clear and destruct the throne room */
    keep_item=first_inventory(THRONE_ROOM);
    while (keep_item) {
      if (living(keep_item) && !keep_item->id("soldier")) {
        str=keep_item->query_name();
        msg=capitalize(str)+" scrambles out a window to safety!\n";
      }
      else {
        str=keep_item->short();
        msg=capitalize(str)+" is blown clear of the keep.\n";
      }
      tell_room(query_keep_room(), msg);
      move_object(keep_item, query_keep_room());
      keep_item=next_inventory(keep_item);
    }
    destruct_keep_room(THRONE_ROOM);
    /* clear and destruct the parapit */
    keep_item=first_inventory(PARAPIT);
    while (keep_item) {
      if (living(keep_item) && !keep_item->id("soldier")) {
        str=keep_item->query_name();
        msg=capitalize(str)+" scrambles out a window to safety!\n";
      }
      else {
        str=keep_item->short();
        msg=capitalize(str)+" is blown clear of the keep.\n";
      }
      tell_room(query_keep_room(), msg);
      move_object(keep_item, query_keep_room());
      keep_item=next_inventory(keep_item);
    }
    destruct_keep_room(PARAPIT);
    /* clear and destruct the repair room */
    keep_item=first_inventory(REPAIR_ROOM);
    while (keep_item) {
      if (living(keep_item) && !keep_item->id("soldier")) {
        str=keep_item->query_name();
        msg=capitalize(str)+" scrambles out a window to safety!\n";
      }
      else {
        str=keep_item->short();
        msg=capitalize(str)+" is blown clear of the keep.\n";
      }
      tell_room(query_keep_room(), msg);
      move_object(keep_item, query_keep_room());
      keep_item=next_inventory(keep_item);
    }
    destruct_keep_room(REPAIR_ROOM);
    tell_room(query_keep_room(),
            "\nThe last cannonball strike seems to have been too much for\n"+
            "the stone of even this sturdy keep to take!  It starts to glow\n"+
            "cherry red, then almost a blue-white.\n\n");
    move_object(clone_object("/players/nooneelse/closed/keep/keep_wreckage"),
                query_keep_room());
    /* clear entry in sales office */
    "/players/nooneelse/closed/keep/keep_sales_office"->
      destroy_keep(query_keep_owner());
    /* destruct the deed */
    destruct(this_object());
  }
  else {
    "/players/nooneelse/closed/keep/keep_sales_office"->
      set_keep(query_keep_owner()+" damage "+keep_damage);
    keep_soldiers=keep_soldiers - 1;
    if (keep_soldiers >= MAX_SOLDIERS) keep_soldiers=MAX_SOLDIERS;
    if (keep_soldiers <= 0) keep_soldiers=0;
    "/players/nooneelse/closed/keep/keep_sales_office"->
      set_keep(query_keep_owner()+" soldiers "+keep_soldiers);
  }
}

dump_keep(str) {
  if (this_player()->query_level() < 32) return 0;
  if (!str || str!="keep") return 0;
  write("keep_soldiers="+keep_soldiers+"\n"+
        "keep_soldiers_defending="+keep_soldiers_defending+"\n"+
        "keep_damage="+keep_damage+"\n"+
        "gates_are_open="+gates_are_open+"\n"+
        "owner_name="+owner_name+"\n"+
        "owner_id="+owner_id+"\n");
  write("THRONE_ROOM=");write(query_THRONE_ROOM());write("\n");
  write("PARAPIT=");write(query_PARAPIT());write("\n");
  write("REPAIR_ROOM=");write(query_REPAIR_ROOM());write("\n");
  write("keep_obj=");write(keep_obj);write("\n");
  write("keep_room_obj=");write(keep_room_obj);write("\n");
  return 1;
}
