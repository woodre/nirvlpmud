inherit "obj/monster";

reset(arg) {
     object money;
     ::reset(arg);
     if(!arg) {
          set_name("ogre");
          set_race("ogre");
          set_level(9);
          set_hp(135);
          set_al(-200);
          set_short("an ogre");
          set_long("The ogre towers over you at nine feet, its violet eyes\n"+
                   "roving for blood-sport.\n");
          set_aggressive(0);
          set_wc(13);
          set_ac(7); 
          money=clone_object("obj/money");
          money->set_money(500);
          move_object(money, this_object()); }
}