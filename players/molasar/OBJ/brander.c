
id(str) { return str == "brander" || str == "personal brander"; }

short() { return "A personal brander"; }

long() { 
     write("You can use this brander to show that you are fighting.\n");
     write("that monster.  If someone should kill a branded\n");
     write("monster, you will be notified who killed it.\n");
}

get() { return 1; }

init() {
     add_action("brand","brand");
}

brand(str) {
     string what;
     object monster, brand;
     string me;
     me = this_player()->query_real_name();

     if(!str || sscanf(str, "%s", what) != 1) {
       write("Brand what?\n");
       return 1;
     }
     monster = present(what, environment(this_player()));
     if(!monster) {
       write(capitalize(what)+" is not here.\n");
       return 1;
     }
     brand = clone_object("players/molasar/OBJ/brand");
     brand->set_short("Branded by "+this_player()->query_real_name());
     brand->set_owner(me);
     brand->set_monster(what);
     brand->set_heart_beat(1);
     move_object(brand, monster);
     write("You have branded "+capitalize(what)+".\n");
     return 1;
}




