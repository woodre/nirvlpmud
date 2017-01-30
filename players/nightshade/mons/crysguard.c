inherit "obj/monster";

reset(arg){
   object armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("guard");
   set_alias("guard");
   set_short("Crystal Guard");
   set_long("A weatherd veteran of many fights stands before you in his glowing crystal armor and gleaming crystal sword.\n");
   set_level(18);
   set_hp(450);
   set_al(1000);
   set_wc(26);
   set_ac(15);
   armor=clone_object("/players/nightshade/armor/crysarmor");
   move_object(armor,this_object());
weapon=clone_object("/players/nightshade/weap/cryswd");
   move_object(weapon, this_object());
}


/* wc was 15, ac was 10, hp was 300 - mythos <6-17-96> */
