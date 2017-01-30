/* 03/13/06 Earwax: made lich wield staff */

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
  object ob, ob2, ob3;
ob3 = clone_object("/players/saber/gems/opal.c");
move_object(ob3,this_object());
  ob = clone_object("/players/saber/weapons/stormstaff.c");
move_object(ob,this_object());
  init_command("wield staff");
 ob2 = clone_object("/players/saber/food/potionheal.c");
move_object(ob2,this_object());
     set_name( "storm lich" );
     set_short("The Storm Lich");
     set_alias("lich");
     set_alt_name("saber_lich"); /* Fred  5-15-03 */
     set_race( "undead");
     set_long("A gaunt skeletal looking figure covered with the rotting rags of what once\n"+
     "must have been fine garments.  The storm lich glares out at you with\n"+
     "shadowy pinpoints of crimson red illumination from the depths of deep\n"+
     "black eye sockets.  The lich is surrounded by an frigid aura of inky black\n"+
     "darkness which sends chills deep into your heart.\n");
     set_level(23);
     set_ac(18);
     set_wc(40);
     set_hp(1000);
     set_al(-1000);
     set_aggressive(0);
     set_chat_chance(17);
     set_a_chat_chance(25);
    load_chat("Storm Lich summons a bolt of lightning.\n");
    load_chat("Storm Lich waves a hand, and there is a boom of thunder.\n");
    load_chat("Storm Lich hisses: And for you there will be no tomorrow...\n");
    load_chat("Storm Lord basks in the glory of the surrounding chaos.\n");
    /* added as another spell
    load_chat("Storm Lich drains some of your life force.\n");
    */
    load_a_chat("Storm Lich summons a  * * BOOM * * of thunder.\n");
    /* added as another spell
    load_a_chat("Storm Lich blasts you with a bolt of blue lightning.\n");
    */
    load_a_chat("Storm Lich hisses at you.\n");
    load_a_chat("Storm Lich glories in the surrounding chaos.\n");
    load_a_chat("Storm Lich hisses: None but the storm Lord may sit upon my throne.\n");
    load_a_chat("Storm Lich hisses: You are doomed.\n");
    add_spell("lightning column",
"\n#MN# engulfs you in a column of blue lightning!\n\n",
"\n#MN# engulfs #TN# in a column of blue lightning!\n\n",
20,90,"other|electric");
    add_spell("lightning bolt",
"\n#MN# blasts you with a bolt of blue lightning!\n\n",
"\n#MN# blasts #TN# with a bolt of blue lightning!\n\n",
10,30,"other|electric",5); /* can hit any attacker */
    add_spell("life drain",
"\n#MN# drains some of your life force!\n\n",
"\n#MN# drains some of #TN#'s life force!\n\n",
10,25,"other|evil",0,"life_drain_heal");
    set_ac_bonus(3);  /* for the heal from the life drain */

/* converted spell and spell-like chats to add_spell - illarion dec 2004
    set_spell_mess1("Storm Lich engulfs its foe in a column of blue lightning.\n");
    set_spell_mess2("Storm Lich engulfs you in a column of blue lightning.\n");
     set_chance(25);
     set_spell_dam(90);
*/
   }
}
/* added by illarion dec 2004 */
life_drain_heal(object target,object room,int dam) {
  if(room && dam > 0) {
    tell_room(room,query_name()+" looks invigorated by the stolen life!\n",({this_object()}));
    hit_point+=dam;
  }
}
