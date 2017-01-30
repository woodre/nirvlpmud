/*****************************************************************************
 *      File:                   office4.c	
 *      Function:               room for acs area
 *      Author(s):              Highlander@Nirvana
 *      Copyright:              Copyright (c) 2011 Highlander 
 *                              All Rights Reserved.
 *      Source:                 2/24/2011
 *      Notes:                  clones stacie
 *      Change History:         
 ****************************************************************************/
inherit "room/room";
reset(arg)
{
  if(arg) return;
  
  if(!present("Stacie"), this_object())
  {
    move_object(clone_object("/players/highlander/areas/acs/mobs/stacie.c"), this_object());
  }
  
  ::reset();

  set_light(1);
  short_desc="Sprint/Nextel OM Office";
long_desc=
 "This is the operations manager office for Sprint/Nextel.  In this room\n" +
 "there is a huge red cherry desk.  The desk is very disorganized.  There\n" +
 "are several Sprint phones and other accessories sitting on this massive desk.\n"+
 "There is also a comptuter terminal that sits in the middle of the desk.\n"+
 "Behind the desk sits a very large and inviting black leather chair.  The\n"+
 "OM sees you enter the room and gets out of her seat and advances towards you\n"+
 "in a threatening manner.  Now would be a good time to beat a hasty retreat\n"+  
 "before you get attacked, Oops too late your screwed now.\n";
 
items=({
 "desk", "A massive desk made of the finest red cherry wood money can buy",
 "computer", "A Dell computer, currently in screen saver mode",
 "chair", "A large plush leather chair",

 });

dest_dir=({
 "/players/highlander/areas/acs/rooms/sprint1.c","out",

           });
        }

/* We need to overload the default 'out' action that's added by the room
   so that we can check for the npc before we let them out.  To add an action
   or we use init(), and then add_action() - Rump
 */
void init()
{
  ::init();  /* Call the room/room init(); so we don't mess anything up that
                is default */
  add_action("out_block", "out");  /* Add an action out_block() to the verb
                                      'out' that we used in our exit */
}

status out_block()
{
  if (present("Stacie"))   /* Check to see if Stacie is still here */
  {
    write("Stacie blocks your escape!\n"); /* Give them some message letting
                                              them know why they can't get
                                              out using 'out' */
    return 1;  /* return 1 to stop the code here, cause she's still here */
  }
  return 0;   /* return 0 cause she's not here, this will then passthrough
                 the verb to the next matching action, which is the exit
                 we defined in dest_dir */
}
/* This will make the room a no teleport room.  Means no possible escape until Stacie is dead. */
realm() { return "NT"; }
