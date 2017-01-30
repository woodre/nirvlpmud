deweave(string str){
  object item;
  if(User->query_ghost()) return 0;
  if(!present("circle_object",this_player()))
  {
    write("Missing guild object!\n");
    return 1;
  }
  if(!present("circle_object",this_player())->query_skills("weave")) return 0;
  if(present("circle_object",this_player())->light_check()) return 1;
  if(!str) return 0;
  item = present(str, User);
  if(!item) return 0;
  if(!item->query_fallen_shadow())
  {
    TOU item->short()+" is not a weaved weapon.\n");
    return 1;
  }
  if((object)User->query_weapon() == item)
  {
    TOU "Please unwield the weapon first.\n");
    return 1;
  }
  if(environment(User)->realm() == "NM")
  {
    TOU"Your power is being drained here.\n");
    return 1;
  }
  if(present("circle_object",this_player())->casting_check()) return 1;

  TOU "You whisper a gentle phrase over "+item->QN+".\n"+
  "The shadow weave slowly fades from the weapon.\n");

  TRU User->query_name()+" whispers a gentle phrase over "+item->QN+
    ".\n", ({User}));

  item->remove_fallen_shadow();

  User->add_spell_point(-50);
  User->add_hit_point(-5);
  present("circle_object",this_player())->add_endurance(-3);
  present("circle_object",this_player())->energy_check();
  return 1;
}
