#define NAME "Braxana"
#define DEST "players/mythos/enterance"
id(str) { return str == "statue"; }

short() {
string name;
  name = allocate(10);
   name[0] = "Lemur";
  name[1] = "Corba";
  name[2] = "Aleph";
  name[3] = "Drone";
  name[4] = "Hyver";
  name[5] = "Syler";
  name[6] = "Saint Dread";
  name[7] = "Plastic Surgeon Bob";
  name[8] = "Blobbo";
  name[9] = "Daffy";
  return "Statue of "+name[random(10)];
}

long() {
  write(short());
}


reset(arg) {
}

is_castle(){return 1;}
