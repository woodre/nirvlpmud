 
#pragma strict_types
#pragma save_types

inherit "/players/vertebraker/closed/std/m_efuns";

void dump_mapping(mapping mp)
{
int i, sz;
    mixed ind, val;
    ind = m_indices(mp);
    val = m_values(mp);
    sz = sizeof(ind);
    for (i = 0 ; i < sz ; i++)
        write(sprintf("%O", ind[i]) + " corresponds to " + sprintf("%O", val[i]) + "\n");
}

