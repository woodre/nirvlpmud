inherit "obj/armor";
reset(arg){
 ::reset(arg);
 set_short("Ring of Magic");
 set_long("The Ring of Magic.  This magic gives a bonus to your\n"+
 "Magic Aptitude when it is worn.\n");
 set_ac(1);
 set_weight(1);
 set_value(500);
 set_alias("ring");
 set_name("Ring of Magic");
 set_type("ring");
  set_save_flag(0);
}

init(){
 add_action("wear_ring","wear");
 add_action("remove_ring","remove");
}

wear_ring(str){
  object ob;
  int tmp;
  if(!id(str)) return 0;
  if(environment() != this_player()){
    write("You must get it first!\n");
    return 1;
  }
  if(worn){
    write("You already wear it!\n");
    return 1;
  }
  if(!present("mageobj", this_player())){
    write("You must be a member of the Mages Guild to use this item.\n");
    return 1;
  }
  ob = call_other(this_player(), "wear", this_object());
  if(!ob){
    worn_by = this_player();
    worn = 1;
    write("The ring enhances your magic ability.\n");
    this_player()->raise_magic_aptitude(3);
    present("mageobj", this_player())->add_mag_bonus(3);
    present("mageobj", this_player())->save_my_stats();
    return 1;
  }
  write("You already have an armor of class "+type+".\n");
  write("Worn armor "+call_other(ob,"short")+".\n");
  return 1;
}

remove_ring(str){
  if(!id(str)) return 0;
  if(!worn) return 0;
  write("The magic enhancement of the ring ends.\n");
  this_player()->raise_magic_aptitude(-3);
  present("mageobj", this_player())->add_mag_bonus(-3);
  present("mageobj", this_player())->save_my_stats();
  call_other(worn_by, "stop_wearing", name);
  worn_by = 0;
  worn = 0;
  return 1;
}

drop(){
  if(worn){
    write("The magic enhancement of the ring ends.\n");
    this_player()->raise_magic_aptitude(-3);
    present("mageobj", this_player())->add_mag_bonus(-3);
    present("mageobj", this_player())->save_my_stats();
    call_other(worn_by, "stop_wearing", name);
    worn_by = 0;
    worn = 0;
  }
}

