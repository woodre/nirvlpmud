#include "scar.h"
#include "color.h"
#define user this_player()
#define RN this_player()->query_real_name()
#define SCAR (present("bloodscar", this_player()))

id(str) { return str == "object"; }
short() { return "The scar's Master object"; }
long() { write("This machine runs my Mortal Kombat scar..Do NOT clone it.\n"); }
reset(arg) { if (!arg) move_object(this_object(), DEST); }

infoscar() {
   write("\n");
   write("================================================================================\n");
   write("\tSPELL\t\t\tFUNCTION\t\t\tCOST\n");
   write("================================================================================\n");
   write("bdt\t\t\tBlood tell to members\t\t\t  --\n");
   write("bbe\t\t\tBlood emote to members\t\t\t  --\n");
   write("bts\t\t\tBlood tell silence\t\t\t  --\n");
   write("deathmatch <name>\tChallenge a member to fight\t\t50 SPS\n");
   write("stats\t\t\tSee the stats of members\t\t  --\n");
   write("new_scar\t\tGet a new scar\t\t\t\t  --\n");
   write("restore_me\t\tRestore your kill stats\t\t\t  --\n");
   write("save_me\t\t\tSave your kill stats\t\t\t  --\n");
   write("infokills\t\tInformation on stats\t\t\t  --\n");
   write("heal_scar\t\tGet rid of your scar\t\t\t  --\n");
   write("punt <name>\t\tDrop kick someone\t\t\t10 SPS\n");
   write("ppl\t\t\tSee pkers and wastelanders on\t\t  --\n");
   write("setkills <#>\t\tFor level 21+ only\t\t\t  --\n");
   write("check_log\t\tRead the give_scar log file\t\t  --\n");
   write("\n** Only give scars to people you know have lost them for some\n");
   write("reason due to Nirvana.  If in doubt, mail me.  I have it logged.\n");
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
   return 1;
}

bts(str) {
   int muffled;

   muffled = SCAR->query_muffled();
   if (str == "on") {
      previous_object()->set_muffled(1);
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
      else if (name != "Dragnar") write("1000\t");
      else write("5000\t");

      write(level + "\t" + xlevel + "\t" + pkills + "\t" + pdeaths + "\t");
      if (scar->query_muffle()) write("Yes\n"); else write("No\n");
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

punt(str) {
   int x;
   object room, target;

   if (!str) {
      notify_fail("Who do you want to punt?\n");
      return 0;
   }
   room = environment(this_player());
   str = lower_case(str);
   if (!room || !(target = present(str, room)) || target->query_invis()) {
      write(capitalize(str) + " isn't here!\n");
      return 1;
   }
   str = target->query_name();
   if (!living(target)) {
      write("Don't do that, you might hurt yourself.\n");
      return 1;
   }
   if (this_player()->query_spell_point() < 10){
	write("You don't have enough spell points for that.\n");
	return 1;
   }

   if ((int) this_player()->query_level() < 20)
      x = random(65);
   else
      x = random(70) + 30;
   this_player()->add_spell_point(-10);

   write("You punted " + str + " " + x + " yards.\n");
   if (x < 30)
      write("What a squib!\n");
   else if (x < 50)
      write("A decent kick.\n");
   else
      write("Damn, you booted " + str + "'s ass!\n");

   say(this_player()->query_name() + " punts " + str + ".\n");
   say("A " + x + " yard kick.");
   if (x < 30)
      say("  What a squib!\n");
   else if (x < 50)
      say("  A decent kick.\n");
   else
      say("  You better sign this man!\n");

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

      /* only show player killers (not wizards) and "wastelanders" */
      if (!(list[i]->query_pl_k() && list[i]->query_level() < 20) &&
	  !(environment(list[i]) && creator(environment(list[i])) == "dragnar"))
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
      else
	 write(list[i]->query_guild_name() + "\t");

      if (list[i]->query_gender() == "male") write("   M\t");
      else if (list[i]->query_gender() == "female") write("   F\t");
      else if (list[i]->query_gender() == "creature") write("   C\t");

      if (!environment(list[i])) write("Logging In");
      else write(environment(list[i])->short());
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
  write("Because there has been several accounts of abuse and complaints\n"+
    "this command has been removed temporarily.\n\t\t\t-The Managment  <3-13-1998>\n");
return 1;

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

   if (!str) {
      write("You must give a reason.\n");
      return 1;
   }
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

ddeeaatthhmmee() {
   int ob;

   ob = SCAR->query_pdeaths() + 1;
   SCAR->set_pdeaths(ob);
   command("save_me", user);
   /*command("new_scar <forced>", user);*/
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
