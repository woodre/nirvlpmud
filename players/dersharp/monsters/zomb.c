inherit "obj/monster";
reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("zombie");
   set_short("A frightening zombie");
   set_long("The Master dug this dead person to serve him in his fight\n"+
            "agaisnt the forces of light.  Free this tortured soul.\n");
   set_level(3);
   set_hp(45);
   set_ac(4);
   set_wc(7);
   set_al(-50);
   gold=clone_object("obj/money");
   gold->set_money(100);
   move_object(gold,this_object());
}
