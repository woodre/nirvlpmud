#define tp this_player()->query_name()
#define TP this_player()

inherit "/obj/monster";

int n, count;
object ob, ob2;

reset(arg) {

ob = clone_object("/players/saber/stuff/cards.c");
move_object(ob,this_object());

   ::reset(arg);
   
if (!arg){

     set_name("star");
     set_short("Star the Occult and Lore Mistress (white lord)");
     set_alias("girl");
     set_race("human");
     set_gender("female");
     set_long(
       "Star is the Occult and Lore Mistress of the Bards.\n"+
       "She is a young woman of perhaps fourteen, with deep blue eyes and and silky\n"+
       "blond hair falling down about her shoulders.  Star is wearing black nickers\n"+
       "and a loose white blouse with silver trim.  She is unbelievably cute.\n");
     set_level(20);
     set_ac(30);
     set_wc(30);
     set_hp(500);
     set_al(900);
     set_aggressive(0);
     set_chat_chance(3);
     set_a_chat_chance(20);
     load_chat("Star shuffles her cards.\n");
     load_chat("Star looks up at you and smiles.\n");
     load_chat("Star asks \"\Have you seen Christopher?\"\n");
     load_chat("Star deals out the cards and observes their positions.\n");
     load_chat("Star says \"\I wish I hadn't died so many times...\"\n");
     load_chat("Star deals out the cards, observes them and nods to herself.\n");
     load_chat("Star looks up at you and winks.\n");
     load_chat("Star splashes you with some water from the translucent crystal pool.\n");
     load_chat("Star dangles her feet in the translucent crystal water.\n");
     load_chat("Star looks into the pool of translucent crystal water.\n");
     load_chat("Star strips of her clothing and goes for a brief dip in the pool.\n");
     load_chat("Star sips some translucent crystal water from the pool.\n");
     load_chat("Star concentrates on the floating blue crystal.\n");
     load_a_chat("Star dodges the attack.\n");
     load_a_chat("Star traces mystic symbols in the air.\n");
     load_a_chat("Star blasts her foe with magical fire.\n");
     load_a_chat("Star nimbly dodges the blow.\n");
     load_a_chat("Star whispers mystic soundind whispers.\n");
     set_chance(25);
     set_spell_dam(75);
     set_spell_mess1("Star whispers the TRUE NAME of her foe.");
     set_spell_mess2("Star whispers your true name!\n"+
                     "You feel a dark chill through your soul.");

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
  if(who == "star" || who == "Star")  return;
   say("Star hugs "+who+".\n");
    }  
    }


hi_there(str) {
string who;
if(sscanf(str, "%s arrives.", who) == 1)  {
  say("Star smiles at "+who+".\n");
    }  
    }
    

init()  {
  ::init();
   add_action("ask_question","ask");
   if(this_player()->query_real_name() == "mythos")  { call_out("mythos_talk",4); }
        }



ask_question(str)  {

  if(!str)  {
    write("Star says \"\You must ask for part 1, 2, 3, 4, or 5 of my tale.\"\n");
    return 1;
        }
   
   if(str == "1")  {
     cat("/players/saber/closed/bards/star/star1");
     return 1;
        }
   if(str == "2")  {
     cat("/players/saber/closed/bards/star/star2");
     return 1;
        }
   if(str == "3")  {
     cat("/players/saber/closed/bards/star/star3");
     return 1;
        }
   if(str == "4")  {
     cat("/players/saber/closed/bards/star/star4");
     return 1;
        }
   if(str == "5")  {
     cat("/players/saber/closed/bards/star/star5");
     return 1;
        }

   write("Star says \"\You must ask for part 1, 2, 3, 4, or 5 of my tale.\"\n");
   return 1;
        }
  
  
mythos_talk()  {
  tell_room(environment(this_object()),
   "\nStar whispers \"\Mythos, I charge you to bear a message to my father.\"\n");
   call_out("mythos_talk2",4);
   return 1;
        }
        
mythos_talk2()  {
  tell_room(environment(this_object()),
   "\nStar whispers \"\Tell him that I still love him,\"\n");
   call_out("mythos_talk3",4);
   return 1;
        }
        
mythos_talk3()  {
  tell_room(environment(this_object()),
   "\nStar whispers \"\And that I hope he will one day have the wisdom to renounce\"\n"+
   "                  \"\this situation which he has put himself into.\"\n");
   call_out("mythos_talk4",4);
   return 1;
        }
        
mythos_talk4()  {
  tell_room(environment(this_object()),
   "\nStar whispers \"\Mythos, tell my father to give up this darkness and come home.\"\n");
   return 1;
        }
