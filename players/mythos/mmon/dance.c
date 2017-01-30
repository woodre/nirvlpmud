inherit "obj/monster";
reset(arg)  {
  object gold, ob;
  int n, z, amo;
  string see, lookie, allie, gen;
  ::reset(arg);
  if(arg) return;
  n = random(6);
  if(n == 0) {  see = "Dancing College Girl"; allie = "girl"; gen = "female";
  lookie = "A young college girl who is looking for a good time.\n"; }
  if(n == 1) {  see = "Dancing College Guy"; allie = "guy"; gen = "male";
  lookie = "A young college guy who is looking for a good time.\n"; }
  if(n == 2) {  see = "Dancing Gal"; allie = "gal"; gen = "female";
  lookie = "A yound woman who is enjoying the music\n"; }
  if(n == 3) {  see = "Dancing Guy"; allie = "guy"; gen = "male";
  lookie = "A young man who is enjoying the music.\n"; }
  if(n == 4) {  see = "Dancing Salary-Man"; allie = "man"; gen = "male";
  lookie = "A man who has come here to forget the rigors of work.\n"; }
  if(n == 5) {  see = "Dancing Career-Woman"; allie = "woman"; gen = "female";
  lookie = "A woman who has come here to forget the rigors of work.\n"; }
  set_name("dancer");
  set_gender(gen);
  set_short(see);
  set_alias(allie);
  set_race("human");
  set_long(lookie);
  set_level(13+random(8));
  if(query_level() == 13) { 
     amo = 500 + random(400); set_wc(17 + random(10)); set_ac(10); 
     set_hp(190 + random(100));}
  if(query_level() == 14) {
     amo = 700 + random(300); set_wc(18 + random(9)); set_ac(11); 
     set_hp(210 + random(100));}
  if(query_level() == 15) {
     amo = 725 + random(300); set_wc(20 + random(10)); set_ac(12); 
     set_hp(225 + random(100)); }
  if(query_level() == 16) {
     amo = 740 + random(300); set_wc(25 + random(10)); set_ac(13 + random(5)); 
     set_hp(375 + random(100)); }
  if(query_level() == 17) {
      amo = 800 + random(300); set_wc(27 + random(10)); set_ac(14 + random(5)); 
     set_hp(400 + random(150)); }
  if(query_level() == 18) {
     amo = 500 + random(1000); set_wc(29 + random(8)); set_ac(15 + random(5)); 
     set_hp(500 + random(100)); }
  if(query_level() == 19) {
     amo = 1000 + random(2000); set_wc(34 + random(8)); set_ac(16 + random(5)); 
     set_hp(520 + random(100)); }
  if(query_level() > 19) {
     amo = random(4000)+2000;
     set_wc(36 + random(10));
     set_ac(17 + random(5));
     set_hp(600 + random(150));
  }
  set_al(-random(1000));
  set_aggressive(0);
  set_chat_chance(10);
  load_chat("The Dancer moves to the beat.\n");
  load_chat("The Dancer motions to you to join in.\n");
  if(random(7) == 0) {
  ob = clone_object("/players/mythos/mmisc/jewel.c");
  z = random(3);
  if(z == 0) { ob->set_short("A gold wristwatch"); ob->set_id("wristwatch"); }
  if(z == 1) { ob->set_short("A gold necklace"); ob->set_id("necklace"); }
  if(z == 2) { ob->set_short("A diamond pierce"); ob->set_id("pierce"); }
  move_object(ob,this_object());
  move_object(clone_object("/players/mythos/mmisc/fan.c"),this_object());
  } else {
  gold=clone_object("obj/money");
  gold->set_money(amo);
  move_object(gold,this_object()); }
}

#include "/players/mythos/amon/hb_ag.h"