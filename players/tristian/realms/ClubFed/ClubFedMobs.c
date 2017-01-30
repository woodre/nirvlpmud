#include "/players/tristian/lib/ClubFeddefine.h"
#define CONVICTS "/players/tristian/realms/ClubFed/mobs/"

string *npcs;
int npcnumber;


/* The add_npcs function allows for additional a previously removed mob   */
/* to be added back to the pool of possible monsters.                     */
void
add_npcs(string str)
{
  npcs += ({ str + ".c" });
  npcnumber = sizeof(npcs);
}

/* The remove_npcs function allows monsters to be easily removed either   */
/* when they cloned or when you want to just get rid of one.              */
void
remove_npcs(string str)
{
  npcs -= ({ str });
  npcnumber = sizeof(npcs);
}

/* The set_npc function sets up the array [list] of monsters that we will */
/* clone into the room randomly. */
void
set_npc()
{
  int x, y;
  npcs = get_dir(CONVICTS + "*.c"); /* Get the files in the mob directory */
  npcnumber = sizeof(npcs);         /* How many are there?                */
  return;
}

/* The create_npc function will clone the monster and move it to the      */
/* room that calls this function.                                         */
void
create_npc(string room_path)
{
  string temp;
  int random_number;

  npcnumber = sizeof(npcs);
  if ( !npcs || !npcnumber )
  {
    set_npc();
    npcnumber = sizeof(npcs);
  }
  if(!room_path) return;
  random_number = random(npcnumber);  /* Random number of a monster       */
  /*
  if (stringp(npcs[random_number]))
  */
    temp = CONVICTS+npcs[random_number];
log_file("tristian.mobs", ctime()+": ATTEMPTING TO CREATE: "+temp+"(room: "+room_path+").\n");
  if (!find_living(temp))
    move_object(clone_object(temp), room_path);
else
log_file("tristian.mobs", "\tfind_living found it.\n");
  if(member_array(npcs[random_number], npcs) > -1 )
  {
     remove_npcs(npcs[random_number]);  /* If we cloned it, remove it */
  }
}

void
dump_mobs()
{
  int i, siz;
  siz = sizeof(npcs);
  i = -1;
  while(++i < siz)
    write(i+"\t"+npcs[i]+"\n");
}

void
reset(status arg)
{
  if (arg) 
    set_npc();
}
