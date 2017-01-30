int rweap(string str){
    object weapon;
    int wc;
    string short;
    if(!str || sscanf(str, "%d %s", wc, short) !=2){
	write("Usage: rweap <wc> <short>\n");
	return 1;
    }
    weapon = clone_object("/obj/weapon.c");
    weapon -> set_class(wc);
    weapon -> set_short(short);
    weapon -> set_long(short+"\n");
    weapon -> set_weight(1);
    weapon -> set_value(4);
    weapon -> set_name(short);
    weapon -> set_alias("weapon");
    move_object(weapon, this_player());
    return 1;
}
