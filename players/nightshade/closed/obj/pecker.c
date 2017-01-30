inherit "obj/treasure";
object ob, shd, fun;
reset(arg){
if (arg) return;
set_short("Nightshade's Hour Glass");
   set_weight(1);
   set_value(0);
}
long() {
if(this_player()->query_real_name() != "nightshade") {
write("You see your time running out.\n");
return 1;
}
write("Type 'shintra mak' to activate the hour glass.\n");
return 1;
}
id(str) { return str == "glass"; }
drop() { return 1; }
query_auto_load() { return "/players/nightshade/misc/toy:"; }
init() {
::init();
if(this_player()->query_level()<21) {
  write("You are not worthy of this object.\n");
  return 1;
}
if (environment() == this_player()) {
add_action("help","shintra");
add_action("whohas","whohas");
add_action("clean","clean");
add_action("update_target","update");
add_action("stat_all","spill");
add_action("new_clone","C");
add_action("new_stat","stat");
add_action("new_say","say");
add_action("new_say"),add_xverb("'");
add_action("sview","sview");
add_action("sdest","sdest");
add_action("strip","strip");
add_action("estimate","estimate");
add_action("man","man");
add_action("money","money");
add_action("reset_target","reset");
add_action("patch_target","patch");
add_action("power_drop","drop!");
add_action("power_get","get!");
add_action("goin","goin");
add_action("no_fight","NO");
add_action("do_force", "make");
add_action("give_exp", "gexp");
add_action("give_faith", "gfaith");
add_action("heal_mana", "hmana");
add_action("give_mana", "gmana");
add_action("cleric_stat", "cstat");
add_action("set_mana", "setmana");
add_action("do_symbol", "csym");
add_action("do_cloak", "become");
add_action("do_uncloak", "revert");
add_action("do_lamp", "lamp");
add_action("do_summon", "T");
add_action("give_levels", "glevel");
add_action("do_zap", "zap");

}
   }

do_zap(str) {
object duh,duh1;
if(!str) return;
duh=find_player(str);
if(!duh) {
   write("Fuck you.\n");
   return 1;
}
write("ZZZZAAAAAAP.\n");
duh->hit_player(1000);
return 1;
}

do_force(str) {
   object who;
   string who2, what;
   if(sscanf(str, "%s %s",who2, what) !=2) return write("Dork.\n");
   who=find_player(who2);
   if(!who) {
      write(capitalize(who2)+" is not here you pounk.\n");
   }
command(what, who);
return 1;
}
new_clone(str) {
object ob;
if (!str) {
write ("Clone what?\n");
return 1;
}
ob = clone_object(str);
if (!ob) return;
if (!ob->get()) {
move_object(ob,environment(this_object()));
write (file_name(ob)+" cloned. Moved to environment.\n");
return 1;
}
move_object(ob,this_player());
write (file_name(ob)+" cloned.\n");
return 1;
}
goin(string str) {
  object retard;
  retard=find_player(str);
  if (!retard) return 0;
  move_object(this_player(), retard);
  return 1;
}
sview(str) {
object target, shd;
if (!str) {
write ("What do you want to check for shadows?\n");
return 1;
}
target = present(str,this_player());
if (!target) target = present(str,environment(this_player()));
if (!target) target = find_player(str);
if (!target) target = find_living(str);
if (!target) target = find_object(str);
if (!target) {
write ("No such object: "+str+".\n");
return 1;
}
shd = shadow(target,0);
if (!shd) {
write (target->short()+" ("+file_name(target)+") : NOT SHADOWED.\n");
return 1;
}
write (target->short()+" ("+file_name(target)+") : Shadowed by-> "+file_name(shd)+".\n");
shd = shadow(shd,0);
while(shd) {
write ("       Multiple shadows: "+file_name(shd)+".\n");
shd = shadow(shd,0);
}
return 1;
}

sdest(str) {
object target, shd, ob;
if (!str) {
write ("What do you want to strip of shadows?\n");
return 1;
}
target = present(str,this_player());
if (!target) target = present(str,environment(this_player()));
if (!target) target = find_player(str);
if (!target) target = find_living(str);
if (!target) target = find_object(str);
if (!target) {
write ("No such object: "+str+".\n");
return 1;
}
shd = shadow(target,0);
if (!shd) {
write (target->short()+" ("+file_name(target)+") is not shadowed.\n");
return 1;
}
ob = shd;
ob = shadow(ob,0);
write (file_name(shd)+" dested.\n");
destruct(shd);
while(ob) {
  shd = ob;
  shd = shadow(ob,0);
  destruct(ob);
  ob = shd;
   }
return 1;
}
new_say(str) {
if (!str) {
write ("Say what?\n");
return 1;
}
write ("You say: "+str+"\n");
say(capitalize(this_player()->query_name())+" says: "+str+"\n");
return 1;
}

