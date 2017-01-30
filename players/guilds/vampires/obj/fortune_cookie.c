/*
 fortune_cookie.c
  This is just for laughs.  It will heal a player 2 if they eat it.
*/

inherit "obj/treasure";

object fortune_obj;

int cookie_is_broken, random_nbr;

string str, fortune_table;

init() {
  ::init();

  add_action("get_paper",    "get");
  add_action("break_cookie", "break");
  add_action("break_cookie", "open");
  add_action("eat_cookie",   "eat");
}

get_paper(str) {
  if (!str) return;
  if (str!="paper" && str!="fortune") return;
  write("You can't get the paper without breaking the cookie.\n");
  return 1;
}

break_cookie(str) {
if(!str) { write("Break what?\n"); return 1; }
if(cookie_is_broken == 1) {
  write("The cookie is already broken.\n"); return 1; }
  write("Crunch.  Crackle.  As you break the cookie you find a\n"+
        "small slip of paper from inside the pieces.\n");
  say("Crunch.  Crackle.  "+this_player()->query_name()+
      " breaks a small cookie and gets a\n"+
      "small slip of paper from inside the pieces.\n");
  get_fortune();
  cookie_is_broken=1;
  return 1;
}

eat_cookie(str) {
if(!str) { write("Eat what?\n"); return 1; }
  write("Crunch.  Crunch.  Crunch.  Ummmm.  That tasted good!\n");
  say("Crunch.  Crunch.  Crunch.  "+this_player()->query_name()+
      " makes lots of noise as "+this_player()->query_pronoun()+
      " eats a cookie.\n");
  this_player()->heal_self(2);
  if(!cookie_is_broken) {
    write("Umph!  What?  There was a piece of paper in there!\n"+
          "You pull a small strip of paper out of your mouth.\n");
    say(this_player()->query_name()+" makes a strange face and pulls\n"+
        "a small strip of paper out of "+this_player()->query_possessive()+
        " mouth.\n");
    get_fortune();
  }
  destruct(this_object());
  return 1;
}

reset(arg) {
  set_short("fortune cookie");
  set_long("A small cookie with a piece of paper folded into it.\n");
  set_value(10);
  set_weight(1);
  cookie_is_broken=0;
}

get_fortune() {
  if (!fortune_table) fill_fortune_table();
  fortune_obj = clone_object("players/eurale/VAMPIRES/OBJ/fortune_paper.c");
  fortune_obj->set_message(fortune_table[random(21)]);
  move_object(fortune_obj, this_player());
  return 1;
}

fill_fortune_table() {
  fortune_table = allocate(21);

fortune_table[20] =
  "Early to bed, early to rise, and your sweetheart will go\n"+
  "out with other guys!";
fortune_table[19] =
  "In the name of the father, son and holy ghost..\n"+
  "He who eats the fastest gets the most!";
fortune_table[18] =
  "They said, 'cheer up, things could be worse'\n"+
  "so I cheered up, and sure enough things got worse!";
fortune_table[17] =
  "NEVER eat yellow snow!";
fortune_table[16] =
  "Run, run, run away... and live to fight another day!";
fortune_table[15] =
  "Work hard and power will eventually befall you.";
fortune_table[14] =
  "He who cheats on the vampire tasks will eventually be found out!";
fortune_table[13] =
  "Age and treachery will overcome youth and skill!";
fortune_table[12] =
  "If at first you don't succeed, you're probably normal.";
fortune_table[11] =
  "Many things come to those who kick bootie.";
fortune_table[10] =
  "It's never a good idea to let your HPs fall below zero.";
fortune_table[9] =
  "Dying is part of living so get on with it.";
fortune_table[8] =
  "Candy is dandy but liquor is quicker!";
fortune_table[7] =
  "If you're going to fight, be sure to wear your equipment!";
fortune_table[6] =
  "If you look a gift horse in the mouth, he may bite you.";
fortune_table[5] =
  "Smile and the world smiles with you...\n"+
  "Frown and you'll spend your time alone.";
fortune_table[4] =
  "He who never gambles, never wins!";
fortune_table[3] =
  "The luckiest people also seem to be the hardest working.";
fortune_table[2] =
  "It's not the size of the dog in the fight...\n"+
  "But the size of the fight in the dog.";
fortune_table[1] =
  "Take time to stop and smell the flowers.";
fortune_table[0] =
  "Beauty is only skin deep, but oh, that skin!";
}

long() {
  if (cookie_is_broken)
    write("The broken pieces of a small cookie.\n");
  else
    write("A small cookie with a piece of paper folded into it.\n");
}

id(str) { return (str=="cookie" || str=="fortune cookie"); }
