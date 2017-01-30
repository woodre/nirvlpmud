/*
 * Appraise
 * Give an approximation of value
 */

status main(string str) {
  object obj;

  if (this_player()->query_guild_rank() < 4) {
    write("You are not high enough level for that.\n");
    return 1;
  }
  if (this_player()->query_sp() < 10) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  if (!str) {
    write("What do you want to appraise?\n");
    return 1;
  }
  obj = present(str, this_player());
  if (!obj) {
    write("You do not have one of those.\n");
    return 1;
  }
  write("The Guild Appraiser says:  Based on looks alone....\n");
  if (obj->query_type()) {
  switch(obj->query_ac()) {
  case 1: write("This would make some ok armor.\n"); break;
  case 2: write("This would make some decent armor.\n"); break;
  case 3: write("This would make some pretty good armor.\n"); break;
  case 4: write("This would make some very good armor.\n"); break;
  case 5: write("This would make some awesome armor.\n"); break;
  default: write("This would make some terrible armor.\n"); break;
  }
  return 1;
  }
  if (obj->weapon_class()) {
  switch(obj->weapon_class()) {
  case 18..19: write("This would be an awesome choice for a weapon.\n"); break;
  case 15..17: write("This would be a very good choice for a weapon.\n"); break;
  case 12..14: write("This would be a pretty good choice for a weapon.\n");
    break;
  case 9..11: write("This would be a decent choice for a weapon.\n"); break;
  case 6..8: write("This would be an okay choice for a weapon.\n"); break;
  case 3..5: write("This would be a very poor choice for a weapon.\n"); break;
  case 0..2: write("This weapon would be worse than your hands.\n"); break;
  default: write("This is a weapon of choice for the gods!\n"); break;
    break;
  }
  return 1;
  }
  this_player()->add_spell_point(-5);
  write("This doesn't appear to be a weapon or any type of armor.\n");
  return 1;
}
