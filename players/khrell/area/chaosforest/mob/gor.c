/*
 *      File:             /players/khrell/area/chaosforest/mob/gor.c
 *      Function:         mob code for random mobs
 *      Author(s):        Khrell@Nirvana
 *      Copyright:        Copyright (c) 2006 Khrell (John Quigley)
 *                                All Rights Reserved.
 *      Source:           10/01/06
 *      Notes:            High-ish level monsters for my chaosforest area.
 *                        these mobs do dish out damage and is not intended
 *                        for low levels or newbies.
 *      Change History:   none as of yet
 */
#include "/players/khrell/define.h"
#include <ansi.h>
inherit "obj/monster";
int X;
int Y;
int Z;
int G;
string SIZE;
string WHAT;
string NAME;
string RACE;
object gold;
object ob;
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  Y = (random(5));
  Z = (random(10));
  X = (Y+18);

  if(X == 18) SIZE = " minor";
  if(X == 19) SIZE = " average";
  if(X == 20) SIZE = " greater";
  if(X == 21) SIZE = " enormous";
  if(X == 22) SIZE = " mighty";

  if(Z == 0) WHAT = ""+NORM+"ungor";
  if(Z == 1) WHAT = ""+NORM+YEL+"gor"+NORM+"";
  if(Z == 2) WHAT = "beastigor"+NORM+"";
  if(Z == 3) WHAT = "minotaur"+NORM+"";
  if(Z == 4) WHAT = ""+NORM+RED+"centigor"+NORM+"";
  if(Z == 5) WHAT = ""+HIR+"dragon-ogre"+NORM+"";
  if(Z == 6) WHAT = ""+BLU+"troll"+NORM+"";
  if(Z == 7) WHAT = "chaos spawn"+NORM+"";
  if(Z == 8) WHAT = ""+NORM+YEL+"tuskgor"+NORM+"";
  if(Z == 9) WHAT = "chaoshound"+NORM+"";

  if(Z == 0) RACE = "beastman";
  if(Z == 1) RACE = "beastman";
  if(Z == 2) RACE = "beastman";
  if(Z == 3) RACE = "minotaur";
  if(Z == 4) RACE = "beastman";
  if(Z == 5) RACE = "dragon-ogre";
  if(Z == 6) RACE = "troll";
  if(Z == 7) RACE = "spawn";
  if(Z == 8) RACE = "beastman";
  if(Z == 9) RACE = "hound";

  if(Z == 0){ ungor(); }
  if(Z == 1){ gor(); }
  if(Z == 2){ beastigor(); }
  if(Z == 3){ minotaur(); }
  if(Z == 4){ centigor(); }
  if(Z == 5){ dragonogre(); }
  if(Z == 6){ troll(); }
  if(Z == 7){ chaos_spawn(); }
  if(Z == 8){ tuskgor(); }
  if(Z == 9){ chaoshound(); }

  if(Y == 0) G = (random(600)+1490);
  if(Y == 1) G = (random(600)+1550);
  if(Y == 2) G = (random(600)+1600);
  if(Y == 3) G = (random(1500)+2000);
  if(Y == 4) G = (random(2000)+3000);

  set_name(WHAT);
  set_short(HIK+"A"+SIZE+" "+WHAT+""+NORM);
  set_alias("RACE");
  set_race("RACE");
  set_hp(500+(Y*25));
  set_level(X);
  set_al(-1200);
  set_wc(X*3);
  set_ac(22+(Y*2));
  set_aggressive(0);


  gold=clone_object("obj/money");
  gold->set_money(G);
  move_object(gold,this_object());

}

  id(str) {
  return (str == WHAT || str == RACE || str == "smon"); 
}

