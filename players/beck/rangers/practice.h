int backflip, block, run, scream, mercy, wheel, shiho_nage;
int irimi_nage, kaiten_nage, kote_gaeshi, ikkoyo;
int nikyo, sankyo, yonkyo, koshi_nage, tenchi_nage, juji_garami;
int aiki_otoshi, sumi_otoshi, kokyu_nage, aiki_nage;
int chop, butterfly, tickle, laugh, death, slap, scratch, throw;
int press, elbow;
int axe, punch;
set_defense_pro(str, arg){
if(str == "shiho-nage") shiho_nage = arg;
if(str == "irimi-nage") irimi_nage = arg;
if(str == "kaiten-nage") kaiten_nage = arg;
if(str == "kote-gaeshi") kote_gaeshi = arg;
if(str == "ikkyo") ikkoyo = arg;
if(str == "nikyo") nikyo = arg;
if(str == "sankyo") sankyo = arg;
if(str == "yonkyo") yonkyo = arg;
if(str == "koshi-nage") koshi_nage = arg;
if(str == "tenchi-nage") tenchi_nage = arg;
if(str == "juji-garami") juji_garami = arg;
if(str == "aiki-otoshi") aiki_otoshi = arg;
if(str == "sumi-otoshi") sumi_otoshi = arg;
if(str == "kokyu-nage") kokyu_nage = arg;
if(str == "aiki-nage") aiki_nage = arg;
if(str == "backflip") backflip = arg;
if(str == "block") block = arg;
if(str == "run") run = arg;
if(str == "scream") scream = arg;
if(str == "mercy") mercy = arg;
if(str == "wheel") wheel = arg;
return 1;
}
query_defense_pro(str){
if(str == "block") return block;
if(str == "backflip") return backflip;
if(str == "run") return run;
if(str == "scream") return scream;
if(str == "mercy") return mercy;
if(str == "wheel") return wheel;
if(str == "shiho-nage") return shiho_nage;
if(str == "irimi-nage") return irimi_nage;
if(str == "kaiten-nage") return kaiten_nage;
if(str == "kote-gaeshi") return kote_gaeshi;
if(str == "ikkyo") return ikkoyo;
if(str == "nikyo") return nikyo;
if(str == "sankyo") return sankyo;
if(str == "yonkyo") return yonkyo;
if(str == "koshi-nage") return koshi_nage;
if(str == "tenchi-nage") return tenchi_nage;
if(str == "juji-garami") return juji_garami;
if(str == "aiki-otoshi") return aiki_otoshi;
if(str == "sumi-otoshi") return sumi_otoshi;
if(str == "kokyu-nage") return kokyu_nage;
if(str == "aiki-nage") return aiki_nage;
}
set_offense_pro(str, arg){
if(str == "chop") chop = arg;
if(str == "press") press = arg;
if(str == "butterfly") butterfly = arg;
if(str == "laugh") laugh = arg;
if(str == "tickle") tickle = arg;
if(str == "death") death = arg;
if(str == "slap") slap = arg;
if(str == "scratch") scratch = arg;
if(str == "throw") throw = arg;
if(str == "elbow") elbow = arg;
if(str == "axe") axe = arg;
if(str == "punch") punch = arg;
return 1;
}
query_offense_pro(str){
if(str == "chop") return chop;
if(str == "press") return press;
if(str == "butterfly") return butterfly;
if(str == "laugh") return laugh;
if(str == "tickle") return tickle;
if(str == "death") return death;
if(str == "slap") return slap;
if(str == "scratch") return scratch;
if(str == "throw") return throw;
if(str == "elbow") return elbow;
if(str == "axe") return axe;
if(str == "punch") return punch;
}
