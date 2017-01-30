/*******************************
*  check /players/mythos/amon/smith.c
*   approved by saber
*
* Changed to only break 1 weapon at a time by
* illarion on 7 May 05
* see zantetsuken.c.pre.ill for original code
* in weapon_hit as I have not left the original in
* previously it broke ALL armor on the target.  now
* it only breaks 1 worn piece at random
*
*******************************/
#include "/players/mythos/closed/ansi.h"
#define tp this_player()->query_name()
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("zantetsuken");
    set_alt_name("sword");
    set_alias("katana");
    set_short(BLU+"Zantetsuken"+NORM);
  set_long("This is the legendary Zantetsuken.  It was known\n"+
    "to have cut through stone with great ease.  A very\n"+
    "valuable and dangerous weapon.\n");
    set_class(17);
    set_weight(5);
    set_value(100000);
    set_hit_func(this_object());
    set_type("sword");
}
object *get_armors(object ob) {
  object *armors;
  object *inv;
  int s;
  armors=({});
  inv=all_inventory(ob);
  s=sizeof(inv);
  while(s--)
    if(inv[s]->armor_class() > 0 && inv[s]->query_worn())
      armors+=({inv[s]});
  return armors;
}
  
  
weapon_hit(attacker){
  object *armors;
  object breakit;
  string title;
  int m,n;
  n=random(300);
  if(this_player())
  if(call_other(this_player(),"query_attrib","ste") > n && !random(2)) {
    say(HIB+"\n\n\tZantetsuken slices through "+attacker->query_name()+
    " with ease!\n\n"+NORM);
    write(HIB+"\n\n\tYou slice through your foe with ease!\n\n"+NORM);
    armors=get_armors(attacker);
    m=sizeof(armors);
    if(m) {
      breakit=armors[random(m)];
      title=breakit->query_name();
      if(!title) title=breakit->query_type();
      if(!title) title="armor";
      write("You slice through your opponent's "+title+"!\n");
      say(tp+" slices through "+attacker->query_name()+"'s "+title+"!\n",attacker);
      tell_object(attacker,tp+" slices through your "+title+"!\n"+
                  "You are cut by the shattered pieces!\n");
      breakit->armor_breaks();
      /* Add some extra damage to compensate for the change */
      attacker->heal_self(-4-random(4));
    }
    call_other(this_player(),"add_hit_point",-2-random(4));
    call_other(attacker,"heal_self",-2-random(4));
    if(!random(3)) {  /* lower the chance of this since not all armor is broken */
      write("You feel the power of the sword- it is immense!\n"+
            "Power comes with price....\n");
      this_player()->lower_attrib();
    }
    return 2;
  }
  if(68==n) {
    write("You fumble the power of the immortals!\n");
    this_object()->weapon_breaks();
    this_player()->hit_player(random(80));
  }
  if(69==n) {
    write("You fumble the power of the immortals!\n");
    this_object()->weapon_breaks();
    armors=get_armors(this_player());
    m=sizeof(armors);
    if(m) {
      breakit=armors[random(m)];
      title=breakit->query_name();
      if(!title) title=breakit->query_type();
      if(!title) title="armor";
      write("You shatter your own "+title+"!\n"+
            "You are cut by the shattered pieces.\n");
      this_player()->heal_self(-4-random(4));
      breakit->armor_breaks();
    }
  }
}


/* make save -Bp
query_save_flag()  { return 1; }
jan -03 */

