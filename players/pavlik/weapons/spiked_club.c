inherit "obj/weapon";
#define ME capitalize(this_player()->query_name())
#define IT capitalize(attacker->query_name())
reset(arg){
 ::reset(arg);
 if(arg) return;
 set_alias("club");
 set_type("club");
 set_name("spiked club");
 set_short("A spiked club");
 set_long("A crude wooden club with iron spikes driven into the top.\n");
 set_class(19);
 set_weight(15);
 set_value(10);
 set_save_flag(1);
 set_hit_func(this_object());
}

weapon_hit(attacker){
 if(random(25) == 11){
    tell_room(environment(this_player()),
    ME+" smashes an enormous spiked club into "+IT+"'s head!\n"+
    "One of the iron spikes sinks deep into "+IT+"'s eye!!!\n");
   return 8;
 }
 return;
}
