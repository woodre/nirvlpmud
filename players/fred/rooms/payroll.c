/*****************************************************************************
 *      File:                   payroll.c
 *      Function:               room for acs area
 *      Author(s):              Highlander@Nirvana
 *      Copyright:              Copyright (c) 2011 Highlander 
 *                              All Rights Reserved.
 *      Source:                 2/24/2011
 *      Notes:                  clones gertrude and martha
 *      Change History:         
 ****************************************************************************/
inherit "room/room";

reset(arg)
{
  if(arg) return;
  
  if(!present("Martha"), this_object())
  {
    move_object(clone_object("/players/highlander/areas/acs/mobs/martha.c"), this_object());
  }
  
  if(!present("Gertrude"), this_object())
  {
    move_object(clone_object("/players/highlander/areas/acs/mobs/gertrude.c"), this_object());
  } 

  ::reset();
  
  set_light(1);
  short_desc="Payroll";
long_desc=
 "This is the Payroll Office for both divisions of this ACS branch.\n" +
 "You would come to this office if you receive a paper check from either\n" +
 "company.  This office pretty remains dead until the 2nd and 4th Friday \\n" +
 "of each month, then it impossible to get in here.  It is a pretty decent\n"+
 "sized office, big enough to handle 2 secretaries and their full sized desks.\n";
 
items=({
 "desk", "Two desks made of hickory that has been varnished using a red wood stain",
 }); 


dest_dir=({
 "/players/highlander/areas/acs/rooms/atrium.c","out",
 
           });
        }