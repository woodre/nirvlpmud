
init(){
     set_heart_beat(1);
     call_out("wear_off", 25);

}
heart_beat(){
     command("laugh", environment(this_object()));
     return 1;
}

wear_off(){
      tell_object(environment(this_object()), "The laughing gas wears off.\n");
     destruct(this_object());
     return 1;
}
