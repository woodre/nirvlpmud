/* *****************************************************************************
 * id.c
 *
 * - Coded by Earwax initially 1/14/04
 * 
 * Returns fairly comprehensive item information.
 *
 * *****************************************************************************
*/
#include "../defs.h"

#define LONGLINE HIK+"===============================================================\n"+NORM+NORM

/*
*/
string req_task() { return TASK_ID; }
int sp_cost() { return 50; }
int arg() { return 3; }

void tellob(string msg) { tell_object(this_player(), msg); }

int main(string arg) {
  object ob, item;
  string ncreator, name, info;

  item = present(arg,this_player());
  if (!item)
    item = present(arg,environment(this_player()));

  if (!item) {
    tell_object(this_player(), "Item must be in your inventory.\n");
    return 1;
  }

  tellob(LONGLINE);
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
      tellob(LONGLINE);
      return 1;
    }

    write("Type:       "+item->query_type()+"\n");
    write("Damage:     "+(int)item->weapon_class()+"\n");

    if (function_exists("weapon_hit",item))
      write("Special:    This item is special in some way.\n");

  }

  /* Identify Armor */
  if (item->is_armor()) {

    if (item->query_broke()) {
      write("This armor is broken, and useless to identify.\n");
      tellob(LONGLINE);
      return 1;
    }

    write("Type:       "+item->query_type()+"\n");
    write("AC:         "+(int)item->armor_class()+"\n");

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

  tellob(LONGLINE);
  return 1;
}
