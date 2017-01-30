inherit "obj/treasure";
/* Created by the Wizard..Merlyn. */

string spouse;
object ob,ob2;
int weight;

reset(arg)
{
  if(arg) return;
  name = "A mentor object";
}

query_auto_load() { return("/players/hawkeye/closed/monk/mentor.c:" + spouse + ";"); }

id(str) { return (str == "mentor" || str == "wedding_ring"); }

short() { if (spouse) { return name + " (" + capitalize(spouse) + ")"; } else { return name; } }

long()
{
write("This is the object that links two monks in a mentorship.\n");
write("Type help mentor for commands.\n");
}

init_arg(str)
{
  sscanf(str,"%s;",spouse);
}

init()
{
  add_action("mentor", "mentor");
  add_action("heal","hm");
  add_action("damn", "911");
  add_action("bring_spouse", "bring");
  add_action("goto_spouse", "step");
  add_action("transfer","throw");
  add_action("check","cstats");
  add_action("help","help");
  if (spouse) {
    ob = find_player(spouse);
    if (ob) {
      mentor(this_player()->query_name() + " has entered the game!");
    } else {
      write("Mentor Object tells you: " + capitalize(spouse) + " is not playing now.\n");
    }
  }
}

get() { return 1; }
query_value() { return (0); }
query_weight(){ return (0); }

get_spouse()
{
  if (spouse) {
    ob = find_player(spouse);
    if (ob) return(1);
write(capitalize(spouse) + " is not on the game at this time.\n");
  } else {
    write("You are not mentored!\n");
  }
  return;
}

mentor(str)
{
  if (!get_spouse()) return(1);
  tell_object(ob, this_player()->query_name() + " (mentor): " + str + "\n");
  write("You mentor to " + ob->query_name() + ": " + str + "\n");
  return(1);
}

local_set_spouse(str) { spouse = str; }

drop(str) { if (spouse) { return(1); } else { return(0); } }

damn(str)
{
  if (!get_spouse()) return(1);
tell_object(ob,this_player()->query_name() + " needs your help!!\n");
write("You scream to " +spouse+" for help!\n");
  return(1);
}

check() {
   int hp,sp,money,xp;
int maxhp,maxsp;
    if(!find_player(spouse)) {
      write(spouse +" is not on the game.\n");
      return 1;
   }
   hp = spouse->query_hit_point();
   sp = spouse->query_spell_point();
   money = spouse->query_money();
   xp = spouse->query_experience();
   maxhp = spouse->query_mhp();
   maxsp = spouse->query_msp();
write(spouse+":");
write("  HP:["+hp+"/"+maxhp+"]");
write("  SP:["+sp+"/"+maxsp+"]");
write("  MONEY: "+money+"  ");
write("XP: "+xp+"\n");
   return 1;
}
heal(str) {
  int sp;
  sp = this_player()->query_spell_point();
if(str > sp) {
   write("You do not have enough spell points.\n");
return 1;
}
if(!find_player(spouse)) {
   write(spouse+" is not on the game.\n");
   return 1;
}
     this_player()->add_spell_point(-str);
     spouse->add_hit_point(str);
     write("You heal "+spouse+" "+str+" points.\n");
     tell_object(spouse,this_player()->query_real_name()+" healed you "+str+" points.\n");

return 1;
}
transfer(str) {
   object ob;
if(!present(str,this_player())) {
       write("You do not have a "+str+" on you.\n");
       return 1;
   }
   ob = present(str,this_player());
   if(ob->query_drop() == 1) {
     write("You can not throw that object.\n");
     return 1;
   }
  write("You throw "+str+" to "+spouse+".\n");
  this_player()->add_spell_point(-5);
  tell_object(spouse,this_player()->query_real_name()+" throws you a "+str+".\n");
  return 1;
}

bring_spouse(str)
{
  if (!get_spouse()) return(1);
  if (environment(ob)->realm() || environment(this_player())->realm()) {
    write("A magical barrier prevents you!\n");
    return(1);
  }
  tell_room(environment(ob),this_player()->query_name() + " grabs "
    + ob->query_name() + " and drags " + ob->query_objective()
    + " off ...\n");
tell_object(ob,this_player()->query_name() + " reaches out and grabs you.\n");
write("You grab " + ob->query_name() +"\n");
  say(this_player()->query_name() + " reaches out and pulls " + ob->query_name()
   + " to " + this_player()->query_objective() + ".\n");
  move_object(ob, environment(this_player()));
  this_player()->add_spell_point(-50);
  return(1);
}

goto_spouse(str)
{
  if (!get_spouse()) return(1);
  if (environment(ob)->realm() || environment(this_player())->realm()) {
    write("A magical barrier prevents you!\n");
    return(1);
  }
tell_room(environment(ob),this_player()->query_name() + " steps in.\n");

tell_object(ob,this_player()->query_name() + " steps in next to you.\n");

write("You step in next to " + ob->query_name() + "\n");
  say(this_player()->query_name() + " runs off.\n");
  move_object(this_player(),environment(ob));
  this_player()->add_spell_point(-50);
  return(1);
}


help(str)
{
  if (str == "mentor") {
cat("/players/hawkeye/closed/monk/menthelp");
    return 1;}
return; }
