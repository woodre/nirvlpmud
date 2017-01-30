#include "/players/pavlik/closed/colors.h"
inherit "obj/weapon.c";
#define ME capitalize(this_player()->query_name())
#define PO this_player()->query_possessive()

/*
 * This weapon requires ammo (~/items/ilstkarn/ammo_box.c) to
 * function effectively.  The drawback of this weapon is keeping
 * it supplied with ammunition.  The ammo box is very difficult
 * to get (includes killing 2 lvl 30 monsters).  The weapon also
 * can jam-up and will not work until it is unjammed.  Please look
 * over carefully and mail Pavlik if you have any questions.
 *
 * from: ~/ilstkarn/monsters/soldier
 */

int jammed;
int loaded;

reset(arg){
  ::reset(arg);
  if (arg) return;
  set_name("Machine Gun");
  set_alt_name("m-60");
  set_alias("machine gun");
  set_short("An M-60 Machine Gun");
  set_long("An M-60 Machine Gun");
  set_type("gun");
  set_class(4);			/* nice low wc */
  set_weight(4);
  set_value(10400);
  set_no_clean(1);
  set_hit_func(this_object());
  jammed = 0;
  loaded = 1;
  message_hit=({
    "bashed"," with the stock of the M-60",
    "smashed"," with a bone crushing sound",
    "clubbed", "",
    "smacked"," hard",
    "hit","",
    "jabbed"," with the gun's barrel",
    "tapped"," lightly",
  });
}

long() {
  write(
  "A large powerful automatic machine gun, the M-60 is the true\n"+
  "killer's weapon.  The massive M-60 is capable of shooting\n"+
  "hundreds of rounds per minute, causing death and destruction\n"+
  "every where it goes.\n");
  if(!loaded) write("The M-60 is not loaded.\n");
  else write("The M-60 is loaded.\n");
  if(jammed) write("The M-60 is jammed!\n");
  return;
}

/*
 * No breaking.
 */
weapon_breaks() {
  return 1;
}

query_jammed(){ return jammed; }
set_jammed(i){ jammed = i; }
query_loaded(){ return loaded; }
set_loaded(i){ loaded = i; }

init() {
  ::init();
  add_action("load","load");
}

load(str) {
  if(id(str)) {
    object obj;
    obj = present("gun_clip", this_player());
    if(!obj) {
      write("Load it with what?\n");
      return 1;
    }
    if(obj->query_ammo() <= 0) {
      write("You are out of ammo.\n");
      return 1;
    }
    write("You take the strip of ammunition and feed it into the M-60.\n");
    say(ME+" loads "+PO+" M-60 machine gun.\n");
    loaded = 1;
    return 1;
  }
}

weapon_hit(attacker){
  object obj;
  int i, dmg;

  obj = present("gun_clip", this_player());

  /* make sure we have ammo */
  if(!obj) loaded = 0;
  if(obj && obj->query_ammo() <= 0) loaded = 0;

  /*
   * If no ammo or the gun is jammed we get the boring emotes
   * and no damage on the return.
   */
  if(!loaded || jammed) {
     if(message_hit[0] != "bashed") {
        message_hit=({
	"bashed"," with the stock of the M-60",
	"smashed"," with a bone crushing sound",
	"clubbed", "",
	"smacked"," hard",
	"hit","",
	"jabbed"," with the gun's barrel",
	"tapped"," lightly",
        });
     }
     if(jammed) {
       /* 25% chance to un-jam the weapon */
       if(!random(4)) {
         write(HIY+"***"+NORM+" You are able to "+HIW+"un-jam"+NORM+" the M-60!\n");
         say(ME+" un-jams the M-60!\n");
         jammed = 0;
       }
       else {
         write("You curse and try to "+HIW+"un-jam"+NORM+" the M-60.\n");
         say(ME+" curses and tries to un-jam "+PO+" M-60 machine gun.\n");
       }
     }
     return;
  }

  /*
   * If the weapon has ammo and is not jammed we get the rockin
   * emotes and do some serious damage through the return.
   */
  if(message_hit[0] == "bashed") {
    message_hit=({
      "squeezed the trigger and "+HIR+"<{ VAPORIZED }>"+NORM, "!!",
      HIR+"{: ripped through :}"+NORM,
      " with a "+HIY+"Burst"+NORM+" from the M-60",
      HIY+"({"+HIR+" WASTED "+HIY+"})"+NORM,
      " with a "+HIY+"salvo"+NORM+" of machine-gun fire",
      "fired a "+HIY+"burst"+NORM+" and "+HIR+"VENTILATED"+NORM,
      ".\n~ Blood pours from "+HIR+"numerous wounds"+NORM,
      "screamed zealously and "+HIR+"BLASTED AWAY"+NORM+" with the M-60!\n~",
      " twists and jerks as it is "+HIW+"pounded"+NORM+" by bullets",
      "squeezed the trigger and "+HIR+"filled"+NORM,
      HIR+" full of lead"+NORM,
      HIR+"grazed"+NORM, "",
    });
  }

  /* 5% chance that the weapon will get jammed */
  if(random(20) == 12) {
    write(HIW+"***"+NORM+" The M-60 "+HIY+"jams up"+NORM+" on you!\n");
    jammed = 1;
    return;
  }

  /* Use up some ammo */
  if(!this_player()->query_ilstkarn()) {
    obj->add_ammo(-(2+random(6)));
  }

  i = random(6);
  if(i==0)
    tell_room(environment(this_player()),
    "The deafening sound of machine gun fire fills the room.\n");
  else if(i==2)
    tell_room(environment(this_player()),
    "A stray bullet ricochetes and screams past your ear.\n");
  else if(i==4)
    tell_room(environment(this_player()),
    "The M-60's muzzle "+HIY+"flares"+NORM+" as bullets stream out!\n");
  
  /*
   *  majority of damage is done through the return, not the
   *  physical weapon class.
   *  return = 16-20 + wc4 = 24 max
   */
  dmg = 16+random(5);

  return dmg;
}