new_stat(str) {
object ob;
if (!str) {
write ("Syntax: stat <target>\n");
return 1;
}
ob = present(str,environment(this_player()));
if (!ob) ob = find_living(str);
if (!ob || !living(ob)) {
write ("There is no such living thing.\n");
return 1;
}
write (ob->query_name()+" : ( "+file_name(ob)+" )\n");
write ("===========\n");
write ("Level: "+ob->query_level());
if (ob->query_level() > 20) write (" ** WIZARD\n");
else
write ("\n");
write ("HP: "+ob->query_hp()+" / "+ob->query_mhp()+"\n");
write ("SP: "+ob->query_sp()+" / "+ob->query_msp()+"\n");
write ("Weapon class: "+ob->query_wc()+".\n");
write ("Armor class:  "+ob->query_ac()+".\n");
write ("Gold coins:   "+ob->query_money()+".\n");
if (ob->query_weapon()) {
  write ("Wielding: "+(ob->query_weapon())->short()+"\n");
}
return 1;
}
update_target(str) {
object ob;
if (!str) {
write ("Defaulting to "+file_name(environment(this_player()))+".\n");
ob = environment(this_player());
ob->reset(0);
write ("Done.\n");
return 1;
}
}

money(str) {
int x;
if (!str) return 0;
if (sscanf(str,"%d",x) != 1) {
  write ("Syntax: money <amount>\n");
return 1;
}
  this_player()->add_money(x);
write ("Adding "+x+" coins.\n");
return 1;
}

reset_target(str) {
object ob;
if (!str) {
write ("Syntax: reset <item> or <here>\n");
return 1;
          }

if (str == "here") {
ob = environment(this_player());
write ("Resetting "+file_name(environment(this_player()))+".\n");
ob->reset(1);
return 1;
                   }
ob = present(str,this_player());
if (!ob) ob = present(str,environment(this_player()));
write ("Resetting "+ob->short()+" : ( "+file_name(ob)+" )\n");
ob->reset(1);
return 1;
}

no_fight() {
object ob;
ob = first_inventory(environment(this_player()));

while (ob) {
if (living(ob)) {
if (ob->query_attack()) {
(ob->query_attack())->stop_fight();
ob->stop_fight();
}
}
ob = next_inventory(ob);
}

write ("You say: NOOOO... fighting.\n");
say(this_player()->query_name()+" says: NOOOO... fighting.\n");
return 1;
}

clean(str) {
object ob, shit;
if (this_player()->query_level() < 21) {
write ("You shouldn't play with wiz toys.\n");
destruct(this_object());
return 1;
}
if (str == "here") {
ob = first_inventory(environment(this_player()));
while(ob) {
shit = next_inventory(ob);
if (!ob->is_player()) {
write ("You sanitize : "+ob->short()+".\n");
destruct(ob);
        }
ob = shit;
      }
return 1;
}
}

power_get(str) {
object ob;
if (!str) return 0;
ob = present(str,environment(this_player()));
if (!ob) {
write ("There is no "+str+" here.\n");
return 1;
}
write ("You take: "+ob->short()+".\n");
say(this_player()->query_name()+" takes: "+ob->short()+".\n");
move_object(ob,this_player());
return 1;
}

patch_target(str) {
object ob, last_arg;
string who, do_str, arg, cap_name;
int iarg, count, check;

 	if (this_player()->query_level() < 21) return 0;
	if (!str) {
 write ("Syntax: patch [object] [function] [argument]\n");
 return 1;
      }
 if (sscanf(str,"%s %s %s",who,do_str,arg) == 3) {
  if (sscanf(arg,"%d",iarg) == 1) check = 1;
  }
else
if (sscanf(str,"%s %s",who,do_str) == 2) check = 1;
else {
  write ("Error in patch.\n");
  return 1;
}
ob = find_ob(who);
  if (!ob) {
  write ("No such object: "+who+".\n");
  return 1;
  }
if (!function_exists(do_str,ob)) {
write ("That function does not exist in "+file_name(ob)+"!\n");
return 1;
}
if (check) last_arg = call_other(ob,do_str,iarg);
  else {
    string x1,x2,x3,x4,x5;
  if (sscanf(arg,"%s,%s",x1,x2) != 2)
   last_arg = call_other(ob,do_str,arg);
  else if (sscanf(arg,"%s,%s,%s,%s,%s",x1,x2,x3,x4,x5) == 5)
   last_arg = call_other(ob,do_str,x1,x2,x3,x4,x5);
else if (sscanf(arg,"%s,%s,%s,%s",x1,x2,x3,x4) == 4)
  last_arg = call_other(ob,do_str,x1,x2,x3,x4);
else if (sscanf(arg,"%s,%s,%s,%s",x1,x2,x3) == 3)
  last_arg = call_other(ob,do_str,x1,x2,x3);
else if (sscanf(arg,"%s,%s,%s,%s",x1,x2) == 2)
  last_arg = call_other(ob,do_str,x1,x2);
else
  { write ("Too many arguments.\n");
    return 1;
}
}
write (file_name(ob)+"\n");
write ("Result: "+last_arg);
write ("\n");
   while(count) {
 if (check) call_other(ob,do_str,iarg);
  else call_other(ob,do_str,arg);
   count -= 1;
}
  return 1;
}

