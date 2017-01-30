/*  List of MK Rankings - Dragnar 6/10/99 */

#define PATH "players/dragnar/MKScar/MKList"
#define LOG "/players/dragnar/MKScar/log/RankDelete"
#define LOG2 "/players/dragnar/MKScar/log/RankDemote"
#define MAX 199

string *names;

void reset(int arg) {
  if(arg) return;

  restore_object(PATH);
}

Demote(string who) {
  int index;
  string who2;

  index = member_array(who, names);
   write_file(LOG2, ctime(time())+": "+who+" was demoted in the Rankings.\n");
  if(index > -1 && index < sizeof(names) -1) {
    who2 = names[index+1];
    Insert(who2, who);
  }
}

Insert(string victor, string defeated) {
  int v_index;
  int d_index;
  int i;

  restore_object(PATH);

  victor = capitalize(victor);
  defeated = capitalize(defeated);
  v_index = member_array(victor, names);
  d_index = member_array(defeated, names);

  if( d_index < v_index ) {
    /* Victor was ranked lower than person defeated, so adjust rankings */

    for( i = v_index - 1; i >= d_index; i-- ) {
      names[i+1] = names[i];
    }
    names[d_index] = victor;
    save_object(PATH);
  }
}

Delete(int number) {
  int i;

  if(number < 1) return 0;
  write_file(LOG, ctime(time())+": "+names[number-1]+" was deleted from the Rankings.\n");
  for(i=number; i < sizeof(names); i++) {
    names[i-1] = names[i];
  }
  names -= ({ names[sizeof(names)-1] });
  save_object(PATH);
}

NewInsert(string name) {
  string who;

  who = name;
  if(!who) return;
  if( member_array(who, names) > -1) return 0;
  names += ({ who });
  save_object(PATH);
}

QRank(string who) {
  return (member_array(who,names)+1);
}

ResetList() {
  names= ({ "Goro","Liu Kang","Johnnie Cage","Rayden","Sub-Zero","Reptile","Kano","Sonya","Scorpion",});
  save_object(PATH);
}

string Champion() {
  return names[0];
}

string list() {
  string str, tempstr;
  int i;

  str = "";
  for(i=1; i<sizeof(names) && i < 35; i++ ) {
    tempstr = i+1+".";
    str += pad(tempstr,4) + names[i] + "\n";
  }
  return str;
}

string tail() {
  string str, tempstr;
  int i;

  str = "";
  for(i=25; i<sizeof(names); i++ ) {
    tempstr = i+1+".";
    str += pad(tempstr,4) + names[i] + "\n";
  }
  return str;
}
