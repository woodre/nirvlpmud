void
print_monitor()
{
    int a, b, c, d, e, f, g, h, i, j;
    string bonk, k;
    object bzz;

    if(custom_monitor)
    {
      tell_object(USER, MASTER->m_decode(custom_monitor) + "\n");
      return;
    }
    else 
      if(bonk = (string)USER->query_monitor_string())
    {
      tell_object(USER, (string)USER->m_decode(bonk) + "\n");
      custom_monitor = bonk;
      save_circle(1);
      return;
    }

    a = (int)USER->query_level();
    b = (int)USER->query_hp();
    c = (int)USER->query_mhp();
    d = (int)USER->query_spell_point();
    e = (int)USER->query_msp();
    f = (int)USER->query_intoxination()*100 / (a+3);
    g = (int)USER->query_stuffed()*100 / (a*8);
    h = (int)USER->query_soaked()*100 / (a*8);
    i = (int)USER->query_infuse()*100 / ((a*9)/2);
    j = MASTER->endurance_monitor();

    if(!(bzz = (object)USER->query_attack())) k = 0;

    else
      k = "AHP: " + 
       (((int)bzz->query_hp() * 10) / ((int)bzz->query_mhp())) + 
       "/10";

    tell_object(USER, 
      RED + "[fallen]" + NORM +
      " HP: " + b + "/" + c +"  SP: " + d + "/" + e + "  E: " + j +
      "% ["+f+"% "+g+"% "+h+"% "+i+"%] " + k ? k : "" + "\n");
}

status
guild_monitor_only()
{
    return 1;
}
