generic_hp_bonus() & generic_sp_bonus()

add into set_max_hp() & set_max_spell()


/*****  CHANGES TO set_max_hp() & set_max_spell() IN PLAYER.C ***************************/

set_max_hp() {
	object gen_ob; /* generic object */
	int hp_tmp;    /* generic hp value */
    if (stamina < 21)
    max_hp = ex_lv*2 + 42 + level * 8 + (stamina - 8) * 8;
  if (stamina > 20)
    max_hp = ex_lv*2 + 42 + level * 8 + 96 + (stamina - 20) * 2;
/* add by Forbin 2005.06.06 -supports generic_sp_bonus() objects ******************/
    if((gen_ob = this_player()) && (gen_ob = present("generic_hp_bonus", gen_ob)))
    {
      while(gen_ob) 
      {
        object ob;
        ob = next_inventory(gen_ob);
        if((hp_tmp = gen_ob->gen_hp_bonus())) 
          max_hp += hp_tmp;
        gen_ob = ob;
      }
    }
/* end addition by Forbin 2005.06.6 ***********************************************/
  if (max_hp < 5) max_hp = 5;
  if (hit_point > max_hp) hit_point = max_hp;
}

set_max_spell() {
  object gen_ob; /* generic object */
  int sp_tmp;    /* generic sp value */
      if(magic_aptitude < 21)
      max_spell = 42 + ex_lv*3 + level * 8 + (magic_aptitude - 8) * 8;
    if(magic_aptitude > 20)
      max_spell = 42 + ex_lv*3 + level * 8 + 96 + (magic_aptitude - 20) * 2;
/* add by Forbin 2005.06.06 -supports generic_sp_bonus() objects */
    if((gen_ob = this_player()) && (gen_ob = present("generic_sp_bonus", gen_ob)))
    {
      while(gen_ob) 
      {
        object ob;
        ob = next_inventory(gen_ob);
        if((sp_tmp = gen_ob->gen_sp_bonus())) 
          max_spell += sp_tmp;
        gen_ob = ob;
      }
    }
/* end addition by Forbin 2005.06.6 ***********************************************/
    if (max_spell < 0)  max_spell = 0;
    if (spell_points > max_spell) spell_points = max_spell;
}

/***********************************************************************************************/