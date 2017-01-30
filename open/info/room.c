inherit "room/room";
#include "/players/zeus/closed/all.h"
#define LENGTH 5

mixed *Items;
object d, r;

reset(arg){
 if(arg) return;

  Items = ({ ({ "Poop", 100, "Misc", "/players/mizan/etheriel/items/shitplus.c", 0 }) /** Just a placeholder for index 0 **/
            ,({ "Gold", 0, 0, 0, "You can exchange x points for x/2 gold" })
            ,({ "Casino Chips", 0, 0, "/players/boltar/casino/floor/chips", "You can exchange x points for x casino chips" })
            ,({ "Scroll of Acumination", 5000, "Misc", "/players/dragnar/SevenSpires/scrolls/acuminate.c", "Scroll that makes any weapon unbreakable (5 charges)" })
            ,({ "Ice Sphere", 4000, "Heal", "/players/snow/heals/ice_sphere", "Non-Tox Heal 100x3" }) 
            ,({ "Full Heal", 5000, "Heal", "/players/morgar/spells/full_heal", "Full Non-Tox Heal" })
            ,({ "Wocket Heal", 8500, "Heal", "/players/wocket/turtleville/OBJ/heal_potion", "Full Non_Tox Heal with tox reduction" })
            ,({ "Savable Bag", 25000, "Misc", "/players/saber/stuff/lr_mbag.c", "Bag that saves when you quit the game" })
            ,({ "Scroll of Wisdom", 100000, "Misc", "/players/dragnar/SevenSpires/scrolls/wisdom", "Scroll that grants 45+ min double xp" })
          });
  d = clone_object("obj/monster");
  r = clone_object("/obj/armor.c");
  r -> set_name("robe");
  r -> set_short("A baggy brown robe");
  r -> set_long("This is a baggy brown robe with a large hood.  It\n"+
    "is made from a rough material and looks very old.\n");
  r -> set_weight(1);
  r -> set_ac(1);
  move_object(r, d);
  command("wear robe", d);

  call_other(d, "set_name", "traveler");
  call_other(d, "set_alias", "man");
  call_other(d, "set_short", "An old traveler");
  call_other(d, "set_race", "human");
  call_other(d, "set_gender", "male");
  call_other(d, "set_long",
    "This is an old man who has traveled all over the areas of Nirvana.\n"+
    "He is wearing a long brown robe which hangs loosely over his body.\n"+
    "His hair is white, and he has a solemn face, but he exudes an aura\n"+
    "of quiet grace and tranquility.  You can ask him about the areas or\n"+
    "the guilds of Nirvana.  Type 'ask about <name|guild>' where name is\n"+
    "either the name of the wizard's area you want information on or the\n"+
    "name of a guild.  To see which areas or guilds he has been to, type:\n"+
    "'ask about areas' or 'ask about guilds'.\n");
  call_other(d, "set_level", 14);
  call_other(d, "set_ac", 111);
  call_other(d, "set_wc", 18);
  call_other(d, "set_hp", 5000);
  call_other(d, "set_al", 200);
/*
  call_other(d, "add_money", 1+random(200));
*/
  call_other(d, "set_chat_chance", 2);
  call_other(d, "set_a_chat_chance", 1);
  call_other(d, "load_chat", "The old traveler looks around with a smile.\n");
  call_other(d, "load_chat", "The old traveler says: 'I can "+HIW+"exchange"+NORM+" your nirvana points for you'.\n");
  call_other(d, "load_chat", "The old traveler glances up at you.\n");
  call_other(d, "load_chat", "The old traveler smiles softly.\n");
  call_other(d, "load_chat", "The old traveler checks his pockets.\n");
  call_other(d, "load_chat", "The old traveler glances north.\n");
  call_other(d, "load_chat", "The old traveler glances down at the ground.\n");
  call_other(d, "load_a_chat", 
    "The old traveler asks, \"Why do you do this?\"\n");
  call_other(d, "load_a_chat", 
    "The old traveler asks, \"What have I done?\"\n");
  call_other(d, "load_a_chat", 
    "The old traveler says, \"This is not right.\"\n");
  move_object(d, this_object());

  add_property("no_fight");
  short_desc="The adventurers guild";
  long_desc =
"This is a side area of the adventurer's guild.  There are numerous\n"+
"tables and chairs for people to relax on.  Other buildings of the\n"+
"village can be seen all around.  The sun is shining overhead.\n";
  items=({
  "tables", "The tables are made of oak and look rather old",
  "chairs", "The chairs look old yet rather comfortable",
  "sun",  "The sun is shining down upon the village",
  "buildings", "Many other buildings of the village can be seen"+
  " in all directions",
  });
  set_light(1);
  dest_dir=({ "/room/adv_guild.c", "east"  }); 
}

