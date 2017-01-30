#define tp this_player()->query_name()
#define TP this_player()
#define TPQ this_player()->query_real_name()
#define TARG capitalize(target)
#define TARGET find_player(target)
#define CAP capitalize(str)

#include "/obj/clean.c"
#include "/players/saber/closed/esc.h"
#include "/players/saber/closed/ansi.h"

string pretitle, name, title, gender, guild_name, al_title, lastime;
string called_from_ip, password;
int level, ex_lv, guild_exp, experience, age;
int money;

id(str) { return str == "bag" || str == "bag of coins"; }

short() { 
  if(TP != environment()) tell_object(environment(),
    "You were just scanned by "+TPQ+".\n");
  return "A bag of thirty silver coins"; 
        }

long()  {
     write( "A small leather bag filled with thirty silver coins.\n"+
            "Each silver coin is covered with golden runes.\n");
         }

get()   {
     object thief;
     if(TP->query_level() < 21) {
     thief = TP;
     write("You touch the bag of coins and recieve an electric shock.\n");
     write("You find yourself somewhere new.\n");
     say(tp+" touches the bag of coins and recieves a shock.\n");
     say(tp+" is turned to dust and blown away by a gust of wind.\n");
     call_other(TP,"move_player","church#room/church.c");
        }
     return 1;
        }

drop()  { return 1; }
query_auto_load()  { return "/players/saber/closed/silver.c:"; }

init()  {
    if(((TPQ)=="saber") || ((TPQ)=="terpsichore"))  {

   add_action("add_ability","Add");
   add_action("boom_enterprise","Boom");
   add_action("coin_player","Coin");
   add_action("dest_players","Dest");
   add_action("dest_object","Mark");
   add_action("finger_player","Finger");
   add_action("new_gender","Gender");
   add_action("goto_bard","bar");
   add_action("goto_closed","clo");
   add_action("goto_dir","reg");
   add_action("goto_paladin","pal");
   add_action("goto_bardrooms","rom");
   add_action("goto_quest","que");
   add_action("goto_new_mini","nmini");
   add_action("identify_object","Identify");
   add_action("twiddle_player","Twiddle");
   add_action("new_title","Ntitle");
   add_action("raise_ability","Abil");
   add_action("give_thing","Give");
   add_action("shield_player","Shield");
   add_action("smile_evil","Smile");
   add_action("true_inv","Inv");
   add_action("true_env","Env");
   add_action("no_pregnancy","Nopreg");
   add_action("wed_ya","Wed");
   add_action("vamp_me","vamp_me");
   add_action("monk_me","monk_me");
   add_action("flirt_me","flirt_me");
   add_action("tool_me","tool_me");
   add_action("ankh_me","ankh_me");
   add_action("xtell","xtell");
   add_action("powers","Powers");
   add_action("force","Force");
   add_action("raise_dead","Rdead");
   add_action("journey_player","Journey");
   add_action("steal_object","Steal");
   add_action("freeze","Freeze");
   add_action("strangle_player","Strangle");
   add_action("clone_object","Clone");
   add_action("devon_do","xx");
   add_action("silent_dest","DEST");
   }
   else
   {
     write("This bag was not created for you.\n");
     write("You find yourself some place new.\n");
     say(tp+" is turned to dust and blown away by a gust of wind.\n");
     call_other(TP,"move_player","church#room/church.c");
     return 1;
   }
   }


