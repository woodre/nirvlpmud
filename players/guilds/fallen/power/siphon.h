

/* 
   THIS SPELL IS UNQUESTIONABLY OVERPOWERED.  That being said, nerfing it
   much will make it worthless.  It limits a Fallen from casting other
   spells while it is active.  In its current form it recovers endurance
   and either sp or hp depending on WHICH YOU NEED MOST.  If it only
   regenerated one or the other, or less, then casting the spell would
   become a much greater liability as it can not be canceled without
   fleeing.  This spell requires maxed guild experience, and as such
   only about 12 players on the mud can use it even though the guild has
   been open for over 5 years.  This is not an easy guild to max and it
   makes sense that the final reward would be one of true power, not
   another spell that will probably just get you killed (see almost all
   the other spells I've written for this guild).

related obj:  ~/realm/OBJ/siphon_stone.c
*/
siphon(str)
{
  object target;
  int c, d, e, f;
  if(!GOB->query_skills("siphon")) return 0;
  if(User->query_ghost()) return 0;
  if(GOB->light_check()) return 1;
  if(!str && User->query_attack())
    target = User->query_attack();
  else if(str)
    target = present(str, environment(User));
  else if(!str && !User->query_attack())
    return 0;
  if(!target)
  {
    TOU"You don't see "+str+" here.\n");
    return 1;
  }
  if(!living(target)){
    TOU"You cannot attack "+str+"!\n");
    return 1;
  }
  else if(!present(target, environment(User)))
  {
    TOU"You don't see "+str+" here.\n");
    return 1;
  }
  if(target->is_player() && !target->query_pl_k() &&
    !target->check_fight_area())
  {
    TOU"You cannot attack "+str+"!\n");
    return 1;
  }
  if(environment(User)->realm() == "NM")
  {
    TOU"Your power is being drained here.\n");
    return 1;
  }
  if(!present("zeus_siphon_stone", User))
  {
    TOU"You lack the spell component to cast this spell.\n");
    return 1;
  }
  if(!GOB->spell_failure(3)) return 1;
/*  if(PO->casting_check()) return 1; */

  c = (int)User->query_hp();
  d = (int)User->query_mhp();
  e = (int)User->query_spell_point();
  f = (int)User->query_msp();

  TOU BOLD+BLK+
    "Shadowy tendrils siphon energy from "+target->QN+" to you.\n"+NORM);
  TRU BOLD+BLK+
    "Shadowy tendrils siphon energy from "+target->QN+".\n"+NORM,
    ({User}));

  if(GOB->query_casting() == 0)
  {
    target->hit_player((15 +
      present("zeus_siphon_stone", User)->qzj()), "other|shadow");
    if(d && f &&  (((c * 100) / d) > ((e * 100) / f)))
      User->add_spell_point(16 + 
        (present("zeus_siphon_stone", User)->qzj() / 2));
    else
      User->add_hit_point(16 + 
        (present("zeus_siphon_stone", User)->qzj() / 2));
      GOB->add_endurance(7 +
          (present("zeus_siphon_stone", User)->qzj() / 3));
    present("zeus_siphon_stone", User)->feed_me_zeus_juice();
  }

  User->attack_object(target);
  GOB->set_casting(6);
  GOB->set_siphon();
  GOB->energy_check();
  return 1;
}

