#include "/players/wocket/closed/ansi.h"
inherit "obj/monster.c";

reset(arg){
int i;
  ::reset(arg);
  if(arg) return;
set_name("moleman");
set_race("mole");
set_al(-500);
set_chat_chance(10);
load_chat("The moleman twiches his nose.\n");
load_chat("The moleman grins at you.\n");
load_chat("The moleman blankly stares at you.\n");
i=random(4);
switch(i){
case 0:  guard();
move_object(clone_object("/players/wocket/caves/OBJ/spear.c"),this_object());
break;
case 1:  warrior();
move_object(clone_object("/players/wocket/caves/OBJ/club.c"),this_object());
break;
case 2:  mage();
break;
case 3:  thief();
move_object(clone_object("/players/wocket/caves/OBJ/dagger.c"),this_object());
break;
}
}


guard(){
  set_short("A moleman guard");
  set_long("This mole like creature is brandishing a small staff.  He wears little\n"+
           "clothes; mostly leather straps with pouches adorn his furry body.  His\n"+
           "black eyes dart around in the dark as his nose twitches smelling his\n"+
           "sourroundings.\n");
  set_alias("guard");
  set_level(17);
  set_hp(425);
  set_wc(24);
  set_ac(14);
  set_spell_dam(20);
  set_chance(25);
  set_spell_mess1("The guard stabs at his opponent.");
  set_spell_mess2("The guard stabs at his opponent.");
}

warrior(){
   set_short("A moleman warrior");
   set_long("His nose twitches back and forth as he eyes the room blindly.  A huge club\n"+
            "is this moleman's weapon of choice.  Many teeth of dead foes have been\n"+
            "tied to a rope around his neck.  Two unkept teeth stick outwards and his\n"+
            "fur is oily and dirt ridden.\n");
   set_alias("warrior");
   set_level(17);
   set_hp(425);
   set_wc(33);
   set_ac(10);
   set_spell_dam(20);
   set_chance(25);
   set_spell_mess1("The warrior bashes his opponent with a club.");
   set_spell_mess2("The warrior bashes his opponent with a club.");
}

thief(){
    set_short("A moleman thief");
    set_long("A very suspicious moleman.  He seems to eye you even though they\n"+
             "are completely black in this light.  His fur is well kept and he moves\n"+
             "very gracefully around.  His nose never twitches and he looks like he is\n"+
             "up to some sort of trick.\n");
    set_alias("thief");
    set_level(17);
    set_hp(400);
    set_wc(24);
    set_ac(20);
    set_spell_dam(30);
    set_chance(20);
    set_spell_mess1("The thief slides behind his opponent stabbing them in the back.");
    set_spell_mess2("The thief slides behind his opponent stabbing you in the back.");
}

mage(){
    set_short("A moleman mage");
    set_long("This moleman is completely naked and his fur is shaved in many patterns\n"+
             "around his body.  The little fur he does have is very slick but well kept.\n"+
             "His eyes are closed as his nose moves around in the air sniffing repetively\n"+
             "as if he is searching for a perticular odor.\n");
    set_alias("mage");
    set_level(17);
    set_hp(425);
    set_wc(27);
    set_ac(7);
    set_spell_dam(70);
    set_chance(45);
    set_spell_mess1("The air crackles as a blast of lightning strikes the mage's opponent.");
    set_spell_mess2("The air crackles as a blast of lightning strikes the mage's opponent.\n"+
                    RED+"...pain streaks though your body as your skin burns..."+NORM);
}