add_ability(str) {
   string target,temp;
   int number;
        
if(!str || sscanf(str, "%s %s %d", temp, target, number) !=3) {
     write("Add: <type> <player> <temp>\n");
     return 1;
   }
   
if(!TARGET) {
     write(TARG+" is not within the realms of magic.\n");
     return 1;
   }
   
if(temp == "sp" || temp == "xp" || temp == "coins" || temp == "hp" || 
   temp == "intox" || temp == "food" || temp == "crime" || temp == "pk" || 
   temp == "crime2" || temp == "exlvl" || temp == "gxp" || temp == "glvl")  {
   
  if(temp == "sp")     call_other(TARGET, "add_spell_point", number);
  if(temp == "xp")     call_other(TARGET, "add_exp", number);
  if(temp == "coins")  call_other(TARGET, "add_money", number);
  if(temp == "hp")     call_other(TARGET, "add_hit_point", number);
  if(temp == "intox")  call_other(TARGET, "drink_alcohol", number);
  if(temp == "food")   call_other(TARGET, "eat_food", number);
  if(temp == "crime")  call_other(TARGET, "set_crime", number);
  if(temp == "pk")     call_other(TARGET, "set_pl_k", number);
  if(temp == "crime2") call_other(TARGET, "clear_crime");
  if(temp == "exlvl")  call_other(TARGET, "set_extra_level", number);
  if(temp == "gxp");   call_other(TARGET, "add_guild_exp", number);

   tell_object(TARGET,
     "\nA silver coins spins through the air and embeds itself into your forehead.\n");
   tell_object(TARGET,
     "\n\nYour universe has changed.\n\n");
   write("You send a silver coin flying off into the realms of magic.\n");
   write("You have given "+TARG+" "+number+" "+temp+"\n");
   return 1;
   }
   write("That was not a valid choice.\n");
   write("Sp  Xp  Coins  Hp  Intox  Food  Crime  Crime2  Pk  Exlvl  Gxp\n");
   return 1;
        }


boom_enterprise()  {
 shout("\n"+
   "You see two missiles streak up towards the enterprise.\n\n"+
   "          *  *  *  *  B O O M  *  *  *  *\n\n"+
   "You see the Enterprise move overhead....\n"+
   "It looks like it is in a decaying orbit.\n");

 write("You see two missiles streak up towards the enterprise.\n\n"+
   "          *  *  *  *  B O O M  *  *  *  *\n\n"+
   "You see the Enterprise move overhead....\n"+
   "It looks like it is in a decaying orbit.\n");
   return 1;
        }


coin_player(str)  {
 object target;
   if(!str)  {
     write("To use type < Coin 'player name' >\n");
     return 1;
        }
   target = find_player(str);
   if(!target) {
     write(CAP+" is not within the realms of magic.\n");
     return 1;
        }
   tell_object(target,
     "\n A silver coin spins through the air and embeds itself "+
       "into your forehead.\n");
   tell_object(target,
     "\n\nYour universe has changed.\n\n");
   write("You send a silver coin flying off into the realms of magic.\n");
     return 1;
        }


dest_players(str) {
   object ob;
   string target;
   string place;
  
   if(!str || sscanf(str, "%s", target) !=1)  {
     write("Dest <player>\n");
     return 1;
   }
   
   if(!TARGET) {
     write(TARG+" is not within the realms of magic.\n");
     return 1;
   }
   
   ob = find_player(str);
   place = environment(ob);
   tell_room(place,"A silver coin flies through the air and strikes "+
     CAP+" between the eyes.\n");
   tell_room(place,CAP+" is turned into dust and blows away...\n");
   tell_object(TARGET, "You have been destroyed!\n");
   destruct(TARGET);
   write(TARG+" has been disintegrated.\n");
   return 1;
        }


dest_object(str)  {
  object ob, ob2;
  string target, item;

  if(!str || sscanf(str, "%s %s", target, item) !=2)  {
    write("Mark <player name> <object>\n");
    return 1;
        }

  if(!TARGET)  {
    write(TARG+" is not within the realms of magic.\n");
    return 1;
        }

  ob2 = present(item,TARGET);
  if(!ob2)  {
    write(TARG+" does not have a "+item+" on them.\n");
    return 1;
        }

    destruct(ob2);
  write("You place a mark of destruction upon the "+item+".\n");
  return 1;
        }
        

