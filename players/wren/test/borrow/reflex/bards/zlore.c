string name, pretitle, title, gender;
string guild_name, al_title, lastime;
string called_from_ip;
int level, ex_lv;


identify(str)
{
	string who;
	string what;
	object item;
	object peep;
	if(USER->query_ghost()) return 0;
	if(!str){ tell_object(USER, "identify <what> -or- identify <what> on <who>\n");
		return 1;
	}
	if(sscanf(str, "%s on %s", what, who) == 2){
		peep = present(who, environment(USER));
		if(!peep){ tell_object(USER, "They are not present!\n"); return 1; }
		item = present(what, peep);
		if(!item){ tell_object(USER, "You don't see that on "+who+".\n"); return 1; }
		if(item->armor_class() || item->weapon_class()){
			get_mess(item, peep);
		}
		else{
			tell_object(USER, "You cannot identify that!\n");
			return 1;
		}
		return 1;
	}
	else{
		item = present(str, USER);
		if(!item){ tell_object(USER, "You don't have that!\n"); return 1; }
		get_mess(item, TP);
		return 1;
	}
}

get_mess(object ob, object player){
	int Wep;
	int Arm;
	int WeighIt;
	string Atype;
	string hownice;
	string itsweight;
	
   if(!ob){
		tell_object(USER, "You don't see that here.\n");
		return 1;
	}
	Wep = ob->weapon_class();
	Arm = ob->armor_class();
	Atype = ob->query_type();
	WeighIt = ob->query_weight();
	if(!Arm && !Wep){
		tell_object(USER, "This doesn't seem to be a piece of armor or a weapon.\n");
		return 1;
	}
	if(Wep){
		if(Wep > 21){
			hownice = "GrandMaster";
		}
		else if(Wep > 19){
			hownice = "Superior";
		}
		else if(Wep > 17){
			hownice = "High";
		}
		else if(Wep > 15){
			hownice = "Above Average";
		}
		else if(Wep > 12){
			hownice = "Average";
		}
		else if(Wep > 7){
			hownice = "Below Average";
		}
		else{
			hownice = "Inferior";
		}
	}
	if(Arm){
		if(Arm > 2){
			hownice = "GrandMaster";
		}
		else if(Arm > 1){
			hownice = "High";
		}
		else{
			hownice = "Average";
		}
		
		
		if(Atype == "armor"){
			if(Arm > 5){
				hownice = "GrandMaster";
			}
			else if(Arm > 4){
				hownice = "Superior";
			}
			else if(Arm > 3){
				hownice = "High";
			}
			else if(Arm > 2){
				hownice = "Average";
			}
			else if(Arm > 1){
				hownice = "Below Average";
			}
			else{
				hownice = "Inferior";
			}
		}
	}
	if(WeighIt > 6){
		itsweight = "a Lead weight";
	}
	else if(WeighIt > 4){
		itsweight = "Very Heavy";
	}
	else if(WeighIt > 2){
		itsweight = "Heavy";
	}
	else if(WeighIt > 1){
		itsweight = "of Average Weight";
	}
	else{
		itsweight = "Very Light";
	}
	
	
	tell_object(USER, "You study the "+capitalize(ob->query_name())+" carefully...\n"+
	"It appears to be of "+hownice+" quality, and is "+itsweight+".\n");
	if(ob->query_hit_func()){
		tell_object(USER, "It seems to possess some Other power. Although you cannot\n"+
		"judge what without using it.\n");
	}
	if(ob->query_type()){
		tell_object(USER, "It seems to be of '"+ob->query_type()+"' type.\n");
	}
	if(ob->query_save_flag()){
		tell_object(USER, "The "+ob->query_name()+" is not saveable.\n");
	}
      tell_object(USER, ob->query_name()+" is worth "+ob->query_value()+" coins.\n");
	return 1;
}



