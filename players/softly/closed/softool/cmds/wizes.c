status
main()
{
    int s, sec, min, hr;
    object *wizes, *us, goo;
    string idle_string;

    s = sizeof(us = users());
    wizes = ({ });

    while(s --)
      if((int)(goo = us[s])->query_level() > 19 && interactive(goo)
         && environment(goo))
       wizes += ({ goo });

    s = sizeof(wizes);
    write("\
  wiz           idle\n\
--------------------------\n");
    while(s --)
    {
      goo = wizes[s];
      sec = query_idle(goo);
      idle_string = "";

      if(min = (sec / 60))
        sec -= (min * 60);
      if(hr = (min / 60))
        min -= (hr * 60);

      if(hr) idle_string += ("" + hr + "h");
      if(min) idle_string += ("" + min + "m");
      if(sec) idle_string += ("" + sec + "s");

      write(pad(capitalize((string)goo->query_real_name()), 16) +
            idle_string + "\n");
    }

    write("\n");
    return 1;
}
