spectral_binding(str)
{
	object ob;
   object binding;
	int a, b;

	if (!str) {
		write
			("Play Harper's Song of Spectral Binding upon what creature?\n");
		return 1;
	}
	ob = present(str, environment(TP));
	if (!ob) {
		write("There is no " + CAP + " here to bind.\n");
		return 1;
	}
   if(!living(ob)){ 
      write("You cannot bind an object.\n");
      return 1;
      }
	if (ob->webbed()) {
		write(CAP + " cannot be further bound.\n");
		return 1;
	}
	if (attack_spell(-150, 6, 20, ob) == -1) return 0;

	if (!ob->query_npc()){
      write("This will not work on players.\n");
      return 1;
      }
		write("You play Harper's Song of Spectral Binding.\n\n" +
			  "The room fills with slow, etheral sounding " +
			  TO->query_instrument() + " music.\n\n" + ob->query_name() +
			  " is bound by illusionary chains.\n\n");
		say(tp + " plays Harper's Song of Spectral Binding.\n\n" +
			"The room fills with slow, etheral sounding " +
			TO->query_instrument() + " music.\n\n" + ob->query_name() +
			" is bound in illusionary chains.\n\n");
      TP->add_spell_point(-20);
   	binding = clone_object("/players/guilds/bards/binding.c");
		binding->set_time(20 + TP->query_level() + TP->query_extra_level());
		binding->web_person(ob);
		return 1;
 	}
	

note_of_cloaking(str)
{
	object ob;

	if (!str) {
		ob = TP;
		if (spell(-176, 3, 10, TP) == -1) return 0;
	write("You play a single note upon your " + TO->query_instrument() +".\n"+
		  "You are cloaked in an illusionary cloak.\n");
	tell_room(environment(ob),
			  "You hear " + tp + " play a single note upon " +
			  TP->query_possessive() + " " + TO->query_instrument() +
                          ".\n" + tp + " is cloaked in an illusionary cloak.\n", ({ TP }));
	call_other(ob, "stop_hunter");
	call_other(TP, "add_spell_point", -10);
		return 1;
	}
	ob = find_player(str);
	/* <change by="Erasmios" date="2001-07-04"> */
	if (!ob || ob->query_level() >= 20) {
	/* </change> */
		write("You cannot find " + CAP + " within the realms of magic.\n");
		return 1;
	}
	if (spell(-176, 3, 10, TP) == -1)
		return 0;
	write("You play a single note upon your " + TO->query_instrument() +
		  ".\n" + CAP + " is cloaked in an illusionary cloak.\n");
	tell_room(environment(ob),
			  "You hear " + tp + " play a single note upon " +
			  TP->query_possessive() + " " + TO->query_instrument() +
			  ".\n" + CAP + " is cloaked in an illusionary cloak.\n");
	call_other(ob, "stop_hunter");
	call_other(TP, "add_spell_point", -10);
	return 1;
}

canticle_of_darkness(str)
{
  if(!str){  write("song <darken, light, or out light>\n"); return 1; }
	if (str == "darken") {
		if (spell(-155, 6, 30) == -1)
			return 0;
		/* <change by="Erasmios" date="2001-07-04"> */
		if (present("dark", environment(this_player()))) {
			write("This spell cannot be cast at this time.\n");
			return 1;
		}
      if(!creator(environment(TP))){
         write("You cannot cast this in the main village.\n");
         return 1;
         }
		/* </change> */
		move_object(clone_object("/players/guilds/bards/dark.c"),
					environment(this_player()));
		tell_room(environment(this_player()),
				  "A cloud of darkness covers the room as " + tp +
				  " plays a canticle.\n");
		call_other(TP, "add_spell_point", -30);
		return 1;
	}
}