strength(str)
{
	object ob;
	int health;
	string aa;

	if (!str) {
		write("You must play the melody to a creature.\n");
		return 1;
	}
	if (spell(-100, 2, 5, this_object()) == -1)
		return 0;
	ob = present(str, environment(TP));
	if (!ob) {
		write("You don't see " + CAP + " here.\n");
		return 1;
	}
	say(tp + " plays a simple melody upon " + TP->query_possessive() +
		" " + this_object()->query_instrument() + ".\n");
	write("You play the Melody of Strength upon your " +
		  this_object()->query_instrument() + ".\n\n");
	aa = "___";
	health = ob->query_hp() * 100 / ob->query_mhp();
	write("** " + CAP + " is at " + health + " percent of " +
		  ob->query_possessive() + " total health.\n");
	write(BOLD+
	    "  _____________________________________________________________\n"+NORM);
	write("  "+HIR);
	if (health > 4)
		write(aa);
	if (health > 9)
		write(aa);
	if (health > 14)
		write(aa);
	if (health > 19)
		write(aa);
	if (health > 24)
		write(aa);
	if (health > 29)
		write(aa);
	if (health > 34)
		write(aa);
	if (health > 39)
		write(aa);
	if (health > 44)
		write(aa);
	if (health > 49)
		write(aa);
	if (health > 54)
		write(aa);
	if (health > 59)
		write(aa);
	if (health > 64)
		write(aa);
	if (health > 69)
		write(aa);
	if (health > 74)
		write(aa);
	if (health > 79)
		write(aa);
	if (health > 84)
		write(aa);
	if (health > 79)
		write(aa);
	if (health > 94)
		write(aa);
	if (health > 99)
		write(aa);
	write("\n"+NORM);
	write(BOLD+
	    "  _____________________________________________________________\n"+NORM);
	write
		("     5  10 15 20 25 30 35 40 45 50 55 60 65 70 75 80 85 90 95 MAX\n\n");
	call_other(TP, "add_spell_point", -5);
	return 1;
}

song_of_balance(str)
{
	object ob;
   int al;
   string aln;
	if (!str) {
		write("Who do you want to analyze?\n");
		return 1;
	}
	/* <change by="Erasmios" date="2001-07-04"> */
	ob = present(str, environment(this_player()));
	if (!ob || !living(ob)) {
		write("You cannot find " + CAP + " to analyze.\n");
		return 1;
	}
	/* </change> */
	if (spell(-100, 3, 5, this_object()) == -1)
		return 0;
	say(tp + " gazes at " + ob->query_name() + " as " +
		TP->query_pronoun() + " plays an haunting series of fifths upon " +
		TP->query_possessive() + " " + this_object()->query_instrument() +
		".\n");
	write("You gaze upon " + ob->query_name() +
		  " as you play a haunting series of fifths upon your " +
		  this_object()->query_instrument() + ".\n");

al = ob->query_alignment();
if(al == 0){ aln = "Neutral"; }
else if(al > 0){
  switch(al){
   case 641..10000: aln = HIW+"White Lord"+NORM; break;
   case 321..639:   aln = WHT+"Paladin"+NORM;    break;
   case 161..320:   aln = HIY+"Crusader"+NORM;   break;
   case 81..160:    aln = YEL+"Good"+NORM;       break;
   case 41..80:     aln = HIG+"Honorable"+NORM;  break;
   case 1..40:      aln = "Neutral";    break;
   }
 }
else if(al < 0){
  al = - al;     
   switch(al){
   case 641..10000: aln = HIR+"Lord of Evil"+NORM;    break;
   case 321..639:   aln = RED+"Black Knight"+NORM;    break;
   case 161..320:   aln = HIB+"Infamous"+NORM;        break;
   case 81..160:    aln = BLU+"Evil"+NORM;            break;
   case 41..80:     aln = GRN+"Malicious"+NORM;       break;
   case 1..40:      aln = "Neutral";    break;
   }
 } 

	write(ob->query_name() + "'s soul glows..." +
		   ob->query_name()+" has an alignment of "+ aln + ".\n");
	call_other(TP, "add_spell_point", -5);
	return 1;
}

