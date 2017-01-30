/*  Criminal Record for Knights Templar - Dragnar 11/9/99 */

#define PATH "players/boltar/templar/daemon/criminal"
#define LIST "/players/boltar/templar/daemon/criminal_record"

#define KILLER    2592000   /* Pet Killer - 30 days */
#define AIDING    2592000   /* Aiding a criminal - 30 days */
#define THIEF     5184000   /* Corpse stealer - 60 days */
#define ATTACK    7776000   /* Attempt to harm innocent - 90 days */
#define MURDERER  10368000  /* Killed innocent or Knight - 120 days */
#define ENEMY     15552000  /* Repeat offender - 180 days */
#define LIFER     31449600  /* Sworn Enemy - 364 days */
#define MAXSIZE   498

string *criminal;   /* Criminal name */
int    *time;   /* Time of punishment */
int    *crime;  /* Type of Crime */

/* Declare the functions, otherwise it errors? */
void Delete(string str);
int GetTime(int time);
string GetType(int type);
void ResetList();

void reset(int arg) {
  int i;

  if(arg) return;
  /* Restore Data, and check for "old" criminals */
  restore_object(PATH);
  if(!criminal)
    ResetList();
  if(sizeof(criminal) != sizeof(time))
    write_file(LIST, ctime(time())+"Criminal array ERROR!\n");
  rm(LIST);
  for(i=0; i<sizeof(criminal); i ++) {
    write_file(LIST, pad(capitalize(criminal[i]),12)+"Crime: "+GetType(crime[i])+
      "   Pardon date: "+ctime(time[i])+"\n");
    if(time[i] - time() <= 0)
      Delete(criminal[i]);
  }
}

void WriteFile() {
  int i;

  rm(LIST);
  for(i=0; i<sizeof(criminal); i ++) {
    write_file(LIST, pad(capitalize(criminal[i]),12)+"Crime: "+GetType(crime[i])+
      "   Pardon date: "+ctime(time[i])+"\n");
  }
}

void Insert(string name, int type) {
  int index,sentence;

  restore_object(PATH);
  if(!name || !type) return;
  sentence = GetTime(type);
  name = lower_case(name);
  if(!call_other("/players/boltar/templar/verif", "verifpl", name)) {
    write("No active player named "+name+".\n");
  return;
  }
  index = member_array(name, criminal);
  if( index > -1 ) {
    if(time[index] < sentence) {
      time[index] = sentence;
      crime[index] = type;
      save_object(PATH);
      WriteFile();
      return;
    }
  }
  else {
    if(sizeof(criminal) >= MAXSIZE) {
      write("Sorry, criminal list is currently full.\n");
      return;
    }
    criminal += ({name,});
    time += ({sentence,});
    crime += ({type,});
    save_object(PATH);
    WriteFile();
    return;
  }
}

status Query(string str) {
  if(member_array(lower_case(str), criminal) > -1) return 1;
  else return 0;
}

string DetailedQuery(string str) {
  int i;

  i = member_array(lower_case(str),criminal);
  if(i > -1) {
    return (pad(capitalize(criminal[i]),12)+"Crime: "+GetType(crime[i])+"   Pardon date: "+ctime(time[i])+"\n");
  }
  else return "";
}

void Delete(string str) {
  int index;

  index = member_array(lower_case(str), criminal);
  if(index > -1) {
    write("You pardon "+capitalize(str)+" of all crimes.\n");
    criminal -= ({criminal[index],});
    time -= ({time[index],});
    crime -= ({crime[index],});
  }
  else write(capitalize(str)+" is not a criminal.\n");
  save_object(PATH);
  WriteFile();
  return;
}

ResetList() {
  criminal = ({});
  time = ({});
  crime = ({});
  save_object(PATH);
  WriteFile();
}

int GetTime(int type) {
  int x;

  switch(type) {
  case 1:
    x = KILLER;
    break;
  case 2:
    x = THIEF;
    break;
  case 3:
    x = ATTACK;
    break;
  case 4:
    x = MURDERER;
    break;
  case 5:
    x = ENEMY;
    break;
  case 6:
    x = LIFER;
    break;
  case 7:
    x = AIDING;
    break;
  default:
    /* This should not happen */
    x = KILLER;
    break;
  }
  return time() + x;
}
string GetType(int type) {
  switch(type) {
  case 1:
    return "killing pets/kids";
    break;
  case 2:
    return "theft";
    break;
  case 3:
    return "attempted murder";
    break;
  case 4:
    return "murder";
    break;
  case 5:
    return "repeat offender";
    break;
  case 6:
    return "sworn enemy";
    break;
  case 7:
    return "aiding a criminal";
    break;
  default:
    /* This should not happen */
    return "Unkown";
    break;
  }
}

