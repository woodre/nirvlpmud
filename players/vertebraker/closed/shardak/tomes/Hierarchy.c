#include "../def.h"

inherit TOME;

void
reset(status arg)
{
    if(arg) return;
    ::reset();
    load_pages(TOMES + "Hierarchy/");
    title = "Hierarchy";
}
