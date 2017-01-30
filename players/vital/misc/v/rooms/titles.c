inherit "room/room";
#include "/players/eurale/VAMPIRES/RMS/check.h"
#include "/players/eurale/defs.h"

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = "Vampire Title Room";
long_desc =
  "This "+BOLD+"circular black room"+NORM+" has a "+HIR+"pentagram"+
      NORM+" etched into the shiney\n"+
  "floor.  A narrow, curved doorway leads north into the Vampire\n"+
  "Guild board room.  A small, curved plaque is attached to the wall\n"+
  "reflecting what little light there is.\n";

items = ({
  "floor","Polished black onyx with a red pentagram",
  "pentagram","A eerie, blazing symbol that emanates from the floor",
  "plaque","A polished black plaque with fire red letters you can read",
  "doorway","A narrow doorway that silhouettes a bat with extended \n"+
            "wings... about to take flight",
});

dest_dir = ({
  "players/eurale/VAMPIRES/RMS/boardroom","north",
  "players/eurale/VAMPIRES/RMS/foyer.c","down",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("down","down");
  add_action("fix_titles","fix_title");
  add_action("show_titles","show_titles");
  add_action("read","read");
}

down() {
if(!present("efangs",TP)) {
  write("A strange force prevents you from going down.\n");
  return 1; }
TP->move_player("down#players/eurale/VAMPIRES/RMS/foyer.c");
return 1;
}

fix_titles() {
write("You silently whisper your request.... the room becomes very\n"+
      "still and quiet..... a coldness, unlike anything you've ever\n"+
      "felt, creeps into the room and brushes across your exposed\n"+
      "skin..... you shiver with goose-bumps... and then the warmth\n"+
      "returns....\n\n");
say(capitalize(TPN)+"'s lips turn blue and "+TP->query_pronoun()+
    " shivers violently...\n");

if(TP->query_real_name() == "eurale") {
  TP->set_pretitle(GRY+"~o~"+NORM);
  TP->set_title("the "+HIR+"S"+GRY+"upreme "+HIR+"N"+GRY+"osferatu"+NORM);
  return 1; }

if(TP->query_real_name() == "magus") {
/*
  TP->set_pretitle(GRY+"C"+HIR+"ount"+NORM);
  TP->set_title("the "+GRY+"V"+HIR+"ampire "+GRY+"U"+HIR+"nderlord"+NORM);
*/
  TP->set_title(BOLD+"the Malefactor Legend of Macabre"+NORM);
  TP->add_alignment(-1500);
  return 1; }

if(TP->query_real_name() == "night") {
  TP->set_title(HIR+"of the Living Dead"+NORM);
  TP->add_alignment(-1500);
  return 1; }

if(TP->query_real_name() == "euboy") {
  TP->set_title("the "+GRY+"Testor of the "+HIR+"Fangs"+NORM);
  return 1; }

if(TP->query_real_name() == "bone") {
  TP->set_pretitle(HIR+"D"+GRY+"ead "+HIR+"M"+GRY+"an "+HIR+"W"+GRY+"alking..."+NORM);
  TP->set_title("the "+HIR+"L"+NORM+BOLD+"egendary "+
    HIR+"L"+NORM+BOLD+"ord of "+
    HIR+"D"+NORM+BOLD+"arkness"+NORM);
  TP->set_al_title("Blackhearted");
  return 1; }

if(TP->query_extra_level() >= 21) {
  if(TP->query_gender() == "male") {
    TP->set_title("the "+HIR+"V"+GRY+"ampire "+HIR+"G"+GRY+
                  "randmaster"+NORM);
    return 1; }
  if(TP->query_gender() == "female") {
    TP->set_title("the "+HIR+"V"+GRY+"ampire "+HIR+"G"+GRY+
                  "randmistress"+NORM);
    return 1; }
}

if(TP->query_extra_level() == 20) {
  TP->set_title("the "+GRY+"Nocturnal "+HIR+"Soul "+GRY+"Hunter"+NORM);
  return 1; }

if(TP->query_extra_level() == 19) {
  if(TP->query_gender() == "male") {
    TP->set_title("the "+GRY+"Dominator of Shadows"+NORM);
    return 1; }
  if(TP->query_gender() == "female") {
    TP->set_title("the "+GRY+"Dominatrix of Shadows"+NORM);
    return 1; }
}

if(TP->query_extra_level() == 18) {
  TP->set_title(RED+"the "+HIR+"Hellhound "+RED+"of "+BOLD +
                "Darkness"+NORM);
  return 1; }

if(TP->query_extra_level() == 17) {
  if(TP->query_gender() == "male") {
    TP->set_title(GRY+"the Lord of "+HIR+"S"+GRY+"orcery"+NORM);
    return 1; }
  if(TP->query_gender() == "female") {
    TP->set_title(GRY+"the Lady of "+HIR+"S"+GRY+"orcery"+NORM);
    return 1; }
}

if(TP->query_extra_level() == 16) {
  TP->set_title("the "+HIR+"Adept"+NORM+" of "+GRY+"Stormy Skies"+NORM);
  return 1; }

if(TP->query_extra_level() == 15) {
  TP->set_title("the "+HIM+"Despiser "+NORM+"of "+HIY+"Sunrise"+NORM);
  return 1; }

if(TP->query_extra_level() == 14) {
  if(TP->query_gender() == "male") {
    TP->set_title("the "+BOLD+"Prince of Darkness"+NORM);
    return 1; }
  if(TP->query_gender() == "female") {
    TP->set_title("the "+BOLD+"Princess of Darkness"+NORM);
    return 1; }
}

if(TP->query_extra_level() == 13) {
  TP->set_title("the "+BOLD+"Dark"+GRY+" Shapechanger"+NORM);
  return 1; }

if(TP->query_extra_level() == 12) {
  if(TP->query_gender() == "male") {
    TP->set_title("the "+HIM+"Highpriest"+NORM+" of "+BOLD+"Shadows"+NORM);
    return 1; }
  if(TP->query_gender() == "female") {
    TP->set_title("the "+HIM+"Highpriestess"+NORM+" of "+BOLD+
                  "Shadows"+NORM);
    return 1; }
}

if(TP->query_extra_level() == 11) {
  if(TP->query_gender() == "male") {
    TP->set_title("the "+GRY+"Master"+NORM+" of "+GRY+"Dark Elements"+NORM);
    return 1; }
  if(TP->query_gender() == "female") {
    TP->set_title("the "+GRY+"Mistress"+NORM+" of "+GRY+
                  "Dark Elements"+NORM);
    return 1; }
}

if(TP->query_extra_level() == 10) {
  if(TP->query_gender() == "male") {
    TP->set_title("the "+HIB+"Living Dead"+NORM+" Highlord");
    return 1; }
  if(TP->query_gender() == "female") {
    TP->set_title("the "+HIB+"Living Dead"+NORM+" Highlady");
    return 1; }
}

if(TP->query_extra_level() == 9) {
  TP->set_title("the "+HIY+"Mind"+HIC+" Magician"+NORM);
  return 1; }

if(TP->query_extra_level() == 8) {
  TP->set_title("the "+RED+"Commander"+NORM+" of "+BOLD+"Darkness"+NORM);
  return 1; }

if(TP->query_extra_level() == 7) {
  if(TP->query_gender() == "male") {
    TP->set_title("the "+HIM+"Baron of Blood"+NORM);
    return 1; }
  if(TP->query_gender() == "female") {
    TP->set_title("the "+HIM+"Baroness of Blood"+NORM);
    return 1; }
}

if(TP->query_extra_level() == 6) {
  if(TP->query_gender() == "male") {
    TP->set_title("the "+GRY+"Master"+NORM+" of the "+GRY+"Night"+NORM);
    return 1; }
  if(TP->query_gender() == "female") {
    TP->set_title("the "+GRY+"Mistress"+NORM+" of the "+GRY+"Night"+NORM);
    return 1; }
}

if(TP->query_extra_level() == 5) {
  TP->set_title("the "+HIM+"fanged"+HIR+" Assassin"+NORM);
  return 1; }

if(TP->query_extra_level() == 4) {
  TP->set_title("the "+GRY+"Adept"+NORM+" of "+HIM+"Night"+HIR+"mares"+
                NORM);
  return 1; }

if(TP->query_extra_level() == 3) {
  TP->set_title("the "+GRY+"Soldier "+NORM+"of "+HIM+"Bloodlust"+NORM);
  return 1; }

if(TP->query_extra_level() == 2) {
  TP->set_title("the "+HIB+"Guardian"+NORM+" of the "+BOLD+
                "Dark Cult"+NORM);
  return 1; }

if(TP->query_extra_level() == 1) {
  TP->set_title("the "+GRY+"Adept"+RED+" of "+BOLD+"Shadows"+NORM);
  return 1; }

if(TP->query_level() == 19) {
  if(TP->query_gender() == "male") {
    TP->set_title("the "+HIB+"Master"+NORM+" of "+HIR+"Bloodletting"+
                  NORM);
    return 1; }
  if(TP->query_gender() == "female") {
    TP->set_title("the "+HIB+"Mistress"+NORM+" of "+HIR+"Bloodletting"+
                  NORM);
    return 1; }
}

if(TP->query_level() == 18) {
  TP->set_title("the "+CYN+"Collector"+NORM+" of "+CYN+
                "Wayward Souls"+NORM);
  return 1; }

if(TP->query_level() == 17) {
  TP->set_title("the "+RED+"Seeker of New "+HIR+"Blood"+NORM);
  return 1; }

if(TP->query_level() == 16) {
  TP->set_title("the "+BLU+"Disciple of "+CYN+"Illusion"+NORM);
  return 1; }

if(TP->query_level() == 15) {
  TP->set_title("the "+MAG+"Cold Wind"+NORM+" Apprentice");
  return 1; }

if(TP->query_level() == 14) {
  TP->set_title("the "+YEL+"Seeker"+NORM+" of the "+BLU+"Storm"+NORM);
  return 1; }

if(TP->query_level() == 13) {
  TP->set_title("the "+HIG+"Child "+NORM+"of the Shadows");
  return 1; }

if(TP->query_level() == 12) {
  TP->set_title("the "+MAG+"Follower of the "+NORM+"Dark "+MAG+
                "Path"+NORM);
  return 1; }

if(TP->query_level() == 11) {
  TP->set_title("the Apprentice of "+CYN+"Lost Souls"+NORM);
  return 1; }

if(TP->query_level() == 10) {
  TP->set_title("of the "+MAG+"Living Dead"+NORM);
  return 1; }

if(TP->query_level() == 9) {
  TP->set_title("the "+YEL+"Walker"+NORM+" of Dark Mists");
  return 1; }

if(TP->query_level() == 8) {
  TP->set_title("the Initiate of "+CYN+"Moonless"+NORM+" Nights");
  return 1; }

if(TP->query_level() == 7) {
  TP->set_title("the "+RED+"Disciple of Blood"+NORM);
  return 1; }

if(TP->query_level() == 6) {
  TP->set_title("the Palid Creature of Night");
  return 1; }

if(TP->query_level() == 5) {
  TP->set_title("the Compadre of Darkness");
  return 1; }

if(TP->query_level() == 4) {
  TP->set_title("the Seeker of Eternal Life");
  return 1; }

}

show_titles(str) {
if(!str) {
write(
"  Level           Title\n"+
"____________________________________________________________\n"+
"    4           the Seeker of Eternal Life\n"+
"    5           the Compadre of Darkness\n"+
"    6           the palid Night Creature\n"+
"    7           the Disciple of Blood\n"+
"    8           the Initiate of moonless nights\n"+
"    9           the Walker of the Dark Mists\n"+
"   10           of the Living Dead\n"+
"   11           the Apprentice of Lost Souls\n"+
"   12           the follower of the Dark Path\n"+
"   13           the Child of Shadows\n"+
"   14           the Seeker of the Storm\n"+
"   15           the Cold Wind Apprentice\n"+
"   16           the Disciple of Illusion\n"+
"   17           the Seeker of New Blood\n"+
"   18           the Collector of Wayward Souls\n"+
"   19           the Master/Mistress of Bloodletting\n\n");
return 1; }

if(str == "+") {
write(
"  Level           Title\n"+
"____________________________________________________________\n"+
"  + 1           the Adept of Shadows\n"+
"  + 2           the Guardian of the Dark Cult\n"+
"  + 3           the Soldier of Bloodlust\n"+
"  + 4           the Adept of Nightmares\n"+
"  + 5           the fanged Assassin\n"+
"  + 6           the Master/Mistress of the Night\n"+
"  + 7           the Baron/Baroness of Blood\n"+
"  + 8           the Commander of Darkness\n"+
"  + 9           the Mind Magician\n"+
"  +10           the Living Dead Highlord/Highlady\n"+
"  +11           the Master/Mistress of Dark Elements\n"+
"  +12           the Highpriest/Highpriestess of Shadows\n"+
"  +13           the Dark Shapechanger\n"+
"  +14           the Prince/Princess of Darkness\n"+
"  +15           the Despiser of Sunrise\n"+
"  +16           the Adept of Elements\n"+
"  +17           the Lord of Sorcery\n"+
"  +18           the Hellhound of Darkness\n"+
"  +19           the Dominator of Dark Shadows\n"+
"  +20           the Nocturnal Soul Hunter\n"+
"  +21           the Vampire Grandmaster/Grandmistress\n\n");
return 1; }
}

read(str) {
if(!str) { write("A voice whispers, 'Read what?'\n"); return 1; }
if(str == "plaque") { write(
RED+"Vampire Title Room\n\n"+
  "  This magical room will allow members of the vampire family to do\n"+
  "the following things:\n\n"+
  "   See lower level vampire titles: "+HIR+"show_titles"+NORM+RED+"\n"+
  "   See upper level vampire titles: "+HIR+"show_titles +"+NORM+RED+"\n"+
  "   Get an appropriate title: "+HIR+"fix_title"+NORM+RED+"\n\n"+
  "The vampire titles have evolved over time and should be proudly\n"+
  "displayed by anyone in the Vampire Guild.\n"+NORM+"\n");
return 1; }
}