void init(){
  ::init();
  add_action("info_cmd", "ask");
  add_action("Exchange","exchange");
  add_action("List","list");
}

Exchange( str ) {
  object item;
  string error;
  int selection, amount;

  if(!present(d, this_object())) return 0;

  if( !str ) {
    write("Exchange <#> <amount to exchange (for coins/chips)>\n");
    return 1;
  }
 
  /** Exhcnage points for gold/chips **/
  if( sscanf(str, "%d %d", selection, amount) == 2 ) {
    if( selection != 1 && selection != 2 ) {
      write("Exchange <#> <amount to exchange (for coins/chips)>\n");
      return 1; 
    }
    if( this_player()->query_nrpoints() < amount ) {
      write("You do not have "+comma_number(amount)+" nirvana points to exchange.\n");
      return 1;
    }
    if( selection == 1 ) {
      this_player()->add_money( amount/2 );
      write("The old traveler happily exchanges your nirvana points for "+Items[1][0]+".\n");
    }
    if( selection == 2 ) {
      if( error = catch( item = clone_object( Items[selection][3] ) ) ) {
        write(Items[selection][0] + " is currently not available, please select another item.\n");
        log_file("NP_VIOLATIONS", Items[selection][3] + " " +error );
        emit_channel("admin", "(admin) "+Items[selection][3] + " " +error );
        return 1;
      }
      else {
        item->add_chip_value( amount );
        move_object( item, this_player() );
        write("The old traveler happily exchanges your nirvana points for "+Items[2][0]+".\n");
      }
    }
    this_player()->add_nrpoints( -amount );
    return 1;
  }

  /** Exchange points for items **/
  if( sscanf(str, "%d", selection) == 1 ) {

    if( selection < 3 || selection > sizeof(Items) - 1 ) {
      write("Exchange <#> <amount to exchange (for coins/chips)>\n");
      return 1; 
    } 
    amount = Items[selection][1]; 
    if( this_player()->query_nrpoints() < amount ) {
      write("You do not have "+comma_number(amount)+" nirvana points to exchange.\n");
      return 1;
    }
    if( error = catch( item = clone_object( Items[selection][3] ) ) ) {
      write(Items[selection][0] + " is currently not available, please select another item.\n");
      log_file("NP_VIOLATIONS", Items[selection][3] + " " +error );
      emit_channel("admin", "(admin) "+Items[selection][3] + " " +error );
      return 1;
    }
    else {
      if (!call_other(this_player(), "add_weight", call_other(item, "query_weight"))) {
        write( "You are unable to carry the "+Items[selection][0] +".\n" );
        destroy(item);
        return 1;
      }
      move_object( item, this_player() );
      this_player()->add_nrpoints( -amount );
      write( "The old traveler happily exchanges the "+Items[selection][0]+" for your nirvana points.\n");
    }
    return 1;
  } 

}

List() {
  int i;

  if(!present(d, this_object())) return 0;

  write(pad("[#]", 5)+pad("Point Cost", -12)+"   Name\n");
  write("-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==--==--==--==--\n");
  for( i=1; i < sizeof( Items); i++ ) {
    write( pad(i+".", -4) + pad( ("  "+Items[i][1] ? comma_number(Items[i][1]) : "Variable"), -13 ) + "   "+ Items[i][0] + "\n" );
  }
  write("-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==-==--==--==--==--\n");
  return 1;
}

