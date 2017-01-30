/* 08/19/06 Earwax: Daemonized this: note, it was a static fun in player.c
 * before.  I see no need for it to be static.
 */

int cmd_invisible(string str) 
{
  object ob;
  
  if ((int)this_object()->test_dark())
  {
    write("You can't cast this spell in the dark.\n");
  return 1;
}

  this_player()->spell_block();

  if((int)this_player()->query_spell_block())
  { 
    write("You are unable to do that.\n"); 
    return 1;
  }
  
  if ((int)this_player()->query_level() < 15)
  return 0;
  
  if ((int)this_player()->query_sp() < 40 || (int)this_player()->checkNM() != 0)
  {
    write("You do not have enough spell points.\n"); 
    return 1;
  }
  
  ob = (str ? present(lower_case(str), environment(this_player())) : this_player());
  
  if (!ob || !living(ob)) 
  {
  write("At whom?\n");
  return 1;
  }
 
  if (ob == this_player()) 
  {
    write("You see your hands disappear!\n");
    say((string)this_player()->query_name());
    say(" fades into nothing.\n");
    ob->set_invs_sp();
    ob->add_spell_point(-40);
  return 1;
  }
  
  say((string)this_player()->query_name());
  say(" waves their hands and casts a spell.\nYou see ");
  say((string)ob->query_name());
  say(" disappear!!!!\n");
  write("You make ");
  write((string)ob->query_name());
  write(" disappear.\n");
  ob->set_invs_sp();
  this_player()->add_spell_point(-40);
  return 1;
}
