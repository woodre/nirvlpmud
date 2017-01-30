inherit "obj/monster";
 
reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("old lady");
   set_race("human");
   set_alias("lady");
   set_short("An old lady");
   set_long("\n"+
"An old lady.  She seems to be minding her own business as she strolls along\n"+
"down the street.\n");
   set_level(15);
   set_hp(125+ random(100));
   set_al(250);
   set_wc(17);
   set_ac(9);
   set_chance(20);
   set_spell_dam(7);
   set_spell_mess1("Lady smacks you over your head with her purse!\n");
   set_spell_mess2("Lady screams HELP!  MUGGER!\n");
   set_chat_chance(2);
   load_chat("Lady says: How are you doing today?\n");
   load_chat("Lady says: Nice day isn't it?\n");
   gold=clone_object("obj/money");
   gold->set_money(random(200)+100);
   move_object(gold,this_object());
   move_object(clone_object("players/pathfinder/detroit/weapons/purse"), this_object());
}
   
 

