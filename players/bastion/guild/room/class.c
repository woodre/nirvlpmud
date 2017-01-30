
#define me this_player()
string DEPT, TOPIC;
object student;

add_commands() {
  add_action("class", "sit");
  add_action("class", "attend");
}

class() {
  string mess;
  if(!me->query_sorcerer()) {
    notify_fail(format("Wizard says: Don't waste my time. You're obviously " +
     "no student of sorcery.\n"));
    return 0;
  }
  mess="Wizard says: I don't see your name on the class roster...";
  if(!present("validated registration form", me)) {
    mess+="Next time make sure to register.\n";
    write(format(mess));
    return 1;
  }
  if(present("form", me)->query_info()!=DEPT) {
    mess+="No wonder, you're not registered in " + DEPT + ".\n";
    write(format(mess));
    return 1;
  }
  if(student) {
    write("A class is already in progress. Come back later.\n");
    return 1;
  }
  mess+="It must be a clerical error. Take a seat in the back.\n";
  write(format(mess));
  student=me;
  call_out("bore_me", 6);
  return 1;
}

bore_me() {
  tell_object(student,format("\nYou sit for what seems like hours listening " +
   "to the instructor drone on about " + TOPIC + ".\n"));
  tell_object(student, "->> ");
  call_out("end_class", 8);
}

end_class() {
  tell_object(student, format("\nFinally, the instructor decides to look at " +
   "the clock and mutters something about time flying.\n"));
  tell_object(student, "->> ");
  present("magesoul", student)->gain_spellcraft(DEPT);
  destruct(present("validated registration form", student));
  student=0;
}
