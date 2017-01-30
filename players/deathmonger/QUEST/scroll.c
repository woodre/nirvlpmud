
object demo;
id(str){ return str == "scroll"; }
short(){ return "A powerful magic scroll"; }
query_save_flag(){ return 1; }
long(){ 
write("The scroll reads:\n\n");
write("This scroll has the power to kill Demogorgon on this plane of existence.\n");
}

init(){
     add_action("use","use");
     add_action("use","read");
}

use(str){
     if(str == "scroll"){
       demo = present("demogorgon", environment(this_player()));
       write("You summon a thousand angels to cast lightning against\n");
       write("Demogorgon all at once, and he is reduced to a cinder.\n");
       demo->hit_player(10000);
       write("The scroll, its magical energy expended, crumbles into dust.\n");
       destruct(this_object());
       return 1;
     }
}
get(){ return 1; }
