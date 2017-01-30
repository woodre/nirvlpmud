inherit "room/room";
#include "/players/pavlik/closed/colors.h"
#define PATH "players/pavlik/cloudcity/room/"
#define MAX_GRAPPLE 6

int grapple_count;
int loser_count;
string *grapple_rooms;

reset(arg) {
  set_light(1);
  short_desc="The Field";
  long_desc=
    "The Field below the City.\n";

  items=({
    "clouds", "White puffy clouds make up the ground that you walk on",
  });

  dest_dir=({
    "/players/pavlik/guild/room/cloud3", "north",
  });

  /* define rooms where grapple machines should be placed */
  grapple_rooms = ({
	"cloud1",
	"cloud5",
	"cloud9",
	"cloud15",
	"cloud19",
	"cloud23",
  });
  realm_init();
  if(grapple_count > 90) {
	grapple_count = 0;
	loser_count = 0;
  }

}

long() {
  if(grapple_count == 99) {
	write(
	"You stand at the north end of the lava field.  Some distance\n"+
	"to the north you see a mass of crumbled, destroyed buildings.\n"+
	"The broken city looks like it might have been beatiful once,\n"+
	"but whatever beauty there once was is gone now.\n"+
	"    There is one obvious exit: south\n");
	return;
  }
  write(
  "You stand at the north end of the lava field.  Some distance to\n"+
  "the north you notice a peculiar cloud formation.  Upon closer\n"+
  "inspection you realize there are buildings on the Cloud!\n");
  if(grapple_count > 0) {
	if(grapple_count == 1) write(
	"You notice "+grapple_count+" large cable connecting the Cloud City to\n");
	else write(
	"You notice "+grapple_count+" large cables connecting the Cloud City to\n");
	write(
	"the ground.  The giant cables seem to be trying to drag the City\n"+
	"right out of the sky!\n");
  }
  write("    There are two obvious exits: north, south\n");
  return;
}

/*********************************************************/
/* this function sets up the Cloud City realm for action */
/* it is called everytime this room resets.              */
/*********************************************************/
realm_init() {
  object ob, obj;
  int i;

  /* place the grapple machines */
  ob = clone_object("players/pavlik/cloudcity/obj/start_ob");
  for(i=0; i<sizeof(grapple_rooms); i++) {
	move_object(ob, PATH+grapple_rooms[i]);
	if(!present("orc_machine", environment(ob))) {
		obj = clone_object("players/pavlik/cloudcity/obj/orc_machine");
		move_object(obj, environment(ob));
		obj->machine_init();
	}
	else {
		present("orc_machine", environment(ob))->machine_init();
	}
  }
  destruct(ob);

  return 1;
}

/***************************************************/
/* track how many of the grapples have been set up */
/***************************************************/
set_grapple_count(i) { grapple_count = i; }
query_grapple_count() { return grapple_count; }
add_grapple_count(i) {

  if(!i) grapple_count++;
  else grapple_count += i;

  if(i <= 0) return 1;

  /* have all of the grapple machines have been built? */
  if(grapple_count >= MAX_GRAPPLE) {
	realm_tell(HIW+"\n"+
		"An Ariel soars overheard and shouts: They have finished the last machine!\n"+
		"We have to stop them "+HIR+"NOW"+HIW+" or we will perish!\n\n"+NORM);
	call_out("loser", 10);
	return 1;
  }

  if(grapple_count == (MAX_GRAPPLE - 1)) {
	realm_tell(HIW+"\n"+
		"An Ariel soars overhead and shouts: The orcs have secured another cable!\n"+
		"If they secure "+HIR+"1 more"+NORM+" they will have enough to destroy our City!\n\n"+NORM);
	return 1;
  }

  realm_tell("\n"+
	HIW+"An Ariel soars overheard and shouts: The orcs have secured another cable\n"+
	"to the Cloud City!  If we don't stop them soon we will all be "+HIR+"doomed!\n\n"+NORM);

  return 1;
}

/********************************************************/
/* this is called when all the grapples have been built */
/********************************************************/
loser() {
  object ob, obj;
  int i;

  if(grapple_count < MAX_GRAPPLE) {
	loser_count = 0;
	return 1;
  }

  if(loser_count < 4) {
    if(loser_count == 0) realm_tell("\nThe Cloud City lurches beneath you.\n\n");
    if(loser_count == 1) realm_tell("\nThe giant cables groan with strain as they pull the City down.\n\n");
    if(loser_count == 3) realm_tell("\nThe Cloud City hovers momentarily on the brink of destruction.\n\n");
    loser_count++;
    call_out("loser", 9);
    return 1;
  }

  realm_tell(HIR+"\n\n"+
	"The Cloud City pitches violently and you stumble to your knees.\n"+
	"The Orcs have captured the City and used their evil grapple-machines\n"+
	"to crash it into the ground!\n\n"+NORM);
  realm_tell(HIR+
	"You are forced to jump for safety as the Cloud City crashes into\n"+
	"the ground.  The sound of the Ariel's sorrowful cries echo in\n"+
	"your head as you run for safety.\n\n"+NORM);

  ob = users();
  for(i=0; i<sizeof(ob); i++) {
	if(environment(ob[i]) && environment(ob[i])->query_cloud_room())
		move_object(ob[i], "players/pavlik/cloudcity/room/start");
  }

  /************/
  /* Clean Up */
  /************/
  grapple_count = 99;
  obj = clone_object("players/pavlik/cloudcity/obj/start_ob");
  for(i=0; i<sizeof(grapple_rooms); i++) {
        move_object(obj, PATH+grapple_rooms[i]);
        if(present("orc_machine", environment(obj)))
		destruct(present("orc_machine", environment(obj)));
  }
  while(find_living("orc_engineer"))
	destruct(find_living("orc_engineer"));

  return 1;
}

/************************************************/
/* broadcast a message to everyone in the realm */
/************************************************/
realm_tell(msg, exclude) {
  object ob;
  int i;

  ob = users();
  for(i=0; i<sizeof(ob); i++) {
	if(environment(ob[i]) && environment(ob[i])->query_cloud_room())
		if(!exclude || environment(ob[i]) != exclude)
			tell_object(ob[i], msg);
  }
  return 1;
}

clean_up() { return 1; }

