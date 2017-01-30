inherit "/obj/monster";

#include <ansi.h>
#include "../defs.h"

/******************************************************************************
 * Program: ezra.c
 * Path: /players/dragnar/SevenSpires/mons
 * Type: Mob
 * Created: March 24th, 2015 by Dragnar
 *
 * Purpose: A high level monster in the Seven Spires area. 
 * Specials:
 *    1. 
 *    2. 
 *    3. 
 * History:
 *          04/30/2015 - Dragnar
 *            Created
 ******************************************************************************/
int offer_flag;
/* 0 = Not offered yet
 * 1 = Offered but not accepted
 * 2 = Offer accepted
 * 3 = Enchantment Type
 * 4 = Enchantment complete
 */
int blessing_type;
object offer_who;
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  SetMultipleIds( ({ "ezra the arch magus","magus", "arch magus" }) );
  set_name("ezra");
  set_race("human");
  set_short("Ezra "+HIY+"The Arch Magus"+NORM);
  set_heal( 50, 3 );
  set_long("Ezra");

  set_gender("male");
  set_level(28);
  set_hp(200+random(500));
  set_wc(75);
  set_ac(35);
  set_al(-100);
  
  add_spell("stomp",
    "#MN# pulls up his huge $G$foot$N$ and S C R E A M S as he $G$S T O M P S$N$ on you!\n",
    "#MN# pulls up his huge $G$foot$N$ and S C R E A M S as he $G$S T O M P S$N$ on #TN#!\n",
    25,"80-120","physical" );
    
}

heart_beat() {
  ::heart_beat();

  /** Begin offer **/
  if( query_hp() * 100 / query_mhp() < 90 && !offer_flag ) {
    offer_flag = 1; 
    /** Only tank gets the offer **/
    offer_who = attacker_ob;
    calm();
    TellRoom( 0 );
    /** Reset heal rate so no healing is done **/
    set_heal( 0 );
  }
}

do_damage(int *damage, string *method){
  /** Block cheaters from getting the blessing and the xp **/
  if( offer_flag > 1 ) {
    calm();
    return 0;
  }

  return ::do_damage( damage, method );
}

calm() {
  object enemy, ob;
  int x;

  ob = all_inventory(environment());
  x = 0;
  while(x < sizeof(ob)) {
    if(ob[x]->query_attack()) {
      enemy = ob[x]->query_attack();
      ob[x]->stop_fight();
      enemy->stop_fight();
    }
    x += 1;
  }
  return 1;
}

destruct_inventory() {
  object next_ob,ob;

  ob = first_inventory(this_object());
  while(ob) {
    next_ob = next_inventory(ob);
    if (!call_other(ob, "id", "soul") && !call_other(ob,"id","wiz_soul"))
      destruct(ob);
   ob = next_ob;
  }
}

TellRoom( int arg ) {
  object env, obj;
  env = environment();
  
  if( !env || !offer_who )
    return;

  switch( arg ) {
    case 0:
      /** Calm **/
      tell_room(env, "\n\n\nEzra commands: 'Peace my bretheren.'\n");
      call_out( "TellRoom", 3+random(2), 1 );
      break;
    case 1:
      /** Offer of a blessing **/
      tell_room(env, "\n\nEzra says: 'You are strong, you have bested me. However I can still\n\
            be useful to you, do not throw my life away so easily!'\n");
      call_out( "TellRoom", 4+random(4), 2 );
      break;
    case 2:
      /** Blessing 2 **/
      tell_room(env, "\n\nEzra says: 'Just ask for a blessing and I shall grant it, and then\n\
            I will go in peace to live out the remainder of my days'.\n");
      break;
    case 3:
      /** Blessing 3 **/
      tell_room(env, "\n\nEzra bows his head and says: 'Thank you for sparing my life.'\n");
      blessing_type = random(4);
      call_out("TellRoom", 4+random(4), 4 + blessing_type );
      break;
    case 4:
      /**  Enchantment **/
      tell_room(env, "\nEzra says: 'For your blessing I will enchant a piece of your\n\
            equipment. Give me whatever piece you choose.'\n");
      offer_flag = 3;
      break;
    case 5:
      /**  XP Blessing**/
      tell_room(env, "\nEzra says: 'You are wise, and for your blessing I will enhance your wisdom.'\n");
      move_object(clone_object("/obj/secure/double_obj.c"), offer_who);
      tell_object( offer_who, HIY+"Ezra has granted you DOUBLE EXPERIENCE!\n"+NORM );
      call_out("TellRoom", 4+random(4), 99 );
      break;
    case 6:
      /** HP Blessing **/
      tell_room(env, "\nEzra says: For your blessing, I will enhance your vitality.'\n");
      obj = clone_object( SCROLLDIR+"/vitality.c");
      move_object( obj, this_object() );
      command("read vitality");
      move_object( obj, offer_who );
      call_out("TellRoom", 4+random(4), 99 );
      break;
    case 7:
      /** WC Blessing **/
      tell_room(env, "\nEzra says: For your blessing, I will enhance your fortitude.'\n");
      obj = clone_object( SCROLLDIR+"/fortitude.c");
      move_object( obj, this_object() );
      command("read fortitude");
      move_object( obj, offer_who );
      call_out("TellRoom", 4+random(4), 99 );
      break;
    case 99:
      /** End **/
      tell_room(env, "\n\nEzra bows deeply to "+offer_who->query_name()+".\n");
      call_out("TellRoom", 4+random(4), 100 );
      break;
    case 100:
      /** End **/
      tell_room(env, HIY+"\n\nEzra intones an ancient word and is gone in a blinding flash!\n"+NORM);
      move_object( this_object(), "/room/void" );
      destruct_inventory();
      destruct( this_object() );
      break;
  }
}

