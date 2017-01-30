reset() {
  object weapon;
   weapon=clone_object("obj/weapon");
        call_other(weapon,"set_name","blah");
        call_other(weapon,"set_id","weapon");
        call_other(weapon,"set_class",5);
        call_other(weapon,"set_weight",1);
        call_other(weapon,"set_value",1);
        call_other(weapon,"set_hit_func",this_object());
        move_object(weapon,this_player());
   }
weapon_hit() {
   if (call_other(environment(this_player()),"realm")=="enterprise") {
     write("ghdggjh\n");
     return 100;
      }
  return 0;
  }
