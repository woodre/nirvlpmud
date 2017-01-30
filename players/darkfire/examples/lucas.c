inherit "/obj/monster";

/******************************************************************************
 * Program: lucas.c
 * Path: /players/dragnar/WalkingDead/mons
 * Type: Mob
 * Created: July 22nd, 2013 by Dragnar
 *
 * Purpose: An NPC that cannot be attacked due to the room having a no
 *          fight set. Runs the shop, mainly for look and feel.  Catch
 *          tell enables players to ask for help on the shop rather than
 *          reading a sign.
 *
 *          Mob sells heals in a unique way. Must order at least 5 heals at
 *          a time. If player gives a bag to the mob the bag will be filled 
 *          with heals and given back to the player. If no bag is supplied
 *          the cost of the bag is added to the total. All checks are done,
 *          including that the provided bag can hold the requested heals.
 * History:
 *          08/19/2013 - Dragnar - Created.
 ******************************************************************************/
#include <ansi.h>
#include "../defs.h"

#define FIREWATER "firewater"
#define SOUP "soup"
#define SHAKE "shake"
#define BSHAKE "blueberry shake"
#define FIREWATER_PATH "/players/dragnar/WalkingDead/heals/firewater"
#define SHAKE_PATH "/players/dragnar/WalkingDead/heals/pshake"
#define SOUP_PATH "/players/dragnar/WalkingDead/heals/soup"
#define BSHAKE_PATH "/players/dragnar/WalkingDead/heals/shake"
#define SACK_PATH "/players/dragnar/WalkingDead/obj/rucksack"
#define VOID_PATH "/players/dragnar/WalkingDead/rooms/void.c"
#define STOREPATH "/players/dragnar/WalkingDead/rooms/store"
#define CHAT_CHANCE 4
#define HEALS ({ SOUP, SHAKE, BSHAKE, FIREWATER })
#define HEAL_STR "Soup, Shake, Blueberry Shake, or Firewater"

 
 /** Shop variables **/
int value;
int item_short;
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  SetMultipleIds( ({ "proprietor", "shop proprietor" }) );
  set_name("lucas");
  set_race("human");
  set_short("Lucas"+HIBLK+" - Black Creek Survival Shop Proprietor"+NORM);
set_long(
"A man in his late thirties with a receding hairline and greasy black\n\
hair. He has sort of a rodent look to his face with big ears, tiny eyes\n\
and a large pointed nose. He is lean and muscular however, and he looks\n\
like he has been in a few tight spots in his life and lived to tell the\n\
tales. Any man that can start a business in the post apocalypse world\n\
must be something of a bad ass to not only survive, but thrive.\n");

  set_gender("male");
  set_level(17);
  
  set_aggressive(0);
  set_al(0);
  
  set_chat_chance(CHAT_CHANCE);
  load_chat("Lucas says: 'If you need help just say so and I will assist you.'\n");
  load_chat("Lucas says: 'Just ask for a list and I can show you what gear I have.'\n");
  load_chat("Lucas says: 'You can ask for: list, sell, buy, purchase or value \n\
             for more information.'\n");
  load_chat("Lucas says: 'Even in a land gone to hell, there is no shop as good as mine!'\n");
  load_chat("Lucas says: 'Gold is the only currency worth a shit since the dead\n\
             started walking.'\n");
  load_chat("Lucas says: 'If you kill a walker make sure you search the corpse and\n\
             I'll buy any useful items you find and don't need.'\n");
  load_chat("Lucas says: 'I can sell you the gear you need to survive this new world.'\n");
  load_chat("Lucas says: 'If you have extra gear you don't need I can take it off\n\
             your hands. The end of the world can be profitable for us!'\n");
  load_chat("Lucas says: 'You can 'purchase' food if you are willing to buy in bulk.'\n");
  load_chat("Lucas says: 'If you don't want to buy a sack, give me a bag before doing\n\
             a 'purchase' or I'll add the charge for the sack automatically.'\n");
  load_chat("Lucas says: 'Purchase some of my "+HIG+"Spinach"+NORM+" Protein Shakes!'\n");
  load_chat("Lucas says: 'Purchase some of my "+YEL+"Soup"+NORM+"!'\n");
  load_chat("Lucas says: 'Purchase some of my "+RED+"Firewater"+NORM+"!'\n");
  load_chat("Lucas says: 'Purchase some of my "+HIB+"Blueberry"+NORM+" Shakes!'\n");
   
  move_object(clone_object("/players/dragnar/WalkingDead/obj/kill_check"), this_object());
  set_hp(650);
  set_heal(250,10);
  set_hp_bonus(1000);
  
  add_spell("shake_heal", 0, 0, 75, 0, 0, 0, "do_heal" );
  
  set_dead_ob(this_object());
  
}

