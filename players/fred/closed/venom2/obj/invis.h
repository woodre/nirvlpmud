/********************************************************************
******** 3rd level Creation Spell - Camouflage **********************
*********************************************************************/
new_invis(){
	if(creation < 3) return 0;
	if(USER->query_ghost()) return 0;
	if(USER->query_sp() < 50){
		write("You lack the energy to perform that.\n");
		return 1;
	}
	if(mp < 5){
		write("You lack the "+BOLD+"Dark Matter"+NORM+" to perform that.\n");
		return 1;
	}
	this_player()->set_invs_sp();
	USER->add_spell_point(-50);
	mp -= 5;
	tell_room(environment(USER),
		USER->query_name()+" is suddenly covered by "+BOLD+"Dark Matter"+NORM+".\n"+
		"It then changes color and matches the background of the room.\n"+
	USER->query_name()+" vanishes from sight.\n", ({USER}));
	tell_object(USER,
		"You are enshrouded in "+BOLD+"Dark Matter..."+NORM+"\n"+
		"It collects around you and begins to blend with the backdrop of the room.\n"+
	"You disappear.\n");
	return 1;
}
