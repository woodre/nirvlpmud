string *female_names;

string *female_names2;

string *female_names3;

string *male_names;

string *male_names2;

string *male_names3;



reset(){

female_names = ({

"Aamiua",

"Aamiunda",

"Aamua",

"Aamunda",

"Aapelia",

"Aapelioba",

"Aapioa",

"Aapoa",

"Aappioa",

"Aappiopa",

"Aappoa",

"Aappopa",

"Aarela",

"Aarera",

"Aaresa",

"Aariela",

"Aariera",

"Aariesa",

"Aarinea",

"Aariofa",

"Aarnea",

"Aarnioda",

"Aarnoda",

"Aarofa",

"Aarrela",

"Aarriela",

"Aartioha",

"Aartoha",

"Aatamia",

"Aatiosa",

"Aatiusa",

"Aatosa",

"Aattiova",

"Aattova",

"Aatusa",

"Acadia",

"Ahtia",

"Ahtoa",

"Ahviota",

"Ailela",

"Ailioa",

"Ailiua",

"Ailua",

"Aimotha",

"Ainaisa",

"Ainionta",

"Ainolda",

"Airaisa",

"Airiova",

"Aithnea",

"Akioha",

"Akseliota",

"Akunda",

"Alainesa",

"Aleksiera",

"Aliisaisa",

"Alinaisa",

"Alinera",

"Allioza",

"Alposa",

"Alvaera",

"Amelia",

"Andriofa",

"Annaisa",

"Annesa",

"Annia",

"Annia",

"Anniaisa",

"Anoa",

"Anselmia",

"Ansia",

"Anssiopa",

"Anterofa",

"Anttiua",

"Anttonia",

"Arhonta",

"Aria",

"Armia",

"Artova",

"Artturioha",

"Arviolda",

"Arvotha",

"Askoba",

"Asmioda",

"Asmoda",

"Assera",

"Assiera",

"Astaisa",

"Astia",

"Atsosa",

"Augustiopa",

"Auisia",

"Aulaisa",

"Aulikkiera",

"Aulioza",

"Aunea",

"Aunoa",

"Auria",

"Auriela",

"Aurorusa",

"Auvoda",

"Ayamera",

"Bediliunda",

"Bedilunda",

"Carelia",

"Celestinesa",

"Delia",

"Delioba",

"Deloba",

"Dervilia",

"Eelaisa",

"Eemelia",

"Eemiela",

"Eerova",

"Eetiusa",

"Eetusa",

"Eevia",

"Eiela",

"Einaria",

"Einariena",

"Einera",

"Einesa",

"Einiera",

"Einiesa",

"Einiofa",

"Einofa",

"Eiria",

"Elenusa",

"Eliasea",

"Eliisia",

"Elinia",

"Ellia",

"Elmea",

"Elmeriova",

"Elmoda",

"Elsea",

"Elsia",

"Elsiaisa",

"Elviiria",

"Elviosa",

"Emalia",

"Emilia",

"Enniopa",

"Ensioa",

"Erkkia",

"Erkkova",

"Ernova",

"Esia",

"Eskolda",

"Essiusa",

"Esteriosa",

"Evadnesa",

"Fortia",

"Grania",

"Grazia",

"Hannusa",

"Harriena",

"Heikkiova",

"Heimota",

"Heiniunda",

"Heinonta",

"Helenia",

"Helioa",

"Helkaisa",

"Hellevia",

"Helliela",

"Helmiota",

"Helviotha",

"Hemminkia",

"Hemmonta",

"Hennia",

"Hennioha",

"Henrikkiera",

"Herkkova",

"Hermanniela",

"Herttia",

"Hetaisa",

"Hilkkea",

"Iinesa",

"Iiriosa",

"Iirova",

"Iivaria",

"Iivota",

"Ilariunda",

"Ilmariena",

"Ilmiusa",

"Ilmoda",

"Ilota",

"Ilpoa",

"Impiofa",

"Inkeria",

"Intosa",

"Ionesa",

"Irenea",

"Irmeliopa",

"Ismosa",

"Istoza",

"Jaakkoa",

"Jaliosa",

"Jalmaria",

"Jaria",

"Jarmioa",

"Jessera",

"Joela",

"Jonia",

"Joonaisa",

"Joukoda",

"Jounioda",

"Juhanioba",

"Jussiofa",

"Juusoba",

"Jyrioha",

"Jyrkiopa",

"Kaapoha",

"Kaarlova",

"Kaia",

"Kainoa",

"Kaiota",

"Kalervotha",

"Kaleviusa",

"Kallesa",

"Kanervia",

"Karelia",

"Karia",

"Karriolda",

"Kasperionta",

"Katrionta",

"Kaukoza",

"Kaunosa",

"Keijoba",

"Keimoda",

"Kerkkofa",

"Kerttua",

"Kieloha",

"Kimmopa",

"Kirsioba",

"Kirstioda",

"Klaaria",

"Konstia",

"Kostiofa",

"Kuismea",

"Kullervoa",

"Kustia",

"Kyllikkiusa",

"Kyostiunda",

"Laria",

"Lauhia",

"Launolda",

"Lauria",

"Lauriusa",

"Lea",

"Leea",

"Leena",

"Leeviunda",

"Leilia",

"Lempiotha",

"Lenia",

"Linnea",

"Livia",

"Lucia",

"Lydia",

"Lyydia",

"Lyyliolda",

"Maariota",

"Mainia",

"Mainionta",

"Mairena",

"Manusa",

"Mariaisa",

"Marioba",

"Markkusa",

"Markoda",

"Markusia",

"Marttia",

"Marttiova",

"Matiaisa",

"Mattioha",

"Maunoha",

"Maunusa",

"Mauriusa",

"Meeriofa",

"Merioza",

"Mervia",

"Mielikkiopa",

"Miia",

"Mikia",

"Mikkota",

"Minttusa",

"Natalia",

"Nathalia",

"Nea",

"Nestoria",

"Nevraelia",

"Niiloa",

"Nikopa",

"Nooria",

"Nuuttia",

"Nyyrikkia",

"Odilai",

"Ohtolda",

"Oilia",

"Oivaisa",

"Oiviosa",

"Olavia",

"Olliunda",

"Oneriova",

"Onnia",

"Oonea",

"Orvokkia",

"Orvota",

"Oskaria",

"Osmoa",

"Ossiena",

"Othilia",

"Otsosa",

"Ottilia",

"Ottotha",

"Outiela",

"Paavoa",

"Paivikkioda",

"Paivioa",

"Palviena",

"Panua",

"Pasiua",

"Paulia",

"Pauliova",

"Pekkea",

"Pellervoha",

"Penttia",

"Perchia",

"Perttiunda",

"Perttusa",

"Petria",

"Petrioa",

"Pietariela",

"Piia",

"Pilviera",

"Pirjoha",

"Pirkkesa",

"Pirkkolda",

"Pulmusa",

"Railiesa",

"Raimosa",

"Rainena",

"Rainera",

"Raisa",

"Raitia",

"Ramiopa",

"Rauhela",

"Rauliofa",

"Raunea",

"Rauniosa",

"Raunoa",

"Reetela",

"Reijoa",

"Reimia",

"Reinoda",

"Rekoba",

"Riikkia",

"Riittia",

"Rikua",

"Ristotha",

"Ritvia",

"Roosia",

"Ruususa",

"Saimia",

"Sainiera",

"Sakariova",

"Sakua",

"Salliofa",

"Salmea",

"Samia",

"Sampota",

"Sampsea",

"Samulia",

"Sanelmioa",

"Sannaisa",

"Santeriena",

"Sariolda",

"Satunda",

"Saulia",

"Sennia",

"Seppova",

"Severia",

"Siirioba",

"Silvotha",

"Simonta",

"Sinikkia",

"Siniua",

"Sipioha",

"Sippoha",

"Slania",

"Soilena",

"Soilia",

"Soiniova",

"Sointusa",

"Suleviena",

"Suloha",

"Suomia",

"Suvioda",

"Sylviofa",

"Taavettiunda",

"Tahvionia",

"Taimiusioa",

"Tainianofa",

"Taistosea",

"Taitosioba",

"Talvikkiasia",

"Tanelionoha",

"Tapanianotha",

"Tapioldua",

"Tarmopiova",

"Tarusia",

"Tarvionia",

"Tatusiofa",

"Taunohiopa",

"Teemusea",

"Teijosolda",

"Tellervo",

"Tenholdua",

"Teppovioa",

"Terhia",

"Terhoa",

"Teroa",

"Terttua",

"Teuvoa",

"Tiia",

"Tiinia",

"Timoa",

"Tittia",

"Toinia",

"Toiniofa",

"Toivofa",

"Toniova",

"Topiaisa",

"Topiania",

"Torstiota",

"Toukosiopa",

"Tuirena",

"Tuomia",

"Tuomotha",

"Tuoviotha",

"Turosia",

"Tuulia",

"Tuulikkiena",

"Tyttiosa",

"Tyynera",

"Ukkopa",

"Ulpusa",

"Unelmioa",

"Untova",

"Urhoda",

"Urmasiova",

"Urpova",

"Ursulia",

"Uskota",

"Uunotha",

"Valionia",

"Valmianofa",

"Valolda",

"Valtopa",

"Valtteriova",

"Vanamoiova",

"Vappusa",

"Varmianoha",

"Varpunda",

"Vaulia",

"Veeria",

"Veijosa",

"Veikkoza",

"Veiniota",

"Veliosa",

"Vellamosa",

"Venlia",

"Verneria",

"Vernia",

"Vesia",

"Vienia",

"Vienoa",

"Vihtoria",

"Viivia",

"Vilhoa",

"Viljoa",

"Villena",

"Vilmia",

"Vilppua",

"Virpia",

"Virvera",

"Virvia",

"Visia",

"Voittotha",

"Vuokkosa",

"Wynisia",

"Xenia",

"Ylermia",

"Yrjosa",});



male_names = ({

"Aamund",

"Aapelian",

"Aapos",

"Aapob",

"Aapod",

"Aapof",

"Aapov",

"Aapot",

"Aapoz",

"Aappoh",

"Aarnen",

"Aarnenian",

"Aarnod",

"Aarob",

"Aarren",

"Aarrianen",

"Aartod",

"Aatamius",

"Aatos",

"Aattoh",

"Aatund",

"Ahtian",

"Ahtod",

"Ahvoh",

"Ailius",

"Aimoz",

"Ainian",

"Ainod",

"Airian",

"Akius",

"Akselian",

"Akunden",

"Allion",

"Almain",

"Alpoh",

"Alpohen",

"Alpohianen",

"Alpohainen",

"Alpohenain",

"Alpohenian",

"Alvaren",

"Andrellus",

"Annian",

"Anos",

"Anosen",

"Anosian",

"Anosain",

"Anosianen",

"Anosainen",

"Anosenian",

"Anselmius",

"Anssion",

"Anterof",

"Anttion",

"Anttonius",

"Archbold",

"Arhoh",

"Arhohius",

"Arion",

"Armius",

"Armian",

"Armenian",

"Armiusen",

"Arnon",

"Arnonen",

"Artoh",

"Artohian",

"Artturian",

"Artur",

"Arturian",

"Arvian",

"Arvius",

"Arvenian",

"Arvod",

"Askov",

"Asmof",

"Asmofen",

"Asmofian",

"Asperdian",

"Asperdius",

"Asperdion",

"Asser",

"Asserion",

"Astain",

"Asten",

"Astian",

"Atsod",

"Augustian",

"Augusten",

"Augustenion",

"Aulion",

"Aulen",

"Aulenion",

"Aulianen",

"Aulikkion",

"Aulis",

"Aunen",

"Aunof",

"Aurian",

"Auvod",

"Belarion",

"Berlikion",

"Belfarlen",

"Belfarlion",

"Belfarlius",

"Belfarlian",

"Belgeous",

"Belinod",

"Belver",

"Bennel",

"Bestmion",

"Brander",

"Caspian",

"Carwenden",

"Celestian",

"Ceril",

"Cilber",

"Clementian",

"Crispen",

"Crispenian",

"Crispeous",

"Crispeousen",

"Crispian",

"Crispion",

"Crivian",

"Cronion",

"Cuenel",

"Damalinion",

"Dartiun",

"Delleb",

"Dilweg",

"Draxian",

"Dunstian",

"Edvarden",

"Eelais",

"Eemelion",

"Eemil",

"Eerod",

"Eetus",

"Eeverten",

"Einarion",

"Einen",

"Einian",

"Einoz",

"Eldubrais",

"Elias",

"Ellius",

"Elmain",

"Elmerias",

"Elmo",

"Elmof",

"Elsian",

"Elvian",

"E'munden",

"Ennianen",

"Ension",

"Erharten",

"Errken",

"Errkenian",

"Erkkian",

"Erkkion",

"Ernoh",

"Ernohen",

"Erythnul",

"Eskod",

"Essian",

"Esterius",

"Estwarden",

"Ewerden",

"Farlanden",

"Fharlanghn",

"Finelann",

"Formen",

"Franz",

"Franzos",

"Galen",

"Galssonian",

"Gartrel",

"Gellcov",

"Gregorof",

"Grenel",

"Greven",

"Grevenian",

"Hannund",

"Harnnanden",

"Harrian",

"Hazen",

"Hazendel",

"Heikkian",

"Heimod",

"Heironeous",

"Helius",

"Hellevian",

"Hellian",

"Helmian",

"Helvion",

"Hemminkian",

"Hemmold",

"Hennien",

"Henrikkiund",

"Herkkos",

"Hermannion",

"Hermod",

"Hexter",

"Hexten",

"Holmer",

"Hughen",

"Ignias",

"Iines",

"Iirias",

"Iirion",

"Iivarian",

"Iivold",

"Ilarius",

"Ilmarian",

"Ilmien",

"Ilmoth",

"Ilpold",

"Ilppoh",

"Ilppohen",

"Ilppohian",

"Impien",

"Ingerskattion",

"Inkerian",

"Intoth",

"Irmelian",

"Isedrian",

"Ismoth",

"Isrilhan",

"Istold",

"Ivid",

"Ividen",

"Jaakkold",

"Jalmarian",

"Jalion",

"Jarias",

"Jarmoth",

"Jemain",

"Jessen",

"Jian",

"Jianen",

"Jianius",

"Jiranen",

"Jonian",

"Joonais",

"Joukos",

"Joukosian",

"Jounien",

"Juhanies",

"Jussion",

"Justen",

"Justenian",

"Juusold",

"Jyrian",

"Jyrkius",

"Jyssion",

"Kaapoth",

"Kaarlion",

"Kain",

"Kainen",

"Kainenian",

"Kainion",

"Kalervion",

"Kalevien",

"Kalle",

"Kanerva",

"Karenin",

"Karion",

"Karian",

"Karienen",

"Karius",

"Karnen",

"Karrian",

"Kasperias",

"Katrion",

"Kaukion",

"Kaunoth",

"Keijold",

"Keimoth",

"Kerkkion",

"Kerttus",

"Kevont",

"Kieleous",

"Killian",

"Kimbertos",

"Kimmont",

"Kirsian",

"Kirstien",

"Kostion",

"Kristian",

"Kullervont",

"Kurell",

"Kurellen",

"Kyllikkian",

"Kyostien",

"Larapel",

"Larien",

"Larian",

"Larius",

"Lariund",

"Larrangen",

"Lashtont",

"Latavius",

"Latimer",

"Launold",

"Launolden",

"Laurian",

"Leevion",

"Lempion",

"Leous",

"Leoth",

"Leothen",

"Leold",

"Luther",

"Lutheren",

"Lylen",

"Lynester",

"Lynwerd",

"Lynwerden",

"Lyylian",

"Maarot",

"Maarotian",

"Magnus",

"Magnius",

"Magnusen",

"Mainian",

"Mainioth",

"Mairen",

"Malev",

"Maleven",

"Manshen",

"Manus",

"Marcos",

"Marcosen",

"Marcoth",

"Marcold",

"Margus",

"Marius",

"Markkul",

"Markod",

"Markos",

"Markus",

"Marttian",

"Mathen",

"Mathenian",

"Mathainen",

"Matias",

"Mattius",

"Maunont",

"Maunul",

"Maurion",

"Medven",

"Medvenian",

"Meerian",

"Menarion",

"Menion",

"Menreth",

"Meront",

"Merias",

"Mervien",

"Mielikkian",

"Mikkold",

"Minttus",

"Melul",

"Melulen",

"Myariken",

"Nalef",

"Nasren",

"Nasrenen",

"Nestorion",

"Niiloth",

"Nikos",

"Nuuttian",

"Nyyrikkien",

"Ogen",

"Ogenian",

"Ogenion",

"Ohtoth",

"Oilion",

"Oivian",

"Olavius",

"Ollion",

"Onnian",

"Orvont",

"Orvokkien",

"Oskarian",

"Osmont",

"Ossian",

"Otsos",

"Ottoh",

"Outian",

"Owen",

"Owenian",

"Paavold",

"Paivian",

"Paivikkius",

"Palvius",

"Panus",

"Parmus",

"Pasias",

"Pellervont",

"Penttias",

"Perttien",

"Perttus",

"Petri",

"Pholtus",

"Pietarien",

"Pilvian",

"Pirjold",

"Pirkkos",

"Piter",

"Portillen",

"Procen",

"Procain",

"Procainen",

"Pulmus",

"Railius",

"Raimos",

"Rainen",

"Rakehell",

"Rakehellen",

"Ramion",

"Raulien",

"Raunius",

"Raunont",

"Regurd",

"Reijoth",

"Reinold",

"Rekos",

"Retoff",

"Rikus",

"Ristold",

"Ristont",

"Rogen",

"Rogainen",

"Romadnen",

"Rusus",

"Ruusius",

"Ruutain",

"Saimion",

"Sainius",

"Sakarius",

"Sakus",

"Salmen",

"Samiund",

"Sampor",

"Samulian",

"Santerius",

"Santhain",

"Sarian",

"Satarchian",

"Satul",

"Saulian",

"Selwerd",

"Senchos",

"Sennien",

"Seppont",

"Serian",

"Severi",

"Sewarndten",

"Seywerd",

"Siirian",

"Silchus",

"Silvos",

"Simod",

"Sinion",

"Sipian",

"Sippos",

"Siskos",

"Soilen",

"Soilian",

"Soinias",

"Sointus",

"Sulevian",

"Sulont",

"Suvias",

"Svenser",

"Sylvius",

"Taavettian",

"Tahvold",

"Taimien",

"Taistion",

"Taiteous",

"Talvikkion",

"Tanelius",

"Tapanian",

"Tapion",

"Tarmont",

"Tarus",

"Tarvold",

"Tatul",

"Taunoh",

"Teemus",

"Teijos",

"Telchur",

"Tellervont",

"Tenhos",

"Teppot",

"Terhian",

"Terheous",

"Terov",

"Terttu",

"Teuvof",

"Thorion",

"Thrommel",

"Timos",

"Toinion",

"Toivont",

"Tonion",

"Topian",

"Topias",

"Toren",

"Torenen",

"Torainen",

"Torstian",

"Toukoz",

"Tuiren",

"Tuomes",

"Tuomias",

"Tuomos",

"Tuovias",

"Tureous",

"Tuulian",

"Tuulikkien",

"Tyttian",

"Tyynen",

"Ukkos",

"Ulpul",

"Untoin",

"Usko",

"Uunold",

"Vainod",

"Vainoen",

"Vainot",

"Valion",

"Valeous",

"Valtont",

"Valtterien",

"Vanamos",

"Vannoin",

"Vappus",

"Varpius",

"Veijov",

"Veikkion",

"Veinian",

"Velius",

"Vellamion",

"Velneous",

"Velnius",

"Venitos",

"Vernerian",

"Vienof",

"Vihtorian",

"Viivian",

"Vilheous",

"Viljoen",

"Villen",

"Vilppus",

"Virpian",

"Virven",

"Voitteous",

"Vuokkold",

"Weynoud",

"Wolsten",

"Ylermian",

"Yrjoen",

"Zilchus",});



male_names2 = ({

"Aanon",

"Abigo",

"Abigor",

"Abinol",

"Abiron",

"Acain",

"Acas",

"A'cas",

"Acayn",

"Achim",

"Acir",

"A'cir",

"Ackys",

"Acmon",

"Acmorn",

"Acrar",

"Acras",

"Acryn",

"Acrys",

"Adaic",

"Adair",

"A'dan",

"Adaym",

"Adin",

"Adin",

"A'din",

"Adkyn",

"Admo",

"Admor",

"Admorn",

"Adran",

"Adrath",

"Adrir",

"Adryn",

"aecay",

"aecys",

"aedic",

"aedyn",

"aelac",

"aemath",

"aemox",

"aenas",

"aenym",

"Aeodacay",

"Aeodamic",

"Aeodanath",

"Aeodasar",

"Aeodayas",

"Aeodican",

"Aeodiram",

"Aeodisad",

"Aeodokir",

"Aeodolys",

"Aeodomin",

"Aeodonyn",

"Aeodornich",

"Aeodorym",

"Aeodymac",

"Aerar",

"Aerorn",

"Aesan",

"Aeso",

"Aetham",

"Aethir",

"Aeyad",

"Aeyin",

"Agaral",

"Agathon",

"Agenor",

"Agirys",

"Agolas",

"Agynis",

"Aidan",

"Aikman",

"Aino",

"A'kath",

"Akmar",

"Aladar",

"Alaric",

"Alastor",

"Alays",

"Alberich",

"Albin",

"Alcan",

"Aldegond",

"Aldis",

"Aldrich",

"Aldro",

"Algernon",

"Aliam",

"Aliar",

"Aliath",

"Aliay",

"Allvar",

"Almas",

"Almox",

"Almox",

"Alnard",

"Aloac",

"Aload",

"Aloas",

"Alocad",

"Alocor",

"Aloir",

"Alolas",

"Alomar",

"Alras",

"Alrys",

"Altragic",

"Altragyn",

"Altrigin",

"Altrigys",

"Altrogan",

"Altrogir",

"Alvan",

"Alyan",

"A'mad",

"Amic",

"A'mic",

"Amicthis",

"Aminthys",

"Amirthas",

"Amkir",

"Amrad",

"Amrar",

"Amrin",

"Amrym",

"Amvath",

"A'nac",

"Aneurin",

"Ankin",

"Anmol",

"Anram",

"Anran",

"Anric",

"Anrir",

"Antal",

"Antor",

"Antrim",

"Anvic",

"Anvo",

"A'nyn",

"Aomo",

"Apad",

"Arano",

"Arasorn",

"Ardal",

"Aretas",

"Ariad",

"Arlo",

"Armin",

"Armon",

"Arno",

"Aron",

"Artol",

"Arvad",

"Arvin",

"Arvys",

"Aryn",

"Arys",

"A'rys",

"Askic",

"Asmol",

"Asram",

"Asray",

"Asrin",

"Asto",

"Astorghan",

"Asvyn",

"Athmo",

"Athol",

"Athrac",

"Athrad",

"Athrich",

"Athvir",

"Aubacom",

"Audaco",

"Auldor",

"Aunac",

"Aundo",

"Aurdon",

"Avan",

"Avano",

"Avas",

"Avathol",

"Aymo",

"Ayrac",

"Ayrath",

"Ayray",

"Ayvan",

"Azaecan",

"Azaedar",

"Azael",

"Azaenath",

"Azaero",

"Baca'yn",

"Bacgryn",

"Bacphegon",

"Bacva'yn",

"B'acvoryn",

"Bada'ir",

"Badgrir",

"Badphegol",

"Badva'ir",

"B'advorir",

"Baelaan",

"Baelvor",

"Bala'ys",

"Baldor",

"Balfarlan",

"Balgrys",

"Balinor",

"Ballva'an",

"B'allvoran",

"B'alon",

"Balotar",

"Balphegor",

"Bama'in",

"Bamgrin",

"B'amol",

"Bamphego",

"Bamva'in",

"B'amvorin",

"Bana'ic",

"Bangric",

"Banial",

"B'anor",

"Banva'ys",

"B'anvorys",

"Bara'ath",

"Bardach",

"Bargrath",

"Barlikyn",

"Barnas",

"Barron",

"Barva'ic",

"B'arvorik",

"Barzhaan",

"Basa'as",

"Batha'ar",

"Bathgras",

"B'atho",

"Bathym",

"Baya'an",

"Baygran",

"Bercan",

"Birath",

"Boca'ac",

"Bodil",

"Bola'an",

"Bona'am",

"Bora'ad",

"Botho",

"Brioch",

"Brocad",

"Brodan",

"Broir",

"Brol",

"Brolay",

"Brolo",

"Bromar",

"Bromol",

"Bron",

"Brona",

"Bronic",

"Brono",

"Bror",

"Brorin",

"Byrtaenys",

"Cacrir",

"Cadmar",

"Cadrys",

"Camrin",

"Canric",

"Caron",

"Cashin",

"Caspyan",

"Cathal",

"Cedran",

"Cedryn",

"Chardris",

"Cior",

"Clafin",

"Colgan",

"Colin",

"Congal",

"Conlan",

"Conor",

"Conrad",

"Cormac",

"Corwyn",

"Cowan",

"Daclyn",

"Dadlir",

"Dador",

"Daeras",

"Daero",

"Daesnar",

"Dagmar",

"Dago",

"Dagon",

"Dallys",

"Dalt",

"D'alt",

"Dalto",

"Daltym",

"Damalinor",

"Damon",

"Danol",

"Darak",

"Darlic",

"Daron",

"Darvin",

"Daslan",

"Dastic",

"Dayyan",

"Delevan",

"Dellin",

"Denham",

"Denzil",

"Derval",

"Derwynt",

"Dhacan",

"Dhadic",

"Dhamin",

"Dhanir",

"Dharyn",

"Dhurath",

"Dhurys",

"Dinham",

"Doak",

"D'oath",

"Docsaan",

"Dogys",

"D'oir",

"Dokgic",

"Doksaic",

"D'olas",

"Dolgyn",

"D'olin",

"Dolon",

"Dolsayn",

"D'omac",

"Domlic",

"Donal",

"Donblas",

"Dongal",

"Dongir",

"Doniol",

"Donlan",

"Donol",

"Donsair",

"Doral",

"D'oran",

"Dorgan",

"Dorgin",

"D'oric",

"Dorlin",

"Dorn",

"Dorsain",

"D'oryn",

"D'orys",

"Dosays",

"Doxo",

"Dragan",

"Dreidal",

"Druthox",

"Du'as",

"Du'ath",

"Du'ic",

"Du'in",

"Dunbar",

"Dundas",

"Dunglas",

"Dunstan",

"Durath",

"Duser",

"Du'ym",

"Du'ys",

"Dvacol",

"Dvado",

"Dvalon",

"Dvalor",

"Dviac",

"Dviam",

"Dviar",

"Dviath",

"Dvonjas",

"Dvonytt",

"Dvorrytt",

"Dvyim",

"Dvyis",

"Dvylin",

"Dylan",

"Eamon",

"Echaeo",

"Ector",

"Edgar",

"Effimas",

"Egan",

"Egon",

"Egron",

"Ehrman",

"Eicir",

"Eicyn",

"Einar",

"Einic",

"Eirin",

"Eirys",

"Elagys",

"Elalin",

"Elalyn",

"Elarin",

"Elaro",

"Elaryn",

"Elbaan",

"Elbain",

"Eldon",

"Eldoym",

"Eldric",

"Eldurin",

"Eleazar",

"Elgic",

"Elgin",

"Elgyn",

"Eligan",

"Elilan",

"Eliran",

"Elirorn",

"Ellic",

"Ellys",

"Elmo",

"Elogir",

"Elolir",

"Elorad",

"Elorir",

"Elric",

"Elrys",

"Emaryn",

"Emiran",

"Emorys",

"Emrath",

"Emrick",

"Emrikol",

"Endsor",

"Ercan",

"Erlan",

"Erlich",

"Erlin",

"Ernan",

"Ervin",

"Esacro",

"Esadron",

"Esedros",

"Eshae",

"Eshaeos",

"Ethaeol",

"Eudo",

"Evald",

"Eymath",

"Eynan",

"Fadorik",

"Faesel",

"Faesel",

"Faeto",

"Faetol",

"Faetor",

"Faicon",

"Faido",

"Faidor",

"Fairol",

"Falcon",

"Fanoran",

"Fayorad",

"Fedor",

"Fedorin",

"Fedorys",

"Festulas",

"Finbar",

"Fingal",

"Fortubo",

"Fraest",

"Fraestar",

"Fraestyn",

"Frolmar",

"Fumaroth",

"Gacnan",

"Gacnys",

"Gacridys",

"Gadnac",

"Gadnyn",

"Gadraiol",

"Gadral",

"Gadridyn",

"Gaecryn",

"Gaedrir",

"Gaeran",

"Gaerys",

"Gaesric",

"Gaethrin",

"Galdor",

"Gallicor",

"Gamnir",

"Gamridir",

"Ganridin",

"Garfalon",

"Garm",

"Garman",

"Garnin",

"Garvin",

"Gasmad",

"Gasnik",

"Gasridic",

"Gathnid",

"Gathridan",

"Gavin",

"Gaynath",

"Gaynor",

"Gellor",

"Gernthan",

"Gernthyn",

"Gicnys",

"Ginmol",

"Girmo",

"Girnyn",

"Gismic",

"Gocthic",

"Goir",

"Gokic",

"Golan",

"Goldar",

"Golys",

"Gomthin",

"Gonac",

"Gonyn",

"Gorin",

"Gormor",

"Gornthys",

"Goxthir",

"Gymnan",

"Gymnic",

"Gynnir",

"Gysnar",

"Gysnin",

"Haborym",

"Hacrys",

"Haddon",

"Hadorath",

"Hadryn",

"Haenath",

"Haeno",

"Haenol",

"Haenon",

"Haenor",

"Haextor",

"Hagoric",

"Halorad",

"Hamrir",

"Hanrin",

"Hasric",

"Hathran",

"Hayral",

"Hinrac",

"Hionhorn",

"Hocan",

"Hodar",

"Hodir",

"Holym",

"Honin",

"Horath",

"Ilgar",

"Ilgath",

"Ilgir",

"Ilgyn",

"Ingram",

"Ioudi",

"Irial",

"Iscaaron",

"Isgoth",

"Ivo",

"Ivor",

"Jaizal",

"Janutt",

"J'arkor",

"Jevan",

"Jolan",

"Jussan",

"Justan",

"Justano",

"Justo",

"Kabor",

"Kaemer",

"Kaemeric",

"Kaemero",

"Kaemerys",

"Kaidh",

"Kaidho",

"Kaldnin",

"Kaldnir",

"Kaldnyn",

"Kaldnys",

"Kamo",

"Kamor",

"Karll",

"Karllan",

"Karllath",

"Karllin",

"Karllon",

"Karral",

"Kaspar",

"Kegan",

"Kerin",

"Kerir",

"Keryn",

"Kerys",

"Kevan",

"Kevellan",

"Khaecic",

"Khaedo",

"Khael",

"Khaelo",

"Khaelorn",

"Khaemay",

"Khaen",

"Khaenar",

"Khaenym",

"Khaerac",

"Khelvin",

"Khent",

"Khental",

"Khentorn",

"Kieran",

"Kobon",

"Kocin",

"Kolir",

"Kolsorm",

"Komon",

"Konin",

"Konsoc",

"Konyn",

"Koonytt",

"Kor",

"Korac",

"Kordal",

"Korentho",

"Kornic",

"Kornyn",

"Koro",

"Korol",

"Korum",

"Korys",

"Kostan",

"Kostys",

"Koxir",

"Krinak",

"Krinako",

"Krinakol",

"Kubo",

"Kubol",

"Kunal",

"Kuno",

"Lacmyn",

"Ladman",

"La'ktar",

"Lamac",

"Lamchan",

"Lanchic",

"Larchin",

"Larmin",

"Laschir",

"Laschyn",

"Lasmic",

"Lathmir",

"Laymys",

"Lazar",

"Ledor",

"Ledorn",

"Lembu",

"Lendar",

"Lendor",

"Lischo",

"Lorin",

"Loschorn",

"Lucibal",

"Luhar",

"Luschys",

"Lycas",

"Macshys",

"Macvox",

"Madchorn",

"Madshyn",

"Maeltan",

"Maeltys",

"Magamo",

"Mahlon",

"Malam",

"Malchom",

"Malhal",

"Malphas",

"Malv",

"Malvo",

"Mamshir",

"Mandal",

"Manshin",

"Marant",

"Marchorm",

"Marshic",

"Mathdar",

"Mathvorn",

"Mayshan",

"Meganwald",

"Mhardox",

"Mocno",

"Mohrgyr",

"Molnar",

"Moltox",

"Monrath",

"Mord",

"Mordath",

"Morn",

"Mornath",

"Movacyn",

"Movadir",

"Movanin",

"Movanys",

"Movarich",

"Movasac",

"Mungo",

"Murdo",

"Murthok",

"Myrlaenis",

"Naberas",

"Nacjhys",

"Nadjhyn",

"Namjhir",

"Nanjhin",

"Narjhic",

"Nasjhan",

"Nasran",

"Nathjhac",

"Nayr",

"Noclik",

"Noclys",

"Nolac",

"Noleborn",

"Nolic",

"Nolin",

"Nolyn",

"Nomin",

"Nomlir",

"Nonlyn",

"Nonvin",

"Noonlac",

"Noran",});



male_names3 = ({

"Norebo",

"Norir",

"Nornlan",

"Norys",

"Noval",

"Obo",

"Ocfeor",

"Ocol",

"Ogon",

"Olfeox",

"Ollam",

"Olox",

"Om",

"Omfeon",

"Onfeorn",

"Onorn",

"Orfeo",

"Orias",

"Ornfeol",

"Oron",

"Oskar",

"Oswald",

"O'tuocmor",

"O'tuolmon",

"O'tuomo",

"O'tuonmox",

"O'tuormol",

"Pael",

"Paelo",

"Paelorn",

"Paelox",

"Paeran",

"Paero",

"Paerox",

"Peacis",

"Peadas",

"Peamal",

"Peath",

"Phado",

"Phaulkon",

"Phaulkor",

"Phymorn",

"Phynor",

"Physol",

"Phyton",

"Pyaray",

"Pyremyas",

"Pytar",

"Raeman",

"Raemic",

"Raenan",

"Raenys",

"Ranjan",

"Ranol",

"Raydrac",

"Reichar",

"Reinchal",

"Reydran",

"Reydrich",

"Reydryn",

"Reymrys",

"Reynrir",

"Reysrin",

"Ronan",

"Sacaelorn",

"Sachial",

"Sachiol",

"Sacrys",

"Sacyin",

"Sacyn",

"Sacys",

"Sadaelo",

"Sadir",

"Sadric",

"Sadryn",

"Sadyic",

"Sadyn",

"Sajys",

"Samael",

"Samic",

"Samin",

"Samiys",

"Samrir",

"Sanir",

"Sanrin",

"Sapiac",

"Sarik",

"Saryan",

"Sasan",

"Sasran",

"Sasyir",

"Sathac",

"Sathan",

"Sathiyn",

"Sathorn",

"Sathox",

"Sathrac",

"Saxo",

"Sayif",

"Scox",

"Scoxal",

"Scoxym",

"Seoir",

"Seokac",

"Seolys",

"Seoman",

"Seonyn",

"Seornin",

"Seoxic",

"Shapjan",

"Shenjaan",

"Slerotin",

"Slortar",

"Socin",

"Solac",

"Solan",

"Somir",

"Sonic",

"Sonys",

"Sorac",

"Sornyn",

"Stacam",

"Staclox",

"Stacvric",

"Stacyn",

"Stadan",

"Stadlorn",

"Stadvrar",

"Stadym",

"Stamir",

"Stamlor",

"Stamvran",

"Stanin",

"Stanlon",

"Stanox",

"Stanvrin",

"Staric",

"Starlo",

"Stasar",

"Stasvram",

"Stasys",

"Statham",

"Stathvrad",

"Stathyn",

"Stavan",

"Stavys",

"Stayad",

"Stayvrac",

"Stelad",

"Stenlac",

"Steno",

"Sticvyrs",

"Sticym",

"Stiggar",

"Stinac",

"Stinir",

"Stinon",

"Stinvryn",

"Stirvrym",

"Stisvrir",

"Stonor",

"Stymin",

"Stynic",

"Stysar",

"Svalor",

"Svelo",

"Svilorn",

"Svolon",

"Szacfrym",

"Szacvorn",

"Szadfryn",

"Szadvor",

"Szamfrin",

"Szamfrir",

"Szamvon",

"Szanfric",

"Szanvo",

"Szasfrys",

"Szathfrar",

"Szayfran",

"Szolfram",

"Szonfrad",

"Szorfrac",

"Tacargin",

"Tacrys",

"Tadargir",

"Tadryn",

"Taecgar",

"Taedgic",

"Taemgin",

"Taengir",

"Taergac",

"Taergad",

"Taergan",

"Taergys",

"Taethgys",

"Talargan",

"Tamrym",

"Tanargic",

"Tanrir",

"Taral",

"Tasrin",

"Tathric",

"Tavis",

"Tavys",

"Tayrar",

"Tevan",

"Thaecorn",

"Thaedo",

"Thaen",

"Thaenal",

"Theesadras",

"Theesar",

"Theolmar",

"Theolmyn",

"Theomad",

"Theommam",

"Theomys",

"Theonman",

"Theonmir",

"Theormic",

"Theormym",

"Theornmin",

"Theoxmac",

"T'ivaryn",

"Tivym",

"Tobbin",

"Tocrac",

"Tolran",

"Tolvad",

"Tonrad",

"Tonvac",

"Toram",

"Tovar",

"T'ovaran",

"Tovas",

"Tovyn",

"Traclyam",

"Tramlyad",

"Tranlyan",

"Trasliym",

"Travan",

"Travin",

"Travlyir",

"Trevlyin",

"Trinlyac",

"Trivam",

"Trivik",

"Trovir",

"Trovlyic",

"Truvlyar",

"Trynliys",

"Trysir",

"Trysliyn",

"Tryvac",

"Tryvam",

"Tryvyn",

"T'shal",

"T'shan",

"T'shar",

"T'shin",

"T'shorn",

"T'svaric",

"Turalo",

"T'varin",

"T'varys",

"Tylquiran",

"Tylvic",

"Tynvan",

"Tynym",

"Tyso",

"Tysvad",

"Tysvar",

"Tyvin",

"Tyvorn",

"Tyvys",

"Ubriac",

"Ubryan",

"Uchas",

"Ucryin",

"Udriam",

"Ufriys",

"Ufryim",

"Uhasorn",

"Ukriyn",

"Uljas",

"Urhok",

"Uriad",

"Urmas",

"Urpo",

"Urthyir",

"Usryic",

"Utha",

"Uthal",

"Uthalo",

"Uthalorn",

"Uthao",

"Uthaso",

"Uthol",

"Uthor",

"Utriar",

"Vacdam",

"Vaddan",

"Valamo",

"Valdemar",

"Valdyn",

"Vanafar",

"Vanard",

"Vanox",

"Vardic",

"Vardis",

"Varon",

"Vasdar",

"Vasdin",

"Vatar",

"Vertislar",

"Viclox",

"Vinath",

"Vindac",

"Vindir",

"Virdys",

"Voclo",

"Voldad",

"Walaeso",

"Waldfrad",

"Walfrac",

"Walnal",

"Waraesath",

"Warfran",

"Warfrys",

"Warnas",

"Warno",

"Wasfrin",

"Wasfryn",

"Watfrir",

"Wilaes",

"Wilaesyn",

"Wilfrick",

"Winfrar",

"Wockfrym",

"Wolaesorn",

"Wolfram",

"Wornalo",

"Xaerbon",

"Xanbor",

"Xanthan",

"Xarbol",

"Xavbo",

"Xavenar",

"Xilborn",

"Xulbox",

"Ybris",

"Yyrko",

"Yyrkon",

"Yyrkor",

"Yyrkorn",

"Zalco",

"Zanethar",

"Zedethin",

"Zeech",

"Zeechal",

"Zeecho",

"Zeethad",

"Zelicox",

"Zelithan",

"Zellis",

"Zelrad",

"Zharuo",

"Zimethym",

"Zinecor",

"Zipethyn",

"Zirethys",

"Zolethic",

"Zulath",

"Zulcon",

"Zulthac",

"Zunethir",});



female_names2 = ({

"Nonebornine",

"Norice",

"Nocine",

"Nomire",

"Noklace",

"Narlane",

"Nadliche",

"Nacline",

"Nanlire",

"Namlyne",

"Naslyse",

"Nathynine",

"Nicyse",

"Nulaenine",

"Obine",

"Obole",

"Obone",

"Oborne",

"Oboxine",

"Ogone",

"Olone",

"Ollama",

"Omine",

"Oonine",

"Orfeoane",

"Orfeole",

"Olfeone",

"Onfeore",

"Ocfeorne",

"Omfeoxe",

"Orisa",

"Oskraine",

"Osprema",

"Oswalda",

"O'tuomone",

"Oasalace",

"Oinarine",

"Oanalya",

"Oamirca",

"Paeline",

"Paeloine",

"Paedorne",

"Paecoxine",

"Paemale",

"Paesane",

"Paecine",

"Paenoe",

"Paethoxine",

"Palanine",

"Peathala",

"Peacasa",

"Peamasi",

"Perissa",

"Petha",

"Poisda",

"Poinore",

"Polanade",

"Porasaye",

"Padame",

"Panirla",

"Phadartha",

"Phanirsi",

"Pharadesy",

"Phaulkine",

"Phytonine",

"Pinja",

"Pirinice",

"Pymonca",

"Pynareya",

"Polaneya",

"Pserchya",

"Pyaraye",

"Pyremyase",

"Pytra",

"Rabella",

"Raemaci",

"Raecana",

"Raedani",

"Raenari",

"Raerayne",

"Raesayse",

"Raethvorte",

"Raenace",

"Raedane",

"Raecayne",

"Raedayse",

"Raenice",

"Raethine",

"Raesire",

"Raija",

"Raila",

"Ranaine",

"Reichale",

"Reichare",

"Reija",

"Reydrane",

"Reydriche",

"Reydrine",

"Rocalda",

"Romanine",

"Ronicsa",

"Rinalya",

"Ryninela",

"Risaneya",

"Rimone",

"Saana",

"Sathara",

"Sadarca",

"Sacarci",

"Samirna",

"Sanrani",

"Sasrari",

"Sathrayne",

"Sinrayse",

"Saija",

"Saila",

"Saima",

"Sajani",

"Sijany",

"Sojari",

"Salace",

"Sacana",

"Sadani",

"Samari",

"Sanayne",

"Sarayse",

"Sasiche",

"Sacaeline",

"Sadaeloe",

"Samaelorne",

"Saphiyse",

"Saphyane",

"Saphonni",

"Saphyine",

"Sardra",

"Saxifine",

"Saxoine",

"Saxorne",

"Seija",

"Selja",

"Selya",

"Selma",

"Senja",

"Seomace",

"Shadinise",

"Shamalya",

"Shonathsa",

"Shomynda",

"Shaka",

"Shalorya",

"Silja",

"Sirja",

"Sircka",

"Sirpa",

"Solja",

"Sonja",

"Solace",

"Somane",

"Socayna",

"Sinayse",

"Sirice",

"Sarine",

"Sanire",

"Sorcha",

"Sorja",

"Stadamy",

"Stacani",

"Stamany",

"Stanari",

"Stathasy",

"Stelare",

"Steline",

"Stelire",

"Stenalore",

"Stiggare",

"Stinvarade",

"Stinvaya",

"Stinvirine",

"Sveline",

"Svelone",

"Svelorane",

"Svelore",

"Syrula",

"Szeffrice",

"Szelavone",

"Taemya",

"Taergace",

"Taecgaya",

"Taecgade",

"Taedgala",

"Taedgame",

"Taemgamya",

"Taemgane",

"Taengani",

"Taergyse",

"Taija",

"Tamaraca",

"Tacirada",

"Tadoramy",

"Tanolani",

"Tarinany",

"Tasymasy",

"Tathonici",

"Tayisima",

"Tacorina",

"Tadathora",

"Tamiela",

"Tanja",

"Tarja",

"Taurea",

"Tavasice",

"Tavadine",

"Teija",

"Tevane",

"Thaecale",

"Thaedine",

"Thaemoe",

"Thaenorne",

"Theesadra",

"Theesra",

"Theola",

"Theocaci",

"Theorada",

"Theonamy",

"Theocana",

"Theacari",

"Theadasy",

"Theamica",

"Thearini",

"Theasiny",

"Theayira",

"Theymma",

"Therila",

"Tovace",

"Tolade",

"Toname",

"Toramy",

"Tocane",

"Tomany",

"Tavare",

"Trelva",

"Taralni",

"Tanayesa",

"Tasintha",

"Jasintha",

"T'shane",

"Tuija",

"Turaline",

"Turla",

"T'varace",

"Tyvane",

"Tynirsi",

"Tysarca",

"Tayineda",

"Tyvorane",

"Tyvri",

"Uhase",

"Uhasoe",

"Uljasa",

"Uljase",

"Ulla",

"Urayine",

"Umyanine",

"Usaynla",

"Usitha",

"Urida",

"Uriyane",

"Urmasa",

"Urnuinine",

"Uryane",

"Uthale",

"Uthaloe",

"Usalorne",

"Udaoe",

"Umine",

"Unoe",

"Vala",

"Valadine",

"Vadadri",

"Vacafare",

"Vanamoe",

"Vamdace",

"Valdade",

"Vacdame",

"Vardane",

"Vandare",

"Vamdari",

"Valdemare",

"Vathdiche",

"Vaydsy",

"Voldyne",

"Vonine",

"Viclyne",

"Valtine",

"V'andree",

"Vadare",

"Vatine",

"Vanone",

"Vicaline",

"Vinaloe",

"Vilja",

"Vinarda",

"Virathe",

"Warnase",

"Wernale",

"Wernaline",

"Wernoe",

"Wilaesine",

"Wilaesoe",

"Wilaestha",

"Walaesyne",

"Wynisa",

"Xanthana",

"Xavenare",

"Xerabine",

"Xiombarge",

"Ybrise",

"Yyrakoe",

"Yyrakone",

"Yyrakore",

"Yyrakorne",

"Zalacone",

"Zadacore",

"Zanalise",

"Zolicine",

"Zaricoe",

"Zasirade",

"Zharuine",

"Zinethace",

"Zulathine", });



female_names3 = ({

"Abigaine",

"Abinoine",

"Abiroline",

"Adeva",

"Adina",

"Adovelala",

"Adracine",

"Anrade",

"Adrame",

"Acrane",

"Asrasa",

"Adrathine",

"Acrice",

"Amrine",

"Anrmya",

"Asrny",

"Athary",

"Adrsya",

"Adrya",

"Aeodolace",

"Aeodonadne",

"Aeodorame",

"Aeodokane",

"Aeodocathe",

"Aeodomci",

"Aeodornine",

"Aeodacni",

"Aeodadny",

"Aeodamri",

"Aeodansa",

"Aeodarsy",

"Aeore",

"Aeradne",

"Aecame",

"Aedane",

"Aemathe",

"Aenca",

"Aerci",

"Aesda",

"Aethine",

"Aerma",

"Aecmy",

"Aedna",

"Aerni",

"Aecnyine",

"Aedorne",

"Aemoxine",

"Aesri",

"Aethsa",

"Aecsy",

"Aertha",

"Aedya",

"Afra",

"Agaraline",

"Agacasine",

"Agamise",

"Aganyse",

"Ahnbelka",

"Ahndja",

"Aija",

"Aina",

"Aithne",

"Alaine",

"Amaine",

"Alaire",

"Alanine",

"Alastinore",

"Alantoe",

"Aladtoline",

"Alartone",

"Alatrina",

"Alayne",

"Alayosine",

"Alda",

"Aleshine",

"Aliace",

"Aciade",

"Adiame",

"Aniara",

"Ariase",

"Asiathe",

"Athiaye",

"Adina",

"Amine",

"Alirrya",

"Acma",

"Admala",

"Armira",

"Anmoine",

"Asmonine",

"Acmora",

"Admorne",

"Armoxine",

"Alocadise",

"Alomorine",

"Alornra",

"Alansha",

"Adraca",

"Anrachira",

"Acradace",

"Asramicha",

"Adranirine",

"Alrany",

"Anrase",

"Anratha",

"Asraye", 

"Amrine",

"Adrorine",

"Acryse",

"Altrigaine",

"Altragice",

"Altrogire",

"Altragny",

"Altrigonine",

"Altrogyse",

"Alvina",

"Alyane",

"Amalina",

"Amanthsa",

"Amacthsine",

"Amadthyse",

"Anelma",

"Anja",

"Annora",

"Antelila",

"Aminlila",

"A'mache",

"A'racine",

"Acamine",

"Adamoe",

"Anamole",

"Asamoxine",

"A'rane",

"Arani",

"Adasine",

"Arathone",

"Aradorne",

"A'rathe",

"Aratore",

"A'rda",

"Areta",

"Ariare",

"Aricine",

"Arina",

"A'rine",

"Arja",

"Arjanine",

"Ackasya",

"Arkice",

"Adknine",

"Ankrine",

"Amkyne",

"Armasa",

"Asmorne",

"A'cny",

"Arnya",

"A'dsya",

"Amtine",

"Artolsine",

"Acvada",

"Advadaine",

"Amvaire",

"Anvani",

"Arvany",

"Asvatha",

"Athvayse",

"Ayvice",

"Arvida",

"A'cysa",

"Arysine",

"Arzhaena",

"Astorghaine",

"Astra",

"Aubaca",

"Audacine",

"Aunacome",

"Auldine",

"Aundonire",

"Aumdorise",

"Avanine",

"Avadice",

"Avasine",

"Avayole",

"Azaelana",

"Azaecara",

"Azaedathe",

"Azaemine",

"Azaenore",

"Baelana",

"Baelvore",

"Bala'adine",

"Baca'ane",

"Bada'anine",

"Bama'arine",

"Bana'asine",

"Bara'caine",

"Basa'cine",

"Batha'ine",

"Baya'maine",

"Bica'nya",

"Bina'raine",

"Bira'tha",

"Byma'yse",

"Balfarlna",

"Bacgarsa",

"Badgrace",

"Bamgranine",

"Bangrany",

"Bargrarine",

"Basgrathe",

"Bathgrayse",

"Baygrine",

"Balialine",

"B'anine",

"Balinore",

"B'alire",

"Bacva'cire",

"Badva'ice",

"Bamva'na",

"Banva'nine",

"Barva'nya",

"Ballva'yse",

"B'acvolari",

"B'acvonasya",

"B'allvokayne",

"B'amvocine",

"B'anvorkine",

"B'arvomna",

"B'aloline",

"B'athore",

"Banotra",

"Bacphegine",

"Balphegoline",

"Badphegone",

"Bamphegorine",

"Barliknya",

"Barzhaane",

"Bathamy",

"Beltar",

"Berita",

"Bethany",

"Briochine",

"Brita",

"Brodna",

"Brolcine",

"Bronice",

"Bromine",

"Brocire",

"Brolnine",

"Brinare",

"Bronda",

"Branice",

"Bradine",

"Brynole",

"Branya",

"Byrna",

"Byrtaenyse",

"Caeriza",

"Caspya",

"Cedracine",

"Cadrane",

"Camrari",

"Canrine",

"Cinrsy",

"Cedryne",

"Chaena",

"Chaerine",

"Chalame",

"Chamase",

"Chardrisa",

"Chorazine",

"Ciorine",

"Clarinda",

"Coela",

"Corwnya",

"Cymorile",

"Daenase",

"Daerine",

"Daecsy",

"Daesnare",

"Daedmare",

"Dagga",

"Dadine",

"Dagmar",

"Danole",

"Dasone",

"Dathore",

"Dalatamya",

"Dacatice",

"Danatine",

"Damalinore",

"Delina",

"Dinlane",

"Dollani",

"Dallany",

"Daslari",

"Damlayse",

"Danlice",

"Dema",

"Derwynise",

"Devra",

"Dhurana",

"Dirizaela",

"Donblase",

"Doralire",

"D'onane",

"D'orathe",

"D'olca",

"D'ornci",

"Dorgana",

"Dolgani",

"Donganya",

"Dokgayse",

"Domgice",

"Docgire",

"D'arine",

"D'orise",

"Dorlana",

"Darlani",

"Dirlany",

"Donlayse",

"Doclice",

"D'orni",

"D'olnine",

"D'omnya",

"D'arsa",

"Dolsacine",

"Dorsaine",

"Donsaire",

"Docsana",

"Domsany",

"Darsayse",

"D'oryse",

"Dorale",

"Doxine",

"Dreidla",

"Du'asy",

"Du'onine",

"Du'olase",

"Du'oroe",

"Du'ocire",

"Du'omine",

"Du'ymla",

"Du'athe",

"Du'ayme",

"Du'ice",

"Du'nine",

"Durakine",

"Dorathe",

"Du'saine",

"Dusire",

"Dvadine",

"Dvacole",

"Dvamone",

"Dvalore",

"Dviare",

"Dviathe",

"Dvica",

"Dvila",

"Dvima",

"Dvonette",

"Dvonjase",

"Dvoljasi",

"Dvorjasy",

"Dvocytati",

"Dvokrytala",

"Dvyine",

"Dvyise",

"Dvymine",

"Edeva",

"Edla",

"Eequore",

"Effimsa",

"Eija",

"Einathe",

"Eirayse",

"Eisice",

"Einire",

"Eirna",

"Eicni",

"Eirnya",

"Elbaine",

"Elbanya",

"Elbari",

"Elbayse",

"Eldoacine",

"Eldoadine",

"Eldoni",

"Eldoyame",

"Eldurine",

"Elgayse",

"Elgice",

"Elgna",

"Ella",

"Ellana",

"Ellani",

"Ellayse",

"Ellice",

"Elmine",

"Elrane",

"Elranya",

"Elrine",

"Elrorane",

"Elryse",

"Emalire",

"Enrana",

"Edrare",

"Emratha",

"Esrayse",

"Emriche",

"Eyrine",

"Emryne",

"Enmelane",

"Erekila",

"Erja",

"Erlane",

"Erliche",

"Erline",

"Erlyse",

"Ervine",

"Esedaroe",

"Esadarone",

"Esedrose",

"Echaena",

"Ethaeoe",

"Eshaeole",

"Echaeose",

"Esmee",

"Evadne",

"Evaine",

"Faemoyra",

"Faena",

"Faeseline",

"Faeseline",

"Faetole",

"Faethorine",

"Faidine",

"Faidoe",

"Faicole",

"Faisore",

"Fedonade",

"Fedolaine",

"Fedonayne",

"Fedocayse",

"Fedomiare",

"Fedoriche",

"Fedirine",

"Felny",

"Festulase",

"Fraestarine",

"Fraestine",

"Fraestoline",

"Fraestonine",

"Fraestyne",

"Frolmare",

"Gadraiela",

"Gacraiole",

"Gathrola",

"Gaeline",

"Gaerany",

"Gaecari",

"Gaedasy",

"Gaemci",

"Gaesna",

"Gaeyni",

"Gallicorine",

"Garfaline",

"Gasmade",

"Ganmaline",

"Girmane",

"Ginmice",

"Gynmine",

"Gysmora",

"Golnane",

"Gornare",

"Gasnathe",

"Gathniche",

"Gicnide",

"Gisnine",

"Girnyna",

"Galnysa",

"Gacridane",

"Gadridice",

"Gamridine",

"Gasridire",

"Gayridyna",

"Ginridysa",

"Gaynore",

"Gellore",

"Gernathaci",

"Garnathana",

"Gacnathani",

"Gymnathany",

"Gysnathari",

"Gonathasy",

"Girnaca",

"Gicnaci",

"Gisnana",

"Gadnani",

"Gacnany",

"Gamnari",

"Gaynasy",

"Golaca",

"Gonaci",

"Goana",

"Gorani",

"Gocany",

"Gomari",

"Gornasy",

"Gokdra",

"Graine",

"Gretavaine",

"Haborade",

"Hadonathe",

"Hacolice",

"Hamoryme",

"Haromyne",

"Hadrace",

"Hacraine",

"Hamrale",

"Hanrice",

"Harrine",

"Hasrire",

"Hathryne",

"Hayryse",

"Haeyace",

"Haethade",

"Haesathe",

"Haerine",

"Haenoe",

"Haemole",

"Haedone",

"Haecore",

"Haenyame",

"Haedyase",

"Hansine",

"Hellina",

"Helsharona",

"Henanase",

"Hilja",

"Hilma",

"Hilpipa",

"Hionshorane",

"Hodamy",

"Holana",

"Horani",

"Honari",

"Homatha",

"Hocra",

"Hysterna",

"Iana",

"Iblise",

"Iida",

"Iikka",

"Iina",

"Ilgany",

"Icgari",

"Ingatha",

"Isgra",

"Ilsola",

"Ilma",

"Ilona",

"Inka",

"Iola",

"Ioudine",

"Irina",

"Irja",

"Irma",

"Iscaaroe",

"Ishaarone",

"Isgothe",

"Ivoe",

"Ivore",

"Jaana",

"Jaizale",

"Janika",

"Janita",

"Janutashi",

"J'arkore",

"Jolane",

"Jorma",

"Jadine",

"Jamyra",

"Jarothe",

"Jasmica",

"Jathdise",

"Jonysorme",

"Jorayine",

"Jalusha",

"Jusasany",

"Jisasci",

"Jicasine",

"Jinasri",

"Jymasyse",

"Jynsane",

"Justane",

"Jystanoe",

"Jastine",

"Kadaena",

"Kaecarade",

"Kaedirase",

"Kaemynice",

"Kaenoline",

"Kaerinoe",

"Kaesinyse",

"Kaidahare",

"Kaicamathe",

"Kainadaye",

"Kairacice",

"Kaymasire",

"Kaisathoe",

"Kaolayone",

"Kaonahyne",

"Kaocahyse",

"Kaija",

"Kaisa",

"Kaldanane",

"Kacdinice",

"Kaddacine",

"Kamdinire",

"Kardiryne",

"Kasdolyse",

"Kalimira",

"Kamoe",

"Kasore",

"Kynlaline",

"Korlalore",

"Kirlalorine",

"Kaylilani",

"Karlla",

"Kathlilari",

"Kaslilone",

"Kadlilorne",

"Kamraline",

"Kenna",

"Keraca",

"Karaki",

"Kacana",

"Kadani",

"Kamanya",

"Kasari",

"Kathasy",

"Kevelaline",

"Kevellane",

"Khaeline",

"Khaeloe",

"Khaelorane",

"Khaeyace",

"Khaethare",

"Khaesaye",

"Khaerice",

"Khaenine",

"Khaemoe",

"Khaedyme",

"Khelavine",

"Khentine",

"Korari",

"Kolayne",

"Konayse",

"Komca",

"Kondala",

"Kocenthoe",

"Karine",

"Kirni",

"Kynoe",

"Korole",

"Komone",

"Kornumoe",

"Korvee",

"Kosasoce",

"Kisasorme",

"Kirtane",

"Kintayne",

"Kantice",

"Kictine",

"Kadtire",

"Kamtyse",

"Krinaka",

"Krirakoe",

"Krisakole",

"Kyriale",

"Laenine",

"Lahja",

"Laila",

"Laina",

"La'katra",

"Latamari",

"Latamasya",

"Latamci",

"Lathamica",

"Ladimana",

"Lanimani",

"Larimanya",

"Ledoare",

"Ledorane",

"Lembuine",

"Linadare",

"Lenadore",

"Lendya",

"Liina",

"Liisa",

"Lilja",

"Liraena",

"Lotta",

"Loviisa",

"Lucibale",

"Luciblane",

"Luhara",

"Luschaci",

"Laschana",

"Larchani",

"Ladchany",

"Lirchari",

"Linchasya",

"Lynchine",

"Luschorne",

"Lycase",

"Lydia",

"Lydora",

"Lylya",

"Lynade",

"Lysane",

"Lirome",

"Locane",

"Lomaline",

"Lorinise",

"Lasynsi",

"Mabelode",

"Maedine",

"Maeltane",

"Maectayne",

"Maedtayse",

"Maemtice",

"Maentine",

"Maertira",

"Maerine",

"Magama",

"Magamine",

"Magda",

"Magna",

"Maija",

"Maila",

"Malavine",

"Macavoe",

"Madavorne",

"Mamavoxine",

"Manchomine",

"Marchorane",

"Maschorme",

"Mashale",

"Malphasa",

"Manashayse",

"Macashice",

"Mamashire",

"Mindale",

"Mandare",

"Mynishane",

"Manishayne",

"Monishine",

"Maranta",

"Marinaella",

"Marja",

"Marjatta",

"Marasla",

"Madisine",

"Marketta",

"Marrta",

"Meganwaldine",

"Merja",

"Mhardoxine",

"Mhari",

"Mhora",

"Milja",

"Minna",

"Mira",

"Mirathe",

"Mirja",

"Mirva",

"Mohrgayre",

"Monrathe",

"Mora",

"Morda",

"Mordathe",

"Morna",

"Mornare",

"Mornathe",

"Mornine",

"Mortine",

"Moladace",

"Monaciche",

"Morarine",

"Mocanire",

"Mothanyne",

"Malvanyse",

"Moyra",

"Murathoce",

"Myrlaenise",

"Myshella",

"Nabersa",

"Narjahca",

"Nacjahcine",

"Nadjahnay",

"Namjahni",

"Nanjahsaya",

"Nasjihci",

"Nathjihrine",

"Nasorna",

"Nayrine",

"Nemine",

"Nenae",

"Nevraeline",

"Ninaline",

"Nynarsy",

"Narocsa",

"Niina",

"Niyoreha",

"Noracine",

"Nolanine", });



}















get_female_name(){

int numero;

numero = random(100);

if(numero > 35){

return female_names[random(sizeof(female_names))];

}

else if(numero > 18){

return female_names2[random(sizeof(female_names2))];

}

else{

return female_names3[random(sizeof(female_names3))];

}

}



get_male_name(){

int numero;

numero = random(100);

if(numero > 35){

return male_names[random(sizeof(male_names))];

}

else if(numero > 18){

return male_names2[random(sizeof(male_names2))];

}

else{

return male_names3[random(sizeof(male_names3))];

}

}

