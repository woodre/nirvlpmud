inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

     set_name("slime");
     set_short("A small patch of green slime");
     set_race( "slime");
     set_alias("green");
     set_gender("creature");
     set_long("The slime is a creature that is currently in testing,\n"+
              "not something you really want to fight yet.\n");
     set_level(14);
     set_ac(14);
     set_wc(14 + random(4));
     set_hp(200 + random(40));
     set_al(-700);
     set_aggressive(0);

     set_chat_chance(15);
     set_a_chat_chance(40);
     load_chat("The slime oozes all about the place.\n");
     load_chat("The slime oozes closer to you.\n");
     load_a_chat("The slime thwaks you with a psudopod.\n");
     load_a_chat("slime is yukky.\n");
   }
}

heart_beat(){
  ::heart_beat();

  room_goop();
}

room_goop(){
    object room_inv;
    int h,up;
    if(!environment(this_object())) return 1;
      room_inv = all_inventory(environment(this_object()));
      for(h = 0;h < sizeof(room_inv);h++) {
        if(room_inv[h]!= this_object()){
            if(room_inv[h]->is_player() && random(100) > 49)
            player_goop(room_inv[h]);
            else if(room_inv[h]->get() && !room_inv[h]->drop() &&
                    room_inv[h]->query_weight() && !living(room_inv[h])){
                        tell_room(environment(this_object()),
                        "Green slime engulfs "+room_inv[h]->short()+"!!!\n");
                        up = room_inv[h]->query_value();
                        up = up/50;
                        if(up + query_hp() > query_mhp())
                         set_hp(up + query_hp());
                         else heal_self(up);
                         tell_room(environment(this_object()),
                           "The slime grows.\n");
                        destruct(room_inv[h]);
                    }
        }
      }
return 1; }

player_goop(object target){
    object playr_inv,tar_obj;
    playr_inv = all_inventory(target);
    tar_obj = playr_inv[random(size_of(playr_inv))];
    if(tar_obj->get() && !tar_obj->drop() && tar_obj->query_weight() &&
      !tar_obj->query_auto_load()) {
        tell_room(enviroment(this_object()),
        "A pseudopod lashes out and jars something loose.\n");
    if(tar_obj->weapon_class() && tar_obj->is_wielded())
    target->set_wc(0);
    if(tar_obj->armor_class() && tar_obj->is_worn())
    target->set_ac(target->query_ac() - tar_obj->armor_class());
    target->add_weight(-tar_obj->query_weight());
    move_object(tar_obj,enviroment(this_object()));
    }
    return 1;
}

