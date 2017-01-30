/*  A new way by Saber to make messages appear in multiple
      rooms at the same time.  Wind, traffic?  Whats next?
*/

id(str) { return str == "wind"; }

long() {
  write("A savage wind.\n");
        }

reset(arg) {
    if(arg) return;
call_out("wind",30);
        }

#define WIND "The wind howls savagely as it passes by, chilling you to the bone.\n");
#define TOWER "/players/saber/tower/tower20

wind() {
  tell_room(TOWER",    WIND
  tell_room(TOWER+01", WIND
  tell_room(TOWER+3",  WIND
  tell_room(TOWER+4",  WIND
  tell_room(TOWER+5",  WIND
  tell_room(TOWER+6",  WIND
  tell_room(TOWER+7",  WIND
  tell_room(TOWER+71", WIND
  tell_room(TOWER+8",  WIND
  tell_room(TOWER+9",  WIND
  tell_room(TOWER+11", WIND

call_out("wind",30);
   return 1;
}

get()  { return 0; }
