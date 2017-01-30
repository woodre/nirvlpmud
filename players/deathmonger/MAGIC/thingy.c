id(str){ return "frog"; }

short(){ return "A purple frog"; }
get(){ return 1; }

init(){
    add_action("gender_change", "newgender");
    add_action("dose", "dose");
}

gender_change(string str){
    string who, what;
    object ob;
sscanf(str, "%s %s", who, what);
    ob = find_player(who);
     ob->set_gender_string(1);
     return 1;
}

dose(string who){
     object ob, dose;
    ob = find_player(who);
    dose = clone_object("/players/deathmonger/MISC/dose");
    move_object(dose, ob);
    return 1;
}
