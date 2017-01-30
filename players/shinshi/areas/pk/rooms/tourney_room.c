inherit "/room/room";
#include <ansi.h>

#define TP this_player()
#define QRN query_real_name()
#define ENV environment
#define CAP capitalize
#define PATH "players/shinshi/areas/pk/rooms/"

reset(arg) 
{
  if(arg) return;
  short_desc= HIK+"PK Tournament Colosseum"+NORM;
  long_desc= "This is the default room description.";
}

init() 
{
  ::init();

  "/players/shinshi/areas/pk/rooms/rm17.c"->Cmd_loot_corpse();  

  add_action("Cmd_quit","quit");
  add_action("Cmd_ctalk","ctalk");
  add_action("Cmd_cwho","cwho");
  add_action("Cmd_block","take");
  add_action("Cmd_block","get");
  add_action("Cmd_portal","portal");
  add_action("Cmd_pray", "pray");

  /* Block Guild Commands for using corpses */

  add_action("Cmd_stop", "offer");         /* Std Mud */
  add_action("Cmd_stop", "process");       /* Bards & Corpse Rod */
  add_action("Cmd_stop", "drain");         /* BCM & Vamps & Shards */
  add_action("Cmd_stop", "ghoul");         /* BCM */
  add_action("Cmd_stop", "sacrifice");     /* Bloodfist & Necro */
  add_action("Cmd_stop", "absorb");        /* Bloodfist & Syms */
  add_action("Cmd_stop", "decorpse");      /* Cyberninjas & Knights */
  add_action("Cmd_stop", "scatter");       /* Dervish */
  add_action("Cmd_stop", "meditate");      /* Fallen */
  add_action("Cmd_stop", "wither");        /* Fallen */
  add_action("Cmd_stop", "sac");           /* Mages */
  add_action("Cmd_stop", "embalm");        /* Necro */
  add_action("Cmd_stop", "harvest");       /* Necro */
  add_action("Cmd_stop", "regain");        /* Poly */
  add_action("Cmd_stop", "donate");        /* Rangers */
  add_action("Cmd_stop", "kneel");         /* Sams */
  add_action("Cmd_stop", "feed_pet");      /* Wocket Pets */
  add_action("Cmd_stop", "eat_corpse");    /* Eurale Demon */
  add_action("Cmd_stop", "feed");          /* Shard Dragon */


  /* Block Guild Commands for resurrecting */

  add_action("Cmd_no", "bede");          /* BCM */
  add_action("Cmd_no", "resurrect");     /* Healer & Knights */

  /* Block certain guild abilities */
 
  add_action("Cmd_summon", "summon");    /* Shard dragon summons */
  add_action("Cmd_dragon", "dragon");    /* BCM dragon summons */
  add_action("Cmd_shadow", "shadows");   /* Cyber shadows */
  add_action("Cmd_mount", "mount");      /* Shard/BCM dragon */
}

Cmd_pray()
{
	if(!this_player()->query_ghost())
	{
		write("You are not dead!\n");
		return 1;
	}
	
	if(this_player()->query_ghost())
	{
		call_other(this_player(), "remove_ghost", 0);
		return 1;
	}
	return 1;
}


Cmd_quit() 
{
  write("You cannot quit from here.\n");
  return 1;
}

Cmd_ctalk(str) 
{
  if(!str) 
  { 
    notify_fail("What do you want to communicate?\n"); 
    return 1; 
  }
  if(str[0]==':')
    emit_tourney(CAP(TP->QRN)+" "+str[1..strlen(str)]);
  else
    emit_tourney(CAP(TP->QRN)+" says: "+str);
  return 1;
}

emit_tourney(str) 
{
  object *ppl;
  int i;
  ppl=users();

  for(i=0;i < sizeof(ppl); i++) 
  {
    if(environment(ppl[i]) &&
       environment(ppl[i])->pk_tourney() ) 
         
       tell_object(ppl[i],
           HIR+"{ TOURNEY }"+NORM+" "+str+"\n");
  }
}