init() {
  ::init();
  add_action("Sell","sell");
  add_action("Value","value");
  add_action("List","list");
  add_action("Buy","buy");
  add_action("Purchase","purchase");
  if( this_player() && this_player()->is_player() )
    call_out( "TellRoom",1+random(4), 14 );
}


void do_heal(object target, object room, int damage) {
  if( !room )
    return;
  
  switch( random(3) ) {
    case 2:
      tell_room( room, "Lucas takes a drink of the "+HIG+"Spinach "+NORM+"Shake.\n" );
      break;
    case 1:
      tell_room( room, "Lucas takes a drink of the "+YEL+"Soup"+NORM+".\n");
      break;
    default:
      tell_room( room, "Lucas takes a drink of the "+RED+"Firewater"+NORM+".\n");
      break;
  }
  
  this_object()->heal_self(100);
}

do_damage()
{
   return 0;
}

heart_beat() {
    ::heart_beat();
}

monster_died() {
  object corpse;
  object item, room;
  
  room = environment(this_object());
  corpse = present( "corpse", environment() );
  if( corpse ) {
    item = present( "kill_check_object", corpse );
    if( item )
      destruct( item );
  }
    return 0; 
}

void catch_tell(string str) {
  string who,what,junk;

  if(sscanf(str, "%s says: %s",who, what) == 2) {
    /*tell_room(environment(), "who : "+who+"\n");
    tell_room(environment(), "what: "+what+"\n"); */
    if( who == "Lucas" )
      return;
    if( find_call_out("TellRoom") > -1 )
      return;
    what = lower_case(what);
    if(sscanf(what, "%shelp\n", junk)) {
      set_chat_chance(0);
      call_out("TellRoom",1+random(4) ,99);
    }
    if(sscanf(what, "%slist\n", junk)) {
      set_chat_chance(0);
      call_out("TellRoom",1+random(4) ,0);
    }
    if(sscanf(what, "%ssell\n", junk)) {
      set_chat_chance(0);
      call_out("TellRoom",1+random(4) ,2);
    }
    if(sscanf(what, "%sbuy\n", junk)) {
      set_chat_chance(0);
      call_out("TellRoom",1+random(4) ,5);
    }
    if(sscanf(what, "%svalue\n", junk)) {
      set_chat_chance(0);
      call_out("TellRoom",1+random(4) ,6);
    }
    if(sscanf(what, "%spurchase\n", junk)) {
      set_chat_chance(0);
      call_out("TellRoom",1+random(4) ,7);
    }
    if(sscanf(what, "%s"+SOUP+"\n", junk)) {
      set_chat_chance(0);
      call_out("TellRoom",1+random(4) ,10);
    }
    if(sscanf(what, "%s"+SHAKE+"\n", junk)) {
      if(sscanf(junk, "blueberry%s",junk) != 1) {
        set_chat_chance(0);
        call_out("TellRoom",1+random(4) ,11);
      }
    }
    if(sscanf(what, "%s"+FIREWATER+"\n", junk)) {
      set_chat_chance(0);
      call_out("TellRoom",1+random(4) ,12);
    }
    if(sscanf(what, "%s"+BSHAKE+"\n", junk)) {
      set_chat_chance(0);
      call_out("TellRoom",1+random(4) ,13);
    }
  }
}
      
