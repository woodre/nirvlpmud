show_stats() {
   int i;
   object yjy,yjyj;
   if(this_object()->query_level())
      write(short() + "\nlevel: " + this_object()->query_level() + "\n");
   if (this_object()->is_player()) 
       write("extra_level: "+this_object()->query_extra_level()+ "\n");
   if (call_other(this_object(), "is_player", 0) && call_other(this_object(), "query_level", 0) > 19) {
      write("earmuffs: ");
      if (call_other(this_object(), "query_muffled", 0))
         write("on");
      else
         write("off");
       write("\n");
   }
   if (this_object()->query_invis())
      write("invis: " + this_object()->query_invis() + "\n");
   if(this_object()->query_money())
      write("coins: "+ money + "\n");
   write(  "max: " + max_hp + "\n");
   if (call_other(this_player(), "query_level", 0) > STAT)
      write("hp: " + this_object()->QHitPoint() + "\n");
    write("spell: " + spell_points + "\n");
    write("max spell: " + max_spell + "\n");
    write("experience: "+ experience + "\n");
    write("armor class: " + armor_class);
    if (head_armor)
	write("\narmor: " + call_other(head_armor, "rec_short", 0));
    write("\nweapon class: \t"); write(weapon_class);
    if (name_of_weapon)
	write("\nweapon: " + call_other(name_of_weapon, "query_name", 0));
   if (!is_npc) {
     write("\nintoxinated:  " + call_other(this_object(), "query_intoxination", 0));
    }
    write("\ncarry: \t" + local_weight);
    if (attacker_ob)
	write("\nattack:  " + call_other(attacker_ob, "query_name"));
    if (alt_attacker_ob)
	write("\nalt attack:  " + call_other(alt_attacker_ob, "query_name"));
    write("\nalign: \t" + alignment + "\n");
    write("gender: \t" + query_gender_string() + "\n");
    if(!is_npc && this_object()->query_pregnancy()){
     i = age - this_object()->query_pregnancy();
     write("pregnancy: "+i+" / 16200 \n");
    }
    if (i = call_other(this_object(), "query_quests", 0))
     {
	write("Quests: \t" + i + "\n");
     write("Quest Points: \t" + query_quest_point() +"\n");
    }
    show_age();
    yjy = environment(this_object());
    if(yjy)
    yjyj = environment(yjy);
    if(yjy)
    write("room: " + file_name(yjy) + "\n");
    if(yjyj) write("Room's room: "+file_name(yjyj) + "\n");
    if(!yjy)  write("room: No environment\n");
    write("this_object()=");
    write(this_object());
    write("\n");
    if(creator(this_object()))
  {
       write("Creator: ");
       write(capitalize(creator(this_object())));
	write ("\n");
    }
      if(call_other(this_object(), "is_player")) 
	write("crime: " + crime + "\n");
}