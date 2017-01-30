inherit "obj/monster";

reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("bugbear");
   set_short("Bugbear");
set_long("This is one scared dude. He has brick red hair and yellow skin. He stands about 7 feet tall and is in a hurry, so dont get in his way.\n");
   set_level(10);
   set_hp(150);
   set_al(-250);
   set_wc(14);
   set_ac(8);
   gold=clone_object("obj/money");
   gold->set_money(random(200)+200);
   move_object(gold,this_object());
}
