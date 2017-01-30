inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
object ob;
 
  ob = clone_object("/players/snow/WEAPONS/souleater.c");
  move_object(ob,this_object());
 
     set_name("ogre mage");
     set_short("A huge blue ogre");
     set_race("ogre");
     set_alias("mage");
     set_long("Standing before you is the largest, bluest ogre you have ever \n" +
                    "seen. You realize this must be an ogre mage. He is wielding a \n" +
                    "blade that is blacker than night and in his palm the long sword \n" +
                    "looks like a dagger. You realize that this could probably be the \n" +
                    "last fight of your life.\n");
     set_level(25);
      set_ac(12);
     init_command("wield souleater");
   set_hp_bonus(300);
     set_wc(60);
/* NEW CODE */
/* boosted from 25 to 75 - verte */
set_wc_bonus(75);
     set_hp(1000);
     set_heal(5,1);
     set_al(-1000);
     set_aggressive(0);
      set_dead_ob(this_object());
call_out("ogre_life",5);
 
set_spell_mess1("The ogre mage's blade drains life force from his victim.\n");
set_spell_mess2("The mage's blade slices into your body and you feel a\n"+
                            "part of your soul being eaten by the black metal.\n");
set_chance(35);
set_spell_dam(50);
 
set_chat_chance(10);
load_chat("The ogre roars: Leave now and I will allow you to live!\n");
set_a_chat_chance(10);
load_a_chat("The mage roars: You wish my blade do you? Well- feel it!\n");
  money = random(3000)+3500;
   }
}

query_spell_point() { return 1000; }

monster_died() {
  write_file("/players/snow/closed/q/mon", ctime(time())+" "+
    attacker_ob->query_real_name()+" killed the ogre mage.\n");
  return 0; }
 
ogre_life() {
  if(attacker_ob) {
    summon2();
    if(attacker_ob == this_object()) pissed();
    if(this_object()->query_wc() < 40) pissed();
  }
call_out("ogre_life",10);
return 1;
}

summon2() {
  object og;
  if(random(10) < 3) {
    og = clone_object("players/snow/MONSTERS/ice_ogre.c");
    move_object(og, environment(this_object()) );
  og->attack_object(attacker_ob);
  }
  return 1;
}

pissed() {
  tell_room(environment(this_object()),"The Ogre Magi grows angry...\n");
  attacker_ob = 0; hunter = 0; hunted = 0;
  set_wc(90);
  hit_point += 300;
  set_heal(10,1);
  return 1;
}

heal_self(arg) {
  if(arg < -15) arg = -15;
  ::heal_self(arg);
  return 1; }
