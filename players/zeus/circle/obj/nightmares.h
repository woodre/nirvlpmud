/* call_out("nightmare2", 3, environment());  */

nightmare(object x){
  int u;
  u = random(7);
  switch(u){
  case 0: nightmare1(x); break;
  case 1: nightmare2(x); break;
  case 2: nightmare3(x); break;
  case 3: nightmare4(x); break;
  case 4: nightmare5(x); break;
  case 5: nightmare6(x); break;
  case 6: nightmare7(x); break;
  }
}

nightmare1(object x){
  int y;
  y = (int)x->query_spell_point() + 16;
  if(x->query_combat())
  {
    call_out("nightmare1", 20, environment());
    return;
  }
  tell_object(x,
"\n\n"+
BOLD+BLK+"\tSuddenly your vision goes black!\n"+NORM+
"\n"+
"Horrific images of death and destruction flash before your eyes.\n"+
"You see men slaughtered as they beg on their knees.\n"+
"Women and children fleeing for their lives.\n"+
"Hordes of demons burning and destroying everything.\n"+
"Dread fills you as you look on helplessly.\n"+
"\n"+
"You grab your head, trying to regain control of your senses.\n"+
"\n\n");
  x->add_spell_point(-y);
}

nightmare2(object x){
  int y;
  y = (int)x->query_spell_point() + 16;
  if(x->query_combat())
  {
    call_out("nightmare2", 20, environment());
    return;
  }
  tell_object(x,
"\n\n"+
BOLD+BLK+"\tSuddenly your vision goes black!\n"+NORM+
"\n"+
"You are laying on the ground, pain elgufing your entire body.\n"+
"You try to move, only to realize that you are pinned to the ground.\n"+
"You touch your stomach, feeling blood pouring from your wounds.\n"+
"Above you a creature stands, its claws digging into your chest.\n"+
"It grins as it stares at you, about to deliver the final blow.\n"+
"\n"+
"You suddenly shake violently as reality fades into view...\n"+
"\n\n");
  x->add_spell_point(-y);
}

nightmare3(object x){
  int y;
  y = (int)x->query_spell_point() + 16;
  if(x->query_combat())
  {
    call_out("nightmare3", 20, environment());
    return;
  }
  tell_object(x,
"\n\n"+
BOLD+BLK+"\tSuddenly your vision goes black!\n"+NORM+
"\n"+
"It is daytime, but as you look up, you realize the sky is black.\n"+
"All around you demons are running about..  everything is on fire.\n"+
"You are knocked to the ground, a demon attacks you from behind.\n"+
"You suddenly feel a sharp pain in the back of you neck.\n"+
"Then all is black...\n"+
"\n"+
"You sudednly shake, as you open your eyes...\n"+
"\n\n");
  x->add_spell_point(-y);
}

nightmare4(object x){
  int y;
  y = (int)x->query_spell_point() + 16;
  if(x->query_combat())
  {
    call_out("nightmare4", 20, environment());
    return;
  }
  tell_object(x,
"\n\n"+
BOLD+BLK+"\tSuddenly your vision goes black!\n"+NORM+
"\n"+
"Off to the north, a giant black vortex is visible in the sky.\n"+
"It is slowly growing, expanding outwards over the trees.\n"+
"As you stare into its depths, you shiver uncontrollably.\n"+
"\n"+
"All of a sudden you awaken..  and all is normal.\n"+
"\n\n");
  x->add_spell_point(-y);
}

nightmare5(object x){
  int y;
  y = (int)x->query_spell_point() + 16;
  if(x->query_combat())
  {
    call_out("nightmare5", 20, environment());
    return;
  }
  tell_object(x,
"\n\n"+
BOLD+BLK+"\tSuddenly your vision goes black!\n"+NORM+
"\n"+
"You are running through the forest as fast as you can.\n"+
"Your whole body aches, but you can not stop.\n"+
"As you turn, you see your parents taken down by demons.\n"+
"In a matter of moments, their bodies are torn to pieces.\n"+
"You can do nothing but run......    run....\n"+
"\n"+
"You jerk awake suddenly!\n"+
"\n\n");
  x->add_spell_point(-y);
}

nightmare6(object x){
  int y;
  y = (int)x->query_spell_point() + 16;
  if(x->query_combat())
  {
    call_out("nightmare6", 20, environment());
    return;
  }
  tell_object(x,
"\n\n"+
BOLD+BLK+"\tSuddenly your vision goes black!\n"+NORM+
"\n"+
"You awake to the sounds of your parents screaming.\n"+
"You run from the house, fleeing into the night.\n"+
"There are people all around you, horrified and confused.\n"+
"Nothing seems to make sense anymore...\n"+
"\n"+
"You slowly awaken, feeling confused and lost.\n"+
"\n\n");
  x->add_spell_point(-y);
}

nightmare7(object x){
  int y;
  y = (int)x->query_spell_point() + 16;
  if(x->query_combat())
  {
    call_out("nightmare7", 20, environment());
    return;
  }
  tell_object(x,
"\n\n"+
BOLD+BLK+"\tSuddenly your vision goes black!\n"+NORM+
"\n"+
"You cower behind the boxes and crates, hoping not to be found.\n"+
"You can hear 'things' running around on the floor above you.\n"+
"Faint screams pierce you like needles as you sob into your hands.\n"+
"Oh if only there was something you could do.\n"+
"\n"+
"Clarity returns to you as the darkness fades.\n"+
"\n\n");
  x->add_spell_point(-y);
}


