/*
 *      File:                 /players/star/lounge/machine.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2005 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               12/31/2005
 *      Notes:
 *      Change History:
 */

inherit "obj/treasure.c";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("soda machine");
  set_alias("machine");
  set_short("A Soda Machine");
  set_long("This is a large machine with a picture of a can of soda on the front\n"+
    "of it.  Under the picture are little windows, each revealing a\n"+
    "different soda can.  There is a 1 below the Pepsi can, a 2 below the\n"+
    "Coke, and a 3 below the Dr. Pepper.  On the right side of the machine\n"+
    "there are three numbered buttons that can be pushed.\n");
  set_value(0);
}

void init()
{
  ::init();
  add_action("push", "push");
}

int push(string str)
  {
  if(!str)
  {
    notify_fail("Push what?\n");
    return 0;
  }
  if(str != "1" && str != "2" && str != "3")
  {
    notify_fail("You can only \"push\" \"1\", \"2\", or \"3\".\n");
    return 0;
  }
  if(str == "1")
  {
    write("You push number 1 and receive a can of Pepsi.\n");
    say((string)this_player()->query_name()+" presses a button on the machine and receives a can of Pepsi.\n");
    move_object(clone_object("/players/star/lounge/pepsi.c"),this_player());
    return 1;
  }
  if(str == "2")
  {
    write("You push number 2 and receive a can of Coke.\n");
    say((string)this_player()->query_name()+" presses a button on the machine and receives a can of Coke.\n");
    move_object(clone_object("/players/star/lounge/coke.c"),this_player());
    return 1;
  }
  if(str == "3")
  {
    write("You push number 3 and receive a can of Dr. Pepper.\n");
    say((string)this_player()->query_name()+" presses a button on the machine and receives a can of Dr. Pepper.\n");
    move_object(clone_object("/players/star/lounge/drpepper.c"),this_player());
    return 1;
  }
}
