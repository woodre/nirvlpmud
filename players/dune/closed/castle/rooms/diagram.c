inherit "room/room";
#include "definitions.h"

int minneyar, resurieni, mayesa, sesuadra, shisaeron, yasira, zaeymiritha;
int try;
object ob;


init()
{
  if(!present("minneyar", TP)  ||
     !present("resurieni",TP)  ||
     !present("mayesa",TP)     ||
     !present("sesuadra",TP)   ||
     !present("shisaeron",TP)  ||
     !present("yasira",TP)     ||
     !present("zaeymiritha",TP))
  {
    write("\nYou cannot enter the sacred Sithi Diagram!\n");
    write("You do not have all 7 Sithi Stones.\n");
    write("You are sent flying back to where you came.\n\n");
    move_object(TP, CASTLEROOM+"/shaosaye.c");      
    return 1;
  }

  write_file("/players/dune/log/QUEST_ROOM", this_player()->
    query_real_name()+" (level "+this_player()->
    query_level()+") entered the Diagram."+
    " ("+ctime()+")\n");

  add_action("place", "place");
  ::init();
}


reset(arg)
{
  try = 0;
  if(!arg)
  {
    set_light(1);
    short_desc=("The Diagram");
    long_desc=
"     The diagram spans radially outward. Upon it, several indented\n"+
"glyphs spread around the outer edges of the circle. A small pedestal\n"+
"of stone stands in the center of the circular Diagram.\n"+
"Perhaps with proper placement, you may solve the secret of the diagram.\n";

    dest_dir=({
CASTLEROOM+"/shaosaye.c", "ruins",
    });

   items=({
"ruins",   "     Enki-o Shao'saye used to be the mightiest of Sithi cities",
"pedestal","     In the center of the Diagram, you see the imprint of a hand.\n"+
"While the glyphs appear to be sockets for the Sithi Stones, the imprint\n"+
"seems as if you could 'place' your hand there",
"diagram", "     The Diagram is filled with vacant imprints of glyphs",
"Diagram", "     The Diagram is filled with vacant imprints of glyphs",
"glyphs",  "     Each Sithi Stone is represented by the 7 glyphs.\n\n"+
"                    _   -   -   _                     \n"+
"     tranquility -  ------|------- -  mirth           \n"+
"              - \ --------| ------- / -               \n"+
"            - ----\ ------| ----- /---- -             \n"+
"          -  ------ \ ----| ----/-------- -           \n"+
"         - ---------- \ --| --/----------- -          \n"+
"        - ------------- \-|-/-------------- -         \n"+
" summer - ----------------O---------------- - universe\n"+
"        - --------------/-|-\ ------------- -         \n"+
"        - ------------/---|-- \------------ -         \n"+
"         - ---------/ ----|---- \ -------- -          \n"+
"          --------/ ------|------ \ ----- -           \n"+
"            ----/ --------|-------- \ - -             \n"+
"          cat - ----------|---------  - farewell      \n"+
"                 ---_-----| ----_---                  \n"+
"                        -   -                         \n"+
"                        beauty                        \n\n"+
"It appears as if you could 'place' a stone upon a glyph.\n",
    });
  }
}


int checkSyntax(string stone, string what, string glyph)
{
  string alt1, alt2, alt3, alt4;

  alt1 = glyph + " glyph";
  alt2 = "the " + glyph + " glyph";
  alt3 = "glyph of " + glyph;
  alt4 = "glyph of the " + glyph;

  if (what == glyph ||
      what == alt1  ||
      what == alt2  ||
      what == alt3  ||
      what == alt4)
  {
    if (present(stone, this_player()))
    {
      destruct(present(stone, this_player()));
    }
    write("You place " + capitalize(stone) + " upon the " + 
                         capitalize(glyph) + " glyph.\n");
    write("The Sithi Stone welds into place, then vanishes.\n");
    return 1;
  }
  else
  {
    write("It appears as if " + capitalize(stone) + " does not fit into " + 
                                capitalize(what) + ".\n");
    return 0;
  }
}


place(string str)
{
  int total;
  string stone, what;

  if(!str)
  {
    write("Place what upon what?\n");
    return 1;
  }

  str = lower_case(str);

  if (sscanf(str, "%s upon %s", stone, what) == 2)
  {
    if (stone == "hand" && what == "imprint")
    {
      total = minneyar + resurieni + mayesa + 
              sesuadra + shisaeron + yasira + zaeymiritha;

      if (total != 7)
      {
        write("Nothing happens.\n");
        return 1;
      }

      write(
"     You place your hand upon the imprint in the pedestal...\n"+
"Suddenly, the glyphs begin to glow, one by one. The air around you\n"+
"swirls and picks up speed... eventually becoming torrents of wind\n"+
"that knock you to the ground. Your hand flies off the pedestal!\n\n"+
"Something growls.\n\n");

      minneyar = 0;
      resurieni = 0;
      mayesa = 0;
      sesuadra = 0;
      shisaeron = 0;
      yasira = 0;
      zaeymiritha = 0;

      ob = clone_object(CASTLEOBJECT+"/questcheck.c");
      ob->first_half_of_quest_is_solved(7);
      move_object(ob, TP);

      write("     The Diagram cracks open and an orb of supernatural\n"+
            "light rises out and falls into your hands. Keep it.\n");
      write("You feel your body being pulled away to some distant realm.\n");

      say("The winds pick up speed.\n"+
          TPN+" is blown to the ground, and sucked into the Diagram.\n");

      move_object(TP, CASTLEROOM+"/fightroom.c");
      return 1;
    }

    else if (stone == "hand" && what != "imprint")
    {
      write("Perhaps you should place your hand on the imprint itself.\n");
      return 1;
    }

    else if (stone == "minneyar")
    {
      if (present(stone, this_player()))
        minneyar = checkSyntax(stone, what, "universe");
      else
        write("You have already placed this stone.\n");
    }

    else if (stone == "resurieni")
    {
      if (present(stone, this_player()))
        resurieni = checkSyntax(stone, what, "tranquility");
      else
        write("You have already placed this stone.\n");
    }

    else if (stone == "mayesa")
    {
      if (present(stone, this_player()))
        mayesa = checkSyntax(stone, what, "cat");
      else
        write("You have already placed this stone.\n");
    }

    else if (stone == "sesuadra")
    {
      if (present(stone, this_player()))
        sesuadra = checkSyntax(stone, what, "farewell");
      else
        write("You have already placed this stone.\n");
    }

    else if (stone == "shisaeron")
    {
      if (present(stone, this_player()))
        shisaeron = checkSyntax(stone, what, "summer");
      else
        write("You have already placed this stone.\n");
    }

    else if (stone == "yasira")
    {
      if (present(stone, this_player()))
        yasira = checkSyntax(stone, what, "beauty");
      else
        write("You have already placed this stone.\n");
    }

    else if (stone == "zaeymiritha")
    {
      if (present(stone, this_player()))
        zaeymiritha = checkSyntax(stone, what, "mirth");
      else
        write("You have already placed this stone.\n");
    }
  }
  /* end of if (sscanf(str, ... */

  else
  {
    write("You place " + str + ", and nothing happens...\n"+
          "Dude, what the heck are you trying to do?\n");
  }

  return 1;
}
