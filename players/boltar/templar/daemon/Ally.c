/*  Ally Record for Knights Templar - Dragnar 12/7/99 */

#define PATH "players/boltar/templar/daemon/ally"
#define LIST "/players/boltar/templar/daemon/ally_record"
#define MAXSIZE 150

string *ally;   /* Ally name */

/* Declare the functions, otherwise it errors? */
void Delete(string str);
void ResetList();

void reset(int arg) {
  int i;

  if(arg) return;
  restore_object(PATH);
  if(!ally)
    ResetList();
}

void WriteFile() {
  int i;

  rm(LIST);
  for(i=0; i<sizeof(ally); i ++) {
    write_file(LIST, i+1+". "+pad(capitalize(ally[i]),12)+"\n");
  }
}

void Insert(string name) {
  int index;

  restore_object(PATH);
  if(!name) return;
  name = lower_case(name);
  if(!call_other("/players/boltar/templar/verif", "verifpl", name)) {
    write("No active player named "+name+".\n");
  return;
  }
  index = member_array(name, ally);
  if( index > -1 ) {
    write(capitalize(name)+" is already an ally.\n");
    return;
  }
  else {
    if(sizeof(ally) >= MAXSIZE) {
      write("Sorry, ally list is currently full.\n");
      return;
    }
    write(capitalize(name)+" is now an Ally of the Knights Templar.\n");
    ally += ({name,});
    save_object(PATH);
    WriteFile();
    return;
  }
}

status Query(string str) {
  if(member_array(lower_case(str), ally) > -1) return 1;
  else return 0;
}

void Delete(string str) {
  int index;

  index = member_array(lower_case(str), ally);
  if(index > -1) {
    write("You remove "+capitalize(str)+" from their station as a Knight Ally.\n");
    ally -= ({ally[index],});
  }
  else write(capitalize(str)+" is not an ally.\n");
  save_object(PATH);
  WriteFile();
  return;
}

ResetList() {
  ally = ({});
  save_object(PATH);
  WriteFile();
}
