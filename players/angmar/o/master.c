#pragma strong_types
#define MAXPHONES 40

inherit "obj/treasure";

string cap_name;
object *phonearray;
int phonenr;

void
reset(status arg) {
  if(arg)
    return;
  phonenr=0;
  phonearray=allocate(40);
  set_name("master-palantir");
  set_alias("palantir");
  set_weight(200);
  set_value(0);
  set_short("The master-palantir");
  set_long(
"It is a large spherical crystal ball. This is the communication-center for all \n"+
"other palantirs. You probably couldn't lift it.\n");
}

int get() { return 1; }

void
init() {
  ::init();
  cap_name = (string)this_player()->query_name();
  add_action("phone", "palantir");
  add_action("phonebook", "palantirs");
  add_action("get_creat", "creator");
}

status
get_creat() {
  object creat;
  creat = clone_object("players/angmar/o/creator");
  creat->set_master(this_object());
  move_object(creat,this_player());
  write("Ok.\n");
  say(this_player()->query_name()+" makes some magical gestures.\n");
  return 1;
}

status
phone() {
  object phone;
  int nr;

  nr=0;
  while(nr<MAXPHONES && phonearray[nr]) {
    nr+=1;
  }

  if(phonenr+1>=MAXPHONES) {
    write("Out of memory.\n");
    return 1;
  }
  phone=clone_object("players/angmar/o/palantir");
  phone->set_nr(100+nr);
  phone->set_station(this_object());
  phonearray[nr]=phone;
  move_object(phone,this_player());
  if(nr==phonenr)
    phonenr+=1;
  write("You speak a magic word and suddenly a palantir appears in\n"+
        "your hands.\n");
  say(this_player()->query_name()+
      " speaks a magic word, and suddenly a palantir appears in\n" +
      this_player()->query_possessive()+" hands.\n");
  return 1;
}

mixed
dial_up(int nr) {
  nr -= 100;
  if (nr < 0 || nr >= phonenr)
    return 0;
  tell_object(environment(),
    "Many-coloured mist is swirling in the master-palantir. Someone\n"+
    "must be using it.\n");
  tell_room(environment(),
    "Many-coloured mist is swirling in the master-palantir. Someone\n"+
    "must be using it.\n");
  return(phonearray[nr]);
}

status
phonebook() {
  int nr;
  nr=0;
  while(nr<phonenr) {
    if (phonearray[nr]) {
      write(nr+100);
      write(": ");
      write(environment(phonearray[nr])->short());
      write("\n");
    }
    nr+=1;
  }
  return 1;
}
