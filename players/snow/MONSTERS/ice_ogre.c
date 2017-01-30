inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
     set_name("Ice Ogre");
     set_short("An Ice Ogre");
     set_race("ogre");
     set_alias("ice ogre");
     set_long(
"This strange monster looks like an ice sculpture of an ogre... \n"+
"But it moves and acts threatening!\n");
     set_level(10);
     set_ac(5);
     /* 05/17/06 Earwax: snow demons should be weak v fire */
     set_armor_params("other|ice",0,100,0); /* No ice damage */
     set_armor_params("other|fire",0,-100,0);   /* Double fire damage */
     set_wc(25);
     set_hp(200);
    set_heal(0,0);
     set_al(-100);
     set_aggressive(1);
     set_a_chat_chance(10);
     load_a_chat("The Ice Ogre is falling apart!\n");
set_chance(20);
set_spell_mess1("The Ice Ogre smashes you!\n");
set_spell_mess2("The Ice Ogre smashes its foe!\n");
set_spell_dam(40);
call_out("decay",1);
   }
}
 
decay() {
  object master;
  if(!environment()) return;
  master = present("ogre magi", environment(this_object()) );
/* This line is causing errors when it kills the monster
  this_object()->hit_player(10);
replacing it with the following line - illarion 3 dec 2004 */
  this_object()->heal_self(-10);
  if(this_object()->query_hp() < 100) {
    say("The Ice Ogre crumbles to pieces and melts away!\n");
    destruct(this_object()); return 1; }
  if(master && master->query_attack() &&
     master->query_attack() != this_object()->query_attack() ) {
    write("The Ice Ogre turns to attack "+master->query_attack()->query_name()+
           "!\n");
    this_object()->attack_object(master->query_attack());
    }
  call_out("decay", 5);
  return 1;
}
