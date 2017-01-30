/*                                                                    *
 *    File:             /players/angel/area/town/npc/multi.c          *
 *    Function:         npc                                           *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2006 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           06/1/06                                       *
 *    Notes:            A Multiple use NPC                            *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "obj/monster";

int x;
int X;
int Y;
int Z;
string ATTI;
string WHAT;
string RACE;
reset(arg){
  ::reset(arg);
  if(arg) return;
  Y = (random(5));
  Z = (random(10));
  X = (Y+16);
  
  if(X == 16) ATTI = " Happy";
  if(X == 17) ATTI = " Grateful";
  if(X == 18) ATTI = " Cheerful";
  if(X == 19) ATTI = " Pleasant";
  if(X == 20) ATTI = " Cool";

  if(Z == 0) WHAT = "Customer";
  if(Z == 1) WHAT = "Citizen";
  if(Z == 2) WHAT = "Patron";
  if(Z == 3) WHAT = "Kid";
  if(Z == 4) WHAT = "Associate";
  if(Z == 5) WHAT = "Worker";
  if(Z == 6) WHAT = "Employee";
  if(Z == 7) WHAT = "Person";
  if(Z == 8) WHAT = "Resident";
  if(Z == 9) WHAT = "Colleague";
  
  if(Z == 0) RACE = "customer";
  if(Z == 1) RACE = "citizen";
  if(Z == 2) RACE = "patron";
  if(Z == 3) RACE = "kid";
  if(Z == 4) RACE = "associate";
  if(Z == 5) RACE = "worker";
  if(Z == 6) RACE = "employee";
  if(Z == 7) RACE = "person";
  if(Z == 8) RACE = "resident";
  if(Z == 9) RACE = "colleague";

  if(Z == 0){ customer(); }
  if(Z == 1){ citizen(); }
  if(Z == 2){ patron(); }
  if(Z == 3){ kid(); }
  if(Z == 4){ associate(); }
  if(Z == 5){ worker(); }
  if(Z == 6){ employee(); }
  if(Z == 7){ person(); }
  if(Z == 8){ resident(); }
  if(Z == 9){ colleague(); }

  set_name(WHAT);
  set_alt_name("human");
  set_short(""+HIB+"A"+ATTI+" "+WHAT+""+NORM+"");
  set_alias("RACE");
  set_race(RACE);
  set_level(14 + random (2));
  set_hp(220 + random (100));
  set_ac(11 + random (7));
  set_wc(18 + random (7));
  set_al(0);
  gender = random_sex();
  set_gender(gender);
  while(x < 2)
  {
    move_object(clone_object("/players/angel/area/town/obj/cash.c"), this_object());
    x++;
  }
}

/* 
 * Function name: random_sex()
 * Description:   This function uses random() to randomly select a sex
 *                for a creature.
 * Arguments:     None
 * Returns:       string
 */

string
random_sex(){
  switch(random(8)) {
    /* 62.5% chance of being male */
    case 0: case 1: case 2: case 3: case 4:
      return "male";
    break;
    case 5: case 6: case 7:
      return "female";
    break;
    default:
      return "male";
  }
}

/* 
 * Function name: WHAT/RACE ()
 * Description: This function uses WHAT/RACE() to select the long
 *              and chat for the correct NPC
 * Arguments:   None 
 * Returns:     long and chat
 */

  id(str) {
  return (str == WHAT || str == RACE || str == "rmob" || str == "multi"); 
}

customer(){
    set_long("  This Customer is a human and lives in Gas City.\n");
  set_chat_chance(8);
  set_a_chat_chance(10);
  load_chat("Customer asks, Is that all you have?\n");
  load_chat("Customer asks, What's in the backroom?\n");
  load_a_chat("Customer says, I need some help over here!\n");
}
citizen(){
    set_long("  This Citizen is a human and lives in Gas City.\n");
  set_chat_chance(8);
  set_a_chat_chance(10);
  load_chat("Citizen says, It's so nice to see more people moving into our town.\n");
  load_chat("Citizen says, I better hurry up, I need to get home!\n");
  load_a_chat("Citizen says, It was a nice walk down here today.\n");
}
patron(){
    set_long("  This Patron is a human and lives in the town of Gas City.\n");
  set_chat_chance(8);
  set_a_chat_chance(10);
  load_chat("Patron says, I need a bit more of that.\n");
  load_chat("Patron ask, What is my tab up too?\n");
  load_a_chat("Patron says, You can add that to my tab!\n");
}
kid(){
    set_long("  This Kid is a human and lives in the town of Gas City.\n");
  set_chat_chance(8);
  set_a_chat_chance(10);
  load_chat("Kid says, I am so glade we have a school break!\n");
  load_chat("Kid says, I want to go down town to the flee market.\n");
  load_a_chat("Kid says, My Mom enjoyed the large flowers from the shop.\n");
}
associate(){
    set_long("  This Associate is a human and lives in the town of Gas City.\n");
  set_chat_chance(8);
  set_a_chat_chance(10);
  load_chat("Associate asks, Anything I can help you with?\n");
  load_chat("Associate says, It was nice to see you again.\n");
  load_a_chat("Associate says, Please come back!\n");
}
worker(){
    set_long("  This Worker is a human and lives in the town of Gas City.\n");
  set_chat_chance(8);
  set_a_chat_chance(10);
  load_chat("Worker asks, Are you interested in my product?\n");
  load_chat("Worker says, I have more if you are interested!\n");
  load_a_chat("Worker asks, May I help you?\n");
}
employee(){
    set_long("  This Employee is a human and lives in the town of Gas City.\n");
  set_chat_chance(8);
  set_a_chat_chance(10);
  load_chat("Employee asks, May I help you?\n");
  load_chat("Employee asks, Did you find everything you need?\n");
  load_a_chat("Employee asks, Anything else for you today?\n");
}
person(){
    set_long("  This Person is a human and lives in the town of Gas City.\n");
  set_chat_chance(8);
  set_a_chat_chance(10);
  load_chat("Person asks, Did you know the election is coming up?\n");
  load_chat("Person says, Mayor Ray has really out done himself this time!\n");
  load_a_chat("Person asks, Have you went to the Wal-Mart store to shop?\n");
}
resident(){
    set_long("  This Resident is a human and lives in the town of Gas City.\n");
  set_chat_chance(8);
  set_a_chat_chance(10);
  load_chat("Resident says, This is a really nice town.\n");
  load_chat("Resident says, I am so glade they built the Wal-Mart store!\n");
  load_a_chat("Resident says, Our school has obtained recognized status this year!\n");
}
colleague(){
    set_long("  This Colleague is a human and lives in the town of Gas City.\n");
  set_chat_chance(8);
  set_a_chat_chance(10);
  load_chat("Colleague asks, So, are you off today also?\n");
  load_chat("Colleague asks, Have you met all the new employees?\n");
  load_a_chat("Colleague says, Kelly is really hot!\n");
}
/*
heart_beat() {
  ::heart_beat();
  if (query_attack() &&  random(2) == 1) {
    if(Z == 0){ a_customer(); }
    if(Z == 1){ a_citizen(); }
    if(Z == 2){ a_patron(); }
    if(Z == 3){ a_kid(); }
    if(Z == 4){ a_associate(); }
    if(Z == 5){ a_worker(); }
    if(Z == 6){ a_employee(); }
    if(Z == 7){ a_person(); }
    if(Z == 8){ a_resident(); }
    if(Z == 9){ a_colleague(); }
  }
}*/