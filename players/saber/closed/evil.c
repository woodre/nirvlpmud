inherit "/players/saber/closed/evil/magi.c";

/*
 *      THE EVIL WIZARDS FOR A BETTER NIRVANA GUILD
 *
 *        A.K.A. THE MAGI OF NIRVANA
 *
 */


#define CAP capitalize(str)
#define tp this_player()->query_name()
#define TP this_player()
#define TARG capitalize(target)

string name, callled_from_ip, pretitle, al_title, mailaddr, lastime;
string guild_name, gender, title, called_from_ip;
int ex_lv, level, experience, money, age, guild_exp;

reset(arg)  {
  ::reset(arg);
  if(arg) return;
  line_flag = 1;
         }

id(str)  {
  return str == "ankh"  ||
         str == "Ankh"  ||
       /* Don't change 'ankh_obj' or you will loose comm powers */
         str == "ankh_obj" ||
         /* Put a pet name here */
         str == "Ankh";
          }

  drop()  { return 1; }
  get()   { return 1; }
  can_put_and_get()  { return 0; }
  query_auto_load()  { return "/players/saber/closed/evil.c:"; }
    /* Be sure to change the auto load to your dir */


short()  { 
  return "An Ankh of worked black silver (worn)";
        }

long()  {
  write("\n"+
"This Ankh marks you as a member of   <Magi>  Provides background and concepts.\n"+
" the obscure Illuminati cult known   <Power> Lists Powers of the Evil Wizards.\n"+
 " as the Magi of Nirvana, nicknamed   <Other> A listing of more Magi abilities.\n"+
" Evil Wizards for a better Nirvana.  <Twist> How to edit your Evil Wiz powers.\n\n");
         }


init()  {
  ::init();
   add_action("Clone","Clone");
   add_action("fire_spell","Fire");
   add_action("heal_obj","Heal");
   add_action("identify_obj","Identify");
   add_action("journey_player","Journey");
   add_action("peace_spell","Peace");
   add_action("summon_blade","Soulblade");
   add_action("soul_player","Soul");
   add_action("steal_object","Steal");
   add_action("Terror","Terror");
        }


magi_update()  {
object OBJ;
  /* Be sure to change this */
OBJ = clone_object("/players/saber/closed/evil.c");
destruct(this_object());
move_object(OBJ,this_player());
  return 0;
        }

fire_spell(str)  {
string target;
int number, check_hp;
object ob;
  if(!str || sscanf(str, "%s %d", target, number) != 2)  {
    write("What mere mortal do you wish to incinerate with fire?\n");
    return 1;
        }
  ob = present(target,environment(this_player()));
  if(!ob)  {
    write("There is no "+TARG+" here to incinerate.\n");
    return 1;
        }
  if(number > 250)  {
    write("Evil as you are, that is a little excessive...\n");
    return 1;
        }
  /* Change this line if you like */
  write("\n"+
    "You incinerate "+TARG+" with an inferno of crimson fire.\n\n");
  /* Change this line if you like */
  say("\n"+
    tp+" incinerates "+TARG+" with an inferno of crimson fire.\n\n");
  tell_object(ob, "\nYou feel your blood begin to boil.\n\n");
  check_hp = ob->query_hp();
  ob->hit_player(number);
  if(number < check_hp)  ob->attck_object(this_player());
  return 1;
        }

heal_obj(str)  {
object ob;
string target;
int heal_amount;
  if(!str || sscanf(str, "%s %d", target, heal_amount) !=2)  {
    write("A small demon says: \"\Master, you must type: Heal <player name> <#>\n"+
    "to use this power.\n\nThe demon bows to you and resumes cowering.\n");
    return 1;
        }
  if(!find_living(target))  {
    write("A demon cowers in front of you.\n"+
      "The demon says: \"\Master, we could not find "+capitalize(target)+" anywhere...\"\n");
    write("\nThe demon cowers.\n\n");
    return 1;
        }
  ob = find_living(target);
  ob->heal_self(heal_amount);
  write("You channel your Evil Wizard powers into "+capitalize(target)+"\n"+
    capitalize(target)+" has been healed "+heal_amount+".\n");
/*
  tell_room(environment(ob), "\n"+
    capitalize(target)+" is covered in an evil gray aura.\n\n");
 */
/*
  tell_object(ob, "You have been healed "+heal_amount+" by "+this_player()->query_name()+".\n"+
    "Remember to thank your Evil Wizard master...\nOr else...\n\n");
*/
  return 1;
        }

identify_obj(str)  {
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
  write("\n* (EVIL WIZARD SIGHT) *  "+ob->short()+"\n\n");
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
    write("A demon whispers \"\Master, I can not find "+capitalize(target)+"\n");
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
  write("You dispatch a black winged servant to take "+capitalize(target)+" to "+Where+".\n");
  tell_room(environment(temp),
    "\nA black winged demon flies into the room and grabs "+capitalize(target)+".\n\n"+
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
    write("A demon says \"\Master, we can not find "+capitalize(where)+" anywhere...\"\n");
    return 1;
        }

  write("You dispatch a black winged servant to move "+capitalize(target)+" to "+capitalize(where)+".\n");
  tell_room(environment(temp),
    "A black winged demon flies into the room and grabs "+capitalize(target)+".\n"+
    "\nThe demon flies off into the sky.\n\n");
  move_object(temp, environment(temp2));
  tell_room(environment(temp2),
  "\nA black winged servant flies in and drop "+capitalize(target)+".\n\n"+
    "The demon flies off.\n\n");
  return 1;
        }

