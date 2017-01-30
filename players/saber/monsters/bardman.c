inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
if (!arg){
     set_name("silus");
     set_short("A swashbuckler bard");
     set_alt_name("bard");
     set_alias("cool one");
     set_race( "human");
     set_gender("male");
   set_long("A swashbucklin young bard named Silus Twetch.\n"+
       "He can tell you about some really cool stuff.\n"+
       "Type: <bard> to get info on the bardic guild and\n"+
       "    : <mini> to get info on the mini guilds.\n\n");
     set_level(16);
     set_ac(13);
     set_wc(22);
     set_hp(425);
     set_al(800);
     set_aggressive(0);
     set_chat_chance(8);
   set_a_chat_chance(15);
     load_chat("Silus says 'Join the Bards, see the world!'\n");
     load_chat("Silus says 'Join a mini guild!\n");
     load_chat("Silus sings part of an irish jig.\n");
     load_chat("Silus says 'Have you seen Briana Ryan?'\n");
     load_chat("Silus hums part of 'Hay Nonny Nonny.'\n");
     load_a_chat("Silus screams 'You fool.'\n");
     load_a_chat("Silus punches his foe in the face.\n");
     load_a_chat("Silus kicks his opponent in the solar plex.\n");

     set_object(this_object());
     set_function("hi_there");
     set_type("arrives");
   }

}
notify(str)  {
  say(str);
}
hi_there(str) {
string who;
if(sscanf(str, "%s arrives.", who) == 1)  {
  notify("Silus says: Hello "+who+".\n");
  notify("Silus smiles at "+who+".\n");
}  }

init()  {
  ::init();
  add_action("bard_stuff","bard");
   add_action("mini_stuff","mini");
        }
/*  added code to both functions so only 1 of each could be gotten
    as they were being abused.  7/10/99  -Eurale  */

bard_stuff()  {
object BARD;
if(present("tome",this_player())) {
  write("Silus says, 'You already have a tome.\n");
  return 1; }
  BARD = clone_object("/players/saber/closed/bards/bard_help.c");
  move_object(BARD,this_player());
say("Silus hands "+this_player()->query_name()+" a tome.\n");
  return 1;
        }

mini_stuff()  {
object MINI;
if(present("scroll",this_player())) {
  write("Silus says, 'You already have a scroll.'\n");
  return 1; }
  MINI = clone_object("/players/saber/mini/mini.c");
  move_object(MINI,this_player());
say("Silus hands "+this_player()->query_name()+" a scroll.\n");
  return 1;
        }
