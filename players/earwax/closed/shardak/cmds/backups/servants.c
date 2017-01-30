#define testers ({ "verte", "maledicta", "zeus", "wocket", "fakir", "boltar", "feldegast", "vertebraker", "vital", "reflex" })
/*
 * SERVANTS shows all registered guildmembers
 */
#pragma strict_types
#include "../include/def.h"
#include "../include/std.h"

#include "../include/daemons.h"
inherit CMD;

status
main()
{
  string *output;
  int i, siz;

  output = (string*) HIERARCHYD->dump_members();

  siz = sizeof(output);

  for (i = 0; i < siz; i++)
    tell_object(this_player(),output[i]);


    /* replaced by earwax, with daemonized servants/hierarchy command 
    string *noms, nom;
    int i, z, l;
    write(RED+"* S * H * A * R * D * A * K *   * A * S * S * A * S * S * I * N * S *\n"+NORM);
    z = sizeof(noms = files("/" + SAVE_PATH + "*.o"));
    for (;i < z; i++) {
	sscanf(noms[i], "%s.o", nom);
	if (l >= 3) {
            if(member_array(nom, testers) == -1)
            {
	    write(capitalize(nom) + "\n");
	    l = 0;
            }
	}
	else {
            if(member_array(nom, testers) == -1)
            {
	    write(pad(capitalize(nom), 18));
	    l++;
            }
	}
    }
    if (l) write("\n");
    write(RED+"* S * H * A * R * D * A * K *   * A * S * S * A * S * S * I * N * S *\n"+NORM);
    
    end commented out portion - earwax */

    return 1;
}
