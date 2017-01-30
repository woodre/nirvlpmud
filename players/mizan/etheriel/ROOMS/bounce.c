inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tPelted by a fungling array of soft, squishy objects, only\n"+
"  after the barrage ends can you open your eyes. To your utter surprise\n"+
"  and bewilderment, you open your eyes to a room full of BEANOS!\n"+
"  However.... These Beanos seem to be off-limits. They are protected\n"+
"  by none other than the Toughest Man in the World, Mr. T.\n";
}

extra_reset() 
{

   object_names = ({
    "players/mizan/etheriel/beasties/mr_t/beano.c",
    "players/mizan/etheriel/beasties/mr_t/beano.c",
    "players/mizan/etheriel/beasties/mr_t/beano.c",
    "players/mizan/etheriel/beasties/mr_t/beano.c",
    "players/mizan/etheriel/beasties/mr_t/beano.c",
    "players/mizan/etheriel/beasties/mr_t/mr_t.c"
   });

  ::extra_reset();

  if(1==random(1000)) 
  {
     move_object(clone_object("players/mizan/etheriel/heals/neutromuck.c"), this_object());
  }
}
