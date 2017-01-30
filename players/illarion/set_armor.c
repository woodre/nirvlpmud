inherit "/obj/armor.c";

string set_name;

status set_set_name(string str) {
  set_name=str;
  return 1;
}

string query_set_name() {
  return set_name;
}
/* checks to see if this item is a member of the set with the name
   being passed to it.  primarily a helper function
 */
status is_set_item(string check_set_name) {
  return worn_by != 0 && check_set_name == set_name;
}
/* Get the number of set items currently worn by the wearer of this item
   For set item checks
 */
int get_set_count() {
  object *armors;
  int s,armor_count;
  if(worn_by == 0) return 0;
  armors = m_indices((mixed)worn_by->QueryArmors());
  s=sizeof(armors);
  while(s--)
    if(armors[s]->is_set_item(set_name))
      armor_count++;
  return armor_count;
}
/* Check to see if a wearer is wearing the other item in the set with the
   passed id
   */
status check_set_item_worn(string unique_item_id) {
  object *armors;
  int s,armor_count;
  if(worn_by == 0) return 0;
  armors = m_indices((mixed)worn_by->QueryArmors());
  s=sizeof(armors);
  while(s--)
    if(armors[s]->is_set_item(set_name) && armors[s]->id(unique_item_id))
      return 1;
  return 0;
}