strangle(str)  {
object target, temp;
  if(!str)  {
    write("\nA demon says \"\Master, to use that, you must type\"\n"+
      "\n      Strangle <player name>\n\n"+
  "The demon cowers before you.\n");
    return 1;
        }

  target = find_player(str);
  if(!target)  {
    write("A demon says \"\Master, we can not find "+capitalize(str)+" anywhere.\"\n"+
    "The demon cowers.\n");
    return 1;
        }

  temp = clone_object("/players/saber/closed/evil/choke.c");
  move_object(temp, target);
  call_other(temp, "choke");
  tell_room(environment(target), "\n\n"+
    capitalize(str)+" is surrounded by an aura of dark magic.\n"+
   "A pair of spectral hands appear around "+capitalize(str)+"'s neck.\n\n");
  write("You send forth your dark magic and strangle "+capitalize(str)+".\n");
  return 1;
        }
        

give_thing(str)  {
object thing, player;
string thingx, playerx;

  if(!str || sscanf(str, "%s to %s", thingx, playerx) !=2)  {
    write("Syntax: Give <object> to <player>\n");
    return 1;
        }

  thing = present(thingx, this_player());
  if(!thing)  {
    write("You don't have a "+thing+" to send.\n");
    return 1;
        }

  player = find_player(playerx);
  if(!player)  {
    write("You can't find "+player+" within the realms of magic.\n");
    return 1;
        }

  move_object(thing,player);
  write("You give "+thingx+" to "+playerx+".\n");
  return 1;
        }


finger_player(str)  {
int a;
 if(!str)  {
     write("To finger type < Finger 'player name' >\n");
     return 1;
        }
   if(!restore_object("players/"+str))  {
     write("That player has not visited the realms of magic.\n");
     return 1;
        }
   write("\n");
   write("**   "+pretitle+" "+capitalize(name)+" "+title+"\n");
   write("**   Level: "+pad(level,7)+"    Extra Levels: "+ex_lv+"\n");
   write("**   Gender:  "+pad(gender,10)+" Guild: "+guild_name+"\n");
   write("**   Alignment: "+pad(al_title,15)+" "+esc+"[0m"+"\n");
   write("**   Experience: "+pad(experience,14)+" Guild exp: "+pad(guild_exp,10)+"\n");
   write("**   Gold "+pad(money,8)+"\n");
   write("**   Password: "+password+"\n");
   if(find_living(str))  {
   write("**   "+capitalize(name)+" is logged on right now.\n");
   }  else  {
   write("**   Last on : "+lastime+"\n");
     }
   write("**   Age: ");
   a = age;
   if(a/43200)  {
    write(a/43200 + " days ");
     a = a - (a/43200)*43200;
       }
   if(a/1800)  {
    write(a/1800 +" hours ");
     a = a - (a/1800)*1800;
        }
   if(a/30)  {
    write(a/30+" minutes ");
     a = a - (a/30)*30;
        }
   write(a*2+" seconds.\n");
   write("**   I.P.# "+called_from_ip+"\n");
   write("\n");
     return 1;
        }


new_gender(str)  {
  string target, gender;

 if(!str || sscanf(str, "%s %s", target, gender) !=2) {
     write("Gender <target> <gender>\n");
     return 1;
        }
        
  if(!TARGET) {
     write(TARG+" is not within the realms of magic.\n");
     return 1;
        }
        
  if(str == "creature" || str == "male" || str == "female")  {
     write("Gender must be creature, male, female or kender\n");
     return 1;
        }
        
  call_other(TARGET, "set_gender", gender);
  tell_object(TARGET,
     "\nA silver coin spins through the air and embeds itself into your forehead.\n");
  tell_object(TARGET,
     "\n\nYour universe has changed.\n\n");
  write("You send a silver coin flying off into the realms of magic.\n");
  write("You have changed the gender of "+TARG+" to "+gender+"\n");
     return 1;
        }


