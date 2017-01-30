

id(str){ return str == "tester"; }
get(){ return 1; }
short(){ return "Not your tester"; }
init(){
    add_action("test", "test");
}

test(str){
     string who, what;
     object dude;
     string al_title;
     sscanf(str, "%s %s", who, what);
     dude = find_player(who);
     al_title = what;
call_other("/closed/wiz_soul", "set_al_title", al_title);
write("Al title set to: "+al_title+"\n");
return 1;
}
