#include "scar.h"
#include "color.h"
#define user this_player()
#define RN this_player()->query_name()
#define SCAR (present("bloodscar", this_player()))
#define capname capitalize(this_player()->query_name())

id(str) { return str == "object"; }
short() { return "The scar's Master object"; }
long() { write("This machine runs my Mortal Kombat scar..Do NOT clone it.\n"); }
reset(arg) {
  return;
}

infoscar() {
   write("\n");
   write("================================================================================\n");
   write("\tSPELL\t\t\tFUNCTION\t\t\tCOST\n");
   write("================================================================================\n");
   write("bdt\t\t\tBlood tell to members\t\t\t  --\n");
   write("bbe\t\t\tBlood emote to members\t\t\t  --\n");
   write("bts\t\t\tBlood tell silence\t\t\t  --\n");
   write("stats\t\t\tSee the stats of members\t\t  --\n");
   write("new_scar\t\tGet a new scar\t\t\t\t  --\n");
   write("restore_me\t\tRestore your kill stats\t\t\t  --\n");
   write("save_me\t\t\tSave your kill stats\t\t\t  --\n");
   write("infokills\t\tInformation on stats\t\t\t  --\n");
   write("heal_scar\t\tGet rid of your scar\t\t\t  --\n");
   write("ppl\t\t\tSee pkers and wastelanders on\t\t  --\n");
   write("setkills <#>\t\tFor level 21+ only\t\t\t  --\n");
   write("check_log\t\tRead the give_scar log file\t\t  --\n");
   write("punt <name>\t\tDrop kick someone\t\t\t  --\n");
   write("mtell p1,p2,p3 <msg>\tTell to multiple players\t\t  1 * n\n");
   write("reply\t\t\tReply to an mtell\t\t\t  --\n");
   write("===============================================================================\n");
   return 1;
}

infokills() {
   write("\t\t\t\tKILLS\n"+
"You can gain a kill whenever you kill another player.  This can\n"+
"be done by killing someone while pking, in a pk area, or by\n"+
"challenging another champion to a fight.  To challenge another\n"+
"champion, type deathmatch <playername>.  They have to agree to the\n"+
"fight and have the option of turning you down.  When in a fight,\n"+
"you are moved to the arena where you will fight to the death.  This\n"+
"isn't as bad as it seems however, because you will lose no exps for\n"+
"being killed.  You only have to type 'pray' in the arena to get your\n"+
"exps back.  You will lose one stat however, this is the price you\n"+
"have to pay.\n"+
"\t\t\t\tDeaths\n"+
"You will get a death when you are killed by a player.  If you get\n"+
"killed by someone without the scar, you will not gain a death\n"+
"since Boltar has removed the shadow command and I'm not able to do\n"+
"so.  However, I hope that anyone that has interest in pk will\n"+
"have a scar.\n"+
"\t\t\t\tRank\n"+
"The idea of rank is fairly simple.  It adds your level, your extra\n"+
"level and your amount of kills together.  Rank is a way that players\n"+
"can put themselves above other champions.  Being a high ranking\n"+
"champion is a great feat; only only the best will be of high ranks\n"+
"amoung you.  May the glory of victory be on your side...\n");
   return 1;
}

bbe(str) {
   if (!str) {
      notify_fail("Emote what to blood brothers?\n");
      return 0;
   }
   CHANNELD->broadcast(RED+"<< >>"+RESET+": " + capitalize(RN) +
		       " " + str + "\n", 0, CHANNAME);
   return 1;
}

bdt(str) {
   if (!str) {
      notify_fail("Tell blood brothers what?\n");
      return 0;
   }
   CHANNELD->broadcast(RED+"<<"+CYA+ capitalize(RN) +
		       RED+">>"+RESET+": " + str + "\n", 0, CHANNAME);
   return 1;
}

