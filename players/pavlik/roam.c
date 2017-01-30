inherit "/obj/monster";

#define MOVE_INTERVAL	300		/* how often our mob moves (in seconds) */
#define MAX_ATTEMPTS	4		/* how many times we'll try for a valid exit */
#define WIZARD_NAME	"pavlik"

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("roamer");
  set_level(1);
  /* etc, etc... */

  /* put this call_out in the reset to start the call_out */
  call_out("roam", MOVE_INTERVAL);
}


roam()
{
  string *dest_dir;
  string *exits;
  int i;

  exits = ({});

  /* clean out all the previous call_outs */
  /* this shouldn't be necessary be just adds some extra safe-guards */
  while(remove_call_out("roam") != -1) continue;

  /* make sure we have an environment */
  /* loop the call_out again just in case we get an environment back */
  if(!environment())
  {
	call_out("roam", MOVE_INTERVAL);
	return 1;
  }

  dest_dir = environment()->query_dest_dir();

  for(i=1; i<sizeof(dest_dir); i+=2)
  {
	/*
	 * make sure the destination is still in our area, otherwise dont add it
	 */
	if(sscanf(dest_dir[i-1], "/players/"+WIZARD_NAME+"/%s") == 1)
	{
		tell_object(find_player("pavlik", "roamer: "+dest_dir[i]+" added to exit list.\n");
		exits += dest_dir[i];
	}
  }

  if(!sizeof(exits))
  {
	tell_object(find_player("pavlik", "roamer: exit list is empty, bombing out.\n");
	call_out("roam", MOVE_INTERVAL);
	return 1;
  }

  i = random(sizeof(exits)-1);
  tell_object(find_player("pavlik", "roamer: selected exit is: "+exits[i]+"\n");

  /* if a valid exit was found then command it */
  if(exits[i])
	command(exits[i], this_object());

  /* loop the call_out */
  call_out("roam", MOVE_INTERVAL);

  return 1;

}

