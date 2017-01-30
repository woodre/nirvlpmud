/* Sparrow 12/27/2006
   Made this room into the master object for the new kale format
*/
#include "/sys/ansi.h"
#define KALEROOM "/players/sparrow/working_dir/kales/"
inherit "room/room";

/* GLOBALS */
object *Room_array;
int *Superkale_array;

int
master_clean_rooms() {
  int i,j;
  object dr;
  /* if there is no room array then return 0 */
  if(!Room_array) {
    return 0;
  }
  i = sizeof(Room_array);
  /* if there is an array but no rooms in it, return 0 */
  if(!i > 0) {
    return 0;
  }
  i--;
  j = 0;
  /* go through all the rooms backwards */
  while(i > -1) {
    if(!first_inventory(Room_array[i])) {
      dr = Room_array[i];
      Room_array -= Room_array[i];
      destruct(dr);
      j++;
    }
    i--;
  }
  return j;
}


reset(arg) {
  /* if reset(1) then clean up all of the cloned rooms - Sparrow */
  if(arg == 1) {
    /************ call cleanup functions here *************/
    int num_clean;
    num_clean = master_clean_rooms();
    if(num_clean == -1) {
      log_file("sparrowkale.log", "ERROR: Cleaning of rooms FAILED at: "+ctime()+"\n");
    }
    else {
      log_file("sparrowkale.log", "STATUS: Cleaned "+num_clean+" rooms at: "+ctime()+"\n");
    }
  }
  if(arg) return;
  /*
  if (!present("flier")) {
    move_object(clone_object("/players/francesco/kale/items/contest.c"),this_object());  
  }
  */
  set_light(1);
  short_desc = ""+HIR+"C"+NORM+YEL+"o"+HIY+"l"+HIG+"o"+HIB+"r"+HIM+"s"+NORM+" entrance";
  long_desc =
    "   This room has been decorated with several posters and drawings on \n"+
    "the walls.  It is of a circular shape, about 20 feet in diameter.\n"+  
    "Some toys are scattered about.  An ample chandelier hangs down from \n"+
    "the ceiling and lights the room.  A board is suspended on a stand.\n";
  items = ({
    "walls","They are covered with some posters",
    "posters","They depict some typical shapes obtained by the fractal theory",
    "drawings","They show some typical shapes obtained by the theory of the diffraction of the light",
    "chandelier","It is made of three tubes, which emit a white shining light",
    "ceiling","It is about twelve feet high",
    "board","A black board holding a flier which you could read",
    "stand","It has three legs and holds a the board",
    "toys",""+HIR+"Th"+NORM+YEL+"e "+HIY+"to"+HIG+"ys"+HIB+" a"+HIM+"re"+NORM+""+HIR+" m"+NORM+YEL+"ul"+HIY+"ti"+HIG+"co"+HIB+"re"+HIM+"d!"+NORM+"",
  });
  dest_dir = ({
    "/room/forest11.c","exit",
  });
}

init() {
  ::init();
  add_action("read","read");
  add_action("random_move","enter");
  return 1;
}

read(str){
  
  if(!str) {
    notify_fail("Read what?\n"); 
    return 0;
  }
  
  if(str == "flier") {
    write("The "+HIR+"C"+NORM+YEL+"o"+HIY+"l"+HIG+"o"+HIB+"r"+HIM+"s"+NORM+" area is actually open only for the kaleidoscopic part.\n"+
          "The kaleidoscopic area can be 'enter'ed from this room.\n"+
          "Just like any other kaleidoscope, it will bring you to an\n"+
          "endless combination of shapes and colors.  Of course, it\n"+
          "is impossible to predict what kind of combination you will\n"+
          "see and what kind of inhabitants (inhabitants??) you will\n"+
          "meet inside.  Likewise, it is unpredictable how to exit\n"+
          "the area, even though it will not be very difficult.\n"+
          "For the best effects, please turn off your brief toggle.\n"+
          "Enjoy the multishaped, multicolored features of the \n"+
          ""+HIR+"Ka"+NORM+YEL+"le"+HIY+"id"+HIG+"os"+HIB+"co"+HIM+"pe"+NORM+"!\n");    
    return 1;
  }
  notify_fail("Read what?\n"); 
  return 0;
}

query_no_fight() { 
  return 1; 
}

