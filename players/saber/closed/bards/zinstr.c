gypsy_me()  {
object ob;
  if(spell(-100,5,0) == -1) return 0;

  if(!present("gpysy_obj", this_player()))  {
  write("Your veins fill with gypsy blood.\n");
  ob = clone_object("/players/saber/closed/new_mini/gypsy.c");
  move_object(ob, this_player());
  return 1;
        }
  write("You are already a gypsy!\n");
  return 1;
        }

charm(str)  {
object ob;
if(!str)  {
  if(spell(-100,3,40,this_object()) == -1) return 0;
  ob = first_inventory(environment(TP));
  while(ob)  {
    ob->stop_fight();
    ob->stop_fight();
    ob->stop_hunter();
    ob = next_inventory(ob);
        }
  write("You raise your "+TO->query_instrument()+" and play a soothing tune.\n"+
  "All of the fighting in the room stops as your music fills the area.\n");
  say(tp+" raises "+TP->query_possessive()+" "+TO->query_instrument()+" and plays a soothing tune.\n"+
  "All of the fighting in the room stops as "+tp+"'s music fills the area.\n"+
  "You have a strong urge to stop fighting and listen to "+tp+".\n");
  call_other(TP, "add_spell_point", -40);
  return 1;
        }

  if(spell(-100,3,30,this_object()) == -1) return 0;
  ob = present(str,environment(TP));
  if(!ob)  {
   write("There is no sign of "+CAP+".\n");
   return 1;
        }
  ob->stop_fight();
  ob->stop_fight();
  TP->stop_fight();
  TP->stop_fight();
  ob->stop_hunter();
  TP->stop_hunter();
  call_other(TP, "add_spell_point", -30);
  write("You play a soothing melody on your "+TO->query_instrument()+" as you gaze into "+CAP+"'s eyes.\n"+
   CAP+" gets a dazed look on "+ob->query_possessive()+" face and stops fighting.\n");
  say(tp+" plays a soothing melody on "+TP->query_possessive()+" "+TO->query_instrument()+" as "+TP->query_pronoun()+" gazes at "+CAP+".\n"+
   CAP+" gets a dazed look in "+ob->query_possessive()+" face and stops fighting.\n");
  tell_object(ob, "You feel very peaceful...\n");
  return 1;
        }


bards_cant(str)  {
object ob, ob2;
  if(!str)  {
  write("What would you like to say?\n");
  return 1;
        }
  ob = first_inventory(environment(TP));
  while(ob)  {
  if(living(ob))  {
  if(present("instrument", ob))  {
    if(ob->query_name() != tp)  {
    tell_object(ob, tp+" signs '"+str+"' in bardic cant.\n");
        }
        }
   if(present("medal", ob))  {
    ob2 = present("medal", ob);
    if(ob2->query_cant() == 1)  {
    tell_object(ob, tp+" signs '"+str+"' in bardic cant.\n");
        }
        }
  if(!present("instrument", ob) && !present("medal", ob))  {
    tell_object(ob, tp+" makes a series of unusual facial and hand gestures.\n");
        }
        }
  ob = next_inventory(ob);
        }
write("You sign '"+str+"' in bardic cant.\n");
  return 1;
        }

int bard_farsinging(string str, int i_emote)  {
object member, person, *list;
int i,c;
  string temp;
  if(spell(-193,5,5) == -1) return 0;
  if(!TP->on_channel("gossip"))  {
    write("You are not on the gossip channel, so you may not sing.\n");
  return 1;
        }
  if(!str)  { notify_fail("You must farsing something.\n"); return 0; }
  temp = "(Songs) "+tp;
  if(!i_emote) temp = "(Songs) "+tp+" sings:";
  temp = temp+" "+str;
  list = users();
  for(i=0;i<sizeof(list); ++i)  {
  person = list[i];
  if(person->on_channel("gossip"))  {
  tell_object(person, format(temp));
  ++c;
        }
        }
  call_other(TP, "add_spell_point", -3);
  return 1;
         }

int bard_farsing(string str)  { return bard_farsinging(str,0); }
int bard_faremote(string str) { return bard_farsinging(str,1); }

bard_image(str)  {
string target, mess;
  if(!str || sscanf(str, "%s %s", target, mess) !=2)  {
    write("Who do you want to send a bard image to?\n");
    return 1;
        }
  if(!find_player(lower_case(target)))  {
    write("That player is not within the realm of magic.\n");
    return 1;
        }
  if(find_player(lower_case(target))->query_invis()) {
  write("That player is not within the realms of magic.\n");
  return 1; }
  if(in_editor(TARGET))  {
    write("That wizard is editing and should not be distrubed.\n");
    return 1;
        }
  if(spell(-100,4,1,this_object()) == -1) return 0;
  tell_object(TARGET,
    "Your ears fill with a light etheral music which somehow suggests that\n"+
    tp+" "+mess+"\n");
  write("You sing your etheral song to "+target+", who gets the etheral image of\n"+
    tp+" "+mess+"\n");
  call_other(TP, "ad_spell_point", -1);
  return 1;
        }

bard_songs()  {
write("As tells are now 1 sp, just use a tell.\n");
  return 1;
        }

