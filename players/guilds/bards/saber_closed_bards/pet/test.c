inherit "/obj/monster";
string master_name, pet_leave, deliver_string;
string deliver_string2, deliver_string3;
string ANIMAL;
int RUN;
object mark;
#define OB this_object()
#define MASTER this_object()->query_master()
#define NAME this_object()->query_name()
#define OWNER capitalize(this_object()->query_master())
#define PET capitalize(this_object()->short())
#define GENDER find_living(MASTER)->query_possessive()
#define CALL this_object()->query_CALL()

reset(arg)  {
mark = clone_object("/players/saber/closed/bards/bard_mark.c");
move_object(mark,this_object());
   ::reset(arg);
    heal_start = 0;
   if (!arg){
     set_name( "raven" );
     set_alias("pet");
     set_short("A large black raven");
     set_gender("creature");
     set_alt_name("pet");
     set_race( "bird");
     set_long(
       "A large raven with dark feathers and gleaming black eyes.\n"+
       "The raven has a small silver band around its left foot.\n");
     set_level(1);
     set_heal(5,20);
     set_ac(3);
     set_wc(5);
     set_hp(15);
     set_al(400);
     set_aggressive(0);
     set_chat_chance(3);
     set_a_chat_chance(2);
     set_spell_mess1("The raven pecks at its opponents eyes.");
     set_spell_mess2("The raven pecks at your eyes.");
     set_chance(10);
     set_spell_dam(random(5));
     enable_commands();
     set_dead_ob(this_object());
call_out("pet_follow",6);
   }
}

init()  {
  ::init();
  if(this_player()->query_real_name() == MASTER)  {
   add_action("dart_command","Com");
   add_action("bye","Bye");
   add_action("sic","Sic");
   add_action("munch","Munch");
   add_action("give","Give");
   add_action("hand","Hand");
   add_action("silence","Silence");
   add_action("talk","Talk");
   add_action("guard","Guard");
   add_action("back_up","Back");
        }
        }

bye()  {
object ob;
  say(PET+" looks over at "+OWNER+" and nods.\n");
  say(PET+" flies off into the sky.\n");

  ob = present(MASTER, environment(OB));
    if(ob)  { transfer_all_to(ob);  }
  remove_call_out("pet_follow");
  destruct(OB);
  return 1;
        }

sic(str)  {
object ob;
  if(!str)  {  
    write("What would you like your "+NAME+" to attack?\n");  return 1;  }
  if(!(ob = present(str, environment(this_object()))))  {
    write("There is no "+str+" here to attack.\n");  return 1;  }
  if(ob->is_player() || ob->is_pet())  {
    write("No pk means players and pets too...\n");  return 1;  }
  say(OWNER+" yells \""+capitalize(alias)+" attack!\"\n");
  say(PET+" dives towards "+capitalize(str)+".\n");
  this_object()->attack_object(ob);
  return 1;
       }

monster_died()  {
object ob;
int DAMAGE;
  ob = find_player(MASTER);
  DAMAGE = this_object()->query_level() * 3;
  ob->hit_player(random(DAMAGE));
  remove_call_out("pet_follow");
  tell_room(environment(this_object()),
     PET+" falls to the ground with a thud.\n\n");
  tell_room(environment(this_object()),
     capitalize(MASTER)+" screams in pain.\n\n");
return 0;
        }