mtell( str ) {
    /* Dragnar/John 11/5/98
    *  A multiple tell that allows players to tell to more than
    *  one object at a time.  explode is used to split the list of
    *  tell objects into an array of strings.  Currently, no
    *  restrictions on the number of tells, and no check for
    *  'spamming' a single person with multiple tells.
    *
    *
    *  Dragnar/John 11/23/98
    *  Fixed the spamming problem with member_array to ensure that
    *  a player is only in the tell_list 1 time.
	*
	*  Dragnar/John 3/23/99
	*  Changed some formatting of the who variable, added checks from
	*  the player.c tell command like invis check, etc.
    */

    string *tell_list;
    string *who_list;
    object tellee;
    string what, wholist, who;
    int i,j;

    if(user->query_invis() > 0 && user->query_level() < 40) {
        write("Don't be annoying.  Become visible before you talk to someone!\n");
        return 1;
    }
	if( user->query_ghost() ) {
        write("In your current state that is impossible.\n");
	    return 1;
    }
    if( user->query_spell_point() < 10 ) {
	    write("You are low on power.\n");
         return 1;
    }
    if( !str || sscanf(str, "%s %s",who,what) != 2 ) {
        write("Usage: mtell player1,player2,player3 <message>\n");
        return 1;
    }
    what = "\""+what+"\"";
    tell_list = explode( who, "," );
    if( sizeof(tell_list) > 10 ) {
        write("You can't tell to more than ten people.\n");
        return 1;
    }
    who_list = allocate(sizeof(tell_list));
    who = 0;
    for( i = 0, j = 0; i < sizeof(tell_list); i++ ) {
        tell_list[i] = lower_case(tell_list[i]);
        tellee = find_player( tell_list[i] );
        if(!tellee) tellee=find_living( tell_list[i] );
        if(!tellee || user->query_level() < tellee->query_level() &&
		  tellee->query_invis() >= 39) {
            write(capitalize(tell_list[i]) +" is not logged on.\n");
        }
        else if(!tellee->query_interactive() && !tellee->query_npc()) {
            write(capitalize(tell_list[i])+" is disconnected.\n");
        }
        else if( user->query_level() < 100 && in_editor(tellee) ) {
            write(capitalize(tell_list[i])+" is editing.  Try again later.\n");
        }
        else {
            if( tellee->query_player() ) {
            if(query_idle(tellee) > 120) {
                write("Warning: "+capitalize(tell_list[i])+" is idle.\n");
            }
            }
            if ( who == 0 ) {
                who = capitalize( tell_list[i] );
				who_list[j] = tell_list[i];
            	j++;
            }
            else {
                if( member_array(tell_list[i],who_list) == -1 ) {
                    who = who + ", " + capitalize(tell_list[i]);
					who_list[j] = tell_list[i];
            		j++;
                }
			}
        }
    }
	for( i = 0; i < j; i++ ) {
        tellee = find_player( who_list[i] );
        if( !tellee ) tellee = find_living( who_list[i] );
        if( tellee ) {
            if( j == 1 ) {
                wholist = "you";
            }
            else {
                wholist = who;
            }
        tell_object_wblock(tellee, capname+" tells "+wholist+": "+what+"\n");
		tellee->add_tellhistory(capname+" tells you: " + what);
        set_reply( tellee->query_name(), this_player()->query_name(), who_list );
		}
	}
    if (who) {
        write("You tell " +(who)+ ": " +what+ "\n");
    }
    if(user->query_level() < 20 ) {
        this_player()->add_spell_point( -1 * j );
     }
    return 1;
}

void set_reply( string receiver, string sender, string *who ) {
    /* Sets the _reply in scar.c and allows player to reply to
    *  a list of people from an mtell.  
    *  Dragnar/John 3/22/99
    */

    object ob;
    string who_list, temp_who, tellee, teller;
     int i;

    tellee = lower_case( receiver );
    teller = lower_case( sender );
    ob = present("bloodscar", find_living( lower_case( tellee ) ) );
    if( !ob ) {
        return;
    }
    else {
        for( i = 0; i < sizeof(who); i++ ) {
            temp_who = lower_case( who[i] );
            if( temp_who == tellee )
               temp_who = teller;
                if( !who_list ) {
                    who_list = temp_who;
                }
                else {
                    who_list = who_list + "," + temp_who;
                }
        }
        ob->set_reply_list( who_list );
        return;
    }
}

int punt( string str ) {
  object who;
  string whon, poss;
  int distance;

  if( !str ) {
    write("Who do you want to punt?\n");
    return 1;
  }

  whon = capitalize( str );
  if(!present(str, environment(this_player()))) {
    write(whon+" is not here.\n");
    return 1;
  }
  who = find_living( str );
  if( !who ) {
    write("You can't punt that!\n");
    return 1;
  }

  poss = (string) who->query_pronoun();
  distance = random(50);
  if(user->query_level() > 20 )
    distance = random(55) + 30;

  if( distance > 0 ) {
    write("You punt "+whon+" "+distance+" yards.");
    say(RN+" punts "+whon+" "+distance+" yards. ");
  }

  switch( distance ) {
  case 0:
    write("You try to punt "+whon+" but "+poss+" deftly moves out of the way!\n");
    say(RN+" tries to punt "+whon+" but "+poss+" deftly moves out of the way!\n");
    say(RN+" lands on the ground with a thud.\n");
    break;
  case 1 .. 25:
    write(" What a squib kick!\n");
    say(" What a squib kick! \n");
    break;
  case 26 .. 39:
    write(" A decent kick.\n");
    say(" A decent kick. \n");
    break;
  default:
    write(" Damn, you booted "+whon+"'s ass!\n");
    say(RN+" booted "+whon+"'s butt!\n");
    break;
  }
  return 1;

}
tell_scar(killer, victim) {
   if (!killer || !victim) {
      killer = this_player()->query_real_name();
      victim = ((string) previous_object()->query_checker() || "Nobody");
   }
   killer = capitalize(killer);
   victim = capitalize(victim);
   CHANNELD->broadcast(
	"<<"+RED+"Angel of Death"+RESET+">>: " + killer + " has killed " +
	victim + ".\n",
	1, CHANNAME);
   write_file("/players/dragnar/KILLS.log", "Worked!\n");
   return 1;
}

