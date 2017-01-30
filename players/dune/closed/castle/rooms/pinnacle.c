inherit "room/room";


init()
{
  ::init();
}


reset(arg)
{
  if(!present("Omni"))
  {
    move_object(clone_object("/players/dune/closed/castle/monsters/omni.c"),
    this_object());
  }

  if(!arg)
  {
    set_light(1);
    short_desc="Pinnacle of Elemental Tower";
    long_desc=
"             (         )    \n"+
"                (   )      \n"+
"          - -- ---*--- -- -\n"+
"               (  _  )    \n"+
"             (   | |   ) \n"+
"                 | |       \n"+
"                 | |       \n"+
"                 | |        \n"+
"     This is the pinnacle of Elemental Tower.\n"+
"The stairs end in a large observation deck.\n"+
"The floor is sparkling red. Tiny jewel dust\n"+
"lies everywhere. Shooting rays of magical\n"+
"ether arc from the air around the deck.\n"+
"A ribbon of churning energy shoots upward into\n"+
"the clouds above.\n";

    items=({
"flame",  "Columns of swirling flame reach at the heavens",
"columns","The columns surround a fiery walkway",
"clouds", "The clouds churn violently",
"winds",  "The winds blast a walkway that leads into it",
"walkway","Four walkways exist, all lead in the four directions",
"waters", "What sort of horrible creature could swim in those depths",
"tunnel", "The tunnel descends in black depths",
"dirt",   "The dirt is black and moist",
"clay",   "The clay is red and soft",
"ribbon", "A ribbon of energy swirls in the sky",
    });

    dest_dir=({
"/players/dune/room/center.c","down",
    });
  }
}


nospell()
{
  write("The energy ribbon disrupts your spell!\n");
  return 1;
}


/*
 This seems unnecessarily annoying given the difficulty of the monster.
 -Feldegast 10-24-00
query_NM() { return 1; }
*/


realm() { return "NT"; }
