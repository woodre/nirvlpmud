#include "../defs.h"

int main(string arg) {
  object ob, item;
  string ncreator, name, info;

  ob = present(GUILDOB,this_player());

  if (!arg) {
    ob->gmsg("Hey, jackass, what is it you want to id?\n");
    return 1;
  }

  item = present(arg,this_player());
  if (!item)
    item = present(arg,environment(this_player()));

  if (!item) {
    ob->gmsg("That item is not in your inventory or in this room.\n");
    return 1;
  }

  ob->gmsg(LONGLINE);
  write("Item:       "+item->short()+"\n");
  write("Name:       "+item->query_name()+"\n");

  ncreator = creator(item);
  if (!ncreator)
    ncreator = "Unknown";

  ncreator = capitalize(ncreator);
  write("Created by: "+ncreator+"\n\n");
  write("Weight:     "+item->query_weight()+"\n");
  write("Value:      "+item->query_value()+"\n");
  write("Saveable:   ");
  if (item->query_save_flag())
    write("NO\n");
  else
    write("YES\n");
  write("\n");

  /* Identify Weapon */
  if (item->is_weapon()) {

    if(item->query_broke()) {
      write("This weapon is broken, and useless to identify.\n");
      ob->gmsg(LONGLINE);
      return 1;
    }

    write("Type:       "+item->query_type()+"\n");
    write("Damage:     "+DAEMON->return_damage_desc(item->weapon_class())+"\n");

    if (function_exists("weapon_hit",item))
      write("Special:    This item is special in some way.\n");

  }

  /* Identify Armor */
  if (item->is_armor()) {

    if (item->query_broke()) {
      write("This armor is broken, and useless to identify.\n");
      ob->gmsg(LONGLINE);
      return 1;
    }

    write("Type:       "+item->query_type()+"\n");
    write("AC:         "+DAEMON->return_ac_desc(item->armor_class())+"\n");

    if (item->query_arm_light())
      write("Light:     This armor is a light source.\n");

    if (function_exists("protect",item))
      write("Protect:    This item has some kind of special protection.\n");

    if (function_exists("do_special",item))
      write("Special:    This item is special in some way.\n");
  }

  info = (string)item->query_info();
  if (info) 
    write("Extra Info: "+info+"\n");

  ob->gmsg(LONGLINE);
  return 1;
}