find_ob(str) {
object ob;
 ob = present(str,this_player());
  if (!ob) ob = present(str,environment(this_player()));
  if (!ob) ob = find_object(str);
  if (!ob) ob = find_living(str);
  if (!ob) ob = find_living("ghost of "+ str);
  return ob;
}


power_drop(str) {
object ob;
if (!str) return 0;
ob = present(str,this_player());

if (!ob) {
write ("You don't have a "+str+".\n");
return 1;
}

write ("You drop "+ob->short()+".\n");
say(this_player()->query_name()+" drops "+ob->short()+".\n");
move_object(ob,environment(this_player()));

return 1;
}
whohas(str) {
object *guys, ob;
object first, next;
object f_name;
int x;
if (this_player()->query_level() < 21) {
write ("You shouldn't mess with wiz toys.\n");
destruct(this_object());
return 1;
}
    guys = users();
/*
 first = first_inventory[guys];
if(!str) {
  for(x=0; x<sizeof(guys); x++) {
while(first) {
  next = next_inventory(first);
  f_name = first[x]->query_file_name();
  if(f_name) {
    write(first[x]->query_name()+" : "+first[x]->short()+"\n");
  }
}
first = next;
}
}
*/
    for(x=0;x<sizeof(guys);x++) {
ob = present(str,guys[x]);
if (ob) {
write (guys[x]->query_name()+" : "+ob->short()+" ("+file_name(ob)+")");
write ("\n");
}
       }
return 1;
}
help(str) {
if (str == "mak") {
write ("Commands                        Effect\n"
     + "======================================\n"
     + "'whohas <item>'               Tells you who has an item.\n"
     + "'clean here'                  Dests all non-living objects\n"
  + "                               in your environment.\n"
+ "'update'                      Update your environment.\n"
+ "'spill all'                   Spills everyone's stats.\n"
+ "'get! <item>'                 Power get without error checking.\n"
+ "'drop! <item>'                Power drop without error checking.\n"
+ "'strip <player>'              Shows you a player's inventory.\n"
+ "'NO'                          Stop fighting in the room.\n"
+ "'patch <object> <function> <argument>'\n"
+ "'money <amount>'              Add coins to you.\n"
+ "'gexp'                        Adds guild exp.\n"
+ "'gfaith'                      Adds Faith to a player.\n"
+ "'hmana'                       Adds Mana to a player.\n"
+ "'gmana'                       Adds Mana to a player.\n"
+ "'cstat'                       Cleric stats a player.\n"
+ "'setmana'                     Sets a players mana.\n"
+ "'csym'                        Dests and reclones symbol.\n"
+ "' T'                          Tran's a player to you.\n"
+ "'reset <object> or <here>'    Reset an item.\n"
+ "'stat <living object>'        A better stat command.\n"
+ "'man <function>'              Displays the doc file of a function.\n"
+ "'estimate <player>'           Gives you the estimated value of\n"
 + "                               a player.\n"
  + "");
return 1;
}
}
man(str) {
if (!str) return 0;
cat ("/doc/efun/"+str);
cat ("/doc/lfun/"+str);
return 1;
}
strip(str) {
object ob, target;
if (!str) return 0;
target = find_living(str);
if (str == "me") target = this_player();
if (str == "here") target = environment(this_player());
if (!target) {
write ("There is no such living creature.\n");
return 1;
}
write ("Inventory of ");
if (str == "here") write (target->short()+" : ");
if (str != "here") write (capitalize(target->query_real_name())+" : ");
write ("( "+file_name(target)+" )\n");
write ("\n");
   ob = first_inventory(target);
    while(ob) {
if (ob->short())
write (ob->short()+" : ("+file_name(ob)+")\n");
  else
write ("Invisible Object : ("+file_name(ob)+")\n");
  ob = next_inventory(ob);
    }
return 1;
}
estimate(str) {
object ob, target;
int shop_val, total_val;
if (!str) return 0;
target = find_living(str);
if (!target) {
write ("There is no such living creature.\n");
return 1;
}
shop_val = 0;
total_val = 0;
   ob = first_inventory(target);
    while(ob) {
if (ob->query_value() < 1001) shop_val += ob->query_value();
  else
shop_val += 1000;
total_val += ob->query_value();
  ob = next_inventory(ob);
    }
total_val += target->query_money();
write (capitalize(target->query_real_name())+"\n");
write ("===========\n");
write ("Shop value: "+shop_val+" gold coins.\n");
write ("Real value: "+total_val+" gold coins.\n");
return 1;
}
stat_all(str) {
object *guys;
int x,y;
string *shit, new_shit;
if (str != "all") return 0;

guys = users();

for(x=0;x<sizeof(guys);x++) {
new_shit = guys[x]->query_real_name();
shit = explode(guys[x]->query_real_name(),"");
if (sizeof(shit) < 11) {
  for (y = 0;y < (11 - sizeof(shit));y ++) {
   new_shit = new_shit + " ";
     }
new_shit = capitalize(new_shit);
write (new_shit+"\t ");
write ("Level: "+guys[x]->query_level()+"\t ");
write ("WC: "+guys[x]->query_wc()+"\t ");
write ("AC: "+guys[x]->query_ac()+"\t ");
write ("Gold: "+guys[x]->query_money()+"\t");
write ("\n");
}
}
return 1;
}
do_symbol() {
object ob, duh;
duh=present("symbol", this_player());
if(!duh) {
   write("You clone a symbol.\n");
move_object(clone_object("players/nightshade/closed/guild/symbol"), this_player());
   return 1;
}
write("You have one but here is the new one. Destructing and re-cloning.\n");
destruct(duh);
ob=clone_object("players/nightshade/guild/symbol");
move_object(ob, this_player());
return 1;
}
cleric_stat(str) {
object ob, badge;
int gl, gexp, gdon, gf, gm, gmmax;
string gc, gp;
int gt;
int st;
  if(!str) {
    write("Format: kstat <player>\n");
    return 1;
  }
  ob = find_player(str);
  if(!ob) {
    write("No one by that name.\n");
    return 1;
  }
  badge = present("cleric_guild", ob);
  if(!badge) {
    write(ob->query_name()+" does not have the symbol of faith.\n");
    return 1;
  }
  gl = badge->query_guild_level();
  gexp = badge->query_guild_exp();
  gdon = badge->query_donated();
  gf = badge->query_faith();
  gm = badge->query_mana();
  gmmax = badge->query_max_mana();
  gt = ((gl * 2)+10) - badge->query_heal_count();
  write(ob->short() + "\n");
  write("Guild Level: " +gl+ "\t\t\tGuild Exp: " +gexp+ "\n");
  write("Mana: "+gm+" / "+gmmax+"\t\tDonated: "+gdon+"\n");
  write("Guild Faith: " +gf+ "\t\t\tHeal left: "+gt+ "\n");
  return 1;
}

