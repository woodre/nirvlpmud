/* Sparrow 12/27/2006
Made this room into the master object for the new kale format
*/
#include "/sys/ansi.h"
#define KALEROOM "/players/francesco/kale/rooms/"
inherit "room/room";

/* GLOBALS */
object *Room_array;
int *Superkale_array;

int
master_clean_rooms() {
   int i,j;
   object dr;
   /* if there is no room array then return 0 */
   if(!Room_array || !sizeof(Room_array) > 0) {
      return 0;
   }
   i = sizeof(Room_array);
   i--;
   j = 0;
   /* go through all the rooms backwards */
   while(i > -1) {
      if(!first_inventory(Room_array[i])) {
         dr = Room_array[i];
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
    int num_clean;
    num_clean = master_clean_rooms();
    if(num_clean == -1) {
      log_file("sparrowkale.log", "ERROR: Cleaning of rooms FAILED at: "+ctime()+"\n");
    }
    return;
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
         "to"});
  dest_dir = ({
         "/room/forest11.c","exit",
         "/room"});
}

init() {
   ::init();
   add_action("read","read");
   add_action("random_move","enter");
   Superkale_array = ({0,0});
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
      move_me(this_player());
      return 1;
   }
   notify_fail("You cannot enter the "+str+".\n"); return 0;
}

void
player_travel(object me, object room) {
   string myname;
   object myroom;  
  /* Move player to new room, write exit messages for the room, and force player
   to look - Sparrow
   */
   myroom = environment(me);
   move_object(me, room);
   myname = (string)me->query_name();
   tell_room(myroom, capitalize(myname)+" wanders off to look at another pattern of the kaleidoscope.\n");
   me->look();
   return;
}

object
create_room(int firstroom) {
  object newroom, kale;
  int i,j;
  newroom = clone_object(KALEROOM+"kaleroom.c");
  newroom->set_master(this_object());
  if(firstroom == 1) { Room_array = ({newroom}); }
  
  else { Room_array += ({newroom}); }
  
  i = member(Superkale_array, 0);
  if((random(2) == 0) && (i > -1)) {
      j = i+1;
      kale = clone_object("/players/francesco/kale/mobs/superkale"+j+".c");
      move_object(kale, newroom);
      Superkale_array[i] = 1;       
      return newroom;
  }  
  
  /* if we havent loaded any superkales, now try to load regular kales 
     - Sparrow
  */
  switch(random(4)) {
    case 0:
      kale = clone_object("/players/francesco/kale/mobs/kale"+random(15)+".c");
      move_object(kale,newroom);  
      return newroom;
      break;
    case 1:
      kale = clone_object("/players/francesco/kale/mobs/kale"+random(15)+".c");
      move_object(kale,newroom);
      kale = clone_object("/players/francesco/kale/mobs/kale"+random(15)+".c");
      move_object(kale,newroom);
      return newroom;
      break;
    default:
      return newroom;
  }
}

void
move_me(object me) {
  int array_size, firstroom, element;
  object moveto;
  /* Check to see if we already have any rooms loaded. If not set the firstroom
     flag to 1 - Sparrow
  */
  if(Room_array) {
    firstroom = 0;
    array_size = sizeof(Room_array);
    element = random(50);
    if(element < array_size) {
      moveto = Room_array[element];
    }
    else {
      moveto = create_room(firstroom);
    }
  }
  else { 
    firstroom = 1;
    moveto = create_room(firstroom);     
  }
  player_travel(me, moveto);   
  return;
}  

void
remove_room(object room) {
   int ele;
   if(!room || !Room_array) { return; }
   ele = member(Room_array, room);
   if(ele == -1) {
      return;
   }
   Room_array -= ({ Room_array[ele] });
   return;
}