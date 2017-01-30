no_fight() {
   object ob;
   ob=first_inventory(environment(this_player()));
   while (ob) {
    if (living(ob)) {
     if (ob->query_attack()) {
      (ob->query_attack())->stop_fight();
      ob->stop_fight();
      }
     }
    ob = next_inventory(ob);
    }
   write("You say: NO Fighting!\n");
   say(this_player()->query_name() + " says: NO Fighting!\n");
   return 1;
}

 
 
power_get(str) {
  object ob;
  if(!str) return 0;
  ob = present(str,environment (this_player()));
   if(!ob) {
     write ("No "+str+" here.\n");
     return 1;
     }
write ("You take: "+ob->short() + ".\n");
move_object(ob,this_player());
return 1;
}
 
power_drop(str) {
  object ob;
  if(!str) {
    return 0;
    }
  if(!present(str,this_player())) {
    write("You don't have that...\n");
    return 1;
    }
  else {
   ob=present(str,this_player());
   move_object(ob,environment(this_player()));
   write("You have dropped the " +str+ "\n");
   return 1;
   }
}
 
goin(str) {
   object retard;
   retard=find_player(str);
   if (!retard) return 0;
   move_object(this_player(),retard);
   return 1;
}
 
money(str) {
 int x;
  if (!str) return 0;
   if (sscanf(str,"%d", x) != 1) {
       write ("snytax: money <amount> \n");
       return 1;
       }
   this_player()-> add_money(x);
   write("Adding "+x+" coins.\n");
return 1;
}
 
 
bring_player(str) {
   object ob;
   string bye, there;
 
   if(!str) return 0;
   ob = find_player(str);
   if(!ob) ob=find_living(str);
   if(!ob) {
     write (capitalize(str) + "is not online at this time.\n");
     return 1;
     }
   there = environment(ob);
   tell_object(ob, "The room fades as darkness falls around you\n" +
      "When the light returns you are in a new place.\n");
if(!str) return 0;
    ob = find_player(str);
    if(!ob) ob=find_living(str);
    if(!ob) {
    write (capitalize(str) + "is not online at this time.\n");
    return 1;
 
   there = environment(ob);
   tell_object(ob,"You are imprisoned "+ capitalize(str)+".\n");
   move_object(ob,"room/prison");
   tell_room(there, capitalize(str) + " is taken away.\n");
   write (capitalize(str) + " is imprisoned.\n");
   return 1;
}
 
}
church_player(str) {
   object ob;
   string bye, there;
 
if(!str) return 0;
   ob = find_player(str);
   if(!ob) ob=find_living(str);
   if(!ob) {
    write(capitalize(str) + " is not online at this time.\n");
     return 1;
     }
   there = environment(ob);
   tell_object(ob,"You are escorted to the church.\n");
   move_object(ob, "room/church");
   tell_room(there, capitalize(str) + " is escorted to the church.\n");
   write (capitalize(str) + " is escorted to the church.\n");
   return 1;
}
 
force (str) {
  object player;
  string name,cmd;
  if (!str) return 0;
  if ((sscanf (str,"%s %s",name,cmd))<2) return 0;
  player=find_living(name);
  if (!player) {write(capitalize(name) + " is not online.\n"); }
  command(cmd,player);
  return 1;
}
 
inv(str) {
  object who, obj, tmp;
  int x;
  string one, two, three;
  if(!find_living(str)) {
    write("I could not find "+str+" in the MUD.\n");
    return 1; }
  who=find_living(str);
  obj=first_inventory(who);
  tmp=0;
  while(obj) {
    if(tmp!=0) {
      write("\t\t***  DESTRUCTED  ***\n");
      destruct(tmp);
      tmp=0; }
    write(obj);
    write(" : ");
    x=0;
    if(obj->short()) { write(obj->short()); x=1; }
    if(obj->query_name()&&x==0) { write(obj->query_name()); x=1; }
    if(obj->query_id()&&x==0) { write(obj->query_id()); x=1; }
    if(x==0) { write("* INVISIBLE *"); }
    write("\n");
    if(sscanf(obj,"%s/closed/%s#%s",one,two,three)==3&&two=="goof") {
      tmp=obj; }
    obj=next_inventory(obj);
  }
  write("Done.\n");
  return 1;
}
 
heal() {
this_player()->heal_self(100000000);
return 1;
}
 
hand(str) {
  object who;
  string what;
  if(!sscanf(str,"%s %s",who,what)==2) {
    write("Usage: hand <player> <item>\n");
    return 1; }
  if(!find_living(who)) {
    write("I could not find `"+who+"'.\n");
    return 1; }
  who=find_living(who);
  move_object(clone_object(what),who);
  tell_object(who,"You feel a sudden breeze and notice you have something new on you.\n");
  write("Done.\n");
  return 1;
}
 
wizzes() {
  object list;
  int i, level, invis;
  string name, ed, tab;
  list = users();
  write("Name"+"\t\t"+"Level"+"\t"+"Invis"+"\t"+"Edit\n");
   write("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
  for(i = 0; i <sizeof(list); i++)
{
  name = capitalize(call_other(list[i],"query_real_name"));
  level = list[i]->query_level();
  invis = list[i]->query_invis();
  if(invis>999){invis=999;
}
  ed = "  ";
  if(in_editor(list[i]))
    {
       ed = "Ed";
    }
  tab = "\t";
  if(strlen(name) < 8){tab = "\t\t";
}
  if(level > 19)
    {
write(name+tab+level+"\t"+invis+"\t"+ed+"\n");
    }
}
    return 1;
}


 
commands() {
  write("This is the list of the commands for your wiztool:\n");
  write("==================================================\n");
  write("force               -  force a player to do something.\n");
  write("hand <who> <what>   -  hand a player something.\n");
  write("I <who>             -  list of a persons inventory (paths).\n");
  write("no                  -  stops fighting in a room.\n");
  write("trans <who>         -  brings a player to you.\n");
  write("bring <who>         -  brings a player to you.\n");
  write("dun <who>           -  throws a player into the town prison.\n");
  write("chr <who>           -  brings a player to the church.\n");
  write("heal                -  heal yourself.\n");
  write("money <amt>         -  give yourself some cash.\n");
  write("get! <object>       -  pickup something you normally couldn't.\n");
  write("drop! <object>      -  drop something you normally couldn't.\n");
  write("wizzes              -  shows all the wizards/gods logged on.\n");
  write("goin <who>          -  go into someones inventory.\n");
  write("\nThats the list for now.\n");
  return 1;
}
 

