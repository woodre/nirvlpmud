/* Updated monster's level and wc,ac and added spells to
strengthen by Pestilence per Dragnar 8-9-2014 */
/*
#include "defs.h"
*/

#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("wolf");
  set_alt_name("black wolf");
  set_race("creature");
  set_short("Black Wolf");
set_long(
	"  A giant black wolf found only in the caves of Drygulch.  It's \n"+
	"jet-black fur, yellow fangs and fire red eyes give it a hideous \n"+
	"appearance.  The pelt, however, is a precious commodity.  It \n"+
	"seems to be hungering for blood...... yours! \n");
  set_level(22);
  set_hp(750);
  set_al(-50);
  set_wc(40);
  set_wc_bonus(19);
  set_ac(20);
  set_heal(10,20);
  set_al(-50);
  set_aggressive(1);
  set_dead_ob(this_object());
  set_a_chat_chance(10);
  load_chat("Glazed eyes gleam out from the darkness....\n");
  load_chat("Something hungers....\n");
  load_a_chat("A black beast growls....\n");
  load_a_chat("The black beast lunges at you!\n"); 

/*
  set_chance(15);
  set_spell_dam(38);
  set_spell_mess1("The wolf suddenly lunges and its teeth sink into flesh!\n");
set_spell_mess2(
  "\n\nThe black beast's canine teeth "+
  RED+"RIP OPEN "+NORM+"a huge wound...\n\n");
*/

add_spell("teeth",
  "\n\nThe black beast's canine teeth "+
  RED+"RIP OPEN "+NORM+"a huge wound...\n\n",
"The wolf suddenly lunges and its teeth sink into flesh!\n",
15,38,0,0);

add_spell("bite",
"$W$#RET#               _..._     ___     ___     ___     ___     _..._$N$\n"+
"$W$             ,'   `::. ,~  `:. ,~  `:. ,~  `:. ,~  `:. ,'   `::.$N$\n"+
"$W$            :      `:::     `::     `::     `::     `::      `:::$N$\n"+
"$W$            :      .:::     .::     .::     .::     .::      .:::$N$\n"+
"$W$            :      .:::`.  .;' `.  .;' `.  .;'.`.  .;':      .:::$N$\n"+
"$W$            :      .:::  `.'    .`.'.:   `.'   ::`.'  :.     .:::$N$\n"+
"$W$            :.     .::'          :::            :     `:     .:::$N$\n"+
"$W$            `:     .::            :                    :     .::'$N$\n"+
"$W$             :     .::            .                    :.    .::$N$\n"+
"$W$              :    ::'                                 `:   .::.$N$\n"+
"$W$              .\\   `:      ,:                   :.      :  .::.:$N$\n"+
"$HR$              :.$W$\\   :.    :.:                   :`:    .' .:$HR$:.:$N$\n"+
"$HR$               ::$W$`.  :   :'::                   : `:   : .;'$HR$.:$N$\n"+
"$HR$                :  $W$`.;  :'.::                   :  ::  ;:'$HR$ ::$N$\n"+
"$HR$                    . $W$ :' .::.                 .:  .::   $HR$  :$N$\n"+
"$HR$                    :$W$ :'   :::                 :'   .::  $HR$  .$N$\n"+
"$W$                      :    `::                 :    .::$N$\n"+
"$W$                     :'    .::.               .:    .:::$N$\n"+
"$W$                     :     .:::  ,:.     .:.  :'    .:::$N$\n"+
"$W$                     :     .:::,'  `:. ,'  `:.:     .:::$N$\n"+
"$W$                     :     .:::     :::     :::     .:::$N$\n"+
"$W$                     :     .:::     :::     :::     .:::$N$\n"+
"$W$                      `._ .::'.`._.::' `._.::'.`._ .::' $N$\n"+      
"$W$                         ~~~   ::             ::  ~~~$N$\n",
"#MN# tears into #TN# with a mighty bite!\n",
30,"20-80",0,3);

}

monster_died() {
  move_object(clone_object("players/eurale/Maze/OBJ/pelt2"),
      environment(this_object()));
return 0; }

init() {
  ::init();
  add_action("Nope","north");
  add_action("Nope","south");
  add_action("Nope","east");
  add_action("Nope","west");
}

Nope() {
  tell_room(environment(),"The wolf snarls and blocks the way...\n");
  return 1; }
