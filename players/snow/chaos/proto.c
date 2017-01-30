/* PROTOTYPE OF CHAOS ROOM */

inherit "players/snow/chaos/arch.c";

reset(arg) {
  ::reset();

  if(!arg) {
  set_short("ChAoS Prototype");
  set_long("This is the ChAoS Prototype room. Here we see if everything\n"+
           "is working A-OK. Type 'chaos' for commands.\n");
  items=({
    "swing","This is a swing",
    "chair","This is a chair",
      });
  }
}
