#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
if(!present("tuyen"))  {
move_object(clone_object("/players/saber/closed/bards/tuyen.c"),this_object());
       }
 if(!arg){
  set_light(1);
short_desc="Bard Lore Chamber";
long_desc=
 "The Lore and Equipment room is a pleasant chamber filled with shelf upon shelf\n"+
 "of scrolls and books.  In the eastern corner sits Tuyen, Song Keeper of the\n"+
 "Bards.  The western wall is covered with maps of both Ryllian and Nirvana.  In\n"+
 "the center of the room is a large leather bound book.\n"+
 "Commands: maps, books and scrolls.\n";

items=({
 "floor","The floor is made from a beautiful mahogany wood",
 "room","You are in the Lore and Equipment chamber",
 "chamber","You are in the Lore and Equipment chamber",
 "scrolls","The room is filled with shelf upon shelf of scrolls.\n"+
    "Type <scrolls> for a list",
 "scroll","The room is filled with shelf upon shelf of scrolls.\n"+
    "Type <scrolls> for a list",
 "book","A large leather bound book filled with the lore of the city of Ryllian",
 "books","The room is filled with sheld upon shelf of books.\n"+
    "Type <books> for a list",
 "maps","The west wall is covered with maps.  Type <maps> for help",
 "map","The western wall is covered with maps.  Type <maps> for help",
 });

  dest_dir=({
 "/players/saber/closed/bards/bardrooms/advance.c","north",
 "/players/saber/closed/bards/bardrooms/common.c","east",
           });
  }   }
init(){
 ::init();
if(!present("instrument",this_player()) &&
   this_player()->is_player())  {
  write("You get the brief image of a blue circle before\n"+
     "\n"+
    " * * * * *  B O O M  * * * * *\n"+
    "\nYour body flies through space.\nYou find yourself somewhere new.\n");
  say(tp+" bounces off the Circle of Warding.\n");
  move_object(this_player(),"/room/void");
  tell_room(environment(this_player()), tp+" falls screaming from the sky.\n"+
      "THUD.\n");
  return 1;
        }
  add_action("search","search");
   add_action("maps","maps");
   add_action("scrolls","scrolls");
   add_action("books","books");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }

books()  {
  write("Books to come later.              -- Saber.\n");
  return 1;
        }

maps(str)  {
  if(!str)  {
  write("List of maps:\n"+
  "1)  Map of Ryllian.\n"+
  "\nType <maps> <#> to get a map.\n");
  return 1;
        }
  if(str == "1")  {
  move_object(clone_object("players/saber/stuff/flier.c"),this_player());
  write("You take a map.\n");
  say(tp+" takes a map from the shelf.\n");
  return 1;
        }
  write("There is no map by that name.\n");
  say(tp+" searches the shelf.\n");
  return 1;
        }

scrolls(str)  {
  if(!str)  {
  write("List of scrolls:\n"+
  "1 - 8 (bard trials)\n"+
  "10)  Bard trial hints.\n"+
  "11)  Mini Guild Scroll.\n"+
  "\nType <scrolls> <#> to get a scroll.\n");
  return 1;
        }
  if(str == "11")  {
  move_object(clone_object("/players/saber/closed/new_mini/scroll.c"),this_player());
  write("You take a scroll.\n");
  say(tp+" takes a scroll.\n");
  return 1;
        }
  if(str == "1")  {
  say(tp+" reads a scroll.\n");
  write(
 "Bard Trial One:\n"+
 "\nFind Johnathin de Oro downstairs and ask about <bard task 1>.\n\n");
  return 1;
        }
  if(str == "2")  {
  say(tp+" reads a scroll.\n");
  write(
 "Bard Trial Two:\n\n"+
 "Go to the Library of Ryllian (check a map if you need to) and\n"+
 "search for the root of your instrumental magical powers.\n\n");
  return 1;
        }
  if(str == "3")  {
  say(tp+" reads a scroll.\n");
  write(
 "Bard Trial Three:\n\n"+
 "Summon the ghost of Selsase.  She will test your bardic abilities.\n"+
 "BE WARNED: this bard trial can be fatal.  Be sure that you know\n"+
 "all of the lore found within the library and be aware of all your\n"+
 "bardic powers before you attempt to advance.\n"+
 "\nTo summon the ghost of Selsase, you will need a sapphire.\n"+
 "She will only respond to a summoning played upon a Violin.\n"+
 "Go to the clearing north of the rift in the mountains and\n"+
 " <summon selsase> to find the ghost.  <begin> when you are ready.\n"+
 "Be prepaired.\n\n");
  return 1;
        }
  if(str == "4")  {
  say(tp+" reads a scroll.\n");
  write(
 "Bard Trial Four:\n\n"+
 "Find the gypsy camp in the green valley.\n");
  write("Type <begin> when you do\n");
  return 1;
        }
  if(str == "5")  {
  say(tp+" reads a scroll.\n");
  write(
  "Bard Trial Five:\n\n"+
  "Go to the Valley of Rock (in the Spine of the Moon) and\n"+
  "cause the stones do dance and cry.  You may need to\n"+
  "<shout> to begin your trial.\n\n");
  return 1;
        }
  if(str == "7")  {
  say(tp+" reads a scroll.\n");
  write(
  "Bard Trial Seven:\n\n"+
  "Collect the following:\n"+
  "The fruit of a clam.\n"+
  "Bottled ghosts.\n"+
  "A silver gypsy medallion.\n"+
  "A stone of blood.\n"+
  "\nTake these materials to Johnathin de Oro and ask <scroll> for a scroll.\n"+
  "Read the scroll to visit the faerie court where you will be tested.\n\n");
  write("Type <begin> to start.\n");
  return 1;
        }
  if(str == "6")  {
  say(tp+" reads a scroll.\n");
  write(
  "\nBard Trial Six:\n\n"+
  "Find the Ebony Orb and give it to Star.\n"+
  "The Orb can be found within the realm of dreams, in Asgard.\n"+
  "(Check the well north of the post office).\n\n"+
  "Look for Loki.\n\n");
  return 1;
        }
  if(str == "8")  {
  say(tp+" reads a scroll.\n");
  write(
  "\nBard Trial Eight:\n\n"+
  "Play a tune for Saber.\n\n"+
  "In the common room of Orin's Inn is a door leading south.\n"+
  "To go south, <translate> the <elvish> on the door.\n\n");
  write("Type <begin> to start.\n");
  return 1;
        }
  if(str == "10")  {
  say(tp+" reads a scroll.\n");
  write(
  "\nHints on Bardic Trials...\n\n"+
  "K.I.S.S (keep it simple stupid) - try the simple stuff first, THAN\n"+
  "  get complex.  Most stuff isn't THAT hard.\n\n"+
  "Know your abilities.  Bard Trials are there to make sure that bards\n"+
  "  are aware of what powers they possess.\n\n"+
  "If a Bardic trial doesn't start when you think it should, type 'begin'\n"+
  "\nMake sure that you're in the right place.\n\n"+
  "Check the 'exact' wording of what is asked of you.\n\n"+
  "For some reason, the bard speach ; works better than the say ' for trials.\n\n"+
  "Be sure to use lower case when answering questions.\n\n"+
  "If you are VERY confused, ask for a clue.  Don't ask for help,\n"+
  "  because you don't want to get other bards in trouble...\n\n");
  return 1;
        }
  write("There is no scroll by that name.\n");
  say(tp+" searches the shelf.\n");
  return 1;
        }

realm()  { return "NT"; }
