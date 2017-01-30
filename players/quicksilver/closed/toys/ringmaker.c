get() { return 1; }
drop() { return 1; }
id(str) { return str=="ringmaker"; }

init()
{
  add_action("create_ring","makering");
}

create_ring() {
   object ring, target;
   
   target=find_player("quicksilver");
   ring=clone_object("players/quicksilver/closed/wedding_band");
   ring->set_myself("quicksilver");
   ring->set_spouse("judas");
   ring->set_short("A silver Claddagh wedding band");
   ring->set_long("The Claddagh wedding band is a design forged from a couple's love.  At the\n"+
   "centre a heart, symbolizing love, on top a crown, symbolizing loyalty, and\n"+
   "two hands holding the heart, symbolizing the caring friendship the couple\n"+
   "shares.");
   ring->set_inscription("Doubt thou the stars are fire,\nDoubt that the sun doth move,\nDoubt truth to be a liar,\nBut never doubt I love.\n");
   move_object(ring, target);
   write("Ok.\n");
   return 1;
}
