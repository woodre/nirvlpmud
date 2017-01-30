spectral_binding(str)  {
object binob;
object ob;
int a, b;
 if(!str)  {
   write("Play Harper's Song of Spectral Binding upon what creature?\n");
   return 1;
        }
  ob = present(str,environment(TP));
  if(!ob)  {
   write("There is no "+CAP+" here to bind.\n");
   return 1;
        }
/*
  if(present("bind_mark",ob))  {
*/
if(ob->query_level() > 19) {
    write(CAP+" is to mighty to be further bound.\n");
    return 1;
        }
binob=present("bind_mark",ob);
if(!binob) {
  binob=clone_object("/players/saber/bards/bind_mark.c");
  binob->set_orgwc(ob->query_wc());
  binob->set_orgac(ob->query_ac());
  move_object(binob,ob);
  }
binob->redo();
 if(attack_spell(-150,6,35,ob) == -1) return 0;
 if(ob->query_npc())  {
write("You play Harper's Song of Spectral Binding.\n\n"+
   "The room fills with slow, etheral sounding "+TO->query_instrument()+" music.\n\n"+
  ob->query_name()+" is bound by illusionary chains.\n\n");
say(tp+" plays Harper's Song of Spectral Binding.\n\n"+
   "The room fills with slow, etheral sounding "+TO->query_instrument()+" music.\n\n"+
   ob->query_name()+" is bound in illusionary chains.\n\n");
 a = ob->query_wc() - random(4);
  /*
 if(a < ((ob->query_level() * 3) / 4))  {
     a = (ob->query_level() * 3) / 4;
  */
   if(a < ((binob->query_orgwc() * 3) / 4)) {
     a = (binob->query_orgwc() * 3) / 4;
     write(ob->query_name()+" cannot be further bound.\n");   }
 ob->set_wc(a);
 b = ob->query_ac() - random(1);
/*
 if(b < (ob->query_level() / 2))  {
     b = ob->query_level() / 2;
*/
 if(b < ((binob->query_orgac() * 3) / 4))  {
     b = binob->query_orgac()*3 / 4;
     write(ob->query_name()+" cannot be further bound.\n");   }
 ob->set_ac(b);
 tell_room(environment(TP), ob->query_name()+" starts moving more slowly.\n");
/*
if(ob->query_level() > 22)  {
move_object(clone_object("/players/saber/bards/bind_mark.c"),ob);
        }
*/
 call_other(TP,"add_spell_point",-35);
   return 1;
        }
  write("You cannot bind an object.\n");
   return 1;
       }

note_of_cloaking(str)  {
object ob;
 if(!str)  { write("Cloak who?\n");  return 1;  }
  ob = find_player(str);
 if(!ob)  {
   write("You cannot find "+CAP+" within the realms of magic.\n");
     return 1;
        }
 if(spell(-176,3,10,TP) ==-1) return 0;
 write("You play a single note upon your "+TO->query_instrument()+".\n"+
   CAP+" is cloaked in an illusionary cloak.\n");
 tell_room(environment(ob), "You hear "+tp+" play a single note upon "+TP->query_possessive()+" "+TO->query_instrument()+".\n"+
    CAP+" is cloaked in an illusionary cloak.\n");
 call_other(ob,"stop_hunter");
 call_other(TP,"add_spell_point",-10);
  return 1;
        }

canticle_of_darkness(str)  {
if(str == "darken")  {
if(spell(-155,6,30) ==-1) return 0;
move_object(clone_object("/players/saber/closed/bards/dark.c"),environment(this_player()));
tell_room(environment(this_player()), "A cloud of darkness covers the room as "+tp+" plays a canticle.\n");
   call_other(TP,"add_spell_point",-30);
  return 1;
        }
        }

chord_of_distortion()  {
if(spell(-111,4,20) ==-1) return 0;
  if(present("illusion_cloak",environment(TO)))  {
  write("You already have cast the spell.\n");
  return 1;
        }
move_object(clone_object("/players/saber/closed/bards/ill_shield.c"),TP);
write("You cloak yourself in illusion as you play a series of chords\n"+
   "upon your "+TO->query_instrument()+".\n");
say(tp+" cloaks "+TP->query_objective()+"self in illusion as "+TP->query_pronoun()+"\n"+
   "plays some chords upon "+TP->query_possessive()+" "+TO->query_instrument()+".\n");
   command("wear illusion_cloak",TP);
   call_other(TP,"add_spell_point",-20);
   return 1;
        }

song_of_illusion(str)  {
object ob;
string target, temp, text;
  if(!str)  {
    write("Illusion <here/player name> <illusion text>\n");
    return 1;
        }
if(sscanf(str, "%s %s", temp, text) !=2)  {
    write("Illusion <here/player name> <illusion text>\n");
    return 1;
        }
if(spell(-194,7,40)  ==-1) return 0;
  if(temp == "here")  {
  move_object(clone_object("/players/saber/closed/bards/ill_obj.c"),environment(TP));
  ob = present("illusion",environment(TP));
  call_other(ob,"set_short",text);
  write("You sing a soft song.\n");
  write("You create an illusion:\n"+
    "* "+text+"\n");
  say(tp+" sings a soft song.\n");
  say("Something has changed.\n");
  call_other(TP,"add_spell_point",-40);
  return 1;
        }
  else {
  if(!find_player(temp))  {
    write("That player is not within the realm of magic.\n");
    return 1;
        }
  ob = find_player(temp);
  if(ob->query_level() > 20 && ob->query_name() != "Saber" || ob->query_invis() > 0) {
    write("You wouldn't want to do that.\n");
    return 1;
        }
  say(tp+" sings a soft song.\n");
  write("You sing a soft song as you send an illusion to "+capitalize(temp)+".\n"+
    "* "+text+"\n\n");
  tell_object(ob, "You see an illusion.\n\n");
  tell_object(ob, text+"\n\n");
  call_other(TP,"add_spell_point",-40);
  return 1;
        }
  write("Illusion <here/player name> <illusion text>\n");
  return 1;
        }

illusion_armor(str)  {
object armor;
string new_name, old_name, new_short, new_long, new_alias;

  if(!str || sscanf(str, "%s %s | %s | %s | %s", old_name, new_name, new_alias, new_short, new_long) < 5)  {
  write("Cover <armor name> <new name> | <nickname> | <appearance> | <detailed desc>\n");
  return 1;
        }

  armor = present(old_name,this_player());
  if(!present(old_name,this_player()))  {
    write("You must have the "+old_name+" to cover it with an illusion.\n");
    return 1;
        }

  if(armor->query_ac() != "0")  {

  if(spell(-111,5,25) ==-1)  return 0;

  armor->set_name(new_name);
  armor->set_alias(new_alias);
  armor->set_short(new_short);
  armor->set_long(new_long+"\n");

  write("You cover the "+capitalize(old_name)+" in illusion.\n"+
    "It now appears as '"+new_short+"'\n");
  say(tp+" changes "+TP->query_possessive()+" "+capitalize(old_name)+" into a "+capitalize(new_name)+".\n");

  call_other(TP, "add_spell_point", -25);
  return 1;
        }
  write("That is not armor!\n");
  return 1;
        }
