inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg){
     set_name( "dart" );
     set_short("A small black drake");
     set_alias("drake");
     set_gender("male");
     set_race( "dragon");
     set_long("A small drake with skin and scales of soft onyx leather.\n"+
      "It has cute little wings of black midnight, a tiny red\n"+
      "forked tongue and eyes of scintillating rainbow hues.\n"+
      "Dart appears to be agile, and looks downright talkative.\n");
     set_level(20);
     set_heal(2,5);
     set_ac(30);
     set_wc(25);
     set_hp(600);
     set_al(1000);
     set_aggressive(0);
     set_chat_chance(0);
     set_a_chat_chance(0);
     set_spell_mess1("Dark blasts his opponent with a burst of flame.");
     set_spell_mess2("Dart blasts you with a burst of flame.");
     set_chance(15);
     set_spell_dam(20);
     set_heart_beat(1);
     set_object(this_object());
     set_function("atme");
     set_type("dart");
     set_match("");
     set_function("pats");
     set_type("pats");
     set_match("");
   }
}

init()  {
  ::init();
   add_action("dart_command","command");
        }

bye()  {
object ob;
 set_heart_beat(0);
say("The small black drake waves goodbye.\n"+
  "Dart says: Goodbye everybody!\n"+
  "The small black drake does an aerial loop and flies off into the sky.\n");
  ob=present("saber",environment(this_object()));
  if(ob) { transfer_all_to(ob);  }
  destruct(this_object());
  return 1;
        }

sic(str)  {
object ob;
ob = present(str,environment(this_object()));
if(!ob) { return 1; }
this_object()->attack_object(ob);
if(living(ob)) ob->attack_object(this_object());
  return 1;
       }

buzz(str)  {
object ob;
string there;
if(!str) { write("Buzz who?\n");  return 1;  }
ob = find_player(str);
 if(!ob) ob=find_living(str);
 if(!ob)  { write(capitalize(str)+" is not within the realms of magic.\n");
     return 1;    }
 there = environment(ob);
tell_object(ob,"A small black drake flies out of nowhere and flashes by you.\n"+
"The small black drake does an aerial loop and flies off into the sky.\n");
tell_room(there,"A small black drake fliers out of nowhere and buzzes "+capitalize(str)+".\nThe small black drake does an aerial loop and fliers off into the sky.\n",ob);
write("The small black drake does an aerial loop and flies off into the sky.\n"+
   "The small black drake flies back in.\n");
    return 1;
        }

wear_f(str)  {
  if(!str)  { notify_fail("What should Dart wear?\n");  return 0;  }
  command("wear "+str);
  return 1;
        }

wield_f(str)  {
  if(!str)  { notify_fail("What should Dart wield?\n"); return 0; }
  command("wield "+str);
  return 1;
        }

give(str)  {
int flag;
string who, what;
object target, item;
if(!str)  { notify_fail("Have Dart take what to who?\n");  return 0;  }
if(sscanf(str,"%s to %s",who,what)<2)  { notify_fail("Have Dart deliver what?\n");
  return 0;   }
item = present(lower_case(what), find_living("saber"));
target = find_player(lower_case(who));
 if(!target)  { notify_fail("Have Dart deliver it to who?\n");
     }
if(!item)  {
  item = present(lower_case(what), this_object());
  if(!item)  { notify_fail("Neither you or Dart has that item.\n");  return 0; }
  flag = 1;
        }
  if(flag)  {
  say("Dart does an aerial loop and flies from the room.\n"+
   "Dart flies into the area and grins at Saber.\n"+
   "Dart says: ok boss, I did it...\n");
  } else {
  say("Dart takes something from Saber and flies from the room.\n"+
   "Dart flies back into the room and smiles at Saber.\n"+
   "Dart says: ok boss, I did it.\n");
         }
  tell_room(environment(target), "A small black drake flies in, gives a "+what+" to "+target->query_name()+", and then flies off.\n");
  move_object(item,target);
  return 1;
         }

munch()  {
object corpse;
 corpse = present("corpse",environment(this_object()));
 if(!corpse)  { notify_fail("There is no corpse here.\n"); return 0; }
  say("The small black drake descends upon the corpse and devours it.\n"+
  "Dart burps.\n"+
   "The small black drake licks its tiny white fangs.\n");
  destruct(corpse);
  heal_self(20);
  return 1;
         }

