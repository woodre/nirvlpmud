
endurance_check(){
  object qq;
  qq = USER->query_attack();

  if(qq)                               /* if in a fight */
  {
    if(focus && random(3))
      endurance--;
    if(endurance < -100)
      endurance = -100;
    if(present(qq, environment(USER)))  /* if AO is present */
    {
      if(endurance >= 0 && endurance_monitor) /* print monitor */
      {
        tell_object(USER, "Endurance: ");
        d = endurance * 10 / max_endurance + 1;
        if(d > 10)
          d = 10;
        for(c = 0; c < d; c++)
          tell_object(USER, posendcol+"|"+NORM);

        tell_object(USER, "\n");
      }
      else if(endurance < 0 && endurance_monitor)
      {
        tell_object(USER, "Endurance: ");
        d = (endurance - 10) / 10;
        for(c = 0; c > d; c--)
          tell_object(USER, negendcol+"|"+NORM);

        tell_object(USER, "\n");
      }
    }
  }
                    /* if neg endurance when fight stops */
  else if((!qq || !present(qq, environment(USER))) && endurance < 0)
  {
    if(endurance <= -40)
    {
      tell_object(USER, "You collapse from exhaustion.\n");
      tell_room(environment(USER),
        USER->QN+" collapses from exhaustion.\n", ({ USER }));
    }
    else if(endurance <= -20)
    {
      tell_object(USER, "You suddenly feel very tired.\n");
      tell_room(environment(USER),
        USER->QN+" suddenly looks very tired.\n", ({ USER }));
    }
    else if(endurance < 0)
    {
      tell_object(USER, "You suddenly feel drained.\n");
      tell_room(environment(USER),
        USER->QN+" suddenly looks drained.\n", ({ USER }));
    }
    USER->add_hit_point(endurance);
    endurance = 0;
    energy_check();
  }
                    /*  regular endurance regeneration */
  else if(!qq || !present(qq, environment(USER)))
  {
    if(!random(2))
      endurance++;
    if(endurance > max_endurance)
      endurance = max_endurance;
  }
}

