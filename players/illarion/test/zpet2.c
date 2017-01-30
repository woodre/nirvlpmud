int *pet_hps;
int *pet_return;
string *pet_names;
summon_pet(str)
{
   string curr_out;
	object ob, ob2, ob3;
	string animal_type, OB;
	string name, xname;
	object petname;
	int length;
	int i;
	string named;
	string named2;
	int notfirst;
        int time;
#define BBB move_object(ob,environment(this_player()))
#define ENVV environment(this_player())
	
	if (!str) {
		write("Companion <type>    <see animal_list>\n");
		return 1;
	}
	if(!this_object()->my_pet()){
		if(spell(-149, 3, 50) == -1){
			write("You do not have the energy to do that.\n");
			return 1;
		}
	}
   if(this_object()->my_pet()){
      if(str == this_object()->my_pet()->query_name()){
        write("That companion is already out!\n");
        return 1;
      }
   }
 if(my_pet())	
   if(my_pet()->query_hp() < my_pet()->query_mhp()){
      write("Your companion cannot return until it is fully healed.\n");
      return 1;
      }
if(this_object()->my_pet()) this_object()->my_pet()->bye2();
else this_player()->add_spell_point(-50);
	
   name = str;
	

	if(name == "phoenix"){
		if((int)pet_return[1] > 0){
                        time=pet_return[1]*2/60/60;
			write("You cannot ask the phoenix to return so soon after its death.\n");
                        write("Less than "+(time+1)+" hour"+(time?"s":"")+" remain"+(time?"":"s")+".\n");
			return 1;
		}
       if(pet_names[1] == "0"){
         write("You must name the Phoenix before summoning it.\n"+
               "petname phoenix <name>\n");
         return 1;
         }
		ob = clone_object("/players/guilds/bards/pet/phoenix2.c");
	   ob->set_alt_name(pet_names[1]);
       ob->set_pet_name(pet_names[1]);
	}
	else if (name == "faerie") {
		if((int)pet_return[2] > 0){
			time=pet_return[2]*2/60/60;
			write("You cannot ask the Faerie to return so soon after its death.\n");
			write("Less than "+(time+1)+" hour"+(time?"s":"")+" remain"+(time?"":"s")+".\n");
			return 1;
		}
       if(pet_names[2] == "0"){
         write("You must name the Faerie before summoning it.\n"+
               "petname faerie <name>\n");
         return 1;
         }
		ob = clone_object("/players/guilds/bards/pet/faerie.c");
	   ob->set_alt_name(pet_names[2]);
       ob->set_pet_name(pet_names[2]);
	}
	else if (name == "brownie") {
		if((int)pet_return[3] > 0){
			time=pet_return[3]*2/60/60;
			write("You cannot ask the brownie to return so soon after its death.\n");
			write("Less than "+(time+1)+" hour"+(time?"s":"")+" remain"+(time?"":"s")+".\n");
			return 1;
		}
       if(pet_names[3] == "0"){
         write("You must name the Brownie before summoning it.\n"+
               "petname brownie <name>\n");
         return 1;
         }
		ob = clone_object("/players/guilds/bards/pet/brownie.c");
	   ob->set_alt_name(pet_names[3]);
       ob->set_pet_name(pet_names[3]);
	}
	else {
		write("That is not a bardic companion.\n");
		return 1;
	}
	/*
	if(this_object()->my_pet()){
		(this_object()->my_pet())->bye2();
	}
	else{
		this_player()->add_spell_point(-50);
	}
   */
	call_other(ob, "set_master_name", this_player()->query_real_name());
	BBB;
	my_pet(ob);
	
	tell_room(environment(TP), "\n\n");
	write("You play a tune of summoning upon your " +
	TO->query_instrument() + ".\n");
	say(tp + " plays a tune upon " + TP->query_possessive() + " " +
	TO->query_instrument() + ".\n");
	
	if (name == "faerie") {
		tell_room(ENVV,
			"A small faerie flies into the room.\n"
			+ "and circles " + tp +
			" three times before landing upon " +
		TP->query_possessive() + " shoulder.\n");
	}
	if (name == "brownie") {
		tell_room(ENVV,
		"A small brownie trots into the room.\n");
	}
	
	if (name == "drake") {
		tell_room(ENVV,
			"A shadow crosses over you as a small drake descends from the sky\n"
			+ "and circles " + tp +
			" three times before landing upon " +
		TP->query_possessive() + " shoulder.\n");
	}
	if (name == "phoenix") {
		tell_room(ENVV,
			"A column of crimson fire descends from the sky.\n\n" +
			"A phoenix rises from the ashes of the fire and flies over to "
		+ tp + ".\n");
	}
	return 1;
}

set_pet_name(str)
{
	pet_name = str;
}

query_pet_name()
{
	return pet_name;
}


name_pet(str){
	int i;
	int length;
	string type;
	string name;
	string named;
	string named2;
	string xname;
	
	if(!str){
		write("petname <type> <name>\n");
		return 1;
	}
	if(sscanf(str, "%s %s", type, name) != 2){
		write("petname <type> <name>\n");
		return 1;
	}
	if(type != "brownie" && type != "faerie" &&
		type != "drake" && type != "phoenix"){
		write("Invalid type.\n"+
		"petname <type> <name>\n");
		return 1;
	}
	
	named = lower_case(name);
	named2 = strlen(name);
	i=0;
	while(i < named2) {
		if (named[i] < 'a' || named[i] > 'z'){
			write("Invalid characters in name.\n");
			return 1;
		}
		i += 1;
	}
	xname = lower_case(name);
	length = strlen(name);
	if (length > 11) {
		write("Companion name is too long.\n");
		return 1;
	}
	if(type == "drake"){        pet_names[0] = xname; }
	else if(type == "phoenix"){ pet_names[1] = xname; }
	else if(type == "faerie"){  pet_names[2] = xname; }
	else { pet_names[3] = xname; }
	write("Your "+type+" has now been named "+name+".\n");
	return 1;
}


set_pet_delay(int time, string pet){
  if(pet == "phoenix"){  pet_return[1] = time; }
  else if(pet == "faerie"){ pet_return[2] = time; }
  else if(pet == "brownie"){ pet_return[3] = time; }
  else return;
  }