succor()  {
object ob, ob2;
int tel_flag, no_sp;
  ob = this_player();
  if(spell(-200,1,35,ob) == -1) return 0;
if(REALM !="NT")  {
  ob2 = present("mirror", environment(ob));
  if(file_name(environment(this_player())) == "room/church") no_sp = 1;
  if(ob2)  say(tp+" glances into the mirror.\n");
say("The runes on "+tp+"'s "+INST+" glow a bright silver.\n"+
    tp+" slowly fades from view.\n");
  if(ob2)  {  tel_flag = 1;  say("The mirror gleams.\n");
        }
move_object(ob, "/players/saber/closed/bards/bardrooms/teleport.c");
  say(tp+" fades into view.\n");
  if(ob2)  write("You gaze into the mirror...\n");
  write("The runes on your instrument glow brightly.\n"+
    "You are now in the Guild hall.\n");
/*
  if(file_name(environment(this_player())) == "/room/church.c")  {
*/
  if(tel_flag || no_sp)  {
  write("You were not drained any mana.\n");
  return 1;  }
  else  {
  call_other(this_player(), "add_spell_point", -35);
    return 1;
        }
  write("You cannot succor from here.\n");
  return 1;
        }
        }

bard_who()  {
int number, b;
string who, levels;
object ob, ob2;
ob = users();

write("\n");
write(" >< >< >< >< >< >< >< >< >< >< >< >< >< >< >< >< >< >< >< >< >< >< >< >< >< ><\n");
write(" ><                                                                         ><\n");
write(" ><    Name     ><  Lvl  /  X-Lvl ><  Gender  ><  Guild   ><    NewGuild    ><\n");
write(" ><                                                                         ><\n");
write(" >< >< >< >< >< >< >< >< >< >< >< >< >< >< >< >< >< >< >< >< >< >< >< >< >< ><\n");
write(" ><                                                                         ><\n");
for(b=0;b<sizeof(ob); b+=1)  {
  if(ob[b]->query_level() < 21)  {
  write(" ><  ");
write(pad(ob[b]->query_name(),15));
write(pad(ob[b]->query_level(),9));
write(pad(ob[b]->query_extra_level(),9));
write(pad(ob[b]->query_gender(),12));
if(ob[b]->query_guild_name() == 0)  {
  write("-----          ");
  }  else  {
write(pad(ob[b]->query_guild_name(), 15));
        }
if(present("base_obj",ob[b]))  {
  ob2 = present("base_obj",ob[b]);
write(pad(ob2->query_newguild(),11));
        }
if(!present("base_obj", ob[b]))  {
write("           ");
        }
write("><");
write("\n");
        }
        }
write(" ><                                                                         ><\n");
write(" >< >< >< >< >< >< >< >< >< >< >< >< >< >< >< >< >< >< >< >< >< >< >< >< >< ><\n");
  write("\n");
  return 1;
        }

bard_kin()  {
int b;
object ob, ob2;
string spon;
ob = users();

write("\n");
write(" ___________________________________________________________________________\n");
write("\n");
write("  Name        Bard Level  Sponsor    Gender  Guild Title\n");
write( " ___________________________________________________________________________\n");
write("\n");
 for(b=0;b<sizeof(ob);b+=1)  {
  if(present("bard_obj", ob[b]))  {
/* changed by wizardchild - i don't like being seen while looking */
if(ob[b]->query_invis() > 30) continue;
write("  ");
  if(ob[b]->query_invis() == 0)  {
    write(pad(ob[b]->query_name(),16));  }
  else  {  write(pad("*"+ob[b]->query_name()+"*",16));  }
  ob2 = present("bard_obj", ob[b]);
  if(ob[b]->query_level() > 20)  {
    if(ob[b]->query_real_name() == "saber" ||
       ob[b]->query_real_name() == "mythos" ||
       ob[b]->query_real_name() == "saber")  {
        write("12      ");  }  else  {
    write("Wiz     ");  }
    }  else  {
  write(pad(ob2->query_bard_level(),8));
        }
  if(ob2->query_bard_level() < 6)  {
  spon = this_object()->query_sponsor();
  ob2 = present("bard_obj", ob[b]);
  spon = ob2->query_sponsor();
  write(pad(spon,11));
  }  else  { write("           ");  }
write(pad(ob[b]->query_gender(),9));
write(pad(ob[b]->query_title(),34));

write("\n");

        }
        }
write("\n");
write(" ___________________________________________________________________________\n");
  write("\n");
  return 1;
        }

bless(str)  {
object ob;
  if(!str)  {  write("Bless who?\n");  return 1;  }
  ob = present(str, environment(TP));
  if(!ob)  {  write("That person is not within sight.\n");  return 1;  }
  if(ob == TP)  {
    write("You are already among the ranks of the blessed.\n"+
    "You are a Bard!\n");
  return 1;
        }
  if(spell(0,2,5,TO) == -1)  return 0;
write("You whisper a traditional Celtic blessing over "+CAP+".\n"+
  CAP+" is succounded by a brief halo of light.\n");
say(tp+" whispers a traditional Celtic blessing over "+str+".\n"+
  CAP+" is surrounded by a brief halo of light.\n");
  tell_object(ob,
    "You feel good.\n");
call_other(TP, "add_spell_point", -5);
  return 1;
        }
