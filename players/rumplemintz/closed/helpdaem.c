id(str) { return str == "helper"; }

short () {
   return "a helper";
}

long() {
   write("This is a usefull item.\n");
}



powlist() {
   write("LIST OF POWERS\n");
   write("\n");
   write("iwho          list of invisible players\n");
   write("money         give yourself 60000 coins\n");
   write("harm          harm a player by any amount\n");
   write("telll         powerful tell\n");
   write("sayy          everyone will see this!\n");
   write("alterr        alter hp/sp of a player.\n");
   write("W             look at a weapon's stats.\n");
   write("A             look at an armor's class.\n");
   write("axp           add xp to someone.\n\n");
   return 1;
}


telll (str)
{
 string who, what, Name, Who;
 if(!str) {
   write("Telll what?\n"); return 1;}
 if(!sscanf(str, "%s %s", who, what)) {
   write("Usage: telll [who] [what]\n"); return 1;}
 if(!find_player(who)) {
   write("No such player '"+who+"'.\n"); return 1;}
 Name = capitalize(this_player()->query_real_name());
 tell_object(find_player(who), Name+" tells you: "+what+"\n");
 Who = capitalize(who);
 write ("You telll "+Who+": "+what+"\n");
 return 1;
}

sayy (str) {
 string Name;
 if (!str) {
   write("Sayy what?\n"); return 1;}
 Name = capitalize(this_player()->query_real_name());
 say(Name+" HAS AN IMPORTANT MESSAGE TO SAY!!!\n");
 say("****************************************\n");
 say("\n");
 say("\n");
 say(Name+" says: "+str+"\n");
 say("\n");
 say("\n");
 say("****************************************\n");
 say("THANK YOU FOR LISTENING TO THIS IMPORTANT MESSAGE.\n");
 write("You sayy: "+str+"\n");
 return 1;
}

Money (str)
{
 write("You're the rich man now!\n");
 this_player()->add_money (60000);
 return 1;
}

axp(str) {
         string name;
         int num;
         object who;
         if(sscanf(str,"%s %d",name,num)!=2) return write("huh?\n");
         if(!name) {
            write("huh?\n");
            return 1;
         }
         if(!num) {
            write("huh?\n");
            return 1;
         }
         who = find_player(name);
         if(!who) {
            write("He ain't here.");
         }
         who->add_exp(num);
         write("Done\n");
         return 1;
}


iwho(str) {
     object us;
     string is_invis;
     int x, y;
     if(str) return;
     us=users();
     write("Invisible player------------>location\n");
     for(x=0;x<sizeof(us);x++) {
        is_invis = us[x]->short();
        y = x+1;
        if(is_invis==0){
           write(y + ".\t"+capitalize(us[x]->query_real_name()));
           if(strlen(us[x]->query_real_name())>7)
              write("\t"); else write("\t\t");
           write(environment(us[x])->short());
           write("\n");
        }
     }
     return 1;
}

harm (str)  {
  int num;
  object obj,env;
  if(!str)  {
     notify_fail("Who do you want to harm?\n");
     return 0;
  }
  num=0;
  sscanf(str,"%s %d",str,num);
  obj=find_living(str);
  if(!obj)   {
     notify_fail("No "+str+" active now.\n");
     return 0;
  }
  env=environment(obj);
  write("You harm "+ call_other(obj,"query_name")+".\n");
  tell_room(env, call_other(obj,"query_name")+" suffers in pain.\n");
  if(!num)
     call_other(obj,"hit_player",(obj->query_mhp())+1);
  else
     call_other(obj,"hit_player",num);
  return 1;
}

alterr(str) {
   object ob;
   string who, type;
   int num;
   if (!str) {
      write("Usage: alterr [player] (hp/sp) [amount].\n");
      return 1;}
   if(!sscanf(str, "%s %s %d", who, type, num)) {
      write("Usage: alterr [player] (hp/sp) [amount].\n");
      return 1;}
   ob = find_player(who);
   if(!ob) {
      write("That player is not on at the moment.\n");
      return 1;}
   if(type == "hp") { ob->add_hit_point(num); return 1; }
   if(type == "sp") { ob->add_spell_point(num); return 1; }
   else {
      write("Usage: alterr [player] (hp/sp) [amount].\n");
      return 1;}
   return 1;
}

W(str) {
  object ob;
  if(!str) { write("Usage: W [weapon].\n"); return 1;}
  ob = present(str, this_player());
  if(ob) {
     write("Stats of "+str+"\n");
     write("WC : "+ob->weapon_class()+"\n");
     return 1;}
}

A(str) {
  object ob;
  if(!str) { write("Usage: A [armor].\n"); return 1;}
  ob = present(str, this_player());
  if(ob) 
     write("Stats of "+str+"\n");
     write("AC : "+ob->armor_class()+"\n");
     return 1;
}