TellRoom(int arg) {
  string temp;
  object env;

  env = environment();
  
  if( !env )
    return;
  
  switch( arg ) {
  case 0:
    /** List **/
    tell_room(env, "\n");
    tell_room(env, "Lucas says: 'You can see what I have available buy using the 'list'\n\
             command. 'List' will show you all the items that I have.\n\
             If you are interested in a specific type, you can 'list <type>'.\n");
    call_out( "TellRoom", 6+random(6), 1 );
    break;
  case 1:
    /** List 2**/
    tell_room(env, "Lucas says: 'The types I track are armors, weapons, heals, and misc.\n\
             Also, if you want a specific item you can 'list \n\
             <item_name>' such as 'list bag'.'\n");
    set_chat_chance(CHAT_CHANCE);
    break;
  case 2:
    /** Sell **/
    tell_room(env, "\n");
    tell_room(env, "Lucas says: 'No shop handles selling as well as I do! If you want\n\
             to sell a particular item use the command 'sell <item_name>'.\n\
             You can also 'sell all <item_name>' to sell all items of\n");
    tell_room(env, "             that name. This will not sell items that are kept\n\
             or equiped. You can 'sell ALL <item_name>' to override the\n\
             check for items being equipped or kept.\n");
    call_out( "TellRoom", 10+random(6), 3 );
    break;
  case 3:
    /** Sell 2 **/
    tell_room(env, "\n");
    tell_room(env, "Lucas says: 'You can of course sell everything in your\n\
             inventory as well by simply doing 'sell all'. The 'sell ALL'\n\
             command will again override the check for equipped or kept.'\n");
    call_out( "TellRoom", 10+random(6), 4 );
    break;
  case 4:
    /** Sell 3 **/
    tell_room(env, "\n");
    tell_room(env, "Lucas says: 'If you have bags in your inventory then all\n\
             items in the bag will be sold if you sell the bag or sell\n\
             all. You can also 'sell all from <bagname>' if you wish to\n");
    tell_room(env, "             sell contents of the bag without selling the bag itself.'\n");
    set_chat_chance(CHAT_CHANCE);
    break;
  case 5:
    /** Buy **/
    tell_room(env, "\n");
    tell_room(env, "Lucas says: 'You can either 'buy <item_name>' or you\n\
             can 'buy #' after you do one of the list commands.'\n");
    set_chat_chance(CHAT_CHANCE);
    break;
  case 6:
    /** Value **/
    tell_room(env, "\n");
    tell_room(env, "Lucas says: 'You can 'value <item_name>' to see what it is worth.'\n");
    set_chat_chance(CHAT_CHANCE);
    break;
  case 7:
    /** Purchase **/
    tell_room(env, "\n");
    tell_room(env, "Lucas says: 'You can 'purchase <amount> <food_name>' to buy\n\
             heals. You can purchase "+SOUP+", "+SHAKE+", or "+FIREWATER+".\n\
             Since I deal in bulk for food you'll have to buy a bag\n\
             from me, or give me a bag prior to your purchase.'\n");
    call_out( "TellRoom", 8+random(4), 8 );
    break;
  case 8:
    /** Purchase 2 **/
    tell_room(env, "\n");
    tell_room(env, "Lucas says: 'You have the option of buying a mix of alcohol\n\
             heals with your food/soak heals. This option will add 1\n\
             alcohol heal for every 10 food heals when you add variety\n\
             to your order: 'purchase 10 "+SOUP+" variety.'\n");
    call_out( "TellRoom", 10+random(4), 9 );
    break;
  case 9:
    /** Purchase 3 **/
    tell_room(env, "\n");
    tell_room(env, "Lucas says: 'The amount that you purchase can also be\n\
             the number of gold coins you want to spend on your\n\
             purchase. To buy 30000 coins of "+SOUP+" you would do:\n\
             'purchase 30000 "+SOUP+" <variety>'.\n");
    set_chat_chance(CHAT_CHANCE);
    break;
  case 10:
    /** Soup **/
    tell_room(env, "\n");
    tell_room(env, "Lucas says: 'You can purchase a Thermos of Soup for "+SOUP_PATH->query_value()+"\n\
             gold coins. Soup is a food/soak heal.'\n");
    set_chat_chance(CHAT_CHANCE);
    break;
  case 11:
    /** Shake **/
    tell_room(env, "\n");
    tell_room(env, "Lucas says: 'You can purchase a Protein Shake for "+SHAKE_PATH->query_value()+"\n\
             gold coins. Shakes are a low intox food/soak heal.'\n");
    set_chat_chance(CHAT_CHANCE);
    break;
  case 12:
    /** Firewater **/
    tell_room(env, "\n");
    tell_room(env, "Lucas says: 'You can purchase a Bottle of Firewater for "+FIREWATER_PATH->query_value()+"\n\
             gold coins. Firewater is an alcohol heal.'\n");
    set_chat_chance(CHAT_CHANCE);
    break;
  case 13:
    /** Blueberry Shake **/
    tell_room(env, "\n");
    tell_room(env, "Lucas says: 'You can purchase a Blueberry Shake for "+BSHAKE_PATH->query_value()+"\n\
             gold coins. Blueberry Shakes are a high intox food/soak heal.'\n");
    set_chat_chance(CHAT_CHANCE);
    break;
  case 14:
    tell_room(env, "\n");
    tell_room(env, "Lucas says: 'Welcome to the Black Creek Survival Shop.'\n");
    break;
  default:
    /** Generic Help **/
    tell_room(env, "\n");
    tell_room(env, "Lucas says: 'You can 'list', 'buy', 'purchase', 'value', or 'sell' in\n\
             my shop. If you need help on any of these commands just\n\
             say what you need help with.'\n");
    set_chat_chance(CHAT_CHANCE);
    break;
  }
}