random_move(str) {
  if(!str) {
    notify_fail("Enter what?\n"); 
    return 0;
  }
  if(str=="kale" || str=="kaleido" || str=="kaleidoscope") {
    /* Changed to use the new movement functions - Sparrow */
    move_me(this_player(), environment(this_player()));
    return 1;
  }
  notify_fail("You cannot enter the "+str+".\n"); return 0;
}

void
move_me(object me, object myroom) {
  int element, size, newroom;
  object moveto, superkale,kale;
  size = sizeof(Room_array);
  element = member(Room_array, myroom);
  /* If we have at least 10 rooms in the array but less than 50, determine wheter we 
     clone a new room or move to an existing one.
  */
  if(size < 50) {
    newroom = random(2);
    /* if we only have a few rooms loaded already, to avoid an infinite loop we will
       automatically load a new room - Sparrow
    */
    if(size < 10) {
      newroom = 1;
    }
    /* If we are creating a new room create a new room and attempt to fill it with creatures 
       - Sparrow
    */
    if(newroom == 1 || size < 15) {
      moveto = clone_object(KALEROOM+"kaleroom.c");
      Room_array += ({moveto});
      moveto->set_master(this_object());
      /* Check to see if we have already cloned the superkales, if not, random chance
         of cloning one. I chose  50% chance of loading them because these are the boss
         mobs of the area. I feel that there should be a good chance that they load.
         This object keeps track of whether or not each superkale has been loaded
         to make sure that multiples are not loaded. There are actually two more
         superkales in that directory. The files that I have seen so far don't seem
         to load the other two so they are not included. I will take a look at them
         and see if they are indeed loaded somewhere, will be easy enough to add.
         - Sparrow
      */
      if(random(2) == 0) {
        /* see if superkale 1 is already loaded - Sparrow */        
        if(Superkale_array[0] == 0) {
          kale = clone_object("/players/francesco/kale/mobs/superkale1.c");
          move_object(kale, moveto);
          Superkale_array[0] = 1;       
        }
        /* see if superkale 2 is already loaded - Sparrow */
        else if(Superkale_array[1] == 0) {
          kale = clone_object("/players/francesco/kale/mobs/superkale2.c");
          move_object(kale, moveto);
          Superkale_array[1] = 1;
        }          
      }
      /* if we havent loaded any superkales, now try to load regular kales 
         50% chance of 0
         25% chance of 1
         25% chance of 2
         - Sparrow
      */
      if(!kale) {
        switch(random(4)) {
          case 0:
            kale = clone_object("/players/francesco/kale/mobs/kale"+random(15)+".c");
            move_object(kale, moveto);
            break;
          case 1:
            kale = clone_object("/players/francesco/kale/mobs/kale"+random(15)+".c");
            move_object(kale, moveto);
            kale = clone_object("/players/francesco/kale/mobs/kale"+random(15)+".c");
            move_object(kale, moveto);
            break;
          case 2: case 3:
            break;
        }
      }
    }
  }  
  /* If we already have 50 rooms loaded or we have randomly selected an existing 
     room, move player to an existing room - Sparrow 
  */
  if(size == 50 || newroom == 0) {
    moveto = Room_array[random(size)];
    /* make sure the room we are moving to is not the room that we currently in 
    - Sparrow
    */
    if(moveto == myroom) {
      moveto = Room_array[member(Room_array, myroom) - 1];
      if(!moveto) {
        moveto = Room_array[member(Room_array, myroom) + 1];
      }
    /* oh well, something went wrong, go to the same room */
    if(!moveto) { moveto == myroom; }
    }
  }
  /* Move player to new room, write exit messages for player and room, and force player
     to look - Sparrow
  */
  tell_object(me, "You wander off to look at another pattern of the kaleidoscope.\n");
  move_object(me, moveto);
  tell_room(myroom, capitalize((me->query_name()))+" wanders off to look at another pattern of the kaleidoscope.\n");
  me->look();
  return;
}

void
remove_room(object room) {
  int ele;
  if(!room || !Room_array) { return; }
  ele = member(Room_array, room);
  if(ele == -1) {
    log_file("sparrowkale.log", "ERROR: Master object received request to remove a room from memory\n"+
                                "       that is not a member of room array.\n"+
                                "ERROR: "+ctime()+"\n");
    return;
  }
  Room_array -= Room_array[ele];
  return;
}