give(str)  {
int flag;
string who, what;
object target, item;

  if(!str)  {
    notify_fail("Have "+NAME+" take what to who?\n");  return 0;  }
  if(sscanf(str, "%s to %s", what, who) < 2)  {
    notify_fail("Have "+NAME+" deliver what?\n");  return 0;  }
  item = present(lower_case(what), find_living(MASTER));
  target = find_player(lower_case(who));
  if(!target)  {
    notify_fail("Have "+NAME+" deliver it to who?\n");  return 0;  }
  if(target->query_invis()) { notify_fail("Have "+NAME+" deliver it to who?\n");  return 0;  }
  if(environment(target)->realm() == "NT" || 
     environment(this_player())->realm() == "NT") {
       write("Either you or the target is in a restricted zone.\n"+
             "The object can not be sent.\n");
  return 1; }
  if(!item)  { item = present(lower_case(what), OB);
    if(!item)  {
      notify_fail("Neither you or "+NAME+" has that item.\n"); return 0;
      }  flag = 1;
    }
 if(call_other(item, "drop", 0))  {
    write("You can't have your "+NAME+" deliver that.\n");
    return 1;
       }
 command("drop "+what, this_player());

  if(flag)  {
    if(RUN)  {
      say(PET+" runs quickly from the room.\n\n"+
      PET+" returns shortly and nods to "+this_object()->query_master()+".\n");
       }  else  {
  say(PET+" flies off into the sky.\n\n"+
     PET+" returns and nods to "+this_object()->query_master()+".\n");
        }
  } else {
    if(RUN)  {
      say(PET+" takes an item from "+this_object()->query_master()+" and runs quickly from the room.\n\n"+
      PET+" returns shortly and nods to "+this_object()->query_master()+".\n");
       }  else  {
  say(PET+" takes an item from "+this_object()->query_master()+" and flies off into the sky.\n\n"+
     PET+" returns and nods to "+this_object()->query_master()+".\n");
         }
        }
  tell_room(environment(target), PET+" flies in and gives a "+what+" to "+who+".\n\n"+PET+" flies off into the sky.\n");
  move_object(item,target);
  return 1;
         }

munch()  {
object corpse;
  if(!(present("corpse", environment(OB))))  {
    write("There is no corpse here.\n"); return 1;  }
  corpse = present("corpse", environment(OB));
  if(OB->query_animal() == "raven" ||
     OB->query_animal() == "crow"  ||
     OB->query_animal() == "hawk")  {
  say(PET+" flies down to the corpse and plucks out its eyeballs.\n");
        }
  if(OB->query_animal() == "sprite")  {
    say("The wind sprite engulfs the corpse.\n");
        }
  if(OB->query_animal() == "drake")  {
    say("The drake flies down to the corpse and rips out its throat.\n"+
      "The drake laps up the blood with a tiny red tongue.\n");
        }
  if(OB->query_animal() == "pegasus" ||
       OB->query_animal() == "bpegasus")  {
    say(PET+" looks down at the corpse and shakes its mane.\n"+
      "The corpse slowly turns to smoke and drifts away.\n");
        }
  if(OB->query_animal() == "phoenix")  {
    say("The Phoenix glares at the corpse.\n"+
      "The corpse explodes into a brief inferno of blazing ash.\n");
        }
  destruct(corpse);
  heal_self(20);
  return 1;
         }

dart_command(str)  {
string name, word, temp, MAS;

  if(sscanf(str, "%s %s", word, temp) <2)  
  word = str;
switch(word)  {
  case "bye": return bye(); break;
  case "sic": return sic(temp); break;
  case "give": return give(temp); break;
  case "munch": return munch(temp); break;
  case "hand": return hand(temp); break;
  case "silence": return silence(); break;
  case "talk": return talk(); break;
  case "guard": return guard(); break;
  case "back": return back_up(temp); break;
  default: notify_fail("Command "+PET+" to do what?\n"); return 0; break;
  }
        }

talk()  {
this_object()->set_chat_chance(5);
say(OWNER+" looks over at "+GENDER+" "+NAME+" and smiles.\n");
return 1;
        }

silence()  {
this_object()->set_chat_chance(0);
say(OWNER+" looks over at "+GENDER+" "+NAME+" and shakes "+GENDER+" head.\n");
  return 1;
        }

