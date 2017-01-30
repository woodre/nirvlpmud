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

#define funcall(c,a) ((mixed) call_other(c[0], c[1], a))
#define closurep(s) pointerp(s)
#define symbol_function(f,o) ({o,f})

#define replace_program(p)
#endif
