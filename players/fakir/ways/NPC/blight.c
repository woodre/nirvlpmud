#include "/players/fakir/color.h"
inherit "/obj/monster";
int ack,qq,q,kkk;
object envir;
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("blight");
  set_race("demon");
  set_short(REVERSE+YELLOW+"Blight"+OFF);
  set_long(
"A sickening mass of twisted flesh, so hideously deformed you can not tell\n"+
"which part was once head, legs, arms or ass.  It breaths in short gasps,\n"+
"and expands and contracts with each breath.  Its skin is covered in blots\n"+
"of yellow goo and half-healed scabs.\n");
  set_level(17);
  set_hp(425 +random(50));
  set_al(-500);
  set_wc(22 +random(5));
  set_ac(13 +random(3));
  set_dead_ob(this_object());
  set_chat_chance(20);
  load_chat(YELLOW+"Your worst fears are manifest in me, and I shall infest you."+OFF+"\n");
  load_chat(YELLOW+"The Blight drips yellow puss-like fluid on the ground."+OFF+"\n");
  load_chat(YELLOW+"The Blight hisses: 'You shall become as me, the Ways shall see to that!"+OFF+"\n");
  set_a_chat_chance(20);
  load_a_chat(RED+"The Blight's skin sizzles and pops."+OFF+" \n");
  load_a_chat("Blight exhales at the moment of impact..."+BOLD+GREEN+"**W H O O S H**"+OFF+"...\n");
  load_a_chat(RED+"Blight sucks in huge gulps of air and bloats into a hideous mass."+OFF+"\n");
  load_a_chat(YELLOW+"A vile odor assaults your nostrils, making you retch and gag."+OFF+"\n");
  set_chance(10);
  set_spell_dam(10);
  set_spell_mess1("Blight opens its mouth and a foul stench issues forth.\n");
  set_spell_mess2("The Blight envelopes you in a foul breath. \n");
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
  move_object(clone_object("/players/fakir/ways/WEP/dagger.c"),
  environment(this_object()));
  move_object(clone_object("/players/fakir/ways/OBJ/blob.c"),
  environment(this_object()));
  tell_room(environment(this_object()),
  "The Blight flattens into a puddle of slimy puss. \n");
  return 0; }
