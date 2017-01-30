inherit "obj/armor";

/*
 * Simple armor with a special ability built in
 */

reset(arg){
 ::reset(arg);
 set_short("Blackthorn Bracers");
 set_long(
 "These bracers are actually pieces of the powerful Ymyaze guardian.\n"+
 "The black shiny armor is lined with numerous barbed spikes.\n");
 set_ac(1);
 set_weight(1);
 set_value(3500);
 set_alias("bracers");
 set_name("Blackthorn Bracers");
 set_type("misc");
 set_save_flag(1);
}

init(){
 ::init();
 add_action("br_punch","punch");
}

/*
 * This function allows the player to punch the target for
 * small amounts of damage.  The function is static so that
 * it can only be used once per round.
 */
static br_punch(str){
  object obj;

  if(!str) {
	return 0;
  }

  if(worn){
	obj = present(str, environment(this_player()));
	if(!obj) {
		return 0;
	}
	if(!living(obj)) {
		return 0;
	}
       /*
	* Damn, can't punch other players.
	*/
	if(obj->is_player()) {
		write("You draw your fist back and get ready to really whop "+
		capitalize(obj->query_name())+" a good one,\n"+
		"But you excerise amazing self control and decide not to.\n");
		return 1; 
	}
	write(
	"You punch your enemy in the face while wearing the rock hard bracers.\n"+
	"The barbed spikes draw nasty gashes in "+capitalize(obj->query_name())+
	"'s cheek!\n");
	say(
	capitalize(this_player()->query_name())+" slashes some flesh from "+
	capitalize(obj->query_name())+" with his blackthorn bracers!\n");
	obj->hit_player(random(2)+1);
	this_player()->add_spell_point(-2);
	obj->attacked_by(this_player());
	return 1;
  }
}
