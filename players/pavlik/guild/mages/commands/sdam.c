inherit "players/pavlik/guild/mages/inherit/command";
#include "/players/pavlik/guild/mages/defs.h"
#include "../include/string.h"

string *valid_types;

reset(arg) {
  int i;
  if(arg) return;
  set_verb("sdam");
  set_name("Spell Damage");
  set_color_name(HIC+"Spell Damage"+NORM);
  set_rank(71);
  set_descrip(
"The spell damage command will allow you to modify the\n\
type of damage you focus your powers on. This command is\n\
only for players of high prestige and max guild level. For\n\
each level of prestige an additional damage type is unlocked.\n"
  );
  valid_types = ({ });
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
    siz = sizeof(DTYPES);
    print_header();
    for( i=0; i < siz && i < plev; i++ ) {
     write("     " +pad(i,15) + DTYPES[i][2] + DTYPES[i][1]+NORM+"\n");
    }
    write( query_footer() + "\n" +NORM );
  return 1;
  }
  if( !valid_types || !sizeof(valid_types) ) {
    for(i =0; i < sizeof(DTYPES); i++ ) {
      valid_types += ({ DTYPES[i][1] });
    }
  }

  siz = member( valid_types, capitalize(str) );
  if( !guild || siz < 0 || siz + 1 > plev ) {
    write("You fail to concentrate your powers to use "+capitalize(str)+".\n");
    return 1;
  } 
  guild->set_spell_dtype( siz );
  write("You concentrate your "+rancol2("Magic")+" powers on "+DTYPES[siz][2]+DTYPES[siz][1]+" damage.\n"+NORM);
  return 1;
}

print_header()
{
  write(CYN+ pad("Pres Level", 15) + "Spell Damage Type\n" + query_footer() + "\n"+NORM);
}

query_footer() {
  return CYN+pad("",70,'~');
}
