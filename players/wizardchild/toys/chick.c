/* chick.c: rubber chicken */
short() { return "A rubber chicken"; }
long()  {
  write("A wobbly rubber chicken. Some folks use them for juggling, but\n");
  write("this one looks like it was made for \"thwap\"ing people.\n");
  write("You can also \"fondle\" it; i hear that's very popular in malaysia.\n");
  write("NEW NEW NEW: You can now \"nuke chicken\" (whee).\n");
  return 1;
}
get() { return 1; }
query_value() { return 30; }
id(str) { return str == "chicken" || str == "rubber chicken"; }
init() {
  if(environment(this_object()) == this_player()) {
  add_action("thwap", "thwap");
  add_action("fondle", "fondle");
  add_action("nuke", "nuke");
  }
}
thwap(str) { 
  object ob;
  if(!str) return 0;
  if(find_living(str) && in_editor(find_living(str))) str = 0;
  if(!str || !(ob=find_living(str)) || ob->query_invis() > this_player()->query_level()) {
    write("Usage: thwap <someone/monster>\n");
    return 1;
  }
  if(ob->query_level() > 20 && ob != find_player("wizardchild")
     && this_player()->query_level() < 21) {
    write("The only wizard you can thwap is Wizardchild.\n");
    return 1;
  }
  str = capitalize(str);
  if(environment(ob) != environment(this_player())) {
    write("You see "+str+" not too far off.\n");
    write("With your best throw, you chuck the rubber chicken at "+str+".\n");
    write(capitalize(ob->query_pronoun())+" is hit in the head!\n");
    tell_object(ob, "From nowhere, a rubber chicken flies in and nails you in the head!\n");
    say(this_player()->query_name()+" nails "+str+" in the head with a rubber chicken!\n");
    tell_room(environment(ob), str+" is hit in the head with a rubber chicken!\n");
    move_object(this_object(), ob);
  } else {
    write("You thwap "+str+" upside the head with your chicken!\n");
    tell_object(ob, this_player()->query_name()+" thwaps you upside the head with a rubber chicken!\n");
    say(this_player()->query_name()+" thwaps "+str+" upside the head with a rubber chicken!\n",ob);
  }
  return 1;
}
nuke(str) {
  if(!str || !id(str)) return 0;
  write("You whip out your rubber chicken, and with a flare of good taste, fling\n");
  write("it up into the sky, watching it disintegrate.\n");
  say(this_player()->query_name()+" nukes their rubber chicken.\n");
  chan_gossip("A rubber chicken disintegrates high in the sky.\n");
  destruct(this_object());
  return 1;
}
chan_gossip(str) {
  int i; object ob; ob = users();
  for(i = 0; i < sizeof(ob); i++) {
    if(ob[i]->on_channel("gossip")) tell_object(ob[i], str);
  }
}
fondle(str) {
  if(!id(str)) return 0;
  write("You fondle your rubber chicken. SICK!\n");
  say(this_player()->query_name()+" fondles a rubber chicken. NASTY!!!\n");
  return 1;
}
