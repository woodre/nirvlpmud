/* lets players set their title [to modified nirv titles] */

string
funk_it(string arg, status flag)
{
    int i, s;
    string *words, word, phew;
    
    s = sizeof(words = explode(arg, " "));

    if(flag) phew = "the";
    else phew = "";

    for(i = 0; i < s; i ++)
      if(word = words[i])
      {
        if(word != "the" && word != "of")
          phew += (capitalize(word) + " ");
        else
          phew += (word + " ");
      }

    return phew[0..strlen(phew) - 2]; /* hack off the last _ */
}      

set_title(z){
  int lvl, xlvl;

  lvl = (int)User->query_level();
  xlvl = (int)User->query_extra_level();

  TOU BOLD+BLK+"You fix your title.\n"+NORM);

  if(z == "special")
    User->set_title((string)GOB->query_special_title());
  else
  {
    if(lvl && xlvl == 0)
    {
      "/room/adv_guild"->get_level(lvl - 1);
      User->set_title(funk_it((string)"/room/adv_guild"->get_new_title(lvl - 1)), 1);
    }

    else if(lvl == 19 && xlvl > 0)
      User->set_title(funk_it((string)"/room/exlv_guild"->get_new_title(xlvl - 1, User), 0));
  }

  User->save_circle();
  User->save_me();
  return 1;
}
