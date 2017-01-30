#include <ansi.h>
#include "../defs.h"
/******************************************************************************
 * Program: aegis.c
 * Path: /players/dragnar/SevenSpires/scrolls
 * Type: Object
 * Created: June 30th, 2015 by Dragnar
 *
 * Purpose: One of the scrolls in the Seven Spires area that give temporary
 *          powers to a player. This one will allow the player to enchant a
 *          a weapon or armor for additional damage/protection.
 * History:
 *          06/30/2015 - Dragnar
 *            Created
 ******************************************************************************/
 
id(string str) {
   return str == "scroll" || str == "aegis" || str == "scroll of aegis";
}
short() {
  return "A Scroll of "+CYN+"Aegis"+NORM;
}

long() {
write(YEL+
" _________________________________\n\
/  _\\                             \\\n\
\\ (_/_____________________________/\n\
 \\                             \\\n\
  \\     "+CYN+"  _  ___  _   ___  __   "+NORM+YEL+"\\ \n\
   \\    "+CYN+" /_) )_  / _   )  (_ `   "+NORM+YEL+"\\\n\
    \\   "+CYN+"/ / (__ (__/ _(_ .__)    "+NORM+YEL+" \\\n\
     \\                             \\\n\
      \\                             \\\n\
       \\   "+NORM+"This scroll gives the "+YEL+"    \\\n\
      __\\    "+NORM+"bearer the power to "+YEL+"     \\\n\
     / )_\\    "+NORM+"aegis any equipment."+YEL+"     \\\n\
     \\___/_____________________________/\n"+NORM);
}

reset(arg){
  if(arg) return;
}

init() {
  add_action("do_aegis","aegis");
}

int do_aegis(string str) {
  int x;
  string t;
  string *dtypes;
  object obj;

  dtypes = ({
        "physical",             HIBLK,
        "magical",              HIM,
        "other|fire",           HIR,
        "other|ice",            HIB,
        "other|poison",         HIG,
        "other|electric",       HIY
  });

  if( !str )
    return 0;

  obj = present( str, this_player() );
  if( !obj ) {
    write("You don't have a "+str+".\n");
    return 1;
  }
  
  if ( !obj->is_weapon() && !obj->is_armor() ) {
    write( obj->short() + " cannot be enchanted.\n");
    return 1;
  }

  if( obj->query_enchantment("scroll enchantment"))
  {
    write( obj->short() + " has already been enchanted.\n");
    return 1;
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
       "scroll enchantment",
       HIC+"["+dtypes[x+1]+"*"+HIC+"]"+NORM,
       obj->query_short()+" does extra "+dtypes[x+1]+t+NORM+" damage.\n",
       5+random(5),
       dtypes[x],
       600 + (int) this_player()->query_extra_level() * 8 ,
       0,
       0,
       0
    );
    write( format("Magic flows from the scroll into the "+obj->short()+" enchanting it with extra "+dtypes[x+1]+t+NORM+" damage.\n", 80) );
  }
  else {
         /*
         * amount is % resistance to the selected damage type
         * name,short,long,amount,dtype,seconds,hits,fun,ob,res
         */
        obj->add_enchantment(
          "scroll enchantment",
          HIC+"["+dtypes[x+1]+"*"+HIC+"]"+NORM,
          obj->query_short()+" now provides extra protection against "+dtypes[x+1]+t+NORM+" attacks.\n",
          0,
          dtypes[x],
          600 + (int) this_player()->query_extra_level() * 8,
          0,
          0,
          0,
          ( (string) obj->query_type() == "armor" ? 10 : 4 )
        );
    write( format("Magic flows from the scroll into the "+obj->short()+" enchanting it with extra protection vs "+dtypes[x+1]+t+NORM+" attacks.\n", 80) );
  }

  write( "The scroll withers and slowly fades away.\n" );
  say(this_player()->query_name()+" whispers a word and light flows into the "+obj->short()+".\n");
  destruct( this_object() );
  return 1; 
}

get() { return 1; }
drop() { return 0; }
query_weight() { return 0; }
query_value() { return 0; }
