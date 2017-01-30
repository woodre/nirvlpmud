inherit "obj/monster";

reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("gollum");
   set_alias("basic");
   set_short("Gollum");
   set_long("This is a decrepit, wrinkled, grey-skinned dude.\n");
   set_level(5);
   set_hp(350);
   set_al(100);
   set_wc(10);
   set_ac(6);
set_chat_chance(40);
load_chat("Gollum says:Im coming for you my preciousssssssssssssss.\n");
   gold=clone_object("obj/money");
   gold->set_money(random(100)+200);
   move_object(gold,this_object());
   armor=clone_object("/players/nightshade/armor/gldring");
   move_object(armor,this_object());
}
