inherit "players/pavlik/guild/mages/inherit/command";
#include "/players/pavlik/guild/mages/defs.h"
#include "../include/string.h"

mixed *dtypes;
string *valid_types;

reset(arg) {
  int i;
  if(arg) return;
  set_verb("sdam");
  set_name("Spell Damage");
  set_color_name(HIC+"Spell Damage"+NORM);
  set_rank(70);
  set_descrip(
"The spell damage command will allow you to modify the\n\
type of damage you focus your powers on. This command is\n\
only for players of high prestige and max guild level.\n"
  );
  dtypes = ({ 
             ({ "magical", "Magic", NORM })
            ,({ "other|fire", "Fire", HIR })
            ,({ "other|ice", "Ice" , HIB })
            ,({ "other|evil", "Evil" , RED })
            ,({ "other|good", "Good" , HIW })
            ,({ "other|light", "Light" , HIY })
            ,({ "other|dark", "Dark" , HIK })
            ,({ "other|poison", "Poison" , HIG })
            ,({ "other|electric", "Electric" , YEL })
            ,({ "physical", "Physical" , NORM })
            ,({ "other|sonic", "Sonic" , HIM })
           });
  valid_types = ({ });
  for(i =0; i < sizeof(dtypes); i++ )
    valid_types += ({ dtypes[i][1] });
}


cmd(str)
{
  int i, siz, plev;

  plev = this_player()->query_prestige_level();
  if( !plev ) {
    write("You lack the required prestige to concentrate your powers.\n");
    return 1;
  }

  plev++;
  if(!str) {
    siz = sizeof(dtypes);
    print_header();
    for( i=0; i < siz && i < plev; i++ ) {
     write("     " +pad(i+1,15) + dtypes[i][2] + dtypes[i][1]+NORM+"\n");
    }
    write( query_footer() + "\n" +NORM );
  return 1;
  }
  siz = member( valid_types, capitalize(str) );
  if( !guild || siz < 0 || siz + 1 > plev ) {
    write("You fail to concentrate your powers to use "+capitalize(str)+".\n");
    return 1;
  } 
  guild->set_spell_dtype( dtypes[siz][0] );
  write("You concentrate your "+rancol2("Magic")+" powers on "+dtypes[siz][2]+dtypes[siz][1]+" damage.\n"+NORM);
  return 1;
}

print_header()
{
  write(CYN+ pad("Pres Level", 15) + "Spell Damage Type\n" + query_footer() + "\n"+NORM);
}

query_footer() {
  return CYN+pad("",70,'~');
}
