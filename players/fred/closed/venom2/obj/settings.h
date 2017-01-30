set_symbiote(str)                  { symbiote = str;    }
query_symbiote()                   { return symbiote;   }

set_sdelay(str)                    { sdelay = str;      }
query_sdelay()                     { return sdelay;     }

set_delay(int i)                   { delay = i;         }
query_delay()                      { return delay;      }

set_glvl(int i)                    { glvl = i;          }
add_glvl(int i)                    { glvl += i;         }
query_glvl()                       { return glvl;       }

add_stored_mp(int i)               { stored_mp += i;    }
query_stored_mp()                  { return stored_mp;  }

add_stored_sp(int i)               { stored_sp += i;    }
query_stored_sp()                  { return stored_sp;  }

add_stored_mon(int i)              { stored_mon += i;   }
query_stored_mon()                 { return stored_mon; }

set_mp(int i)                      { mp = i;            }
add_mp(int i)                      { mp += i;
                                     if(mp > max_mp)
                                     mp = max_mp;       }
query_mp()                         { return mp;         }
query_used_mp()                    { return used_mp;    }
query_max_mp()                     { return 300 + (query_glvl() * 10) - query_used_mp(); }

set_burnoff(int i)                 { burnoff = i;       }
query_burnoff()                    { return burnoff;    }

set_hyper(int i)                   { hyper = i;         }
query_hyper()                      { return hyper;      }
 
set_regen(int i)                   { regen = i;         }
query_regen()                      { return regen;      }
 
set_has_lair(int i)                { has_lair = i;      }
query_has_lair()                   { return has_lair;   }

set_lair(string str)               { lair = str;        }
query_lair()                       { return lair;       }
 
set_control(int i)                 { control = i;       }
add_control(int i)                 { control += i;      }
query_control()                    { return control;    }

set_combat(int i)                  { combat = i;        }
add_combat(int i)                  { combat += i;       }
query_combat()                     { return combat;     }

set_creation(int i)                { creation = i;      }
add_creation(int i)                { creation += i;     }
query_creation()                   { return creation;   }

set_t_burn(int i)                  { t_burn = i;        }
add_t_burn(int i)                  { t_burn += i;       }
query_t_burn()                     { return t_burn;     }

set_t_regen(int i)                 { t_regen = i;       }
add_t_regen(int i)                 { t_regen += i;      }
query_t_regen()                    { return t_regen;    }

set_t_attack(int i)                { t_attack = i;      }
add_t_attack(int i)                { t_attack += i;     }
query_t_attack()                   { return t_attack;   }

set_t_defend(int i)                { t_defend = i;      }
add_t_defend(int i)                { t_defend += i;     }
query_t_defend()                   { return t_defend;   }

set_pet(ob)                        { pet = ob;          }
query_pet()                        { return pet;        }                           

set_wep_damage(int i)              { wep_damage = i;    }
query_wep_damage()                 { return wep_damage; }

set_block(int i)                   { block = 1;         }
query_block()                      { return block;      }

set_body(int i)                    { body = i;          }
add_body(int i)                    { body += i;         }
query_body()                       { return body;       }

query_glvl_cost(int i)             { return (GLVLCOST[i] * 100000); }

add_sh_armor(string str)           { return sh_armor += ({ str, }); }
