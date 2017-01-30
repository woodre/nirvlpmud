main(string str) {
  int level;

  level = previous_object()->query_skill(str);
  if(level) {
    write("Skill "+str+" is at level "+level+".\n");
    return 1;
  }
  write("Skill "+str+" has not yet been mastered.\n");
  return 1;
}
