/*
  stone_of_alchemy.c
*/

inherit "obj/treasure";

string str;

init() {
  add_action("touch_item", "touch");
}

touch_item(str) {
  int chance_to_break, item_value;
  string item_name;
  object item_obj, coins;
  if (!str) return;
  item_name=0;
  sscanf(str, "%s with stone", item_name);
  if (!item_name) {
    write("Touch what with the stone?\n");
    return 1;
  }
  item_obj=present(item_name, this_player());
  if (!item_obj) return;
  chance_to_break=random(100);
  if (chance_to_break < 5) {
    write("Something goes wrong with the stone's magic and it shatters!\n");
    this_player()->add_weight(-1);
    destruct(this_object());
    return 1;
  }
  item_value=item_obj->query_value();
  if (item_value <= 0) {
    write("Since that item has no value, the stone does nothing to it.\n");
    return 1;
  }
  if (item_value > 1000) item_value=1000+random(500);
  coins=clone_object("obj/money");
  coins->set_money(item_value);
  move_object(coins, environment(this_player()));
  write("There is a bright flash as the stone touches the "+item_name+"\n"+
        "it is changed into "+item_value+
        " gold coins which fall to the ground.\n");
  say("There is a bright flash as "+this_player()->query_name()+
      " touches "+item_name+" to a strange stone.\n", this_player());
  this_player()->add_weight(- item_obj->query_weight());
  move_object(item_obj, "room/void");
  destruct(item_obj);
  return 1;
}

reset(arg) {
  short_desc="An alchemist stone";
  long_desc=
    short()+".\n"+
    "There are rumors that an item such as this can change items into gold.\n"+
    "You might try 'touch <item> with stone.\n";
  set_value(50);
  set_weight(1);
}


query_save_flag() { return 1; }

id(str) { return str=="stone" ||
                 str=="alchemist stone" ||
                 str=="alchemists stone" ||
                 str=="stone_of_alchemy"; }
