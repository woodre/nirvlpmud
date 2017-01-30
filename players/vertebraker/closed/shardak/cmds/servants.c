#define testers ({ "verte", "maledicta", "zeus", "wocket", "fakir", "boltar", "feldegast", "vertebraker", "vital", "reflex" })
/*
 * SERVANTS shows all registered guildmembers
 */
#pragma strict_types
#include "../def.h"
#include "../std.h"
inherit CMD;

status
main()
{
    string *noms, nom;
    int i, z, l;

    write("* S * H * A * R * D * A * K *   * A * S * S * A * S * S * I * N * S *\n");
    z = sizeof(noms = get_dir("/" + SAVE_PATH + "*.o"));
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
    write("* S * H * A * R * D * A * K *   * A * S * S * A * S * S * I * N * S *\n");
    return 1;
}
