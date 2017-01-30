inherit "/obj/treasure.c";
#define PATH "players/dragnar/kills/"
#define LOG  "/players/dragnar/logs/MK_rmlog"
#define MIN_KILLS 38  /* minimum kills for inactive players */

/****************************************************************
**  Tool to rm .o files from the old Mortal Kombat Scar.       **
**  Credit to Zeus, the tool was taken from taken from his     **
**  title wand, and modified a bit.  Also borrowed some code   **
**  from Boltar to check for inactive players.                 **
****************************************************************/

int pkills;     /* Number of kills from player.o file */
string WCARD;  /* wild card get_dir will use */

reset(arg){

  set_short("MK clean-up wand");
  set_long(
"This wand will automatically remove all outdated files from the\n"+
" /players/dragnar/kills/  directory.\n"+
"Just type:  cleanup or set\n");
  set_weight(0);
  set_value(0);
  WCARD = "*";  /* Default wild card is all files */
}

id(str){ return str == "wand"; }

void init(){
  ::init();
  add_action("set", "set");
  add_action("cleanup", "cleanup");
}

cleanup(){
  int x;
  string dir, who;
  dir = get_dir("/"+PATH+WCARD);
  x = 0;
  if(this_player()->query_level() < 30) return 0;
  write_file(LOG, "\n");
  write_file(LOG, ctime(time())+": Total files: "+sizeof(dir)+".\n");
  write_file(LOG, "\t\tWild Card: "+WCARD+"\n");
  while(x < sizeof(dir)) 
  {
    if(sscanf(dir[x],"%s.o",who)) 
    {
      if(restore_object(PATH+who))
      {
        if(pkills < 1)
        {
          rm("/"+PATH+who+".o");
          write_file(LOG, "Removed "+who+" : 0 kills.\n");
        }
        else if(!Verify(who))
        {
          rm("/"+PATH+who+".o");
          write_file(LOG, "Removed "+who+" : Player doesn't exist.\n");
        }
        else if(Verify(who) == 2 && pkills < MIN_KILLS)
        {
          rm("/"+PATH+who+".o");
          write_file(LOG, "Removed "+who+" Inactive, < "+MIN_KILLS+" kills.\n");
        }
      }
    }
    x++;
  } /* end while */
  dir = get_dir("/"+PATH);
  write_file(LOG, "Total files remaining: "+sizeof(dir)+"\n");
  write("\nAll clean.\n");
  return 1;
}

set(str) {
  if(!str) {
    write("set <wildcard>\n");
    write("example: set a*\n");
    return 1;
  }
  WCARD = str;
  write("Wild card set to: "+WCARD+"\n");
  return 1;
}

Verify(str) {
  /* Taken from Boltars /boltar/templar/verif.c and modified */

  if(restore_object("pfiles/" + extract(str,0,0) + "/" + str)) return 1;
  if(restore_object("players/inactive_saved/" + str)) return 2;
  return 0;
}
