/* waiting_room.c
 * Waiting room for my workroom - Rumplemintz
 */

inherit "room/room";

#define WORKROOM "/players/rumplemintz/workroom.c"

void reset(int arg){
  if(arg) return;
  set_short("Rump's Waiting Room");
  set_long("\n"+
"This is a waiting room. When Rumplemintz is busy, or wishes to be\n"+
"left alone (i.e. has his shields up on the workroom), this is where\n"+
"someone should wait. There is a counter with a bell sitting on top\n"+
"and a sign hanging behind it.\n");
  items = ({
    "sign", "Maybe you should read it",
    "bell", "A steel bell with a plunger on top. Looks like you could ring it",
    "counter", "Looks like a good place for an assistant, though it's vacant"
  });
  dest_dir = ({
    "/room/church", "church",
    "/players/rumplemintz/workroom", "workroom",
    "/room/shop", "shop",
    "/room/vill_green", "green"
  });
  set_light(1);
}

void init(){
   ::init();
   add_action("read_sign", "read");
   add_action("ring_bell", "ring");
}

int read_sign(string str){
  if(str=="sign"){
    write("Rumplemintz's Waiting Room\n");
    write("-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    write("Ring bell for assistance  \n");
    write("-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    return 1;
  }
  return 0;
}

int ring_bell(string str){
   if(str=="bell"){
      write("You ring the bell on the counter.\n");
      say(this_player()->query_name()+" rings the bell.\n");
      write("DING DING DING DING\n");
      if(WORKROOM->check("rumplemintz"))
         tell_object(find_player("rumplemintz"), this_player()->query_name()+
           " is ringing the waiting room bell.\n");
      return 1;
   }
   return 0;
}
