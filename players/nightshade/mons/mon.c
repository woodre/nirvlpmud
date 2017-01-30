inherit "obj/monster";

reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("basic monster");
   set_race("monster");
   set_alias("basic");
   set_short("Basic monster");
   set_long("This is a basic monster.\n");
   set_level(10);
   set_hp(150);
   set_al(-1000);
   set_wc(14);
   set_ac(8);
   set_chance(30);
   set_spell_dam(50);
   set_spell_mess1("This message goes to the room.");
   set_spell_mess2("This message goes to the person who gets hit.\n");
   set_chat_chance(10);
   load_chat("This is one message the monster will say.\n");
   load_chat("This is another one it will say.\n");
   gold=clone_object("obj/money");
   gold->set_money(random(100)+200);
   move_object(gold,this_object());
   weapon=clone_object("/players/sweetness/newbie/weapon");
   move_object(weapon,this_object());
   armor=clone_object("/players/sweetness/newbie/plate");
   move_object(armor,this_object());
}

/*  wc was 10 ac was 6 hp was 100 - mythos <6-17-96> */
