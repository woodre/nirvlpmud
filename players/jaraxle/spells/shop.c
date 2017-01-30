/*  Here a guildless player can buy a sigil for 10k coins. They are prompted to
    whether or not they already have a sigil. If they do, and lie about it, they
    die from a magical overload.  The mage must be present in order to buy or
    ask anything.  This room is no fight also, mainly because of the input_to's
    i used.  I added a check to see if the mage is busy with helping someone
    already. Did this because the variables were getting mixed up with two ppl
    attempting to purchase at the same time.  This also checks for guilded. A
    log of who buys is sent to ~log/sigils. 
    Maledicta 01.24.00 */

/*  This idea and skeleton was given to my by Maledicta (Thanks man) I have
    taken it and rewrote about 90% of the stuff. But credit is given where
    credit is due.
    Jaraxle 04.04.01 */

#include "/players/jaraxle/define.h"

#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
object test;
int busy;
object owner;
string what;
object item;
string new_location;

reset(arg) {
if(!present("sigil_mage")){
        owner = clone_object("/players/jaraxle/spells/sigil_mage.c");
        move_object(owner, this_object());
        }

  if(arg) return;
set_light(1);
short_desc = "Enchanted Clearing";
long_desc =
"  This is a small hut. Several shelves line the wooden walls, each\n"+
"holding various components and jars. A series of books can be found\n"+
"along the back wall, behind a wooden counter. A curtain is all that\n"+
"separates the front and back rooms. A strong smell of spices and other\n"+
"more cloying scents invades your nostrils.\n"; 

items = ({
  "walls",
  "Made from wood, these walls seem very sturdy",
  "shelves",
  "Small wooden shelves that hold numerous items",
  "components",
  "Most likely these components are used for some type of magical ritual",
  "jars", 
  "Small and large jars that hold dead animals and creatures",
  "curtain",
  "A heavy red curtain that separates the front and back rooms",
  "books",
  "A large set of leather bound books. Each is carefully embroidered with\n"+
  "gold, with a large lock on its side",
  "counter",
  "A large wooden counter",
});

dest_dir = ({
  "/players/jaraxle/NONE.c", "out"
});
}

init(){
    ::init();   
  add_action("ask_it","ask");
   add_action("purchase_it","purchase");
  }

query_no_fight(){ return 1; }   
 