dart_command(str)  {
 string word,temp;

  if(sscanf(str,"%s %s", word,temp)<2)
  word = str;
switch(word)  {
  case "bye": return bye(); break;
  case "sic": return sic(temp); break;
  case "give": return give(temp); break;
  case "wear": return wear_f(temp); break;
  case "wield": return wield_f(temp); break;
  case "munch": return munch(temp); break;
  case "buzz": return buzz(temp); break;
  default: notify_fail("Command dart to do what?\n");  return 0; break;
  }
       }


catch_tell(str)  {
string who, it;
object ob;
int n;

if(sscanf(str, "%s dies %s",who,it)==2 || sscanf(str,"%s died%s",who,it)==2)  {
  if(who=="saber")  {
  say("The small black drake begins to cry.\n");
  return 1;    }
  else  {
  say("The small black drake does an aerial loop to avoid the falling corpse.\n");
    return 1;
        }
        }

  if(sscanf(str, "%s missed %s",who,it)==2 && who!="Dart")  {
  n = random(17);
  if(n == 1)  { say("The small black drake laughs at "+who+".\n"); }
  if(n == 2)  { say("The small black drake dodges the wild attack.\n");  }
  if(n == 3)  { say("Dart flies about the area to get a better view of the fight.\n");  }
  if(n == 4)  { say("Dart says: You almost hit me "+who+".\n"); }
  if(n == 5)  { say("Dart says: Wow!  That was a wild swing!\n");  }
  if(n == 6)  { say("The small black drake dodges the attack with an aerial loop.\n");  }
  if(n == 7)  { say("The small black drake sticks his tongue out at "+who+".\n");  }
  if(n == 8)  { say("Dart cheers for "+who+".\n"); }
     }

if (sscanf(str,"%s fuck %s",who,it)==2 ||
   sscanf(str,"%s bastard %s",who,it) ==2 ||
   sscanf(str,"%s bitch %s",who,it)==2 ||
   sscanf(str,"%s cock %s",who,it)==2 ||
   sscanf(str,"%s shit %s",who,it)==2 ||
   sscanf(str,"%s asshole %s",who,it)==2 ||
   sscanf(str,"%s dick %s",who,it)==2 ||
   sscanf(str,"%s cunt %s",who,it)==2 ||
   sscanf(str,"%s fuck",who)==1 ||
   sscanf(str,"%s shit",who)==1 ||
   sscanf(str,"%s bastard",who)==1 ||
   sscanf(str,"%s bitch",who)==1 ||
   sscanf(str,"%s cock",who)==1 ||
   sscanf(str,"%s dick",who)==1 ||
   sscanf(str,"%s cunt",who)==1 ||
   sscanf(str,"%s asshole",who)==1 ||
   sscanf(str,"%s fucker %s",who,it)==2)
   {
     call_out("naughty",1);
   return 1;
        }

}

atme(str)  {
string a,b;
  sscanf(str,"%s %s",a,b);
  if(a == "dart" || a == "Dart")
     return;
 if(!sscanf(str, "% says: %s",a,b)==2) { return; }
  str = b;
  if(sscanf(str, "%sDart%s", a,b) == 2)  {
   say("Dart nods enthusiastically.\n");
    }
    return 1;
         }

pats(str)  {
string who;
 if(sscanf(str, "% pats",who) == 1)  {
  if(who == "Dart" || who == "dart")
  return;
  say("Dart purrs softly.\n");
  write("Dart purrs softly.\n");
   return 1;
    }   }

naughty()  {
  say("The small black drake arches an eyebrow in surprise.\n"+
   "Dart says: You know that language like that can get you in trouble...\n");
  return 1;
        }


heart_beat()  {
object ob;
  ob = find_living("saber");
  if(!ob)  {
   say("A small black drake flies home.\n");
  set_heart_beat(0);
  destruct(this_object());
  return 1;
       }
 if(!present(ob,environment(this_object())))  {
  say("A small black drake flies from the room after his master.\n");
  move_object(this_object(), environment(ob));
  say("A small black drake flies into the room.\n");
  return 1;
        }
  ::heart_beat();
        }

query_guild()  {
  return "vampire";
         }
