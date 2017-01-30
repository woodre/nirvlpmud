/* *************************************************************************
 * /obj/stocks_loader.c
 *
 * Stocks Object Autoloader
 *
 * Earwax 5/20/04
 *
 * *************************************************************************
*/

#define STOCKS "/players/earwax/stocks/stocks"
#define AUTOLOAD "/players/earwax/stocks_loader:0"
#define ID "STOCKS_AUTO_LOADER"

void
reset(status arg)
{
  return;
}

status drop() { return 1; }
status get() { return 1; }
status id(string arg) { return (arg == ID); }
/* *************************************************************************
 * init_arg
 *
 * this function is called when the object is autoloaded to a player
 *
*/

void
init_arg(string x)
{
  if (!((status)STOCKS->query_member((string)this_player()->query_real_name())))
  {
    tell_object(environment(this_object()), "You have been released from the stocks.\n");
    destruct(this_object());
  }
  else
    STOCKS->slappem_in(this_player());
}

string query_auto_load() { return AUTOLOAD; }