ungor(){
    set_long("     The ungor are the lowest in beastmen society.  They are\n"+
             "spiteful creatures with lower half of a cloven hoofed animal\n"+
             "and the upper body is humanoid, with a horned head.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("The ungor glares at you with hatred.\n");
  load_chat("A high pitched braying sound comes from the ungor.\n");
  load_a_chat("The ungor rakes you with dirty claws.\n");
}

gor(){
    set_long("     The gor are the standard creature of beastman society.\n"+
             "Usually powerfully built with a great horned head and with \n"+
             "legs of a goat or some other animal. They do pride themselves\n"+
             "on the size and shape of their great horns.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("The gor scratches the ground and snorts.\n");
  load_chat("A loud braying sound echoes from all around.\n");
  load_a_chat("The beastman beatbutts you with his horned head.\n");
  set_multi_cast(0);
  
   add_spell("head-butt",
   "The gor swings its head forward and $R$SLAMS$N$ you with a vicious headbutt!\n",
   "The gor swings its head forward and $R$SLAMS$N$ #TN# with a vicious headbutt!\n",
   20,80,"physical");
   
   add_spell("hoof-stomp",
   "The gor violently $HK$kicks$N$ you in the groin!\n",
   "The gor violently $HK$kicks$N$ #TN# in the groin!\n",
   5,100,"physical"); 
}

beastigor(){
    set_long("     The beastigor are often the favored gors of the tribal chief\n"+
             "and as such generally are the envy of the lesser ranks of their \n"+
             "own kind.  Though no ungor could ever gain this status, the gor are\n"+
             "the sole race chosen for this honor.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("The beastigor struts proudly about.\n");
  load_chat("The beastigor polishes his impressive horns.\n");
  load_a_chat("The beastigor punches you in the gut.\n");
  set_multi_cast(0);
  
   add_spell("head-butt",
   "The beastigor swings its head forward and $R$SLAMS$N$ you with a vicious headbutt!\n",
   "The beastigor swings its head forward and $R$SLAMS$N$ #TN# with a vicious headbutt!\n",
   20,85,"physical");
   
   add_spell("hoof-stomp",
   "The beastigor violently $HK$kicks$N$ you in the groin!\n",
   "The beastigor violently $HK$kicks$N$ #TN# in the groin!\n",
   5,101,"physical");
}

minotaur(){
    set_long("     The minotaur are commonly known as the guardians of the\n"+
             "herdstones and sacred places of the beastmen.  They tower over\n"+
             "most of the lesser creatures of chaos and are known to be quite\n"+
             "bloodthirsty in battle.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("The minotaur snorts at you.\n");
  load_chat("The minotaur sniffs the air.\n");
  load_a_chat("The minotaur bellows in rage!\n");
  set_multi_cast(0);
  
   add_spell("head-butt",
   "The minotaur swings its head forward and $R$SLAMS$N$ you with a vicious headbutt!\n",
   "The minotaur swings its head forward and $R$SLAMS$N$ #TN# with a vicious headbutt!\n",
   20,110,"physical");
   
   add_spell("stampede",
   "The minotaur roars....\n"+
   "    ....... digs into the ground with his hoofs....\n"+
   "             .......... then $HR$CHARGES$N$ savagely over you!\n",
   "The minotaur roars....\n"+
   "    ....... digs into the ground with its hoofs....\n"+
   "             .......... then $HR$CHARGES$N$ savagely!\n",
   5,110,"physical");
}

centigor(){
    set_long("     The centigor are another example of the warping nature of chaos.\n"+
             "It had the upper body of a gor, but the lower body is of some great\n"+
             "four legged beast.  Also well known for it's love of strong drink and\n"+
             "an equally bad temper, this creature is dangerous.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("A deep growl echoes through the still air.\n");
  load_chat("The centigor burps then drinks from a wineskin.\n");
  load_a_chat("The centigor attacks in a drunken fury.\n");
    set_multi_cast(0);
  
   add_spell("drunken-rage",
   "The centigor flails its limbs about drunkenly!\n",
   "The centigor flails its limbs about grunkenly!\n",
   20,90,"physical");
   
   add_spell("hoof-kick",
   "The centigor violently $HK$kicks$N$ you in the face!\n",
   "The centigor violently $HK$kicks$N$ #TN# in the face!\n",
   5,100,"physical");
}

dragonogre(){
    set_long("     The dragon-ogres are one of the oldest races.  Long ago they\n"+
             "traded away their souls for so they would never have to suffer the\n"+
             "touch of age.  They resemble a centauroid of a an ogre, with the\n"+
             "lower half of some great scaled beast.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("Something unidentifiable drips from the mouth of the dragon-ogre.\n");
  load_chat("The dragon-ogre growls dangerously.\n");
  load_a_chat("A terrible unwashed stench assails your senses.\n");
  set_multi_cast(0);
  
   add_spell("raking claws",
   "The dragon-ogre $HR$S L A S H E S$N$  at you with its sharp claws!\n",
   "The dragon-ogre $HR$S L A S H E S$N$  at #TN# with its sharp claws!\n",
   20,110,"physical");
   
   add_spell("smash",
   "The dragon-ogre violently $R$smashes$N$ you to the ground!\n",
   "The dragon-ogre violently $R$smashes$N$ #TN# to the ground!\n",
   5,150,"physical");
}

troll(){
  set_long("     Trolls in the armies of chaos are generally ones that have fallen\n"+
             "under chaos' dire influence.  The seem to be more intellgent yet they\n"+
             "retain their beastial intellgence.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  set_heal(10,5);
  load_chat("The stomach of the troll gurgles.\n");
  load_chat("The troll open one of it's many mouths.\n");
  load_a_chat("A mutated limb painfully hits you.\n");
  set_multi_cast(0);
  
   add_spell("vomit",
   "The troll heaves then opens its mouth wide and.....\n"+
   "  $C$V $R$O $Y$M $R$I $C$T $Y$S\n"+
   "    all over you!\n",
   "The troll heaves, opens its mouth wide and....!\n"+
   "  $C$V $R$O $Y$M $R$I $C$T $Y$S\n"+
   "    all over #TN#!\n",
   20,({90,90}),({"physical","other|poison"}));
   
   add_spell("bite",
   "The troll snaps its jaws painfully on you!\n",
   "The troll snaps its jaws painfully on #TN#!\n",
   5,100,"physical");  
}

chaos_spawn(){
  set_long("     It is unknown where this spawn originated, but it is known they\n"+
             "were once a fell servant of chaos.  But due to some failure; real or\n"+
             "imagined by the fickle gods, or just a matter of whimsey of their dark\n"+
             "patrons, they are now a shapeless idiotic creature.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("A piercing wail echoes from the spawn.\n");
  load_chat("The spawn undulates over the ground.\n");
  load_a_chat("The spawn slams into you with it's corpulent form.\n");
}

tuskgor(){
    set_long("     The tuskgor are a odd war beast of the beastman armies.  It \n"+
             "seems to be a gigantic boar that sports the all too familiar horns\n"+
             "all too common with the beastmen race.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("The tuskgor grunts.\n");
  load_chat("The snorts and paws at the ground.\n");
  load_a_chat("Pain shoots through you as the tuskgor rams into you.\n");
  set_multi_cast(0);
  
   add_spell("head-butt",
   "The tuskgor swings its head forward and $R$SLAMS$N$ you with a vicious headbutt!\n",
   "The tuskgor swings its head forward and $R$SLAMS$N$ #TN# with a vicious headbutt!\n",
   20,80,"physical");
   
   add_spell("hoof-stomp",
   "The tuskgor violently $HK$kicks$N$ you in the groin!\n",
   "The tuskgor violently $HK$kicks$N$ #TN# in the groin!\n",
   5,100,"physical");
   
   add_spell("stampede",
   "The tuskgor grunts....\n"+
   "    ....... digs into the ground with his hoofs....\n"+
   "             .......... then $HR$CHARGES$N$ savagely over you!\n",
   "The tuskgor grunts....\n"+
   "    ....... digs into the ground with its hoofs....\n"+
   "             .......... then $HR$CHARGES$N$ savagely!\n",
   5,110,"physical");   
}

chaoshound(){
    set_long("     This shaggy beast can barely be called a hound by some sort of\n"+
             "great understatement. Its form is warped and twisted by its exposure\n"+
             "to chaos thus no two are ever alike.  Massive mutations visited upon \n"+
             "this creature have driven it beyond the brink of sanity.\n");
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("The hound growls low in its throat.\n");
  load_chat("Madness flickers within the eyes of the hound.\n");
  load_a_chat("The hound snaps his slavering fangs at your throat.\n");
  add_spell("bite",
   "The hound snaps its jaws painfully on you!\n",
   "The hound snaps its jaws painfully on #TN#!\n",
   5,100,"physical");  
}
