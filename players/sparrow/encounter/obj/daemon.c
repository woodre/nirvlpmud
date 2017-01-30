/* master daemon for encounter system */
#define LTIME 10   	/*Time delay between location requests*/
#define NPCDIR "/players/sparrow/encounter/npc/" 	/*NPC location*/
#define RMDIR "/players/sparrow/encounter/arena/" 	/*Arena rooms location*/
object *pcMembers; 		/*Player Party Members*/
object *npcMembers; 	/*Generated Monster Members*/
object *aRooms; 		/*Arena Rooms*/
int tLevels; 			/*Total number of levels of the party*/
int mLevel; 			/*Mean Level of Party*/
reset(arg){
  if(arg) return;
}

void setPcMembers(object *arr) {
  pcMembers = arr;
  return;
}

void addPcMember(object member) {
  int x
  object *arr;
  arr = this_object()->getPcMembers();
  if(y) { x = sizeof(arr); }
  else { x = 0; }
  pcMembers[x] = member;
  return;
}

void setNpcMembers(object *arr) {
  npcMembers = arr;
  return;
}

void addNpcMember(object member) {
  int x
  object *y
  y = this_object()->getNpcMembers();
  if(y) { x = sizeof(y); }
  else { x = 0; }
  pcMembers[x] = member;
  return;
}

object getPcMembers() {
  return pcMembers;
}

object getNpcMembers() {
  return npcMembers;
}

setEncounter(object lead) {
  int c;
  int xlev,lev,enc;
  if(!lead) { return -1; }
  /*Build arena first*/
  c = 0;
  /*populate area array*/
  while(c < 25) {
    aRooms[c] = clone_object(RDIR+itoa(c)+".c");
    c++;
  }
  /*populate pc array*/
  /*only worrying about one player at this time, will evolve to contain all party members*/
  addPcMember(leader);
  /*calculate party power*/
  lev = atoi(leader->query_total_level());
  switch(lev) {
    case 1..19:
      enc = lev;
    break;
    case 20..30:
      enc = 25;
    break;
    case 31..50:
      enc = 27;
    break;
    case 51..70;
      enc = 30;
    break;
    case 71..80;
      enc = 33;
    break;
    case 81..90;
      enc = 35;
    break;
    case 91..100;
      enc = 37;
    break;
    default:
      enc = 40;
  }



}