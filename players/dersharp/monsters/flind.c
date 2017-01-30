inherit "obj/monster";

reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("ogre");
   set_short("A large ogre");
   set_long("Ogres are known for their strength and hardiness in combat. \n"+
            "To fight one means to bring upon the chance of death....\n");
   set_level(5);
   set_hp(75);
   set_al(-100);
   set_ac(5);
   set_wc(9);
   set_chat_chance(2);
   load_chat("Ogre says: I'm gonna chew you up manling!\n");
   gold=clone_object("obj/money");
   gold->set_money(200);
   move_object(gold,this_object());
   set_dead_ob(this_object());
}
monster_died() {
   object trent;
   object here;
   here = environment(this_object());
   tell_room(here,"The death of the ogre breaks the fabric of space and a\n"+
             "figure walks through!\n");
   trent = clone_object("/players/dersharp/joint/mons/trent");
   move_object(trent, here);
   return 0
}
