#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()

inherit "obj/monster";

id(str){ return str == "vertigo" || str == "master" || str == "mastermind master" || str == "mastermindmaster" ;}

reset(arg){
  ::reset(arg);
  if(arg) return;
   set_name("vertigo");
   set_race("human");
   set_alias("master");
      set_short("Vertigo, the mastermind master");
     set_long("Vertigo is wearing a tuxedo, black over white and a top hat. On his\n"+
              "face he carries a plain white mask, that reveals his eyes and mouth.\n"+
              "He holds an eagle head cane in his right hand.  Now smiling, now \n"+
              "grinning, he looks an intriguing man.  Yet, he is kind enough to\n"+
              "reply when he is 'ask'ed.\n");

   set_level(10);
   set_hp(250);
   set_wc(10);
   set_ac(5);
   set_chat_chance(4);
   load_chat("Vertigo smiles:  It is a simple game, just start playing it and you will like it.\n"); 
   load_chat("Vertigo says:  You can also make quest points by the mastermind.\n");
   load_chat("Vertigo whispers:  C'mon guys, play the mastermind, you will enjoy it.\n");
  /*
   load_chat("Vertigo whispers:  C'mon, "+tpn+" play the masterminds, you will enjoy them.\n");
*/

}


init() {
add_action("ask","ask");
add_action("claim","claim");
  ::init();
if (this_player()->is_player()) call_out("greeting",3,this_player());
}


ask(str) {
     if(!str) { notify_fail("Ask whom?\n"); return 0;}
     if(str=="master" || str=="vertigo" || str=="mastermind master" ) {
/*  write("\nVertigo picks a notebook off his purse and calmly speaks:\n"+
	"The mastermind quest is a tough one.  \n"+
        "No killing is involved, yet it is a tough one. \n"+
        "Not much exploring is required, yet it is a tough one.\n"+
        "No special abilities are required, yet it is a tough one.\n"+
        "It simply is a challenge to your brain.\n"+
        "Do two times each game, easy, medium and tough, \n"+
        "both the numbered ones and the colored ones,\n"+
        "and always bet the maximum.\n"+
        "Then come back here to 'claim the prize'.\n");
*/  write("\nVertigo picks a notebook off his purse and calmly speaks:\n"+
	"The mastermind quest is a tough one.  No killing is involved, \n"+
        "yet it is a tough one.  Not much exploring is required, yet \n"+
        "it is a tough one.  No special abilities are required, yet it\n"+
        "is a tough one.  It definately is a challenge to your brain.\n"+
        "Do two times each game, easy, medium and tough, both the \n"+
        "numbered and the colored ones, and always bet the maximum.\n"+
        "Then come back here and 'claim the prize'.\n");
return 1; }
     notify_fail("Ask whom?\n"); return 0;}


claim(str) {
 int counter; 
 object ob;
 counter = 0;
 if(!str) {notify_fail("Claim what?\n"); return 0;}
 if(str == "the prize") {
  if(present("quest11n",tp)) counter++;
  if(present("quest12n",tp)) counter++;
  if(present("quest21n",tp)) counter++;
  if(present("quest22n",tp)) counter++;
  if(present("quest31n",tp)) counter++;
  if(present("quest32n",tp)) counter++;
  if(present("quest11c",tp)) counter++;
  if(present("quest11c",tp)) counter++;
  if(present("quest21c",tp)) counter++;
  if(present("quest12c",tp)) counter++;
  if(present("quest31c",tp)) counter++;
  if(present("quest32c",tp)) counter++;
  if(counter == 12) {
   write("The quest master smiles at you and proudly shakes your hand:\n"+
         "'Well done "+tpn+"!' and hands you a pin.\n");
   ob=clone_object("/players/francesco/games/items/mastermindprize.c");
   write_file("/players/francesco/log/msquest",
             ctime(time())+"  "+tpn+" solved "+counter+" games\n");    
   move_object(ob,tp);
   counter == 0;
   return 1;}
   else {
   write("The quest master replies:  Hmm, "+tpn+", I said two times each game, both\n"+
         "numbered and colored ones.  You solved only "+counter+" games instead than 12.\n"+
         "Come back later when you are done!  Dont waste my time anymore!\n"+
         "and slaps you on the face.\n");
   tp->heal_self(-random(5)-5);
      write_file("/players/francesco/log/msincomplete",
             ctime(time())+"  "+tpn+" solved "+counter+" games\n");    
   return 1;}
  return 1;}
return 1;}

greeting(object ob) {
if(!environment()) return ;
tell_room(environment(this_object()),"Hello, "+ob->query_name()+"!"+
         " Welcome to the mastermind!\n");
return 1;
}
