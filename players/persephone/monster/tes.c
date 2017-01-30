inherit "obj/weapon";
reset (arg){ 
 ::reset(arg);
  set_name("sword");
  set_short("sword of souls");
  set_long("a beautiful weapon, the sword of souls pulses with a light that\n"+
         "seems to emanate from deep within the ebony blade.  the blade\n"+
         "whispers of its power, war, death, and victory in the voices of\n"+
         "its slain foes.\n");
  set_class(19); 
  set_value(950);
  set_weight(2);
  set_save_flag(0);
  set_hit_func(this_object());
}
  weapon_hit(attacker){
   if(random(100) > 50){
     write("you feel the power of the sword of souls as it struggles to rip\n"+
           "the soul from your opponent\n your foe screams in agony!\n");
     say("the battle lust of the sword of souls is a palpable force\n"+
         "the sword's unfortunate victim screams in agony and terror as it\n"+
         "realizes it's fate is to feed the sword.\n");
     attacker->hit_player(15);
     return 1;
   }
}
