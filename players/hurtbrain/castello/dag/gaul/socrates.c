inherit "obj/monster";
reset(arg){
   object gold,ob1;
   ::reset(arg);
   if(arg) return;
   set_name("socrates");
   set_race("human");
   set_alias("philosoph");
   set_short("Socrates, the philosoph");
   set_long("He is a strange looking man. He is a roman philosoph.\n");
   set_level(18);
   set_hp(450);
   set_al(-100);
   set_wc(26);
   set_ac(15);
   ob1=clone_object("players/hurtbrain/castello/dag/tunic2");
   move_object(ob1,this_object());
   ob1=clone_object("players/hurtbrain/castello/dag/ring");
   move_object(ob1,this_object());
}