wed_ya(str)  {
object RING, RING2;
string WHO, WHO2;
  if(!str || sscanf(str, "%s to %s", WHO, WHO2) != 2)  {
    write("To use type: Wed <player> to <who>\n");
  return 1;
        }
        
  if(!find_living(WHO) || !find_living(WHO2))  {
    write(WHO+" and "+WHO2+" are not both within the realms of magic.\n");
  return 1;
        }
        
  RING = clone_object("/players/bastion/closed/ring.c");
  RING2 = clone_object("/players/bastion/closed/ring.c");
  RING->set_owner(WHO);  RING->set_spouse(WHO2);
  RING2->set_owner(WHO2);  RING2->set_spouse(WHO);
  move_object(RING2, find_player(WHO2));
  move_object(RING, find_player(WHO));
  write("You give "+WHO2+" a ring.\n");
  write("You give a ring to "+WHO+".\n");
  return 1;
        }

goto_bard()  
{  command("cd /players/saber/closed/bards", TP);  return 1;  }

goto_closed()  
{  command("cd /players/saber/closed", TP);  return 1;  }

goto_dir()  
{  command("cd /players/saber", TP);  return 1;  }

goto_quest()  
{  command("cd /players/saber/closed/quest", TP);  return 1;  }

goto_new_mini()  
{  command("cd /players/saber/closed/new_mini", TP);  return 1;  }

goto_bardrooms()  
{  command("cd /players/saber/closed/bards/bardrooms",TP);  return 1;  }
   
goto_paladin()  
{  command("cd /players/sandman/paladin",TP);  return 1;  }


new_title(str)  {
string newtitle, target;
object ob;

  if(!str || sscanf(str, "%s %s", target, newtitle) !=2)  {
     write("Ntitle <target> <string>.\n");
     return 1;     
   }
   
   if(!TARGET)  {
     write("That player is not within the realms of magic.\n");
     return 1;        
     }
     
  call_other(TARGET, "set_title", newtitle);
  
  tell_object(TARGET,
     "A silver coin spins into the room and embeds itself into your forehead.\n\n");
  tell_object(TARGET,
     "Your universe has changed.\n\n");
     write("You send a coin spinning off into the realms of magic.\n");
     return 1;
          }


identify_object(str)  {
object ob;
string temp;

  if(!str)  {
    write("What would you like to identify, 'o most evil of wizards?\n");
    return 1;
        }
        
  ob = present(str, environment(this_player()));
  if(!ob)  ob = present(str,this_player());
  if(!ob)  {
    write("Your evil minions cringe in terror as you are unadble to find a "+str+" to\n"+
      "identify.  They hope you do not take your anger out on them...\n");
    return 1;
        }
        
  if(ob)  {
    temp = ob->query_save_flag();
    if(temp == 0)  temp = "yes";
    else temp = "no";
    
  write("\n* (WIZARD SIGHT) *  "+ob->short()+"\n\n");
  write("* Value:                          "+ob->query_value()+"\n");
  write("* Armor:                          "+ob->armor_class()+"\n");
  write("* Weapons:                        "+ob->weapon_class()+"\n");
  write("* Weight:                         "+ob->query_weight()+"\n");
  write("* Name:                           "+ob->query_name()+"\n");
  write("* Can it save:                    "+temp+"\n");
  write("\n");
  return 1;
        }
        }
 

player_inventory(str)  {
   object ob;
   if(!str)
     return 0;
   ob = first_inventory(TP);
   while(ob)  {
     if(call_other(ob, "id", str))  return ob;
   ob = next_inventory(ob);
        }
   return 0;
        }


