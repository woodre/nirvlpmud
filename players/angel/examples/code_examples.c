

All file are a basic set up


/*
NPC / MOB  EXAMPLE
*/

/*                                                                    *
 *    File:             /players/angel/area/school/npc/student_01.c   *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2007 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           08/15/07                                      *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"/*This lint is required for LD conversion*/

#include <ansi.h>/*This is for use of color*/

inherit "obj/monster";/*this gives definitions for npc's/mob's*/

reset(arg)
{
  object gold,armor,weapon;/*use which ever item that you will have*/
  ::reset(arg);
  if(arg) return;
  set_name("1st grade Student");
  set_race("human");
  set_alias("student");
  set_short("A 1st grade student");
  set_long("\
This is a 1st grade student. He is the\n\
top of his class and has straight A's.\n");
  set_level(6);
  set_hp(90);
  set_wc(10);
  set_ac(5);
  set_al(300);
  set_heal(10,10);/*easy way for npc/mob to have heals*/
  set_chat_chance(4);/*higher the number increased talking time*/
  load_chat(query_name()+" asks, \"Hello, what are you doing here?\"\n");
  load_chat("The student says, This is our classroom\n");
  gold=clone_object("obj/money");
  gold->set_money(random(300)+25);/*adds money to drop*/
  move_object(gold, this_object());
  armor=clone_object("/players/angel/area/school/obj/underwear_01.c");/*adds item to drop*/
  move_object(armor, this_object());
  command("wear underwear", this_object());
  add_spell("fireball",/*adds a spell, you can name it what ever you want*/
  "#MN# throws a large $HR$fireball$N$ at you.\n",
  "#MN# throws a large $HR$fireball$N$ at #TN#.\n",
  5,10,"other|fire");
}

/*
ROOM EXAMPLE
*/

/*                                                                    *
 *    File:             /players/angel/area/stargate/room/hall8.c     *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2006 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           12/31/06                                      *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h" /*This lint is required for LD conversion*/
 
#include <ansi.h> /*This is for use of color*/

inherit "room/room"; /*this gives definitions for rooms*/

reset(arg)
{
  ::reset(arg);
  if( !present("corporal", this_object()) )  /*placing npc after reset helps it to be called correctly*/
    move_object(clone_object("/players/angel/area/stargate/npc/corporal.c"), this_object());
  if(arg) return;
  set_light(1);
  short_desc = HIC+"HALL"+NORM;
  long_desc =   /*I like the \n\ at the end of a sentence but you can still use \n"+ if you prefer*/
"    "+HIC+"~ HALL LEVEL 27 ~"+NORM+"\n\ 
"+CYN+"  This is a deep underground facility. All sides of the room are\n\
made of three feet thick concrete. Many pipes and wires run along\n\
the ceiling and air is pumped down from the surface. This facility\n\
is well secured. The hallway leads to many rooms."+NORM+"\n";
/*you should space in two'2 from the left
items and dest_dir should follow this format*/
  items =
  ({
    "facility",
    "underground building",
    "room",
    "its solid concrete",
    "concrete",
    "man maid solid rock",
    "pipes",
    "various sizes and colors",
    "wires",
    "various sizes and color",
    "ceiling",
    "Its full of pipes and wires",
    "surface",
    "earth, what you walk on",
    "hallway",
    "a long corridor connecting rooms",
  });

  dest_dir =
  ({
	"/players/angel/area/stargate/room/hall2",  "north",
	"/players/angel/area/stargate/room/hall9",  "south",
	"/players/angel/area/stargate/room/ar2",    "east",
	"/players/angel/area/stargate/room/iw",     "west",
  });
}

init(){
  ::init();
    this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }/*set area to PK*/

realm(){ return "NT"; }/*this stop the use of follow*/

/*
OBJ EXAMPLE
*/


/*                                                                    *
 *    File:             /players/angel/area/stargate/room/hall8.c     *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2006 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           12/31/06                                      *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */
 
#include "/sys/lib.h" /*This lint is required for LD conversion*/
 
#include <ansi.h> /*This is for use of color*/

inherit "/obj/armor";/*this gives definitions for obj*/

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("belt");
   set_alias("a belt");
   set_short("A Belt");
   set_long("This is a basic belt\n");
   set_ac(1);
   set_type("belt");   /* armor,helmet,boots,ring,amulet,shield,misc,  */
   set_weight(2);       /* chest,necklace,cloak,bracelet,pants,gloves,  */
   set_value(200);        /* earing,underwear                             */
}