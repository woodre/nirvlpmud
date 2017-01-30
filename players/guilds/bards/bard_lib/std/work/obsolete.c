int
hit_pet(int wc, int spell) {
    int tmpk;
    string name_alt_at;

    if (is_npc && AltAttacker->is_pet() && random(100) < 37) {
	AlreadyFought = 0;
	name_alt_at = AltAttacker->query_name();
	
	tmpk = AltAttacker->hit_player(random(wc) + spell);
	if (tmpk > 10)
	  say(CapName + " hits " + name_alt_at + " hard with a side attack.\n");
	else if (tmpk > 0)
	  say(CapName + " hits " + name_alt_at + " with a side attack.\n");
	else
	  say(CapName + " missed " + name_alt_at + ".\n");
    }
    return 1;
}
