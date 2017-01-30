/*
 * Invasion master object
 * Version 0.3
 * Vertebraker & Dune
 */

#define INVASION_DEBUG  /* if defined, still in "testing" mode */

#pragma strict_types

static object  invoker;          /* wiz who started the invasion */
static int     monsters_killed;  /* Total monsters killed thusfar */
static string  *rooms;           /* Rooms monsters will clone to .. see reset() */
static mapping killers;          /* Holds names of players and how many mobs they've killed */
static object  *monster_obs;     /* Array holding monster objects .. usable to remotely 
                                    "dest" or track all loaded critters if need be .. */
static string  monster_path;     /* Path of monster to clone */
static string  invasion_type;    /* Type of monster invasion .. i.e. "Smurf", or "Undead" */
static int     total_monsters;

mixed *Invasion;

#define MAX_CLONE 20             /* Maximum number of monsters to clone per cycle */


void clone_monster(string monster, string room)
{
  object ob;

  if(!find_object(room))  /* Just making sure */
    room->load_me();

  ob=clone_object(monster);
  ob->set_invasion_type(invasion_type);
  tell_object(invoker, "Cloning: "+monster+" to "+room+"\n");
  move_object(ob, find_object(room));

#ifndef INVASION_DEBUG
  tell_room(find_object(room),
    ob->short()+" appears suddenly, as if by magic.\n");
#else
  if(present("vertebraker", find_object(room)))
    tell_object(find_player("vertebraker"),
     ob->short()+" appears suddenly, as if by magic.\n");
#endif

  monster_obs+=({ob});
}


/* Loop through the clone_pairs, max of MAX_CLONE pairs per call_out.
   Remember that element 0 of clone_pairs is our loop count, so our
   inner loop must start at 1, not 0!
 */
void clone_monsters(mixed *clone_pairs)
{
  int i;
  string response;
  response = "";

  for (i=1; i<=MAX_CLONE && i<=clone_pairs[0];i++)
  {
    clone_monster(clone_pairs[i][0], clone_pairs[i][1]);
  }
  clone_pairs[0] -= i-1;

  if (clone_pairs[0] > 0)
  {
    call_out("clone_monsters", 1, clone_pairs);
  }
}


void create_monsters()
{
  int i, roomCount;
  mixed *clone_pairs;

  if(total_monsters <= 0)
  {
    write("Total monsters not set.\n");
    return;
  }

  if(!invasion_type)
  {
    write("Invasion type not set.\n");
    return;
  }

  if(!monster_path)
  {
    write("Monster path not set.\n");
    return;
  }

  roomCount=sizeof(rooms);  /* How many rooms are we cloning to */

  /* Holds monster_path to room path pairings.
     The first element of this structure is a loop count, not a pairing!
   */
  clone_pairs = allocate(total_monsters + 1);
  clone_pairs[0] = total_monsters;

  /* Distribute equal # of monsters, accounting for remainders.
     This loop must start at 1 because element 0 is a call_out loop count.
     Even though monster_path is always the same, we include it so that in
     the future, it is easier to modify this daemon so that multiple mob 
     monsters can be in the same invasion.
   */
  for(i=1;i<=total_monsters;i++)
  {
    clone_pairs[i] = allocate(2);
    clone_pairs[i][0] = monster_path;
    clone_pairs[i][1] = rooms[i % roomCount];
  }

  invoker = this_player();
  call_out("clone_monsters", 1, clone_pairs);

/*
#ifndef INVASION_DEBUG
  log_file("INVASION", 
  (string)invoker->query_real_name()+" started "+invasion_type
   +" Invasion: "+ctime()+"\n");
#endif

  write("Invasion begun.\n");
*/
}


void reset(status x)
{
  rooms=({"room/vill_green","room/vill_track", "room/vill_road1",
          "room/vill_road2","room/vill_road3", "room/vill_shore",
          "room/vill_shore2", "room/jetty2", "room/sea",
        });
  killers=([]);
  monster_obs=({});
  monsters_killed=0;
  total_monsters=0;
  monster_path=0;
  invasion_type=0;
  invoker=0;
  restore_object("obj/invasion/save");
  if(!Invasion)
    Invasion=({});
}


int sort_me(int a, int b)
{
  return (b>a);
}


void sort_map()
{
  int i, s;
  mixed *ks, *vals, *new_arr;
  mapping new_map;

  vals = sort_array(m_values(killers),"sort_me",this_object());
  s = sizeof(vals);
  new_arr = ({ });

  for(i = 0; i < s; i ++)
  {
    string nm;
    new_arr += ({ nm=get_key(killers, vals[i]) });
    killers = m_delete(killers, nm);
  }
  killers = reconstruct_mapping(new_arr);
}


void dump_all_info()
{
  object zx;
  int i, sz;
  string *ks;
  log_file("INVASION", "Invasion Ended at "+ctime()[4..15]);

  if((zx=this_player()) && ((int)zx->query_level() > 20))
    log_file("INVASION", " by "+capitalize((string)zx->query_real_name())+"\n");
  else
    log_file("INVASION", ".\n");
  Invasion+=({
    (expand_month(ctime()[4..6])+ctime()[7..9]+", "+ctime()[20..24])
   });
  Invasion += ({ deconstruct_mapping(killers), });
  save_object("obj/invasion/save");
  reset(0);
}


void end_invasion()
{
#ifndef INVASION_DEBUG
  emit_channel("announce",
    "(announce) The Invasion Has Ended!\n"+
    "(announce) "+monsters_killed+" Monsters Slain by Players!\n");
#endif
  dump_all_info();
}


void add_kill(string nm)
{
  ++killers[nm];
  sort_map();  /* might have to cut this down .. run on a call_out rather
                  than "every" kill .. due to possible number of players killing */
  if(++monsters_killed == total_monsters)
    end_invasion();
}


/* Getters */
int     query_kills(string nm) { return killers[nm]; }
object *query_monster_obs()    { return monster_obs; }
string *query_rooms()          { return rooms; }
mixed  *Invasion()             { return Invasion; }
string  query_monster_path()   { return monster_path; }
string  query_invasion_type()  { return invasion_type; }
int     query_total_monsters() { return total_monsters; }


/* Setters */
void set_monster_path(string x)  { monster_path=x; }
void set_invasion_type(string x) { invasion_type=x; }
void set_total_monsters(int x)   { total_monsters=x; }
