
/*
 * BARDS_CANT 
 * Allows Paladins to speak with Bards Cant
 */

bards_cant(str)  {
  object ob, ob2;
  string name;
  
  if(!previous_object()->query_cant())
    return 0;
  if(!str)  {
    write("What would you like to say?\n");
    return 1;
  }
  ob = first_inventory(environment(this_player()));
  name = this_player()->query_name();
  while(ob)  {
    if(living(ob))  {
      ob2 = present("guild_medal",ob);
      if(present("instrument",ob) || (ob2 && ob2->query_cant()))  
        tell_object(ob, name+" signs '"+str+"' in bardic cant.\n");
       else {
        tell_object(ob, name+
            " makes a series of unusual facial and hand gestures.\n");
       }
    }
    ob = next_inventory(ob);
  }
  write("You sign '"+str+"' in bardic cant.\n");
  return 1;
}
