/*
File: maidlock.c
Author: Feldegast
Date: 3/18/02
Description:
  A magic amulet found in the fireplace in the temple in the
orc encampment in Caladon.  It can be used by a woman upon a
man to grant a blessing once every three days.
*/
#include "/players/feldegast/defines.h"

inherit "/obj/treasure.c";

int charge;

void reset(int arg)
{
  if(!arg)
  {
    set_id("locket");
    set_alias("maiden's locket");
    set_short("The "+HIY+"Maiden's"+NORM+" Locket");
    set_long(
      "This is a golden locket with the face of a beautiful maiden in it.\n"+
      "As a goddess of beauty and love, The Maiden's most powerful magic\n"+
      "is to "+BOLD+"inspire"+NORM+" others to battle.\n"
    );
    set_weight(1);
    set_value(5000);
  }
}

void init()
{
  ::init();
  add_action("cmd_inspire", "inspire");
}

int cmd_inspire(string str)
{
  object ob;
  object bonus;
  if(!str)
  {
    write("Inspire who?\n");
    return 1;
  }

  ob=present(str, environment(TP));

  if(time() < charge)
  {
    write("The locket will be recharged: "+ctime(charge)+".\n");
    return 1;
  }

  if(!ob || !living(ob) || !ob->is_player())
  {
    notify_fail("There is no '"+str+"' here.\n");
    return 0;
  }
  
  if((string)TP->query_gender()!= "female")
  {
    write("Only women may grant the Maiden's Gift.\n");
    return 1;
  }
  
  if((string)ob->query_gender()!="male")
  {
    write("Only men can be inspired by the Maiden's Gift.\n");
    return 1;
  }

  if(present("maiden_bonus", ob))
  {
    write("That person has already been inspired.\n");
    return 1;
  }

  if(present("magic_bonus", ob))
  {
    write("Another blessing interferes with the locket.\n");
    return 1;
  }

  write(HIY+"You inspire "+ob->query_name()+" with the Maiden's Blessing.\n"+NORM);
  tell_object(ob, HIY+TPN+" inspires you with the Maiden's Blessing!\n"+NORM);
  bonus = clone_object(OBJ_PATH+"maid_bless.c");
  bonus->start(TPN);
  move_object(bonus, ob);
  charge = time() + (3*24*60*60); /* 3 days */
  return 1;
}

locker_arg() {
  return charge+"";
}

locker_init(arg) {
  sscanf(arg,"%d",charge);
}
    
generic_object() { return 1; } 

restore_thing(str) {
  restore_object(str);
  return 1;
}

save_thing(str) {
  save_object(str);
  return 1;
}
