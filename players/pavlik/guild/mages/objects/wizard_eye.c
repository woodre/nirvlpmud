#include <ansi.h>

long() {
  write("A mysterious floating eye.\n");
  return;
}


reset(arg) {
 if(arg)
  return;
 set_light(2);
}

short() { "A floating eyeball"; }


id(str) {
  return str == "wizard_eye" || str == "eyeball" || str == "eye";
}

query_value() {
    return 0;
}

get() {
    return 0;
}


/*
 * report the contents of a room
 */
do_report(dir, num)
{
  int i;
  object ob;
  object obj;

  tell_room(environment(this_object()),
   "A "+HIY+"Wizard's "+HIM+"Eye"+NORM+" floats into the room and looks around.\n" +
   "The magic eye zooms off.\n");

  if(!num)
  {
	write("To the "+HIC+dir+NORM+" ..... " + environment(this_object())->short() + " : \n");
  }

  obj = all_inventory(environment(this_object()));

  if(!obj)
  {
	write("  nothing.\n");
  }
  else
  {
	for(i=0; i<sizeof(obj); i++)
	{
		if(obj[i]->short()) write("  "+obj[i]->short()+"\n");
	}
  }
  return 1;
}


/*
 * scan multiple rooms in the same direction
 */
exit_report(str)
{
  int good_exit, i;
  int count;
  string exits, fname;
  string dir;

  good_exit = 1;
  count = 0;

  while(good_exit == 1 && count < 4)
  {
	good_exit = 0;
	fname = 0;
	exits = environment(this_object())->query_dest_dir();
	for(i=0; i<sizeof(exits); i+=2)
	{
		if(exits[i+1] == str)
		{
			fname = exits[i];
			good_exit = 1;
		}
	}
	if(fname)
	{
		move_object(this_object(), fname);
		tell_room(environment(this_object()),
		 "A "+HIY+"Wizard's "+HIM+"Eye"+NORM+" floats into the room and looks around.\n" +
		 "The magic eye zooms off.\n");

		if(count == 0) dir = "Nearby to the "+HIC+str+NORM;
		if(count == 1) dir = "To the "+HIC+str+NORM;
		if(count == 2) dir = "Far away to the "+HIC+str+NORM;
		if(count == 3) dir = "Very far away to the "+HIC+str+NORM;
		write(dir+" ..... " + environment(this_object())->short() + " : \n");

		do_report(str, 1);
		count++;
	}
  }
  return 1;
}

