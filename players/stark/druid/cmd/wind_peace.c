wind_peace(str){
	object fighter;
	fighter = first_inventory(environment(this_player()));

	while (fighter) {
		fighter->stop_fight();
		fighter->stop_fight();
		fighter->stop_hunter();
		fighter=next_inventory(fighter);
	}
}