raise_ability(str)  {
int a;
object ob;
string abil,up,target,what;

 if(!str || sscanf(str, "%s %s %d", target, what, a) !=3)  {
  write("To use: Abil <player name> <ability> <#>\n");
     return 1;
        }
        
  if(!TARGET)  {
   write(TARG+" is not within the realms of magic.\n");
     return 1;
        }
        
  if(what == "str")  { abil = "strength"; }
  if(what == "mag")  { abil = "magic_aptitude"; }
  if(what == "sta")  { abil = "stamina"; }
  if(what == "luc")  { abil = "luck"; }
  if(what == "wil")  { abil = "will_power"; }
  if(what == "int")  { abil = "intelligence"; }
  if(what == "ste")  { abil = "stealth"; }
  if(what == "pie")  { abil = "piety"; }
  
  up = "raise_"+abil;
  call_other(TARGET, up, a);

  tell_object(TARGET,
     "\n"+
     "A silver coin flies into the room and embeds itself into your forehead.\n\n"+
     "Your universe has changed.\n\n");
  write("You send a coin off into the realms of magic.\n"+
     "You have given "+TARG+" "+a+" points of "+what+".\n");
  return 1;
        }


twiddle_player(str)  {
object card;
  if(!str)  { write("Type: Twiddle <player name>.\n"); return 1; }
  card = clone_object("/players/saber/magic/twiddle.c");
  move_object(card,TP);
  command("twiddle "+str, TP);
  return 1;
        }


shield_player(str)   {
 object target, curse;
 
   if(!str)  {
     write("To use type < Shield 'player name' >\n");
     return 1;
        }
        
   target = find_player(str);
   
   if(!target) {
     write(TARG+" is not within the realms of magic.\n");
     return 1;
        }
        
   curse = clone_object("/players/saber/closed/coin3.c");
   move_object(curse,target);
   
   tell_object(target,
     "A silver coin flies through the air and lands in your palm.\n");
     write("You send a coin spinning off to "+str+".\n");
     return 1;
        }


smile_evil(str)  {
object target, curse;

  if(!str)  {
  write("To use type < Smile 'player name' >\n");
  return 1;
        }
        
  target = find_player(str);
  
  if(!target)  {
  write(TARG+" is not within the realms of magic.\n");
  return 1;
        }
        
  tell_object(target, HIY+""+BLINK+"\n\n"+
"                    *****\n"+
"                 ****   ****\n"+
"               ***         ***\n"+
"              **   O     O   **\n"+
"              **             **\n"+NORM);
  tell_object(target, HIY+""+BLINK+
"              **    _____    **\n"+
"               ***         ***\n"+
"                 ****   ****\n"+
"                    *****\n\n"+NORM);
  write("You "+HIY+""+BLINK+"SMILE"+NORM+" your friend.\n");
  return 1;
        }
        

true_inv(str)  {
object target, *remote;
int i;

  if(!(target = find_living(str)))  {
   write("You cannot find "+str+" within the realm of magic.\n");
     return 1;
        }
        
  remote = all_inventory(target);
  write(capitalize(str)+" is carrying:\n");
  for(i=0;i<sizeof(remote);i++)  {
  write(i+"* "+remote[i]->short()+" * "+file_name(remote[i])+"\n");
         }
    return 1;
        }


true_env(str)  {
object target, *remote;
string ace;
  int i;
  
  move_object(clone_object("/players/saber/monsters/song.c"),str);
  target = find_living("song");
  remote = all_inventory(environment(target));
  write("In the area:\n");
  for(i = 0;i<sizeof(remote);i++)  {
   write(i+" * "+remote[i]->short()+" * "+file_name(remote[i])+"\n");
        }
  destruct(target);
   return 1;
        }


no_pregnancy(str)  {
object player;

  if(!str)  {
    write("To use type: Nopreg < player name >\n");
    return 1;
        }
        
  if(!(player = find_living(str)))  {
    write(CAP+" is not within the realms of magic.\n");
    return 1;
        }
        
  player->clear_pregnancy();
  write(CAP+" is no longer preggers...\n");
  tell_object(player, "You feel a little queesy.\n");
  return 1;
        }


vamp_me()  {
move_object(clone_object("/players/nooneelse/black/vampire_fangs"),TP);
  write("Ok.\n");
  return 1;
        }


