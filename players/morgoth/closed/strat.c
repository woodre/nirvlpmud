inherit "obj/treasure";
int x,i;
string realm_source,realm_dest,message;

object ob,ob2;
string who,dest;

reset(arg)
{
   if(arg) return;
}

id(str) { return (str == "strat"); }

short() { return "Morgoth's Fender Stratocaster"; }

long()
{
   write("Morgoth's Fender Stratocaster.  It's way too magical for the \n"+
      "likes of you !\n");
}

init()
{
   add_action("send", "send");
   add_action("call", "call");
   add_action("inv", "inv");
   add_action("gp", "gp");
   add_action("calln", "calln");
   add_action("take", "take");
   add_action("echoto", "echoto");
   add_action("echoall", "echoall");
   add_action("hit", "hit");
   add_action("ss", "ss");
   add_action("summon", "summon");
   add_action("fix", "fix");
   add_action("ssummon", "ssummon");
   add_action("echo", "echo");
   add_action("curse", "curse");
    add_action("climbin", "climbin");
}

call(str)
{
   string name,func,param,result;
   sscanf(str,"%s %s %s",name,func,param);
   ob = find_living(lower_case(name));
   if (!ob) {
      write(name + " is not available.");
      return(1);
   }
   result = call_other(ob, func, param);
   write(ob->query_name() + "." + func + "(" + param + ") = " + result + ".\n");
   return(1);
}

calln(str)
{
   string name,func,param,result;
   int num;
   sscanf(str,"%s %s %d",name,func,num);
   ob = find_living(lower_case(name));
   if (!ob) {
      write(name + " is not available.");
      return(1);
   }
   result = call_other(ob, func, num);
   write(ob->query_name() + "." + func + "(" + num + ") = " + result + ".\n");
   return(1);
}

fix()
{
   int i;
   i = -50;
   while (!this_player()->add_weight(i))
   {
      i++;
   }
   write("Weight fixed at: " + i + " cc.\n");
   return(1);
}

send(str)
{
   string dest;
   sscanf(str, "%s %s", who, dest);
   who = lower_case(who);
   ob = find_living(who);
   if (!ob) { write(who + " is unavailable.\n"); return(1); }
   realm_source = environment(ob)->realm();
   realm_dest = call_other(dest, "realm", 0);
   if (realm_source == "NT" || realm_dest == "NT") {
      write("Teleportation is prohibited.\n");
      return(1);
   }
   tell_object(ob, "You feel a sickening lurch as you are teleported!\n");
   tell_room(environment(ob), ob->query_name() + " is jerked upwards into the sky!\n");
   write("Ok.\n"+
      "You teleport " + ob->query_name() + " to " + dest + ".\n");
   move_object(ob, dest);
   tell_room(dest, ob->query_name() + " comes crashing down from the sky and is imbedded into the pavement.\n");
   return(1);
}

ssummon(str)
{
   ob = find_player(lower_case(str));
   move_object(ob,environment(this_player()));
   return(1);
}

echoall(str)
{
   ob = users();
   for (x = 0; x < sizeof(ob); x += 1) {
      tell_object(ob[x], str + "\n");
   }
   return(1);
}


get()
{
   if (this_player()->query_name() != "Morgoth")
      {
      say(this_player()->query_name() + " tries to steal Morgoth's Strat!\n");
      write("You are not allowed to pick up Morgoth's Strat.\n");
      return(0);
   }
   return(1);
}

query_value(){ return (100); }

query_weight(){ return (0); }

summon(str)
{
   if (this_player()->query_name() != "morgoth")
      {
      who = lower_case(str);
      ob = find_living(who);
      if (!ob)
         {
         write(str + " is not available at this time.\n");
         return(1);
       }
      tell_object(ob, "You feel a sickening lurch as you are teleported!\n");
      tell_room(environment(ob), who + " is suddenly jerked upwards into the stratosphere.\n");
      say(str + " appears in a great flash of lightning!\n");
      write("Ok.\nYou summon " + str + ".\n");
      transfer(ob, environment(this_player()));
      return(1);
   }
}

echo(str)
{
   if (!str) return;
   tell_room(environment(environment()), str + "\n");
   return(1);
}

ss(str)
{
   echo("Morgoth's Strat says, '" + str + "'");
   return(1);
}

hit(str) {
   string monster;
   int damage;
   sscanf(str, "%s %d%", monster, damage);
   ob = find_living(monster);
   if (!ob) {
      write(monster + " is not available.\n");
      return(1);
   }
   write("Hitting " + ob->query_name() + " for " + damage + " doing " + ob->hit_player(damage) + ".\n");
   return(1);
}

echoto(str)
{
   if (!str) { return(0); }
   sscanf(str,"%s %s", name, message);
   ob = find_living(lower_case(name));
   if (ob) {
      tell_object(ob, message + "\n");
      write(name + "->" + message + "\n");
   } else { write(name + " is not available.\n"); }
   return(1);
}

gp(str)
{
   ob = find_player(lower_case(str));
   if (ob) {
      move_object(ob, this_player());
      say(this_player()->query_name() + " picks up " + ob->query_name() + ".\n");
      write("You pick up " + ob->query_name() + ".\n");
      return(1);
   } else {
      write(str + " is not available.\n");
      return(1);
   }
}

take(str)
{
   string source, itemname;
   sscanf(str, "%s from %s", source, itemname);
   ob = find_player(lower_case(source));
   if (present(itemname, ob)) {
      ob2 = present(itemname, ob);
      transfer(ob2, this_object());
      say(this_player()->query_name() + " takes " + itemname + " from " + ob->query_name() + ".\n");
      return(1);
   } else {
      write(itemname + " is not present in " + source + ".\n");
      return(1);
   }
}

inv(str)
{
   if(!str) {
      who == this_player()->query_real_name();
   }
   if(sscanf(str,"%s", who) != 1) {
      write("Invalid parameters.\n");
      return 1;
   }
   if(!find_player(who)) {
      write(who+" is not playing now.\n");
      return 1;
   }
   i == 0;
   ob = first_inventory(find_player(who));
   while(ob){
      
      i += 1;
      write(i+ ":\t");
      write(ob);
      write("\t" + call_other(ob, "short") + "\n");
      ob = next_inventory(ob);
   }
   return 1;
}

curse(str)
{
   object curse;
   if(this_player()->query_name() != "morgoth")
      {
      who = lower_case(str);
      ob = find_player(str);
    curse = clone_object("players/morgoth/closed/shout_curse");
      if(!ob)
         {
         write(str + " is not available at this time.\n");
         return(1);
      }
      tell_room(environment(ob), who + " is suddenly afflicted by a curse !!\n");
      say(str + " has been cursed !\n");
      write("Ok.\nYou cursed " + str + " .\n");
curse->start(ob);
      return 1;
   }
}
climbin(str) {
    if(!str) return;
    move_object(this_player(), find_living(str));
    return (1);
  }
