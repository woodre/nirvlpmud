inherit "obj/monster";
reset(arg){
   object gold,ob1;
   ::reset(arg);
   if(arg) return;
   set_name("idefix");
   set_race("dog");
   set_alias("dog");
   set_short("A dog named Idefix");
   set_long("This is a little white dog. You can crash him under your feet.(or not?)\n");
   set_level(20);
   set_hp(500);
   set_al(100);
   set_wc(30);
   set_ac(17);
   set_chat_chance (90);
   load_chat("BARK\n");
   ob1=clone_object("players/hurtbrain/castello/dag/gaul/osso");
   move_object(ob1,this_object());
}
