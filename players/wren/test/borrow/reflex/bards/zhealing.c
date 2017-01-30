
bury_corpse(str)
{
	object corpse;
	int heal;
	string gender;

	heal = 0;
	corpse = present("corpse", environment(this_player()));
	if (!corpse) {
		corpse = present("corpse", this_player());
	}
	if (!corpse) {
		write("There is no corpse here to bury.\n");
		return 1;
	}
	/* <change by="Erasmios" date="2001-07-04"> */
	heal = corpse->heal_value();
	if (heal <= 0) {
		write("The corpse is devoid of energy.\n");
		return 1;
	}
	call_other(this_player(), "add_hit_point", heal * 2);
	/* </change> */

	gender = this_player()->query_pronoun();
	write("You murmur a brief prayer and then bury the corpse.\n" +
		  "You feel good.\n");
	say(tp + " murmurs a brief prayer as " + gender +
		" buries a corpse.\n");
	destruct(corpse);
	/* <change by="Erasmios" date="2001-07-05"> */
	corpse = clone_object("/players/reflex/guilds/bards/marker");
	if (transfer(corpse, environment(this_player()))) {
		destruct(corpse);
	} else {
		say(tp + " drops a grave marker.\n");
	}
	/* </change> */
	return 1;
}

pyre_corpse(str)
{
	object corpse;
	int heal;

	heal = 0;
	corpse = present("corpse", environment(this_player()));
	if (!corpse) {
		corpse = present("corpse", this_player());
	}
	if (!corpse) {
		write("There is no corpse here to burn.\n");
		return 1;
	}
	heal = corpse->heal_value();
	/* <change by="Erasmios" date="2001-07-04"> */
	if (heal <= 0) {
		write("The corpse is devoid of energy.\n");
		return 1;
	}
	/* </change> */
	call_other(this_player(), "add_spell_point", heal * 2);
	write("You make a funeral pyre and burn the corpse.\n" +
		  "You feel good.\n");
	say(tp + " builds a funeral pyre and burns a corpse.\n");
	destruct(corpse);
	return 1;
}

chant_heal(str)
{
	object ob;

	if (!str) {
	if (spell(0, 2, 15, TO) == -1)
		return 0;
	ob = TP;
	ob->add_hit_point(12);
	write("You chant the song of healing.\n" +
		  "You dance around in a circle.\n"+ 
		  "You are healed.\n");
	say(tp + " chants a strangely soothing chant.\n"+
		tp + " dances around in a circle.\n" +
		tp + " is covered in an aura of healing.\n");
	call_other(TP, "add_spell_point", -15);
		return 1;
	}
	ob = present(str, environment(TP));
	if (!ob) {
		write("You do not see a " + CAP + " here.\n");
		return 1;
	}
	if (spell(0, 2, 15, TO) == -1)
		return 0;
	ob->add_hit_point(12);
	write("You chant the song of healing.\n" +
		  "You dance around in a circle.\n" + CAP + " is healed.\n");
	say(tp + " chants a strangly soothing chant.\n" +
		tp + " dances around in a circle.\n" +
		CAP + " is covered in an aura of healing.\n");
	tell_object(ob, "You feel very good.\n");
	call_other(TP, "add_spell_point", -15);
	return 1;
}

chord_of_agony(str)
{
	string gender;
	object ob;
   object mod;
   int i; 
   int numero;

	if (!str) {
		write("You must strike the Chord of Agony towards a creature.\n");
		return 1;
	}
	ob = present(str, environment(TP));
	if (!ob) {
		write(CAP + " is not here.\n");
		return 1;
	}
   gender=ob->query_objective();
   if(present("acwc_modifier", ob)){
      write(CAP + " is already in Agony!\n");
      return 1;
      }
	if (attack_spell(-100, 4, 30, ob) == -1) return 0;

	say(tp + " plays a dissonant chord upon " + TP->query_possessive() +
		" " + TO->query_instrument() + ".\n" +
		"A black aura settles over " + capitalize(str) + ".\n");
	write("You play a dissonant chord upon your " +
		  TO->query_instrument() + ".\n" + "A black aura settles over " +
		  capitalize(str) + ".\n");
   mod = clone_object("/players/maledicta/closed/w/OBJ/mob_mod.c");
   move_object(mod, ob);
   mod->originals();
numero = random(5) + 1;
while(numero){
   mod->wc_mod();
   mod->ac_mod();
   numero -= 1;
   }
	call_other(TP, "add_spell_point", -30);
	return 1;
}

