#include "/players/eurale/defs.h"
inherit "room/room";
object ob;
string item;

reset(arg) {
  if(arg) return;
if(!present("trashcan")) {
  move_object(clone_object("/players/eurale/VAMPIRES/OBJ/trashcan.c"),
      this_object()); }
set_light(0);

short_desc = BOLD+"Vampire Shop"+NORM;
long_desc =
  "This is the "+BOLD+"Vampire Shop"+NORM+"."+
    "  You may purchase or sell items here\n"+
  "at a reasonable price.  The commands are:\n"+
  "  sell <item>, buy <item>, sell all, list, value <item>\n\n";

dest_dir = ({
  "players/eurale/VAMPIRES/RMS/equip.c","north",
  "/players/eurale/VAMPIRES/RMS/souvenir_shop.c","east",
  "/players/eurale/VAMPIRES/RMS/wolf_path.c","west",
});
}

realm() { return "NT"; }
query_drop_castle() { return 1; }

init() {
  ::init();
  add_action("Sell","sell");
  add_action("value","value");
  add_action("buy","buy");
  add_action("list","list");
}

Sell(item) {
if(!item) { write("Sell what?\n"); return 1; }

if (item == "all") {
object next;
ob = first_inventory(this_player());
	while(ob) {
	    next = next_inventory(ob);
	    if (!ob->drop() && ob->query_value()) {
		do_sell(ob);
	    }
	    ob = next;
	}
	write("Ok.\n");
	return 1;
    }

ob = present(item, this_player());

if(!ob) ob = present(item,TP);
if(!ob) { write("You have no "+item+" to sell.\n"); return 1; }

    do_sell(ob);
    return 1;
}

do_sell(ob) {
int value,value2,do_destroy;
value = ob->query_value();

if(!value) { write(ob->short()+" has no value.\n"); return 1; }

if (environment(ob) == this_player()) {
  if(ob->drop()) {
	  write("I can't take it from you!\n");
    return 1; }
}

if (value > 1000) {
  write("The shop tucks this valuable item away in the safe.\n");
  value2 = 1000 + random(200);
  if(value > value2) { value = value2; }
  }
write("You sell a "+ob->short()+" for "+value+" coins.\n");
say(capitalize(TPRN)+" sells a "+ob->short()+".\n");
TP->add_money(value);

destruct(ob);
return 1;
}

value(item) {
int value;
string name_of_item;

if(!item) { write("Value what?\n"); return 1; }
name_of_item = present(item);
if(!name_of_item) name_of_item = find_item_in_player(item);

if (!name_of_item) {
  if (call_other("room/store", "value",item))
  write("There is no '"+item+"' here or in the store.\n");
  return 1; }

value = call_other(name_of_item, "query_value", 0);

if(!value) { write(capitalize(item)+" has no value.\n"); return 1; }

write("You would get "+value+" coins for that item.\n");
    return 1;
}

buy(item) {
if(!item) { write("Buy what?\n"); return 1; }
  call_other("room/store", "buy", item);
  return 1; }


list(obj) {
  call_other("room/store", "inventory", obj);
  return 1; }

find_item_in_player(i) {
object ob;

    ob = first_inventory(this_player());
    while(ob) {
        if (call_other(ob, "id", i))
	    return ob;
	ob = next_inventory(ob);
    }
    return 0;
}
