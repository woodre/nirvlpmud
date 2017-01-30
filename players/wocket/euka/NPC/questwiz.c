#include "/players/wocket/closed/ansi.h"
inherit "obj/monster.c";
object deadone;
int wait;

reset(arg){
  ::reset(arg);
  if(arg) return;
  set_name("makai");
  set_short(BOLD+"Makai"+OFF+", the archmage");
  set_long("Dark robes billow around this sinister looking mage.  White hair\n"+
           "and wrinkles cover his bitter face.  An evil grin seems to always\n"+
           "adorn his face.  Magic sparkles from his finger tips.\n");
  set_long("yes\n");
  set_level(20);
  set_hp(500);
  set_wc(18);
  set_ac(17);
  set_race("dark elf");
  set_al(-1000);
  set_heart_beat(1);
}

heart_beat(){
object att;
object shield;
string spell,spellshort;
  ::heart_beat();
  if(query_attack()){
    att = query_attack();
    if(deadone){
        if(environment(deadone) != environment(this_object())){
          move_object(this_object(), environment(deadone));
          say("Makai appears from a cloud of smoke.\n");
          say("Makai exclaims, \"DIE!\"\n");
          this_object()->attack_object(deadone);
        }
        if(att != deadone){
          this_object()->attack_object(deadone);
        }
    }
  
     if(random(3)){
       switch(random(4)){
         case 0:  spell = "fireball"; spellshort = HIR+"         F I R E B A L L \n"+OFF;
         break;
         case 1:  spell = "iceball"; spellshort = HIC+"         I C E B A L L\n"+OFF;
         break;
         case 2:  spell = "lightning bolt"; spellshort = HIY+"         L I G H T N I N G  B O L T\n"+OFF;
         break;
         case 3:  spell = "elemental blast"; spellshort = HIG+"         E L E M E N T A L  B L A S T\n"+OFF;
         break;
         } 
       tell_object(att,"\nMakai speaks some arcane enchantments and hurls a\n"+
                spellshort+
                "towards you.\n\n");
       shield = present("euka_quest_shield",att); 
       if( shield && shield->query_polish() && shield->query_worn() ){
         tell_object(att,"The "+spell+" consumes your shield but, deflects some of the blast back at Makai!\n");
         heal_self(-40);
         att->hit_player(20);
       }
       else
        att->hit_player(60);
     }  
     if(hit_point < ((max_hp*10)/100) ){
       say("\nMakai says, \"You may have bested me this time but I'll be back!\"\n");
       say("Makai vanishes in a cloud of smoke.\n\n");
       destruct(this_object());
     }
  } 
  else{
    if(deadone){
      if(environment(deadone) != environment(this_object())){
        move_object(this_object(),environment(deadone));
        say("Makai appears from a cloud of smoke.\n");
      } 
      say("Makai exclaims, \"DIE!\"\n");
      this_object()->attack_object(deadone);
    }
    else{
      wait++;
      if(wait > 20){
        say("Makai vanishes in a puff of smoke.\n");
        destruct(this_object());
      }
    }
  }
}

set_attacker(object ob){ deadone = ob; }
