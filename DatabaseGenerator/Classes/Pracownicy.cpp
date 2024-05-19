#include "Pracownicy.h"
#include <sstream>

int Pracownicy::counter = 0;

std::vector<std::string> Pracownicy::names = { "Anna", "Katarzyna", "Maria", "Malgorzata", "Agnieszka", "Barbara", "Ewa", "Magdalena", "Elzbieta", "Krystyna", "Joanna", "Aleksandra", "Monika", "Zofia", "Teresa", "Natalia", "Julia", "Danuta", "Karolina", "Marta", "Beata", "Dorota", "Alicja", "Halina", "Jadwiga", "Jolanta", "Iwona", "Grazyna", "Janina", "Paulina", "Zuzanna", "Justyna", "Irena", "Hanna", "Wiktoria", "Bozena", "Renata", "Urszula", "Agata", "Sylwia", "Maja", "Patrycja", "Helena", "Izabela", "Emilia", "Oliwia", "Aneta", "Weronika", "Ewelina", "Martyna", "Klaudia", "Gabriela", "Marzena", "Lena", "Dominika", "Marianna", "Amelia", "Kinga", "Stanislawa", "Edyta", "Kamila", "Wieslawa", "Alina", "Wanda", "Daria", "Lidia", "Mariola", "Lucyna", "Tetiana", "Nikola", "Milena", "Nataliia", "Olena", "Wioletta", "Miroslawa", "Iryna", "Laura", "Antonina", "Angelika", "Olga", "Kazimiera", "Olha", "Bogumila", "Oksana", "Ilona", "Michalina", "Sandra", "Genowefa", "Mariia", "Svitlana", "Nadia", "Yuliia", "Anastasiia", "Kornelia", "Marlena", "Viktoriia", "Henryka", "Lucja", "Sabina", "Boguslawa", "Nina", "Jozefa", "Anita", "Stefania", "Iga", "Liliana", "Regina", "Pola", "Marcelina", "Kateryna", "Jagoda", "Czeslawa", "Aniela", "Wladyslawa", "Karina", "Liudmyla", "Wioleta", "Adrianna", "Diana", "Roksana", "Dagmara", "Sara", "Malwina", "Halyna", "Eliza", "Cecylia", "Zaneta", "Maryna", "Zdzislawa", "Sofiia", "Klara", "Roza", "Kaja", "Valentyna", "Leokadia", "Blanka", "Nadiia", "Anastazja", "Bernadeta", "Bronislawa", "Eugenia", "Julita", "Oleksandra", "Aldona", "Rozalia", "Violetta", "Daniela", "Lilianna", "Inna", "Magda", "Celina", "Yana", "Matylda", "Liubov", "Adriana", "Honorata", "Veronika", "Nela", "Paula", "Larysa", "Brygida", "Aurelia", "Valeriia", "Izabella", "Kalina", "Alla", "Marika", "Gertruda", "Mieczyslawa", "Sonia", "Bozenna", "Elwira", "Liliia", "Marzanna", "Olivia", "Tamara", "Andzelika", "Polina", "Alona", "Arleta", "Tatiana", "Yelyzaveta", "Luiza", "Khrystyna", "Victoria", "Adela", "Judyta", "Mia", "Nicole", "Franciszka", "Ivanna", "Mariana", "Nicola", "Natasza", "Liwia", "Jowita", "Vira", "Vanessa", "Alfreda", "Yevheniia", "Apolonia", "Romana", "Melania", "Inga", "Jessica", "Anhelina", "Elena", "Daryna", "Ada", "Eleonora", "Marzenna", "Julianna", "Estera", "Bianka", "Ludwika", "Marharyta", "Lesia", "Milana", "Sofia", "Bernadetta", "Zenona", "Waclawa", "Karyna", "Zlata", "Kira", "Uliana", "Alisa", "Donata", "Walentyna", "Ludmila", "Anetta", "Yeva", "Lidiia", "Maya", "Olesia", "Felicja", "Lilia", "Rita", "Ida", "Hildegarda", "Zenobia", "Emma", "Amanda", "Romualda", "Kseniia", "Myroslava", "Otylia", "Kristina", "Arina", "Gizela", "Ruslana", "Irmina", "Albina", "Dariia", "Vita", "Viktoria", "Lilla", "Slawomira", "Bernarda", "Alena", "Eryka", "Pelagia", "Angelina", "Gaja", "Solomiia", "Anastasiya", "Yuliya", "Longina", "Waleria", "Ryszarda", "Vladyslava", "Kamilla", "Teodozja", "Teodora", "Irina", "Alexandra", "Zhanna", "Raisa", "Mirela", "Tatsiana", "Adelajda", "Zoja", "Lila", "Varvara", "Volha", "Faustyna", "Anzhela", "Katsiaryna", "Nataliya", "Marina", "Mariya", "Bohdana", "Samanta", "Anastasia", "Olimpia", "Natallia", "Eva", "Ksenia", "Marcela", "Maryla", "Jagna", "Galyna", "Lucja", "Yaroslava", "Nel", "Snizhana", "Zyta", "Oktawia", "Konstancja", "Darya", "Pamela", "Leonarda", "Zoriana", "Feliksa", "Emiliia", "Wanessa", "Noemi", "Claudia", "Tetyana", "Nikol", "Sophie", "Evelina", "Emily", "Bogna", "Maryia", "Iuliia", "Mirella", "Anzhelika", "Stella", "Inez", "Lea", "Ganna", "Michelle", "Zinaida", "Tola", "Krzysztofa", "Zoia", "Nelia", "Sarah", "Ola", "Jasmina", "Valentina", "Boleslawa", "Svetlana", "Nadzieja", "Angela", "Edwarda", "Mila", "Viktoryia", "Elfryda", "Liudmila", "Galina", "Miriam", "Ana", "Salomea", "Sviatlana", "Taisiia", "Ines", "Lara", "Natalie", "Edeltrauda", "Antonia", "Vitalina", "Lina", "Marietta", "Iza", "Roma", "Sophia", "Vasylyna", "Aliaksandra", "Arletta", "Maiia", "Adelina", "Klementyna", "Erika", "Manuela", "Elina", "Klaudyna", "Veronica", "Amina", "Margarita", "Ruta", "Nadiya", "Greta", "Yanina", "Sofiya", "Livia", "Wiera", "Lyudmyla", "Helga", "Jana", "Andrea", "Nika", "Florentyna", "Martina", "Ala", "Gerda", "Gloria", "Kseniya", "Roksolana", "Lyubov", "Dobroslawa", "Ekaterina", "Isabella", "Mira", "Yaryna", "Malina", "Ina", "Linda", "Eulalia", "Valeria", "Irmgarda", "Viktoriya", "Katerina", "Jennifer", "Jaroslawa", "Yelizaveta", "Bernardyna", "Nicol", "Patricia", "Sabrina", "Ella", "Violeta", "Ariana", "Veranika", "Elvira", "Dina", "Hannah", "Bogdana", "Wanesa", "Marcjanna", "Elizabeth", "Majka", "Hanka", "Teofila", "Dzesika", "Erna", "Marita", "Ludmila", "Simona", "Andriana", "Gabriella", "Anika", "Larisa", "Valeryia", "Dana", "Palina", "Wirginia", "Vera", "Luba", "Liana", "Tamila", "Alice", "Lily", "Alesia", "Carmen", "Dajana", "Vlada", "Caroline", "Yuliana", "Naomi", "Emanuela", "Yulia", "Balbina", "Dalia", "Nikoletta", "Alicia", "Lizaveta", "Berenika", "Nelly", "Vitaliia", "Elizaveta", "Bianca", "Aksana", "Liliya", "Ramona", "Kunegunda", "Inka", "Irma", "Lilly", "Darina", "Kornela", "Filomena", "Seweryna", "Krystsina", "Ulyana", "Maia", "Zaklina", "Kaya", "Idalia", "Iwonna", "Swietlana", "Jozefina", "Michaela", "Blandyna", "Amalia", "Hana", "Nadzeya", "Stefaniia", "Cristina", "Benedykta", "Carolina", "Emila", "Ingrid", "Melaniia", "Lubomira", "Ligia", "Abigail", "Nastassia", "Mariam", "Melisa", "Sybilla", "Marie", "Gabryela", "Zoe", "Leontyna", "Roxana", "Aliona", "Melissa", "Celestyna", "Leila", "Monica", "Gracjana", "Ingeborga", "Fatima", "Slawa", "Taisa", "Dobrawa", "Aurora", "Clara", "Zanetta", "Margareta", "Leonia", "Bernardeta", "Ela", "Benita", "Dziyana", "Domicela", "Lisa", "Margaryta", "Nino", "Tekla", "Kasandra", "Silvia", "Oriana", "Orysia", "Mylana", "Jesika", "Inesa", "Iana", "Karin", "Berta", "Aryna", "Jasmina", "Tina", "Natalya", "Eunika", "Giulia", "Dagna", "Dobrochna", "Jessika", "Inha", "Elisabeth", "Nathalie", "Yauheniya", "Elisa", "Selena", "Jasmin", "Sofija", "Tamar", "Zoya", "Natasha", "Sylvia", "Nella", "Valiantsina", "Nikolina", "Tatyana", "Samantha", "Lia", "Melanie", "Lesya", "Liza", "Miroslava", "Catherine", "Nelli", "Charlotte", "Lili", "Laila", "Lucia", "Susanna", "Marieta", "Bozhena", "Letycja", "Leslawa", "Nell", "Oryna", "Julitta", "Vivien", "Christina", "Miranda", "Augustyna", "Samira", "Katherine", "Wilhelmina", "Noa", "Miia", "Elmira", "Tereza", "Luna", "Arianna", "Ariadna", "Marija", "Katharina", "Nikoleta", "Sylwestra", "Juliana", "Karen", "Yael", "Rozwita", "Stanislava", "Roza", "Miloslawa", "Elza", "Oxana", "Layla", "Agnes", "Valeriya", "Yustyna", "Alevtyna", "Ernestyna", "Izolda", "Radoslawa", "Dobromila", "Ania", "Ema", "Angelica", "Eufemia", "Jasmine", "Ryta", "Christine", "Rymma", "Lyudmila", "Petronela", "Alma", "Halszka", "Neonila", "Aida", "Chiara", "Margot", "Ludomira", "Jacqueline", "Lidiya", "Solomiya", "Gaia", "Matilda", "Ingrida", "Isabelle", "Martha", "Margaret", "Ruth", "Maryana", "Yevanhelina", "Ismena", "Ievgeniia", "Lubov", "Anida", "Amy", "Isabel", "Francesca", "Jelena", "Fryderyka", "Michal", "Zlatoslava", "Andzelina", "Chloe", "Amira", "Debora", "Zenaida", "Ksymena", "Stephanie", "Rehina", "Nastia", "Mary", "Yasmin", "Betina", "Benigna", "Cyryla", "Delfina", "Inessa", "Jesica", "Hiacynta", "Irene", "Narcyza", "Lukrecja", "Emiliya", "Paola", "Lubow", "Lucy", "Iwetta", "Amelie", "Daiana", "Madina", "Gracja", "Julie", "Nadine", "Anne", "Lada", "Rachel", "Waltrauda", "Iweta", "Zarina", "Anna-Mariia", "Vasilisa", "Olesya", "Nana", "Leyla", "Eliana", "Nicoletta", "Scholastyka", "Aniceta", "Zanna", "Juliia", "Lolita", "Bibianna", "Aisha", "Luisa", "Ludmyla", "Ecaterina", "Sharon", "Emilie", "Malika", "Thi", "Carla", "Hermina", "Kesja", "Larissa", "Nadezhda", "Vivienne", "Andrzelika", "Alla", "Camilla", "Adi", "Katia", "Ilza", "Lydia", "Yulianna", "Helen", "Vladislava", "Johanna", "Adamina", "Szarlota", "Natia", "Klavdiia", "Katarina", "Megan", "Modesta", "Mika", "Liubou", "Iulia", "Rose", "Rachela", "Camila", "Eleni", "Ludwina", "Lorena", "Nila", "Astrid", "Susanne", "Lana", "Cornelia", "Liubomyra", "Switlana", "Nastazja", "Esther", "Malvina", "Maryam", "Wera", "Karine", "Alessandra", "Grace", "Sonja", "Petra", "Otolia", "Yeseniia", "Alessia", "Rebecca", "Anja", "Leonora", "Ameliia", "Ingryda", "Oliviia", "Yevdokiia", "Karmen", "Anastasija", "Lucjanna", "Wincentyna", "Liia", "Ursula", "Arlena", "Nadija", "Rosa", "Leah", "Hieronima", "Wielislawa", "Doris", "Serafina", "Cynthia", "Fatma", "Vladlena", "Karola", "Zosia", "Prakseda", "Stepaniia", "Leona", "Susan", "Natalija", "Katrin", "Lilli", "Sofie", "Dariya", "Nadejda", "Teona", "Asia", "Heronima", "Marine", "Aurela", "Mirona", "Anat", "Sofya", "Laurencja", "Liuba", "Zara", "Ester", "Evgeniia", "Solomia", "Yvonne", "Kiara", "Yasmina", "Tal", "Erwina", "Irmgard", "Pauline", "Jolenta", "Fabiola", "Leonida", "Bella", "Nonna", "Zeynep", "Th?", "Chantal", "Elif", "Roni", "Syntia", "Gabrielle", "Merve", "Deborah", "Shira", "Rena", "Daniella", "Zoryana", "Susana", "Amaliia", "Hilda", "Rimma", "Nadja", "Neli", "Rebeka", "Agatha", "Marharita", "Khatuna", "Viyaleta", "Wlodzimiera", "Dolores", "Ksawera", "Flora", "Noelia", "Aya", "Blanca", "Karla", "Kamelia", "Iliana", "Viviana", "Anna-Maria", "Roberta", "Rada", "Salma", "Beatriz", "Danielle", "Iris", "Tadeusza", "Krystiana", "Stela", "Victoriia", "Milla", "Evgenia", "Suzanna", "Augusta", "Virginia", "Ani", "Denise", "Vivian", "Patrizia", "Evelyn", "Herta", "Jagienka", "Salome", "Ivana", "Nora", "Gustawa", "Alojza", "Suzanne", "Tatjana", "Izydora", "Pavlina", "Maria", "Vanda", "Edith", "Rut", "Bogda", "Kristine", "Scarlett", "Yelizavieta", "Julieta", "Vanesa", "Zbigniewa", "Evgeniya", "Dioniza", "Yevheniya", "Jenny", "Felicyta", "Romina", "Simone", "Hania", "Vittoria", "Lola", "Koryna", "Walburga", "Rafaela", "Rozaliia", "Kate", "Tea", "Nadiezda", "Ahata", "Viola", "Josephine", "Wincenta", "Annette", "Cecilia", "Katrina", "Ilana", "Ava", "Zuzana", "Raquel", "Nona", "Juliette", "Margota", "Kamilia", "Kasjana", "Chanel", "Karalina", "Lucie", "Claire", "Ineza", "Mihaela", "Damiana", "Mariami", "Waleska", "Anzhalika", "Dora", "Iman", "Lubomila", "Dabrowka", "Ketevan", "Adel", "Kayla", "Yuval", "Lida", "Kathrin", "Louise", "Bettina", "Yelena", "Paloma", "Margarete", "Denisa", "Alyona", "Dasha", "Viorica", "Lucjana", "Kelly", "Stefaniya", "Kryspina", "Annika", "Adolfa", "Lali", "Fryda", "Yasmine", "Lilian", "Zina", "Dinara", "Elyzaveta" };

