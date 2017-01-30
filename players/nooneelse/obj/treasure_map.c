/*
  treasure_map.c
*/

string short_desc, long_desc, destination, treasure_short, treasure_long;
string treasure_name, treasure_alias_name, treasure_read_msg;
int treasure_value, treasure_weight;
object treasure_obj;

init() {
    add_action("read", "read");
    add_action("dig",  "dig");
}

read(str) {
  if (!id(str)) return;
  write(long_desc);
  return 1;
}

dig(str) {
  if (str) return;
  if (environment(this_player()) != find_object(destination)) {
    write("You dig for a while, but find nothing.\n");
    return 1;
  }
  write("You found the treasure!  You see a huge blue star sapphire!\n"+
        "In your excitement, you crumble the map & find that it was\n"+
        "very brittle.  It crumbles to dust.\n");
  treasure_obj = clone_object("obj/treasure");
  treasure_obj->set_id(treasure_name);
  treasure_obj->set_short(treasure_short);
  treasure_obj->set_value(treasure_value);
  if (treasure_alias_name) treasure_obj->set_alias(treasure_alias_name);
  if (treasure_long) treasure_obj->set_long(treasure_long);
  if (treasure_weight) treasure_obj->set_weight(treasure_weight);
  if (treasure_read_msg) treasure_obj->set_read(treasure_read_msg);
  move_object(treasure_obj, find_object(destination));
  destruct(this_object());
  return 1;
}

long() { write(long_desc); }

short() { return short_desc;}

set_short(str) { short_desc = str; long_desc = short_desc + "\n";}
set_long(str) { long_desc = str; }
set_destination(str) { destination = str; }
set_treasure_name(str) { treasure_name = str; }
set_treasure_short(str) { treasure_short = str; }
set_treasure_value(n) { treasure_value = n; }
set_treasure_long(str) { treasure_long = str; }
set_treasure_weight(n) { treasure_weight = n; }
set_treasure_alias_name(str) { treasure_alias_name = str; }
set_treasure_read_msg(str) { treasure_read_msg = str; }

get() { return 1;}

id(str) { return str=="map" || str=="treasure map"; }