chord_of_distortion(str)
{
	object ob;
   object targ;
   int acboost;
	if (spell(-111, 4, 40) == -1)
		return 0;

   if(!str){
	if (present("defend_spell", environment(TO))) {
		write("You are already surrounded by distortion waves.\n");
		return 1;
	   }
   switch(TO->query_bard_level()){
   case 10..10000: acboost = 4; break;
   case 8..9:      acboost = 3; break;
   case 6..7:      acboost = 2; break;
   case 1..5:      acboost = 1; break;
   default:        acboost = 0; break;
   } 
	ob = clone_object("/players/guilds/bards/bard_defend.c");
	move_object(ob, TP);
   ob->start(TP, acboost, TO->query_bard_level() * 600);
   
   write("You cloak yourself in illusion as you play a series of chords\n"
		  + "upon your " + TO->query_instrument() + ".\n");
	say(tp + " cloaks " + TP->query_objective() + "self in illusion as " +
		TP->query_pronoun() + "\n" + "plays some chords upon " +
		TP->query_possessive() + " " + TO->query_instrument() + ".\n");
	call_other(TP, "add_spell_point", -40);
	return 1;
}

  targ = present(str, environment(TP));
  if(!targ){
     write("You do not see "+str+" present.\n");
     return 1;
     }
  if(!living(targ)){
     write("You cannot distort that.\n");
     return 1;
     }
  if(!targ->is_player()){
     write("This only works for players.\n");
     return 1;
     }
  if(present("defend_spell", targ)) {
		write("They are already surrounded by distortion waves.\n");
		return 1;
	   }
   switch(TO->query_bard_level()){
   case 10..10000: acboost = 4; break;
   case 8..9:      acboost = 3; break;
   case 6..7:      acboost = 2; break;
   case 1..5:      acboost = 1; break;
   default:        acboost = 0; break;
   } 
	ob = clone_object("/players/guilds/bards/bard_defend.c");
	move_object(ob, targ);
   ob->start(targ, acboost, TO->query_bard_level() * 600);
   
   write("You cloak "+targ->query_name()+" in illusion as you play a series of chords\n"
		  + "upon your " + TO->query_instrument() + ".\n");
	say(tp + " cloaks " + targ->query_name() + " in illusion as " +
		TP->query_pronoun() + "\n" + "plays some chords upon " +
		TP->query_possessive() + " " + TO->query_instrument() + ".\n");
	call_other(TP, "add_spell_point", -40);
	return 1;
}
    
song_of_masking(){
   object m;
   if(spell(-194, 9, 5) == -1)
		return 0;
   if(environment(this_player())->bard_room_hide()){
      write("The room is already masked in mist.\n");
      return 1;
      }
   this_player()->add_spell_point(-5);
   write(HIW+"You sing a soft song of masking...\n"+
         "The room is suddenly covered in a soft "+HIG+"Mist"+HIW+".\n"+NORM);
   say(this_player()->query_name()+" plays a soft song.\n"+
       "A mist rolls into the room.\n");
   m = clone_object("/players/guilds/bards/hide_room");
   m->start_shadow(environment(this_player()));
   return 1;
   }   


song_of_illusion(str)
{
	object ob;
	string target, temp, text;

	if (!str) {
		write("Illusion <here/player name> <illusion text>\n");
		return 1;
	}
	if (sscanf(str, "%s %s", temp, text) != 2) {
		write("Illusion <here/player name> <illusion text>\n");
		return 1;
	}
	if (spell(-194, 7, 40) == -1)
		return 0;
	if (temp == "here") {
		move_object(clone_object("/players/guilds/bards/ill_obj.c"),
					environment(TP));
		ob = present("illusion", environment(TP));
		call_other(ob, "set_short", text);
		write("You sing a soft song.\n");
		write("You create an illusion:\n" + "* " + text + "\n");
		say(tp + " sings a soft song.\n");
		say("Something has changed.\n");
		call_other(TP, "add_spell_point", -40);
		return 1;
	} else {
		/* <change by="Erasmios" date="2001-07-04"> */
		ob = find_player(temp);
		if (!ob || ob->query_level() >= 20) {
			write("That player is not within the realm of magic.\n");
			return 1;
		}
		/* </change> */
		say(tp + " sings a soft song.\n");
		write("You sing a soft song as you send an illusion to " +
			  capitalize(temp) + ".\n" + "* " + text + "\n\n");
		tell_object(ob, "You see an illusion.\n\n");
		tell_object(ob, text + "\n\n");
		call_other(TP, "add_spell_point", -40);
		return 1;
	}
	write("Illusion <here/player name> <illusion text>\n");
	return 1;
}

