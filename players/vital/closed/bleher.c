/* i hate cheaters */

#include <ansi.h>

id(str) { return (str == "autojailor" || str == "make_war"); }

reset(x) { if(!x && !root()) call_out("tell_story", 15 + random(15)); }

drop() { return 1; }

tell_story() {
   object x, player;
   string msg;
   if((player = find_player("fastkill")) || (player = find_player("silentkill"))) {
     if((x = environment())) {
        switch(random(6)) {
          case 0: msg = "There is one simple rule, if you have more than one character they MUST be TOTALLY SEPARATE.\n"; player->set_title("\[multiplayer\]"); break;
          case 1: msg = "Sharing of equipment, money, and anything else is NOT allowed.\n"; player->set_title("has violated the rules for multiplaying"); break;
          case 2: msg = "Leaving behind money or objects for a second to pick up or to pass money through a third player, pet or monster is not legal and will be considered multiplaying.\n"; player->set_title("is being haunted for failing to follow the rules"); break;
          case 3: msg = "The honest player should be offended by such behavior.\n"; player->set_title("should know better than to cheat"); break;
          case 4: msg = "You might want to consider taking a look at \'help multiple\'\n"; player->set_title("is inconsiderate of other honest, hardworking mudders"); break;
          case 5: msg = "I sure hope a wiz isn\'t watching.\n"; player->set_title("has been branded "+HIM+"\[multiplayer\]"+NORM); break;
        }
     }
     tell_object(player,msg);
     write_file("/players/vital/logs/remind.log",ctime(time())+" told "+player->query_real_name()+" "+msg+"\n");
     if(player->query_hps() >= 20) player->add_hp(-6+random(6));
     remove_call_out("tell_story");
     call_out("tell_story", 30 + random(120));
   }
   remove_call_out("tell_story");
   call_out("tell_story", 600);
}
