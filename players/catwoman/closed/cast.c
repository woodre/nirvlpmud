#include "/players/catwoman/closed/hello.h"
id(str){ return str == "gnome"; }
get(){ return 1; }
/*
drop() { return 1; }
*/
 


init(){
     add_action("cast","cast");
}


cast(str){
     object ob;
     string mes;
     if (!str) {
     write("No message?\n");
     return 1;
     }
     sscanf(str, "%s", mes);
     ob = clone_object("/players/catwoman/spells/mess");
     call_other(ob, "set_mess",mes);
     move_object(ob, environment(this_player()));
write("you betcha\n");
return 1;
}

