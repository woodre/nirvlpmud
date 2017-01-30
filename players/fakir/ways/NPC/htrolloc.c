inherit "/obj/monster";
int ack,qq,q,kkk;
object envir;
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("trolloc");
  set_alias("troll");
  set_race("creature");
  set_short("A Huge Trolloc");
  set_long(
"A creature of the Dark One, created during the war of the shadow.\n"+
"Huge in stature, vicious in the extreme, he is a twisted blend of\n"+
"animal and human stock, and he kills for the sheer pleasure of\n"+
"killing.  Sly, deceitful and treacherous, he can be trusted\n"+
"only by those he fears. \n");
  set_level(17);
  set_hp(400 +random(50));
  set_al(-600);
  set_wc(25);
  set_ac(14);
  set_dead_ob(this_object());
  set_chat_chance(15);
  load_chat("The trolloc licks his lips and drools. \n");
  set_a_chat_chance(15);
  load_a_chat("The trolloc sidesteps and bites your shoulder. \n");
  set_chance(10);
  set_spell_dam(10 +random(10));
  set_spell_mess1("The trolloc moves with the grace of a cat. \n");
  set_spell_mess2("The trolloc boldly rushes inside your guard and strikes. \n");
}

heart_beat() {
  ::heart_beat();
  if(!environment()) return;
  if(!query_attack()) {
    if(!random(10)) {
      envir = 0;
      ack = allocate(10);
      qq = 0;
      kkk = 0;
      envir = all_inventory(environment(this_object()));
      for(q=0;q<sizeof(envir);q++) { 
        if(envir[q]->is_player()) {
          ack[qq] = envir[q];
          qq++; }
        }
      q = 0;
      while(q<sizeof(ack) && !kkk) {
        if(ack[q] && !random(5)) {
        attack_object(ack[q]);
        kkk = 1;
        }
      q++; } 
      }
    } 
  else if(query_attack() && query_attack() == this_object()) { heal_self(100000); }
  }

monster_died() {
  move_object(clone_object("/players/fakir/ways/OBJ/purse2.c"),
      environment(this_object()));
  tell_room(environment(this_object()),
  "The trolloc whistles to his tribe with his last breath. \n");
  return 0; }
