inherit "obj/treasure";
reset(arg) {
  if(arg) return;
    set_id("stone");
    set_alias("rubble");
    set_short("A chunk of rubble");
    set_long("A chunk of stone.\n"+
             "Perhaps it comes from the ruins of some\n"+
             "legendary city or monument.  Maybe from the\n"+
             "Mystic City of Luxor itself or the High Cronis\n"+
             "Pyramids that are rumoured to be found in the\n"+
             "desolate sands of the Sylan Desert.\n");
    set_weight(10 + random(30));
    set_value(1 + random(10));
}