int do_enchant(object obj) {
  int x;
  string t;
  string *dtypes;

  dtypes = ({
        "physical",             HIBLK,
        "magical",              HIM,
        "other|fire",           HIR,
        "other|ice",            HIB,
        "other|poison",         HIG,
        "other|electric",       HIY
  });

  if( !environment() || !obj || !offer_who || offer_flag > 3 ) {
    /** FUBAR **/
    return 1;
  }
  
  if ( !obj->is_weapon() && !obj->is_armor() ) {
    tell_room(environment(), "Ezra says: '"+obj->short() + " cannot be enchanted.'\n");
    tell_room(environment(), "Ezra drops the "+obj->short() +".\n");
    move_object( obj, environment() );
    return 1;
  }

  if( obj->query_enchantment("ezra enchantment"))
  {
    tell_room(environment(), "Ezra says: '"+obj->short() + " has already been enchanted.'\n");
    tell_room(environment(), "Ezra drops the "+obj->short() +".\n");
    move_object( obj, environment() );
    return 0;
  }

  x = random(sizeof(dtypes)-1);
  if(x%2) x--;

  if(sscanf(dtypes[x], "other|%s", t) != 1)
    t = dtypes[x];

  if( obj->is_weapon() ) {
    /*
     * amount is added to the weapon damage
     * name,short,long,amount,dtype,seconds,hits,func,ob
     */
    obj->add_enchantment(
       "ezra enchantment",
       HIC+"["+dtypes[x+1]+"*"+HIC+"]"+NORM,
       "This weapon has been "+HIC+"enchanted"+NORM+" by "+HIY+"The Arch Magus Ezra"+NORM+".\n"+NORM+
       obj->query_short()+" now does extra "+dtypes[x+1]+t+NORM+" damage.\n",
       9+random(4),
       dtypes[x],
       0,
       0,
       0,
       0
    );
    tell_room( environment(), "Ezra enchants the "+obj->short()+" with extra "+dtypes[x+1]+t+NORM+" damage.\n" );
  }
  else {
         /*
         * amount is % resistance to the selected damage type
         * name,short,long,amount,dtype,seconds,hits,fun,ob,res
         */
        obj->add_enchantment(
          "ezra enchantment",
          HIC+"["+dtypes[x+1]+"*"+HIC+"]"+NORM,
          "This armor has been "+HIC+"enchanted"+NORM+" by "+HIY+"The Arch Magus Ezra"+NORM+".\n"+NORM+
          obj->query_short()+" now provides extra protection against "+dtypes[x+1]+t+NORM+" attacks.\n",
          0,
          dtypes[x],
          0,
          0,
          0,
          0,
          ( (string) obj->query_type() == "armor" ? 10 : 4 )
        );
    tell_room( environment(), "Ezra enchants the "+obj->short()+" with extra protection vs "+dtypes[x+1]+t+NORM+" attacks.\n" );
  }

  tell_room( environment(), "Ezra gives the "+obj->short()+" to "+offer_who->query_name()+".\n" );
  move_object( obj, offer_who );
  call_out( "TellRoom", 4+random(4), 99);
  offer_flag = 4;

  return 1; 
}

void catch_tell(string str) {
  object obj;
  string who,what,junk;

  if( !offer_flag || !offer_who )
    return;

  if(sscanf(str, "%s says: %s",who, what) == 2) {
    if( who == "Ezra" )
      return;

    if( who == (string )offer_who->query_name() ) {
      if(sscanf(what, "%sblessing", junk) && offer_flag == 1 ) {
        call_out("TellRoom", 2+random(4), 3 );
        offer_flag = 2;
      }
    }
  }

  if(sscanf(str, "%s gives %s to Ezra%s\n", who, what, junk) && 
     offer_flag == 3 && who == (string )offer_who->query_name() )  
  {
    obj = present( what, this_object() );
    call_out( "do_enchant", 4+random(4), obj ); 
  }
}

/** For the scrolls **/
query_extra_level() { return 200 + random(200); }
