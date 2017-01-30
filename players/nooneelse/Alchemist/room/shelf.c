/*
  alchemist_shelf.c
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

inherit "room/room";
inherit "/players/nooneelse/Alchemist/room/rooms.c";

#define PURCHASE_COST 30000
#define STORAGE_COST 500
#define SHELF "players/nooneelse/Alchemist/room/shelf/"

string shelf_item1, shelf_item2, shelf_item3, shelf_item4;
string item, shelf_filename, item_filename, tmp;
object item_obj;

init() {
  add_action("buy"        "buy");
  add_action("place",     "place");
  add_action("place",     "put");
  add_action("retrieve",  "retrieve");
  add_action("retrieve",  "get");
  add_action("retrieve",  "take");
  add_action("examine",   "examine");
  add_action("examine",   "list");
  add_action("examine",   "look");
  add_action("northeast", "northeast");
  check_membership(this_player());
}

id(str) { return str=="shelf"; }

short() { return "A shelf"; }

long() {
  write("A sturdy shelf built into the wall.\n\n"+
        "You can:\n"+
        "  place <item> on shelf\n"+
        "  retrieve <item> from shelf\n"+
        "  examine shelf\n");
}

examine(str) {
  if (!str || str!="at shelf" && str!="shelf") return;
  if (!present("Alchemist Robes", this_player())) {
    write("These shelves are for Alchemist use only!\n");
    return 1;
  }
  say(this_player()->query_real_name()+" peers at the shelves.\n");
  shelf_filename = SHELF+this_player()->query_real_name();
  if (file_size(shelf_filename)<0) {
    write("You don't have a shelf!\n");
    return 1;
  }
  shelf_item1 = read_file(shelf_filename, 1);
  shelf_item2 = read_file(shelf_filename, 2);
  shelf_item3 = read_file(shelf_filename, 3);
  shelf_item4 = read_file(shelf_filename, 4);
  if(shelf_item1=="@" && shelf_item2=="@" && shelf_item3=="@" && shelf_item4=="@") {
    write("You don't have any items stored.\n");
    return 1;
  }
  write("Item(s) stored on your shelf:\n");
  if(shelf_item1!="@") {
    item_obj = clone_object(shelf_item1);
    write("   "+item_obj->short()+"\n");
  }
  if(shelf_item2!="@") {
    item_obj = clone_object(shelf_item2);
    write("   "+item_obj->short()+"\n");
  }
  if(shelf_item3!="@") {
    item_obj = clone_object(shelf_item3);
    write("   "+item_obj->short()+"\n");
  }
  if(shelf_item4!="@") {
    item_obj = clone_object(shelf_item4);
    write("   "+item_obj->short()+"\n");
  }
  return 1;
}

write_shelf_file() (
  write_file(shelf_filename, shelf_item1+"\n");
  write_file(shelf_filename, shelf_item2+"\n");
  write_file(shelf_filename, shelf_item3+"\n");
  write_file(shelf_filename, shelf_item4+"\n");
}

buy(str) {
  if (!str || str!="shelf") return;
  if (!present("Alchemist Robes", this_player())) {
    write("These shelves are for Alchemist use only!\n");
    return 1;
  }
  if (this_player()->query_money() < PURCHASE_COST) {
    write("It costs "+PURCHASE_COST+" coins to purchase shelf space.\n");
    return 1;
  }
  shelf_filename = SHELF+this_player()->query_real_name();
  if (file_size(shelf_filename)<0) {
    write("You have already purchased shelf space!\n");
    return 1;
  }
/*
    write_file(SHELF+"LOG",
           this_player()->query_name()+" purchased a shelf "+ctime(time())+".\n");
*/
  this_player()->add_money(-PURCHASE_COST);
  shelf_item1 = "@";
  shelf_item2 = "@";
  shelf_item3 = "@";
  shelf_item4 = "@";
  write_shelf_file();
  write("You purchased shelf space.\n");
  say(this_player()->query_name()+" purchases shelf space.\n");
  return 1;
}

place(str) {
  if (!str) return;
  if (sscanf(str, "%s on shelf", item) != 1) {
    write("Place what where?\n");
    return 1;
  }
  if (!present("Alchemist Robes", this_player())) {
    write("These shelves are for Alchemist use only!\n");
    return 1;
  }
  if (item=="all") {
    write("No! You must place each item on individually.\n");
    return 1;
  }
  if (item=="shelf") {
    write("Huh?  You want to place the shelf on the shelf?\n");
    return 1;
  }
  item = lower_case(item);
  item_obj = present(item, this_player());
  if (!item_obj) {
    write("You have no "+item+"!\n");
    return 1;
  }
  sscanf(file_name(item_obj), "%s#%s", item_filename, tmp);
  if (item_filename=="obj/weapon" ||
      item_filename=="obj/armor" || item_filename=="obj/armour" ||
      item_filename=="obj/container" || item_filename=="obj/treasure" ||
      item_obj->drop() || item_obj->prevent_insert() ||
      (item_obj->query_save_flag() && item_obj->query_save_flag() != 3)) {
    write("That cannot be stored on these shelves.\n");
    return 1;
  }
  if (this_player()->query_money() < STORAGE_COST) {
    write("It costs "+STORAGE_COST+" coins to deposit items.\n");
    return 1;
  }
  shelf_filename = SHELF+this_player()->query_real_name();
  if (file_size(shelf_filename)<0) {
    write("You don't have a shelf!\n");
    return 1;
  }
  shelf_item1 = read_file(shelf_filename, 1);
  shelf_item2 = read_file(shelf_filename, 2);
  shelf_item3 = read_file(shelf_filename, 3);
  shelf_item4 = read_file(shelf_filename, 4);
  if(shelf_item1!="@" && shelf_item2!="@" && shelf_item3!="@" && shelf_item4!="@") {
    write("You don't have any more space to store items.\n");
    return 1;
  }
  if(shelf_item1=="@") {
    shelf_item1 = item_filename;
    return 1;
  } else
  if(shelf_item2=="@") {
    shelf_item2 = item_filename;
    return 1;
  } else
  if(shelf_item3=="@") {
    shelf_item3 = item_filename;
    return 1;
  } else
  if(shelf_item4=="@") {
    shelf_item4 = item_filename;
    return 1;
  }
  rm(shelf_filename);
  write_shelf_file();
  this_player()->add_weight(- item_obj->query_weight());
  move_object(item_obj, "room/void");
  destruct(item_obj);
  this_player()->add_money(-STORAGE_COST);
  write("You place "+item+" on the shelf.\n");
  say(this_player()->query_name()+" places a "+item+" on the shelf.\n");
/*
    write_file(SHELF+"LOG",
           this_player()->query_real_name()+" stored "+item_filename+" on "+ctime(time())+".\n");
*/
  return 1;
}

