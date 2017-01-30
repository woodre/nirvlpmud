
inherit "obj/monster";

reset(arg)
{
  object weapon, armor;
  ::reset(arg);
  if(arg) return;
  set_name("rebel");
   set_race("human");
  set_alias("rebel");
  set_short("A Rebel Warrior");
  set_long("This is a warrior who fights for his country\n"+
  "He is a strong man who fights for what he thinks is right, however,\n"+
 "he does not always use the proper means\n"+
  "He is willing kill you in the name of glory\n");

/*
  Changed to spec's by Saber.  
*/
  set_level(20);
  set_hp(500);
  set_al(500);
  set_wc(30);
  set_ac(17);
   set_money(700);
/*
   set_spell_dam(30);
   set_spell_mess("The Rebel strikes you down in the name of his country");
   set_chance(5);
*/
   weapon=clone_object("players/pain/closed/weapons/rebelweap.c");
  move_object(weapon,this_object());
  armor=clone_object("players/pain/closed/armor/rebelarmor.c");
  move_object(armor,this_object());
}

