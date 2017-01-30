/*  A room with some advanced features.  Read RYLLIAN.c before you
 *    read this, as it will explain some of the more basic functions.
 *
 *						-- Saber
 */

inherit "room/room";

reset(arg){

if(!present("gypsy"))  {
move_object(clone_object("/players/saber/mini/zzgypsy.c"),this_object());  }

 if(!arg){

 set_light(1);
 short_desc="Valley End";
 long_desc=
 "You have reached the end of the green valley, where the surrounding\n"+
 "mountains of the Spine of the Moon have come together to form a\n"+
 "natural cul-de-sac.\n";

items=({
 "mountain", "The valley is sheltered by tall, snow covered mountains",
 "moon","A distant crescent moon",
 "ground","The valley floor is covered with lush green grass",
 "stars","Softly gleaming stars are visible overhead",
 "valley","A luscious green valley with a pleasantly warm climate",
 "walls","The valley is sheltered by tall, snow covered mountains",
 });

  dest_dir=({
 "/players/saber/ryllian/gv2.c","east",
 "/players/saber/closed/bard/bardrooms/gypsy_q.c","south",
      });
  }   }


/*  The init() lets you add actions which players can do in this
    room.  For example, players can search this room, or go in a
    cave.  The first word is the name of the function called, 
    which happens when the second word is typed.                  */
init()  {
 ::init();
  add_action("search_room","search");
  add_action("go_in","in");
  add_action("south","south");
}


/*  This will tell players who type search that they find a cave.  */
search_room() {
  write("You find a small cave to the north\n"+
       "Perhaps you could go 'in' to it\n");
  say (this_player()->query_name() +" searches the area\n");
  return 1;  }


/*  This will move players into the cave.              */
go_in() {
call_other(this_player(),"move_player","in#players/saber/ryllian/cave.c");
say(this_player()->query_name()+" enters a small cave\n");
return 1;  }


/*  This is a very selective program which will ONLY let bards
    travel south.  It can easily be modified to exclude other
    types of player by things such as level (for newbee realms),
    gender, ect.                                       */
south()  {
object ob;
  ob = present("instrument",this_player());

if(!present("instrument",this_player()))  {
  write("You are not a bard.  You may not go south.\n");
  return 1;
        }

if((this_player()->query_level()) < 10)  {
  write("You are not high enough level to go south.\n");
  return 1;
        }

 if(ob->query_bard_level() !=4)  {
  write("You must be bard level 4 to go south.\n");
  return 1;
        }

call_other(this_player(),"move_player","south#players/saber/closed/bards/bardrooms/gypsy_q.c");
  return 1;
         }
