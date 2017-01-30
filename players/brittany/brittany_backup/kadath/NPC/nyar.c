#include "/players/brittany/ansi"
inherit "obj/monster.c";

int y;
object ob3;

reset(arg)  {
   object gold, ob, ob2;
   ::reset(arg);
   if(arg) return;
   y = 0;

   
   set_name("nyar");
   set_alias("man");
   set_alt_name("priest");
   set_race("human");
   set_short("Nyar, the crawling chaos");
set_long("Nyar is a dark man in a yellow silk robe, lined with\n"+
"red.  His eyes, peering through a yellow mask, are dark\n"+
"and yet burn with an intensity hot enough to burn the\n"+
"soul.  His hands are monstrous and clawlike.  He is the\n"+
"priest, who according to legend has never been described.\n");
   set_gender("male");
   set_level(20);
   set_hp(500);
ob=clone_object("/players/brittany/kadath/OBJ/cloak.c");
move_object(ob,this_object());
ob2=clone_object("/players/brittany/kadath/OBJ/mask.c");
move_object(ob2,this_object());
ob3=clone_object("/players/brittany/kadath/OBJ/tbow.c");
move_object(ob3,this_object());
   init_command("wield bow");
   init_command("wear cloak");
   init_command("wear mask");
   set_wc(30);
   set_ac(17);
   set_al(-1000);
   set_aggressive(1);
   set_dead_ob(this_object());
   
   set_chat_chance(6);
load_chat("The dark figure raises his clawlike paw and points\n"+
"to the circle inside the ringed altar.\n");
   
   set_chance(18);
set_spell_dam(40+random(50));

set_spell_mess1(
"The dark man swings wildly with his paw, scratching deep gashes into his opponent.\n");

set_spell_mess2(
"The dark man swings wildly with his paw, scratching deep gashes into you.\n");
   
   gold = clone_object("obj/money");
   gold->set_money(random(2000));
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
    if(x > 10 && y < 3) {
    move_object(clone_object("/players/brittany/kadath/NPC/spirit.c"),environment(this_object()));
      present("spirit",environment(this_object()))->attack_object(this_object()->query_attack());
      tell_room(environment(this_object())," A mystical wraith appears and joins the fray . . .\n");
      y++;
     }
}
}