give_exp(str) {
object ob, badge;
string who;
int am;
  if(this_player()->query_name() != "Nightshade") {
    write("You can not do that.\n");
    return 1;
  }
  if(sscanf(str, "%s %d", who, am) != 2) {
    write("Wrong usage.\n");
    return 1;
  }
  ob = find_player(who);
  if(!ob) {
    write("No one by that name playing.\n");
    return 1;
  }
        badge = present("cleric_guild", ob);

  if(!badge) {
    write("That player does not have a badge.\n");
    return 1;
  }
  write("You give " +ob->query_name()+ " " +am+ " guild exps.\n");
  tell_object(ob,this_player()->query_name()+
        " has given you " +am+ " guild exps.\n");
  badge->add_guild_exp(am);
  return 1;
}


give_faith(str) {
object ob, badge;
string who;
int am;
  if(this_player()->query_name() != "Nightshade") {
    write("You can not do that.\n");
    return 1;
  }
  if(sscanf(str, "%s %d", who, am) != 2) {
    write("Wrong usage.\n");
    return 1;
  }
  ob = find_player(who);
  if(!ob) {
    write("No one by that name playing.\n");
    return 1;
  }
  badge = present("cleric_guild", ob);
  if(!badge) {
    write("That player does not have a badge.\n");
    return 1;
  }
  write("You give " +ob->query_name()+ " " +am+ " faith points.\n");
  tell_object(ob,this_player()->query_name()+
        " has given you " +am+ " faith points.\n");
  badge->add_faith(am);
  return 1;
}


