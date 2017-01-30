guild_death()
{
  int cexp;

  if(USER->QL > 9)
  {
    GOB->set_venomed(0);
    GOB->set_shaped(0);
    GOB->set_shapetype(0);

    if((string)GOB->query_oldalign())
      USER->set_al_title(GOB->query_oldalign());

    if((string)GOB->query_oldtitle())
      USER->set_title(GOB->query_oldtitle());

    if((string)GOB->query_oldpretitle())     
      USER->set_pretitle(GOB->query_oldpretitle());
     
    GOB->set_oldalign(0);
    GOB->set_oldtitle(0);
    GOB->set_oldpretitle(0);
    GOB->set_webf_delay(0);
    GOB->set_hardened(0);
    GOB->set_hyper_mode(0);
    GOB->set_burnoff(0);
    GOB->set_regen(0);
    GOB->set_no_harden(0);
  
    call_other(USER, "stop_wielding", this_object());

    wielded = 0;
    wielded_by = 0;
  }

  cexp = call_other("room/adv_guild", "check_level", USER->QL);

  if(USER->query_exp() < cexp)
    call_other("room/adv_guild", "correct_level", USER);

  if(USER->QEL) 
  {
    cexp = call_other("room/exlv_guild", "check_level", USER->QEL);
    if(USER->query_exp() < cexp)
      call_other("room/exlv_guild", "correct_extra_level", USER);
  }
  USER->save_me();
  return;
}
