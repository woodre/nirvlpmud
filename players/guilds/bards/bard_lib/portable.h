/*
 * because the Amylaar efuns have consistent names
 * well.. sort of
 * and m_values suck big time
 */
#ifndef __VERSION__
#define mappingp(m) mapp(m)
#define m_indices(m) keys(m)
#define copy_mapping(m) m
#define m_delete(m,i) deletem(m,i)
#define this_interactive() this_player(1)
#endif
