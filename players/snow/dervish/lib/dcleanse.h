status dervish_cleanse(string str)
{
  object me, myob;
  object poison, next;
  string a,b;
  me = this_player();
  myob = present(GID, me);
  if(!me || !myob) { write("Something is wrong.\n"); return 1; }
  if(me->query_level() < 19) {
    write("You are not high enough level to use this Master ability yet.\n");
    return 1; }
  if(me->query_ghost()) {
    write("You lack substance.\n"); return 1; }
  if(me->query_attrib("pie") < 30) {
    write("You lack devotion.\n"); return 1; }
  if(myob->query_spell_delay()) {
    write("You cannot cast a spell again so soon.\n"); return 1; }
/*
  if(me->query_attack()) {
    write("You cannot cast a spell in combat.\n"); return 1; }
*/
  write(BOLD+RED+"\tYou scream and spin into a frenzy!\n"+OFF+OFF);
  say(BOLD+RED+me->query_name()+" screams and spins into a frenzy!\n"+OFF+OFF);
 me->drink_alcohol(-(((int)me->query_level()/4)+((int)me->query_extra_level()/5)));
  me->eat_food(-(((int)me->query_level())+((int)me->query_extra_level()/5)));
  me->drink_soft(-(((int)me->query_level())+((int)me->query_extra_level()/5)));
  myob->delete_sand_points(20+random(15));
  if(myob->query_sand_points() < 1)
  {
   me->add_hit_point(-15);
   tell_object(me, "The sand takes your blood as its sacrifice.\n");
   myob->add_sand_points((21-((int)me->query_level()))*5);
   if(me->query_hp() < 1)
    myob->kill_me(me);
    myob->add_spell_delay(10+random(40));
   return 1;
  }
  myob->add_spell_delay(10+random(40));
  return 1;
} 
