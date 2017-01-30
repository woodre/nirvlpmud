/*
 fortune_cookie.c
*/

/*
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
  if (!str || str != "cookie") return;
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
  if (!str || str != "cookie") return;
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
  set_short("A small cookie");
  set_long("A small cookie with a piece of paper folded into it.\n");
  set_value(10);
  set_weight(1);
  cookie_is_broken=0;
}

get_fortune() {
  if (!fortune_table) fill_fortune_table();
  fortune_obj=clone_object("players/nooneelse/obj/fortune_paper");
  fortune_obj->set_message(fortune_table[random(21)]);
  move_object(fortune_obj, this_player());
  return 1;
}

fill_fortune_table() {
  fortune_table = allocate(21);

  fortune_table[20]	="You will solve a riddle and destroy the undead.";
  fortune_table[19]	="You will travel far and learn much of the world.";
  fortune_table[18]	="You are about to undertake a perilous journey.";
  fortune_table[17]	="LOOKOUT!  The system administrator just came in!";
  fortune_table[16]	="You can sometimes smell the way out of trouble.";
  fortune_table[15]	="You will eventually become one of the powerful.";
  fortune_table[14]	="Pssst.  Listen.  To solve the vampire quest you "+
                         "must (cont. on next page)";
  fortune_table[13]	="The wise will overcome adversity.";
  fortune_table[12]	="The pieces of the puzzle are scattered.";
  fortune_table[11]	="All things come to he who kicks butt.";
  fortune_table[10]	="Never let your hp fall below zero.";
  fortune_table[9]	="The end is near.";
  fortune_table[8]	="The path is clear.  You may proceed, "+
                         "but with caution.";
  fortune_table[7]	="Make sure you are always fully equipped.";
  fortune_table[6]	="Always look a gift horse in the mouth.";
  fortune_table[5]	="Always take wooden nickels.";
  fortune_table[4]	="Walk under ladders.  Don't let life get boring.";
  fortune_table[3]	="Balogna baffles brains.";
  fortune_table[2]	="Contemplate the whichness of the why carefully.";
  fortune_table[1]	="This page intentionally left blank.";
  fortune_table[0]	="What the hell are you looking at?";
}

long() {
  if (cookie_is_broken)
    write("The broken pieces of a small cookie.\n");
  else
    write("A small cookie with a piece of paper folded into it.\n");
}

id(str) { return (str=="cookie" || str=="fortune cookie"); }
