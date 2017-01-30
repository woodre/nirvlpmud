status
main(string arg)
{
    if(!arg)
    {
      notify_fail("Rnuke who?\n");
      return 0;
    }
    else
    {
      object *us, ob;
      int s, copies;

      s = sizeof(us = users());

      while(s--)

        if(objectp(ob = us[s]) && 
           (string)ob->query_real_name() == arg)
        {
          if(arg == "jackass")
          tell_object(ob, "Inappropriate name.\n");
          destruct(ob);
          copies ++;
        }

      if(copies)
        write("Success.\n" + copies + " copies of " + arg
               +" destructed.\n");
      else
        write("Failure.\nCould not find any copies of " + arg + ".\n");

      return 1;
    }
}