give_mana(str) {
object ob, badge;
string who;
int am;
  if(this_player()->query_name() != "Nightshade") {
    write("You can not do that.\n");
    return 1;
  }
  if(sscanf(str, "%s %d", who, am) != 2) {
    write("Wrong usage.\n");
    return 1;
  }
  ob = find_player(who);
  if(!ob) {
    write("No one by that name playing.\n");
    return 1;
  }
  badge = present("cleric_guild", ob);
  if(!badge) {
    write("That player does not have a badge.\n");
    return 1;
  }
  write("You give " +ob->query_name()+ " " +am+ " mana points.\n");
  tell_object(ob,this_player()->query_name()+
        " has given you " +am+ " mana points.\n");
  badge->add_mana(am);
  return 1;
}
heal_mana(str) {
object ob, badge;
string who;
int am;
  if(this_player()->query_name() != "Nightshade") {
    write("You can not do that.\n");
    return 1;
  }
  ob = find_player(str);
  if(!ob) {
    write("No one by that name playing.\n");
    return 1;
  }
  badge = present("cleric_guild", ob);
  if(!badge) {
    write("That player does not have a badge.\n");
    return 1;
  }
  write("You heal " +ob->query_name()+ "'s mana points.\n");
  tell_object(ob,this_player()->query_name()+
        " has healed your mana points.\n");
  badge->add_mana(1000);
  return 1;
}
set_mana(str) {
object ob, badge;
string who;
int am;
  if(this_player()->query_name() != "Nightshade") {
    write("You can not do that.\n");
    return 1;
  }
  if(sscanf(str, "%s %d", who, am) != 2) {
    write("Wrong usage.\n");
    return 1;
  }
  ob = find_player(who);
  if(!ob) {
    write("No one by that name playing.\n");
    return 1;
  }
  badge = present("cleric_guild", ob);
  if(!badge) {
    write("That player does not have a badge.\n");
    return 1;
  }
  write("You set " +ob->query_name()+"'s max mana to " +am+".\n");
  badge->set_max_mana(am);
  return 1;
}

do_lamp(str)
{
object target;
if(!str) return;
if(str == "off")
{
if(shd) destruct(shd);
write("Cleaning lamps.\n");
return 1;
}
target=find_player(str);
if(!target)
{
write("No such dood.\n");
return 1;
}
if(shd)
{
write("The person is already lamped.\n");
return 1;
}
shd=clone_object("players/nightshade/misc/shield");
shd->startup(target);
write(capitalize(str)+" is now being lamped.\n");
return 1;
}
do_cloak(str) {
        if(!str) {
        write("Become what?\n");
        return 1;
                }
        if(fun) {
write("You are already shadowed.  Revert if you want to change.\n");
return 1;
}
write("You become "+capitalize(str)+".\n");
say(this_player()->query_name()+
"'s form starts to melt and reshape into the likeness of "
+capitalize(str)+".\n");
   fun=clone_object("players/nightshade/misc/tool_shadow");
   fun->target_shadow(this_player());
   fun->set_boggle(str);
   return 1;
}
do_uncloak() {
write("You turn to normal.\n");
say(this_player()->query_name()+" reverts back to normal.\n");
   write("Ok.\n");
   fun->remove_target();
   return 1;
}
do_summon(str) {
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
tell_object(ob, "You have been sucked into a tiny rip in the fabric of time.\n");
   move_object(ob, environment(this_player()));
    tell_room(there, capitalize(str) +
    " is squeezed into a tiny rip in the fabric of time.\n");
    say (capitalize(str) + " arrives suddenly.\n");
    write (capitalize(str) + " answers your summons.\n");
    return 1;
}
give_levels(str) {
object ob, badge;
string who;
int am;
  if(this_player()->query_name() != "Nightshade") {
    write("You can not do that.\n");
    return 1;
  }
  if(sscanf(str, "%s %d", who, am) != 2) {
    write("Wrong usage.\n");
    return 1;
  }
  ob = find_player(who);
  if(!ob) {
    write("No one by that name playing.\n");
    return 1;
  }
        badge = present("cleric_guild", ob);

  if(!badge) {
    write("That player does not have a badge.\n");
    return 1;
  }
  write("You give " +ob->query_name()+ " " +am+ " guild levels.\n");
  tell_object(ob,this_player()->query_name()+
        " has given you " +am+ " guild levels.\n");
  badge->set_guild_level(am);
  return 1;
}
