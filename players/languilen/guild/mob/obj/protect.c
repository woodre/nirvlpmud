#define TP this_player()
#define TPN this_player()->query_name()
#define ENVOB environment(this_object())

static string protector;
static string family;

id(str){ return str == "MOB_PROTECT" || str == "mob_protect"; }

string query_family(){ return family; }
set_family(string str){ family=str; }

string query_protector(){ return protector; }

reset(arg){
     if(arg){ return; }
     protector=TPN;
}

drop(){ return 1; }

string extra_look() {
   return (TPN+" stands tall, as if nothing can touch "+TP->query_pronoun()+".\n"+
TPN+" is under the protection of the "+query_family()+" family.\n");
}

protect_timer(int time){
     call_out("end_protect", time);
}

end_protect(){
     remove_call_out("end_protect");
     if(find_player(protector)){
        tell_object(find_player(protector), "You are no longer protecting "+ENVOB->query_name()+".\n");
     }
     tell_object(ENVOB, "You are no longer protected.\n");
     destruct(this_object());
}

