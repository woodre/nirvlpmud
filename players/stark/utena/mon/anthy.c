inherit "/obj/monster";
#include "/players/stark/defs.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("Himemiya Anthy");
    set_short("Himemiya Anthy");
    set_alias("anthy");
    set_alt_name("himemiya");
    set_gender("female");

set_level(1);
set_hp(10000);
set_al(1000);
set_wc(50);
set_ac(50);
set_no_clean(1);
set_aggressive(0);

set_chat_chance(3);
load_chat("Anthy tends to her roses.\n");
load_chat("Anthy looks around for ChuChu.\n");
load_chat("Anthy waters a rose slowly.\n");
load_chat("Anthy sighs quietly.\n");
load_chat("Anthy looks at you and smiles.\n");
set_a_chat_chance(50);
load_a_chat("If you can see this you're a cheater\n");

    set_long(
"Himemiya Anthy is a female student at Ohtori Academy.  She wears the \n"+
"school's traditional fuku (uniform):  A white blouse with fluffy \n"+
"sleeves tucked neatly into a green and white pleated skirt, knee high \n"+
"socks and a big red bow tied at her neck.  Her plum coloured hair is \n"+
"parted down the middle and seems short.  But a well hidden length of \n"+
"hair is bunned up on the sides.  Her dark tanned skin harkens to her \n"+
"Indian roots.  She wears a pair of simple framed glasses.  This is \n"+
"the key to Eternity, the tool that will crack the worlds shell...  \n"+
"The Rose Bride is the way to bring Revolution!\n");
}
