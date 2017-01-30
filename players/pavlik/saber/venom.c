/*
 *    Venom from a spider.
 */

#define tp this_player()->query_name()

int w;
object player;
inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("spider venom");
    set_alias("venom");
    set_type("venom");         /* set type added by Pavlik */
    set_short("Spider venom");
    set_long("A huge glob of spider venom.\n"+
             "You could 'coat' your weapon with it.\n");
    set_class(14);
    set_weight(1);
    set_value(500);
}

init()  {
  ::init();
  add_action("coat_weapon","coat");
         }
         
coat_weapon(str)  {
  object weapon;
  int temp_wc;
  
  if(!str || !(weapon = present(str, this_player())))  {
    write("What weapon do you want to coat with venom?\n");
    return 1;
          }
  
  if(weapon->weapon_class() < 1)  {
    write("Thats not a weapon...\n");
    return 1;
          }

  temp_wc = weapon->weapon_class();
  if(temp_wc < 20)  { temp_wc = temp_wc + (random(2) + 1);  }
    else { temp_wc = temp_wc;  }
  weapon->set_class(temp_wc);
  write("You cover your "+capitalize(str)+" with the spider venom.\n");
  say(tp+" covers "+weapon->short()+" with spider venom.\n");
  destruct(this_object());
  return 1;
         }
