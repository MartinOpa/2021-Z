Spuštění programu:

program využívá standardní knihovnu SDL2 a její části: SDL2_mixer, SDL2_image, SDL2_ttf, knihovny nejsou součástí složky a je potřeba je mít v počítači

program byl psán na MacOS Big Sur 11.6.1, měl by jít spustit na jakémkoli OS se správnou SDL2 knihovnou

VSCode -> right click na složku "pacman", open in integrated terminal
napsat make + enter
spuštění = do příkazové řádky ./pacman

ovládání:

W/šipka nahoru = nahoru
S/šipka dolů = dolů
D/šipka doprava = doprava
A/šipka doleva = doleva

NPC:

Blinky - červený, následuje pozici hráče (slepě), rychlostí jen o málo nižší než hráč
Inky - modrý, následuje pozici hráče (slepě), rychlostí nižší než hráč
Pinky - růžový, při nárazu do kraje mapy si vybere náhodný směr, kterým bude pokračovat, rychlost stejná jako hráč
Clyde - oranžový, při nárazu do kraje mapy si vybere náhodný směr, kterým bude pokračovat, rychlost stejná jako hráč

skóre je promítáno vpravo nahoře, 1 sebraný point = 50 bodů ke skóre

konec hry, ať už posbíráním všech bodů nebo ztrátou všech životů, je následován zvukovým efektem a hráč je přesunut doprostřed mapy, odkud se do ukončení programu nedostane