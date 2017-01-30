#define ME capitalize(this_player()->query_name())
inherit "/obj/monster";
int nightshade, sulfur, bat_guano;

reset(arg) {
   ::reset(arg);
   if (!arg) {
 set_name("Jannhi the Vendor");
 set_alias("jannhi");
 set_short("Jannhi the Vendor");
 set_long("Jannhi is ");
 set_level(30);
 set_ac(3);
 set_wc(50);
 set_hp(2000);
 set_al(-100);
 set_aggressive(0);
 set_chat_chance(30);
 load_chat("Jannhi says: You Buy from Jannhi, he has best deals, ok?\n");
 load_chat("Jannhi sells some items to a passing wizard.\n");
 load_chat("Boltar buys some Guano from Jannhi.\n");
 load_chat("Jannhi yells: GUANO! BUY YOUR GUANO FROM JANNHI!\n");
 load_chat("Jannhi gives you a crooked smile.\n");
  nightshade = 10;
  sulfur = 20;
  bat_guano = 20;
   }
}

init(){
add_action("look","look");
add_action("buy","buy");
}

look(str){
 if(str == "at jannhi"){
write(
"Jannhi is a small dark skinned man.  He's dressed in eccentric clothes\n"+
"and his long white beard nearly touches the floor.  Jannhi has his wares\n"+
"spread out on a horse blanket in front of him.\n"+
"for sale are:  \n");
whats_for_sale();
write("\n");
write("Jannhi gives you a smile full of yellow crooked teeth.\n"+
"Jannhi says: You want to buy something from Jannhi, yes?\n"+
"Jannhi says: You give money to Jannhi, Jannhi give something to you, ok?\n");
return 1;
    }
}

whats_for_sale(){
if(nightshade > 0)
write("  Nightshade               ("+nightshade+" left).\n");
if(sulfur > 0)
write("  Sulfur                   ("+sulfur+" left).\n");
if(bat_guano > 0)
write("  Bat Guano                ("+bat_guano+" left).\n");
}

buy(str){
 string who, what;
 object obj;

if(!str){
  write("Buy <what> from <who>.\n");
  return 1; }

if(sscanf(str, "%s from %s", what, who) != 2){
  write("Buy <what> from <who>.\n");
  return 1;  }

if(who == "jannhi"){     /* make sure they're buying from jannhi */

  if(what == "nightshade"){
    if(nightshade < 1){
       out_of_stock();
    return 1;
                       }
    if(this_player()->query_money() < 101){
      no_money(what);
      return 1;
                       }
    write("Jannhi says: Ahhh, Nightshade, a very good choice indeed!\n"+
    "Jannhi takes your money and gives you nightshade.\n");
    write("Jannhi says: Tell all your friends about Jannhi, ok?\n");
    sold_something(what);
    /* clone and move object */
    this_player()->add_money(-100);
    nightshade = nightshade - 1;
    return 1;
                            }  /* end nightshade */
  if(what == "sulfur"){
    if(sulfur < 1){
      out_of_stock();
      return 1;
                  }
  if(this_player()->query_money() < 51){
      no_money(what);
    return 1;
                       }
    write("Jannhi says: Ahh, Sulfur is a very good buy indeed!\n"+
        "You give Jannhi your money and he gives you sulfur.\n"+
        "Jannhi says: You come to Jannhi for best price in town!\n");
    sold_something(what);
  /* clone and move object */
    this_player()->add_money(-50);
    sulfur = sulfur - 1;
    return 1;
                           }  /* end sulfur */
  if(what == "bat guano" || str == "guano"){
    if(bat_guano < 1){
      out_of_stock();
      return 1;
                     }
    if(this_player()->query_money() < 51){
      no_money(what);
      return 1;
                     }
    write("Jannhi says: Mmm Hmm, Best Guano on the Market!\n"+
          "You give Jannhi some coins and he gives you Bat Guano.\n"+
          "Jannhi says: Always a pleasure, kind sir.\n");
    sold_something(what);
    /* clone and move object */
    this_player()->add_money(-50);
    bat_guano = bat_guano - 1;
    return 1;
                           }  /* end bat_guano */
  if(what == "lamp"){
    if(this_player()->query_money() < 201){
      write("Jannhi says: You have not enough money for Lamp! "+
            "Go Away!\n");
      return 1;
                     }
    write("Jannhi says:  Such a beautiful artifact, and for only "+
          "200 coins!\n"+
          "Jannhi says:  I should arrest you for such a steal!\n"+
          "You give Jannhi 200 coins and he gives you a Lamp.\n");
    /* clone and move object */
    this_player()->add_money(-200);
    return 1;
                          }  /* end lamp */
        }
}


out_of_stock(){
  write("Jannhi says: So sorry, but I am fresh out!\n"+
        "Jannhi says: Perhaps you buy pretty Lamp instead, yes?\n"+
        "Jannhi holds an old dusty lamp out before you.\n"+
        "Jannhi says: A great buy at 200 coins!\n");
  return 1;
}

no_money(str){
  write("Jannhi ignores your penniless soul.\n"+
        "Jannhi calls out: "+capitalize(str)+"!  "+capitalize(str)+" here "+
        "for a customer _with money_!\n");
  write("Jannhi looks at you pointedly.\n");
return 1;
}

sold_something(what){
  write("Jannhi smiles at the other merchants victoriously.\n");
  if(random(10) > 5)
   write("Ropert flips Jannhi off.\n");
  else
   write("Ropert gives you a dirty look.\n");
  return 1;
}