ask_it(str){
string who;
string what;
        if(!str){
                write("Ask who?\n");
                return 1;
        }
        if(!present("sigil_mage", this_object())){
          write("You don't see anyone here.\n");
          return 1;
          }
                if(sscanf(str, "%s about %s", who, what) == 2){
                        if(who == "mage" || who == "illkaunder"){
                                if(what == "sigils" || what == "sigil"){
write("The Mage Illkaunder turns to you and says,\n"+
          " 'The Sigils are an ancient power from long ago.  My life's research\n"+
          "  has been to recover them, and unravel their secrets. Having done so\n"+
          "  I can now recreate them, the original three.  For a price.  If you\n"+
          "  wish to know more about the three: fire, ice, and electricity, then\n"+
          "  ask me about them.  If you wish to know about purchasing, then ask.\n"+
          "  Later, I will continue searching for more sigils. But I believe the\n"+
          "  world needs to learn these first. I hear the others are much more\n"+
          "  powerful.'\n"+
          "The mage goes back to working on something.\n");
                        return 1;
                                }
                                if(what == "fire"){
write("The Mage says,\n"+
          " 'Yes, that one is my favorite.  It was also the first I discovered. A\n"+
          "  journey that led me to a once active volcano. The power of the fire\n"+
          "  sigil is derived from the plane of fire.  It uses your own bodies\n"+
          "  energies to feed and open this link.  Once the link is open you can\n"+
          "  hurl flame at your opponent, and later, once you have mastered its\n"+
          "  power, you can envelope your opponents in a destructive cone of fire.\n"+
      "  If you wish to purchase this sigil, simply 'purchase' it. It will\n"+
          "  only cost you 10,000 coins.'\n"+
          "Illkaunder arches an eyebrow and waits.\n");
      return 1;
                                }
                                if(what == "ice"){
write("The Mage says,\n"+
          " 'An interesting choice.  The ice sigil was the second one to be\n"+
          "  discovered.  I found it in a small cave, being guarded by a very\n"+
          "  large, and now quite dead, dragon.'\n"+
          "He stops to smile, then clears his throat to continue...\n"+
          " 'Anyway, the ice sigil is a direct link to the plane of ice. By\n"+
          "  invoking its power with your own magical energies you can open\n"+
          "  this link and call forth a destructive ice blast.  Later, once\n"+
          "  you master its power, you can focus this into a cone of frost\n"+
          "  which can envelop your enemies.  If you wish to purchase this\n"+
          "  sigil, simply 'purchase' it. It will only cost you 10,000 coins.'\n"+
      "Illkaunder sits down to wait.\n");
      return 1;
                                }
                if(what == "electricity"){
write("The Mage says,\n"+
          " 'Ahhh, yes, the Sigil of electricity.  This was the last of the\n"+
          "  sigils that I found, but an interesting one to be sure. I heard\n"+
          "  of this sigil from a dying man near Ryllian.  He told me of a\n"+
          "  palace in the clouds, one that held the secret of this little known\n"+
          "  sigil.  I traveled there, and fought terrible things, but came out\n"+
          "  with the knowledge of this powerful sigil.  The sigil of electricity\n"+
          "  harnesses the natural energies that flow around. When you invoke\n"+
          "  its power with your own energies, it gathers this up and delivers\n"+
          "  it in the form of a powerful charge.  Later, when you have mastered\n"+
          "  its power, you can focus this into a powerful cone of energy. If you\n"+
          "  wish to purchase this sigil, simply 'purchase' it. It will only\n"+
          "  cost you 10,000 coins.'\n"+
          "Illkaunder smiles and waits.\n");
      return 1;
                                }
                                if(what == "purchasing"){
write("The mage says,\n"+
          " 'All you have to do is 'purchase <fire, ice, or electricity>'.\n"+
          "  Remember though, the cost is 10,000 coins.'\n");
      return 1;
                                }
write("Ask mage about <what>?\n");
return 1;
                        }
write("Ask <who> about <what>?\n");
return 1;
                }
write("Ask <who> about <what>?\n");
return 1;
                }

purchase_it(string str){
        int purchase;
        purchase = str;

  if(tp->query_level() > 19){
  write("The mage smacks you and says, 'You're a wizard, just clone it.'\n"); 
 return 1; }
  if(tp->query_guild_name() && tp->query_guild_name() != 0){
  write("You are in a guild!\n"); 
 return 1; }
  if(tp->query_guild_rank()){
  write("You are in a guild!\n"); 
 return 1; }
  if(tp->query_guild_exp()){
  write("You are in a guild!\n");
  return 1; }
 
 if(!present("sigil_mage", this_object())){
        write("You don't see anyone here.\n");
        return 1;
        }
if(this_player()->query_level() < 5){
         write("The mage shakes his head and says, 'Your not high enough level.'\n");
         return 1;
 }
if(busy){ write("The mage says, 'Sorry, one person at a time.'\n");
          return 1;
          }
      busy = 1;
        if(!purchase){ write("Usage: purchase fire, ice, water or electricity.\n"); busy = 0; return 1; }
        if(purchase == "fire"){
          item = clone_object("/players/jaraxle/spells/fire_sigil.c");
          what = "Fire Sigil";
          }
        else if(purchase == "ice"){
          item = clone_object("/players/jaraxle/spells/wind_sigil.c");
          what = "Ice Sigil";
          }
        else if(purchase == "water"){
       item = clone_object("/players/jaraxle/spells/water_sigil.c");
          what = "Water Sigil";
}
        else if(purchase == "electricity"){
          item = clone_object("/players/jaraxle/spells/elec_sigil.c");
          what = "Electricity Sigil";
          }
        
       else{
          write("The Mage says, 'I'm sorry, I don't carry that sigil...yet.'\n");
          busy = 0;
        return 1;
        }       
        
 if (call_other(this_player(), "query_money", 0) < 10000) {
    write("The Mage says, 'I'm sorry, but you don't have enough for that.'\n");
    busy = 0;
    return 1;
     }          
 write("The Mage gets a very serious look on his face and asks,\n"+
           " 'Do you already have a sigil? I need to know.'\n"+
           "How do you answer? <y/n>?:");
 input_to("sigil_question");
 return 1;
}


