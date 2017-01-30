inherit "obj/monster";
reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("bat");
   set_race("bat");
   set_alias("rodent");
   set_short("A small furry bat");
   set_long("This is one of the evil creatures that the Shadow Master has \n"+
       "brought here to protect his domain.\n");
   set_level(1);
   set_hp(15);
   set_al(-20);
   set_wc(5);
   set_ac(3);
   set_chat_chance(2);
   load_chat("SQUEEK SQUEEK SQUEEK!!!\n");
   gold=clone_object("players/dersharp/stuff/tail");
   move_object(gold,this_object());
}
