int rarmor(string str){
    object armor;
    int ac;
    string short, type;
    if(!str || sscanf(str, "%d %s", ac, short) !=2){
        write("Usage: rarmor <ac> <type> <short>\n");
        return 1;
    }
    sscanf(short, "%s %s", type, short);
    armor = clone_object("/obj/armor.c");
    armor->set_ac(ac);
    armor->set_type(type);
    armor->set_short(short);
    armor->set_long(short+"\n");
    armor->set_weight(1);
    armor->set_value(4);
    armor->set_name(short);
    armor->set_alias(type);
    move_object(armor, this_player());
    return 1;
}