bts(str) {
   int muffled;

   muffled = SCAR->query_muffled();
    if(!str) {
        if ( muffled ) {
            previous_object()->set_muffled(0);
            write("You are now on the MK channel.\n");
            return 1;
        }
        else {
            previous_object()->set_muffled(1);
            write("You are now muffled.\n");
            return 1;
        }
    }
   if (str == "on") {
      write("You are now muffled.\n");
      return 1;
   }
   if (str == "off") {
      previous_object()->set_muffled(0);
      write("You are now on the blood channel.\n");
      return 1;
   }
   write("Usage: bts <on/off>\n");
   return 1;
}

stats() {
   object *scars, scar, blood;
   int i, mylevel, level, pkills, xlevel, pdeaths, color;
   string name;

   mylevel = (int) this_player()->query_level();
   scars = (object *) CHANNELD->users(CHANNAME);
   if (color = (int) previous_object()->toggle_ansi(0)) write(GRE);
   write("\n================================================================================\n");
   write("NAME:\t\tRANK:\tLEVEL:\tEX_LEV:\tKILLS:\tDEATHS:\tMUFFS:\n");
   write("================================================================================\n");
   if (color) write(NOSTYLE);
   for (i = 0; i < sizeof(scars); i++) {
      scar = scars[i];
      if (!scar || !(blood = environment(scar))) continue;
      if (blood->query_invis()) continue;

      name = capitalize(blood->query_real_name());
      level = blood->query_level();
      xlevel = blood->query_extra_level();
      pkills = scar->query_pkills();
      pdeaths = scar->query_pdeaths();

      if (!blood->query_interactive()) name = "(" + name + ")";
      write(name);
      if (strlen(name) > 7) write("\t"); else write("\t\t");
      if (level < 20) write(level + xlevel + pkills + "\t");
      else if( name != "Dragnar" && name != "Balowski" ) write("1000\t");
      else write("5000\t");

      write(level + "\t" + xlevel + "\t" + pkills + "\t" + pdeaths + "\t");
      if (scar->query_muffled()) write("Yes\n"); else write("No\n");
   }
   if (color) write(GRE);
   write("================================================================================\n");
   if (color) write(NOSTYLE);
   return 1;
}

heal_scar() {
   write("You mumble some magic words and your scar slowly fades away.\n");
   destruct(previous_object());
   return 1;
}

deathmatch(str) {
   object ob, fightob;
   object target;

   if (!str) {
      write("Who do you wish to fight?\n");
      return 1;
   }
   /* added by mizan */
   if (this_player()->query_ghost()) {
      write("You're dead, you moron.\n");
      return 1;
   }
   target = present(str, environment(this_player()));
   if (!target) {
      write(capitalize(str) + " is not here.\n");
      return 1;
   }
   /* also added by mizan */
   if (target->query_ghost()) {
      write("That player is dead.\n");
      return 1;
   }
   if (target == this_player()) {
      write("A great warrior like you wants to fight yourself?  How weak.\n");
      return 1;
   }
   if (!interactive(target)) {
      write("You can only fight players.\n");
      return 1;
   }
   if (!present("bloodscar", target)) {
      write("You can only fight Champions.\n");
      return 1;
   }
   if (this_player()->query_spell_point() < 50){
      write("You don't have enought spell points.\n");
      return 1;
   }
   this_player()->add_spell_point(-50);
   fightob = clone_object("/players/dragnar/closed/fightob");
   move_object(fightob, target);
   fightob->set_owner(this_player());
   write("You have asked " + capitalize(str) + " to fight to the death!\n");
   tell_object(target, capitalize(this_player()->query_real_name()) +
	" wishes to fight you to the death.\n" +
	"If you wish to fight them type 'accept fight'.  If you don't want to\n" +
	"fight " + this_player()->query_objective() + " them type 'decline fight'.\n");
   return 1;
}