std::vector<std::string> Pracownicy::surnames = { "Nowak", "Kowalska", "Wisniewska", "Wojcik", "Kowalczyk", "Kaminska", "Lewandowska", "Zielinska", "Szymanska", "Dabrowska", "Wozniak", "Kozlowska", "Mazur", "Jankowska", "Kwiatkowska", "Wojciechowska", "Krawczyk", "Kaczmarek", "Piotrowska", "Grabowska", "Pawlowska", "Michalska", "Krol", "Zajac", "Wieczorek", "Jablonska", "Wrobel", "Nowakowska", "Majewska", "Olszewska", "Adamczyk", "Jaworska", "Malinowska", "Stepien", "Dudek", "Gorska", "Nowicka", "Witkowska", "Pawlak", "Sikora", "Walczak", "Rutkowska", "Michalak", "Szewczyk", "Ostrowska", "Baran", "Tomaszewska", "Zalewska", "Wroblewska", "Pietrzak", "Jasinska", "Marciniak", "Sadowska", "Jakubowska", "Zawadzka", "Duda", "Wlodarczyk", "Chmielewska", "Borkowska", "Bak", "Wilk", "Sokolowska", "Szczepanska", "Sawicka", "Lis", "Kucharska", "Kalinowska", "Maciejewska", "Mazurek", "Wysocka", "Kubiak", "Kolodziej", "Czarnecka", "Kazmierczak", "Urbanska", "Sikorska", "Krupa", "Sobczak", "Krajewska", "Glowacka", "Zakrzewska", "Wasilewska", "Laskowska", "Ziolkowska", "Gajewska", "Kozak", "Szulc", "Mroz", "Makowska", "Brzezinska", "Przybylska", "Kaczmarczyk", "Baranowska", "Szymczak", "Adamska", "Blaszczyk", "Borowska", "Gorecka", "Szczepaniak", "Kania", "Leszczynska", "Janik", "Czerwinska", "Chojnacka", "Lipinska", "Andrzejewska", "Wesolowska", "Kowalewska", "Mikolajczyk", "Mucha", "Cieslak", "Jarosz", "Zieba", "Konieczna", "Koziol", "Markowska", "Kowalik", "Kolodziejczyk", "Musial", "Brzozowska", "Domanska", "Tomczyk", "Orlowska", "Pawlik", "Piatek", "Nowacka", "Kopec", "Tomczak", "Kruk", "Kurek", "Zak", "Ciesielska", "Kot", "Markiewicz", "Polak", "Wawrzyniak", "Wolska", "Wojtowicz", "Stankiewicz", "Jastrzebska", "Sowa", "Urbaniak", "Karpinska", "Czajkowska", "Stasiak", "Wierzbicka", "Luczak", "Nawrocka", "Piasecka", "Klimek", "Dziedzic", "Sosnowska", "Janicka", "Bednarek", "Bielecka", "Milewska", "Gajda", "Stefanska", "Madej", "Majchrzak", "Lesniak", "Jozwiak", "Maj", "Urban", "Kowal", "Sliwinska", "Skiba", "Malecka", "Bednarczyk", "Socha", "Dobrowolska", "Marek", "Michalik", "Romanowska", "Domagala", "Ratajczak", "Wrona", "Wilczynska", "Kasprzak", "Matuszewska", "Orzechowska", "Swiatek", "Olejniczak", "Pajak", "Rybak", "Kurowska", "Bukowska", "Sobolewska", "Owczarek", "Mazurkiewicz", "Lukasik", "Rogowska", "Olejnik", "Grzelak", "Kedzierska", "Kosinska", "Baranska", "Matusiak", "Sobczyk", "Skowronska", "Marcinkowska", "Marszalek", "Zych", "Bednarska", "Bednarz", "Chrzanowska", "Lisowska", "Kuczynska", "Swiderska", "Sroka", "Morawska", "Kasprzyk", "Janiszewska", "Koziel", "Muszynska", "Chmiel", "Bialek", "Grzybowska", "Malek", "Kwiecien", "Jedrzejewska", "Pluta", "Krzeminska", "Witek", "Turek", "Marczak", "Osinska", "Paluch", "Piekarska", "Czaja", "Czajka", "Kubicka", "Czech", "Zukowska", "Marzec", "Janowska", "Michalowska", "Biernacka", "Szydlowska", "Przybysz", "Golebiewska", "Sliwa", "Serafin", "Staniszewska", "Stefaniak", "Kaczor", "Rudnicka", "Lech", "Poplawska", "Murawska", "Kulesza", "Lewicka", "Smolinska", "Debska", "Kujawa", "Podgorska", "Gora", "Kacprzak", "Rak", "Stachowiak", "Piatkowska", "Cieslik", "Pietrzyk", "Banach", "Matysiak", "Sowinska", "Rosinska", "Banas", "Karczewska", "Niemiec", "Zurek", "Golebiowska", "Klimczak", "Zurawska", "Zawada", "Godlewska", "Bieniek", "Drozd", "Augustyniak", "Czyz", "Komorowska", "Skrzypczak", "Grochowska", "Gruszka", "Gorka", "Kus", "Rozanska", "Winiarska", "Przybyla", "Szczesna", "Cybulska", "Kulik", "Krawiec", "Ptak", "Lesniewska", "Panek", "Konopka", "Zaremba", "Krzyzanowska", "Slowik", "Gil", "Mikolajczak", "Cichon", "Cichocka", "Tokarska", "Szczepanik", "Siwek", "Mielczarek", "Graczyk", "Zarzycka", "Melnyk", "Strzelecka", "Mlynarczyk", "Szymczyk", "Bartkowiak", "Mackowiak", "Klos", "Buczek", "Kaczynska", "Stanczyk", "Szczygiel", "Kostrzewa", "Szostak", "Biernat", "Janus", "Niewiadomska", "Wegrzyn", "Janiak", "Grzyb", "Filipiak", "Skowron", "Sienkiewicz", "Kucharczyk", "Kaleta", "Gorna", "Jurek", "Gawron", "Rakowska", "Bogusz", "Baginska", "Kubik", "Ksiazek", "Gasior", "Ciesla", "Banasiak", "Antczak", "Zebrowska", "Bartczak", "Rozycka", "Gawlik", "Krolikowska", "Trzcinska", "Hajduk", "Mikulska", "Kula", "Zareba", "Rogalska", "Fraczek", "Grzegorczyk", "Rzepka", "Rojek", "Dlugosz", "Maliszewska", "Malec", "Rogala", "Palka", "Trojanowska", "Gawronska", "Dobosz", "Radomska", "Witczak", "Tkaczyk", "Borek", "Stec", "Rybicka", "Lach", "Mika", "Frankowska", "Kisiel", "Bogucka", "Zaborowska", "Karwowska", "Slusarczyk", "Kaczorowska", "Wasik", "Galazka", "Grzesiak", "Kmiecik", "Kwasniewska", "Wieckowska", "Lipska", "Bialas", "Kubacka", "Walkowiak", "Frackowiak", "Pietras", "Dudzinska", "Bochenek", "Janas", "Sokol", "Pawelec", "Juszczak", "Nawrot", "Wojtczak", "Wnuk", "Wojcicka", "Mroczek", "Lasota", "Rosiak", "Zygmunt", "Skrzypek", "Pasternak", "Kolodziejska", "Burzynska", "Czyzewska", "Wronska", "Szafranska", "Piwowarczyk", "Jedrzejczyk", "Fijalkowska", "Lukasiewicz", "Gruszczynska", "Zmuda", "Piorkowska", "Borowiec", "Zajaczkowska", "Krysiak", "Jurkiewicz", "Jagiello", "Misiak", "Maslowska", "Jagodzinska", "Lapinska", "Krakowiak", "Dabek", "Lisiecka", "Jedrzejczak", "Bujak", "Pilarska", "Gawel", "Wilczek", "Gutowska", "Flis", "Karas", "Dziuba", "Twardowska", "Drzewiecka", "Sobieraj", "Skibinska", "Strzelczyk", "Bielawska", "Debowska", "Lukaszewska", "Stelmach", "Kubica", "Zielonka", "Cygan", "Tarnowska", "Skoczylas", "Szczesniak", "Kaluza", "Soltys", "Bober", "Bilska", "Falkowska", "Kovalchuk", "Raczynska", "Filipek", "Jakubiak", "Pakula", "Szwed", "Cebula", "Mierzejewska", "Shevchenko", "Gasiorowska", "Bartosik", "Wasiak", "Majcher", "Stanek", "Kedziora", "Gorniak", "Guzik", "Krupinska", "Romaniuk", "Wiecek", "Nowaczyk", "Rusin", "Urbanczyk", "Staszewska", "Ciszewska", "Stolarczyk", "Goral", "Matuszak", "Czapla", "Jaskiewicz", "Kopczynska", "Wolak", "Drozdowska", "Zagorska", "Kulig", "Partyka", "Rucinska", "Florek", "Zwolinska", "Siedlecka", "Modzelewska", "Kaczmarska", "Slowinska", "Kaszuba", "Grzywacz", "Kaluzna", "Motyka", "Golab", "Slawinska", "Paczkowska", "Pytel", "Cholewa", "Misztal", "Andrzejczak", "Milczarek", "Pawlikowska", "Dubiel", "Jezierska", "Wojtas", "Prokop", "Michalek", "Stachura", "Jackowska", "Malicka", "Jurkowska", "Sochacka", "Bozek", "Gwozdz", "Bielak", "Kepa", "Kuchta", "Swierczynska", "Rosa", "Olczak", "Sieradzka", "Skalska", "Szyszka", "Bienkowska", "Kuc", "Galka", "Szczerba", "Plonka", "Jankowiak", "Janusz", "Kwiecinska", "Broda", "Chojnowska", "Dudzik", "Stepniak", "Iwanska", "Mroczkowska", "Wos", "Knapik", "Kolasa", "Paszkowska", "Sitek", "Kruszewska", "Szatkowska", "Skora", "Chmura", "Kapusta", "Lenart", "Suska", "Dec", "Wyszynska", "Majka", "Czechowska", "Kowalczuk", "Puchalska", "Stanislawska", "Ivanova", "Wlodarska", "Florczak", "Boiko", "Dominiak", "Salamon", "Zdunek", "Dudziak", "Tomala", "Trzeciak", "Mankowska", "Kotowska", "Michalczyk", "Lipka", "Molenda", "Januszewska", "Skowronek", "Augustyn", "Filipowicz", "Kawa", "Adamczak", "Tokarz", "Buczynska", "Bondarenko", "Glogowska", "Kolakowska", "Adamek", "Mrozek", "Maslanka", "Kogut", "Moroz", "Kita", "Kobus", "Piechota", "Koper", "Noga", "Jagielska", "Adamus", "Stolarska", "Pilch", "Zietek", "Malik", "Gorczyca", "Dobrzynska", "Kaniewska", "Grzesik", "Banasik", "Zuk", "Kovalenko", "Jurczak", "Koza", "Bakowska", "Budzynska", "Chudzik", "Robak", "Niemczyk", "Maciag", "Rudzinska", "Niedzwiecka", "Jarzabek", "Wiacek", "Przybyl", "Warchol", "Soltysiak", "Prus", "Buczkowska", "Kuzma", "Rudnik", "Stanczak", "Miskiewicz", "Porebska", "Kalisz", "Sojka", "Klosowska", "Wypych", "Kos", "Moskal", "Drabik", "Kopacz", "Adamowicz", "Herman", "Gadomska", "Stachurska", "Dabkowska", "Surma", "Kasperek", "Oleksy", "Ossowska", "Bartnik", "Olczyk", "Pilat", "Bialkowska", "Golec", "Marchewka", "Blaszczak", "Kucinska", "Stachowicz", "Magiera", "Wolinska", "Kielbasa", "Balcerzak", "Niedzielska", "Szelag", "Rys", "Bielska", "Zablocka", "Jaros", "Korzeniowska", "Tracz", "Budzinska", "Roman", "Adamiak", "Wojtkowiak", "Rybarczyk", "Zyla", "Furman", "Szymkowiak", "Drozdz", "Rudzka", "Grudzien", "Miller", "Radecka", "Kosowska", "Slezak", "Sek", "Lesiak", "Kujawska", "Pietruszka", "Piotrowicz", "Bury", "Tomasik", "Kozik", "Kostecka", "Pelc", "Urbanek", "Warzecha", "Trela", "Woznica", "Bielinska", "Sobanska", "Fratczak", "Jurczyk", "Sekula", "Pawlicka", "Czerniak", "Schmidt", "Pelka", "Wojtasik", "Grzeskowiak", "Kruczek", "Krakowska", "Woloszyn", "Pogorzelska", "Polanska", "Biskup", "Swiatkowska", "Kulinska", "Urbanowicz", "Piwowarska", "Shevchuk", "Sobota", "Mierzwa", "Stawicka", "Mackiewicz", "Szuba", "Glab", "Kmiec", "Gut", "Hoffmann", "Czekaj", "Kawecka", "Smigielska", "Banaszek", "Swider", "Litwin", "Panasiuk", "Borys", "Krasowska", "Grudzinska", "Tkachenko", "Ratajczyk", "Aleksandrowicz", "Kwiatek", "Lorenc", "Roszkowska", "Roszak", "Makuch", "Wisniowska", "Werner", "Tokarczyk", "Juszczyk", "Izdebska", "Szwarc", "Skorupa", "Lukaszewicz", "Napierala", "Szarek", "Koval", "Siwiec", "Bogacz", "Liszka", "Szot", "Studzinska", "Kawka", "Knap", "Jozwik", "Pietka", "Jakubczyk", "Jeziorska", "Turowska", "Krukowska", "Karcz", "Kukla", "Kusiak", "Lange", "Wrzesinska", "Zuchowska", "Gacek", "Wach", "Kedzior", "Rozek", "Paprocka", "Krolak", "Sidor", "Kravchenko", "Bobrowska", "Kraszewska", "Rybka", "Manka", "Grodzka", "Kruszynska", "Mielcarek", "Szeliga", "Bogdanska", "Tkacz", "Cicha", "Wojda", "Spiewak", "Maziarz", "Korczak", "Smolen", "Korzeniewska", "Niedziela", "Kosmala", "Gasiorek", "Grzybek", "Majkowska", "Filip", "Semeniuk", "Malkowska", "Radziszewska", "Rusek", "Szymanek", "Wolna", "Wagner", "Olech", "Rzepecka", "Grabarczyk", "Perkowska", "Romanska", "Jakubiec", "Reszka", "Wajda", "Lipiec", "Staszak", "Szkudlarek", "Nowinska", "Rodak", "Wasielewska", "Pekala", "Lewinska", "Potocka", "Sledz", "Kapuscinska", "Plichta", "Bartoszek", "Pisarek", "Kawalec", "Adamiec", "Szopa", "Kulpa", "Kozakiewicz", "Gladysz", "Konarska", "Drozdz", "Kupiec", "Raczkowska", "Rogozinska", "Bugajska", "Duszynska", "Wojtowicz", "Piech", "Kazmierska", "Gola", "Paszkiewicz", "Skonieczna", "Banaszak", "Janczak", "Osowska", "Kochanska", "Rokicka", "Szymanowska", "Polishchuk", "Wyrzykowska", "Olszak", "Bilinska", "Oliinyk", "Kalinska", "Sulkowska", "Suchecka", "Stoklosa", "Kurzawa", "Bugaj", "Kepka", "Wrzosek", "Brzeska", "Solecka", "Karolak", "Puchala", "Pierzchala", "Ambroziak", "Balicka", "Golinska", "Kokot", "Waszkiewicz", "Wojciak", "Gruca", "Sudol", "Pasek", "Orzel", "Lasek", "Jaskulska", "Brodowska", "Szczygielska", "Wielgus", "Swierczek", "Martyniuk", "Wojtaszek", "Barszcz", "Krauze", "Biela", "Goralczyk", "Bialecka", "Burda", "Piechocka", "Szczurek", "Kokoszka", "Mach", "Weber", "Zapala", "Chrobak", "Jaroszewska", "Wozna", "Maczka", "Bojarska", "Platek", "Zborowska", "Bator", "Garbacz", "Jamroz", "Lorek", "Piszczek", "Dymek", "Czarnota", "Ozog", "Ferenc", "Dzikowska", "Figura", "Matusik", "Koprowska", "Kostka", "Dutkiewicz", "Stepniewska", "Kochanowska", "Oles", "Paszek", "Szpak", "Golabek", "Osuch", "Walczyk", "Sala", "Gabrys", "Traczyk", "Grygiel", "Bernat", "Tkachuk", "Dolata", "Paradowska", "Piskorz", "Grela", "Kozyra", "Wdowiak", "Blazejewska", "Lawniczak", "Smolarek", "Surowiec", "Modrzejewska", "Stencel", "Kempa", "Baron", "Zawisza", "Bartosiewicz", "Kolasinska", "Mularczyk", "Szymaniak", "Adamczewska", "Bartnicka", "Grabska", "Mieczkowska", "Cichosz", "Kolodziejczak", "Stachowska", "Dolinska", "Winnicka", "Zawistowska", "Zarebska", "Mrowiec", "Poltorak", "Wielgosz", "Wachowiak", "Brozek", "Mysliwiec", "Zasada", "Switala", "Plewa" };

