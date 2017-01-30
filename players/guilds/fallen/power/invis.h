
new_invis(str){
  object who;
  if(User->query_ghost()) return 0;
  if(User->query_level() < 15) return 0;
  if(GOB->light_check()) return 1;
  if(User->query_no_spell()) return 0;
  if(environment(User)->realm() == "NM")
  {
    TOU"Your power is being drained here.\n");
    return 1;
  }
  if(str)
  {
    who = present(str, environment(User));
    if(!who)
    {
      TOU "You don't see "+str+" here.\n");
      return 1;
    }
    if(!who->is_player())
    {
      TOU "You can not hide "+str+" in a shadow.\n");
      return 1;
    }
    if(!GOB->spell_failure(1)) return 1;
    if(GOB->casting_check()) return 1;
    TOU "You whisper softly as you pull the shadows near you...\n"+
      "As you wave your hands, a soft blanket of shadows appears...\n"+
      "The shadows settle upon "+str+", hiding "+who->query_objective()+
      " from sight.\n");
    TRU User->query_name()+" whispers softly summoning the shadows...\n"+
      who->query_name()+" is wrapped in a soft blanket of shadows.\n",
      ({ User }));
    who->set_invs_sp();
  }
  else
  {
    if(!GOB->spell_failure(1)) return 1;
    TOU "You whisper softly as you pull the shadows near you...\n"+
      "As you wave your hands, a soft blanket of shadows appears...\n"+
      "The shadows settle upon you, hiding you from sight.\n");
    TRU User->query_name()+" whispers softly summoning the shadows...\n"+
      User->query_name()+" is wrapped in a soft blanket of shadows.\n",
      ({ User }));
    User->set_invs_sp();
  }

  User->add_spell_point(-40);
  GOB->add_endurance(-2);
  GOB->energy_check();
  return 1;
}
