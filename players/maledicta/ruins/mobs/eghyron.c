#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object armor;
object sword;
  ::reset(arg);
  if(arg) return;

set_name("eghyron");
set_alt_name("hunter");
set_alias("hunter");
set_race("human");
set_short("Eghyron the "+GRN+"Hunter"+NORM+" ["+GRN+"wounded"+NORM+"]");
set_long(
  "  Standing before you is rugged looking man who looks as though he\n"+
  "has seen too much combat and killing in his long lifetime. His armor\n"+
  "is in tatters, looking as though it was nearly ripped from his body\n"+
  "by huge claws. His hair and dark beard are matted with blood, some\n"+
  "his own, some not. He carries a huge two-handed sword, its once razor\n"+
  "sharp edge now dulled from use. He looks at you expectantly, as though\n"+
  "waiting for you to say something.\n");
set_level(5);
set_hp(150);
set_al(500);
set_wc(16);
set_ac(6);
set_chat_chance(15);
  load_chat("Eghyron says: Are you here to help?\n");
  load_chat("Eghyron asks: Ask me what you will, I am too tired to do anything but\n"+
            "answer.\n");
  load_chat("Eghyron looks at you intently, as though measuring your ability.\n");
  load_chat("The hunter limps over to stand by the wall.\n");
  load_chat("Eghyron says: Just tell me your here to help, that is all I ask.\n");
set_a_chat_chance(15);
  load_a_chat("Eghyron shouts, 'I should have known!!!'\n");
  load_a_chat("The hunter swings his huge sword into a ready position.\n");
  
set_chance(10);
set_spell_dam(10);

set_spell_mess1(
  "Eghyron swings his massive sword, cutting deeply into his foe!\n");
set_spell_mess2(
  "Eghyron swings at you, cutting into your flesh!");

armor = clone_object("/players/maledicta/ruins/obj/earmor.c");
move_object(armor, this_object());
sword = clone_object("/players/maledicta/ruins/obj/esword.c");
move_object(sword, this_object());
}

init(){
    ::init();
    if(this_object()->query_hp() > ((this_object()->query_mhp())/4)){
    	(this_object()->set_hp(this_object()->query_mhp()/2));
    	}
           
}



void catch_tell(string str){
                           
    string who;
    string what;
    if (sscanf(str, "%s says: %s\n", who, what) == 2) {

	what = lower_case(what);
 	if (sscanf(what, "%shelp", who)){
    write("\nEghyron looks at you closely, and nods.\n");
    write(
          "He says: 'I was hoping you would say that. I was injured trying to\n"+
          "          clean the evil from these once holy halls. And now I am\n"+
          "          afraid I cannot continue to fight.'\n\n");
    write( 
          "He then sighs and continues, 'I understand that you may not want\n"+
          "to adventure out into such danger without a reward, and so I am\n"+
          "willing to offer you a sum of coins for each demon you kill here.'\n"+
          "\nHe then smiles, 'But you will need proof of the kill.'\n\n"+
          "Eghyron stands and walks over to you, a visible limp making his\n"+
          "every move a struggle.\n\n"+
          "He says, 'Each of these creatures here will drop an item, proof of\n"+
          "          their demise. Bring it to me, and I will reward you with\n"+
          "          a great number of coins. Some creatures here aren't worth\n"+
          "          the reward though, you will know which ones that is when\n"+
          "          you encounter them.'\n\n"+
          "He clasps your hand, 'Bring me the items and 'collect bounty' for\n"+
          "                      each of them. And good luck, the realm and\n"+
          "                      it's Gods are backing your efforts.\n"+
          "He then perks up for a second, 'Before I forget, you can also\n"+
          "                                get past the guardian by 'circling\n"+
          "                                ruins' at the entrance, that way\n"+
          "                                you can avoid the guardian at the\n"+
          "                                entrance.\n"+
          "Eghyron then walks over and sits down, waving to you and wishing you\n"+
          "luck once again.\n");
                 }
   }
}