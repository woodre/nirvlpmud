id(str) {return str == "teacher";}
short() {return "Plastic Music Teacher";}
long() {write("Plastic Music Teacher\n"); return;}
get() {return 1;}
int note1, note2;
init() {
  add_action("play","play");
}
play(str) {
  if(!str){
    write("Teacher says: What you playing?\n");
    return 1;
  }
  sscanf(str,"note %d note %d", note1, note2);
  if(note1 == 1 && note2 == 2) {
    write("Teacher says: Good Job!\n");
    return 1;
  }
  if(note1 == 1 && note2 != 2) {
    write("Teacher says: Almost there.\n");
    return 1;
  }
  write("Teacher says: All wrong!\n");
  return 1;
}
