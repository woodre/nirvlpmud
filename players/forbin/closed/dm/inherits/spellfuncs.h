varargs object spell_ok(int attack, int no_target, string target)
{
  object gob, enemy, friend;
  int    nok;
  int    *res;
  int    x, y;
  
  gob = present("cleric_object", this_player());
  
  if((int)this_player()->query_ghost())
  {
    write("You are dead.\n");
    return 0;
  }
  
  if(!gob->query_focus())
  {
    write("You are not focused.\n");
    return 0;
  }
   
  if(!(res=(int*)gob->query_spell(spell_name)))
  {
    write("You have not yet learned the spell \""+spell_name+"\".\n");
    return 0;
  }
  
  if((int)this_player()->query_total_level() < level_req)
  {
    write("You must achieve level "+level_req+" before you may\n"+
          "cast the spell \""+spell_name+"\".\n");
    return 0;
  }
  
  y = sizeof(stat_reqs);
  for(x = 0; x < y; x +=2)
  {
    if((int)this_player()->query_attrib(stat_reqs[x]) < stat_reqs[x+1])
    {
      write("\
You need a "+elongate_attrib(stat_reqs[x])
+" attribute of "+stat_reqs[x+1]+".\n");
      nok=1;
    }
  }
  if(nok)
    return 0;
  
  if((int)gob->query_donation() < donation_req)
  {
    write("You need "+donation_req+" coins in donation to cast this spell.\n");
    return 0;
  }
  
  if((int)this_player()->query_sp() < sp_cost)
  {
    write("You need "+sp_cost+" SP to cast this spell.\n");
    return 0;
  }
  
  if((int)this_player()->query_hp() < hp_cost)
  {
    write("You need "+hp_cost+" HP to cast this spell.\n");
    return 0;
  }
  
  if((int)this_player()->query_alignment() < 0)
  {
    write("The "+HIK+"darkness"+NORM
    +" of your soul prevents you from casting any spells.\n");
    return 0;
  }
  
  if(!no_target)
  {
    if(attack)
    {
      if(!target)
      {
        if(!(enemy=(object)this_player()->query_attack()))
        {
          write("You must specify a target!\n");
          return 0;
        }
      }
      else if(!(enemy=present(target,environment(this_player()))))
      {
        write("You don't see "+target+" here.\n");
        return 0;
      }
      if((int)enemy->query_alignment() > 0)
      {
        write((string)enemy->query_name()+"'s soul is too "+HIW+
        "pure"+NORM+" to attempt harming it with godmagic.\n");
        return 0;
      }
    }
    else
    {
      if(!target)
        friend = this_player();
      else if(!(friend=present(target,environment(this_player()))))
      {
        write("You don't see "+target+" here.\n");
        return 0;
      }
      else if((int)friend->query_alignment() < 0)
      {
        write((string)friend->query_name()+"'s soul is too "+HIK+
        "corrupted"+NORM+" to attempt defending it with godmagic.\n");
        return 0;
      }
    }
  }
  
  this_player()->add_sp(-sp_cost);
  this_player()->add_hp(-hp_cost);
  gob->add_donation(-donation_req);
  gob->clear_focus();
  this_player()->add_alignment(1 + (int)this_player()->query_total_level() / 10);
  
  if(res[1] < 100)
  {
    if(res[0] == res[1]*2)
    {
      gob->set_spell_casts(spell_name,0);
      gob->add_spell_level(spell_name,1);
      write(HIW+"Your spell proficiency in "+spell_name+" increases!\n"+NORM);
      say((string)this_player()->query_name()+" appears more learned.\n");
      res[1] += 1;
    }
    else
      gob->add_spell_casts(spell_name,1);
    
    if(res[1] < random(100))
    {
      write(RED+"Your spell fails!\n"+NORM);
      say((string)this_player()->query_name()+"'s spell fizzles.\n");
      return 0;
    }
  }

  write("You cast the spell of "+HIW+spell_name+NORM+"...\n");
  clerical_say((string)this_player()->query_name()+
    " casts the spell of "+HIW+spell_name+NORM+"...\n");
  other_say((string)this_player()->query_name()+
    " grumbles a few strange, gutteral words.\n");
    
  if(!no_target)
  {
    object obj;
    obj = (friend?friend:enemy);
    if(obj != this_player())
      write(replace_targ(my_msg,friend?friend:enemy));
    say(replace_targ(room_msg,friend?friend:enemy), friend?friend:enemy);
    tell_object(friend?friend:enemy, replace_targ(target_msg,friend?friend:enemy));
  }
  else
  {
    write(my_msg);
    say(room_msg);
  }
  
  if(!no_target)
    return (friend?friend:enemy);
  else
    return environment(this_player());
}