Cmd_cwho(str) 
{                       
  object *ppl;
  object room;
  object npc;
  int i;
  ppl=users();

  write(
   "The following people are still in the Colosseum:\n\n");

   for(i=0; i<sizeof(ppl); i++) 
   {
     room=environment(ppl[i]);

     if(room && room->pk_tourney() && !ppl[i]->query_ghost())
     {
       write("\t "+pad(CAP(ppl[i]->QRN),20));
       write("\n");
     }
  }          
  return 1;
}

Cmd_portal()
{
  string here;
  string where;

  if(this_player()->query_sp() < 60)
  {
    write("You don't have enough spell points.\n");
    return 1;
  }

  here = object_name(environment(this_player()));

  switch(random(16))
  {
    case 0: where = PATH+"rm1"; break;
    case 1: where = PATH+"rm2"; break;
    case 2: where = PATH+"rm3"; break;           
    case 3: where = PATH+"rm4"; break;
    case 4: where = PATH+"rm5"; break;
    case 5: where = PATH+"rm6"; break;
    case 6: where = PATH+"rm7"; break;
    case 7: where = PATH+"rm8"; break;
    case 8: where = PATH+"rm9"; break;
    case 9: where = PATH+"rm10"; break;
    case 10: where = PATH+"rm11"; break;
    case 11: where = PATH+"rm12"; break;
    case 12: where = PATH+"rm13"; break;
    case 13: where = PATH+"rm14"; break;
    case 14: where = PATH+"rm15"; break;
    case 15: where = PATH+"rm16"; break;
  }

  if(here == where)
  {
    command("portal", this_player());
    return 1;
  }

  this_player()->add_sp(-60);

  tell_object(this_player(),
    "A "+HIB+"blue"+NORM+" haze engulfs you and transports you to a new location.\n\n");
  command("look", this_player());

  tell_room(environment(this_player()),
    "A "+HIB+"blue"+NORM+" haze engulfs "+capitalize(this_player()->query_real_name())+" and transports them to a new location.\n\n", ({ this_player() }));

  move_object(this_player(), where);

  return 1;
}  

Cmd_block(str)
{
  string item;
  
  if(str == "all" && this_player()->query_name() == "shinshi")
  {
	  move_object(str, this_player());
	  return 1;
  }

  if(!str)
  {
    write("What do you want to do?\n");
    return 1;
  }
  if(sscanf(str, "%s from corpse", item))
  {
    write("You're not allowed to loot corpses here.\n");
    return 1;
  }
  if(str == "all" && present("corpse", this_object()))
  {
    write("You cannot do that with a corpse present.\n");
    return 1;
  }
  if(str == "all" && present("corpse", this_object()))
  {
    write("You cannot do that with a corpse present.\n");
    return 1; 
  }
  if(str == "corpse" && this_player()->query_level() < 20)
  {
    write("You're not allowed to steal corpses.\n");
    return 1;
  }
  return 0;
}

Cmd_stop(str)
{
  if(!str)
  {
    write("You cannot use corpses in the Colosseum.\n");
    return 1;
  }
  if(str == "corpse")
  {
    write("You cannot use corpses in the Colosseum.\n");
    return 1;
  }
  if(str == "to the sands")
  {
    write("You cannot use corpses in the Colosseum.\n");
    return 1;
  }
  if(str == "dragon")
  {
	write("You cannot use corpses in the Colosseum.\n");
	return 1;
  }
  if(str == "for bones")
  {
	write("You cannot use corpses in the Colosseum.\n");
	return 1;
  }
  return 0;
}

Cmd_no()
{
  Write("You cannot bring people back to life in the Colosseum.\n");
  return 1;
}

Cmd_summon(str)
{
  if(!str) return 1;
  if(str == "dragon")
  {
    write("You can't summon a dragon from here.\n");
    return 1;
  }
  return 1;
}

Cmd_dragon()
{
  write("You can't summon a dragon from here.\n");
  return 1;
}

Cmd_shadow()
{
  write("You can't hide in the shadows here, coward.\n");
  return 1;
}

Cmd_mount(str)
{
  if(present("dark_circle", this_player()) || present("shardak_mark", this_player()))
  {
    if(!str || str == "dragon")
    {  write("You can't mount dragons in here.\n");
       return 1;
    }
  }
  return 0;
}

pk_tourney(){ return 1; }

realm(){ return "NT"; }