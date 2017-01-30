/* Modified a bit by Rumplemintz for LD 8-26-2014 */
#include <ansi.h>

inherit "obj/monster";

object item, buyer;
int    value, m;
int    TRI, PROD, STONES;

void reset(int arg) {
  ::reset(arg);

  TRI = 5;  /*  number of triangles available  */
  PROD = 1;  /*  only 1 cattle prod per reset  */
  STONES = 12;  /* 12 honing stones per reboot  */
  if(arg) return;

  set_name("drucilla");
  set_race("human");
  set_short(BOLD + "Matron" + NORM + " of the " + BOLD + "Warp" + NORM +
            ", Drucilla");
  set_alias("matron");
  set_long(
	"Drucilla, the Matron of the Warp, is a stout, cherub-faced lady\n"+
	"with long flowing red hair.  She carries a large sack with items\n"+
	"inside that she will gladly share with the needy adventurer if\n"+
	"they but [ask].  Her freckled face gives her the look of youth\n"+
	"but she has been around long enough to know how to take good\n"+
	"care of herself.\n");
  set_level(20);
  set_hp(1050);
  set_al(0);
  set_wc(55);
  set_ac(24);
  set_heal(30,2);
  set_no_clean(1);
  set_aggressive(0);
  set_chat_chance(4);
  load_chat("Drucilla asks: Can I get something for you?\n");
  load_chat("'I hear there's more stones at the Rainbow Inn', says Drucilla\n");
}

void init() {
  ::init();
  add_action("go_warp", "north");
  add_action("go_warp", "down");
  add_action("go_warp", "out");
  add_action("go_warp", "gulch");
  add_action("go_warp", "park");
  add_action("go_warp", "phantasm");
  add_action("go_warp", "fiendsville");
  add_action("go_warp", "keep");
  add_action("go_warp", "chess");
  add_action("go_warp", "glade");
  add_action("go_warp", "enter");
  add_action("ask","ask");
  add_action("buy","buy");
}

int ask(string str) {
  if((!str) || str == "drucilla" || str == "matron" ) {
    write("Drucilla smiles at you and begins.... \n"+
          "  Many an adventurer has found themself in need of an item now\n"+
          "and then that they forgot to [buy].  I've taken it upon my-\n"+
          "self to pick up a few of these items and keep them with me just\n"+
          "in case someone needs them.  Here's what I have in my sack at\n"+
          "the moment....\n"+
          "  \n"+
          "     large leather pocket              375 coins\n"+
          "     a tempstick                       710 coins\n"+
          "     Magic [triangle]                  925 coins\n"+
          "     Ugly club                        1000 coins\n"+
          "     rock candy                       1400 coins\n"+
          "     an oiled honing [stone]          1450 coins\n"+
          "     Wand of Calming                  2500 coins\n"+
          "     Cattle prod                      4200 coins\n"+
          "\n");
    return 1;
  }
  return 0;
}

int buy(string str) {
  string item, type, article;
  int cost;
  object ware;

  switch(str) {
  case "candy":
  case "rock candy":
    item = "/players/eurale/OBJ/rock_candy";
    cost = 1400;
    break;
  case "pocket":
  case "leather pocket":
    item = "/players/eurale/OBJ/lbag";
    cost = 375;
    break;
  case "wand":
    item = "/players/eurale/OBJ/calm_wand";
    cost = 2500;
    break;
  case "stone":
  case "honing stone":
    item = "/players/eurale/OBJ/honing_stone";
    cost = 1450;
    type = "stone";
    article = "";
    break;
  case "club":
  case "ugly club":
    item = "/players/eurale/OBJ/ugly";
    cost = 1000;
    article = "an ";
    break;
  case "tempstick":
    item = "/players/eurale/OBJ/tempstick";
    cost = 710;
    article = " ";
    break;
  case "triangle":
  case "magic triangle":
    item = "/players/eurale/OBJ/triangle";
    cost = 925;
    type = "triangle";
    break;
  case "prod":
  case "cattle prod":
    item = "/players/eurale/OBJ/cattle_prod";
    cost = 4200;
    type = "prod";
    break;
  default:
    write("Drucilla says, 'I don't seem to have any of those in my sack.\n");
    return 1;
  }

  if ((int)this_player()->query_money() < cost) {
    write("You do not have enough to purchase this item!\n");
    return 1;
  }

  ware = clone_object(item);

  if (!this_player()->add_weight((int)ware->query_weight())) {
    write("Drucilla says, 'You'll have to lighten your load first!\n");
    return 1;
  }

  switch(type) {
  case "stone":
    if (!STONES) {
      write("'I'm fresh out of honing stones', laments Drucilla. 'Maybe " +
            "another time'\n");
      return 1;
    }
    STONES--;
    break;
  case "triangle":
    if (!TRI) {
      write("Drucilla says, 'Sorry, just sold my last one but I might\n" +
            "have more later.... check back.\n");
      return 1;
    } else  if(present("triangle", this_player())) {
      write("Drucilla pokes you and says, 'You're a greedy little\n" +
            "feller but I only sell one to a customer. *wink*\n");
      return 1;
    }
    TRI--;
    break;
  case "prod":
    if (!PROD) {
      write("Drucilla frowns and says, 'I'm sorry, I just sold the\n" +
            "only prod I had.  Maybe next time.'\n");
      return 1;
    }
    PROD--;
    break;
  default:
    break;
  }

  this_player()->add_money(-cost);
  move_object(ware, this_player());
  write("You purchase " + (article ? article : "a ") + ware->short() + ".\n");
  say(this_player()->query_name() + " purchases " +
      (article ? article : "a ") + ware->short() + ".\n", this_player());
  return 1;
}

int go_warp() {
  if (attacker_ob) {
    write("Drucilla laughs.\n");
    return 1;
  }
}
