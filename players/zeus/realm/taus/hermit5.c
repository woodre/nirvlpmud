inherit "room/room";
#include "/players/zeus/closed/all.h"
#include "/players/zeus/closed/fl_demon.h"
#define SAVE_PATH "players/zeus/realm/taus/hermit_log"
#define TIME 14400+random(14401)    /* 4-8 hours */
int teleport, lock, open, search, cnt;

reset(arg){

  teleport = 0;  if(random(TFL_TLP)) teleport = 1;
  if(!present("dolan")) MO(CO("/players/zeus/realm/NPC/dolan.c"), TO);

  if(!restore_object(SAVE_PATH))
  {
    lock = 1;      /*  The chest starts locked  */
    open = 0;      /*  The chest starts closed  */
    search = 0;    /*  The chest has something in it  */
  }
  else if(cnt < time())
  {
	lock = 1;
	open = 0;
	search = 0;
    save_object(SAVE_PATH);
  }

 if(arg) return;

 short_desc="The Fallen Lands";
 set_light(1);
 dest_dir=({ "/players/zeus/realm/taus/hermit4.c", "south",  });
}


long(){
	write(
"This is a dug out room beneath the forest.  It is about eight feet\n"+
"wide, twelve feet deep, and eleven feet tall.  Many dangling roots\n"+
"are growing down from the ceiling.  There is a small hole which leads\n"+
"to the surface in the ceiling.  A large treasure chest is sitting in\n"+
"the back corner of the room.  There are two sconces on the back wall\n"+
"which are glowing softly.\n"+
"    There is one obvious exit: south\n");
	return 1;
}

  void init(){
	::init();
	add_action("s_dir", "south");
	add_action("unlock_cmd", "unlock");
	add_action("open_cmd", "open");
	add_action("look_cmd", "look");
	add_action("look_cmd", "l");
	add_action("search_cmd", "search");

  if(!restore_object(SAVE_PATH))
  {
    lock = 1;      /*  The chest starts locked  */
    open = 0;      /*  The chest starts closed  */
    search = 0;    /*  The chest has something in it  */
  }
  else if(cnt < time())
  {
	lock = 1;
	open = 0;
	search = 0;
    save_object(SAVE_PATH);
  }

}

exit(){    if(TP) TP->clear_fight_area();     }
realm(){   if(teleport) return "NT";    }
okay_follow(){ return 1; }

status look_cmd(string str)
{
  if(!str)	return 0;
  if(str == "at chest" || str == "at treasure chest")
  {
    write(
      "This is a large treasure chest.  It is made of a black material and is\n"+
      "coated in several layers of dust.  It has a gold lock on it.  The\n"+
      "tresure chest is ");
    if(lock == 0)
      write("unlocked and ");
    if(lock == 1)
      write("locked and ");
    if(open && !search)
      write("the lid is open.\n");
    if(open && search)
      write("the lid is open.  It is empty.\n");
    if(!open)
      write("it is closed.\n");
    return 1; 
  }
  if(str == "at room")
  {
    write(
      "The room is fairly roomy considering that it was dug out probaby by hand.\n"+
      "It is a great little hideaway in the forest.\n");  return 1; }
  if(str == "at ceiling")
  {
    write(
      "The ceiling is very uneven and looks somewhat loose.  Many roots are\n"+
      "hanging down from it, in search of nutrients.\n"); return 1; }
  if(str == "at roots")
  {
    write(
      "The little brown roots hang down from the ceiling like snakes.\n");
    return 1;  
  }
  if(str == "at hole")
  {
    write(
      "The hole is only about half a foot wide, and barely any light is getting\n"+
      "through it.  It's only purpose is to provide fresh air for the room.\n");
    return 1;
  }
  if(str == "at sconces")
  {
    write(
      "There are two wooden sconces in the room, each one is glowly softly.\n");
    return 1;
  }
  else
    return 0;
  return 1;
}

status unlock_cmd(string str)
{
  if(!present("hermit_key", TP))
    return 0;
  if(str == "chest" || str == "treasure chest")
  {
    if(present("dolan"))
    {
      write("Dolan says:  You don't touch that now.\n");
      say("Dolan says:  You don't touch that now.\n");
      return 1;
    }
    if(lock == 0)
      write("The chest is already unlocked.\n");
    else 
    {
      write("You unlock the chest.\n");
      say(TP->QN+" unlocks the chest.\n");
      lock = 0;
      return 1;
    }
    return 1;
  }
  else
    write("What do you want to unlock?\n");
  return 1;
}

status open_cmd(string str)
{
  if(str == "chest" || str == "treasure chest")
  {
    if(present("dolan"))
    {
      write("Dolan says:  You don't touch that now.\n");
      say("Dolan says:  You don't touch that now.\n");
      return 1;
    }
    if(lock == 1)
    {
      write("The chest is locked and can't be opened.\n");
      say(TP->QN+" tries to open the chest, but it is locked.\n");
      return 1;
    }
    if(open == 1)
    {
      write("The chest is already open.\n");
      return 1;
    }
    else 
    {
      write("You open the chest.\n");
      say(TP->QN+" opens the chest.\n");
      open = 1;
      return 1;
    }
    return 1;
  }
  else
    write("What do you want to open?\n");
  return 1;
}

status search_cmd(string str){
  if(!str)
  {
	write("You search the room and find nothing.\n");
    return 1;
  }
  else if(str== "chest" || str == "treasure chest")
  {
    if(lock == 0 && open == 1)
    {
      if(search == 1)
      {
	    write("You search the chest and find nothing.\n");
		say(TP->QN+" searches the chest.\n");
	    return 1;
	  }
	  else 
      {
        write("You search the chest and find some treasure!\n");
        say(TP->QN+" searches the chest.\n");
        if(!TP->add_weight(6))
        {
          write("Unfortunatly it is too heavy for you to carry.\n");
          return 1; 
        }
        else {
          MO(CO("/players/zeus/realm/OBJ/onyx_platemail.c"), TP);
          MO(CO("/players/zeus/realm/OBJ/red_powder.c"), TP);
          search = 1;
          cnt = time() + TIME;
          save_object(SAVE_PATH);
          return 1;
        }
        return 1;
      }
      return 1;
    }
    else return 0;
    return 1;
  }
  return 1;
}

