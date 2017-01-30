/* weenie.c: water weenie */
#define USES 6
int used;
add_water(x) { 
  used -= x;
  if(used < 0) used = 0;
}
query_water() { return (USES-used); }
get() { return 1; }
query_value() { return 20+(query_water()*10); }
drop() { return 0; }
id(str) { return str == "weenie" || str == "water weenie" 
  || str == "elongated water weenie"; }
short() { 
  string sh;
  sh = "An elongated water weenie";
  if(query_water() > 3) sh += " (jiggling)";
  return sh;
}
long() {
  write("A long rubber 'thing', capable of holding water. At one end is a large\n");
  write("opening, and the other a smaller one. As you hold onto it, water drips\n");
  write("out the smaller end.\n");
  write("You could probably \"squirt\" someone with it, or, if you have extra\n");
  write("water, you could \"refill\" it.\n");
  write("There are about "+query_water()+" squirts left.\n");
  return 1;
}
init() {
  if(environment(this_object()) == this_player())
    add_action("squirt", "squirt");
  else destruct(this_object());
}
squirt(str) {
  object who,s;
  if(!query_water()) {
    write("The water weenie is empty.\n");
    return 1;
  }
  if(!str) { 
    write("Usage: squirt <who>\n");
    return 1;
  }
  who = find_player(str);
  if(!who || who->query_invis() > this_player()->query_level()) {
    write("No such player.\n");
    return 1;
  }
  if(who->query_level() > 20 && who != find_player("wizardchild") &&
     this_player()->query_real_name() != "wizardchild") {
    write("You cannot squirt anybody but Wizardchild.\n");
    return 1;
  }
  if(in_editor(who)) {
    write("That person is busy.\n");
    return 1;
  }
  s = clone_object("/players/wizardchild/toys/squirt");
  write("You aim the water weenie at "+capitalize(str)+", and after stroking it\n");
  write("gently, it lets out a gush of water at "+who->query_possessive()+"!\n");
  tell_object(who, this_player()->query_name()+" squirts you with a gush of water!\n");
  tell_object(who, "Your clothes are drenched!\n");
  say(this_player()->query_name()+" nails "+capitalize(str)+" with a gush of water!\n",who);
  say("Dang, that water weenie really squirts!\n");
  if(environment(who) != environment(this_player())) 
    tell_room(environment(who), capitalize(str)+" is squirted mercilessly with a water weenie!\n");
  if(present("squirt",who)) destruct(present("squirt",who));
  move_object(s, who);
  used++;
  return 1;
}  
