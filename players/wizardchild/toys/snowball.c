#define PUDDLE "/players/wizardchild/toys/puddle.c"
#define PILE "/players/wizardchild/toys/snowpile.c"
int melt;
id(str) { return str == "snow" || str == "snowball"; }
short() { return "A snowball"; }
get() { return 1; }
drop() { return 0; }
long() {
  write("A perfectly round snowball, made of compacted pure white snow.\n");
  write("Just looking at it makes you want to throw it at someone...\n");
}
reset(arg) {
  if(!arg) call_out("melt_me",240);
}
melt_me() {
  melt++;
  if(melt < 6) tell_object(environment(), "The snowball partially melts away.\n");
  else {
    object o;
    tell_object(environment(), "The snowball melts completely, leaving a puddle.\n");
    o = clone_object(PUDDLE);
    move_object(o,environment(environment()));
    destruct(this_object());
  }
  return 1;
}
init() {
  add_action("throw","throw");
}
throw(str) {
  string who,what,where;
  object o,p;
  /* no string check added by wocket 11/04/03 */
  if(!str){
    notify_fail("You have to throw the snowball at someone.\n");
    return 0;
  }
  if(sscanf(str, "%s at %s",what,who) != 2) 
    return 0;
  if(!id(what)) return 0;
  if(!(o = find_player(who)) || o->query_invis() > this_player()->query_level()) {
    write("Player not found.\n");
    return 1;
  }
if(who != "wizardchild")
  if(o->query_level() > 20 && this_player()->query_level() < 20) {
    write("You cannot throw that at a wizard!\n");
    return 1;
  }
  who = capitalize(who);
  if(environment(environment()) == environment(o)) {
    write("You quietly space yourself from "+who+".\n");
    write("Then, when nobody is looking, you throw the snowball at "+who+" with all\n");
    write("your strength, and hit them straight in the "+(where=random_part())+"!\n");
    write("You quickly reposition yourself in the crowd, and act shocked.\n");
    tell_object(o,"You hear some shuffling behind you, when...\n");
    tell_object(o,"            SSSLLLAAAMMM!!!\n");
    tell_object(o,"You are hit in the "+where+" by a huge snowball!\n");
    tell_object(o,"The snow falls to the ground, leaving a small pile.\n");
    say("From nowhere, a huge snowball flies straight into "+who+"'s "+where+"!\n",o);
    say(this_player()->query_name()+" moves around.\n");
  } else {
    write("You see "+who+" off in the distance.\n");
    write("With all your strength, you throw the snowball as hard as possible at "+who+"!\n");
    if(!random(3)) {
      write("The snowball misses by just a few feet!\n");
      write("You scream in pure frustration!\n");
      say(this_player()->query_name()+" throws a snowball, but misses.\n");
      say(this_player()->query_name()+" screams in frustration.\n");
      tell_object(o,"A snowball crashes hard within a few feet of you, leaving a pile of snow.\n");
      o->remote_say("A snowball, apparently headed for "+who+", plops on the ground.\n");
    } else {
      write("The snowball slams into "+who+"'s "+(where=random_part())+"!\n");
      write("You stand as the grand master of the snowball.\n");
      say(this_player()->query_name()+" beams someone a ways away with a snowball.\n");
      say("You are left in pure awe of "+this_player()->query_name()+"'s aura.\n");
      tell_object(o,"Just when you thought you were safe...\n");
      tell_object(o,"            SSSLLLAAAMMM!!!\n");
      tell_object(o,"You are hit in the "+where+" by a huge snowball!\n");
      o->remote_say(who+" is beamed by a huge snowball!\n");
      tell_room(environment(o),"The snowball collapses into a pile of snow.\n");
    }
  }
  p = clone_object(PILE);
  move_object(p,environment(o));
  destruct(this_object());
  return 1;
}
random_part() {
  return ({"back","head","arm","leg","butt","face","chest"})[random(7)];
}