Sell( str ) { 
  return SHOP->sell( str );
}

Value( str ) {
  return SHOP->value( str );
}

List( string str ) {
  return SHOP->list( str );
}

fill_bag( object sack, int amt, string type) {
  int i, weight;
  
  if( type == SOUP )
    weight = SOUP_PATH->query_weight();
  if( type == SHAKE )
    weight = SHAKE_PATH->query_weight();
  if( type == FIREWATER )
    weight = FIREWATER_PATH->query_weight();
  if( type == BSHAKE )
    weight = BSHAKE_PATH->query_weight();
    
  for( i=0; i < amt; i++ ) {
    if( sack->add_weight( weight ) ) {
      if( type == SOUP )
        move_object(clone_object(SOUP_PATH), sack );
      else if( type == FIREWATER )
        move_object(clone_object(FIREWATER_PATH), sack );
      else if( type == BSHAKE )
        move_object(clone_object(BSHAKE_PATH), sack );
      else
        move_object(clone_object(SHAKE_PATH), sack );
    }
    else {
      write("Lucas says: 'This inferior "+sack->short()+" will not hold that many.'\n");
      SHOP->destroy_inventory( sack );
      SHOP->transfer_inventory( VOID_PATH, sack );
      move_object( sack, environment( this_object() ) );
      write("Lucas drops the "+ sack->short() + " with a disgusted shake of his head.\n");
      return 1;
    }
  }
  return 0;
}

int
recalc_amt( int amt, string type, int variety_flag ) {
  int fw_base_cost, new_amt, base_cost, cost, fw_cost;
  
  fw_base_cost = (int) FIREWATER_PATH->query_value();
  
  if( type == SOUP )
    base_cost = (int) SOUP_PATH->query_value();
  if( type == SHAKE )
    base_cost = (int) SHAKE_PATH->query_value();
  if( type == BSHAKE )
    base_cost = (int) BSHAKE_PATH->query_value();
  if( type == FIREWATER )
    base_cost = fw_base_cost;
  
  new_amt = amt / base_cost;
  if( !present( "bag" ) )
    cost = (int) SACK_PATH->query_value();
  cost += new_amt * base_cost;
  if( cost > amt )
    new_amt -= 1;
  if( this_player() && this_player()->query_level() > 39 )
    write("New amt: " + new_amt + "\n");
  
  if( variety_flag ) {
    fw_cost = new_amt * 10 / 100 * fw_base_cost;
    if( this_player() && this_player()->query_level() > 39 )
      write("FW cost: " + fw_cost + "\n" );
    cost = new_amt * base_cost + fw_cost;
    if( !present( "bag" ) )
      cost += (int) SACK_PATH->query_value();
    if( this_player() && this_player()->query_level() > 39 )
      write("Cost: " + cost + "\n" );
    if( cost > amt )
      new_amt -=  ( fw_cost + (base_cost - 1) ) / base_cost;
    if( this_player() && this_player()->query_level() > 39 )
      write("Adj new amt: " + new_amt + "\n" );
  }
  return new_amt;
}

