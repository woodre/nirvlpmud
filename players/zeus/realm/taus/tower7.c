inherit "room/room";	/*  tower7.c  */
#include "/players/zeus/closed/all.h"
#include "/players/zeus/closed/fl_demon.h"
object cash;
int teleport, ser;

reset(arg){

  if(!present("t_chest"))
  {
    move_object(clone_object("/players/zeus/realm/OBJ/auseth_chest.c"),
      this_object());
    cash = clone_object("/obj/money.c");
    cash -> set_money(3000+random(1001));
    move_object(cash, present("t_chest"));
  }

	teleport = 0;  if(random(TFL_TLP)) teleport = 1;
	if(arg) return;
    ser = 0; /* not yet */

 short_desc="Auseth's Tower";
 long_desc=
"You have entered a quaint little bedroom.  A comfortable looking bed is\n"+
"resting against the eastern wall of the room, beneath a large painting.\n"+
"In the southern end of the room is a small fireplace.  A few dressers\n"+
"are sitting next to the bed, and a small rug is on the floor.  There is\n"+
"also a large, ornate treasure chest near the bed.  One large window is\n"+
"in the north end of the room.  A door leads back to the west.  There is\n"+
"a staircase which leads up to the top of the tower.\n";
 set_light(1);
 items=({
   "staircase",
"The stone staircase leads up to the top of the tower",
	 "bed",
"The bed is rather large and looks quite comfortable.  The blankets on it\n"+
"are very unorganized and messy",
	"blankets",
"There are two blankets laying on the bed, each of which looks very filty",
	"painting",
"The large painting depicts the Fallen Lands as seen from what appears\n"+
"to be the top of the tower.  It is a magnificent painting",
	"fireplace",
"The small fireplace looks as though it hasn't been used in quite a while.\n"+
"A few new logs are sitting in it, waiting to be burned",
	"logs",
"The logs are small and look very dry",
	"dressers",
"The dressers are made of nice oak, and are rather well made",
	"rug",
"The small rug is the only thing on the stone cold floor.  It looks as\n"+
"though it could be 'move'd around",
	"window",
"The single large window is looking out to the north.  Off in the distance,",
"over the trees a large body of water can be seen",
	"door",
"The simple oak door leads out of the room to the west",
 });
 dest_dir=({
	  "/players/zeus/realm/taus/tower6.c", "west",
	  "/players/zeus/realm/d/ttop.c", "up",   });
}


void init(){
	::init();
	add_action("w_dir", "west");
    add_action("move_cmd", "move");
    add_action("down_dir", "down");
    add_action("up_dir", "up");
}

exit(){    if(TP) TP->clear_fight_area();     }
realm(){   if(teleport) return "NT";    }
okay_follow(){ return 1; }

down_dir(){
  if(0 == ser) return 0;
  write("You walk down the staircase...\n\n");
  TP->MP("down#/players/zeus/realm/d/ent4.c");
  return 1;
}

up_dir(){	write("You walk up the stairs...\n\n");   }

move_cmd(str){
  if(str != "rug") return 0;
  if(1 == ser)
  {
    write("The rug has already been moved.\n"+
      "You can go 'down' the secret staircase.\n");
    return 1;
  }
  write("You move the rug to reveal a secret staircase 'down'\n");
  ser = 1;
  return 1;
}

