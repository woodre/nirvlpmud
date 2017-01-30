#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#define SYMB present("venom_object", tp)
inherit "room/room";
int allow_challenge;

reset(arg) {
if(!present("black ball", this_object())){
move_object(clone_object("/players/maledicta/venom/OBJ/ball.c"), this_object());
}
  if(arg) return;
set_light(1);

long_desc = 
BOLD+"  You find yourself standing in a room made of dark matter.  The walls\n"+
"glisten in the dim light.  A small blackish pool stands in the center\n"+
"of the room."+NORM+"\n";

items = ({
"pool",
"You concentrate on the pool and find that you may do any of the\n"+
"following:\n"+
/* "   renew_symbiote   -  Get a new symbiote object. Use this to update\n"+
"                       or if you have lost your object.\n"+ */
"   news             -  Use this command to see any news on the guild.\n"+
"   store_coins      -  Store coins in the pool of matter",
"walls",
"They are made of a rock hard glistening substance. You aren't sure\n"+
"exactly what it is",
});


dest_dir = ({
  "/players/maledicta/castle/rooms/m3.c","out",
});

}

short(){ return ""+BOLD+"Dark Matter"+NORM+""; }

init(){
::init();
add_action("renew_object", "renew_symbiote");
add_action("news_stuff", "news");
add_action("challenge", "challenge");
add_action("open_challenge", "open");
}

open_challenge(str){
 if(!present("new_venom_object", this_player())){
    return 0;
    }
 
 if(!str){
    write("Open what?\n");
    return 1; 
    }
 if(str == "crack"){  
   if(allow_challenge){ write("It is already open!\n"); return 1; } 
   write("You pry open the "+BOLD+"Dark Matter"+NORM+" wall...\n"+
          "A large crack forms allowing entrance for just one person.\n"+
          "Your chosen one may now 'challenge symbiote'.\n");
    say(this_player()->query_name()+" grips the "+BOLD+"Dark Matter"+NORM+" wall tightly and tears it open...\n");
    allow_challenge = 1;
    call_out("blahblah", 60);
    return 1;
    }
 write("open what?\n");
 return 1;
 }


blahblah(){
 if(!allow_challenge) return;
 else{
  allow_challenge = 0;
  tell_room(this_object(), "The walls breach closes...\n");
  }
}



challenge(str){
 object arena;
 object mob;
 string named;
 if(!allow_challenge) return 0;
 if(!present("venom_object_chal", tp)) return 0;
 if(tp->query_level() < 19 && tp->query_extra_level() < 8) return 0;
 if(!str){ write("You must 'challenge symbiote'.\n"); return 1; }
 if(str != "symbiote"){ write("You must 'challenge symbiote'.\n"); return 1; }
 if(SYMB->query_changed()){ write("You cannot challenge your symbiote while changed!\n"); return 1; }
 write_file("/players/maledicta/log/challenged!",
 this_player()->query_real_name()+" challenged symbiote on "+ctime(time())+".\n");
 named = SYMB->query_symbiote();

 mob = clone_object("/players/maledicta/venom2/OBJ/symbiote_mob.c");
 mob->set_symb_name(named);
 mob->set_challenger(tp);
 mob->set_saved_money(SYMB->query_stored_coins());

 arena = clone_object("/players/maledicta/venom2/OBJ/challenge_room.c");
 arena->set_who(tp);
 
 move_object(tp, arena);
 move_object(mob, arena);
 tell_object(tp, 
 "\n\n\n"+HIR+"As you are pulled into the pool of Dark Matter, you feel as though you are\n"+
 "torn in half!"+NORM+"\n\n\n"); 
 tp->hit_player(100 + random(50)); 
tp->shadow_symboff();
 command("look", tp);
 tell_object(tp,
 HIR+"Your symbiote is pulled from your body and forms up before you..."+NORM+"\n\n");
 tell_object(tp,
 BOLD+capitalize(named)+" hisses: Traitor! I will destroy you!"+NORM+"\n");
this_player()->set_guild_name(0);
 destruct(SYMB);
 allow_challenge = 0;
 remove_call_out("blahblah");
 return 1;
 }


renew_object(str){
if(tp->query_guild_name() != "symbiote") return 0;
if(!present("venom_object", tp)){
move_object(clone_object("/players/maledicta/venom/venom.c"), tp);
write("Your lost object has been restored...\n");
return 1;
}
else{
if(present("venom_object", tp)->query_venomed()){
write("You must return to normal shape first!\n");
return 1;
}
command("ssave", tp);
call_other(this_player(), "stop_wearing", present("venom_object", tp), "mine", 1);
destruct(present("venom_object", tp));
move_object(clone_object("/players/maledicta/venom/venom.c"), tp);
write("Object updated...\n");
return 1;
}
return 1;
}
realm() { return "NT"; }

news_stuff(){
if(tp->query_guild_name() != "symbiote") return 0;
cat("/players/maledicta/venom/news");
return 1;
}
no_hunter(){ return 1; }