Purchase( string str ) {
  int i, amt, amt_s, amt_f, cost, bag_flag, variety_flag;
  string what, what2, junk;
  object sack;
  
  if( !str ) {
    set_chat_chance(0);
    call_out("TellRoom",2,7);
    return 1;
  }
  if( sscanf(str, "%d %s", amt, what) == 2 ) {
    if( sscanf(what, "%s variety", what ) == 1) {
        variety_flag = 1;
    }
    
    if( this_player() && this_player()->query_level() > 39 )
      write("what: "+what+"\n" );
    if( member( HEALS, what ) < 0 ) {
      write("Lucas says: 'You can purchase "+HEAL_STR+".'\n");
      return 1;
    }
    /** Assume player wants to spend amt number of coins **/
    if( amt > 100 ) {
      amt = recalc_amt( amt, what, variety_flag ); 
    }
    if( amt < 5 ) {
      write("Lucas says: 'I only deal in bulk for food items. Minimum order is 5.'\n");
      return 1;
    }
    sack = present( "bag" );
    if( !sack ) {
      sack = clone_object( SACK_PATH );
      move_object( sack, this_object() );
      cost += sack->query_value();
      bag_flag = 1;
    }
    if( what == FIREWATER ) {
      amt_f = amt;
      amt_s = 0;
    }
    if( what == SOUP || what == SHAKE || what == BSHAKE ) {
      amt_s = amt;
      amt_f = 0;
    }
    if( variety_flag ) {
      amt_f = amt * 10 / 100;
      amt_s = amt;
    }
    if( this_player() && this_player()->query_level() > 39 )
      write("Buying "+ amt_s + " "+what+" and "+ amt_f +" firewater.\n");
    if( what == SOUP )
      cost += ( SOUP_PATH->query_value() * amt_s ) + ( FIREWATER_PATH->query_value() * amt_f );
    if( what == SHAKE )
      cost += ( SHAKE_PATH->query_value() * amt_s ) + ( FIREWATER_PATH->query_value() * amt_f );
    if( what == BSHAKE )
      cost += ( BSHAKE_PATH->query_value() * amt_s ) + ( FIREWATER_PATH->query_value() * amt_f );
    if( what == FIREWATER )
      cost += FIREWATER_PATH->query_value() * amt_f;
    if( this_player() && this_player()->query_level() > 39 )
      write("Total cost: " + cost + "\n");
    if( cost > 80000 ) {
      write("Lucas says: 'Sorry, there are no banks since the Walkers arrived.'\n" );
      return 1;
    }
    if( this_player()->query_money() < cost ) {
      write("Lucas says: 'These are hard times, I can't afford to be charitable.'\n" );
      write("Lucas says: 'Come back when you have "+cost+" gold and I'll hook you up.'\n" );
      if( !bag_flag ) {
        write("Lucas says: 'Since you wasted my time I'll hold onto this "+ sack->short()+".'\n" );
        write("Lucas dumps the contents of the bag on the ground and puts the "+sack->short()+" in the storeroom.\n");
        SHOP->transfer_inventory( sack, environment( this_player() ) );
        SHOP->move_store( sack );
      }
      else
        destruct( sack );
      return 1;
    }

    if( !bag_flag ) {
      /** Clean the void **/
      SHOP->destory_inventory( VOID_PATH );
      /** Transfer all items from the bag to the void for safe keeping **/
      SHOP->transfer_inventory( sack, VOID_PATH );
    }
    if( fill_bag( sack, amt_s, what ) )
      return 1;
    
    if( amt_f > 0 ) 
      if( fill_bag( sack, amt_f,  FIREWATER ) )
        return 1;

    if(!this_player()->add_weight(sack->query_weight())) {
      write("Lucas says: 'It doesn't look like you can carry that.'\n");
      /* Cloned the bag so destroy it and what it contains */
      if( bag_flag ) {
        destroy( sack );
        return 1;
      }
      /** Destroy the heals added to the bag **/
      SHOP->destroy_inventory( sack );
      /** Put items back in the bag **/
      SHOP->transfer_inventory( VOID_PATH, sack );
      move_object( sack, environment( this_object() ) );
      write("Lucas drops the "+ sack->short() + ".\n");
      return 1; 
    }
    SHOP->transfer_inventory( VOID_PATH, sack );
    write("Lucas takes your "+cost+" gold coins. He then reaches behind a counter and fills\n\
a "+sack->short()+" with "+amt_s+" "+what+"s"+(amt_f > 0 ? " and "+amt_f+" "+FIREWATER : "")+", and hands it to you.\n");
    move_object( sack, this_player() );
    this_player()->add_money( -cost );
    return 1;
  }
  else {
    write("Lucas says: 'What do you want to purchase?'\n");
    return 1;
  }
}