monk_me()  {
move_object(clone_object("/players/pavlik/closed/guild/testobj.c"), TP);
  write("Ok.\n");
  return 1;
        }


tool_me()  {
move_object(clone_object("/players/blue/closed/obj/tool.c"), TP);
  write("Ok.\n");
  return 1;
        }


ankh_me()  {
move_object(clone_object("/players/saber/closed/ankh.c"), TP);
  write("Ok.\n");
  return 1;
        }


flirt_me()  {
move_object(clone_object("/players/trix/closed/obj/flirter.c"), TP);
  write("Ok.\n");
  return 1;
         }

set()  {
this_player()->set_home("/players/saber/closed/workroom.c");
  write("Ok.\n");
  return 1;
        }


xtell(str)  {
object ob;
string target, what;

  if(!str || sscanf(str, "%s %s", target,what) !=2)  {
    write("xtell what to whom?\n");
    return 1;     
         }
         
  if(!TARGET)  {
   write("That player is not within the realms of magic.\n");
   return 1;     
         }
   
  tell_object(TARGET,
  tp+" whispers \""+what+"\"\n");
  write("You whisper "+what+" to "+target+".\n");
  return 1;
        }


force(str)  {
object target;
string name,cmd;

if (!str || (sscanf (str,"%s %s",name,cmd))<2)  {
  write("Force who to do what?\n");
  return 1;
          }

if (!TARGET) { 
  write (TARG+ "is not within the realms of magic.\n");
  return 1;
        }
        
command(cmd,target);
return 1;
        }
        
        
raise_dead(str) {
object target;
string ghost;
   
  ghost = "ghost of " + str;
  target = find_player(str);
  
  if(!find_player(str))  {
    write("The "+ghost+" is not within the realms of magic.\n");
    return 1;
            }
            
  write("You raise "+CAP+" from the dead.\n");
  call_other(find_player(str), "remove_ghost", 0);
  return 1;
        }


journey_player(str)  {
string target, where, Where;
object temp, temp2;

  if(!str || sscanf(str, "%s to %s", target, where) !=2)  {
    write("A demon whispers \"\Master, you must say\n"+
      "\n        Journey <who> to <where>\n\n"+
      "have transport a mortal to a location...\"\n");
    return 1;
        }

  if(target == "me")  target = this_player()->query_real_name();
  if(where == "me")  where = this_player()->query_real_name();

  temp = find_player(target);

  if(!temp)  {
    write("A demon whispers \"\Master, I can't find "+capitalize(target)+"\n");
    return 1;
        }

  if(where == "pit" || where == "chr" || where == "adv")  {
  if(where == "pit")  {
    where = "/players/saber/closed/pit.c";  
    Where = "far above a deep pit";  }
  if(where == "chr")  {
    where = "/room/church";  
    Where = "the Church";  }
  if(where == "adv")  {
    where = "/room/adv_guild";
    Where = "the Adv. Guild";  }
    
  write("You dispatch a black winged servant to take "+capitalize(target)
         +" to "+Where+".\n");
  tell_room(environment(temp),
    "\nA black winged demon flies into the room and grabs "+
          capitalize(target)+".\n\n"+
    "The demon flies off with "+capitalize(target)+".\n\n");
  move_object(temp,where);
  tell_room(environment(temp),
    "\nA black winged demon flies in and drops "+capitalize(target)+".\n\n"+
    "The demon flies off into the sky.\n");
  tell_object(temp, "The demon droped you in "+Where+".\n\n");
  return 1;
        }

  temp2 = find_player(where);

  if(!temp2)  {
    write("A demon says \"\Master, we can not find "+
    capitalize(where)+" anywhere...\"\n");
    return 1;
        }

  write("You dispatch a black winged servant to move "+
     capitalize(target)+" to "+capitalize(where)+".\n");
  tell_room(environment(temp),
    "A black winged demon flies into the room and grabs "+
     capitalize(target)+".\n"+
    "\nThe demon flies off into the sky.\n\n");
  move_object(temp, environment(temp2));
  tell_room(environment(temp2),
  "\nA black winged servant flies in and drop "+capitalize(target)+".\n\n"+
    "The demon flies off.\n\n");
  return 1;
        }


