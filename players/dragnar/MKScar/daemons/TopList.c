/*  List to keep track of top player killers - Dragnar 6/1/99 */

#define PATH "players/dragnar/MKScar/TopList"
#define MAX 14

string *names;
int *kills;

void reset(int arg) {
  if(arg) return;

  restore_object(PATH);
}
Insert(string name, int amt) {
  int index;

  restore_object(PATH);

  name = lower_case(name);
  index = member_array(name, names);
  if( index > -1 ) {
    if(kills[index] < amt) kills[index] = amt;
    SortList();
    return;
  }
  if( amt > kills[MAX] ) {
    kills[MAX] = amt;
    names[MAX] = name;
    SortList();
    return;
  }
}

void SortList() {
  int pass, hold, i;
  string hold2;

  for( pass = 0; pass < sizeof(kills)-1; pass++ ) {
    for( i = 0; i < sizeof(kills)-1; i++ ) {

      if( kills[i] < kills[i+1] ) {
        hold = kills[i];
        hold2 = names[i];
        kills[i] = kills[i+1];
        names[i] = names[i+1];
        kills[i+1] = hold;
        names[i+1] = hold2;
      }
    }
  }
  save_object(PATH);
}

ResetList() {
names=({"Noone","Noone","Noone","Noone","Noone","Noone","Noone","Noone","Noone","Noone","Noone","Noone","Noone","Noone","Noone",});
kills=({0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,});
  save_object(PATH);
}

string list() {
  string str;
  int i;

  str = "";
  for( i = 0; i < sizeof(kills); i++ ) {
    if(names[i] != "Noone")
    str += capitalize(pad(names[i],16)) + kills[i] +"\n";
  }
  return str;
}
