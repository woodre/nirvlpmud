
inherit "obj/monster";
string who;
set_who(name){ who = name; }
query_who(){ return who; }
id(str){ return str == "womble"; }
get(){ return 1; }
extra_look(){
     return capitalize(who)+" has been diseased!  Better steer clear!";
}

init(){
set_heart_beat(1);
}

heart_beat(){
     if(find_player(who)->query_hp() > 10){
       find_player(who)->add_hp(-2);
       write("You begin to lose in your fight against the disease.\n");
       return 1;
     }
     return 1;
}
