short() { return "A rotting wooden sign"; }
long()  {
  write("This is an old wooden sign, rotting away and covered with mold due\n");
  write("to the moisture and heat.\n");
  write("You could try reading it.\n");
}
id(str) { 
  return str == "sign" || str == "wooden sign" || str == "rotting wooden sign"; 
}
init()  {
  add_action("read","read");
}
read(str) {
  if(!id(str)) return 0;
  write("The sign says:\n\n");
  write("Hello, Welcome to the Congo!\n");
  write("The Congo is an expirement in trickery - the rooms are random, and so\n");
  write("are their content. It is very unlikely that you will be able to return\n");
  write("to any area that you leave, so make sure you look it over pretty good\n");
  write("before you walk off!\n");
  write("Sometimes it's hard to leave this area. If you have that problem, just\n");
  write("walk around a bit and keep trying.\n");
  write("There IS a possibility of you being stuck. It's about 1 in 9 million.\n");
  write("If that happens, just tell a wizard. I doubt we'll have this problem, though.\n");
  write("Monsters here are newbie friendly - if something is aggressive, and you are\n");
  write("way too young to fight it, then it won't attack you. Looking at monsters will\n");
  write("tell you what class they are intended for.\n");
  write("Remember, in darkness, there is more than meets the eye. :)\n");
  write("                                   Ciao,\n");
  write("                                    Wizardchild\n");
  return 1;
}
