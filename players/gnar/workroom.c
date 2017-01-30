inherit "room/room";

init() {
::init();
  if( this_player() )
    move_object( this_player(), "/players/dragnar/workroom" );
}

reset(arg) {
  if(arg) return;
  short_desc=("A Dune Cave");
  long_desc=
    "       You stand at the mouth of a cliff overlooking the planet\n"+
    "Arrakis.  The sun is setting on the horizon of the desert that\n"+
    "stretches out in front of you.  Although the climate of Dune is harsh,\n"+
    "it seems almost peaceful and beautiful now.  Still, you are\n"+
    "thankful for the safety of the cave behind you because you know what is\n"+
    "to come.  As you think of the death and bloodshed that is about to\n"+
    "begin, you whisper words that comfort your fears:\n"+
    "       'I must not fear.  Fear is the mind-killer.\n"+
    "       Fear is the little death that brings total obliteration.\n"+
    "       I will face my fear.  I will permit it to pass over me\n"+
    "       and through me.  And when fear has gone past I will turn to\n"+
    "       look at fears path. Where fear has gone there will be nothing.\n"+
    "       Only I will remain.'\n",
  items=
    ({
    });
  dest_dir=({
  });
}
