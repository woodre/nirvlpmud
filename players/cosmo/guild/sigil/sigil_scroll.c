id(str) { return str=="paper" || str=="scroll" || str=="parchment"; }

short() { return "A scroll of invitation [SIGILS]"; }
long() {
  write("To join the Sigil guild type: sjoin <type> <location>\n");
  write("where <type> is fire, ice, or electricity,\n");
  write("and <location> is a body part.\n");
}

get(){ return 1; }    /* Can get */
drop(){ return 1; }   /* Can't drop */

init() {
  add_action("sjoin", "sjoin");
}

sjoin(str) {
int x;
string type, place;
object ob;
  if(!str) {
    notify_fail("Usage: sjoin <type> <location>\n");
    return 0;
  }
  if(sscanf(str,"%s %s",type,place) != 2) {
    notify_fail("Usage: sjoin <type> <location>\n");
    return 0;
  }
  ob = clone_object("/players/cosmo/guild/sigil/gob.c");
  ob->set_type(type);
  ob->set_location(place);
  move_object(ob, this_player());
  write("Sigil guild object creation complete.\n");
  destruct(this_object());
  return 1;
}

