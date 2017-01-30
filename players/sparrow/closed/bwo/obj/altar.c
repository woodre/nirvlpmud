#include <ansi.h>
#include "../defs.h"
inherit "obj/clean";
inherit"../std/tell_text";
int busy;
int rank, cost, mems, funds;

short() {
  return HIK+"an ornate altar"+NORM;
}
long() {
  write("This is the ceremonial altar used for worship in a Parish of\n"+
        "the Black Willow Order. Carved from the dark wood of the black\n"+
        "willow tree, enchantments have been placed on it to enhance the\n"+
        "black color. Delicate runes have been carved on the surface, the\n"+
        "inlays fitted with platinum.\n");
}
get() { return; }
drop() { return 1; }
id(str) { return str == "bwo_altar" || str == "altar"; }

void init() {
  if (!this_object()) return;
  add_action("ceremony", "ceremony");
}


int
ceremony(string str){
  int failure;
  object gob;
  gob = present("black_willow_object", this_player());
  rank = (int)this_player()->query_guild_rank();
  if(!gob) {
    write("The congregation looks at you quizzically as you fumble around the altar.\n");
    return 1;
  }
  if(busy) {
    write("The altar is being used in a ceremony already, please wait.\n");
    return 1;
  }
  if(str == "advance" || str == "renown" || str == "advancement" || str == "level") {
    if(rank == 20) {
      write("You have already mastered your Parish.\n"+
            "Now go and spread the "+HIK+"Dark Word"+NORM+" throughout the realm!\n");
      return 1;
    }
    switch(rank) {
      case 1:
        cost = 40000;
        mems = 1200;
        funds = 5000;
        break;
      case 2:
        cost = 80000;
        mems = 7200;
        funds = 12000;
        break;
      case 3:
        cost = 230000;
        mems = 20000;
        funds = 50000;
        break;
      case 4:
        cost = 400000;
        mems = 50000;
        funds = 100000;
        break;
      case 5:
        cost = 500000;
        mems = 100000;
        funds = 200000;
        break;
      case 6:
        cost = 750000;
        mems = 200000;
        funds = 300000;
        break;
      case 7:
        cost = 1000000;
        mems = 300000;
        funds = 500000;
        break;
      case 8:
        cost = 1000000;
        mems = 500000;
        funds = 750000;
        break;
      case 9:
        cost = 2000000;
        mems = 750000;
        funds = 1000000;
        break;
      case 10:
        cost = 2000000;
        mems = 1000000;
        funds = 1250000;
        break;
      case 11:
        cost = 2000000;
        mems = 1250000;
        funds = 1500000;
        break;
      case 12:
        cost = 2000000;
        mems = 1500000;
        funds = 2000000;
        break;
      case 13:
        cost = 2000000;
        mems = 1750000;
        funds = 2500000;
        break;
      case 14:
        cost = 2000000;
        mems = 2000000;
        funds = 3000000;
        break;
      case 15:
        cost = 2000000;
        mems = 2500000;
        funds = 3500000;
        break;
      case 16:
        cost = 3000000;
        mems = 3000000;
        funds = 4000000;
        break;
      case 17:
        cost = 3000000;
        mems = 3500000;
        funds = 5000000;
        break;
      case 18:
        cost = 3000000;
        mems = 4000000;
        funds = 6000000;
        break;
      case 19:
        cost = 3000000;
        mems = 5000000;
        funds = 8000000;
    }
    if(this_player()->query_free_exp() < cost )
    {
      write("You require "+HIK+"["+HIC+cost+HIK+"]"+NORM+" experience to grow your renown.\n");
      failure = 1;
    }
    if(gob->queryParish() < mems ) {
      write("You require "+HIK+"["+HIC+mems+HIK+"]"+NORM+" Parish members to grow your renown.\n");
      failure = 1;
    }
    if(gob->queryWorth() < funds ) {
      write("You require "+HIK+"["+HIC+funds+HIK+"]"+NORM+" gold in your coffers to grow your renown.\n");
      failure = 1;
    }
    if(failure) {
      return 1;
    }
    busy = 1;
    write("You begin the Ceremony of Advancement.\n");
    say(this_player()->query_name()+" begins the Ceremony of Advancement.\n");;
    tell_text(environment(this_player()),
      BOLD+"The cathedral bells begin sounding throughout the realm.\n"+
      NORM+"Ushers begin seating the congregation in the pews.\n");
    call_out("adv1", 6, this_player());
  }
  else {
    write("Which ceremony would you like to perform?\n");
    return 1;
  }

}

void adv1(object ob) {
  if(!ob || !present(ob, environment(this_object()))) {
    busy = 0;
    return;
  }
  tell_text(environment(ob),
    "The cathedral is full, your entire congregation has arrived.\n"+
    BOLD+"The bells slow down, eventually ending the barrage of sound.\n"+NORM+
    "The huge pipe organ begins to play a beautifully dark melody.\n"+
    BOLD+"Chrysta the Choir Monk"+NORM+" moves in front of the congregation to lead the chant.\n\n\n\n");
    call_out("adv2", 6, ob);
    return;
}

void adv2(object ob) {
  if(!ob || !present(ob, environment(this_object()))) {
    busy = 0;
    return;
  }
  tell_text(environment(ob),
    BOLD+"Chrysta sings: '"+NORM+"Dominus Noctis exaudi preces filiorum tuorum."+BOLD+"'\n"+NORM+
    "There is an electricity in the air, like a long dead power awakening...\n"+
    BOLD+"The congregation repeats: '"+NORM+"Dominus Noctis exaudi preces filiorum tuorum."+BOLD+"'\n"+NORM+
    "The power begins to congeal, creating a swirling dark mass above the altar.\n\n\n\n");
    call_out("adv3", 6, ob);
    return;
}

void adv3(object ob) {
  if(!ob || !present(ob, environment(this_object()))) {
    busy = 0;
    return;
  }
  tell_text(environment(ob),
    BOLD+"Chrysta sings: '"+NORM+"Electis, redde diffusa potestas tuos."+BOLD+"'\n"+NORM+
    ob->query_name()+" grabs the altar and begins to go into a trance.\n"+
    BOLD+"The congregation repeats: '"+NORM+"Electis, redde diffusa potestas tuos."+BOLD+"'\n"+NORM+
    "Dark energy pours from the mouths of the congregation.\n\n\t\t"+HIK+"Shaade"+NORM+" has arrived!\n\n\n\n");
    call_out("adv4", 6, ob);
    return;
}

void adv4(object ob) {
  if(!ob || !present(ob, environment(this_object()))) {
    busy = 0;
    return;
  }
  tell_text(environment(ob),
    BOLD+"Chrysta screams: '"+NORM+"Ut det electus vestra sancta aditus potestatem!"+BOLD+"'\n"+NORM+
    HIK+"Shaade"+NORM+" reaches out and violently grabs "+ob->query_name()+"by the face! \n"+
    BOLD+"The congregation screams: '"+NORM+"Ut det electus vestra sancta aditus potestatem!"+BOLD+"'\n"+NORM+
    "There is a blinding flash!\n\n\t\t"+ob->query_name()+" is thrown back!\n\n"+
    "Everything goes deathly quiet, "+ob->query_name()+" slowly rises - exuding power.\n");
    ob->add_xp(-cost);
    ob->add_guild_rank(1);
    tell_object(ob, "Congratulations, you have attained rank "+HIR+(rank+1)+NORM+"!\n");
    busy = 0;
    return;
}
