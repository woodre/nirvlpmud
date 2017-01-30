sset(str) {
  string who, what, wht;
  int whtn;
  object ob;
    if(!str) {
    write("sset <who> <what> <wht> \n");  return 1; }
  sscanf(str,"%s %s %s",who,what,wht);
  ob = find_player(who);
  if(!ob) { write("not logged on.... \n"); return 1; }
if(what == "title") { ob->set_title(wht);
        write("title of "+who+" set to "+wht+".\n"); return 1; }
if(what == "gender") { ob->set_gender(wht);
        write("gender of "+who+" set to "+wht+".\n"); return 1; }
if(what == "name") { ob->set_living_name(wht);
        write("name of "+who+" set to "+wht+".\n"); return 1; }
if(what == "swield") { ob->stop_wielding(wht);
        write(who+" stops wielding "+wht+".\n"); return 1; }
if(what == "home") { ob->set_home(wht);
        write(who+"'s home is now "+wht+"\n"); return 1; }
if(what == "swear") { ob->stop_wearing(wht);
        write(who+" stops wearing "+wht+".\n"); return 1; }
if(what == "alt") { ob->set_al_title(wht);
        write("allignment title set to "+wht+".\n"); return 1; }
if(what == "race") { ob->set_race(wht);
        write("race of "+who+" set to "+wht+".\n"); return 1; }
if(what == "guild") { ob->set_guild_name(wht);
       write("Guild of "+who+" set to "+wht+".\n"); return 1; }
return 1;
}
