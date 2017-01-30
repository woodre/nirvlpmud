
id(str){ return str == "bubble"; }
get(){return 1;}
query_value(){ return 500; }
short(){ return "A Bubble of Privacy"; }
long(){ 
write("This magic item will protect you from spying by\n");
write("assassins and vampires.\n");
}

init(){
set_heart_beat(1);
}

heart_beat(){
     object womble, snooper;
     womble = present("womble", environment(this_object()));
     if(womble){
       destruct(womble);
       return 1;
     }
     snooper = present("snooperbat", environment(this_object()));
     if(snooper){
       destruct(snooper);
       return 1;
     }
}