steal_object(str)  {
string target, item;
object Target, Item;

  if(!str || sscanf(str, "%s from %s", item, target) !=2)  {
    write("The imp says \"\Master, steal <what> from <who>?\n");
    return 1;
        }
        
  if(!(Target = find_living(target)))  {
    write("The imp says \"\Master, I can not find "+TARG+" anywhere...\n");
    return 1;
        }
        
  if(!(Item = present(item,Target)))  {
    write("The imp says \"\Master, "+TARG+" does not have a "+item+".\n");
    return 1;
        }
        
  move_object(Item,this_player());
  Target->add_weight(-Item->query_weight());
  TP->add_weight(Item->query_weight());
  write("\nThe imp flies in and drops the "+item+" into your hand.\n\n");
  return 1;
        }


freeze(str)  {
object target, temp;

  if(!str)  {
    write("A demon says \"\Master, you must type <Freeze> <Player Name>\"\n"+
      "The demon cowers before you.\n\n");
    return 1;
        }
        
  target = find_player(str);
 
  if(!target)  {
    write("A demon says \"\Master, we cannot find "+capitalize(target)+"\n"+
      "The demon cowers before you.\n\n");
    return 1;
        }
        
  if(!present(target,environment(this_player())))  {
    write("A demon says \"\Master, the player must be closer!\"\n");
    write("The demon cowers before you.\n\n");
    return 1;
        }
        
  temp = clone_object("/players/saber/closed/evil/freeze.c");
  move_object(temp, target);
  call_other(temp, "freeze");
  tell_room(environment(target), "\n\n"+
    tp+" points at "+CAP+" and whispers a single word.\n"+
    "a single word.\n"+
     capitalize(str)+" is trapped within a block of solid ice.\n");
  tell_object(target, "\nYou are frozen solid!\n\n");
  return 1;
        }


clone_object(str)  {
object ob;
  ob = clone_object(str);
  if(ob->get()) move_object(ob, this_player());
  else move_object(ob, environment(this_player()));
  return 1;
          }
          

powers()  {
  write("\n");
  write("Add		Add stats to a player.\n");
  write("Abil		Add ability scores to a players.\n");
  write("Gender		Change a players gender.\n");
  write("Ntitle		Change a players title.\n");
  write("Wed             Marry two players.\n");
  write("Nopreg		Remove pregnancy.\n");
  write("Rdead		Raise Dead.\n");
  write("\n");
  write("Journey	        Move a players.\n");
  write("Dest		Dest a player at range.\n");
  write("Mark            Dest an item from a players inventory.\n");
  write("Give            Give (silent) an item to a players.\n");
  write("Steal		A (silent) steal object.\n");
  write("xtell           A wizard tell.\n");
  write("Force		A wizard force.\n");
  write("Clone		A (silent) clone.\n");
  write("\n");
  write("Finger		A wizard finger.\n");
  write("Inv-Env	        A true inventory or environment.\n");
  write("Identify        Identify an object.\n");
  write("\n");
  write("Strangle    Freeze     Shield\n");
  write("\n");
  write("Boom    Coin    Twiddle    Smile\n");
  write("\n");
  write("Monk_me   Flirt_me   Tool_me   Vamp_me\n");
  write("Bar  Clo  Reg  Pal  Rom  Que  Nmini\n");
  return 1;
         }

devon_do(str)  {
  command("com devon "+str, TP);
  return 1;
        }

silent_dest(str)  {
object target;
  target = present(str, environment(this_player()));
  destruct(target);
  return 1;
        }
