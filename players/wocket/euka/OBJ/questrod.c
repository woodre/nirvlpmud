#include "/players/wocket/closed/ansi.h"
#include "../Def.h"
string *stonelist;
string *masterlist;
string *foundlist;
string *northlist;
string *southlist;
string *eastlist;
string *westlist;
string *hints;

id(str){ return (str == "rod" || str == "devination rod" || str == "euka_quest_rod"); }
short(){ return "A devination rod"; }
long(){
  write("This fine devination rod is made from a delecate birch tree.  It's\n"+
        "white coloring and many nodes makes it appear very fragle.  The rod\n"+
        "is shaped like a \"Y\".  When held properly it has been said that\n"+
        "this rod can lead someone to the 3 stones of Euka.\n");
}
get(){ return 1; }
drop(){ return 0; }

reset(arg){
int i,a;
int number;
string *templist;
if(arg) return;
stonelist = allocate(3);
masterlist = ({ "room/farmroad1","room/mine/tunnel13","room/south/sislnd18", });
masterlist += ({ "players/mouzar/castle/mid/cave47","players/wocket/graveyard/gr9", });
masterlist += ({"players/feldegast/island/jungle/jungle15","players/mythos/aroom/rice2", });
masterlist += ({"players/dragnar/WasteLands/rooms/forest4","players/eurale/Glade/eg10", });
northlist = southlist = eastlist = westlist = hints = foundlist = ({});
templist = masterlist;
for(i=0,a=3;i<a;i++){
  number = random(sizeof(templist)-1);
  stonelist[i] = templist[number];
  templist-=stonelist[i];
}
set_dirlists();
set_heart_beat(1);
}

init(){
  add_action("stonesearch","search");
}

query_stones(){ return stonelist[0]+","+stonelist[1]+","+stonelist[2]+"\n"; }
query_masterlist(){ return masterlist[0]+","+masterlist[1]+","+masterlist[2]+"\n"; }

heart_beat(){
string roomfile;
object room;
  if(environment(this_object()) && environment(this_object())->is_player()){
    room = environment(environment(this_object()));
    if(room)
      roomfile = file_name(room);
    if(member_array(roomfile,stonelist) != -1 && member_array(roomfile,foundlist) == -1){
      tell_object(environment(this_object()),"The devination rod shakes violently.\n");
    }
    if(member_array(roomfile,northlist) != -1 && member_array(roomfile,foundlist) == -1){
      tell_object(environment(this_object()),"The devination rod leads you to the north.\n");
    }
    if(member_array(roomfile,southlist) != -1 && member_array(roomfile,foundlist) == -1){
      tell_object(environment(this_object()),"The devination rod leads you to the south.\n");
    }
    if(member_array(roomfile,eastlist) != -1 && member_array(roomfile,foundlist) == -1){
      tell_object(environment(this_object()),"The devination rod leads you to the east.\n");
    }
    if(member_array(roomfile,westlist) != -1 && member_array(roomfile,foundlist) == -1){
      tell_object(environment(this_object()),"The devination rod leads you to the west.\n");
    }
  }
}

set_dirlists(){
int i,a;
for(i=0,a=3;i<a;i++){
switch(stonelist[i]){
case "room/farmroad1":
  southlist += "room/farmroad2";
  eastlist += "room/lanceroad4";
  hints += "lost in the cornfields of the farmlands";
  break;
case "room/mine/tunnel13":
  northlist += "room/mine/tunnel12";
  northlist += "room/mine/tunnel11";
  hints += "the far end of a tunnel"; 
  break;
case "room/south/sisland18":
  northlist += "room/south/sislnd16";
  southlist += "room/south/sislnd13";
  eastlist += "room/south/sislnd17";
  westlist += "room/south/sislnd15";
  hints += "the ruins of Arcanarton";
  break;
case "players/mouzar/castle/mid/cave47":
  eastlist += "players/mouzar/castle/mid/cave41";
  eastlist += "players/mouzar/castle/mid/cave46";
  hints += "in the mountains, north of the great rift";
  break;
case "players/wocket/graveyard/gr9":
  westlist += "players/wocket/graveyard/gr10";
  southlist += "players/wocket/graveyard/gr8";
  hints += "within the graveyard of the dryants";
  break;
case "players/feldegast/island/jungle/jungle15":
  northlist += "players/feldegast/island/jungle/jungle18";
  westlist += "players/feldegast/island/jungle/jungle16";
  eastlist += "players/feldegast/island/jungle/jungle14";
  hints += "in the jungle through the shrine";
  break;
case "players/mythos/aroom/rice2":
  westlist += "players/mythos/aroom/rice";
  hints += "lost in the rice fields"; break;
  break;
case "players/dragnar/WasteLands/rooms/forest4":
  northlist += "players/dragnar/WasteLands/rooms/forest2";
  northlist += "players/dragnar/WasteLands/rooms/forest";
  hints += "deep within the ruined forest of the wastelands";
  break;
case "players/eurale/Glade/eg10":
  eastlist += "players/eurale/Glade/eg9.c";
  northlist += "players/eurale/Glade/eg11.c";
  hints += "hidden in the tall grasses of the glade";
  break;
}

}
}

