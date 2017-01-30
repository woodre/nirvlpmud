void soul_check()
{
    if((int)User->query_alignment() < 0)
    {
      TOU("The dark gods lend you some of their strength.\n");
      User->heal_self(random(10));
    }
    else
    {
      TOU("The dark gods punish you for your wavering loyalty.\n");
      User->heal_self(-(10 + random(20)));
    }
    call_out("soul_check", 1600+random(500));
}
