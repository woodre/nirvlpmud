inherit "/obj/monster";

#define tp this_player()->query_name()
object ob;

reset(arg) {
ob = clone_object("/players/nooneelse/obj/rose.c");
move_object(ob,this_object());
   ::reset(arg);
if (!arg){
   set_name("girl");
   set_short("A young girl selling flowers");
   set_alias("flower girl");
   set_race( "vampire");
   set_gender("female");
   set_long("A young waif of a girl dressed all in black.  She has pale\n"+
        "skin, dirty blond hair and devastating blue eyes.  The girl \n"+
        "is carrying a large bouquet of individually wrapped long-\n"+
        "stemmed roses.  If you <ask>, she might sell you one.\n");
   set_level(5);
   set_ac(9);
   set_wc(9);
   set_hp(150);
   set_al(0);
   set_aggressive(0);
   set_chat_chance(10);
   set_a_chat_chance(12);
   load_chat("The young girl hums part of an old irish tune.\n");
   load_chat("The young girl says: Hay, wanna buy a flower?\n");
   load_chat("The girl brushes a lock of hair from away from her eyes.\n");
   load_chat("The young girl says: Would you like to buy a flower?\n");
   load_chat("The young girl looks around a shivers.\n");
   load_chat("The young girl says: I knew them all...\n");
   load_a_chat("The young girl screams in terror!\n");
   load_a_chat("The young girl cowers in fear.\n");

   set_object(this_object());
   set_function("hugs");
   set_type("hug");
   set_match("");
   set_function("hi_there");
   set_type("arrives");
   set_match("");
   }

}

hugs(str)  {
  string who;
  if(sscanf(str, "%s hugs", who) == 1) {
  if(who == "girl" || who == "Girl")
  return;
 say("The young girl hugs "+who+".\n");
}   }

hi_there(str) {
string who;
if(sscanf(str, "%s arrives.", who) == 1)  {
  say("The young girl nods solemnly at "+who+".\n");
  say("The young girl whispers \"\Hello "+who+"\".\n");
}  }

init()  {
  add_action("ask_for_flower","ask");
        }

ask_for_flower()  {
int cash;
object flower;

  if(this_player()->query_money() < 50) 
    { cash = 0; } else { cash = 50; }

  flower = clone_object("/players/nooneelse/obj/rose.c");
  call_other(this_player(), "add_money", -cash);

  say(tp+" gives the girl a golden coin.\n"+
      "The young girl gives "+tp+" a long stemmed rose.\n");

  move_object(flower, this_player());

  return 1;
        }
