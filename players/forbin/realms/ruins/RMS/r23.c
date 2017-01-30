#include "/players/forbin/realms/ruins/ruinsdefine.h"
inherit "/players/forbin/closed/std/room.c";

reset(arg) {
  if(!present("archangel")) {
    move_object(clone_object(NPC+"deathangel.c"), this_object()); 
  }
  if(arg) return;
set_light(-1);

short_desc = RUINS;
long_desc =
"  You find yourself in an elegantly decorated throne room. Standing\n"+
"directly in front of you is a giant throne, its polished onyx surface\n"+
"glistening with its own inner light.  The floor is made from a dark\n"+
"marble as is the ceiling and walls. A huge unholy symbol stands\n"+
"directly behind you, a large black pearl set in its center.\n";

items = ({
  "throne",
  "You look closely and see that it is covered with numerous runes of power and\n"+
  "its high back is decorated as a copy of the unholy symbol that brought you\n"+
  "here",
  "floor",
  "Polished to a high sheen, you can nearly see yourself reflected in its surface",
  "walls",
  "You look closely and see that they are made of a fine marble and highly polished",
  "ceiling",
  "You look up at the high dome ceiling and see it is covered with an intricate\n"+
  "painting",
  "painting",
  "You look and see that it is a historical battle of some type, detailing the fall\n"+
  "of some holy stronghold. Making out the details you could almost swear that you\n"+
  "have been at this place. But how could that be? The scenery is beautiful and is\n"+
  "only then being touched by evil as it pours through a portal from the abyss. You\n"+
  "can almost see the vegetation wither and die as the evil approached, the good\n"+
  "being overwhelmed by its unstoppable movement. It is then you realize that the\n"+
  "stronghold is the very ruins that lie above you. What could have brought forth so\n"+
  "much evil to destroy so much? perhaps you may never know the truth",
  "symbol",
  "It looks to be an exact copy of the one that brought you here, a giant black pearl\n"+
  "set within its center",
  "unholy symbol",
  "It looks to be an exact copy of the one that brought you here, a giant black pearl\n"+
  "set within its center",
  "pearl",
  "Again, as with the other, you see claw marks around the setting of the pearl",
  "runes",
  "You cannot make them out, but you do realize that they are some ancient language",
  
});

}

query_ruinsroom() { return 1; }

short() { 
  int i;
  string sh;
  if(set_light(0) > 0) { 
    if(this_player()) {
      if(!environment(this_player())->query_ruinsroom() && this_player()->query_level() < 40) return HIW+RUINS+NORM; 
      else { 
        sh = HIW+short_desc+" ["+NORM;
        if(!dest_dir || no_exits) sh += "no exits";
        else {
          for(i=1; i<sizeof(dest_dir); i+=2) {
            sh += translate_exit(dest_dir[i]);
            if (i < sizeof(dest_dir)-2) sh += ",";
          }
        }
        sh += HIW+"]";
        return sh+NORM; 
      }
    }
    else return HIW+RUINS+NORM;   
  }
  else return "Dark room";     
}

init()
{
  ::init();
  add_action("way_out", "turn");
}

way_out(string str)
{
  if(!str){ write("turn what?\n"); return 1; }
  if(str == "pearl")
  {
    write("\n\nYou turn the black pearl and find that it moves very easily within\n");
    write("its setting. You feel it click and watch in astonishment as your\n");
    write("settings shimmer and fade away to be replaced by that of a new room.\n\n\n");  
    say(TPN+" fades away.\n");
    move_object(TP, RMS+"r13.c");
    tell_room(environment(TP), TPN+" arrives.\n", ({TP}));
    command("look", TP);
      return 1;
  }
  write("That didn't seem to work.\n");
    return 1;
}
 
    