info_cmd(str){
  int x, c, suze;
  string hmm, test, heh, a, b;
  if(!present(d, this_object())) return 0;
  if(!str) return (notify_fail("\
Type 'ask about <what>' where name is the name of the wizard's\n\
area you want information on, or the guild you want information\n\
on.  To see which areas he has been to type 'ask about areas' and\n\
to see what guilds he is familiar with type 'ask about guilds'.\n\
You can also ask about items from my list like 'ask about 1'.\n"),0);

  if(sscanf(str, "%spoints%s", a,b)) {
    write("\nThe old traveler says, \"You can get a "+HIW+"list"+NORM+" of items I can "+HIW+"exchange"+NORM+" for\n\
Nirvana points. Some items you can ask about as well.\"\n");
    return 1;
  }
  if(sscanf(str, "%sguild%s", a,b))
  {
    c = 1;
    test = get_dir("/open/info/guilds/");
    suze = sizeof(test);
    write(
    "\nThe old traveler says, \"These are the guilds i'm familiar with:\"\n"+
    GRN+" - --- ------- -- -------  ------------- --- --- ------\n\n  "+NORM);
    for(x = 0; x < suze; x++)
    {
      if(sscanf(test[x],"%s.nfo",hmm))
      {
        write(pad(capitalize(hmm), 12));
        if(c == LENGTH)
        {
          write("\n  ");
          c = 0;
        }
        c++;
      }
    } /* end for */
    write(GRN+"\n\n - --- ------- -- ------- "+
      " ------------- --- --- ------\n\n"+NORM);
    say("The traveler says something to "+TP->QN+".\n");
    return 1;
  }
  if(sscanf(str, "%sarea%s", a,b))
  {
    c = 1;
    test = get_dir("/open/info/");
    suze = sizeof(test);
    write(
    "\nThe old traveler says, \"These are the areas i've been to:\"\n"+GRN+
    " - --- ------- -- -------  ------------- --- --- ------\n\n  "+NORM);
    for(x = 0; x < suze; x++)
    {
      if(sscanf(test[x],"%s.nfo",hmm))
      {
        write(pad(capitalize(hmm), 12));
        if(c == LENGTH)
        {
          write("\n  ");
          c = 0;
        }
        c++;
      }
    } /* end for */
    write(GRN+"\n\n - --- ------- -- ------- "+
      " ------------- --- --- ------\n\n"+NORM);
    say("The traveler says something to "+TP->QN+".\n");
    return 1;
  }
  else if(sscanf(str, "about %d", x)) {
    if( x < sizeof( Items ) ) {
      write("The old traveler says: "+Items[x][4]+"\n");
      return 1;
    }
  }
  else if(sscanf(str, "about %s", b))
  {
    int      sz;
    string    info_path;
    heh = lower_case(b);
    if(heh == "dark order") heh = "order";
    if((sz = (file_size(info_path = "/open/info/"+heh+".nfo"))) > 0)
    {
      if(sz > 2000) "/closed/wiz_soul"->more(info_path);
      else cat(info_path);
      say("The traveler says something to "+TP->QN+".\n");
      return 1;
    }
    else if((sz=(file_size(info_path = "/open/info/guilds/"+heh+".nfo"))) > 0)
    {
      if(sz > 2000) "/bin/wiz/_more"->cmd_more(info_path);
      else cat(info_path);
      say("The traveler says something to "+TP->QN+".\n");
      return 1;
    }
     return (notify_fail("The traveler tells you: I don't have any " +
        "information on " + capitalize(b) + ".\n"), 0);
  }
  return (notify_fail("The traveler pokes you.\n" +
     "The traveler tells you: You can only 'ask' about 'guilds', 'areas',\n"+
     "'points', or 'about' someone's area!\n"), 0);
}