retrieve(str) {
  if (!str) return;
  if (sscanf(str, "%s from shelf", item) != 1) {
    write("Retreive what?\n");
    return 1;
  }
  if (!present("Alchemist Robes", this_player())) {
    write("These shelves are for Alchemist use only!\n");
    return 1;
  }
  if (item=="all") {
    write("You must retrieve each item individually.\n");
    return 1;
  }
  if (item=="shelf") {
    write("Huh?  You want to retrieve the shelf from the shelf?\n");
    return 1;
  }
  item = lower_case(item);
  shelf_filename = SHELF+this_player()->query_real_name();
  if (file_size(shelf_filename)<0) {
    write("You don't have a shelf!\n");
    return 1;
  }
  shelf_item1 = read_file(shelf_filename, 1);
  shelf_item2 = read_file(shelf_filename, 2);
  shelf_item3 = read_file(shelf_filename, 3);
  shelf_item4 = read_file(shelf_filename, 4);
  if(shelf_item1!="@" && shelf_item2!="@" && shelf_item3!="@" && shelf_item4!="@") {
    write("You don't have any items stored.\n");
    return 1;
  }
  if(shelf_item1!="@") {
    item_obj = clone_object(shelf_item1);
    if (item_obj) {
      if (item_obj->short()==item || item_obj->id(item)){
        move_object(item_obj,this_player());
        write("You retrieve "+item+" from the shelf.\n");
        say(this_player()->query_name()+" retrieves a "+item+" from the shelf.\n");
/*
write_file(SHELF+"LOG",
           this_player()->query_real_name()+" retrieved "+item+" # "+filename+
           " on "+ctime(time())+".\n");
*/
        shelf_item1 = "@";
        rm(shelf_filename);
        write_shelf_file();
        return 1;
      } else {
        move_object(item_obj, "room/void");
        destruct(item_obj);
      }
    }
    return 1;
  }
  if(shelf_item2!="@") {
    item_obj = clone_object(shelf_item2);
    if (item_obj) {
      if (item_obj->short()==item || item_obj->id(item)){
        move_object(item_obj,this_player());
        write("You retrieve "+item+" from the shelf.\n");
        say(this_player()->query_name()+" retrieves a "+item+" from the shelf.\n");
/*
write_file(SHELF+"LOG",
           this_player()->query_real_name()+" retrieved "+item+" # "+filename+
           " on "+ctime(time())+".\n");
*/
        shelf_item2 = "@";
        rm(shelf_filename);
        write_shelf_file();
        return 1;
      } else {
        move_object(item_obj, "room/void");
        destruct(item_obj);
      }
    }
    return 1;
  }
  if(shelf_item3!="@") {
    item_obj = clone_object(shelf_item3);
    if (item_obj) {
      if (item_obj->short()==item || item_obj->id(item)){
        move_object(item_obj,this_player());
        write("You retrieve "+item+" from the shelf.\n");
        say(this_player()->query_name()+" retrieves a "+item+" from the shelf.\n");
/*
write_file(SHELF+"LOG",
           this_player()->query_real_name()+" retrieved "+item+" # "+filename+
           " on "+ctime(time())+".\n");
*/
        shelf_item3 = "@";
        rm(shelf_filename);
        write_shelf_file();
        return 1;
      } else {
        move_object(item_obj, "room/void");
        destruct(item_obj);
      }
    }
    return 1;
  }
  if(shelf_item4!="@") {
    item_obj = clone_object(shelf_item4);
    if (item_obj) {
      if (item_obj->short()==item || item_obj->id(item)){
        move_object(item_obj,this_player());
        write("You retrieve "+item+" from the shelf.\n");
        say(this_player()->query_name()+" retrieves a "+item+" from the shelf.\n");
/*
write_file(SHELF+"LOG",
           this_player()->query_real_name()+" retrieved "+item+" # "+filename+
           " on "+ctime(time())+".\n");
*/
        shelf_item4 = "@";
        rm(shelf_filename);
        write_shelf_file();
        return 1;
      } else {
        move_object(item_obj, "room/void");
        destruct(item_obj);
      }
    }
    return 1;
  }
  write("Huh? I seem to be screwed up. Notify the wizard.\n");
  return 1;
}

reset(arg) {
  if (arg) return;

  dest_dir=
    ({
      ALCHEMIST_CENTRAL, "northeast",
    });
}