ppl() {
   int i, no, color;
   object *list;

   list = users();
   if (color = (int) previous_object()->toggle_ansi(0)) write(GRE);
   write("\n");
    write("   Name:\tLevel:\tGuild:\tGender:\tLocation:\n");
   write("[------------------------------------------------------------------------------]\n");
   if (color) write(NOSTYLE);
   for (i = 0, no = 0; i < sizeof(list); i++) {
    if(list[i]->query_invis()) continue;

      if (!(list[i]->query_pl_k() && list[i]->query_level() < 20) &&
    !(environment(list[i]) && list[i]->query_fight_area() &&
    list[i]->query_level() < 20) )
	 continue;

      write(++no + ". ");
      write(list[i]->query_name());

      if (no < 10)
	 if (strlen(list[i]->query_name()) > 4)
	    write("\t");
	 else
	    write("\t\t");
      else
	 if (strlen(list[i]->query_name()) > 3)
	    write("\t");
	 else
	    write("\t\t");

      if (list[i]->query_pl_k())
	 write(list[i]->query_level() + "*\t");
      else
	 write(list[i]->query_level() + "\t");

      if (!list[i]->query_guild_name())
    write("None\t");
    else {
    write(extract(list[i]->query_guild_name(),0,6));
    write("\t");
    }

      if (list[i]->query_gender() == "male") write("   M\t");
      else if (list[i]->query_gender() == "female") write("   F\t");
      else if (list[i]->query_gender() == "creature") write("   C\t");

      if (!environment(list[i])) write("Logging In");
    else write(extract(environment(list[i])->short(), 0,39));
      write("\n");
   }
   if (color) write(GRE);
   write("[------------------------------------------------------------------------------]\n");
   if (color) write(NOSTYLE);
   return 1;
}

give_scar(str) {
   int kills;
   object who,scar;

   if (!str) return 0;
   if( this_player()->query_real_name() != "dragnar" ) {
  write("Because there has been several accounts of abuse and complaints\n"+
    "this command has been removed temporarily.\n\t\t\t-The Managment  <3-13-1998>\n");
return 1;
    }

   kills = previous_object()->query_pkills();
   if (user->query_level() < 21 &&
       (kills + user->query_level() + user->query_extra_level() < 200)) {
      write("You are NOT allowed to do that.\n");
      return 1;
   }

   who = find_player(lower_case(str));
   if (!who) {
      write("I could not find " + capitalize(str) + " on the mud.\n");
      return 1;
   }

   write_file(LOGFILE, ctime() + " " + capitalize(RN) + " gave " +
		       capitalize(str) + " a scar.\n");
   scar = clone_object(SCAROBJ);
   move_object(scar, who);

   tell_object(who, this_player()->query_real_name() +
		    " has given you a Blood Scar.\n");
   write("Logging your command...\n");
   return 1;
}

set_kills(str) {
   int ks;
   if (this_player()->query_level() < 21) {
      write("You have to earn your kills.\n");
      return 1;
   }
   sscanf(str, "%d", ks);
   previous_object()->set_pkills(ks);
   command("save_me", this_player());
   command("restore_me", this_player());
   write("You now have " + ks + " kills set.\n");
   return 1;
}

new_scar(str) {
   object scar;

   write_file(LOGFILE, ctime() + " " + capitalize(RN) +
		       " did new_scar.  Reason: " + str + ".\n");
   write("Resetting scar...\n");
   destruct(previous_object());
   scar = clone_object(SCAROBJ);
   move_object(scar, this_player());
   return 1;
}

check_log() {
   tail(LOGFILE);
   return 1;
}


scaransi() {
    if (previous_object()->toggle_ansi(1)) {
	add_attribute("ansi", this_player());
	write("Bloodscar ANSI colour is now ON.\n");
    }
    else {
	delete_attribute("ansi", this_player());
	write("Colour is now OFF.\n");
    }
   return 1;
}

status
boot_blood()
{
    int i;
    object *all, ob;

    if (this_player()->query_level() < 50) return 0;
    i = sizeof(all = users());
    while (i--) {
       if (ob = present("bloodscar", all[i]))
	  CHANNELD->register(ob, CHANNAME);
       if (ob = present("shardak_mark", all[i]))
	  CHANNELD->register(ob);
       else if (ob = present("ally_mark", all[i]))
	  CHANNELD->register(ob);
    }
    return 1;
}
