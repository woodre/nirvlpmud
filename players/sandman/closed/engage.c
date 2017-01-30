#define who "sandman"
#define me "china"
#define cp(str) capitalize(str)
short() { return "A ring of engagement ("+cp(who)+") (worn)"; }
get() { return 1; }
drop() { 
  return this_player()->query_real_name() != who;
}
query_auto_load() { return "/players/sandman/closed/engage:"; }
id(str) { return str == "ring of engagement" || str == "ring" || 
str == "engagement ring"; }
init() {
  if(this_player()->query_real_name() == me) {
    add_action("engage", "ering");
    add_action("tossme", "toss");
    add_action("ringgo", "visit");
  } else {
    write("Type \"engage\" when you are ready to give "+cp(me)+" the ring.\n");
    add_action("handover", "engage");
  }
}
long() {
 write("A priceless ring crafted in days long gone when Elf, Dwarf and Man\n");
 write("worked, lived and fought together. Crafted to celebrate the\n");
 write("engagement of Arwen, evening star of the elves, and Aranthor King\n");
 write("of Gondor, it is a marvel of craftsmanship. The band is made of\n");
 write("intertwining strands of gold and mithril that are as thin as blades\n");
 write("of grass. Atop the band, in the most delicate of settings, is a\n");
 write("marvel of the jeweler's art. Emeralds, gleaned from the depths of\n");
 write("Moria, are carved into the shape of tiny flower petals, opening up\n");
 write("as if the sun had just hit it. In the center of the emerald\n");
 write("flower is nestled one of the rare siral diamonds. The diamond\n");
 write("glows softly with an inner light, giving off a soft white light.\n");
  write("Inscribed on the inside of the band is the following:\n");
  write(" "+cp(who)+" and "+cp(me)+", forever.\n");
  write(" <Type \"ering\" for info on what this ring can do.>\n");
  return 1;
}
engage() {
  write("Your beautiful enagement ring allows you to do the following:\n");
  write("visit       Visit your beloved (50 sp).\n");
  write("toss ring   Abandon your engagement.\n");
  return 1;
}
tossme(str) {
  if(!id(str)) return 0;
  write("You decided you'd rather not marry "+cp(who)+" after all.\n");
  if(find_player(who))
    tell_object(find_player(who), cp(me)+" decided not to marry you.\n");
  destruct(this_object());
  return 1;
}
visit() {
  object env;
  if(!find_player(who)) {
    write(cp(who)+" is not logged in.\n");
    return 1;
  }
  env = environment(find_player(who));
  if(env->realm() == "NT" || environment(this_player())->realm() == "NT") {
    write("Something blocks the way.\n");
    return 1;
  }
  if(this_player()->query_sp() < 50) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  tell_object(find_player(who),"Your fiance comes to visit you.\n");
  write("You visit your spouse.\n");
  find_player(who)->remote_say(cp(me)+" arrives.\n");
  say(cp(me)+" leaves to visit her fiance.\n");
  this_player()->add_spell_point(-50);
  move_object(this_player(), env);
  return 1;
}
handover() {
  object ob;
  ob = find_player(me);
  if(!ob) {
    write(cp(me)+" isn't on.\n");
    return 1;
  }
  write("You take "+cp(me)+"'s hand, and gently slide the ring onto her ring\n");
  write("finger.\n");
  tell_object(ob, cp(who)+" gently slides the engagement ring onto your finger.\n");
  say(cp(who)+" gently slides an engagement ring onto "+cp(me)+"'s finger.\n", ob);
  move_object(this_object(), ob);
  return 1;
}