std::string Pracownicy::randomName()
{
	return names[rand() % names.size()];
}

std::string Pracownicy::randomSurname()
{
	return surnames[rand() % surnames.size()];
}

std::string Pracownicy::randomDateOfBirth()
{
	//aged 22 - 56
	int year = 2023 - (rand() % 35 + 22);
	int month = rand() % 12 + 1;
	int day = 1;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		day = rand() % 31 + 1;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		day = rand() % 30 + 1;
		break;
	case 2:
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
			day = rand() % 29 + 1;
		else
			day = rand() % 28 + 1;
		break;
	}
	std::string date;
	std::stringstream stream;

	stream << year << '-';
	if (month >= 10)
		stream << month << '-';
	else
		stream << '0' << month << '-';
	if (day >= 10)
		stream << day;
	else
		stream << '0' << day;

	stream >> date;

	return date;
}

std::string Pracownicy::randomDateOfEmployment()
{
	//'2022-01-01' to '2022-12-31'
	int year = 2022;
	int month = rand() % 12 + 1;
	int day = 1;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		day = rand() % 31 + 1;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		day = rand() % 30 + 1;
		break;
	case 2:
		day = rand() % 28 + 1;
		break;
	}
	std::string date;
	std::stringstream stream;

	stream << year << '-';
	if (month >= 10)
		stream << month << '-';
	else
		stream << '0' << month << '-';
	if (day >= 10)
		stream << day;
	else
		stream << '0' << day;

	stream >> date;

	return date;
}

int Pracownicy::randomSalary()
{
	//2000 - 4000, increasing by 10 (200 - 400)
	return (rand() % 201 + 200) * 10;
}

Pracownicy::Pracownicy()
{
	id = ++counter;
	imie = randomName();
	nazwisko = randomSurname();
	data_urodzenia = randomDateOfBirth();
	data_zatrudnienia = randomDateOfEmployment();
	pensja = randomSalary();
}