peace_spell(str)  {
object ob;
  if(!str)  {
ob = first_inventory(environment(this_player()));
  while(ob)  {
    ob->stop_fight();
    ob->stop_fight();
    ob->stop_hunter();
    ob = next_inventory(ob);
        }
  write("You release demons into the chamber...\n"+
    "\nAll the fighting suddenly stops.  (Wonder why?  *EVIL WIZARD*)\n\n");
  say(this_player()->query_name()+" opens a portal.\n"+
    "Demons step into the room.\n\n"+
    "A demon walks up to you.\n  You decide that maybe you should stop fighting...\n\n");
  return 1;
        }

  ob = present(str,environment(this_player()));
  if(!ob)  {
    write("You summon a demon to stop the fighting.\n"+
    "The demon says \"\Master, I can not find "+capitalize(str)+" to pacify them...\"\n\n");
    return 1;
        }
  ob->stop_fight();
  ob->stop_fight();
  this_player()->stop_fight();
  this_player()->stop_fight();
  write("You gate in a demon and point to "+capitalize(str)+".\n"+
    "\nThe demon strides up to "+capitalize(str)+" and grabs "+ob->query_objective()+".\n"+
    capitalize(str)+" stops fighting.\n\n");
  say(this_player()->query_name()+" gates in a demon and points to "+capitalize(str)+"\n"+
    "The demon strides up to "+capitalize(str)+" and grabs "+ob->query_objective()+".\n"+
    capitalize(str)+" stops fighting.\n\n");
  ob->stop_hunter();
  this_player()->stop_hunter();
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
/*
  if((Target->query_level()) > 20)  {
    write("\nThe demon can not touch the items of another Evil Wizard...\n\n");
    return 1;
        }
  */
  move_object(Item,this_player());
  Target->add_weight(-Item->query_weight());
  TP->add_weight(Item->query_weight());
  write("\nThe imp flies in and drops the "+item+" into your hand.\n\n");
  return 1;
        }

summon_blade()  {
move_object(clone_object("/players/saber/closed/evil/soulsword.c"),TP);
write("\nThe room dims.\n\nA gate opens, and a demon steps forth.\n"+
  "\nThe demon hands you a SOULBLADE.\n\n");
say("\nThe room dims.\n\nA mystic gate opens, and a demon steps forth.\n"+
  "\nThe demon hands "+this_player()->query_name()+" a SOULBLADE.\n\n");
tell_room(environment(this_player()),
  "\nThe demon departs.\n\n");
  return 1;
        }

soul_player(str)  {
int a;
  if(!str)  {
    write("Your mystic senses do not sense the soul of "+capitalize(str)+" anywhere.\n");
    return 1;
        }
  if(!restore_object("players/"+str))  {
    write("There is no soul by the name of "+capitalize(str)+".\n");
    return 1;
        }
  write("\n");
  write("**   "+pretitle+" "+capitalize(name)+" "+title+"\n");
  write("**   Level: "+pad(level,7)+"    Extra Levels: "+ex_lv+"\n");
  write("**   Gender:  "+pad(gender,10)+" Guild: "+guild_name+"\n");
  write("**   Alignment: "+pad(al_title,15)+"\n");
  write("**   Experience: "+pad(experience,14)+" Guild exp: "+pad(guild_exp,10)+"\n");
  write("**   Gold "+pad(money,8)+"\n");
  write("**   Email address: "+mailaddr+"\n");
  if(find_living(str))  {
    write("**   "+capitalize(name)+" is logged on right now.\n");
    }  else  {
    write("**   Last on: "+lastime+"\n");
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

Terror(str)  {
object ob;
int a;

  if(!str)  {
  ob = first_inventory(environment(this_player()));
  write("You use your Evil Wizard powers to terrorize EVERYBODY!!!\n");
  say(this_player()->query_name()
    +"fills the room with an aura of EVIL.\n"+
    "You are VERY afraid.\n");
  while(ob)  {
  if(ob->query_interactive())  {
  if(ob->query_level() < 21)  {
  ob->run_away();
        }
        }
  ob = next_inventory(ob);
        }
  return 1;
        }

  ob = present(str, environment(this_player()));
  if(!ob)  {
  write("You do not see "+capitalize(str)+" here to inspire terror in.\n");
  return 1;
        }
/*
  if(ob->query_level() > 29)  {
    write("You shouldn't scare other Evil Wizards.\n");
    return 1;
        }
 */
  if(!ob->query_interactive())  {
    write("Why scare an NPC?\n");
    return 1;
        }
  write("You use your Evil Wizard power to terrorize "+capitalize(str)+" .\n");
  say(this_player()->query_name()+" uses "+this_player()->query_possessive()+" Evil Wizard powers to terrorify "+capitalize(str)+".\n");
  ob->run_away();
  return 1;
        }

