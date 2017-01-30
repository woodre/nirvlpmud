#include "/players/brittany/ansi"
inherit "obj/monster.c";

reset(arg)  {
   object gold, ob, ob2, ob3;
   ::reset(arg);
   if(arg) return;

   
   set_name("nyar");
   set_alias("man");
   set_alt_name("priest");
   set_race("human");
   set_short("Nyar, the crawling chaos");
set_long("A dark man in a yellow silk robe, lined with red and\n"+
"on his face he has a yellow silk mask, his eyes peering through\n"+
"has a darkness in them that would burn a soul.  His hands look\n"+
"monstrous and clawlike.  He is the dark high priest, legended\n"+
"never to have been described.\n");
   set_gender("male");
   set_level(20);
   set_hp(500);
   set_wc(30);
   set_ac(17);
ob=clone_object("/players/brittany/kadath/armor/cloak.c");
move_object(ob,this_object());
ob2=clone_object("/players/brittany/kadath/armor/mask.c");
move_object(ob2,this_object());
   set_al(-50);
   set_aggressive(0);
   set_dead_ob(this_object());
   
   set_chat_chance(9);
load_chat("The dark figure raises his clawlike paw and points\n"+
"to the circle inside the ringed altar.\n");
   
   set_chance(10);
   set_spell_dam(30);

set_spell_mess1(
"The dark man swings wildly with his paw, scratching deep gashes into you\n");
   
   gold = clone_object("obj/money");
   gold->set_money(1000);
   move_object(gold,this_object());
}

monster_died() {
   tell_room(environment(this_object()),
  "The crawling chaos SCREECHES one last breath, before falling dead.\n\n");
   return 0; }

heart_beat() {
  int x; x = random(12);
  ::heart_beat();
  if(this_object()->query_attack()) {
    if(x > 10) {
      move_object(clone_object("/players/vertebraker/beasts/brit_spirit.c"),environment(this_object()));
      present("spirit",environment(this_object()))->attack_object(this_object()->query_attack());
      tell_room(environment(this_object())," A mystical wraith appears and joins the fray . . .\n");
     }
}
}