Buy( string str ) {
  return SHOP->buy( str );
}

object
query_backshop() {
  object store;
  store = find_object( STOREPATH );
  if( !store ) {
    call_other( STOREPATH, "???");
    store = find_object( STOREPATH );
  }
  return store;
}

query_annoy() { return "Lucas says: 'Not sure what you want from me?'"; }
query_annoy2() { return "Lucas rolls his eyes at "+capitalize(this_player()->query_name())+"."; }
query_sold() { return "Lucas buys your "+item_short+" for "+value+" gold coins."; }
query_sold2() { return "Lucas buys your "+item_short+" and says:\n'Sorry, "+value+" is the max gold I can pay.'" ; }
query_is_eq() { return "Lucas says: '"+item_short+" is equipped.'"; }
query_is_kept() { return "Lucas says: '"+item_short+" is kept.'"; }
query_no_item() { return "Lucas says: 'You don't seem to have "+item_short+".'"; }
query_no_item2() { return "Lucas says: 'I don't have "+item_short+".'"; }
query_no_drop() { return "Lucas says: 'I can't seem to take that from you.'"; }
query_no_bag() { return "Lucas says: 'You don't seem to have "+item_short+".'"; }
query_error() { return "Lucas says: 'Damn, something went wrong.'"; }
query_no_value() { return "Lucas says: '"+item_short+" is worthless.'"; }
query_no_move() { return "Lucas says: '"+item_short+" can't be moved.'"; }
query_empty() { return "Lucas says: '"+item_short+" is empty.'"; }
query_empty_shop() { return "Lucas says: 'Sorry I am out of gear at the moment, come back later.'"; }
query_dest_msg() { return "Lucas says: '"+item_short+" is a beauty, that is going in my private collection!'"; }
query_value_msg() { return "Lucas says: 'You would get "+value+" gold coins for "+item_short+".'"; }
query_value_msg2() { return "The "+item_short+" would cost you "+value+" gold coins."; }
query_no_money() { return "Lucas says: 'It would cost you "+value+" coins, which you don't have.'"; }
query_no_carry() { return "Lucas says: 'You are unable to carry "+item_short+".'"; }
query_buy() { return "Lucas sells you "+item_short+" for "+value+" gold coins."; }
query_dump_worthless_bag_items() { return "Lucas dumps the worthless items from the "+item_short+" onto the ground."; }
query_total(int nbr_items, int total ) { return "Lucas says: 'You sold "+nbr_items+" items for "+total+" gold coins.'"; }
query_buy_msg() { return capitalize(this_player()->query_name())+" buys "+item_short+" from Lucas."; }
query_sold_msg() { return capitalize(this_player()->query_name())+" sells "+item_short+" to Lucas."; }
query_value_func() { return "query_walker_value"; }

set_obj_value( int val ) {
  if( intp( val ) )
    value = val;
}

set_obj_short( string str ) {
  if( stringp( str ) )
    item_short = str;
}

