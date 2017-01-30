inherit "obj/monster";

reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("servant");
   set_race("servant");
   set_alias("ghost");
   set_ep(335800);
   set_short("ghost of maid servant");
   set_long("	Obviously once beautiful in life, this watery spirit is now\n"+
"  a deteorated and pathetic creature. Shifting between a ghostly and undead\n"+
"  state, this maid servant sure spooks the hell out of you.\n");
   set_level(15);
   set_hp(234);
   set_al(-1000);
   set_wc(20);
   set_ac(13);
   set_chance(20);
   set_spell_dam(13);
set_spell_mess1("The maid servant rakes you, and drains you of your life essence!");
set_spell_mess2("The maid servant emits a banshee wail!");
   set_chat_chance(2);
load_chat("The servant moans and sobs quietly\n");
load_chat("The servant grins evilly at you.\n");
load_chat("The servant wails soflty.\n");
   gold=clone_object("obj/money");
   gold->set_money(random(200)+1500);
   move_object(gold,this_object());
}
