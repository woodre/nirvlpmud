id(str) { return str == "__wizcheck__"; }
get() { return 1; }
drop() { return 0; }

init() { 
add_action("dest","dest");
}

dest(string str) {
  object ob, room;
  int i;
  if(this_player()->query_level() > 20) {
     room = users();
     for(i = 0; i < sizeof(room); i++) {
        if(room[i]->is_player()          &&
           room[i]->query_level() < 20   &&
           present(room[i], environment(this_player())) ) {
           if(present(str, environment(this_player())))
              ob = present(str, environment(this_player()));
           if(present(str, this_player())) 
              ob = present(str, this_player());
           if(ob) {           write_file("/players/dune/log/DEST",
              "___________________________________________\n"+
              this_player()->query_real_name()+
              " dested a "+str+" when "+room[i]->query_real_name()+
              " was in the same room.\n"+
              "("+ctime()+")\n");
           write_file("/players/dune/log/DEST", 
              "___________________________________________\n");
              }
           }
        }
     }
}