stonesearch(str){
object room;
object filename;
  if(!str){
    notify_fail("What would you like to search?\n");
    return 0;
  }
  room = environment(environment(this_object()));
  if(room) filename = file_name(room);
  if( (member_array(filename,stonelist) != -1) && (member_array(filename,foundlist) == -1) ){
    if( (str == "grass") && (filename == "players/eurale/Glade/eg10") ){
      write("You find a stone deep with in the grass!\n");
      get_stone(filename);
      return 1;
    }
    if( (str == "marsh") && (filename == "players/mythos/aroom/rice2") ){
      write("You fine a stone deep within the marsh!\n");
      get_stone(filename);
      return 1;
    } 
    if( (str == "skeleton") && (filename == "players/dragnar/WasteLands/rooms/forest4") ){
      write("You find a stone hidden underneath the decaying bones!\n");
      get_stone(filename);
      return 1;
    }
    if( (str == "crops") && (filename == "room/farmroad1") ){
      write("Hidden in the field you unearth a stone!\n");
      get_stone(filename);
      return 1;
    }
    if( (str == "tunnel") && (filename == "room/mine/tunnel13") ){
      write("You find a buried stone!\n");
      get_stone(filename);
      return 1;
    }
    if( (str == "ruins") && (filename == "room/south/sislnd18") ){
      write("You find, hidden underneath lumps of melted rocks, a stone!\n");
      get_stone(filename);
      return 1;
    }
    if( (str == "bushes") && (filename == "players/feldegast/island/jungle/jungle15") ){
      write("You find a stone hidden in the bushes!\n");
      get_stone(filename);
      return 1;
    } 
    if( (str == "cave") && (filename == "players/mouzar/castle/mid/cave47") ){
      write("You find a stone laying on the ground!\n");
      get_stone(filename);
      return 1;
    }
    if( (str == "tombstones") && (filename == "players/wocket/graveyard/gr9") ){
      write("You find a stone hidden behind a tombstone!\n");
      get_stone(filename);
      return 1;
    }
  }
  notify_fail("You find nothing of interest.\n");
  return 0;
}

get_stone(filename){
int number;
object stone;
object wiz;
  number = member_array(filename,stonelist);
  stone = clone_object(EPATH+"OBJ/queststone.c");
  stone->set_number(number);
  foundlist += filename;
  add_foundlist(filename);
  move_object(stone,this_player());
  wiz = clone_object(EPATH+"NPC/questwiz.c"); 
  move_object(wiz,environment(this_player()));
  write("A cloud of smoke apears and Makai appears.\n");
  write("Makai says, \"So you have found one of the hidden stones.  You will not\n"+
                     "finish your quest.  Prepare to face your doom!\"\n");
  say("Makai says, \"So you have found on of the hidden stones.  You will not\n"+
                    "finish your quest.  Prepare to face your doom!\"\n");
  wiz->set_attacker(this_player());
  return 1;
}



add_foundlist(filename){
switch(filename){
case "room/farmroad1":
  foundlist += "room/farmroad2";
  foundlist += "room/lanceroad4";
  break;
case "room/mine/tunnel13":
  foundlist += "room/mine/tunnel12";
  foundlist += "room/mine/tunnel11";
  break;
case "room/south/sisland18":
  foundlist += "room/south/sislnd16";
  foundlist += "room/south/sislnd13";
  foundlist += "room/south/sislnd17";
  foundlist += "room/south/sislnd15";
  break;
case "players/mouzar/castle/mid/cave47":
  foundlist += "players/mouzar/castle/mid/cave41";
  foundlist += "players/mouzar/castle/mid/cave46";
  break;
case "players/wocket/graveyard/gr9":
  foundlist += "players/wocket/graveyard/gr10";
  foundlist += "players/wocket/graveyard/gr8";
  break;
case "players/feldegast/island/jungle/jungle15":
  foundlist += "players/feldegast/island/jungle/jungle18";
  foundlist += "players/feldegast/island/jungle/jungle16";
  foundlist += "players/feldegast/island/jungle/jungle14";
  break;
case "players/mythos/aroom/rice2":
  foundlist += "players/mythos/aroom/rice";
  break;
case "players/dragnar/WasteLands/rooms/forest4":
  foundlist += "players/dragnar/WasteLands/rooms/forest2";
  foundlist += "players/dragnar/WasteLands/rooms/forest";
  break;
case "players/eurale/Glade/eg10":
  foundlist += "players/eurale/Glade/eg9.c";
  foundlist += "players/eurale/Glade/eg11.c";
  break;
}

}