sigil_question(str){
        if(!str){
                write("The mage looks at you strangely and says,\n"+
                          " 'You don't have to answer, but I can't sell to you unless you do.\n");

            busy = 0;
                return 1;
        }
        if(str == "y"){
                write("The Mage breathes a sigh of relief and says,\n"+
                          " 'I am glad you were honest with me. A person can have only\n"+
                          "  one sigil at a time. The conflict would have torn you apart.\n"+
                          "  You will have to remove the original to have it replaced.'\n");
            busy = 0;
                return 1;
        }
        if(str == "n"){
                
                write("The mage nods and continues...\n"+
                          "Now you need to decide where you want to have it. I can place\n"+
                          "it on your hand, chest, forehead, arm, or neck.\n"+
                          "Where would you like it?:");
                input_to("sigil_locale");
            return 1;
        }
        write("The mage says, 'I am sorry, I need a yes or no.'");
      busy = 0;
        return 1;
}

sigil_locale(str){
        if(!str){
                write("The mage says,\n"+
                          " 'I am sorry, I need to know where you want it.'\n");
         busy = 0;      
       return 1;
        }
if(str == "hand" || str == "forehead" || str == "chest" || str == "arm" ||
   str == "neck"){
new_location = str;
if(present("mal_sigil_new", this_player())){

/* Copied from Zeus' Code - Thanks BUDDY! */
        test = clone_object("/obj/monster.c");
        test->set_name(HIR+"I Lied"+NORM);
        tp->stop_fight();
     tp->stop_fight();
        tp->attacked_by(test);
        tp->add_hit_point(-350);
                        write(""+HIY+"The mage nods and begins placing the sigil on your body. There\n"+
                                  "is a sudden spark of magic and you feel your body suddenly torn\n"+
                                  "apart! You disappear into a blast of incinerating magic!\n"+
                                  "You suddenly realize as you die that maybe you shouldn't have lied\n"+
                                  "about not having a sigil already."+NORM+"\n");
                  this_player()->hit_player(20000);
                      busy = 0;
                return 1;
                }
        write("The mage nods and says,\n"+
                  " 'Very well, the "+str+" it is.'\n\n"+
                  "He then sits down to work with a needle and some glowing ink, he\n"+
                  "begins to imprint the sigil into your "+str+". After about an hour\n"+
                  "the sigil is done. He then opens a book and begins to chant. A soft\n"+
                  "glow envelops the sigil.  He is done.\n\n"+
          "The mage says,\n"+
                  " 'Please look at it, there you will find answers to your questions.'\n");
 busy = 0;
 write("You pay the mage 10000 coins.\n");
 say(tp->query_name() + " purchases a sigil.\n");
 item->set_slocale(new_location);
 move_object(item,this_player());
 tp->add_money(-10000);
  write_file("/players/jaraxle/spells/log/sigils",
  ctime(time())+"  "+HIR+this_player()->query_real_name()+NORM+" Bought "+what+" LOC: "+new_location+".\n");  
return 1; 
}
 write("The mage says, 'I am sorry, where?'\n");
busy = 0; 
return 1;
}   

