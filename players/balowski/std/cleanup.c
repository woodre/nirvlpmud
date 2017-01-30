/*
 * Bit of a rip off. Inspiration: Foundation by George Reese
 * Remember to check on compat mode specifics..
 *      TRY_LATER should only be called under certain circumstances
 */
#pragma strict_types
#pragma save_types

private int     NoClean;
#define NEVER_AGAIN 0
#define TRY_LATER 1

int
clean_up(int refcount)
{
    object ob, env, *inv;
    int i;

    if (NoClean) return NEVER_AGAIN;
    if (refcount > 0) return TRY_LATER;

    /* this_object() is 0 if already dested */
    if (!(ob = this_object()) || ob->query_auto_load()) return NEVER_AGAIN;
    if ((env = environment()) && env->is_storage()) return TRY_LATER;

    i = sizeof(inv = deep_inventory(ob));
#ifdef __VERSION__
    /* bug in 3.1.2-DR: strict_types + array intersect = bad */
    if (sizeof(users() & inv)) return TRY_LATER;
#else
    while (i--)
        if (interactive(inv[i])) return TRY_LATER;
    i = sizeof(inv);
#endif
    if (!env) {
        while (i--)
            if (inv[i]) destruct(inv[i]);
        if (ob) ob->remove_object();
        if (ob) destruct(ob);
        return NEVER_AGAIN;
    }
    if (interactive(env)) return TRY_LATER;
    return (int) env->clean_up(-1);     /* hmm.. */
}

void
set_no_clean(int x)
{
    NoClean = x;
}