hymn_of_healing(str)
{
object targ;
if (spell(-100, 8, 50, TO) == -1) return 0;

if(!str){
	TP->add_hit_point(40);
	write
		("You are surrounded by a halo of light as you play the Hymn of Healing.\n"
		 +
		 "You faintly hear a choir of angels singing in accompaniment to your "
		 + TO->query_instrument() + ".\n" +
		 "Your wounds are bathed in a healing aura.\n");
	say(tp + " is surrounded by a halo of light as " +
		TP->query_possessive() + " plays a Hymn.\n" +
		"You faintly hear a choir of angles singing in accompniment to the "
		+ TO->query_instrument() + " music.\n" + tp +
		" is bathed in a healing aura.\n");
	call_other(TP, "add_spell_point", -50);
	return 1;
}
targ = present(str, environment(TP));
if(!targ){
   write("They are not present.\n");
   return 1;
   }
if(!living(targ)){
   write("You cannot heal that!\n");
   return 1;
   }
   targ->add_hit_point(40);
	write
		("You are surrounded by a halo of light as you play the Hymn of Healing.\n"
		 +
		 "You faintly hear a choir of angels singing in accompaniment to your "
		 + TO->query_instrument() + ".\n" +
		 targ->query_name()+"'s wounds are bathed in a healing aura.\n");
	say(tp + " is surrounded by a halo of light as " +
		TP->query_possessive() + " plays a Hymn.\n" +
		"You faintly hear a choir of angles singing in accompaniment to the "
		+ TO->query_instrument() + "'s music.\n" + targ->query_name() +
		" is bathed in a healing aura.\n");
	call_other(TP, "add_spell_point", -50);
	return 1;
}



regeneration(str)
{
object woo;
	if (spell(-194, 9, 100) == -1)
		return 0;

	if(!str){       
	/* <change by="Erasmios" date="2001-07-04"> */
	if (present("regen", this_player())) {
		write("This spell cannot be cast at this time.\n");
		return 1;
	}
	/* </change> */
	tell_room(environment(TP), "\n\n");
	write("You play the Rhapsody of Regeneration upon your " +
		  TO->query_instrument() + ".\n" +
		  "You speak one of the Words of Power.\nYou begin to regenerate.\n");
	say(tp + " plays a Rhapsody upon " + TP->query_possessive() + " " +
		TO->query_instrument() + ".\n" + tp +
		" speaks one of the Words of Power.\n\nYou shiver.\n" + tp +
		" begins to regenerate at a rapid rate.\n");
	move_object(clone_object("/players/reflex/guilds/bards/regen.c"),
				this_player());
	call_other(TP, "add_spell_point", -100);
	return 1;
    }
woo = present(str, environment(TP));
if(!woo){
	 write("They are not present!\n");
	 return 1;
}
if(!living(woo) || !woo->is_player()){
	 write("You cannot cast regen on that!\n");
	 return 1;
}
	if (present("regen", woo)) {
		write("This spell cannot be cast on them again.\n");
		return 1;
	}
    tell_room(environment(TP), "\n\n");
	write("You play the Rhapsody of Regeneration upon your " +
		  TO->query_instrument() + ".\n" +
		  "You speak one of the Words of Power.\n"+
		  woo->query_name()+" begins to regenerate.\n");
	say(tp + " plays a Rhapsody upon " + TP->query_possessive() + " " +
		TO->query_instrument() + ".\n"+
		woo->query_name()+" begins to regenerate at a rapid rate.\n");
	move_object(clone_object("/players/reflex/guilds/bards/regen2.c"),
				woo);
	call_other(TP, "add_spell_point", -100);
	return 1;
    }