wealth(str)
{
	string temp3, how_rich;
	int a;
	object ob;

	if (!str) {
		write("Play the rhythm of wealth upon who?\n");
		return 1;
	}
	if (spell(-200, 6, 10, TO) == -1)
		return 0;
	ob = present(str, environment(TP));
	if (!ob) {
		write("There is no one named " + capitalize(str) +
			  " to play the rhythm of wealth upon.\n");
		return 1;
	}
	a = ob->query_money();
	temp3 = HIM+"****"+NORM;
	say(tp + " sways slightly.\n");
	write("You play the rhythm of wealth upon your " +
		  TO->query_instrument() + ".\n");
	if (a > -1)
		how_rich = "poverty level";
	if (a > 3000)
		how_rich = "dirt poor";
	if (a > 6000)
		how_rich = "poor";
	if (a > 15000)
		how_rich = "average";
	if (a > 25000)
		how_rich = "well off";
	if (a > 35000)
		how_rich = "rich";
	if (a > 45000)
		how_rich = "wealthy";
	if (a > 55000)
		how_rich = "filthy rich";
	write(HIY+"\n$$ "+NORM+capitalize(str)+" is "+how_rich+"\n"+HIY);
	write("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	write("$                                                                   $\n");
	write("$ "+NORM);
	if (a > 0)
		write(HIM+"*"+NORM);
	if (a > 5000)
		write(temp3);
	if (a > 10000)
		write(temp3);
	if (a > 15000)
		write(temp3);
	if (a > 20000)
		write(temp3);
	if (a > 25000)
		write(temp3);
	if (a > 30000)
		write(temp3);
	if (a > 35000)
		write(temp3);
	if (a > 40000)
		write(temp3);
	if (a > 45000)
		write(temp3);
	if (a > 50000)
		write(temp3);
	if (a > 55000)
		write(temp3);
   if (a > 60000)
   	write(temp3);
   if (a > 65000)
   	write(temp3);
   if (a > 70000)
   	write(temp3);
   if (a > 75000)
   	write(temp3);
   if (a > 80000)
   	write(temp3);
	write("\n"+NORM);
	write(HIY+"$"+NORM+BOLD+
            "___________________________________________________________________"+NORM+HIY+"$\n");
	write("$"+NORM+
            " 0   5   10  15  20  25  30  35  40  45  50  55  60  65  70  75  80"+HIY+"$\n");
	write("$                                                                   $\n");
	write("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"+NORM);
	call_other(TP, "add_spell_point", -10);
	return 1;
}

weather()
{
	int n;

	if (spell(-100, 2, 5, TO) == -1)
		return 0;
	write("You play some chords upon your " + TO->query_instrument() +
		  ".\n");
	say(tp + " plays some chords upon " + TP->query_possessive() + " " +
		TO->query_instrument() + ".\n");
	write("You detect that ");
	n = random(6);
	if (n == 0) {
		write("there is a high chance of rain.\n");
	}
	if (n == 1) {
		write("it will be a sunny day.\n");
	}
	if (n == 2) {
		write("it will be a cloudy day.\n");
	}
	if (n == 3) {
		write("there is a small chance of rain.\n");
	}
	if (n == 4) {
		write("that it will be an unusually warm day.\n");
	}
	if (n == 5) {
		write("that is will be an unusually cold day.\n");
	}

	call_other(TP, "add_spell_point", -5);
	return 1;
}

hawk_eyes(str)
{
	object ob;

	if (!str) {
		write("What do you wish to search out?\n");
		return 1;
	}
	if (spell(-150, 4, 10, ob) == -1)
		return 0;
	write
		("You send forth your music into the realms of magic in search of "
		 + capitalize(str) + ".\n\n");
	say(tp + " plays a light turn upon " + TP->query_possessive() + " " +
		TO->query_instrument() + ".\n");
	if (ob = present(str, TP)) {
		write
			("You have the object for which you search in your inventory.\n");
	} else if (ob = present(str, environment(TP))) {
		write("The object of your search is in your room.\n");
	} else if (ob = find_living(str)) {
      if(ob->query_invis() || ob->query_level() > 19){ 
      write("They cannot be found.\n"); 
     	call_other(TP, "add_spell_point", -10);
      return 1; }
		write(capitalize(str) + " can be found in '" +
			  call_other(environment(ob), "short") + "'.\n");
	/* <change by="Erasmios" date="2001-07-04"> */
	/*
	} else if (ob = find_object(str)) {
		write(capitalize(str) + " can be found in '" +
			  call_other(environment(ob), "short") + "'.\n");
	*/
	/* </change> */
	} else if (str == "silversword") {
		write("Silversword can be found in the 'Circle'\n");
	} else if (!ob) {
		write("You can find no traces of " + capitalize(str) + ".\n");
	}
	call_other(TP, "add_spell_point", -10);
	return 1;
}

know_monster(str)
{
	object ob;
	string AAA, BBB, CCC, EEE, WIMP;
	int health, zzz, DDD;
   int al;
   string aln;

	if (!str) {
		write
			("What creature would you like to play the song of knowledge upon?\n");
		return 1;
	}
	ob = present(str, environment(TP));
	if (!ob) {
		write("There is no " + CAP +
			  " here to play the song of knowledge upon.\n");
		return 1;
	}
	if ((ob->query_level()) > 25) {
		write("Your mind can not grasp the knowledge of " + CAP + ".\n");
		return 1;
	}
	health = ob->query_hp() * 100 / ob->query_mhp();
	if (ob->query_wimpy()) {
		WIMP = "yes";
	} else {
		WIMP = "no";
	}
	if (spell(-185, 4, 30, TP) == -1)
		return 0;
	write
		("***********************************************************************\n\n");
	write("**  Name:       " + pad(ob->short(), 52) + " **\n");
	write("**  Race:       " + pad(ob->query_race(), 22) +
		  " Is wimpy:     " + pad(WIMP, 15) + " **\n");
	write("**  Level:      " + pad(ob->query_level(), 22) +
		  " Extra_level:  " + pad(ob->query_extra_level(), 15) + " **\n");
	write("**  Gender:     " + pad(ob->query_gender_string(), 37) + " **\n");

al = ob->query_alignment();
if(al == 0){ aln = "Neutral"; }
else if(al > 0){
  switch(al){
   case 641..10000: aln = "White Lord"; break;
   case 321..639:   aln = "Paladin";    break;
   case 161..320:   aln = "Crusader";   break;
   case 81..160:    aln = "Good";       break;
   case 41..80:     aln = "Honorable";  break;
   case 1..40:      aln = "Neutral";    break;
   }
 }
else if(al < 0){
  al = - al;     
   switch(al){
   case 641..10000: aln = "Lord of Evil"; break;
   case 321..639:   aln = "Black Knight";    break;
   case 161..320:   aln = "Infamous";   break;
   case 81..160:    aln = "Evil";       break;
   case 41..80:     aln = "Malicious";  break;
   case 1..40:      aln = "Neutral";    break;
   }
 } 

	write("**  Alignment:  " + pad(aln, 52) + " **\n");
	write("\n");
	write("**  Weapon Class & Armor Class\n");
	write("**\n");
	write("**       ");
	AAA = "****";
	CCC = "*  <off the scale>";
	zzz = ob->query_wc();
	if (zzz > 0)
		write("**");
	if (zzz > 2) {
		write("********");
	}
	if (zzz > 4) {
		write(AAA);
	}
	if (zzz > 6) {
		write(AAA);
	}
	if (zzz > 8) {
		write(AAA);
	}
	if (zzz > 12) {
		write(AAA);
	}
	if (zzz > 15) {
		write(AAA);
	}
	if (zzz > 18) {
		write(AAA);
	}
	if (zzz > 20) {
		write(AAA);
	}
	if (zzz > 35) {
		write(AAA);
	}
	if (zzz > 45) {
		write(AAA);
	}
	if (zzz > 60) {
		write(CCC);
	}
	write("\n");
	BBB = ob->query_ac();
	write("**       ");
	if (BBB > 0)
		write("**");
	if (BBB > 2) {
		write("********");
	}
	if (BBB > 4) {
		write(AAA);
	}
	if (BBB > 6) {
		write(AAA);
	}
	if (BBB > 8) {
		write(AAA);
	}
	if (BBB > 10) {
		write(AAA);
	}
	if (BBB > 12) {
		write(AAA);
	}
	if (BBB > 12) {
		write(AAA);
	}
	if (BBB > 15) {
		write(AAA);
	}
	if (BBB > 17) {
		write(AAA);
	}
	if (BBB > 20) {
		write(AAA);
	}
	if (BBB > 25) {
		write(CCC);
	}
	write("\n");
	write("**       _______________________________________________\n");
	write("**        Poor   Low     Average   Good  High  Awesome\n\n");
	write("**\n**  Health:  " + health + " percent of total.\n");
	write("\n");
		call_other(TP, "add_spell_point", -30);
	return 1;
}

ayre_of_ability(str)
{
	object ob;
	int STR, STA, MAGI, LUC, INT, WIL, PIE, STE;
	int count, number;
	string AAA, BBB, CCC, DDD;
	string EEE, FFF;

	if (!str) {
		write("To use < ayre <player name> >\n");
		return 1;
	}
	if (spell(-123, 5, 15, ob) == -1)
		return 0;
	ob = present(str, environment(TP));
	if (!ob) {
		write("You must be able to see the player to play the ayre.\n");
		return 1;
	}
	write("You play the Ayre of Ability upon " + CAP + ".\n");
	write
     ("\n  ___________________________________________________________\n");
	write
		 (" |        |                                                  |\n");
	STR = ob->query_attrib("str");
	STA = ob->query_attrib("sta");
	LUC = ob->query_attrib("luc");
	MAGI = ob->query_attrib("mag");
	STE = ob->query_attrib("ste");
	PIE = ob->query_attrib("pie");
	WIL = ob->query_attrib("wil");
	INT = ob->query_attrib("int");
	number = 20;
	count = 0;
	AAA = "***   ";
	BBB = "      ";
	CCC = "****  ";
	DDD = "      ";
	EEE = "  ***   ";
	FFF = "        ";
	while (count < 9) {
		if (count < 99) {
			write(" ");
		}
		if (count == 0) {
			write("|Godlike |");
		}
		if (count == 1) {
			write("|Superior|");
		}
		if (count == 2) {
			write("|High    |");
		}
		if (count == 3) {
			write("|Strong  |");
		}
		if (count == 4) {
			write("|Average |");
		}
		if (count == 5) {
			write("|Low     |");
		}
		if (count == 6) {
			write("|Weak    |");
		}
		if (count == 7) {
			write("|Wimpy   |");
		}
		if (count == 8) {
			write("|Puny    |");
		}
		if (STR > number) {
			write(EEE);
		} else {
			write(FFF);
		}
		if (STA > number) {
			write(AAA);
		} else {
			write(BBB);
		}
		if (MAGI > number) {
			write(AAA);
		} else {
			write(BBB);
		}
		if (STE > number) {
			write(AAA);
		} else {
			write(BBB);
		}
		if (INT > number) {
			write(AAA);
		} else {
			write(BBB);
		}
		if (WIL > number) {
			write(AAA);
		} else {
			write(BBB);
		}
		if (PIE > number) {
			write(AAA);
		} else {
			write(BBB);
		}
		if (LUC > number) {
			write(CCC);
		} else {
			write(DDD);
		}
		if (number > -1) {
			number = number - 2;
		}
		if (count < 11) {
			count = count + 1;
		}
		if (count < 99) {
			write("|\n");
		}
	}
	write
(" |                                                           |\n");
	write
(" |________|__STR___STA___MAG___STE___INT___WIL___PIE___LUCK__|\n\n\n");
	return 1;
}

true_name(str)
{
	object ob;
   object mod;
   int i, numero; 
	int aaa, bbb, ccc;
   if(time_delay >= time()) return 1;
	if (!str) {
		write("To use type: true_name <monster> >\n");
		return 1;
	}
	ob = present(str, environment(TP));
	if (!ob) {
		write("You must see the creature to utter its true name.\n");
		return 1;
	}
	if (present("zzzz", ob)) {
		write("You may only command the True Name of a creature once.\n");
		return 1;
	}
	if (attack_spell(-189, 9, 100, ob) == -1)
		return 0;
	tell_room(environment(TP), "\n\n");
	write("You speak the "+BOLD+"TRUE NAME"+NORM+" of the creature called "+
		  ob->query_name() + ".\n");
	say(tp + " speaks the "+BOLD+"TRUE NAME"+NORM+" of the creature called "+
		ob->query_name() + ".\n");
	tell_room(environment(TP),
			  "You watch as " + ob->query_name() + " writhes in\n\n");
        tell_room(environment(TP),HIR+
	    "                  *                                   \n"+ 
            "                *  *                                  \n"+
	    "              *    *                                  \n");
        tell_room(environment(TP),
	    "             * ** *   ****  *****  ****   *   *       \n"+
	    "            *    *   *  *   *   *   *  *   *   *      \n"+
	    "           *    *   *  *    *   *    *  *   *   *     \n");
        tell_room(environment(TP),
	    "          *    *   * **     *****     *  *   *****    \n"+
	    "                     *                            *   \n"+
	    "                    *                       *      *  \n");
        tell_room(environment(TP),
	    "               *****                       ********** \n\n"+NORM+
            "                                at the sound of its "+BOLD+
            "TRUE NAME"+NORM+".\n\n");
	call_other(ob, "set_heal", 0, 100);
	ccc = 50;
	if (ccc > ob->query_hp())
		ccc = ob->query_hp() - 1;
	ob->hit_player(ccc);
	if (living(ob))
		ob->attack_object(TP);
 	TP->attack_object(ob);

 if(!present("acwc_modifier", ob)){
   mod = clone_object("/players/maledicta/closed/w/OBJ/mob_mod.c");
   move_object(mod, ob);
   mod->originals();
   numero = random(5) + 3;
while(numero){
   mod->wc_mod();
   mod->ac_mod();
   numero -= 1;
   }
  }
   time_delay = time();
	call_other(TP, "add_spell_point", -100);
	move_object(clone_object("/players/reflex/guilds/alliance/mark.c"), ob);
	return 1;
}

reflect()
{
	if (spell(-159, 8, 100) == -1)
		return 0;
	write("You play the Canticle of Reflection upon your " +
		  TO->query_instrument() + "\n" + "\n");
	say(tp + " plays a Canticle upon " + TP->query_possessive() + " " +
		TO->query_instrument() + "\n\n");
	tell_room(environment(TP),
			  "A small cloud of silver mist comes forth from chaos.\n" +
			  "\nIt begins to rain.\n\n" +
			  "A dark pool of water forms upon the ground.\n");
	move_object(clone_object("/players/reflex/guilds/bards/pool.c"),
				environment(TP));
	call_other(TP, "add_spell_point", -100);
	return 1;
}

wander_music(str)
{
	object ob, ob2;
	string there, short_str;

	if (!str) {
		ob = find_object("music");
		if (!ob) {
			ob = find_living("music");
		}
		if (!ob) {
			write
				("There is no living music within the realms of magic.\n");
			return 1;
		}
		write("You see music:\n");
		there = call_other(environment(ob), "long");
		ob2 = first_inventory(environment(ob));
		while (ob2) {
			short_str = call_other(ob2, "short");
			if (short_str) {
				write(short_str + ".\n");
			}
			ob2 = next_inventory(ob2);
		}
		return 1;
	}
	if (str == "music") {
		if (spell(-195, 5, 25) == -1)
			return 0;
		move_object(clone_object("/players/reflex/guilds/bards/music.c"),
					environment(TP));
		call_other(TP, "add_spell_point", -25);
		write("You summon living music.\n");
		say(tp + " plays a tune upon " + TP->query_possessive() + " " +
			TO->query_instrument() + " and summons living music.\n");
		return 1;
	}
	if (str == "kill") {
		ob = find_living("music");
		if (!ob) {
			ob = find_object("music");
		}
		if (!ob) {
			write
				("There is no living music within the realms of music.\n");
			return 1;
		}
		tell_room(environment(ob), "The chords of music fade away.\n");
		destruct(ob);
		write("You release the chords of living music.\n");
		return 1;
	}
	if (spell(-111, 5, 25) == -1)
		return 0;
	move_object(clone_object("/players/reflex/guilds/bards/music2.c"),
				environment(TP));
	ob = find_living("chord");
	if (!ob)
		write("NO OBJECT!\n");
	command(str, ob);
	write("You play a single note upon your " + TO->query_instrument() +
		  " and send it " + str + ".\n");
	say(tp + " plays a single note upon " + TP->query_possessive() + " " +
		TO->query_instrument() + " and directs it " + str + ".\n");
	write("You see music:\n");
	there = call_other(environment(ob), "long");
	ob2 = first_inventory(environment(ob));
	while (ob2) {
		short_str = call_other(ob2, "short");
		if (short_str) {
			write(short_str + ".\n");
		}
		ob2 = next_inventory(ob2);
	}
	destruct(ob);
	call_other(TP, "add_spell_point", -25);
	return 1;
}
