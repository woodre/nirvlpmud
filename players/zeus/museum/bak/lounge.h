/*  Additional stuff for the Museum Lounge */
#include "/players/zeus/closed/all.h"
int opponent, o1,o2,o3,o4,o5,o6,o7,o8,o9,o666;

clean_room(object room){
  int i;
  object *wr;
  if(!room)
	  room->reset();
  wr = all_inventory(room);
  for(i=0; i<sizeof(wr); i++) {
    MO(wr[i], "/players/zeus/museum/void.c");
	}
  wr = all_inventory(room);
  if(sizeof(wr) > 0){
	for(i=0; i<sizeof(wr); i++) {
       MO(wr[i], "/players/zeus/museum/void.c");
	}
  }
}


clean_arena(){
	clean_room("/players/zeus/museum/arena/ar1.c");
	clean_room("/players/zeus/museum/arena/ar2.c");
	clean_room("/players/zeus/museum/arena/ar3.c");
	clean_room("/players/zeus/museum/arena/ar4.c");
	clean_room("/players/zeus/museum/arena/ar5.c");
	clean_room("/players/zeus/museum/arena/ar6.c");
	clean_room("/players/zeus/museum/arena/ar7.c");
	clean_room("/players/zeus/museum/arena/ar8.c");
	clean_room("/players/zeus/museum/arena/ar9.c");
}

occupied(){
  int i;
  int temp;
  object* person;
  string place;
  person = users();
  for(i = 0; i < sizeof(person); i++){
    if(environment(person[i])) {
		if(sscanf(file_name(environment(person[i])), 
                "players/zeus/museum/arena/%s", place)){
			temp = 1;
		}
	}
  }
  return temp;
}

npc1(){ o1 = 0; }
npc2(){ o2 = 0; }
npc3(){ o3 = 0; }
npc4(){ o4 = 0; }
npc5(){ o5 = 0; }
npc6(){ o6 = 0; }
npc7(){ o7 = 0; }
npc8(){ o8 = 0; }
npc9(){ o9 = 0; }
npc666(){ o666 = 0; }

