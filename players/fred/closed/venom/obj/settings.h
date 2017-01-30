
drop() { return 1; }
get()  { return 1; }

query_weight() { return 0; }
query_value()  { return 0; }

add_pk(int i)                { total_pks += i; }
add_pk_level(int i)          { total_level_pks += i; }

set_symbiote(string x)       { symb_name = x; }
query_symbiote()             { return symb_name; }

query_venomed()              { return venomed; }
set_venomed(int i)           { venomed = i; }

query_burnoff()              { return burnoff; }
set_burnoff(int i)           { burnoff = i; }

query_hyper_mode()           { return hyper_mode; }
set_hyper_mode(int i)        { hyper_mode = i; }
add_hyper_mode(int i)        { hyper_mode += i; }

query_mp()                   { return mp; }
set_mp(int i)                { mp = i; }
add_mp(int i)                { mp += i;
                               if(mp >= 300)
                               mp = 300; }

query_shaped()               { return shaped; }
set_shaped(int i)            { shaped = i; }

query_hardened()             { return hardened; }
set_hardened(int i)          { hardened = i; }

query_uncovered()            { return uncovered; }
set_uncovered(int i)         { uncovered = i; }

query_bite_delay()           { return bite_delay; }
set_bite_delay(int i)        { bite_delay = i; }
add_bite_delay(int i)        { bite_delay += i; }

query_webf_delay()           { return webf_delay; }
set_webf_delay(int i)        { webf_delay = i; }
add_webf_delay(int i)        { webf_delay += i; }

query_anti_webs()            { return anti_webs; }
set_anti_webs(int i)         { anti_webs = i; }
add_anti_webs(int i)         { anti_webs += i; }

query_shapetype()            { return shapetype; }
set_shapetype(string str)    { shapetype = str; }

query_no_harden()            { return no_harden; }
set_no_harden(int i)         { no_harden = i; }
add_no_harden(int i)         { no_harden += i; }

query_hb_count()             { return hb_count; }
set_hb_count(int i)          { hb_count = i; }
add_hb_count(int i)          { hb_count += i; }

query_regen()                { return regen; }
set_regen(int i)             { regen = i; }

query_best_xp_score()        { return best_xp_score; }
set_best_xp_score(int i)     { best_xp_score = i; }

query_best_xp_name()         { return best_xp_name; }
set_best_xp_name(string str) { best_xp_name = str; }       

query_stored_mon()           { return stored_mon; }
set_stored_mon(int i)        { stored_mon = i; }
add_stored_mon(int i)        { stored_mon += i;}

query_oldtitle()             { return oldtitle; }
set_oldtitle(string str)     { oldtitle = str; }

query_oldalign()             { return oldalign; }
set_oldalign(string str)     { oldalign = str; }

query_oldpretitle()          { return oldpretitle; }
set_oldpretitle(string str)  { oldpretitle = str; }

query_bitestat()             { return bitestat; }
set_bitestat(int i)          { bitestat = i; }
add_bitestat(int i)          { bitestat += i; }

query_slamstat()             { return slamstat; }
set_slamstat(int i)          { slamstat = i; }
add_slamstat(int i)          { slamstat += i; }

query_absorbstat()           { return absorbstat; }
set_absorbstat(int i)        { absorbstat = i; }
add_absorbstat(int i)        { absorbstat += i; }

query_shapestat()            { return shapestat; }
set_shapestat(int i)         { shapestat = i; }
add_shapestat(int i)         { shapestat += i; }

query_burnstat()             { return burnstat; }
set_burnstat(int i)          { burnstat = i; }
add_burnstat(int i)          { burnstat += i; }

query_hyperstat()            { return hyperstat; }
set_hyperstat(int i)         { hyperstat = i; }
add_hyperstat(int i)         { hyperstat += i; }

query_changestat()           { return changestat; }
set_changestat(int i)        { changestat = i; }
add_changestat(int i)        { changestat += i; }

query_old_exp()              { return old_exp; }
set_old_exp(int i)           { old_exp = i; }

query_player_short()         { return player_short; }
set_player_short(string str) { player_short = str; }

query_has_changed()          { return has_changed; }
set_has_changed(int i)       { has_changed = i; }
