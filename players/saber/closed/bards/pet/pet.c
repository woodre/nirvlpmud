inherit "/obj/monster";
string master_name, pet_leave, deliver_string;
string deliver_string2, deliver_string3;
int RUN;
object mark;
#define OB this_object()
#define PET capitalize(this_object()->short())

reset(arg)  {
mark = clone_object("/players/saber/closed/bards/bard_mark.c");
move_object(mark,this_object());
   ::reset(arg);
   if (!arg){
     set_name( "raven" );
     set_short("A large black raven");
     set_alt_name("bird");
     set_gender("creature");
     set_race( "bird");
     set_long(
       "A large raven with dark feathers and gleaming black eyes.\n"+
       "The raven has a small silver band around its left foot.\n");
     set_level(1);
     set_heal(4,20);
     set_ac(3);
     set_wc(5);
     set_hp(15);
     set_al(400);
     set_aggressive(0);
     set_chat_chance(3);
     set_a_chat_chance(2);
     load_chat("The raven ruffles its feathers.\n");
     load_chat("The raven looks at you.\n");
     load_chat("The raven says \"\KAARR\"\n");
     load_chat("The raven asks \"\WROAARRKK?\"\n");
     load_chat("The raven says \"\CRAACKK\"\n");
     load_chat("The raven circles.\n");
     load_a_chat("The raven circles its foe.\n");
     set_spell_mess1("The raven pecks at its opponents eyes.");
     set_spell_mess2("The raven pecks at your eyes.");
     set_chance(10);
     set_spell_dam(random(5));
     set_dead_ob(this_object());
call_out("pet_follow",6);
   }
}

init()  {
  ::init();
  if(present("instrument",this_player()))  {
   add_action("dart_command","raven");
        }
        }

bye()  {
object ob;
say(capitalize(this_object()->short())+" looks over at "+capitalize(this_object()->query_master())+" and nods.\n");
say(PET+" flies off into the sky.\n");
  ob=present(this_object()->query_master(),environment(this_object()));
  if(ob) { transfer_all_to(ob);  }
  remove_call_out("pet_follow");
  destruct(this_object());
  return 1;
        }

sic(str)  {
object ob;
ob = present(str,environment(this_object()));
if(ob->is_player())  { return 1; }
if(ob->is_pet())  { return 1; }
if(!ob) { return 1; }
say(PET+" flies towards "+capitalize(str)+".\n");
this_object()->attack_object(ob);
  return 1;
       }

monster_died()  {
object ob;
string temp3, mas;
int DAMAGE;
temp3 = this_object()->query_master();
ob = find_player(temp3);
DAMAGE = this_object()->query_level() * 3;
ob->hit_player(random(DAMAGE));
remove_call_out("pet_follow");
tell_room(environment(this_object()),
   PET+" falls to the ground with a thud.\n\n");
tell_room(environment(this_object()),
   capitalize(temp3)+" screams in pain.\n\n");
return 0;
        }

give(str)  {
int flag;
string who, what;
object target, item;
if(!str)  { notify_fail("Have "+this_object()->name()+" take what to who?\n");  return 0;  }
if(sscanf(str,"%s to %s",what,who)<2)  { notify_fail("Have "+this_object()->name()+" deliver what?\n");
  return 0;   }
item = present(lower_case(what), find_living(this_object()->query_master()));
target = find_player(lower_case(who));
 if(!target)  { notify_fail("Have "+this_object()->name()+" deliver it to who?\n");
     }
if(!item)  {
  item = present(lower_case(what), this_object());
  if(!item)  { notify_fail("Neither you or "+this_object()->name()+" has that item.\n");  return 0; }
  flag = 1;
        }
  if(what == "instrument" || what == "base_obj" || what == "coat" || what == "soul")  {
  return 1;  }
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
 corpse = present("corpse",environment(this_object()));
 if(!corpse)  { notify_fail("There is no corpse here.\n"); return 0; }
  say(PET+" flies down to the corpse and plucks out its eyeballs.\n");
  destruct(corpse);
  heal_self(20);
  return 1;
         }

dart_command(str)  {
string name, word, temp;

  if(sscanf(str, "%s %s", word,temp) <2)
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
  default: notify_fail("Command "+PET+" to do what?\n"); return 0; break;
  }
       }

talk()  {
this_object()->set_chat_chance(5);
write("You look over at your "+this_object()->query_name()+" and smile.\n");
return 1;
        }

silence()  {
this_object()->set_chat_chance(0);
write("You look over at your "+this_object()->query_name()+" and shake your head.\n");
  return 1;
        }

pet_follow()  {
string there, master;
master = this_object()->query_master();
there = find_player(master);
if(!find_player(master))  { bye(); }
if(!present(master,environment(this_object())))  {
  say(
   "The raven flies from the room after its master.\n");
  move_object(this_object(),environment(there));
  say(
   "A black raven flies into the room.\n");
        }
call_out("pet_follow",6);
  return 1;
        }

hand(str)  {
int flag;
string who_to,what;
object target, item;
if(!str)  { notify_fail("Have the "+this_object()->query_name()+" give you what?\n"); return 0; }
if(sscanf(str,"%s to %s",what,who_to) < 2)  {
    notify_fail("Have the "+this_object()->query_name()+" give you what?\n");  return 0;  }
target = present(who_to,environment(this_object()));
item = present(what,this_object());
if(!target || !living(target))  {
  notify_fail("Have the "+this_object()->query_name()+" give the "+what+" to who?\n"); return 0; }
if(!item)  {
  notify_fail("The "+this_object()->query_name()+" does not have a "+what+".\n"); return 0; }
if(what == "instrument" || what == "base_obj" || what == "rock" || what == "soul")  { return 1; }
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
