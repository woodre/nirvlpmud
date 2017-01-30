inherit "/obj/treasure.c";
#define PATH "players/dragnar/kills/"
#define LOG  "/players/dragnar/logs/MK_rmlog"

/****************************************************************
**  Tool to rm .o files from the old Mortal Kombat Scar.       **
**  Credit to Zeus, the tool was taken from taken from his     **
**  title wand, and modified a bit.  Also borrowed some code   **
**  from Boltar to check for inactive players.                 **
****************************************************************/

int pkills;

reset(arg){

  set_short("Tester clean-up wand");
  set_long(
"Tester wand, type 'check <player>' to test it.\n");
  set_weight(0);
  set_value(0);
}

id(str){ return str == "wand"; }

void init(){
  ::init();
  add_action("check", "check");
}

check(str) {
  int x;
  string *tmp;

  write("File size is: ");
  tmp = tail("/players/dragnar/tool.c");
  write(tmp+"\n");
  return 1;
  write(capitalize(str)+" is: ");
  x = Verify(str);
  switch(x) {
  case 1:
    write("ACTIVE.\n");
    break;
  case 2:
    write("INACTIVE.\n");
    break;
  default:
    write("Non Existant.\n");
    break;
  }
  return 1;
}

Verify(str) {
  /* Taken from Boltars /boltar/templar/verif.c and modified */

  if(file_size("/pfiles/" + extract(str,0,0) + "/" + str) > 0) return 1;
  if(file_size("/players/inactive_saved/" + str) > 0) return 2;
  return 0;
}