back_up(str)  {
object ob;
object ob2;
  if(!str)  {
    write("What do you want your "+NAME+" to retreat from?\n");
    return 1;
        }
  if(!(ob = present(str, environment(this_object()))))  {
    write("There is no "+capitalize(str)+" here for your "+NAME+" to retreat from.\n");
    return 1;
        }
    if(!this_object()->query_attack()) { 
    write("The Pet is not in combat!\n");
   return 1;}
   if(ob != this_object()->query_attack()) {
    write("The Pet is not attacking "+capitalize(str)+".\n");
   return 1;}
  if(ob->query_attack()) ob2 = ob->query_attack();
    else ob2 = this_player();
    ob->stop_fight();
    ob->stop_fight();
    this_object()->stop_fight();
    this_object()->stop_fight();
    ob->stop_hunter();
    this_object()->stop_hunter();
  say(PET+" retreats from its fight with the "+capitalize(str)+".\n");
    ob->attack_object(ob2);
  return 1;
        }

pet_follow()  {
string there, master;
object ob;
int HP_LVL;
there = find_player(MASTER);
if(!find_player(MASTER))  { bye(); }
  ob = find_player(MASTER);
  HP_LVL = this_object()->query_hp() * 100 / this_object()->query_mhp();
  if(this_object()->query_hp() < this_object()->query_mhp())  {
    tell_object(ob, "Your "+NAME+" is at "+HP_LVL+"% of its health.\n");
        }
if(!present(MASTER,environment(this_object())))  {
  say(
    PET+" flies from the room after its master.\n");
  move_object(this_object(),environment(there));
  say(
    PET+" flies into the room.\n");
        }
call_out("pet_follow",6);
  return 1;
        }

hand(str)  {
int flag;
string who_to,what;
object target, item;

  if(!str)  {
    notify_fail("Have "+NAME+" give you what?\n");  return 0;  }
  if(sscanf(str, "%s to %s", what, who_to) < 2)  {
    notify_fail("Have the "+NAME+" give you what?\n");  return 0;  }
  target = present(who_to,environment(this_object()));
  item = present(what,this_object());
if(!target || !living(target))  {
  notify_fail("Have the "+this_object()->query_name()+" give the "+what+" to who?\n"); return 0; }
if(!item)  {
  notify_fail("The "+this_object()->query_name()+" does not have a "+what+".\n"); return 0; }
tell_room(environment(this_object()),
  "The "+this_object()->query_name()+" drops a "+what+" into "+capitalize(who_to)+"'s hand.\n");
move_object(item,target);
  return 1;
        }

guard()  {
object ob;
string temp, temp2;

  if(this_object()->query_attack())  {

  ob = attacker_ob;
  temp = ob->query_name();

tell_room(environment(this_object()),
  "\n\nThere is a bedazzling flash of illumination as the slim figure of a woman\n"+
  "materializes in the air above you.\n\n"+
  "The woman speaks\n\n");
tell_room(environment(this_object()),
  "       \"\I am Crysea, goddess who watches over animals.\"\n"+
  "\n       \"\This "+this_object()->query_name()+" is under my protection.\"\n\n"+
  "Crysea points at "+capitalize(temp)+" as her eyes flash.\n\n");

if(ob->is_player())  {
  temp2 = (ob->query_hp() / 4);
  ob->heal_self(-temp2);
tell_room(environment(this_object()),
  capitalize(temp)+" is struck by a blazing bolt of lightning.\n\n");
  return 1;
        }

if(ob->is_pet())  {
  temp2 = (ob->query_hp() / 2);
  ob->add_hit_point(-temp2);
tell_room(environment(this_object()),
  capitalize(temp)+" is struck by an inferno of fire which rages down from the sky.\n"+
  "\nThe goddess is gone.\n");
  return 1;
        }
        }
  write("Your }"+this_object()->query_name()+" is not under attack by a player or pet or kid.\n");
  return 1;
        }

set_master(str)  {  master_name = str;  }
query_master()   {  return master_name; }
is_pet()         {  return 1; }
set_run(str)     { RUN = str;   }
RUN()            { return RUN;  }
set_animal(str)  {  ANIMAL = str;  }
query_animal()   {  return ANIMAL; }
