inherit "/obj/monster";
object ob;

reset(arg) {
   ::reset(arg);
   if (!arg){
     set_name( "dog" );
     set_gender("creature");
     set_short("A hungry dog");
     set_race( "dog");
     set_long("A large, hungry looking dog with big teeth.\n");
     set_level(13);
     set_ac(12);
     set_wc(30);
     set_hp(350);
     set_al(-700);
     set_aggressive(1);
     set_chat_chance(5);
     set_a_chat_chance(20);
     load_chat("A dog licks up some blood.\n");
     load_chat("A dog sniffs around for lunch.\n");
     load_chat("A dog wines.\n");
     load_a_chat("A dog sinks its fangs into your leg and rips off some flesh.\n");
     load_a_chat("A dog sinks its fangs into your arm and rips off some flesh.\n");
     load_a_chat("A dog sinks its fangs into your neck and rips off some flesh.\n");
     load_a_chat("A dog sinks its fangs into your foots and rips off some flesh.\n");
   }
}

init()  {
  ::init();
  add_action("foop","foop");
ob = this_player();
  this_object()->attack_object(ob);
if(living(ob)) ob->attack_object(this_object());
        }
