inherit "obj/monster";
reset(arg){
   int xy;
   object heal;
   ::reset(arg);
   if(arg) return;
   set_name("igor");
   set_race("human");
   set_alias("butcher");
   set_short("Igor, the butcher");
   set_long("Igor wears blood soaked cloathes, he has a large knife in his hands.\n");
   set_level(20);
   set_hp(500);
   set_al(300);
   set_wc(30);
   set_ac(17 );
   set_aggressive(0);
   xy=0;
   while(xy<40){
xy++;
   heal=clone_object("/obj/heal");
move_object(heal,this_object());
 }
}
